/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_aes.h
  * @author  FMSH Application Team
  * @brief   Head file of AES LL Module
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
#ifndef __FM33LC0XX_LL_AES_H
#define __FM33LC0XX_LL_AES_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_AES
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup AES_LL_ES_INIT AES Exported Init structures
  * @{
  */

/**
  * @brief LL AES Init Sturcture definition
  */
typedef struct
{
  /* 秘钥长度 */
  uint32_t KeyLenth;          
  /* 数据流处理模式 */
  uint32_t CipherMode;
  /* AES工作模式 */      
  uint32_t OperationMode;
  /* 输入数据类型 */                                             
  uint32_t DataType;
                                                      
} LL_AES_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup AES_LL_Exported_Constants AES Exported Constants
  * @{
  */
#define    LL_AES_KEY0_OFFSET                                     (0x1U)
#define    LL_AES_KEY1_OFFSET                                     (0x2U)
#define    LL_AES_KEY2_OFFSET                                     (0x3U)
#define    LL_AES_KEY3_OFFSET                                     (0x4U)
#define    LL_AES_KEY4_OFFSET                                     (0x5U)
#define    LL_AES_KEY5_OFFSET                                     (0x6U)
#define    LL_AES_KEY6_OFFSET                                     (0x7U)
#define    LL_AES_KEY7_OFFSET                                     (0x8U)
#define    LL_AES_IVR0_OFFSET                                     (0x0U)
#define    LL_AES_IVR1_OFFSET                                     (0x1U)
#define    LL_AES_IVR2_OFFSET                                     (0x2U)
#define    LL_AES_IVR3_OFFSET                                     (0x3U)

#define    LL_AES_KEY_LENTH_IS_128BITS                            (0x0U << AES_CR_KEYLEN_Pos)
#define    LL_AES_KEY_LENTH_IS_192BITS                            (0x1U << AES_CR_KEYLEN_Pos)
#define    LL_AES_KEY_LENTH_IS_256BITS                            (0x2U << AES_CR_KEYLEN_Pos)

#define    LL_AES_CIPHER_ECB_MODE                                 (0x0U << AES_CR_CHMOD_Pos)
#define    LL_AES_CIPHER_CBC_MODE                                 (0x1U << AES_CR_CHMOD_Pos)
#define    LL_AES_CIPHER_CTR_MODE                                 (0x2U << AES_CR_CHMOD_Pos)
#define    LL_AES_CIPHER_MULT_MODE                                (0x3U << AES_CR_CHMOD_Pos)

#define    LL_AES_OPERATION_MODE_ENCRYPTION                       (0x0U << AES_CR_MODE_Pos)
#define    LL_AES_OPERATION_MODE_KEY_EXTENSION                    (0x1U << AES_CR_MODE_Pos)
#define    LL_AES_OPERATION_MODE_DECRYPT                          (0x2U << AES_CR_MODE_Pos)
#define    LL_AES_OPERATION_MODE_KEY_EXTENSION_AND_DECRYPT        (0x3U << AES_CR_MODE_Pos)

#define    LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED                    (0x0U << AES_CR_DATATYP_Pos)
#define    LL_AES_DATA_SWAP_RULE_HAIFWORD_EXCHANGE                (0x1U << AES_CR_DATATYP_Pos)
#define    LL_AES_DATA_SWAP_RULE_BYTE_EXCHANGED                   (0x2U << AES_CR_DATATYP_Pos)
#define    LL_AES_DATA_SWAP_RULE_BIT_EXCHANGED                    (0x3U << AES_CR_DATATYP_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup AES_LL_Exported_Functions AES Exported Functions
  * @{
  */

/**
  * @brief    Set key size selection
  * @rmtoll   CR    KEYLEN    LL_AES_SetBitLenthofKeys
  * @param    AESx AES instance
  * @param    lenth This parameter can be one of the following values:
  *           @arg @ref LL_AES_KEY_LENTH_IS_128BITS
  *           @arg @ref LL_AES_KEY_LENTH_IS_192BITS
  *           @arg @ref LL_AES_KEY_LENTH_IS_256BITS
  * @retval   None
  */
__STATIC_INLINE void LL_AES_SetBitLenthofKeys(AES_Type* AESx, uint32_t lenth)
{
    MODIFY_REG(AESx->CR, AES_CR_KEYLEN_Msk, lenth);
}

/**
  * @brief    Get key size selection
  * @rmtoll   CR    KEYLEN    LL_AES_GetBitLenthofKeys
  * @param    AESx AES instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_AES_KEY_LENTH_IS_128BITS
  *           @arg @ref LL_AES_KEY_LENTH_IS_192BITS
  *           @arg @ref LL_AES_KEY_LENTH_IS_256BITS
  */
__STATIC_INLINE uint32_t LL_AES_GetBitLenthofKeys(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->CR, AES_CR_KEYLEN_Msk));
}

/**
  * @brief    DMA output enable
  * @rmtoll   CR    DMAOEN    LL_AES_Enable_DMA_AutoDataOutput
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_Enable_DMA_AutoDataOutput(AES_Type* AESx)
{
    SET_BIT(AESx->CR, AES_CR_DMAOEN_Msk);
}

/**
  * @brief    DMA output disable
  * @rmtoll   CR    DMAOEN    LL_AES_Disable_DMA_AutoDataOutput
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_Disable_DMA_AutoDataOutput(AES_Type* AESx)
{
    CLEAR_BIT(AESx->CR, AES_CR_DMAOEN_Msk);
}

/**
  * @brief    DMA input enable
  * @rmtoll   CR    DMAIEN    LL_AES_Enable_DMA_AutoDataInput
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_Enable_DMA_AutoDataInput(AES_Type* AESx)
{
    SET_BIT(AESx->CR, AES_CR_DMAIEN_Msk);
}

/**
  * @brief    DMA input disable
  * @rmtoll   CR    DMAIEN    LL_AES_Disable_DMA_AutoDataInput
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_Disable_DMA_AutoDataInput(AES_Type* AESx)
{
    CLEAR_BIT(AESx->CR, AES_CR_DMAIEN_Msk);
}

/**
  * @brief    Set cipher mode
  * @rmtoll   CR    CHMOD    LL_AES_SetCipherMode
  * @param    AESx AES instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_AES_CIPHER_ECB_MODE
  *           @arg @ref LL_AES_CIPHER_CBC_MODE
  *           @arg @ref LL_AES_CIPHER_CTR_MODE
  *           @arg @ref LL_AES_CIPHER_MULT_MODE
  * @retval   None
  */
__STATIC_INLINE void LL_AES_SetCipherMode(AES_Type* AESx, uint32_t mode)
{
    MODIFY_REG(AESx->CR, AES_CR_CHMOD_Msk, mode);
}

/**
  * @brief    Get cipher mode
  * @rmtoll   CR    CHMOD    LL_AES_GetCipherMode
  * @param    AESx AES instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_AES_CIPHER_ECB_MODE
  *           @arg @ref LL_AES_CIPHER_CBC_MODE
  *           @arg @ref LL_AES_CIPHER_CTR_MODE
  *           @arg @ref LL_AES_CIPHER_MULT_MODE
  */
__STATIC_INLINE uint32_t LL_AES_GetCipherMode(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->CR, AES_CR_CHMOD_Msk));
}

