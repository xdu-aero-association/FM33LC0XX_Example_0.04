/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_uart.h
  * @author  FMSH Application Team
  * @brief   Head file of UART LL Module
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
#ifndef __FM33LC0XX_LL_UART_H
#define __FM33LC0XX_LL_UART_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_UART
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup UART_LL_ES_INIT UART Exported Init structures
  * @{
  */

/**
  * @brief LL UART Init Sturcture definition
  */
typedef struct
{
    /*! 时钟源选择 */
    uint32_t ClockSrc; 
    /*! 通讯BaudRate */    
    uint32_t BaudRate;                  
    /*! 数据位宽 */
    uint32_t DataWidth;                 
    /*! 停止位 */
    uint32_t StopBits;                  
    /*! 奇偶校验位 */
    uint32_t Parity;                    
    /*! 传输反向 */
    uint32_t TransferDirection;         
    /*! 红外调制使能 */
    uint32_t InfraredModulation;       

} LL_UART_InitTypeDef;
/**
  * @brief LL UART InfraRed Init Sturcture definition
  */
typedef struct
{
    /*! 调制极性默认bit1调制 */
    uint32_t Polarity;                  
    /*! 红外调制占控比 */
    uint32_t ModulationDuty;                 
    /*! 红外调制频率 */
    uint32_t ModulationFrequency;                  
         
} LL_UART_InfraRed_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup UART_LL_Exported_Constants UART Exported Constants
  * @{
  */

#define    LL_UART_INFRARED_POLARITY_POSITIVE                     (0x0U << UART_IRCR_IRFLAG_Pos)
#define    LL_UART_INFRARED_POLARITY_NEGATIVE                     (0x1U << UART_IRCR_IRFLAG_Pos)

#define    LL_UART_DATA_BITORDER_LSBFIRST                         (0x0U << UART_CSR_BITORD_Pos)
#define    LL_UART_DATA_BITORDER_MSBFIRST                         (0x1U << UART_CSR_BITORD_Pos)

#define    LL_UART_STOPBITS_1                                     (0x0U << UART_CSR_STOPCFG_Pos)
#define    LL_UART_STOPBITS_2                                     (0x1U << UART_CSR_STOPCFG_Pos)

#define    LL_UART_DATAWIDTH_7B                                   (0x0U << UART_CSR_PDSEL_Pos)
#define    LL_UART_DATAWIDTH_8B                                   (0x1U << UART_CSR_PDSEL_Pos)
#define    LL_UART_DATAWIDTH_9B                                   (0x2U << UART_CSR_PDSEL_Pos)
#define    LL_UART_DATAWIDTH_6B                                   (0x3U << UART_CSR_PDSEL_Pos)

#define    LL_UART_PARITY_NONE                                    (0x0U << UART_CSR_PARITY_Pos)
#define    LL_UART_PARITY_EVEN                                    (0x1U << UART_CSR_PARITY_Pos)
#define    LL_UART_PARITY_ODD                                     (0x2U << UART_CSR_PARITY_Pos)

#define    LL_UART_RXPIN_LEVEL_STANDARD                           (0x0U << UART_CSR_RXPOL_Pos)
#define    LL_UART_RXPIN_LEVEL_INVERTED                           (0x1U << UART_CSR_RXPOL_Pos)

#define    LL_UART_TXPIN_LEVEL_STANDARD                           (0x0U << UART_CSR_TXPOL_Pos)
#define    LL_UART_TXPIN_LEVEL_INVERTED                           (0x1U << UART_CSR_TXPOL_Pos)

#define    LL_UART_DIRECTION_NONE                                 0x00000000U                          
#define    LL_UART_DIRECTION_RX                                   UART_CSR_RXEN                       
#define    LL_UART_DIRECTION_TX                                   UART_CSR_TXEN                      
#define    LL_UART_DIRECTION_TX_RX                               (UART_CSR_RXEN|UART_CSR_TXEN)
/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup UART_LL_Exported_Functions UART Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   IRCR    IRFLAG    LL_UART_SetInfraredPolarity
  * @param    UART_Comment UART_Comment instance
  * @param    Polarity This parameter can be one of the following values:
  *           @arg @ref LL_UART_INFRARED_POLARITY_POSITIVE
  *           @arg @ref LL_UART_INFRARED_POLARITY_NEGATIVE
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetInfraredPolarity(UART_COMMON_Type* UART_Comment, uint32_t Polarity)
{
    MODIFY_REG(UART_Comment->IRCR, UART_IRCR_IRFLAG_Msk, Polarity);
}

/**
  * @brief    
  * @rmtoll   IRCR    IRFLAG    LL_UART_GetInfraredPolarity
  * @param    UART_Comment UART_Comment instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_UART_INFRARED_POLARITY_POSITIVE
  *           @arg @ref LL_UART_INFRARED_POLARITY_NEGATIVE
  */
__STATIC_INLINE uint32_t LL_UART_GetInfraredPolarity(UART_COMMON_Type* UART_Comment)
{
    return (uint32_t)(READ_BIT(UART_Comment->IRCR, UART_IRCR_IRFLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   IRCR    TH    LL_UART_SetInfraredModulationDuty
  * @param    UART_Comment UART_Comment instance
  * @param    Config 
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetInfraredModulationDuty(UART_COMMON_Type* UART_Comment, uint32_t Config)
{
    MODIFY_REG(UART_Comment->IRCR, (0xfU << 11U), (Config << 11U));
}

/**
  * @brief    
  * @rmtoll   IRCR    TH    LL_UART_GetInfraredModulationDuty
  * @param    UART_Comment UART_Comment instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_UART_GetInfraredModulationDuty(UART_COMMON_Type* UART_Comment)
{
    return (uint32_t)(READ_BIT(UART_Comment->IRCR, 0xfU) >> 11U);
}

/**
  * @brief    
  * @rmtoll   IRCR    TZBRG    LL_UART_SetInfraredModulationFrequency
  * @param    UART_Comment UART_Comment instance
  * @param    Freq 
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetInfraredModulationFrequency(UART_COMMON_Type* UART_Comment, uint32_t Freq)
{
    MODIFY_REG(UART_Comment->IRCR, (0x7ffU << 0U), (Freq << 0U));
}

/**
  * @brief    
  * @rmtoll   IRCR    TZBRG    LL_UART_GetInfraredModulationFrequency
  * @param    UART_Comment UART_Comment instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_UART_GetInfraredModulationFrequency(UART_COMMON_Type* UART_Comment)
{
    return (uint32_t)(READ_BIT(UART_Comment->IRCR, 0x7ffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CSR    BUSY    LL_UART_LL_IsActiveFlag_Busy
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_Busy(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_BUSY_Msk) == (UART_CSR_BUSY_Msk));
}

/**
  * @brief    
  * @rmtoll   CSR    TXIREN    LL_UART_Enable_InfraredModulation
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_Enable_InfraredModulation(UART_Type* UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_TXIREN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    TXIREN    LL_UART_Disable_InfraredModulation
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_Disable_InfraredModulation(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_TXIREN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    TXIREN    LL_UART_IsEnbaled_InfraredModulation
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaled_InfraredModulation(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_TXIREN_Msk) == UART_CSR_TXIREN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    RXTOEN    LL_UART_Enable_ReceiveTimeOut
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_Enable_ReceiveTimeOut(UART_Type* UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_RXTOEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    RXTOEN    LL_UART_Disable_ReceiveTimeOut
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_Disable_ReceiveTimeOut(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_RXTOEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    RXTOEN    LL_UART_IsEnbaled_ReceiveTimeOut
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaled_ReceiveTimeOut(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_RXTOEN_Msk) == UART_CSR_RXTOEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    IOSWAP    LL_UART_Enable_TxPinRxPinSwap
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_Enable_TxPinRxPinSwap(UART_Type* UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_IOSWAP_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    IOSWAP    LL_UART_Disable_TxPinRxPinSwap
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_Disable_TxPinRxPinSwap(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_IOSWAP_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    IOSWAP    LL_UART_IsEnbaled_TxPinRxPinSwap
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaled_TxPinRxPinSwap(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_IOSWAP_Msk) == UART_CSR_IOSWAP_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    NEWUP    LL_UART_Enable_NegtiveEdgeWakeup
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_Enable_NegtiveEdgeWakeup(UART_Type* UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_NEWUP_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    NEWUP    LL_UART_Disable_NegtiveEdgeWakeup
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_Disable_NegtiveEdgeWakeup(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_NEWUP_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    NEWUP    LL_UART_IsEnbaled_NegtiveEdgeWakeup
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaled_NegtiveEdgeWakeup(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_NEWUP_Msk) == UART_CSR_NEWUP_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    DMATXIFCFG    LL_UART_EnableIT_DMATansmitFinish
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_EnableIT_DMATansmitFinish(UART_Type* UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_DMATXIFCFG_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    DMATXIFCFG    LL_UART_DisableIT_DMATansmitFinish
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_DisableIT_DMATansmitFinish(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_DMATXIFCFG_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    DMATXIFCFG    LL_UART_IsEnbaledIT_DMATansmitFinish
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaledIT_DMATansmitFinish(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_DMATXIFCFG_Msk) == UART_CSR_DMATXIFCFG_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    BITORD    LL_UART_SetTransferBitOrder
  * @param    UARTx UART instance
  * @param    order This parameter can be one of the following values:
  *           @arg @ref LL_UART_DATA_BITORDER_LSBFIRST
  *           @arg @ref LL_UART_DATA_BITORDER_MSBFIRST
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetTransferBitOrder(UART_Type* UARTx, uint32_t order)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_BITORD_Msk, order);
}

/**
  * @brief    
  * @rmtoll   CSR    BITORD    LL_UART_GetTransferBitOrder
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_UART_DATA_BITORDER_LSBFIRST
  *           @arg @ref LL_UART_DATA_BITORDER_MSBFIRST
  */
__STATIC_INLINE uint32_t LL_UART_GetTransferBitOrder(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_BITORD_Msk));
}

/**
  * @brief    
  * @rmtoll   CSR    STOPCFG    LL_UART_SetStopBitsLength
  * @param    UARTx UART instance
  * @param    lenth This parameter can be one of the following values:
  *           @arg @ref LL_UART_STOPBITS_1
  *           @arg @ref LL_UART_STOPBITS_2
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetStopBitsLength(UART_Type* UARTx, uint32_t lenth)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_STOPCFG_Msk, lenth);
}

/**
  * @brief    
  * @rmtoll   CSR    STOPCFG    LL_UART_GetStopBitsLength
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_UART_STOPBITS_1
  *           @arg @ref LL_UART_STOPBITS_2
  */
__STATIC_INLINE uint32_t LL_UART_GetStopBitsLength(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_STOPCFG_Msk));
}

/**
  * @brief    
  * @rmtoll   CSR    PDSEL    LL_UART_SetDataWidth
  * @param    UARTx UART instance
  * @param    datawidth This parameter can be one of the following values:
  *           @arg @ref LL_UART_DATAWIDTH_7B
  *           @arg @ref LL_UART_DATAWIDTH_8B
  *           @arg @ref LL_UART_DATAWIDTH_9B
  *           @arg @ref LL_UART_DATAWIDTH_6B
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetDataWidth(UART_Type* UARTx, uint32_t datawidth)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_PDSEL_Msk, datawidth);
}

/**
  * @brief    
  * @rmtoll   CSR    PDSEL    LL_UART_GetDataWidth
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_UART_DATAWIDTH_7B
  *           @arg @ref LL_UART_DATAWIDTH_8B
  *           @arg @ref LL_UART_DATAWIDTH_9B
  *           @arg @ref LL_UART_DATAWIDTH_6B
  */
__STATIC_INLINE uint32_t LL_UART_GetDataWidth(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_PDSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   CSR    PARITY    LL_UART_SetParity
  * @param    UARTx UART instance
  * @param    parith This parameter can be one of the following values:
  *           @arg @ref LL_UART_PARITY_NONE
  *           @arg @ref LL_UART_PARITY_EVEN
  *           @arg @ref LL_UART_PARITY_ODD
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetParity(UART_Type* UARTx, uint32_t parith)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_PARITY_Msk, parith);
}

