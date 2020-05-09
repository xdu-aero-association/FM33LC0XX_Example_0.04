/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_rng.h
  * @author  FMSH Application Team
  * @brief   Head file of RNG LL Module
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
#ifndef __FM33LC0XX_LL_RNG_H
#define __FM33LC0XX_LL_RNG_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_RNG
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup RNG_LL_ES_INIT RNG Exported Init structures
  * @{
  */

/**
  * @brief LL RNG Init Sturcture definition
  */
typedef struct
{
    /* 预分频系数 RNG是使用RCHF作为时钟的*/
    uint32_t Prescaler; 

}LL_RNG_InitTypeDef;    
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup RNG_LL_Exported_Constants RNG Exported Constants
  * @{
  */

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup RNG_LL_Exported_Functions RNG Exported Functions
  * @{
  */

/**
  * @brief    RNG enable
  * @rmtoll   CR    EN    LL_RNG_Enable
  * @param    RNGx RNG instance
  * @retval   None
  */
__STATIC_INLINE void LL_RNG_Enable(RNGCTL_Type* RNGx)
{
    SET_BIT(RNGx->CR, RNG_CR_EN_Msk);
}

/**
  * @brief    RNG enable status
  * @rmtoll   CR    EN    LL_RNG_IsEnabled
  * @param    RNGx RNG instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RNG_IsEnabled(RNGCTL_Type* RNGx)
{
    return (uint32_t)(READ_BIT(RNGx->CR, RNG_CR_EN_Msk) == RNG_CR_EN_Msk);
}

/**
  * @brief    RNG disable
  * @rmtoll   CR    EN    LL_RNG_Disable
  * @param    RNGx RNG instance
  * @retval   None
  */
__STATIC_INLINE void LL_RNG_Disable(RNGCTL_Type* RNGx)
{
    CLEAR_BIT(RNGx->CR, RNG_CR_EN_Msk);
}

/**
  * @brief    Read RNG output data register
  * @rmtoll   DOR        LL_RNG_Read
  * @param    RNGx RNG instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RNG_Read(RNG_Type* RNGx)
{
    return (uint32_t)(READ_BIT(RNGx->DOR, 0xffffffffU) >> 0U);
}

/**
  * @brief    Get LFSR Flag
  * @rmtoll   SR    LFSREN    LL_RNG_IsActiveFlag_LFSREN
  * @param    RNGx RNG instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RNG_IsActiveFlag_LFSREN(RNG_Type* RNGx)
{
    return (uint32_t)(READ_BIT(RNGx->SR, RNG_SR_LFSREN_Msk) == (RNG_SR_LFSREN_Msk));
}

/**
  * @brief    Get random number fail flag
  * @rmtoll   SR    RNF    LL_RNG_IsActiveFlag_RandomFail
  * @param    RNGx RNG instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RNG_IsActiveFlag_RandomFail(RNG_Type* RNGx)
{
    return (uint32_t)(READ_BIT(RNGx->SR, RNG_SR_RNF_Msk) == (RNG_SR_RNF_Msk));
}

/**
  * @brief    Clear random number fail flag
  * @rmtoll   SR    RNF    LL_RNG_ClearFlag_RandomFail
  * @param    RNGx RNG instance
  * @retval   None
  */
__STATIC_INLINE void LL_RNG_ClearFlag_RandomFail(RNG_Type* RNGx)
{
    WRITE_REG(RNGx->SR, RNG_SR_RNF_Msk);
}

/**
  * @brief    CRC enable
  * @rmtoll   CRCCR    CRCEN    LL_RNG_EnableCRC
  * @param    RNGx RNG instance
  * @retval   None
  */
__STATIC_INLINE void LL_RNG_EnableCRC(RNG_Type* RNGx)
{
    SET_BIT(RNGx->CRCCR, RNG_CRCCR_CRCEN_Msk);
}

/**
  * @brief    Get CRC enable status
  * @rmtoll   CRCCR    CRCEN    LL_RNG_IsEnabledCRC
  * @param    RNGx RNG instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RNG_IsEnabledCRC(RNG_Type* RNGx)
{
    return (uint32_t)(READ_BIT(RNGx->CRCCR, RNG_CRCCR_CRCEN_Msk) == RNG_CRCCR_CRCEN_Msk);
}

/**
  * @brief    CRC disable
  * @rmtoll   CRCCR    CRCEN    LL_RNG_DisableCRC
  * @param    RNGx RNG instance
  * @retval   None
  */
__STATIC_INLINE void LL_RNG_DisableCRC(RNG_Type* RNGx)
{
    CLEAR_BIT(RNGx->CRCCR, RNG_CRCCR_CRCEN_Msk);
}

/**
  * @brief    Write CRC data input
  * @rmtoll   CRCDIR        LL_RNG_CrcWriteData
  * @param    RNGx RNG instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void LL_RNG_CrcWriteData(RNG_Type* RNGx, uint32_t data)
{
    MODIFY_REG(RNGx->CRCDIR, (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    Read CRC data input
  * @rmtoll   CRCDIR        LL_RNG_CrcReadData
  * @param    RNGx RNG instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RNG_CrcReadData(RNG_Type* RNGx)
{
    return (uint32_t)(READ_BIT(RNGx->CRCDIR, 0xffffffffU) >> 0U);
}

/**
  * @brief    Get CRC calculation done Flag
  * @rmtoll   CRCSR    CRCDONE    LL_RNG_IsActiveFlag_CRCCalculationFinish
  * @param    RNGx RNG instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RNG_IsActiveFlag_CRCCalculationFinish(RNG_Type* RNGx)
{
    return (uint32_t)(READ_BIT(RNGx->CRCSR, RNG_CRCSR_CRCDONE_Msk) == (RNG_CRCSR_CRCDONE_Msk));
}

/**
  * @brief    Clear CRC calculation done Flag
  * @rmtoll   CRCSR    CRCDONE    LL_RNG_ClearFlag_CRCCalculationFinish
  * @param    RNGx RNG instance
  * @retval   None
  */
__STATIC_INLINE void LL_RNG_ClearFlag_CRCCalculationFinish(RNG_Type* RNGx)
{
    CLEAR_BIT(RNGx->CRCSR, RNG_CRCSR_CRCDONE_Msk);
}

/**
  * @}
  */

/** @defgroup RNG_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_RNG_DeInit(RNG_Type *RNGx);
ErrorStatus LL_RNG_Init(RNG_Type* RNGx,LL_RNG_InitTypeDef *InitStruct);
uint32_t GetRandomNumber(void);
uint32_t GetCrc32(uint32_t dataIn);
void LL_RNG_StructInit(LL_RNG_InitTypeDef *InitStruct);


/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_RNG_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-12-02**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