/**
  * @brief    Set operation mode
  * @rmtoll   CR    MODE    LL_AES_SetOpertionMode
  * @param    AESx AES instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_AES_OPERATION_MODE_ENCRYPTION
  *           @arg @ref LL_AES_OPERATION_MODE_KEY_EXTENSION
  *           @arg @ref LL_AES_OPERATION_MODE_DECRYPT
  *           @arg @ref LL_AES_OPERATION_MODE_KEY_EXTENSION_AND_DECRYPT
  * @retval   None
  */
__STATIC_INLINE void LL_AES_SetOpertionMode(AES_Type* AESx, uint32_t mode)
{
    MODIFY_REG(AESx->CR, AES_CR_MODE_Msk, mode);
}

/**
  * @brief    Get operation mode
  * @rmtoll   CR    MODE    LL_AES_GetOpertionMode
  * @param    AESx AES instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_AES_OPERATION_MODE_ENCRYPTION
  *           @arg @ref LL_AES_OPERATION_MODE_KEY_EXTENSION
  *           @arg @ref LL_AES_OPERATION_MODE_DECRYPT
  *           @arg @ref LL_AES_OPERATION_MODE_KEY_EXTENSION_AND_DECRYPT
  */
__STATIC_INLINE uint32_t LL_AES_GetOpertionMode(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->CR, AES_CR_MODE_Msk));
}