/**
  * @brief    
  * @rmtoll   CSR    PARITY    LL_UART_GetParity
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_UART_PARITY_NONE
  *           @arg @ref LL_UART_PARITY_EVEN
  *           @arg @ref LL_UART_PARITY_ODD
  */
__STATIC_INLINE uint32_t LL_UART_GetParity(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_PARITY_Msk));
}

/**
  * @brief    
  * @rmtoll   CSR    RXPOL    LL_UART_SetRXPinLevel
  * @param    UARTx UART instance
  * @param    level This parameter can be one of the following values:
  *           @arg @ref LL_UART_RXPIN_LEVEL_STANDARD
  *           @arg @ref LL_UART_RXPIN_LEVEL_INVERTED
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetRXPinLevel(UART_Type* UARTx, uint32_t level)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_RXPOL_Msk, level);
}

/**
  * @brief    
  * @rmtoll   CSR    RXPOL    LL_UART_GetRXPinLevel
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_UART_RXPIN_LEVEL_STANDARD
  *           @arg @ref LL_UART_RXPIN_LEVEL_INVERTED
  */
__STATIC_INLINE uint32_t LL_UART_GetRXPinLevel(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_RXPOL_Msk));
}

/**
  * @brief    
  * @rmtoll   CSR    TXPOL    LL_UART_SetTXPinLevel
  * @param    UARTx UART instance
  * @param    level This parameter can be one of the following values:
  *           @arg @ref LL_UART_TXPIN_LEVEL_STANDARD
  *           @arg @ref LL_UART_TXPIN_LEVEL_INVERTED
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetTXPinLevel(UART_Type* UARTx, uint32_t level)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_TXPOL_Msk, level);
}

/**
  * @brief    
  * @rmtoll   CSR    TXPOL    LL_UART_GetTXPinLevel
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_UART_TXPIN_LEVEL_STANDARD
  *           @arg @ref LL_UART_TXPIN_LEVEL_INVERTED
  */
