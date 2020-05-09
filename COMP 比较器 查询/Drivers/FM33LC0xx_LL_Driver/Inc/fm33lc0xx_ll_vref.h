/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_vref.h
  * @author  FMSH Application Team
  * @brief   Head file of VREF LL Module
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
#ifndef __FM33LC0XX_LL_VREF_H
#define __FM33LC0XX_LL_VREF_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_VREF
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup VREF_LL_ES_INIT VREF Exported Init structures
  * @{
  */

/**
  * @brief LL VREF Init Sturcture definition
  */
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup VREF_LL_Exported_Constants VREF Exported Constants
  * @{
  */

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup VREF_LL_Exported_Functions VREF Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CR    VREF_EN    LL_VREF_EnableVREF
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_EnableVREF(VREF_Type* VREFx)
{
    SET_BIT(VREFx->CR, VREF_CR_VREF_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    VREF_EN    LL_VREF_IsEnabledVREF
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsEnabledVREF(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->CR, VREF_CR_VREF_EN_Msk) == VREF_CR_VREF_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    VREF_EN    LL_VREF_DisableVREF
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_DisableVREF(VREF_Type* VREFx)
{
    CLEAR_BIT(VREFx->CR, VREF_CR_VREF_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    PTAT_EN    LL_VREF_EnableTemperatureSensor
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_EnableTemperatureSensor(VREF_Type* VREFx)
{
    SET_BIT(VREFx->CR, VREF_CR_PTAT_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    PTAT_EN    LL_VREF_IsEnabledTemperatureSensor
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsEnabledTemperatureSensor(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->CR, VREF_CR_PTAT_EN_Msk) == VREF_CR_PTAT_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    PTAT_EN    LL_VREF_DisableTemperatureSensor
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_DisableTemperatureSensor(VREF_Type* VREFx)
{
    CLEAR_BIT(VREFx->CR, VREF_CR_PTAT_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   SR    FLAG    LL_VREF_IsActiveFlag_VREFFlag
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsActiveFlag_VREFFlag(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->SR, VREF_SR_FLAG_Msk) == (VREF_SR_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   SR    RDY    LL_VREF_IsActiveFlag_VREFReady
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsActiveFlag_VREFReady(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->SR, VREF_SR_RDY_Msk) == (VREF_SR_RDY_Msk));
}

/**
  * @brief    
  * @rmtoll   SR    IF    LL_VREF_IsActiveFlag_VREFIF
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsActiveFlag_VREFIF(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->SR, VREF_SR_IF_Msk) == (VREF_SR_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   SR    IF    LL_VREF_ClearFlag_VREFIF
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_ClearFlag_VREFIF(VREF_Type* VREFx)
{
    WRITE_REG(VREFx->SR, VREF_SR_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    IE    LL_VREF_EnableITVREFReady
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_EnableITVREFReady(VREF_Type* VREFx)
{
    SET_BIT(VREFx->IER, VREF_IER_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    IE    LL_VREF_IsEnabledITVREFReady
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsEnabledITVREFReady(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->IER, VREF_IER_IE_Msk) == VREF_IER_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    IE    LL_VREF_DisableITVREFReady
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_DisableITVREFReady(VREF_Type* VREFx)
{
    CLEAR_BIT(VREFx->IER, VREF_IER_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    LL_VREF_EnableVPTATBufferOutPut
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_EnableVPTATBufferOutPut(VREF_Type* VREFx)
{
    SET_BIT(VREFx->BUFCR, VREF_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    LL_VREF_IsEnabledVPTATBufferOutPut
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsEnabledVPTATBufferOutPut(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->BUFCR, VREF_BUFCR_VPTATBUFFER_OUTEN_Msk) == VREF_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    LL_VREF_DisableVPTATBufferOutPut
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_DisableVPTATBufferOutPut(VREF_Type* VREFx)
{
    CLEAR_BIT(VREFx->BUFCR, VREF_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VPTATBUFFER_EN    LL_VREF_EnableVPTATBuffer
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_EnableVPTATBuffer(VREF_Type* VREFx)
{
    SET_BIT(VREFx->BUFCR, VREF_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VPTATBUFFER_EN    LL_VREF_IsEnabledVPTATBuffer
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsEnabledVPTATBuffer(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->BUFCR, VREF_BUFCR_VPTATBUFFER_EN_Msk) == VREF_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VPTATBUFFER_EN    LL_VREF_DisableVPTATBuffer
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_DisableVPTATBuffer(VREF_Type* VREFx)
{
    CLEAR_BIT(VREFx->BUFCR, VREF_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VREFBUFFER_OUTEN    LL_VREF_EnableVREFBufferOutPut
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_EnableVREFBufferOutPut(VREF_Type* VREFx)
{
    SET_BIT(VREFx->BUFCR, VREF_BUFCR_VREFBUFFER_OUTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VREFBUFFER_OUTEN    LL_VREF_IsEnabledVREFBufferOutPut
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsEnabledVREFBufferOutPut(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->BUFCR, VREF_BUFCR_VREFBUFFER_OUTEN_Msk) == VREF_BUFCR_VREFBUFFER_OUTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VREFBUFFER_OUTEN    LL_VREF_DisableVREFBufferOutPut
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_DisableVREFBufferOutPut(VREF_Type* VREFx)
{
    CLEAR_BIT(VREFx->BUFCR, VREF_BUFCR_VREFBUFFER_OUTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VREFBUFFER_EN    LL_VREF_EnableVREFBuffer
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_EnableVREFBuffer(VREF_Type* VREFx)
{
    SET_BIT(VREFx->BUFCR, VREF_BUFCR_VREFBUFFER_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VREFBUFFER_EN    LL_VREF_IsEnabledVREFBuffer
  * @param    VREFx VREF instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREF_IsEnabledVREFBuffer(VREF_Type* VREFx)
{
    return (uint32_t)(READ_BIT(VREFx->BUFCR, VREF_BUFCR_VREFBUFFER_EN_Msk) == VREF_BUFCR_VREFBUFFER_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   BUFCR    VREFBUFFER_EN    LL_VREF_DisableVREFBuffer
  * @param    VREFx VREF instance
  * @retval   None
  */
__STATIC_INLINE void LL_VREF_DisableVREFBuffer(VREF_Type* VREFx)
{
    CLEAR_BIT(VREFx->BUFCR, VREF_BUFCR_VREFBUFFER_EN_Msk);
}

/**
  * @}
  */

/** @defgroup VREF_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_VREF_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-09-23**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