/**
  * @brief    Set data type selection
  * @rmtoll   CR    DATATYP    LL_AES_SetDataType
  * @param    AESx AES instance
  * @param    rule This parameter can be one of the following values:
  *           @arg @ref LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED
  *           @arg @ref LL_AES_DATA_SWAP_RULE_HAIFWORD_EXCHANGE
  *           @arg @ref LL_AES_DATA_SWAP_RULE_BYTE_EXCHANGED
  *           @arg @ref LL_AES_DATA_SWAP_RULE_BIT_EXCHANGED
  * @retval   None
  */
__STATIC_INLINE void LL_AES_SetDataType(AES_Type* AESx, uint32_t rule)
{
    MODIFY_REG(AESx->CR, AES_CR_DATATYP_Msk, rule);
}

/**
  * @brief    Get data type selection
  * @rmtoll   CR    DATATYP    LL_AES_GetDataType
  * @param    AESx AES instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED
  *           @arg @ref LL_AES_DATA_SWAP_RULE_HAIFWORD_EXCHANGE
  *           @arg @ref LL_AES_DATA_SWAP_RULE_BYTE_EXCHANGED
  *           @arg @ref LL_AES_DATA_SWAP_RULE_BIT_EXCHANGED
  */
__STATIC_INLINE uint32_t LL_AES_GetDataType(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->CR, AES_CR_DATATYP_Msk));
}