__STATIC_INLINE uint32_t LL_UART_GetTXPinLevel(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_TXPOL_Msk));
}

/**
  * @brief    
  * @rmtoll   CSR    RXEN    LL_UART_EnableDirectionRx
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_EnableDirectionRx(UART_Type* UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_RXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    RXEN    LL_UART_DisableDirectionRx
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_DisableDirectionRx(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_RXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    RXEN    LL_UART_IsEnbaledDirectionRx
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaledDirectionRx(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_RXEN_Msk) == UART_CSR_RXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    TXEN    LL_UART_EnableDirectionTx
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_EnableDirectionTx(UART_Type* UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_TXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    TXEN    LL_UART_DisableDirectionTx
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_DisableDirectionTx(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_TXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CSR    TXEN    LL_UART_IsEnbaledDirectionTx
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaledDirectionTx(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_TXEN_Msk) == UART_CSR_TXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXTOIE    LL_UART_EnableIT_ReceiveTimeOut
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_EnableIT_ReceiveTimeOut(UART_Type* UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXTOIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXTOIE    LL_UART_DisableIT_ReceiveTimeOut
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_DisableIT_ReceiveTimeOut(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_RXTOIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXTOIE    LL_UART_IsEnbaledIT_ReceiveTimeOut
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaledIT_ReceiveTimeOut(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_RXTOIE_Msk) == UART_IER_RXTOIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXERRIE    LL_UART_EnableIT_ReceiveError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_EnableIT_ReceiveError(UART_Type* UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXERRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXERRIE    LL_UART_DisableIT_ReceiveError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_DisableIT_ReceiveError(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_RXERRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXERRIE    LL_UART_IsEnbaledIT_ReceiveError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaledIT_ReceiveError(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_RXERRIE_Msk) == UART_IER_RXERRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXBFIE    LL_UART_EnableIT_ReceiveBuffFull
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_EnableIT_ReceiveBuffFull(UART_Type* UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXBFIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXBFIE    LL_UART_DisableIT_ReceiveBuffFull
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_DisableIT_ReceiveBuffFull(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_RXBFIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXBFIE    LL_UART_IsEnbaledIT_ReceiveBuffFull
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaledIT_ReceiveBuffFull(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_RXBFIE_Msk) == UART_IER_RXBFIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    NEWUPIE    LL_UART_EnableIT_NegtiveEdgeWakeup
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_EnableIT_NegtiveEdgeWakeup(UART_Type* UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_NEWUPIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    NEWUPIE    LL_UART_DisableIT_NegtiveEdgeWakeup
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_DisableIT_NegtiveEdgeWakeup(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_NEWUPIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    NEWUPIE    LL_UART_IsEnbaledIT_NegtiveEdgeWakeup
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaledIT_NegtiveEdgeWakeup(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_NEWUPIE_Msk) == UART_IER_NEWUPIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXBEIE    LL_UART_EnableIT_TxBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_EnableIT_TxBuffEmpty(UART_Type* UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TXBEIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXBEIE    LL_UART_DisableIT_TxBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_DisableIT_TxBuffEmpty(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_TXBEIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXBEIE    LL_UART_IsEnbaledIT_TxBuffEmpty
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaledIT_TxBuffEmpty(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_TXBEIE_Msk) == UART_IER_TXBEIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXSEIE    LL_UART_EnableIT_ShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_EnableIT_ShiftBuffEmpty(UART_Type* UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TXSEIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXSEIE    LL_UART_DisableIT_ShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_DisableIT_ShiftBuffEmpty(UART_Type* UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_TXSEIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXSEIE    LL_UART_IsEnbaledIT_ShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnbaledIT_ShiftBuffEmpty(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_TXSEIE_Msk) == UART_IER_TXSEIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    PERR    LL_UART_IsActiveFlag_PERR
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_PERR(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_PERR_Msk) == (UART_ISR_PERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    PERR    LL_UART_ClearFlag_PERR
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_ClearFlag_PERR(UART_Type* UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_PERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    FERR    LL_UART_IsActiveFlag_FERR
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_FERR(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_FERR_Msk) == (UART_ISR_FERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    FERR    LL_UART_ClearFlag_FERR
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_ClearFlag_FERR(UART_Type* UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_FERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    RXERR    LL_UART_IsActiveFlag_RXERR
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_RXERR(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_RXERR_Msk) == (UART_ISR_RXERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    RXERR    LL_UART_ClearFlag_RXERR
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_ClearFlag_RXERR(UART_Type* UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_RXERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    RXTO    LL_UART_IsActiveFlag_RXTO
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_RXTO(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_RXTO_Msk) == (UART_ISR_RXTO_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    RXTO    LL_UART_ClearFlag_RXTO
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_ClearFlag_RXTO(UART_Type* UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_RXTO_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    RXBF    LL_UART_IsActiveFlag_RXBF
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_RXBF(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_RXBF_Msk) == (UART_ISR_RXBF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    RXBF    LL_UART_ClearFlag_RXBF
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_ClearFlag_RXBF(UART_Type* UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_RXBF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    NEWUP    LL_UART_IsActiveFlag_NEWUP
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_NEWUP(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_NEWUP_Msk) == (UART_ISR_NEWUP_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    NEWUP    LL_UART_ClearFlag_NEWUP
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_ClearFlag_NEWUP(UART_Type* UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_NEWUP_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    TXBE    LL_UART_IsActiveFlag_TXBE
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_TXBE(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_TXBE_Msk) == (UART_ISR_TXBE_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    TXSE    LL_UART_IsActiveFlag_TXSE
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsActiveFlag_TXSE(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_TXSE_Msk) == (UART_ISR_TXSE_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    TXSE    LL_UART_ClearFlag_TXSE
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void LL_UART_ClearFlag_TXSE(UART_Type* UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_TXSE_Msk);
}

/**
  * @brief    
  * @rmtoll   TODR    TXDLY_LEN    LL_UART_SetTxTimeDelay
  * @param    UARTx UART instance
  * @param    time 
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetTxTimeDelay(UART_Type* UARTx, uint32_t time)
{
    MODIFY_REG(UARTx->TODR, (0xffU << 8U), (time << 8U));
}

/**
  * @brief    
  * @rmtoll   TODR    TXDLY_LEN    LL_UART_GetTxTimeDelay
  * @param    UARTx UART instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_UART_GetTxTimeDelay(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->TODR, 0xffU) >> 8U);
}

/**
  * @brief    
  * @rmtoll   TODR    RXDLY_LEN    LL_UART_SetRxTimeOut
  * @param    UARTx UART instance
  * @param    time 
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetRxTimeOut(UART_Type* UARTx, uint32_t time)
{
    MODIFY_REG(UARTx->TODR, (0xffU << 0U), (time << 0U));
}

/**
  * @brief    
  * @rmtoll   TODR    RXDLY_LEN    LL_UART_GetRxTimeOut
  * @param    UARTx UART instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_UART_GetRxTimeOut(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->TODR, 0xffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   RXBUF        LL_UART_ReceiveData
  * @param    UARTx UART instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_UART_ReceiveData(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RXBUF, 0x1ffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   TXBUF        LL_UART_TransmitData
  * @param    UARTx UART instance
  * @param    Data 
  * @retval   None
  */
