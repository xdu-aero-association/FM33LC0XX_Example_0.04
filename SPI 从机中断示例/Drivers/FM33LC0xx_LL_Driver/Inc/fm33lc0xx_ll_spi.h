/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_spi.h
  * @author  FMSH Application Team
  * @brief   Head file of SPI LL Module
  *******************************************************************************************************
  * @attention
  *
  * Copyright (c) [2019] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under the Mulan PSL v1.
  * can use this software according to the terms and conditions of the Mulan PSL v1.
  * You may obtain a copy of Mulan PSL v1 at:
  * http://license.coscl.org.cn/MulanPSL
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
  * PURPOSE.
  * See the Mulan PSL v1 for more details.
  *
  *******************************************************************************************************
  */


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33LC0XX_LL_SPI_H
#define __FM33LC0XX_LL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_SPI
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup SPI_LL_ES_INIT SPI Exported Init structures
  * @{
  */

/**
  * @brief LL SPI Init Sturcture definition
  */
typedef struct
{
    /*! SPI传输方向 接受发送 */
    uint32_t TransferDirection;
    /*! 传输模式 单双工 */ 
    uint32_t TransferMode;
    /*! 主从模式 */
    uint32_t Mode;             
    /*! 数据位宽 */
    uint32_t DataWidth;        
    /*! 时钟极性 */                        
    uint32_t ClockPolarity;    
    /*! 时钟相位 */
    uint32_t ClockPhase;       
    /*! NSS 脚模式 软件或硬件 */
    uint32_t SSN;              
    /*! 通讯速率 */
    uint32_t BaudRate;         
    /*! Bit方向 */
    uint32_t BitOrder;         
                          
} LL_SPI_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup SPI_LL_Exported_Constants SPI Exported Constants
  * @{
  */
#define    LL_SPI_SWAP_MOMI_PIN_DISABLE                           (0x0U << SPI_CR1_IOSWAP_Pos)
#define    LL_SPI_SWAP_MOMI_PIN_ENABLE                            (0x1U << SPI_CR1_IOSWAP_Pos)

#define    LL_SPI_SAMP_POSITION_NORMAL                            (0x0U << SPI_CR1_MSPA_Pos)
#define    LL_SPI_SAMP_POSITION_DELAY_HALF_CLK                    (0x1U << SPI_CR1_MSPA_Pos)

#define    LL_SPI_SEND_POSITION_NORMAL                            (0x0U << SPI_CR1_SSPA_Pos)
#define    LL_SPI_SEND_POSITION_ADVANCE_HALF_CLK                  (0x1U << SPI_CR1_SSPA_Pos)

#define    LL_SPI_WORK_MODE_SLAVE                                 (0x0U << SPI_CR1_MM_Pos)
#define    LL_SPI_WORK_MODE_MASTER                                (0x1U << SPI_CR1_MM_Pos)

#define    LL_SPI_SEND_POSITION_SLAVE                             (0x0U << SPI_CR1_MM_Pos)
#define    LL_SPI_SEND_POSITION_MASTER                            (0x1U << SPI_CR1_MM_Pos)

#define    LL_SPI_BAUDRATEPRESCALER_DIV2                          (0x0U << SPI_CR1_BAUD_Pos)
#define    LL_SPI_BAUDRATEPRESCALER_DIV4                          (0x1U << SPI_CR1_BAUD_Pos)
#define    LL_SPI_BAUDRATEPRESCALER_DIV8                          (0x2U << SPI_CR1_BAUD_Pos)
#define    LL_SPI_BAUDRATEPRESCALER_DIV16                         (0x3U << SPI_CR1_BAUD_Pos)
#define    LL_SPI_BAUDRATEPRESCALER_DIV32                         (0x4U << SPI_CR1_BAUD_Pos)
#define    LL_SPI_BAUDRATEPRESCALER_DIV64                         (0x5U << SPI_CR1_BAUD_Pos)
#define    LL_SPI_BAUDRATEPRESCALER_DIV128                        (0x6U << SPI_CR1_BAUD_Pos)
#define    LL_SPI_BAUDRATEPRESCALER_DIV256                        (0x7U << SPI_CR1_BAUD_Pos)

#define    LL_SPI_BIT_ORDER_MSB_FIRST                             (0x0U << SPI_CR1_LSBF_Pos)
#define    LL_SPI_BIT_ORDER_LSB_FIRST                             (0x1U << SPI_CR1_LSBF_Pos)

#define    LL_SPI_SPI_POLARITY_LOW                                (0x0U << SPI_CR1_CPOL_Pos)
#define    LL_SPI_SPI_POLARITY_HIGH                               (0x1U << SPI_CR1_CPOL_Pos)

#define    LL_SPI_SPI_PHASE_1EDGE                                 (0x0U << SPI_CR1_CPHA_Pos)
#define    LL_SPI_SPI_PHASE_2EDGE                                 (0x1U << SPI_CR1_CPHA_Pos)

#define    LL_SPI_DUMMY_CYCLE_DISABLE                             (0x0U << SPI_CR2_DUMMY_EN_Pos)
#define    LL_SPI_DUMMY_CYCLE_ENABLE                              (0x1U << SPI_CR2_DUMMY_EN_Pos)

#define    LL_SPI_RECV_ONLY_DISABLE                               (0x0U << SPI_CR2_RXO_Pos)
#define    LL_SPI_RECV_ONLY_ENABLE                                (0x1U << SPI_CR2_RXO_Pos)

#define    LL_SPI_DATAWIDTH_8BIT                                  (0x0U << SPI_CR2_DLEN_Pos)
#define    LL_SPI_DATAWIDTH_16BIT                                 (0x1U << SPI_CR2_DLEN_Pos)
#define    LL_SPI_DATAWIDTH_24BIT                                 (0x2U << SPI_CR2_DLEN_Pos)
#define    LL_SPI_DATAWIDTH_32BIT                                 (0x3U << SPI_CR2_DLEN_Pos)

#define    LL_SPI_MODE_FULL_DUPLEX                                (0x0U << SPI_CR2_HALFDUPLEX_Pos)
#define    LL_SPI_MODE_SIMPLEX                                    (0x1U << SPI_CR2_HALFDUPLEX_Pos)

#define    LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_TX                (0x0U << SPI_CR2_HD_RW_Pos)
#define    LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_RX                (0x1U << SPI_CR2_HD_RW_Pos)

#define    LL_SPI_SIMPLEX_CMD_LEN_CONFIG_AS_DLEN                  (0x0U << SPI_CR2_CMD8B_Pos)
#define    LL_SPI_SIMPLEX_CMD_LEN_FIX_8BIT                        (0x1U << SPI_CR2_CMD8B_Pos)

#define    LL_SPI_SSN_SEND_MODE_HIGH                              (0x0U << SPI_CR2_SSNM_Pos)
#define    LL_SPI_SSN_SEND_MODE_LOW                               (0x1U << SPI_CR2_SSNM_Pos)

#define    LL_SPI_TXONLY_AUTO_OFF_DISABLE                         (0x0U << SPI_CR2_TXO_AC_Pos)
#define    LL_SPI_TXONLY_AUTO_OFF_ENABLE                          (0x1U << SPI_CR2_TXO_AC_Pos)

#define    LL_SPI_TXONLY_MODE_DISABLE                             (0x0U << SPI_CR2_TXO_Pos)
#define    LL_SPI_TXONLY_MODE_ENABLE                              (0x1U << SPI_CR2_TXO_Pos)

#define    LL_SPI_SSN_MODE_HARDWARE                               (0x0U << SPI_CR2_SSNSEN_Pos)
#define    LL_SPI_SSN_MODE_SOFTWARE                               (0x1U << SPI_CR2_SSNSEN_Pos)

#define    LL_SPI_HALFDUPLE_DCN_CMD                               (0x0U << SPI_ISR_DCN_TX_Pos)
#define    LL_SPI_HALFDUPLE_DCN_DATA                              (0x1U << SPI_ISR_DCN_TX_Pos)
/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup SPI_LL_Exported_Functions SPI Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CR1    IOSWAP    LL_SPI_SetIOPinSwap
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_SWAP_MOMI_PIN_DISABLE
  *           @arg @ref LL_SPI_SWAP_MOMI_PIN_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetIOPinSwap(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->CR1, SPI_CR1_IOSWAP_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR1    IOSWAP    LL_SPI_GetIOPinSwap
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SWAP_MOMI_PIN_DISABLE
  *           @arg @ref LL_SPI_SWAP_MOMI_PIN_ENABLE
  */
__STATIC_INLINE uint32_t LL_SPI_GetIOPinSwap(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_IOSWAP_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    MSPA    LL_SPI_SetSampilingAdjust
  * @param    SPIx SPI instance
  * @param    adjust This parameter can be one of the following values:
  *           @arg @ref LL_SPI_SAMP_POSITION_NORMAL
  *           @arg @ref LL_SPI_SAMP_POSITION_DELAY_HALF_CLK
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetSampilingAdjust(SPI_Type* SPIx, uint32_t adjust)
{
    MODIFY_REG(SPIx->CR1, SPI_CR1_MSPA_Msk, adjust);
}

/**
  * @brief    
  * @rmtoll   CR1    MSPA    LL_SPI_GetSampilingAdjust
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SAMP_POSITION_NORMAL
  *           @arg @ref LL_SPI_SAMP_POSITION_DELAY_HALF_CLK
  */
__STATIC_INLINE uint32_t LL_SPI_GetSampilingAdjust(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_MSPA_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    SSPA    LL_SPI_SetSendAdjust
  * @param    SPIx SPI instance
  * @param    adjust This parameter can be one of the following values:
  *           @arg @ref LL_SPI_SEND_POSITION_NORMAL
  *           @arg @ref LL_SPI_SEND_POSITION_ADVANCE_HALF_CLK
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetSendAdjust(SPI_Type* SPIx, uint32_t adjust)
{
    MODIFY_REG(SPIx->CR1, SPI_CR1_SSPA_Msk, adjust);
}

/**
  * @brief    
  * @rmtoll   CR1    SSPA    LL_SPI_GetSendAdjust
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SEND_POSITION_NORMAL
  *           @arg @ref LL_SPI_SEND_POSITION_ADVANCE_HALF_CLK
  */
__STATIC_INLINE uint32_t LL_SPI_GetSendAdjust(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_SSPA_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    MM    LL_SPI_SetSPIWorkMode
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_WORK_MODE_SLAVE
  *           @arg @ref LL_SPI_WORK_MODE_MASTER
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetSPIWorkMode(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->CR1, SPI_CR1_MM_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR1    MM    LL_SPI_GetSPIWorkMode
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SEND_POSITION_SLAVE
  *           @arg @ref LL_SPI_SEND_POSITION_MASTER
  */
__STATIC_INLINE uint32_t LL_SPI_GetSPIWorkMode(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_MM_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    WAIT    LL_SPI_SetSendWait
  * @param    SPIx SPI instance
  * @param    wait 
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetSendWait(SPI_Type* SPIx, uint32_t wait)
{
    MODIFY_REG(SPIx->CR1, (0x3U << 6U), (wait << 6U));
}

/**
  * @brief    
  * @rmtoll   CR1    WAIT    LL_SPI_GetSendWait
  * @param    SPIx SPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_SPI_GetSendWait(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR1, 0x3U) >> 6U);
}

/**
  * @brief    
  * @rmtoll   CR1    BAUD    LL_SPI_SetBaudrate
  * @param    SPIx SPI instance
  * @param    baud This parameter can be one of the following values:
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV2
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV4
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV8
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV16
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV32
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV64
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV128
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV256
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetBaudrate(SPI_Type* SPIx, uint32_t baud)
{
    MODIFY_REG(SPIx->CR1, SPI_CR1_BAUD_Msk, baud);
}

/**
  * @brief    
  * @rmtoll   CR1    BAUD    LL_SPI_GetBaudrate
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV2
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV4
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV8
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV16
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV32
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV64
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV128
  *           @arg @ref LL_SPI_BAUDRATEPRESCALER_DIV256
  */
__STATIC_INLINE uint32_t LL_SPI_GetBaudrate(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_BAUD_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    LSBF    LL_SPI_SetBitOrder
  * @param    SPIx SPI instance
  * @param    BitOrder This parameter can be one of the following values:
  *           @arg @ref LL_SPI_BIT_ORDER_MSB_FIRST
  *           @arg @ref LL_SPI_BIT_ORDER_LSB_FIRST
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetBitOrder(SPI_Type* SPIx, uint32_t BitOrder)
{
    MODIFY_REG(SPIx->CR1, SPI_CR1_LSBF_Msk, BitOrder);
}

/**
  * @brief    
  * @rmtoll   CR1    LSBF    LL_SPI_GetBitOrder
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_BIT_ORDER_MSB_FIRST
  *           @arg @ref LL_SPI_BIT_ORDER_LSB_FIRST
  */
__STATIC_INLINE uint32_t LL_SPI_GetBitOrder(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_LSBF_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    CPOL    LL_SPI_SetClockPolarity
  * @param    SPIx SPI instance
  * @param    ClockPolarity This parameter can be one of the following values:
  *           @arg @ref LL_SPI_SPI_POLARITY_LOW
  *           @arg @ref LL_SPI_SPI_POLARITY_HIGH
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetClockPolarity(SPI_Type* SPIx, uint32_t ClockPolarity)
{
    MODIFY_REG(SPIx->CR1, SPI_CR1_CPOL_Msk, ClockPolarity);
}

/**
  * @brief    
  * @rmtoll   CR1    CPOL    LL_SPI_GetClockPolarity
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SPI_POLARITY_LOW
  *           @arg @ref LL_SPI_SPI_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t LL_SPI_GetClockPolarity(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_CPOL_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    CPHA    LL_SPI_SetClockPhase
  * @param    SPIx SPI instance
  * @param    ClockPhase This parameter can be one of the following values:
  *           @arg @ref LL_SPI_SPI_PHASE_1EDGE
  *           @arg @ref LL_SPI_SPI_PHASE_2EDGE
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetClockPhase(SPI_Type* SPIx, uint32_t ClockPhase)
{
    MODIFY_REG(SPIx->CR1, SPI_CR1_CPHA_Msk, ClockPhase);
}

/**
  * @brief    
  * @rmtoll   CR1    CPHA    LL_SPI_GetClockPhase
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SPI_PHASE_1EDGE
  *           @arg @ref LL_SPI_SPI_PHASE_2EDGE
  */
__STATIC_INLINE uint32_t LL_SPI_GetClockPhase(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_CPHA_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    DUMMY_EN    LL_SPI_SetDummyCycle
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_DUMMY_CYCLE_DISABLE
  *           @arg @ref LL_SPI_DUMMY_CYCLE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetDummyCycle(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_DUMMY_EN_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR2    DUMMY_EN    LL_SPI_GetDummyCycle
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_DUMMY_CYCLE_DISABLE
  *           @arg @ref LL_SPI_DUMMY_CYCLE_ENABLE
  */
__STATIC_INLINE uint32_t LL_SPI_GetDummyCycle(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_DUMMY_EN_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    RXO    LL_SPI_SetRecvModeOnly
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_RECV_ONLY_DISABLE
  *           @arg @ref LL_SPI_RECV_ONLY_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetRecvModeOnly(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_RXO_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR2    RXO    LL_SPI_GetRecvModeOnly
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_RECV_ONLY_DISABLE
  *           @arg @ref LL_SPI_RECV_ONLY_ENABLE
  */
__STATIC_INLINE uint32_t LL_SPI_GetRecvModeOnly(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_RXO_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    DLEN    LL_SPI_SetDataWidth
  * @param    SPIx SPI instance
  * @param    DataWidth This parameter can be one of the following values:
  *           @arg @ref LL_SPI_DATAWIDTH_8BIT
  *           @arg @ref LL_SPI_DATAWIDTH_16BIT
  *           @arg @ref LL_SPI_DATAWIDTH_24BIT
  *           @arg @ref LL_SPI_DATAWIDTH_32BIT
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetDataWidth(SPI_Type* SPIx, uint32_t DataWidth)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_DLEN_Msk, DataWidth);
}

/**
  * @brief    
  * @rmtoll   CR2    DLEN    LL_SPI_GetDataWidth
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_DATAWIDTH_8BIT
  *           @arg @ref LL_SPI_DATAWIDTH_16BIT
  *           @arg @ref LL_SPI_DATAWIDTH_24BIT
  *           @arg @ref LL_SPI_DATAWIDTH_32BIT
  */
__STATIC_INLINE uint32_t LL_SPI_GetDataWidth(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_DLEN_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    HALFDUPLEX    LL_SPI_SetTransferMode
  * @param    SPIx SPI instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_MODE_FULL_DUPLEX
  *           @arg @ref LL_SPI_MODE_SIMPLEX
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetTransferMode(SPI_Type* SPIx, uint32_t Mode)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_HALFDUPLEX_Msk, Mode);
}

/**
  * @brief    
  * @rmtoll   CR2    HALFDUPLEX    LL_SPI_GetTransferMode
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_MODE_FULL_DUPLEX
  *           @arg @ref LL_SPI_MODE_SIMPLEX
  */
__STATIC_INLINE uint32_t LL_SPI_GetTransferMode(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_HALFDUPLEX_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    HD_RW    LL_SPI_SetTransferDirection
  * @param    SPIx SPI instance
  * @param    TransferDirection This parameter can be one of the following values:
  *           @arg @ref LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_TX
  *           @arg @ref LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_RX
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetTransferDirection(SPI_Type* SPIx, uint32_t TransferDirection)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_HD_RW_Msk, TransferDirection);
}

/**
  * @brief    
  * @rmtoll   CR2    HD_RW    LL_SPI_GetTransferDirection
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_TX
  *           @arg @ref LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_RX
  */
__STATIC_INLINE uint32_t LL_SPI_GetTransferDirection(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_HD_RW_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    CMD8B    LL_SPI_SetSimplexCmdlen
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_SIMPLEX_CMD_LEN_CONFIG_AS_DLEN
  *           @arg @ref LL_SPI_SIMPLEX_CMD_LEN_FIX_8BIT
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetSimplexCmdlen(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_CMD8B_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR2    CMD8B    LL_SPI_GetSimplexCmdlen
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SIMPLEX_CMD_LEN_CONFIG_AS_DLEN
  *           @arg @ref LL_SPI_SIMPLEX_CMD_LEN_FIX_8BIT
  */
__STATIC_INLINE uint32_t LL_SPI_GetSimplexCmdlen(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_CMD8B_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    SSNM    LL_SPI_SetSSNPinMode
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_SSN_SEND_MODE_HIGH
  *           @arg @ref LL_SPI_SSN_SEND_MODE_LOW
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetSSNPinMode(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_SSNM_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR2    SSNM    LL_SPI_GetSSNPinMode
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SSN_SEND_MODE_HIGH
  *           @arg @ref LL_SPI_SSN_SEND_MODE_LOW
  */
__STATIC_INLINE uint32_t LL_SPI_GetSSNPinMode(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_SSNM_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    TXO_AC    LL_SPI_SetTxOnlyModeAutoDisable
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_TXONLY_AUTO_OFF_DISABLE
  *           @arg @ref LL_SPI_TXONLY_AUTO_OFF_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetTxOnlyModeAutoDisable(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_TXO_AC_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR2    TXO_AC    LL_SPI_GetTxOnlyModeAutoDisable
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_TXONLY_AUTO_OFF_DISABLE
  *           @arg @ref LL_SPI_TXONLY_AUTO_OFF_ENABLE
  */
__STATIC_INLINE uint32_t LL_SPI_GetTxOnlyModeAutoDisable(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_TXO_AC_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    TXO    LL_SPI_SetTxOnlymode
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_TXONLY_MODE_DISABLE
  *           @arg @ref LL_SPI_TXONLY_MODE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetTxOnlymode(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_TXO_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR2    SSN    LL_SPI_SetSSNPin
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetSSNPin(SPI_Type* SPIx)
{
    SET_BIT(SPIx->CR2, SPI_CR2_SSN_Msk); 
}

/**
  * @brief    
  * @rmtoll   CR2    SSN    LL_SPI_ResetSSNPin
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE void LL_SPI_ResetSSNPin(SPI_Type* SPIx)
{
    CLEAR_BIT(SPIx->CR2, SPI_CR2_SSN_Msk);  
}

/**
  * @brief    
  * @rmtoll   CR2    SSNSEN    LL_SPI_SetSNNMode
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_SSN_MODE_HARDWARE
  *           @arg @ref LL_SPI_SSN_MODE_SOFTWARE
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetSNNMode(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->CR2, SPI_CR2_SSNSEN_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR2    SSNSEN    LL_SPI_GetSNNMode
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_SSN_MODE_HARDWARE
  *           @arg @ref LL_SPI_SSN_MODE_SOFTWARE
  */
__STATIC_INLINE uint32_t LL_SPI_GetSNNMode(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_SSNSEN_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    SPIEN    LL_SPI_Enable
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_Enable(SPI_Type* SPIx)
{
    SET_BIT(SPIx->CR2, SPI_CR2_SPIEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR2    SPIEN    LL_SPI_IsEnabled
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsEnabled(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_SPIEN_Msk) == SPI_CR2_SPIEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR2    SPIEN    LL_SPI_Disable
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_Disable(SPI_Type* SPIx)
{
    CLEAR_BIT(SPIx->CR2, SPI_CR2_SPIEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR3    TXBFC    LL_SPI_TxBuffClear
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_TxBuffClear(SPI_Type* SPIx)
{
    WRITE_REG(SPIx->CR3, SPI_CR3_TXBFC_Msk);
}

/**
  * @brief    
  * @rmtoll   CR3    RXBFC    LL_SPI_RxBuffClear
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_RxBuffClear(SPI_Type* SPIx)
{
    WRITE_REG(SPIx->CR3, SPI_CR3_RXBFC_Msk);
}

/**
  * @brief    
  * @rmtoll   CR3    MERRC    LL_SPI_MasterErrorClear
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_MasterErrorClear(SPI_Type* SPIx)
{
    WRITE_REG(SPIx->CR3, SPI_CR3_MERRC_Msk);
}

/**
  * @brief    
  * @rmtoll   CR3    SERRC    LL_SPI_SlaveErrorClear
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SlaveErrorClear(SPI_Type* SPIx)
{
    WRITE_REG(SPIx->CR3, SPI_CR3_SERRC_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    ERRIE    LL_SPI_DisableIT_Error
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_DisableIT_Error(SPI_Type* SPIx)
{
    CLEAR_BIT(SPIx->IER, SPI_IER_ERRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    ERRIE    LL_SPI_EnabledIT_Error
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_EnabledIT_Error(SPI_Type* SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_ERRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    ERRIE    LL_SPI_IsEnabledIT_Error
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsEnabledIT_Error(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->IER, SPI_IER_ERRIE_Msk) == SPI_IER_ERRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXIE    LL_SPI_DisableIT_Transmitcomplete
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_DisableIT_Transmitcomplete(SPI_Type* SPIx)
{
    CLEAR_BIT(SPIx->IER, SPI_IER_TXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXIE    LL_SPI_EnabledIT_Transmitcomplete
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_EnabledIT_Transmitcomplete(SPI_Type* SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_TXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXIE    LL_SPI_IsEnabledIT_Transmitcomplete
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsEnabledIT_Transmitcomplete(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->IER, SPI_IER_TXIE_Msk) == SPI_IER_TXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXIE    LL_SPI_DisableIT_Receivecomplete
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_DisableIT_Receivecomplete(SPI_Type* SPIx)
{
    CLEAR_BIT(SPIx->IER, SPI_IER_RXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXIE    LL_SPI_EnabledIT_Receivecomplete
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_EnabledIT_Receivecomplete(SPI_Type* SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXIE    LL_SPI_IsEnabledIT_Receivecomplete
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsEnabledIT_Receivecomplete(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->IER, SPI_IER_RXIE_Msk) == SPI_IER_RXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    DCN_TX    LL_SPI_SetDataOrCmdMode
  * @param    SPIx SPI instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SPI_HALFDUPLE_DCN_CMD
  *           @arg @ref LL_SPI_HALFDUPLE_DCN_DATA
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_SetDataOrCmdMode(SPI_Type* SPIx, uint32_t mode)
{
    MODIFY_REG(SPIx->ISR, SPI_ISR_DCN_TX_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   ISR    DCN_TX    LL_SPI_GetDataOrCmdMode
  * @param    SPIx SPI instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SPI_HALFDUPLE_DCN_CMD
  *           @arg @ref LL_SPI_HALFDUPLE_DCN_DATA
  */
__STATIC_INLINE uint32_t LL_SPI_GetDataOrCmdMode(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_DCN_TX_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    RXCOL    LL_SPI_IsActiveFlag_ReceiveCollosion
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_ReceiveCollosion(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_RXCOL_Msk) == (SPI_ISR_RXCOL_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    RXCOL    LL_SPI_ClearFlag_RxBuffCollosion
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_ClearFlag_RxBuffCollosion(SPI_Type* SPIx)
{
    WRITE_REG(SPIx->ISR, SPI_ISR_RXCOL_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    TXCOL    LL_SPI_IsActiveFlag_TxBuffCollosion
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_TxBuffCollosion(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_TXCOL_Msk) == (SPI_ISR_TXCOL_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    TXCOL    LL_SPI_ClearFlag_TxBuffCollosion
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_ClearFlag_TxBuffCollosion(SPI_Type* SPIx)
{
    WRITE_REG(SPIx->ISR, SPI_ISR_TXCOL_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    BUSY    LL_SPI_IsActiveFlag_SPIBusy
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_SPIBusy(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_BUSY_Msk) == (SPI_ISR_BUSY_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    MERR    LL_SPI_IsActiveFlag_MasterError
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_MasterError(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_MERR_Msk) == (SPI_ISR_MERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    MERR    LL_SPI_ClearFlag_MasterError
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_ClearFlag_MasterError(SPI_Type* SPIx)
{
    WRITE_REG(SPIx->ISR, SPI_ISR_MERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    SERR    LL_SPI_IsActiveFlag_SlaveError
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_SlaveError(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_SERR_Msk) == (SPI_ISR_SERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    SERR    LL_SPI_ClearFlag_SlaveError
  * @param    SPIx SPI instance
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_ClearFlag_SlaveError(SPI_Type* SPIx)
{
    WRITE_REG(SPIx->ISR, SPI_ISR_SERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    TXBE    LL_SPI_IsActiveFlag_TxBufffEmpty
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_TxBufffEmpty(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_TXBE_Msk) == (SPI_ISR_TXBE_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    RXBF    LL_SPI_IsActiveFlag_RxBufffFull
  * @param    SPIx SPI instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_RxBufffFull(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->ISR, SPI_ISR_RXBF_Msk) == (SPI_ISR_RXBF_Msk));
}
/**
  * @brief    
  * @rmtoll   TXBUF        LL_SPI_WriteTxBuff
  * @param    SPIx SPI instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void LL_SPI_WriteTxBuff(SPI_Type* SPIx, uint32_t data)
{
    MODIFY_REG(SPIx->TXBUF, (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    
  * @rmtoll   RXBUF        LL_SPI_ReadRxBuff
  * @param    SPIx SPI instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_SPI_ReadRxBuff(SPI_Type* SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->RXBUF, 0xffffffffU) >> 0U);
}

/**
  * @}
  */

/** @defgroup SPI_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_SPI_DeInit(SPI_Type *SPIx);
ErrorStatus LL_SPI_Init(SPI_Type *SPIx,LL_SPI_InitTypeDef *SPI_InitStruct);
void LL_SPI_StructInit(LL_SPI_InitTypeDef *SPI_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_SPI_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-17**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
