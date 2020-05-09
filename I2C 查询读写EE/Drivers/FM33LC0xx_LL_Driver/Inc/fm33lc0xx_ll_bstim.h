/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_bstim.h
  * @author  FMSH Application Team
  * @brief   Head file of BSTIM LL Module
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
#ifndef __FM33LC0XX_LL_BSTIM_H
#define __FM33LC0XX_LL_BSTIM_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_BSTIM
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup BSTIM_LL_ES_INIT BSTIM Exported Init structures
  * @{
  */

/**
  * @brief LL BSTIM Init Sturcture definition
  */
    
typedef struct
{
    /* 预分频系数 */ 
    uint32_t Prescaler;         
    /* 自动重装载值 */
    uint32_t Autoreload;
    /* 自动重装载值 */
    uint32_t AutoreloadState;                                  
    
    uint32_t ClockSource;

}LL_BSTIM_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup BSTIM_LL_Exported_Constants BSTIM Exported Constants
  * @{
  */
#define    LL_BSTIM_UNDATE_CNTSTATUS_RUN                          (0x0U << BSTIM_CR1_OPM_Pos)
#define    LL_BSTIM_UNDATE_CNTSTATUS_STOP                         (0x1U << BSTIM_CR1_OPM_Pos)

#define    LL_BSTIM_UNDATE_INTERUPT_OVERFLOW_UG_SLAVE             (0x0U << BSTIM_CR1_URS_Pos)
#define    LL_BSTIM_UNDATE_INTERUPT_ONLY_OVERFLOW                 (0x1U << BSTIM_CR1_URS_Pos)

#define    LL_BSTIM_MASTER_SYN_SRC_UG                             (0x0U << BSTIM_CR2_MMS_Pos)
#define    LL_BSTIM_MASTER_SYN_SRC_CNT_EN                         (0x1U << BSTIM_CR2_MMS_Pos)
#define    LL_BSTIM_MASTER_SYN_SRC_UE                             (0x2U << BSTIM_CR2_MMS_Pos)
/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup BSTIM_LL_Exported_Functions BSTIM Exported Functions
  * @{
  */

/**
  * @brief    Auto-Reload Preload Enable
  * @rmtoll   CR1    ARPE    LL_BSTIM_EnableAutoReload
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_EnableAutoReload(BSTIM_Type* BSTIMx)
{
    SET_BIT(BSTIMx->CR1, BSTIM_CR1_ARPE_Msk);
}

/**
  * @brief    Get Auto-Reload Preload Enable Status
  * @rmtoll   CR1    ARPE    LL_BSTIM_IsEnabledAutoReload
  * @param    BSTIMx BSTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BSTIM_IsEnabledAutoReload(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->CR1, BSTIM_CR1_ARPE_Msk) == BSTIM_CR1_ARPE_Msk);
}

/**
  * @brief    Auto-Reload Preload Disable
  * @rmtoll   CR1    ARPE    LL_BSTIM_DisableAutoReload
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_DisableAutoReload(BSTIM_Type* BSTIMx)
{
    CLEAR_BIT(BSTIMx->CR1, BSTIM_CR1_ARPE_Msk);
}

/**
  * @brief    Set One Pulse Mode
  * @rmtoll   CR1    OPM    LL_BSTIM_SetOnePulseMode
  * @param    BSTIMx BSTIM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_BSTIM_UNDATE_CNTSTATUS_RUN
  *           @arg @ref LL_BSTIM_UNDATE_CNTSTATUS_STOP
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_SetOnePulseMode(BSTIM_Type* BSTIMx, uint32_t mode)
{
    MODIFY_REG(BSTIMx->CR1, BSTIM_CR1_OPM_Msk, mode);
}

/**
  * @brief    Get One Pulse Mode
  * @rmtoll   CR1    OPM    LL_BSTIM_GetOnePulseMode
  * @param    BSTIMx BSTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_BSTIM_UNDATE_CNTSTATUS_RUN
  *           @arg @ref LL_BSTIM_UNDATE_CNTSTATUS_STOP
  */
__STATIC_INLINE uint32_t LL_BSTIM_GetOnePulseMode(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->CR1, BSTIM_CR1_OPM_Msk));
}

/**
  * @brief    Set Update Request Select
  * @rmtoll   CR1    URS    LL_BSTIM_SetUpdateInteruptSrc
  * @param    BSTIMx BSTIM instance
  * @param    src This parameter can be one of the following values:
  *           @arg @ref LL_BSTIM_UNDATE_INTERUPT_OVERFLOW_UG_SLAVE
  *           @arg @ref LL_BSTIM_UNDATE_INTERUPT_ONLY_OVERFLOW
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_SetUpdateInteruptSrc(BSTIM_Type* BSTIMx, uint32_t src)
{
    MODIFY_REG(BSTIMx->CR1, BSTIM_CR1_URS_Msk, src);
}

/**
  * @brief    Get Update Request Select Status
  * @rmtoll   CR1    URS    LL_BSTIM_GetUpdateInteruptSrc
  * @param    BSTIMx BSTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_BSTIM_UNDATE_INTERUPT_OVERFLOW_UG_SLAVE
  *           @arg @ref LL_BSTIM_UNDATE_INTERUPT_ONLY_OVERFLOW
  */
__STATIC_INLINE uint32_t LL_BSTIM_GetUpdateInteruptSrc(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->CR1, BSTIM_CR1_URS_Msk));
}