__STATIC_INLINE void LL_UART_TransmitData(UART_Type* UARTx, uint32_t Data)
{
    MODIFY_REG(UARTx->TXBUF, (0x1ffU << 0U), (Data << 0U));
}

/**
  * @brief    
  * @rmtoll   BGR        LL_UART_SetBaudRate
  * @param    UARTx UART instance
  * @param    BaudRate 
  * @retval   None
  */
__STATIC_INLINE void LL_UART_SetBaudRate(UART_Type* UARTx, uint32_t BaudRate)
{
    MODIFY_REG(UARTx->BGR, (0xffffU << 0U), (BaudRate << 0U));
}

/**
  * @brief    
  * @rmtoll   BGR        LL_UART_GetBaudRate
  * @param    UARTx UART instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_UART_GetBaudRate(UART_Type* UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->BGR, 0xffffU) >> 0U);
}

/**
  * @}
  */

/** @defgroup UART_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_UART_DeInit(UART_Type *UARTx);
void LL_UART_StructInit(LL_UART_InitTypeDef *UART_InitStruct);
ErrorStatus LL_UART_Init(UART_Type *UARTx, LL_UART_InitTypeDef *UART_InitStruct);
void LL_UART_InfraRed_StructInit(LL_UART_InfraRed_InitTypeDef *InfraRed_InitStruct);
ErrorStatus LL_UART_InfraRed_Init(UART_Type *UARTx, LL_UART_InfraRed_InitTypeDef *InfraRed_InitStruct);
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_UART_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-09-19**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
