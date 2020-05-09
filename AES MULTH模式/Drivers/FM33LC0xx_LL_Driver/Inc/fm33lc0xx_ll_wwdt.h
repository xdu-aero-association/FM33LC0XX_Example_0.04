/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_wwdt.h
  * @author  FMSH Application Team
  * @brief   Head file of WWDT LL Module
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
#ifndef __FM33LC0XX_LL_WWDT_H
#define __FM33LC0XX_LL_WWDT_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_WWDT
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup WWDT_LL_ES_INIT WWDT Exported Init structures
  * @{
  */

/**
  * @brief LL WWDT Init Sturcture definition
  */
typedef  struct
{
    /* 看门狗溢出周期 */
    uint32_t OverflowPeriod;
    
}LL_WWDT_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup WWDT_LL_Exported_Constants WWDT Exported Constants
  * @{
  */
#define    LL_WWDT_COUNTER_CONTRL_START                           (0x5AU << WWDT_CR_CON_Pos)

#define    LL_WWDT_COUNTER_CONTRL_RESET                           (0xACU << WWDT_CR_CON_Pos)

#define    LL_WWDT_OVERFLOW_PERIOD_X1                             (0x0U << WWDT_CFGR_CFG_Pos)
#define    LL_WWDT_OVERFLOW_PERIOD_X4                             (0x1U << WWDT_CFGR_CFG_Pos)
#define    LL_WWDT_OVERFLOW_PERIOD_X16                            (0x2U << WWDT_CFGR_CFG_Pos)
#define    LL_WWDT_OVERFLOW_PERIOD_X64                            (0x3U << WWDT_CFGR_CFG_Pos)
#define    LL_WWDT_OVERFLOW_PERIOD_X128                           (0x4U << WWDT_CFGR_CFG_Pos)
#define    LL_WWDT_OVERFLOW_PERIOD_X256                           (0x5U << WWDT_CFGR_CFG_Pos)
#define    LL_WWDT_OVERFLOW_PERIOD_X512                           (0x6U << WWDT_CFGR_CFG_Pos)
#define    LL_WWDT_OVERFLOW_PERIOD_X1024                          (0x7U << WWDT_CFGR_CFG_Pos)
/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup WWDT_LL_Exported_Functions WWDT Exported Functions
  * @{
  */

/**
  * @brief    WWDT enable counter
  * @rmtoll   CR    CON    LL_WWDT_EnableCounter
  * @param    WWDTx WWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_WWDT_EnableCounter(WWDT_Type* WWDTx)
{
    WRITE_REG(WWDTx->CR, LL_WWDT_COUNTER_CONTRL_START);
}

/**
  * @brief    WWDT reset counter
  * @rmtoll   CR    CON    LL_WWDT_ResetCounter
  * @param    WWDTx WWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_WWDT_ResetCounter(WWDT_Type* WWDTx)
{
    WRITE_REG(WWDTx->CR, LL_WWDT_COUNTER_CONTRL_RESET);
}

/**
  * @brief    Set WWDT overflow period
  * @rmtoll   CFGR    CFG    LL_WWDT_SetCounterPeriod
  * @param    WWDTx WWDT instance
  * @param    period This parameter can be one of the following values:
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X1
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X4
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X16
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X64
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X128
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X256
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X512
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X1024
  * @retval   None
  */
__STATIC_INLINE void LL_WWDT_SetCounterPeriod(WWDT_Type* WWDTx, uint32_t period)
{
    MODIFY_REG(WWDTx->CFGR, WWDT_CFGR_CFG_Msk, period);
}

/**
  * @brief    Get WWDT overflow period
  * @rmtoll   CFGR    CFG    LL_WWDT_GetCounterPeriod
  * @param    WWDTx WWDT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X1
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X4
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X16
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X64
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X128
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X256
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X512
  *           @arg @ref LL_WWDT_OVERFLOW_PERIOD_X1024
  */
__STATIC_INLINE uint32_t LL_WWDT_GetCounterPeriod(WWDT_Type* WWDTx)
{
    return (uint32_t)(READ_BIT(WWDTx->CFGR, WWDT_CFGR_CFG_Msk));
}

/**
  * @brief    Get WWDT Counter value
  * @rmtoll   CNT        LL_WWDT_GetCounter
  * @param    WWDTx WWDT instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_WWDT_GetCounter(WWDT_Type* WWDTx)
{
    return (uint32_t)(READ_BIT(WWDTx->CNT, 0x3ffU) >> 0U);
}

/**
  * @brief    WWDT interrupt enable
  * @rmtoll   IER    IE    LL_WWDT_EnableIT_WWDT_Interrupt
  * @param    WWDTx WWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_WWDT_EnableIT_WWDT_Interrupt(WWDT_Type* WWDTx)
{
    SET_BIT(WWDTx->IER, WWDT_IER_IE_Msk);
}

/**
  * @brief    WWDT interrupt enable status
  * @rmtoll   IER    IE    LL_WWDT_IsEnabledIT_WWDT_Interrupt
  * @param    WWDTx WWDT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_WWDT_IsEnabledIT_WWDT_Interrupt(WWDT_Type* WWDTx)
{
    return (uint32_t)(READ_BIT(WWDTx->IER, WWDT_IER_IE_Msk) == WWDT_IER_IE_Msk);
}

/**
  * @brief    WWDT interrupt disable
  * @rmtoll   IER    IE    LL_WWDT_DisableIT_WWDT_Interrupt
  * @param    WWDTx WWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_WWDT_DisableIT_WWDT_Interrupt(WWDT_Type* WWDTx)
{
    CLEAR_BIT(WWDTx->IER, WWDT_IER_IE_Msk);
}

/**
  * @brief    Get WWDT 75% overflow flag
  * @rmtoll   ISR    NOVF    LL_WWDT_IsActiveFlag_Interrupt
  * @param    WWDTx WWDT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_WWDT_IsActiveFlag_Interrupt(WWDT_Type* WWDTx)
{
    return (uint32_t)(READ_BIT(WWDTx->ISR, WWDT_ISR_NOVF_Msk) == (WWDT_ISR_NOVF_Msk));
}

/**
  * @brief    Clear WWDT 75% overflow flag
  * @rmtoll   ISR    NOVF    LL_WWDT_ClearFlag_Interrupt
  * @param    WWDTx WWDT instance
  * @retval   None
  */
__STATIC_INLINE void LL_WWDT_ClearFlag_Interrupt(WWDT_Type* WWDTx)
{
    WRITE_REG(WWDTx->ISR, WWDT_ISR_NOVF_Msk);
}

/**
  * @brief    Get WWDT prescaler divider counter
  * @rmtoll   PSC    DIV_CNT    LL_WWDT_GetPrescaler
  * @param    WWDTx WWDT instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_WWDT_GetPrescaler(WWDT_Type* WWDTx)
{
    return (uint32_t)(READ_BIT(WWDTx->PSC, 0xfffU) >> 0U);
}

/**
  * @}
  */

/** @defgroup WWDT_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_WWDT_DeInit(WWDT_Type* WWDTx);
void LL_WWDT_StructInit(LL_WWDT_InitTypeDef *WWDT_InitStruct);
ErrorStatus LL_WWDT_Init(WWDT_Type* WWDTx, LL_WWDT_InitTypeDef *WWDT_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_WWDT_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-12-02**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
