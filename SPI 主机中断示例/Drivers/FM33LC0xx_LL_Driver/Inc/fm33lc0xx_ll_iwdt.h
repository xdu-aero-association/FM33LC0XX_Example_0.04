/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_iwdt.h
  * @author  FMSH Application Team
  * @brief   Head file of IWDT LL Module
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
#ifndef __FM33LC0XX_LL_IWDT_H
#define __FM33LC0XX_LL_IWDT_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_IWDT
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup IWDT_LL_ES_INIT IWDT Exported Init structures
  * @{
  */

/**
  * @brief LL IWDT Init Sturcture definition
  */
typedef  struct
{
    /* 看门狗溢出时间 */
    uint32_t OverflowPeriod;
    /* 清狗窗口 */
    uint32_t IwdtWindows;

}LL_IWDT_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup IWDT_LL_Exported_Constants IWDT Exported Constants
  * @{
  */

#define    LL_IWDT_IWDT_OVERFLOW_PERIOD_125MS                     (0x0U << IWDT_CR_OVP_Pos)
#define    LL_IWDT_IWDT_OVERFLOW_PERIOD_250MS                     (0x1U << IWDT_CR_OVP_Pos)
#define    LL_IWDT_IWDT_OVERFLOW_PERIOD_500MS                     (0x2U << IWDT_CR_OVP_Pos)
#define    LL_IWDT_IWDT_OVERFLOW_PERIOD_1000MS                    (0x3U << IWDT_CR_OVP_Pos)
#define    LL_IWDT_IWDT_OVERFLOW_PERIOD_2000MS                    (0x4U << IWDT_CR_OVP_Pos)
#define    LL_IWDT_IWDT_OVERFLOW_PERIOD_4000MS                    (0x5U << IWDT_CR_OVP_Pos)
#define    LL_IWDT_IWDT_OVERFLOW_PERIOD_8000MS                    (0x6U << IWDT_CR_OVP_Pos)
#define    LL_IWDT_IWDT_OVERFLOW_PERIOD_16000MS                   (0x7U << IWDT_CR_OVP_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup IWDT_LL_Exported_Functions IWDT Exported Functions
  * @{
  */

/**
  * @brief    Set IWDT service register
  * @rmtoll   SERV        LL_IWDG_ReloadCounter
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_IWDG_ReloadCounter(IWDT_Type* IWDTx)
{
    IWDTx->SERV = IWDT_RELOAD_KEY; 
}

/**
  * @brief    Set freeze in sleep enable
  * @rmtoll   CR    FREEZE    LL_IWDG_EnableStopCounterUnderSleep
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_IWDG_EnableStopCounterUnderSleep(IWDT_Type* IWDTx)
{
    SET_BIT(IWDTx->CR, IWDT_CR_FREEZE_Msk);
}

/**
  * @brief    Set freeze in sleep disable
  * @rmtoll   CR    FREEZE    LL_IWDG_DisableStopCounterUnderSleep
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_IWDG_DisableStopCounterUnderSleep(IWDT_Type* IWDTx)
{
    CLEAR_BIT(IWDTx->CR, IWDT_CR_FREEZE_Msk);
}

/**
  * @brief    Get freeze in sleep enable status
  * @rmtoll   CR    FREEZE    LL_IWDG_IsEnabledStopCounterUnderSleep
  * @param    IWDTx IWDT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_IWDG_IsEnabledStopCounterUnderSleep(IWDT_Type* IWDTx)
{
    return (uint32_t)(READ_BIT(IWDTx->CR, IWDT_CR_FREEZE_Msk) == IWDT_CR_FREEZE_Msk);
}

/**
  * @brief    Set IWDT overflow period
  * @rmtoll   CR    OVP    LL_IWDG_SetCounterPeriod
  * @param    IWDTx IWDT instance
  * @param    period This parameter can be one of the following values:
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_125MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_250MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_500MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_1000MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_2000MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_4000MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_8000MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_16000MS
  * @retval   None
  */
__STATIC_INLINE void LL_IWDG_SetCounterPeriod(IWDT_Type* IWDTx, uint32_t period)
{
    MODIFY_REG(IWDTx->CR, IWDT_CR_OVP_Msk, period);
}

/**
  * @brief    Get IWDT overflow period
  * @rmtoll   CR    OVP    LL_IWDG_GetCounterPeriod
  * @param    IWDTx IWDT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_125MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_250MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_500MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_1000MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_2000MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_4000MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_8000MS
  *           @arg @ref LL_IWDT_IWDT_OVERFLOW_PERIOD_16000MS
  */
__STATIC_INLINE uint32_t LL_IWDG_GetCounterPeriod(IWDT_Type* IWDTx)
{
    return (uint32_t)(READ_BIT(IWDTx->CR, IWDT_CR_OVP_Msk));
}

/**
  * @brief    Get IWDT current counter value
  * @rmtoll   CNT        LL_IWDG_GetCounter
  * @param    IWDTx IWDT instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_IWDG_GetCounter(IWDT_Type* IWDTx)
{
    return (uint32_t)(READ_BIT(IWDTx->CNT, 0xfffU) >> 0U);
}

/**
  * @brief    Set IWDT window register
  * @rmtoll   WIN        LL_IWDG_SetIwdtWindows
  * @param    IWDTx IWDT instance
  * @param    Vel 
  * @retval   None
  */
__STATIC_INLINE void LL_IWDG_SetIwdtWindows(IWDT_Type* IWDTx, uint32_t Vel)
{
    MODIFY_REG(IWDTx->WIN, (0xfffU << 0U), (Vel << 0U));
}

/**
  * @brief    Get IWDT window register
  * @rmtoll   WIN        LL_IWDG_GetIwdtWindows
  * @param    IWDTx IWDT instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_IWDG_GetIwdtWindows(IWDT_Type* IWDTx)
{
    return (uint32_t)(READ_BIT(IWDTx->WIN, 0xfffU) >> 0U);
}

/**
  * @brief    IWDT interrupt enable
  * @rmtoll   IER    IE    LL_IWDG_EnableIT
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_IWDG_EnableIT(IWDT_Type* IWDTx)
{
    SET_BIT(IWDTx->IER, IWDT_IER_IE_Msk);
}

/**
  * @brief    IWDT interrupt disable
  * @rmtoll   IER    IE    LL_IWDG_DisableIT
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_IWDG_DisableIT(IWDT_Type* IWDTx)
{
    CLEAR_BIT(IWDTx->IER, IWDT_IER_IE_Msk);
}

/**
  * @brief    Get IWDT interrupt enable status
  * @rmtoll   IER    IE    LL_IWDG_IsEnabledIT
  * @param    IWDTx IWDT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_IWDG_IsEnabledIT(IWDT_Type* IWDTx)
{
    return (uint32_t)(READ_BIT(IWDTx->IER, IWDT_IER_IE_Msk) == IWDT_IER_IE_Msk);
}

/**
  * @brief    Get IWDT window interrupt flag
  * @rmtoll   ISR    WINF    LL_IWDG_IsActiveFlag_WINF
  * @param    IWDTx IWDT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_IWDG_IsActiveFlag_WINF(IWDT_Type* IWDTx)
{
    return (uint32_t)(READ_BIT(IWDTx->ISR, IWDT_ISR_WINF_Msk) == (IWDT_ISR_WINF_Msk));
}

/**
  * @brief    Clear IWDT window interrupt flag
  * @rmtoll   ISR    WINF    LL_IWDG_ClearFlag_WINF
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_IWDG_ClearFlag_WINF(IWDT_Type* IWDTx)
{
    WRITE_REG(IWDTx->ISR, IWDT_ISR_WINF_Msk);
}

/**
  * @}
  */

/** @defgroup IWDT_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_IWDT_DeInit(IWDT_Type* IWDTx);
void LL_IWDT_StructInit(LL_IWDT_InitTypeDef *IWDT_InitStruct);
ErrorStatus LL_IWDT_Init(IWDT_Type* IWDTx,LL_IWDT_InitTypeDef *IWDT_InitStruct);
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_IWDT_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-12-02**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