/**
  * @brief    Set Update Enable
  * @rmtoll   CR1    UDIS    LL_BSTIM_EnableUpdateEvent
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_EnableUpdateEvent(BSTIM_Type* BSTIMx)
{
    CLEAR_BIT(BSTIMx->CR1, BSTIM_CR1_UDIS_Msk);
}

/**
  * @brief    Get Update Enable Status
  * @rmtoll   CR1    UDIS    LL_BSTIM_IsEnabledUpdateEvent
  * @param    BSTIMx BSTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BSTIM_IsEnabledUpdateEvent(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(!(READ_BIT(BSTIMx->CR1, BSTIM_CR1_UDIS_Msk) == BSTIM_CR1_UDIS_Msk));
}

/**
  * @brief    Set Update Disable
  * @rmtoll   CR1    UDIS    LL_BSTIM_DisableUpdateEvent
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_DisableUpdateEvent(BSTIM_Type* BSTIMx)
{
    SET_BIT(BSTIMx->CR1, BSTIM_CR1_UDIS_Msk);
}

/**
  * @brief    Counter Enable
  * @rmtoll   CR1    CEN    LL_BSTIM_EnableCounter
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_EnableCounter(BSTIM_Type* BSTIMx)
{
    SET_BIT(BSTIMx->CR1, BSTIM_CR1_CEN_Msk);
}

/**
  * @brief    Get Counter Enable Status
  * @rmtoll   CR1    CEN    LL_BSTIM_IsEnabledCounter
  * @param    BSTIMx BSTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BSTIM_IsEnabledCounter(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->CR1, BSTIM_CR1_CEN_Msk) == BSTIM_CR1_CEN_Msk);
}

/**
  * @brief    Counter Disable
  * @rmtoll   CR1    CEN    LL_BSTIM_DisableCounter
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_DisableCounter(BSTIM_Type* BSTIMx)
{
    CLEAR_BIT(BSTIMx->CR1, BSTIM_CR1_CEN_Msk);
}

/**
  * @brief    Set Master Mode Select
  * @rmtoll   CR2    MMS    LL_BSTIM_SetMasterSynSrc
  * @param    BSTIMx BSTIM instance
  * @param    src This parameter can be one of the following values:
  *           @arg @ref LL_BSTIM_MASTER_SYN_SRC_UG
  *           @arg @ref LL_BSTIM_MASTER_SYN_SRC_CNT_EN
  *           @arg @ref LL_BSTIM_MASTER_SYN_SRC_UE
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_SetMasterSynSrc(BSTIM_Type* BSTIMx, uint32_t src)
{
    MODIFY_REG(BSTIMx->CR2, BSTIM_CR2_MMS_Msk, src);
}

/**
  * @brief    Get Master Mode Select Status
  * @rmtoll   CR2    MMS    LL_BSTIM_GetMasterSynSrc
  * @param    BSTIMx BSTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_BSTIM_MASTER_SYN_SRC_UG
  *           @arg @ref LL_BSTIM_MASTER_SYN_SRC_CNT_EN
  *           @arg @ref LL_BSTIM_MASTER_SYN_SRC_UE
  */
__STATIC_INLINE uint32_t LL_BSTIM_GetMasterSynSrc(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->CR2, BSTIM_CR2_MMS_Msk));
}