/**
  * @brief    AES enable
  * @rmtoll   CR    EN    LL_AES_Enable
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_Enable(AES_Type* AESx)
{
    SET_BIT(AESx->CR, AES_CR_EN_Msk);
}

/**
  * @brief    Get AES enable status
  * @rmtoll   CR    EN    LL_AES_IsEnabled
  * @param    AESx AES instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_AES_IsEnabled(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->CR, AES_CR_EN_Msk) == AES_CR_EN_Msk);
}

/**
  * @brief    AES disable
  * @rmtoll   CR    EN    LL_AES_Disable
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_Disable(AES_Type* AESx)
{
    CLEAR_BIT(AESx->CR, AES_CR_EN_Msk);
}

/**
  * @brief    Write error interrupt enable
  * @rmtoll   IER    WRERR_IE    LL_AES_IT_Write_Err_Enable
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_IT_Write_Err_Enable(AES_Type* AESx)
{
    SET_BIT(AESx->IER, AES_IER_WRERR_IE_Msk);
}

/**
  * @brief    Get write error interrupt enable status
  * @rmtoll   IER    WRERR_IE    LL_AES_IT_Write_Err_IsEnabled
  * @param    AESx AES instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_AES_IT_Write_Err_IsEnabled(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->IER, AES_IER_WRERR_IE_Msk) == AES_IER_WRERR_IE_Msk);
}

/**
  * @brief    Write error interrupt disable
  * @rmtoll   IER    WRERR_IE    LL_AES_IT_Write_Err_Disable
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_IT_Write_Err_Disable(AES_Type* AESx)
{
    CLEAR_BIT(AESx->IER, AES_IER_WRERR_IE_Msk);
}

/**
  * @brief    Read error interrupt enable
  * @rmtoll   IER    RDERR_IE    LL_AES_IT_Read_Err_Enable
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_IT_Read_Err_Enable(AES_Type* AESx)
{
    SET_BIT(AESx->IER, AES_IER_RDERR_IE_Msk);
}

/**
  * @brief    Get read Error interrupt enable status
  * @rmtoll   IER    RDERR_IE    LL_AES_IT_Read_Err_IsEnabled
  * @param    AESx AES instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_AES_IT_Read_Err_IsEnabled(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->IER, AES_IER_RDERR_IE_Msk) == AES_IER_RDERR_IE_Msk);
}

/**
  * @brief    Read error interrupt disable
  * @rmtoll   IER    RDERR_IE    LL_AES_IT_Read_Err_Disable
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_IT_Read_Err_Disable(AES_Type* AESx)
{
    CLEAR_BIT(AESx->IER, AES_IER_RDERR_IE_Msk);
}

/**
  * @brief    Cipher complete interrupt enable
  * @rmtoll   IER    CCF_IE    LL_AES_IT_Complete_Enable
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_IT_Complete_Enable(AES_Type* AESx)
{
    SET_BIT(AESx->IER, AES_IER_CCF_IE_Msk);
}

/**
  * @brief    Get cipher complete interrupt enable status
  * @rmtoll   IER    CCF_IE    LL_AES_IT_Complete_IsEnabled
  * @param    AESx AES instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_AES_IT_Complete_IsEnabled(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->IER, AES_IER_CCF_IE_Msk) == AES_IER_CCF_IE_Msk);
}

/**
  * @brief    Cipher complete interrupt disable
  * @rmtoll   IER    CCF_IE    LL_AES_IT_Complete_Disable
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_IT_Complete_Disable(AES_Type* AESx)
{
    CLEAR_BIT(AESx->IER, AES_IER_CCF_IE_Msk);
}

/**
  * @brief    Get write error flag
  * @rmtoll   ISR    WRERR    LL_AES_IsActiveFlag_WriteERROR
  * @param    AESx AES instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_AES_IsActiveFlag_WriteERROR(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->ISR, AES_ISR_WRERR_Msk) == (AES_ISR_WRERR_Msk));
}

/**
  * @brief    Clear write error flag
  * @rmtoll   ISR    WRERR    LL_AES_ClearFlag_WriteERROR
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_ClearFlag_WriteERROR(AES_Type* AESx)
{
    WRITE_REG(AESx->ISR, AES_ISR_WRERR_Msk);
}

/**
  * @brief    Get read error flag
  * @rmtoll   ISR    RDERR    LL_AES_IsActiveFlag_ReadERROR
  * @param    AESx AES instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_AES_IsActiveFlag_ReadERROR(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->ISR, AES_ISR_RDERR_Msk) == (AES_ISR_RDERR_Msk));
}

/**
  * @brief    Clear read error flag
  * @rmtoll   ISR    RDERR    LL_AES_ClearFlag_ReadERROR
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_ClearFlag_ReadERROR(AES_Type* AESx)
{
    WRITE_REG(AESx->ISR, AES_ISR_RDERR_Msk);
}

/**
  * @brief    Get cipher complete flag
  * @rmtoll   ISR    CCF    LL_AES_IsActiveFlag_Complete
  * @param    AESx AES instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_AES_IsActiveFlag_Complete(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->ISR, AES_ISR_CCF_Msk) == (AES_ISR_CCF_Msk));
}

/**
  * @brief    Clear cipher complete flag
  * @rmtoll   ISR    CCF    LL_AES_ClearFlag_Complete
  * @param    AESx AES instance
  * @retval   None
  */
__STATIC_INLINE void LL_AES_ClearFlag_Complete(AES_Type* AESx)
{
    WRITE_REG(AESx->ISR, AES_ISR_CCF_Msk);
}

