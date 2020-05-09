/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_dma.h
  * @author  FMSH Application Team
  * @brief   Head file of DMA LL Module
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
/********************************************DMA channel mapping*****************************************                                                                  
        -------------------------------------------------------------------------------------------------
        |Channel|   0     |    1    |     2    |    3    |        4        |         5    |    6         |
        --------------------------------------------------------------------------------------------------
        |Func1  |ADC      |UARTRX0  | SPI2RX   |SPI1_RX  |ADC              |SPI1RX        |SPI1_TX       |
        -----------------------------------------------------------------------------------------
        |Func2  |LPUART0RX|LPUART0TX| UARTTX0  |UARTRX0  |SPI1_TX          |SPI2RX        |SPI2_TX       |
        --------------------------------------------------------------------------------------------------
        |Func3  |LPUART1TX|IICRX    | UARTRX0  |UARTRX1  |SPI2_TX          |UARTRX1       |UARTTX1       |
        --------------------------------------------------------------------------------------------------
        |Func4  |AESIN    |AESOUT   | LPUART1RX|UARTTX4  |UARTTX0          |LPUART0TX     |UARTTX5       |
        --------------------------------------------------------------------------------------------------
        |Func5  |CRC      |ATIMCH2  | IICTX    |LPUART0RX|UARTTX1          |LPUART1RX     |LPUART1_TX    |
        --------------------------------------------------------------------------------------------------
        |Func6  |ATIMCH1  |GTIM1CH2 | ATIMCH3  |ATIMCH4  |UARTRX5          |U7816RX       |U7816TX       |
        --------------------------------------------------------------------------------------------------
        |Func7  |GTIM1CH1 |GTIM2CH2 | GTIM1CH3 |GTIM1CH4 |I2C_RX           |GTIM2TRIG/UEV |I2C_TX        |
        -----------------------------------------------------------------------------------------------------------
        |Func8  |GTIM2CH1 |LPTIMCH1 | GTIM2CH3 |GTIM2CH4 |ATIMTRIG/COM/UEV |LPT32CH2      |GTIM1TRIG\UEV |
        --------------------------------------------------------------------------------------------------
********************************************DMA channel mapping*****************************************/                                                                                 


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33LC0XX_LL_DMA_H
#define __FM33LC0XX_LL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_DMA
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup DMA_LL_ES_INIT DMA Exported Init structures
  * @{
  */

/**
  * @brief LL DMA Init Sturcture definition
  */
typedef struct
{
    /*! DMA外设映射地址 */    
    uint32_t PeriphAddress;  
    /*! RAM地址 */ 
    uint32_t MemoryAddress;  
    /*! DMA传输方向 */ 
    uint32_t Direction;                                 
    /*! RAM地址增长方向 */ 
    uint32_t MemoryAddressIncMode;
    /*! RAM地址增长方向 */ 
    uint32_t FlashAddressIncMode;    
    /*! DAM传输通道数据位宽 */ 
    uint32_t DataSize;  
    /*! DMA传输数据字节个数 */ 
    uint32_t NbData;                                 
    /*! DMA通道优先级 */  
    uint32_t Priority;                         
    /*! 循环模式使能 */
    uint32_t CircMode;
  
} LL_DMA_InitTypeDef;

/**
  * @brief Configuration with temporary structure variable users will not be used directly
  */    
typedef struct
{    
    __IO uint32_t CHCR;  
    __IO uint32_t CHMAD; 
} CHANNEL;
/**
  * @brief Configuration with temporary structure variable users will not be used directly
  */
typedef struct
{    
    __IO uint32_t RESV; 
    __IO CHANNEL  Channel[7];
	__IO uint32_t CH7CR;  	
	__IO uint32_t CH7FLSAD; 
	__IO uint32_t CH7MAD;
}DMA_ADDR;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Constants DMA Exported Constants
  * @{
  */
#define    LL_DMA_CHANNEL_0                                       (0x0U << 0U)
#define    LL_DMA_CHANNEL_1                                       (0x1U << 0U)
#define    LL_DMA_CHANNEL_2                                       (0x2U << 0U)
#define    LL_DMA_CHANNEL_3                                       (0x3U << 0U)
#define    LL_DMA_CHANNEL_4                                       (0x4U << 0U)
#define    LL_DMA_CHANNEL_5                                       (0x5U << 0U)
#define    LL_DMA_CHANNEL_6                                       (0x6U << 0U)
#define    LL_DMA_CHANNEL_7                                       (0x7U << 0U)

#define    LL_DMA_CHANNEL_PRIORITY_LOW                            (0x0U << DMA_CHCR_PRI_Pos)
#define    LL_DMA_CHANNEL_PRIORITY_MEDIUM                         (0x1U << DMA_CHCR_PRI_Pos)
#define    LL_DMA_CHANNEL_PRIORITY_HIGH                           (0x2U << DMA_CHCR_PRI_Pos)
#define    LL_DMA_CHANNEL_PRIORITY_VERYHIGH                       (0x3U << DMA_CHCR_PRI_Pos)

#define    LL_DMA_INCREMENTAL_INCREASE                            (0x1U << DMA_CHCR_INC_Pos)
#define    LL_DMA_INCREMENTAL_REDUCE                              (0x0U << DMA_CHCR_INC_Pos)

#define    LL_DMA_PERIPHERAL_FUNCTION1                            (0x0U << DMA_CHCR_SSEL_Pos)
#define    LL_DMA_PERIPHERAL_FUNCTION2                            (0x1U << DMA_CHCR_SSEL_Pos)
#define    LL_DMA_PERIPHERAL_FUNCTION3                            (0x2U << DMA_CHCR_SSEL_Pos)
#define    LL_DMA_PERIPHERAL_FUNCTION4                            (0x3U << DMA_CHCR_SSEL_Pos)
#define    LL_DMA_PERIPHERAL_FUNCTION5                            (0x4U << DMA_CHCR_SSEL_Pos)
#define    LL_DMA_PERIPHERAL_FUNCTION6                            (0x5U << DMA_CHCR_SSEL_Pos)
#define    LL_DMA_PERIPHERAL_FUNCTION7                            (0x6U << DMA_CHCR_SSEL_Pos)
#define    LL_DMA_PERIPHERAL_FUNCTION8                            (0x7U << DMA_CHCR_SSEL_Pos)

#define    LL_DMA_DIR_PERIPHERAL_TO_RAM                           (0x0U << DMA_CHCR_DIR_Pos)
#define    LL_DMA_DIR_RAM_TO_PERIPHERAL                           (0x1U << DMA_CHCR_DIR_Pos)

#define    LL_DMA_BAND_WIDTH_BYTE                                 (0x0U << DMA_CHCR_BDW_Pos)
#define    LL_DMA_BAND_WIDTH_HALF_WORD                            (0x1U << DMA_CHCR_BDW_Pos)
#define    LL_DMA_BAND_WIDTH_WORD                                 (0x2U << DMA_CHCR_BDW_Pos)




#define    LL_DMA_DIR_FLASH_TO_RAM                                (0x1U << DMA_CH7CR_DIR_Pos)
#define    LL_DMA_DIR_RAM_TO_FLASH                                (0x0U << DMA_CH7CR_DIR_Pos)

#define    LL_DMA_CH7_RAM_ADDR_INCREASE                           (0x1U << DMA_CH7CR_RAM_INC_Pos)
#define    LL_DMA_CH7_RAM_ADDR_REDUCE                             (0x0U << DMA_CH7CR_RAM_INC_Pos)

#define    LL_DMA_CH7_FLASH_ADDR_INCREASE                         (0x1U << DMA_CH7CR_FLASH_INC_Pos)
#define    LL_DMA_CH7_FLASH_ADDR_REDUCE                           (0x0U << DMA_CH7CR_FLASH_INC_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Functions DMA Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   GCR    ADDRERR_EN    LL_DMA_EnableIT_GloableAddrErr
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_EnableIT_GloableAddrErr(DMA_Type* DMAx)
{
    SET_BIT(DMAx->GCR, DMA_GCR_ADDRERR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   GCR    ADDRERR_EN    LL_DMA_IsEnabledIT_GloableAddrErr
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_GloableAddrErr(DMA_Type* DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->GCR, DMA_GCR_ADDRERR_EN_Msk) == DMA_GCR_ADDRERR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   GCR    ADDRERR_EN    LL_DMA_DisableIT_GloableAddrErr
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_DisableIT_GloableAddrErr(DMA_Type* DMAx)
{
    CLEAR_BIT(DMAx->GCR, DMA_GCR_ADDRERR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   GCR    EN    LL_DMA_Enable_DMA
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_Enable_DMA(DMA_Type* DMAx)
{
    SET_BIT(DMAx->GCR, DMA_GCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   GCR    EN    LL_DMA_IsEnabled_DMA
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabled_DMA(DMA_Type* DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->GCR, DMA_GCR_EN_Msk) == DMA_GCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   GCR    EN    LL_DMA_Disable_DMA
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_Disable_DMA(DMA_Type* DMAx)
{
    CLEAR_BIT(DMAx->GCR, DMA_GCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CHCR    TSIZE    LL_DMA_SetTransmissionSize
  * @param    DMAx DMA instance
  * @param    TransmissionSize 
  * @param    Channel 
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_SetTransmissionSize(DMA_Type* DMAx, uint32_t TransmissionSize, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[Channel].CHCR, (0xffffU << 16U), (TransmissionSize << 16U));
    }
    else
    {
        MODIFY_REG(Temp->CH7CR, (0xffffU << 16U), (TransmissionSize << 16U));
    }
}

/**
  * @brief    
  * @rmtoll   CHCR    TSIZE    LL_DMA_GetTransmissionSize
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   
  */
__STATIC_INLINE uint32_t LL_DMA_GetTransmissionSize(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, 0xffffU) >> 16U);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, 0xffffU) >> 16U);
    }
}

/**
  * @brief    
  * @rmtoll   CHCR    PRI    LL_DMA_SetChannelPriority
  * @param    DMAx DMA instance
  * @param    Priority This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_PRIORITY_LOW
  *           @arg @ref LL_DMA_CHANNEL_PRIORITY_MEDIUM
  *           @arg @ref LL_DMA_CHANNEL_PRIORITY_HIGH
  *           @arg @ref LL_DMA_CHANNEL_PRIORITY_VERYHIGH
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_SetChannelPriority(DMA_Type* DMAx, uint32_t Priority, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[Channel].CHCR, DMA_CHCR_PRI_Msk, Priority);
    }
    else
    {
        MODIFY_REG(Temp->CH7CR, DMA_CHCR_PRI_Msk, Priority);
    }
    
}

/**
  * @brief    
  * @rmtoll   CHCR    PRI    LL_DMA_GetChannelPriority
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_PRIORITY_LOW
  *           @arg @ref LL_DMA_CHANNEL_PRIORITY_MEDIUM
  *           @arg @ref LL_DMA_CHANNEL_PRIORITY_HIGH
  *           @arg @ref LL_DMA_CHANNEL_PRIORITY_VERYHIGH
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelPriority(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_PRI_Msk));
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_PRI_Msk));
    }
}

/**
  * @brief    
  * @rmtoll   CHCR    INC    LL_DMA_SetChannelAddrIncremental
  * @param    DMAx DMA instance
  * @param    Incremental This parameter can be one of the following values:
  *           @arg @ref LL_DMA_INCREMENTAL_INCREASE
  *           @arg @ref LL_DMA_INCREMENTAL_REDUCE
  *           @arg @ref LL_DMA_CH7_RAM_ADDR_INCREASE 
  *           @arg @ref LL_DMA_CH7_RAM_ADDR_REDUCE
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_SetChannelAddrIncremental(DMA_Type* DMAx, uint32_t Incremental, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[Channel].CHCR, DMA_CHCR_INC_Msk, Incremental);
    }
    else
    {
        MODIFY_REG(Temp->CH7CR, DMA_CH7CR_RAM_INC_Msk, Incremental);
    }
}

/**
  * @brief    
  * @rmtoll   CHCR    INC    LL_DMA_GetChannelAddrIncremental
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_DMA_INCREMENTAL_INCREASE
  *           @arg @ref LL_DMA_INCREMENTAL_REDUCE
  *           @arg @ref LL_DMA_CH7_RAM_ADDR_INCREASE 
  *           @arg @ref LL_DMA_CH7_RAM_ADDR_REDUCE
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelAddrIncremental(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_INC_Msk));
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CH7CR_RAM_INC_Msk));
    }
}
/**
  * @brief    
  * @rmtoll   CH7CR    INC    LL_DMA_SetFlash_AddrIncremental
  * @param    DMAx DMA instance
  * @param    Incremental This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CH7_FLASH_ADDR_INCREASE 
  *           @arg @ref LL_DMA_CH7_FLASH_ADDR_REDUCE   
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_SetFlash_AddrIncremental(DMA_Type* DMAx, uint32_t Incremental)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    MODIFY_REG(Temp->CH7CR, DMA_CH7CR_FLASH_INC_Msk, Incremental);
}

/**
  * @brief    
  * @rmtoll   CHCR    INC    LL_DMA_GetFlashAddrIncremental
  * @param    DMAx DMA instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_DMA_CH7_FLASH_ADDR_INCREASE 
  *           @arg @ref LL_DMA_CH7_FLASH_ADDR_REDUCE   
  */
__STATIC_INLINE uint32_t LL_DMA_GetFlashAddrIncremental(DMA_Type* DMAx)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CH7CR_FLASH_INC_Msk));
}
/**
  * @brief    
  * @rmtoll   CHCR    SSEL    LL_DMA_SetChannelPeripheralMap
  * @param    DMAx DMA instance
  * @param    PeripheralMap This parameter can be one of the following values:
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION1
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION2
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION3
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION4
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION5
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION6
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION7
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION8
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_SetChannelPeripheralMap(DMA_Type* DMAx, uint32_t PeripheralMap, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[Channel].CHCR, DMA_CHCR_SSEL_Msk, PeripheralMap);
    }
}

/**
  * @brief    
  * @rmtoll   CHCR    SSEL    LL_DMA_GetChannelPeripheralMap
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION1
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION2
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION3
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION4
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION5
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION6
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION7
  *           @arg @ref LL_DMA_PERIPHERAL_FUNCTION8
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelPeripheralMap(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_SSEL_Msk));
    }
    return 0;
}

/**
  * @brief    
  * @rmtoll   CHCR    DIR    LL_DMA_SetChannelTransDirection
  * @param    DMAx DMA instance
  * @param    TransDirection This parameter can be one of the following values:
  *           @arg @ref LL_DMA_DIR_PERIPHERAL_TO_RAM
  *           @arg @ref LL_DMA_DIR_RAM_TO_PERIPHERAL
  *           @arg @ref LL_DMA_DIR_FLASH_TO_RAM  
  *           @arg @ref LL_DMA_DIR_RAM_TO_FLASH  

  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_SetChannelTransDirection(DMA_Type* DMAx, uint32_t TransDirection, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[Channel].CHCR, DMA_CHCR_DIR_Msk, TransDirection);
    }
    else
    {
        MODIFY_REG(Temp->CH7CR, DMA_CH7CR_DIR_Msk, TransDirection);
    }  
}

/**
  * @brief    
  * @rmtoll   CHCR    DIR    LL_DMA_GetChannelTransDirection
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_DMA_DIR_PERIPHERAL_TO_RAM
  *           @arg @ref LL_DMA_DIR_RAM_TO_PERIPHERAL
  *           @arg @ref LL_DMA_DIR_FLASH_TO_RAM  
  *           @arg @ref LL_DMA_DIR_RAM_TO_FLASH
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelTransDirection(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_DIR_Msk));
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CH7CR_DIR_Msk));
    }  
}

/**
  * @brief    
  * @rmtoll   CHCR    BDW    LL_DMA_SetChannelBandWidth
  * @param    DMAx DMA instance
  * @param    BandWidth This parameter can be one of the following values:
  *           @arg @ref LL_DMA_BAND_WIDTH_BYTE
  *           @arg @ref LL_DMA_BAND_WIDTH_HALF_WORD
  *           @arg @ref LL_DMA_BAND_WIDTH_WORD
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_SetChannelBandWidth(DMA_Type* DMAx, uint32_t BandWidth, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[Channel].CHCR, DMA_CHCR_BDW_Msk, BandWidth);
    }
}

/**
  * @brief    
  * @rmtoll   CHCR    BDW    LL_DMA_GetChannelBandWidth
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_DMA_BAND_WIDTH_BYTE
  *           @arg @ref LL_DMA_BAND_WIDTH_HALF_WORD
  *           @arg @ref LL_DMA_BAND_WIDTH_WORD
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelBandWidth(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_BDW_Msk));
    }
    return 0;
}

/**
  * @brief    
  * @rmtoll   CHCR    CIRC    LL_DMA_Enable_CircularMode
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_Enable_CircularMode(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_CIRC_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk);
    }   
}

/**
  * @brief    
  * @rmtoll   CHCR    CIRC    LL_DMA_IsEnabled_CircularMode
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabled_CircularMode(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_CIRC_Msk) == DMA_CHCR_CIRC_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk) == DMA_CHCR_CIRC_Msk);
    }  
}

/**
  * @brief    
  * @rmtoll   CHCR    CIRC    LL_DMA_Disable_CircularMode
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_Disable_CircularMode(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_CIRC_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk);
    }  
}

/**
  * @brief    
  * @rmtoll   CHCR    FTIE    LL_DMA_EnableIT_FinishedTransfer
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_EnableIT_FinishedTransfer(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_FTIE_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_FTIE_Msk);
    }   
}

/**
  * @brief    
  * @rmtoll   CHCR    FTIE    LL_DMA_IsEnabledIT_FinishedTransfer
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_FinishedTransfer(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_FTIE_Msk) == DMA_CHCR_CIRC_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk) == DMA_CHCR_FTIE_Msk);
    }   
}

/**
  * @brief    
  * @rmtoll   CHCR    FTIE    LL_DMA_DisableIT_FinishedTransfer
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_DisableIT_FinishedTransfer(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_FTIE_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CHCR_FTIE_Msk);
    }   
}

/**
  * @brief    
  * @rmtoll   CHCR    HTIE    LL_DMA_EnableIT_HalfTransfer
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_EnableIT_HalfTransfer(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_HTIE_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_HTIE_Msk);
    }    
}

/**
  * @brief    
  * @rmtoll   CHCR    HTIE    LL_DMA_IsEnabledIT_HalfTransfer
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_HalfTransfer(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_HTIE_Msk) == DMA_CHCR_CIRC_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk) == DMA_CHCR_HTIE_Msk);
    }   
}

/**
  * @brief    
  * @rmtoll   CHCR    HTIE    LL_DMA_DisableIT_HalfTransfer
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_DisableIT_HalfTransfer(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_HTIE_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CHCR_HTIE_Msk);
    }     
}

/**
  * @brief    
  * @rmtoll   CHCR    EN    LL_DMA_Enable_Channel
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_Enable_Channel(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_EN_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_EN_Msk);
    }   
}

/**
  * @brief    
  * @rmtoll   CHCR    EN    LL_DMA_IsEnabled_Channel
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabled_Channel(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_EN_Msk) == DMA_CHCR_CIRC_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk) == DMA_CHCR_EN_Msk);
    }  
}

/**
  * @brief    
  * @rmtoll   CHCR    EN    LL_DMA_Disable_Channel
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_Disable_Channel(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[Channel].CHCR, DMA_CHCR_EN_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CHCR_EN_Msk);
    }    
}

/**
  * @brief    
  * @rmtoll   MEMAD        LL_DMA_SetChannelMemAddr
  * @param    DMAx DMA instance
  * @param    Data 
  * @param    Channel 
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_SetChannelMemAddr(DMA_Type* DMAx, uint32_t Data, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[Channel].CHMAD, (0xffffffffU ), (Data));
    }
    else
    {
        MODIFY_REG(Temp->CH7MAD, (0xffffffffU ), (Data));
    } 
}

/**
  * @brief    
  * @rmtoll   MEMAD        LL_DMA_GetChannelMemAddr
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelMemAddr(DMA_Type* DMAx, uint32_t Channel)
{
    DMA_ADDR*  Temp = (DMA_ADDR*)DMAx;
    
    if(Channel <= LL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[Channel].CHMAD, (0xffffffffU )));
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7MAD,(0xffffffffU )));
    } 

    
}

/**
  * @brief    
  * @rmtoll   CH7FLSAD        LL_DMA_SetChannelFlashAddr
  * @param    DMAx DMA instance
  * @param    Data 
  * @param    Channel 
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_SetChannelFlashAddr(DMA_Type* DMAx, uint32_t Data, uint32_t Channel)
{
    MODIFY_REG(DMAx->CH7FLSAD, (0xffffffffU ), (Data)); 
}

/**
  * @brief    
  * @rmtoll   CH7FLSAD        LL_DMA_GetChannelFlashAddr
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelFlashAddr(DMA_Type* DMAx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(DMAx->CH7FLSAD, (0xffffffffU ))); 
}

/**
  * @brief    
  * @rmtoll   ISR    ADDRERR    LL_DMA_IsActiveFlag_ADDRERR
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_ADDRERR(DMA_Type* DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->ISR, DMA_ISR_ADDRERR_Msk) == (DMA_ISR_ADDRERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    ADDRERR    LL_DMA_ClearFlag_ADDRERR
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_ADDRERR(DMA_Type* DMAx)
{
    WRITE_REG(DMAx->ISR, DMA_ISR_ADDRERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    CHFT    LL_DMA_IsActiveFlag_Finished
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_Finished(DMA_Type* DMAx, uint32_t Channel)
{
   return (uint32_t)(uint32_t)(READ_BIT(DMAx->ISR, (DMA_ISR_CHFT_Msk<<Channel)) == (DMA_ISR_CHFT_Msk<<Channel));
}

/**
  * @brief    
  * @rmtoll   ISR    CHFT    LL_DMA_ClearFlag_Finished
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_Finished(DMA_Type* DMAx, uint32_t Channel)
{
    WRITE_REG(DMAx->ISR, (DMA_ISR_CHFT_Msk<<Channel)); 
}

/**
  * @brief    
  * @rmtoll   ISR    CHHT    LL_DMA_IsActiveFlag_Half
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_Half(DMA_Type* DMAx, uint32_t Channel)
{
    return (uint32_t)(uint32_t)(READ_BIT(DMAx->ISR, (DMA_ISR_CHHT_Msk<<Channel)) == (DMA_ISR_CHHT_Msk<<Channel)); 
}

/**
  * @brief    
  * @rmtoll   ISR    CHHT    LL_DMA_ClearFlag_Half
  * @param    DMAx DMA instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_DMA_CHANNEL_0
  *           @arg @ref LL_DMA_CHANNEL_1
  *           @arg @ref LL_DMA_CHANNEL_2
  *           @arg @ref LL_DMA_CHANNEL_3
  *           @arg @ref LL_DMA_CHANNEL_4
  *           @arg @ref LL_DMA_CHANNEL_5
  *           @arg @ref LL_DMA_CHANNEL_6
  *           @arg @ref LL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_Half(DMA_Type* DMAx, uint32_t Channel)
{
    WRITE_REG(DMAx->ISR, (DMA_ISR_CHHT_Msk<<Channel)); 
}

/**
  * @}
  */

/** @defgroup DMA_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_DMA_DeInit(DMA_Type *DMAx);
ErrorStatus LL_DMA_Init(DMA_Type *DMAx,LL_DMA_InitTypeDef *DMA_InitStruct,uint32_t Channel);
ErrorStatus LL_StartOnceDMATransmion(DMA_Type *DMAx,LL_DMA_InitTypeDef *DMA_InitStruct ,uint32_t Channel);
void LL_DMA_StructInit(LL_DMA_InitTypeDef *InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_DMA_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-25**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