/**
  * @brief    Update event Interrupt Disable
  * @rmtoll   IER    UIE    LL_BSTIM_DisableIT_UpdataEvent
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_DisableIT_UpdataEvent(BSTIM_Type* BSTIMx)
{
    CLEAR_BIT(BSTIMx->IER, BSTIM_IER_UIE_Msk);
}

/**
  * @brief    Update event Interrupt Enable
  * @rmtoll   IER    UIE    LL_BSTIM_EnabledIT_UpdataEvent
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_EnabledIT_UpdataEvent(BSTIM_Type* BSTIMx)
{
    SET_BIT(BSTIMx->IER, BSTIM_IER_UIE_Msk);
}

/**
  * @brief    Get Update event Interrupt Status
  * @rmtoll   IER    UIE    LL_BSTIM_IsEnabledIT_UpdataEvent
  * @param    BSTIMx BSTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BSTIM_IsEnabledIT_UpdataEvent(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->IER, BSTIM_IER_UIE_Msk) == BSTIM_IER_UIE_Msk);
}

/**
  * @brief    Get Update event Interrupt Flag
  * @rmtoll   ISR    UIF    LL_BSTIM_IsActiveFlag_UpdataEvent
  * @param    BSTIMx BSTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_BSTIM_IsActiveFlag_UpdataEvent(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->ISR, BSTIM_ISR_UIF_Msk) == (BSTIM_ISR_UIF_Msk));
}

/**
  * @brief    Clear Update event Interrupt Flag
  * @rmtoll   ISR    UIF    LL_BSTIM_ClearFlag_UpdataEvent
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_ClearFlag_UpdataEvent(BSTIM_Type* BSTIMx)
{
    WRITE_REG(BSTIMx->ISR, BSTIM_ISR_UIF_Msk);
}

/**
  * @brief    Set User Generate Enable
  * @rmtoll   EGR    UG    LL_BSTIM_GenerateEvent_UPDATE
  * @param    BSTIMx BSTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_GenerateEvent_UPDATE(BSTIM_Type* BSTIMx)
{
    SET_BIT(BSTIMx->EGR, BSTIM_EGR_UG_Msk);
}

/**
  * @brief    Set Counter
  * @rmtoll   CNT        LL_BSTIM_SetCounterCnt
  * @param    BSTIMx BSTIM instance
  * @param    cnt 
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_SetCounterCnt(BSTIM_Type* BSTIMx, uint32_t cnt)
{
    MODIFY_REG(BSTIMx->CNT, (0xffffffffU << 0U), (cnt << 0U));
}

/**
  * @brief    Get Counter
  * @rmtoll   CNT        LL_BSTIM_GetCounterCnt
  * @param    BSTIMx BSTIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_BSTIM_GetCounterCnt(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->CNT, 0xffffffffU) >> 0U);
}

/**
  * @brief    Set Counter Clock Prescaler
  * @rmtoll   PSC        LL_BSTIM_SetCounterPsc
  * @param    BSTIMx BSTIM instance
  * @param    psc 
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_SetCounterPsc(BSTIM_Type* BSTIMx, uint32_t psc)
{
    MODIFY_REG(BSTIMx->PSC, (0xffffffffU << 0U), (psc << 0U));
}

/**
  * @brief    Get Counter Clock Prescaler
  * @rmtoll   PSC        LL_BSTIM_GetCounterPsc
  * @param    BSTIMx BSTIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_BSTIM_GetCounterPsc(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->PSC, 0xffffffffU) >> 0U);
}

/**
  * @brief    Set Auto-Reload Register
  * @rmtoll   ARR        LL_BSTIM_SetCounterAutoReloadValue
  * @param    BSTIMx BSTIM instance
  * @param    value 
  * @retval   None
  */
__STATIC_INLINE void LL_BSTIM_SetCounterAutoReloadValue(BSTIM_Type* BSTIMx, uint32_t value)
{
    MODIFY_REG(BSTIMx->ARR, (0xffffffffU << 0U), (value << 0U));
}

/**
  * @brief    Get Auto-Reload Register
  * @rmtoll   ARR        LL_BSTIM_GetCounterAutoReloadValue
  * @param    BSTIMx BSTIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_BSTIM_GetCounterAutoReloadValue(BSTIM_Type* BSTIMx)
{
    return (uint32_t)(READ_BIT(BSTIMx->ARR, 0xffffffffU) >> 0U);
}

/**
  * @}
  */

/** @defgroup BSTIM_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_BSTIM_DeInit(BSTIM_Type *BSTIMx);
ErrorStatus LL_BSTIM_Init(BSTIM_Type *BSTIMx,LL_BSTIM_InitTypeDef *BSTIM_InitStruct);
void LL_BSTIM_StructInit(LL_BSTIM_InitTypeDef *BSTIM_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_BSTIM_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-12-02**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