/**
  * @brief    Write AES data input register
  * @rmtoll   DIR        LL_AES_WriteDataToDIR
  * @param    AESx AES instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void LL_AES_WriteDataToDIR(AES_Type* AESx, uint32_t data)
{
    MODIFY_REG(AESx->DIR, (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    Read AES data input register
  * @rmtoll   DIR        LL_AES_ReadDataToDIR
  * @param    AESx AES instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_AES_ReadDataToDIR(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->DIR, 0xffffffffU) >> 0U);
}

/**
  * @brief    Read AES data output register
  * @rmtoll   DOR        LL_AES_ReadDataFromDOR
  * @param    AESx AES instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_AES_ReadDataFromDOR(AES_Type* AESx)
{
    return (uint32_t)(READ_BIT(AESx->DOR, 0xffffffffU) >> 0U);
}

/**
  * @brief    Set key registers
  * @rmtoll   KEY0        LL_AES_SetKeys
  * @param    AESx AES instance
  * @param    KEYx This parameter can be one of the following values:
  *           @arg @ref LL_AES_KEY0_OFFSET
  *           @arg @ref LL_AES_KEY1_OFFSET
  *           @arg @ref LL_AES_KEY2_OFFSET
  *           @arg @ref LL_AES_KEY3_OFFSET
  *           @arg @ref LL_AES_KEY4_OFFSET
  *           @arg @ref LL_AES_KEY5_OFFSET
  *           @arg @ref LL_AES_KEY6_OFFSET
  *           @arg @ref LL_AES_KEY7_OFFSET
  * @param    data This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void LL_AES_SetKeys(AES_Type* AESx, uint32_t KEYx, uint32_t data)
{
    WRITE_REG(*(((uint32_t*)&AESx->KEY0)+KEYx), data); 
}

/**
  * @brief    Get key registers
  * @rmtoll   KEY0        LL_AES_GetKeys
  * @param    AESx AES instance
  * @param    KEYx This parameter can be one of the following values:
  *           @arg @ref LL_AES_KEY0_OFFSET
  *           @arg @ref LL_AES_KEY1_OFFSET
  *           @arg @ref LL_AES_KEY2_OFFSET
  *           @arg @ref LL_AES_KEY3_OFFSET
  *           @arg @ref LL_AES_KEY4_OFFSET
  *           @arg @ref LL_AES_KEY5_OFFSET
  *           @arg @ref LL_AES_KEY6_OFFSET
  *           @arg @ref LL_AES_KEY7_OFFSET
  * @retval   
  */
__STATIC_INLINE uint32_t LL_AES_GetKeys(AES_Type* AESx, uint32_t KEYx)
{
    return (uint32_t)READ_REG(*(((uint32_t*)&AESx->KEY0)+KEYx)); 
}

/**
  * @brief    Write initialization vector registers
  * @rmtoll   IVR        LL_AES_WriteDataToIVR
  * @param    AESx AES instance
  * @param    IVRx 
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void LL_AES_WriteDataToIVR(AES_Type* AESx, uint32_t IVRx, uint32_t data)
{
    WRITE_REG(*(((uint32_t*)&AESx->IVR0)+IVRx), data);  
}

/**
  * @brief    Read initialization vector registers
  * @rmtoll   IVR        LL_AES_ReadDataFromIVR
  * @param    AESx AES instance
  * @param    IVRx This parameter can be one of the following values:
  *           @arg @ref LL_AES_IVR0_OFFSET
  *           @arg @ref LL_AES_IVR1_OFFSET
  *           @arg @ref LL_AES_IVR2_OFFSET
  *           @arg @ref LL_AES_IVR3_OFFSET
  * @retval   
  */
__STATIC_INLINE uint32_t LL_AES_ReadDataFromIVR(AES_Type* AESx, uint32_t IVRx)
{
    return (uint32_t)READ_REG(*(((uint32_t*)&AESx->IVR0)+IVRx)); 
}

/**
  * @}
  */

/** @defgroup AES_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_AES_DeInit(void);
void LL_AES_StructInit(LL_AES_InitTypeDef* AES_InitStructer);
ErrorStatus LL_AES_Init(AES_Type* AESx,LL_AES_InitTypeDef* AES_InitStructer);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_AES_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-12-02**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
