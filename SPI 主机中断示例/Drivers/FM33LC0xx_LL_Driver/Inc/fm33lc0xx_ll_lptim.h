/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_lptim.h
  * @author  FMSH Application Team
  * @brief   Head file of LPTIM LL Module
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
#ifndef __FM33LC0XX_LL_LPTIM_H
#define __FM33LC0XX_LL_LPTIM_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_LPTIM
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup LPTIM_LL_ES_INIT LPTIM Exported Init structures
  * @{
  */

/**
  * @brief LL LPTIM Init Sturcture definition
  */
/* 时基配置 */
typedef struct
{
    /* 内部时钟源*/
	uint32_t ClockSource;
    /* 预分器的时钟源 可选择内部时钟 也可选择外部时钟*/
	uint32_t PrescalerClockSource;   
    /* 分频系数*/
	uint32_t Prescaler;      
    /* 定时器工作模式选择 */
	uint32_t Mode;
    /* 单次计数使能 */   
    uint32_t OneState;
    /* ETR 外部触发计数边沿 */
	uint32_t CountPolarity; 
    /* 外部 触发的时钟极性 */
    uint32_t TriggerPolarity;
    
}LL_LPTIM_TimeInitTypeDef;

/* 输入输出比较配置 */ 
typedef struct
{     
    /* 输入捕获通道 */
	uint32_t ICSource;  
    /* 输入捕获极性 */
	uint32_t ICPolarity;          
	
}LL_TIM_IC_InitTypeDef;

/* 输入输出比较配置 */ 
typedef struct
{           
    /* 自动重装载值 */
    uint32_t OC_Arr;
    /* 比较载值 */
    uint32_t OC_Ccr;    
    /* 比较输出极性*/
	uint32_t OCPolarity;    
	
}LL_TIM_OC_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup LPTIM_LL_Exported_Constants LPTIM Exported Constants
  * @{
  */

#define    LL_LPTIM_PRESCALER_INPUT_LPTIM_CLK                     (0x0U << LPTIM_CFGR_PSCSEL_Pos)
#define    LL_LPTIM_PRESCALER_INPUT_LPTIM_INPUT                   (0x1U << LPTIM_CFGR_PSCSEL_Pos)

#define    LL_LPTIM_INPUT_EXTERNAL_INPUT                          (0x0U << LPTIM_CFGR_INSEL_Pos)
#define    LL_LPTIM_INPUT_ADC_EOC                                 (0x1U << LPTIM_CFGR_INSEL_Pos)

#define    LL_LPTIM_CLOCKDIVISION_DIV1                            (0x0U << LPTIM_CFGR_DIVSEL_Pos)
#define    LL_LPTIM_CLOCKDIVISION_DIV2                            (0x1U << LPTIM_CFGR_DIVSEL_Pos)
#define    LL_LPTIM_CLOCKDIVISION_DIV4                            (0x2U << LPTIM_CFGR_DIVSEL_Pos)
#define    LL_LPTIM_CLOCKDIVISION_DIV8                            (0x3U << LPTIM_CFGR_DIVSEL_Pos)
#define    LL_LPTIM_CLOCKDIVISION_DIV16                           (0x4U << LPTIM_CFGR_DIVSEL_Pos)
#define    LL_LPTIM_CLOCKDIVISION_DIV32                           (0x5U << LPTIM_CFGR_DIVSEL_Pos)
#define    LL_LPTIM_CLOCKDIVISION_DIV64                           (0x6U << LPTIM_CFGR_DIVSEL_Pos)
#define    LL_LPTIM_CLOCKDIVISION_DIV128                          (0x7U << LPTIM_CFGR_DIVSEL_Pos)

#define    LL_LPTIM_EXTERNAL_INPUT_COUNT_POLARITY_RISING          (0x0U << LPTIM_CFGR_EDGESEL_Pos)
#define    LL_LPTIM_EXTERNAL_INPUT_COUNT_POLARITY_FALLING         (0x1U << LPTIM_CFGR_EDGESEL_Pos)

#define    LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_RINSING       (0x0U << LPTIM_CFGR_TRIGCFG_Pos)
#define    LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_FALLING       (0x1U << LPTIM_CFGR_TRIGCFG_Pos)
#define    LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_BOTHEDGE      (0x2U << LPTIM_CFGR_TRIGCFG_Pos)

#define    LL_LPTIM_ONE_STATE_TIMER_CONTINUE                      (0x0U << LPTIM_CFGR_ONST_Pos)
#define    LL_LPTIM_ONE_STATE_TIMER_SINGLE                        (0x1U << LPTIM_CFGR_ONST_Pos)

#define    LL_LPTIM_OPERATION_MODE_NORMAL                         (0x0U << LPTIM_CFGR_TMOD_Pos)
#define    LL_LPTIM_OPERATION_MODE_TRIGGER_CNT                    (0x1U << LPTIM_CFGR_TMOD_Pos)
#define    LL_LPTIM_OPERATION_MODE_EXTERNAL_ASYN_PULSE_CNT        (0x2U << LPTIM_CFGR_TMOD_Pos)
#define    LL_LPTIM_OPERATION_MODE_TIMEOUT                        (0x3U << LPTIM_CFGR_TMOD_Pos)

#define    LL_LPTIM_IC1_CAPCTURE_SOURCE_CHANNEL1                  (0x0U << LPTIM_CCSR_CAP1SSEL_Pos)
#define    LL_LPTIM_IC1_CAPCTURE_SOURCE_XTLF                      (0x1U << LPTIM_CCSR_CAP1SSEL_Pos)
#define    LL_LPTIM_IC1_CAPCTURE_SOURCE_RCLP                      (0x2U << LPTIM_CCSR_CAP1SSEL_Pos)
#define    LL_LPTIM_IC1_CAPCTURE_SOURCE_RC4M_PSC                  (0x3U << LPTIM_CCSR_CAP1SSEL_Pos)

#define    LL_LPTIM_IC2_CAPCTURE_SOURCE_GPTIM1_TRGO               (0x0U << LPTIM_CCSR_CAP2SSEL_Pos)
#define    LL_LPTIM_IC2_CAPCTURE_SOURCE_GPTIM2_TRGO               (0x1U << LPTIM_CCSR_CAP2SSEL_Pos)
#define    LL_LPTIM_IC2_CAPCTURE_SOURCE_ATIM_TRGO                 (0x2U << LPTIM_CCSR_CAP2SSEL_Pos)
#define    LL_LPTIM_IC2_CAPCTURE_SOURCE_CHANNEL2                  (0x3U << LPTIM_CCSR_CAP2SSEL_Pos)
/*Functional abstraction*/
#define    LL_LPTIM_CC_MODE_NONE                                 (0x0U)
#define    LL_LPTIM_CC_MODE_CAPTURE                              (0x1U)
#define    LL_LPTIM_CC_MODE_COMPARE                              (0x2U)
#define    LL_LPTIM_IC_POLARITY_EDGE_RISING                      (0x0U)
#define    LL_LPTIM_IC_POLARITY_EDGE_FALLING                     (0x1U)
#define    LL_LPTIM_IC_POLARITY_EDGE_BOTHEDGE                    (0x2U)
#define    LL_LPTIM_OC_POLARITY_LOW_TO_HIGH                      (0x0U)
#define    LL_LPTIM_OC_POLARITY_HIGH_TO_LOW                      (0x1U)
#define    LL_LPTIM_IC_CAPCTURED_EDGE_FALLING                    (0x0U)
#define    LL_LPTIM_IC_CAPCTURED_EDGE_RISING                     (0x1U)

#define    LL_LPTIM_CHANNEL_1                                    (0x0U << 0U)
#define    LL_LPTIM_CHANNEL_2                                    (0x1U << 0U)
/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup LPTIM_LL_Exported_Functions LPTIM Exported Functions
  * @{
  */

/**
  * @brief    LPTIM Enable
  * @rmtoll   CR    EN    LL_LPTIM_Enable
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_Enable(LPTIM_Type *LPTIMx)
{
    SET_BIT(LPTIMx->CR, LPTIM_CR_EN_Msk);
}

/**
  * @brief    LPTIM Disable
  * @rmtoll   CR    EN    LL_LPTIM_Disable
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_Disable(LPTIM_Type *LPTIMx)
{
    CLEAR_BIT(LPTIMx->CR, LPTIM_CR_EN_Msk);
}

/**
  * @brief    Get LPTIM Enable Status
  * @rmtoll   CR    EN    LL_LPTIM_IsEnabled
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabled(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CR, LPTIM_CR_EN_Msk) == LPTIM_CR_EN_Msk);
}

/**
  * @brief    External Trigger input Analog Filter Enable
  * @rmtoll   CFGR    ETR_AFEN    LL_LPTIM_EnableExternalTriggerAnalogFilter
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_EnableExternalTriggerAnalogFilter(LPTIM_Type *LPTIMx)
{
    SET_BIT(LPTIMx->CFGR, LPTIM_CFGR_ETR_AFEN_Msk);
}

/**
  * @brief    External Trigger input Analog Filter Disable
  * @rmtoll   CFGR    ETR_AFEN    LL_LPTIM_DisableExternalTriggerAnalogFilter
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_DisableExternalTriggerAnalogFilter(LPTIM_Type *LPTIMx)
{
    CLEAR_BIT(LPTIMx->CFGR, LPTIM_CFGR_ETR_AFEN_Msk);
}

/**
  * @brief    Get External Trigger input Analog Filter Enable Status
  * @rmtoll   CFGR    ETR_AFEN    LL_LPTIM_IsEnabledExternalTriggerAnalogFilter
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledExternalTriggerAnalogFilter(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_ETR_AFEN_Msk) == LPTIM_CFGR_ETR_AFEN_Msk);
}

/**
  * @brief    Set Prescaler input Select
  * @rmtoll   CFGR    PSCSEL    LL_LPTIM_SetPrescalerInput
  * @param    LPTIMx LPTIM instance
  * @param    PrescalerInput This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_PRESCALER_INPUT_LPTIM_CLK
  *           @arg @ref LL_LPTIM_PRESCALER_INPUT_LPTIM_INPUT
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_SetPrescalerInput(LPTIM_Type *LPTIMx, uint32_t PrescalerInput)
{
    MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_PSCSEL_Msk, PrescalerInput);
}

/**
  * @brief    Get Prescaler input Select
  * @rmtoll   CFGR    PSCSEL    LL_LPTIM_GetPrescalerInput
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_PRESCALER_INPUT_LPTIM_CLK
  *           @arg @ref LL_LPTIM_PRESCALER_INPUT_LPTIM_INPUT
  */
__STATIC_INLINE uint32_t LL_LPTIM_GetPrescalerInput(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_PSCSEL_Msk));
}

/**
  * @brief    Set External Trigger input source Select
  * @rmtoll   CFGR    INSEL    LL_LPTIM_SetInput
  * @param    LPTIMx LPTIM instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_INPUT_EXTERNAL_INPUT
  *           @arg @ref LL_LPTIM_INPUT_ADC_EOC
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_SetInput(LPTIM_Type *LPTIMx, uint32_t Input)
{
    MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_INSEL_Msk, Input);
}

/**
  * @brief    Get External Trigger input source Select
  * @rmtoll   CFGR    INSEL    LL_LPTIM_GetInput
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_INPUT_EXTERNAL_INPUT
  *           @arg @ref LL_LPTIM_INPUT_ADC_EOC
  */
__STATIC_INLINE uint32_t LL_LPTIM_GetInput(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_INSEL_Msk));
}

/**
  * @brief    Set Counter Clock Divider Select
  * @rmtoll   CFGR    DIVSEL    LL_LPTIM_SetColckDivision
  * @param    LPTIMx LPTIM instance
  * @param    ClockDivision This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV1
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV2
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV4
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV8
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV16
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV32
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV64
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV128
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_SetColckDivision(LPTIM_Type *LPTIMx, uint32_t ClockDivision)
{
    MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_DIVSEL_Msk, ClockDivision);
}

/**
  * @brief    Get Counter Clock Divider Select
  * @rmtoll   CFGR    DIVSEL    LL_LPTIM_GetColckDivision
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV1
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV2
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV4
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV8
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV16
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV32
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV64
  *           @arg @ref LL_LPTIM_CLOCKDIVISION_DIV128
  */
__STATIC_INLINE uint32_t LL_LPTIM_GetColckDivision(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_DIVSEL_Msk));
}

/**
  * @brief    Set ETR Clock Edge Select
  * @rmtoll   CFGR    EDGESEL    LL_LPTIM_SetPolarityExternalInput
  * @param    LPTIMx LPTIM instance
  * @param    Polarity This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_COUNT_POLARITY_RISING
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_COUNT_POLARITY_FALLING
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_SetPolarityExternalInput(LPTIM_Type *LPTIMx, uint32_t Polarity)
{
    MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_EDGESEL_Msk, Polarity);
}

/**
  * @brief    Get ETR Clock Edge Select
  * @rmtoll   CFGR    EDGESEL    LL_LPTIM_GetPolarityExternalInput
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_COUNT_POLARITY_RISING
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_COUNT_POLARITY_FALLING
  */
__STATIC_INLINE uint32_t LL_LPTIM_GetPolarityExternalInput(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_EDGESEL_Msk));
}

/**
  * @brief    Set ETR trigger Configuration
  * @rmtoll   CFGR    TRIGCFG    LL_LPTIM_SetTriggerExternalInput
  * @param    LPTIMx LPTIM instance
  * @param    Trigger This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_RINSING
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_FALLING
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_BOTHEDGE
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_SetTriggerExternalInput(LPTIM_Type *LPTIMx, uint32_t Trigger)
{
    MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_TRIGCFG_Msk, Trigger);
}

/**
  * @brief    Get ETR trigger Configuration
  * @rmtoll   CFGR    TRIGCFG    LL_LPTIM_GetTriggerExternalInput
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_RINSING
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_FALLING
  *           @arg @ref LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_BOTHEDGE
  */
__STATIC_INLINE uint32_t LL_LPTIM_GetTriggerExternalInput(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_TRIGCFG_Msk));
}

/**
  * @brief    Set One State Timer Mode
  * @rmtoll   CFGR    ONST    LL_LPTIM_Set_OneStateTimer
  * @param    LPTIMx LPTIM instance
  * @param    OneStateTimer This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_ONE_STATE_TIMER_CONTINUE
  *           @arg @ref LL_LPTIM_ONE_STATE_TIMER_SINGLE
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_Set_OneStateTimer(LPTIM_Type *LPTIMx, uint32_t OneStateTimer)
{
    MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_ONST_Msk, OneStateTimer);
}

/**
  * @brief    Get One State Timer Mode
  * @rmtoll   CFGR    ONST    LL_LPTIM_Get_OneStateTimer
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_ONE_STATE_TIMER_CONTINUE
  *           @arg @ref LL_LPTIM_ONE_STATE_TIMER_SINGLE
  */
__STATIC_INLINE uint32_t LL_LPTIM_Get_OneStateTimer(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_ONST_Msk));
}

/**
  * @brief    Set Timer operation Mode
  * @rmtoll   CFGR    TMOD    LL_LPTIM_SetOperationMode
  * @param    LPTIMx LPTIM instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_OPERATION_MODE_NORMAL
  *           @arg @ref LL_LPTIM_OPERATION_MODE_TRIGGER_CNT
  *           @arg @ref LL_LPTIM_OPERATION_MODE_EXTERNAL_ASYN_PULSE_CNT
  *           @arg @ref LL_LPTIM_OPERATION_MODE_TIMEOUT
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_SetOperationMode(LPTIM_Type *LPTIMx, uint32_t Mode)
{
    MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_TMOD_Msk, Mode);
}

/**
  * @brief    Get Timer operation Mode
  * @rmtoll   CFGR    TMOD    LL_LPTIM_GetOperationMode
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_OPERATION_MODE_NORMAL
  *           @arg @ref LL_LPTIM_OPERATION_MODE_TRIGGER_CNT
  *           @arg @ref LL_LPTIM_OPERATION_MODE_EXTERNAL_ASYN_PULSE_CNT
  *           @arg @ref LL_LPTIM_OPERATION_MODE_TIMEOUT
  */
__STATIC_INLINE uint32_t LL_LPTIM_GetOperationMode(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_TMOD_Msk));
}

/**
  * @brief    Set Channel1 Compare Register
  * @rmtoll   CCR1        LL_LPTIM_OC_SetCompareCH1
  * @param    LPTIMx LPTIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_OC_SetCompareCH1(LPTIM_Type *LPTIMx, uint32_t CompareValue)
{
    MODIFY_REG(LPTIMx->CCR1, (0xffffffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    Get Channel1 Compare Register
  * @rmtoll   CCR1        LL_LPTIM_OC_GetCompareCH1
  * @param    LPTIMx LPTIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_LPTIM_OC_GetCompareCH1(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCR1, 0xffffffffU) >> 0U);
}

/**
  * @brief    Set Channel2 Compare Register
  * @rmtoll   CCR2        LL_LPTIM_OC_SetCompareCH2
  * @param    LPTIMx LPTIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_OC_SetCompareCH2(LPTIM_Type *LPTIMx, uint32_t CompareValue)
{
    MODIFY_REG(LPTIMx->CCR2, (0xffffffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    Get Channel2 Compare Register
  * @rmtoll   CCR2        LL_LPTIM_OC_GetCompareCH2
  * @param    LPTIMx LPTIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_LPTIM_OC_GetCompareCH2(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCR2, 0xffffffffU) >> 0U);
}

/**
  * @brief    Get Channel1 Capture Register
  * @rmtoll   CCR1        LL_LPTIM_IC_GetCaptureCH1
  * @param    LPTIMx LPTIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_LPTIM_IC_GetCaptureCH1(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCR1, 0xffffffffU) >> 0U);
}

/**
  * @brief    Get Channel2 Capture Register
  * @rmtoll   CCR2        LL_LPTIM_IC_GetCaptureCH2
  * @param    LPTIMx LPTIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_LPTIM_IC_GetCaptureCH2(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCR2, 0xffffffffU) >> 0U);
}

/**
  * @brief    Capture/Compare channel 1 Interrupt Enable
  * @rmtoll   IER    CC1IE    LL_LPTIM_EnableIT_Channel1
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_EnableIT_Channel1(LPTIM_Type *LPTIMx)
{
    SET_BIT(LPTIMx->IER, LPTIM_IER_CC1IE_Msk);
}

/**
  * @brief    Capture/Compare channel 2 Interrupt Enable
  * @rmtoll   IER    CC2IE    LL_LPTIM_EnableIT_Channel2
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_EnableIT_Channel2(LPTIM_Type *LPTIMx)
{
    SET_BIT(LPTIMx->IER, LPTIM_IER_CC2IE_Msk);
}

/**
  * @brief    Counter Over-Flow Interrupt Enable
  * @rmtoll   IER    OVIE    LL_LPTIM_EnableIT_CounterOver
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_EnableIT_CounterOver(LPTIM_Type *LPTIMx)
{
    SET_BIT(LPTIMx->IER, LPTIM_IER_OVIE_Msk);
}

/**
  * @brief    External Trigger Interrupt Enable
  * @rmtoll   IER    TRIGIE    LL_LPTIM_EnableIT_ExternalTrigger
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_EnableIT_ExternalTrigger(LPTIM_Type *LPTIMx)
{
    SET_BIT(LPTIMx->IER, LPTIM_IER_TRIGIE_Msk);
}

/**
  * @brief    Channel 1 Over-Capture Interrupt Enable
  * @rmtoll   IER    OVR1IE    LL_LPTIM_EnableIT_CAP1OVR
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_EnableIT_CAP1OVR(LPTIM_Type *LPTIMx)
{
    SET_BIT(LPTIMx->IER, LPTIM_IER_OVR1IE_Msk);
}

/**
  * @brief    Channel 2 Over-Capture Interrupt Enable
  * @rmtoll   IER    OVR2IE    LL_LPTIM_EnableIT_CAP2OVR
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_EnableIT_CAP2OVR(LPTIM_Type *LPTIMx)
{
    SET_BIT(LPTIMx->IER, LPTIM_IER_OVR2IE_Msk);
}

/**
  * @brief    Capture/Compare channel 1 Interrupt Disable
  * @rmtoll   IER    CC1IE    LL_LPTIM_DisableIT_Channel1
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_DisableIT_Channel1(LPTIM_Type *LPTIMx)
{
    CLEAR_BIT(LPTIMx->IER, LPTIM_IER_CC1IE_Msk);
}

/**
  * @brief    Capture/Compare channel 2 Interrupt Disable
  * @rmtoll   IER    CC2IE    LL_LPTIM_DisableIT_Channel2
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_DisableIT_Channel2(LPTIM_Type *LPTIMx)
{
    CLEAR_BIT(LPTIMx->IER, LPTIM_IER_CC2IE_Msk);
}

/**
  * @brief    Counter Over-Flow Interrupt Disable
  * @rmtoll   IER    OVIE    LL_LPTIM_DisableIT_CounterOver
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_DisableIT_CounterOver(LPTIM_Type *LPTIMx)
{
    CLEAR_BIT(LPTIMx->IER, LPTIM_IER_OVIE_Msk);
}

/**
  * @brief    External Trigger Interrupt Disable
  * @rmtoll   IER    TRIGIE    LL_LPTIM_DisableIT_ExternalTrigger
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_DisableIT_ExternalTrigger(LPTIM_Type *LPTIMx)
{
    CLEAR_BIT(LPTIMx->IER, LPTIM_IER_TRIGIE_Msk);
}

/**
  * @brief    Channel 1 Over-Capture Interrupt Disable
  * @rmtoll   IER    OVR1IE    LL_LPTIM_DisableIT_CAP1OVR
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_DisableIT_CAP1OVR(LPTIM_Type *LPTIMx)
{
    CLEAR_BIT(LPTIMx->IER, LPTIM_IER_OVR1IE_Msk);
}

/**
  * @brief    Channel 2 Over-Capture Interrupt Disable
  * @rmtoll   IER    OVR2IE    LL_LPTIM_DisableIT_CAP2OVR
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_DisableIT_CAP2OVR(LPTIM_Type *LPTIMx)
{
    CLEAR_BIT(LPTIMx->IER, LPTIM_IER_OVR2IE_Msk);
}

/**
  * @brief    Get Capture/Compare channel 1 Interrupt Enable Status
  * @rmtoll   IER    CC1IE    LL_LPTIM_IsEnabled_Channel1
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabled_Channel1(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->IER, LPTIM_IER_CC1IE_Msk) == LPTIM_IER_CC1IE_Msk);
}

/**
  * @brief    Get Capture/Compare channel 2 Interrupt Enable Status
  * @rmtoll   IER    CC2IE    LL_LPTIM_IsEnabled_Channel2
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabled_Channel2(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->IER, LPTIM_IER_CC2IE_Msk) == LPTIM_IER_CC2IE_Msk);
}

/**
  * @brief    Get Counter Over-Flow Interrupt Enable Status
  * @rmtoll   IER    OVIE    LL_LPTIM_IsEnabled_CounterOver
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabled_CounterOver(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->IER, LPTIM_IER_OVIE_Msk) == LPTIM_IER_OVIE_Msk);
}

/**
  * @brief    Get External Trigger Interrupt Enable Status
  * @rmtoll   IER    TRIGIE    LL_LPTIM_IsEnabled_ExternalTrigger
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabled_ExternalTrigger(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->IER, LPTIM_IER_TRIGIE_Msk) == LPTIM_IER_TRIGIE_Msk);
}

/**
  * @brief    Get Channel 1 Over-Capture Interrupt Enable Status
  * @rmtoll   IER    OVR1IE    LL_LPTIM_IsEnabled_CAP1OVR
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabled_CAP1OVR(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->IER, LPTIM_IER_OVR1IE_Msk) == LPTIM_IER_OVR1IE_Msk);
}

/**
  * @brief    Get Channel 2 Over-Capture Interrupt Enable Status
  * @rmtoll   IER    OVR2IE    LL_LPTIM_IsEnabled_CAP2OVR
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabled_CAP2OVR(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->IER, LPTIM_IER_OVR2IE_Msk) == LPTIM_IER_OVR2IE_Msk);
}

/**
  * @brief    Get Capture/Compare channel 1 Interrupt Flag
  * @rmtoll   ISR    CC1IF    LL_LPTIM_IsActiveFlag_Channel1
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_Channel1(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->ISR, LPTIM_ISR_CC1IF_Msk) == (LPTIM_ISR_CC1IF_Msk));
}

/**
  * @brief    Get Capture/Compare channel 2 Interrupt Flag
  * @rmtoll   ISR    CC2IF    LL_LPTIM_IsActiveFlag_Channel2
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_Channel2(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->ISR, LPTIM_ISR_CC2IF_Msk) == (LPTIM_ISR_CC2IF_Msk));
}

/**
  * @brief    Get Counter Over-Flow Interrupt Flag
  * @rmtoll   ISR    OVIF    LL_LPTIM_IsActiveFlag_CounterOver
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_CounterOver(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->ISR, LPTIM_ISR_OVIF_Msk) == (LPTIM_ISR_OVIF_Msk));
}

/**
  * @brief    Get External Trigger Interrupt Flag
  * @rmtoll   ISR    TRIGIF    LL_LPTIM_IsActiveFlag_ExternalTrigger
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_ExternalTrigger(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->ISR, LPTIM_ISR_TRIGIF_Msk) == (LPTIM_ISR_TRIGIF_Msk));
}

/**
  * @brief    Get Channel 1 Over-Capture Interrupt Flag
  * @rmtoll   ISR    CAP1OVR    LL_LPTIM_IsActiveFlag_CAP1OVR
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_CAP1OVR(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->ISR, LPTIM_ISR_CAP1OVR_Msk) == (LPTIM_ISR_CAP1OVR_Msk));
}

/**
  * @brief    Get Channel 2 Over-Capture Interrupt Flag
  * @rmtoll   ISR    CAP2OVR    LL_LPTIM_IsActiveFlag_CAP2OVR
  * @param    LPTIMx LPTIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_CAP2OVR(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->ISR, LPTIM_ISR_CAP2OVR_Msk) == (LPTIM_ISR_CAP2OVR_Msk));
}

/**
  * @brief    Clear Capture/Compare channel 1 Interrupt Flag
  * @rmtoll   ISR    CC1IF    LL_LPTIM_ClearFlag_Channel1
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_ClearFlag_Channel1(LPTIM_Type *LPTIMx)
{
    WRITE_REG(LPTIMx->ISR, LPTIM_ISR_CC1IF_Msk);
}

/**
  * @brief    Clear Capture/Compare channel 2 Interrupt Flag
  * @rmtoll   ISR    CC2IF    LL_LPTIM_ClearFlag_Channel2
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_ClearFlag_Channel2(LPTIM_Type *LPTIMx)
{
    WRITE_REG(LPTIMx->ISR, LPTIM_ISR_CC2IF_Msk);
}

/**
  * @brief    Clear Counter Over-Flow Interrupt Flag
  * @rmtoll   ISR    OVIF    LL_LPTIM_ClearFlag_CounterOver
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_ClearFlag_CounterOver(LPTIM_Type *LPTIMx)
{
    WRITE_REG(LPTIMx->ISR, LPTIM_ISR_OVIF_Msk);
}

/**
  * @brief    Clear External Trigger Interrupt Flag
  * @rmtoll   ISR    TRIGIF    LL_LPTIM_ClearFlag_ExternalTrigger
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_ClearFlag_ExternalTrigger(LPTIM_Type *LPTIMx)
{
    WRITE_REG(LPTIMx->ISR, LPTIM_ISR_TRIGIF_Msk);
}

/**
  * @brief    Clear Channel 1 Over-Capture Interrupt Flag
  * @rmtoll   ISR    CAP1OVR    LL_LPTIM_ClearFlag_CAP1OVR
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_ClearFlag_CAP1OVR(LPTIM_Type *LPTIMx)
{
    WRITE_REG(LPTIMx->ISR, LPTIM_ISR_CAP1OVR_Msk);
}

/**
  * @brief    Clear Channel 2 Over-Capture Interrupt Flag
  * @rmtoll   ISR    CAP2OVR    LL_LPTIM_ClearFlag_CAP2OVR
  * @param    LPTIMx LPTIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_ClearFlag_CAP2OVR(LPTIM_Type *LPTIMx)
{
    WRITE_REG(LPTIMx->ISR, LPTIM_ISR_CAP2OVR_Msk);
}

/**
  * @brief    Set Auto-Reload Register
  * @rmtoll   ARR        LL_LPTIM_SetAutoReload
  * @param    LPTIMx LPTIM instance
  * @param    AutoReload 
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_SetAutoReload(LPTIM_Type *LPTIMx, uint32_t AutoReload)
{
    MODIFY_REG(LPTIMx->ARR, (0xffffffffU << 0U), (AutoReload << 0U));
}

/**
  * @brief    Get Auto-Reload Register
  * @rmtoll   ARR        LL_LPTIM_GetAutoReload
  * @param    LPTIMx LPTIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_LPTIM_GetAutoReload(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->ARR, 0xffffffffU) >> 0U);
}

/**
  * @brief    Set Channel 1 Capture edge Config
  * @rmtoll   CCSR    CAPCFG1    LL_LPTIM_IC_SetPolarityChannel1
  * @param    LPTIMx LPTIM instance
  * @param    Polarity This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_RISING
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_FALLING
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_BOTHEDGE
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_IC_SetPolarityChannel1(LPTIM_Type *LPTIMx, uint32_t Polarity)
{
    MODIFY_REG(LPTIMx->CCSR, LPTIM_CCSR_CAPCFG1_Msk, Polarity << LPTIM_CCSR_CAPCFG1_Pos);
}

/**
  * @brief    Get Channel 1 Capture edge Config
  * @rmtoll   CCSR    CAPCFG1    LL_LPTIM_IC_GetPolarityChannel1
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_RISING
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_FALLING
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_BOTHEDGE
  */
__STATIC_INLINE uint32_t LL_LPTIM_IC_GetPolarityChannel1(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_CAPCFG1_Msk) >> LPTIM_CCSR_CAPCFG1_Pos);
}

/**
  * @brief    Set Channel 2 Capture edge Config
  * @rmtoll   CCSR    CAPCFG2    LL_LPTIM_IC_SetPolarityChannel2
  * @param    LPTIMx LPTIM instance
  * @param    Polarity This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_RISING
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_FALLING
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_BOTHEDGE
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_IC_SetPolarityChannel2(LPTIM_Type *LPTIMx, uint32_t Polarity)
{
    MODIFY_REG(LPTIMx->CCSR, LPTIM_CCSR_CAPCFG2_Msk, Polarity<<LPTIM_CCSR_CAPCFG2_Pos);
}

/**
  * @brief    Get Channel 2 Capture edge Config
  * @rmtoll   CCSR    CAPCFG2    LL_LPTIM_IC_GetPolarityChannel2
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_RISING
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_FALLING
  *           @arg @ref LL_LPTIM_IC_POLARITY_EDGE_BOTHEDGE
  */
__STATIC_INLINE uint32_t LL_LPTIM_IC_GetPolarityChannel2(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_CAPCFG2_Msk)>>LPTIM_CCSR_CAPCFG2_Pos);
}

/**
  * @brief    Set Channel 1 compare output Polarity
  * @rmtoll   CCSR    POLAR1    LL_LPTIM_OC_SetPolarityChannel1
  * @param    LPTIMx LPTIM instance
  * @param    Polarity This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_OC_POLARITY_LOW_TO_HIGH
  *           @arg @ref LL_LPTIM_OC_POLARITY_HIGH_TO_LOW
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_OC_SetPolarityChannel1(LPTIM_Type *LPTIMx, uint32_t Polarity)
{
    MODIFY_REG(LPTIMx->CCSR, LPTIM_CCSR_POLAR1_Msk, Polarity << LPTIM_CCSR_POLAR1_Pos);
}

/**
  * @brief    Get Channel 1 compare output Polarity
  * @rmtoll   CCSR    POLAR1    LL_LPTIM_OC_GetPolarityChannel1
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_OC_POLARITY_LOW_TO_HIGH
  *           @arg @ref LL_LPTIM_OC_POLARITY_HIGH_TO_LOW
  */
__STATIC_INLINE uint32_t LL_LPTIM_OC_GetPolarityChannel1(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_POLAR1_Msk) >>LPTIM_CCSR_POLAR1_Pos );
}

/**
  * @brief    Set Channel 2 compare output Polarity
  * @rmtoll   CCSR    POLAR2    LL_LPTIM_OC_SetPolarityChannel2
  * @param    LPTIMx LPTIM instance
  * @param    Polarity This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_OC_POLARITY_LOW_TO_HIGH
  *           @arg @ref LL_LPTIM_OC_POLARITY_HIGH_TO_LOW
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_OC_SetPolarityChannel2(LPTIM_Type *LPTIMx, uint32_t Polarity)
{
    MODIFY_REG(LPTIMx->CCSR, LPTIM_CCSR_POLAR2_Msk, Polarity << LPTIM_CCSR_POLAR2_Pos);
}

/**
  * @brief    Get Channel 2 compare output Polarity
  * @rmtoll   CCSR    POLAR2    LL_LPTIM_OC_GetPolarityChannel2
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_OC_POLARITY_LOW_TO_HIGH
  *           @arg @ref LL_LPTIM_OC_POLARITY_HIGH_TO_LOW
  */
__STATIC_INLINE uint32_t LL_LPTIM_OC_GetPolarityChannel2(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_POLAR2_Msk) >> LPTIM_CCSR_POLAR2_Pos);
}

/**
  * @brief    Set Channel 2 Capture/Compare Select
  * @rmtoll   CCSR    CC2S    LL_LPTIM_CC_Set_ModeChannel2
  * @param    LPTIMx LPTIM instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_CC_MODE_NONE
  *           @arg @ref LL_LPTIM_CC_MODE_CAPTURE
  *           @arg @ref LL_LPTIM_CC_MODE_COMPARE
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_CC_Set_ModeChannel2(LPTIM_Type *LPTIMx, uint32_t Mode)
{
    MODIFY_REG(LPTIMx->CCSR, LPTIM_CCSR_CC2S_Msk, Mode << LPTIM_CCSR_CC2S_Pos);
}

/**
  * @brief    Get Channel 2 Capture/Compare Select
  * @rmtoll   CCSR    CC2S    LL_LPTIM_CC_Get_ModeChannel2
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_CC_MODE_NONE
  *           @arg @ref LL_LPTIM_CC_MODE_CAPTURE
  *           @arg @ref LL_LPTIM_CC_MODE_COMPARE
  */
__STATIC_INLINE uint32_t LL_LPTIM_CC_Get_ModeChannel2(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_CC2S_Msk) >> LPTIM_CCSR_CC2S_Pos);
}

/**
  * @brief    Set Channel 1 Capture/Compare Select 
  * @rmtoll   CCSR    CC1S    LL_LPTIM_CC_Set_ModeChannel1
  * @param    LPTIMx LPTIM instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_CC_MODE_NONE
  *           @arg @ref LL_LPTIM_CC_MODE_CAPTURE
  *           @arg @ref LL_LPTIM_CC_MODE_COMPARE
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_CC_Set_ModeChannel1(LPTIM_Type *LPTIMx, uint32_t Mode)
{
    MODIFY_REG(LPTIMx->CCSR, LPTIM_CCSR_CC1S_Msk, Mode << LPTIM_CCSR_CC1S_Pos );
}

/**
  * @brief    Get Channel 1 Capture/Compare Select 
  * @rmtoll   CCSR    CC1S    LL_LPTIM_CC_Get_ModeChannel1
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_CC_MODE_NONE
  *           @arg @ref LL_LPTIM_CC_MODE_CAPTURE
  *           @arg @ref LL_LPTIM_CC_MODE_COMPARE
  */
__STATIC_INLINE uint32_t LL_LPTIM_CC_Get_ModeChannel1(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_CC1S_Msk)>>LPTIM_CCSR_CC1S_Pos);
}

/**
  * @brief    Get Channel 1 Captured Edge
  * @rmtoll   CCSR    CAP1EDGE    LL_LPTIM_IC_GetCapcturedEdgeChannel1
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_IC_CAPCTURED_EDGE_FALLING
  *           @arg @ref LL_LPTIM_IC_CAPCTURED_EDGE_RISING
  */
__STATIC_INLINE uint32_t LL_LPTIM_IC_GetCapcturedEdgeChannel1(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_CAP1EDGE_Msk) >> LPTIM_CCSR_CAP1EDGE_Pos);
}

/**
  * @brief    Get Channel2 Captured Edge
  * @rmtoll   CCSR    CAP2EDGE    LL_LPTIM_IC_GetCapcturedEdgeChannel2
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_IC_CAPCTURED_EDGE_FALLING
  *           @arg @ref LL_LPTIM_IC_CAPCTURED_EDGE_RISING
  */
__STATIC_INLINE uint32_t LL_LPTIM_IC_GetCapcturedEdgeChannel2(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_CAP2EDGE_Msk) >> LPTIM_CCSR_CAP2EDGE_Pos);
}

/**
  * @brief    Set Channel 1 Capture Source Select
  * @rmtoll   CCSR    CAP1SSEL    LL_LPTIM_IC_SetCapctureSourceChannel1
  * @param    LPTIMx LPTIM instance
  * @param    CaptureSource This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_IC1_CAPCTURE_SOURCE_CHANNEL1
  *           @arg @ref LL_LPTIM_IC1_CAPCTURE_SOURCE_XTLF
  *           @arg @ref LL_LPTIM_IC1_CAPCTURE_SOURCE_RCLP
  *           @arg @ref LL_LPTIM_IC1_CAPCTURE_SOURCE_RC4M_PSC
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_IC_SetCapctureSourceChannel1(LPTIM_Type *LPTIMx, uint32_t CaptureSource)
{
    MODIFY_REG(LPTIMx->CCSR, LPTIM_CCSR_CAP1SSEL_Msk, CaptureSource);
}

/**
  * @brief    Get Channel 1 Capture Source Select
  * @rmtoll   CCSR    CAP1SSEL    LL_LPTIM_IC_GetCapctureSourceChannel1
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_IC1_CAPCTURE_SOURCE_CHANNEL1
  *           @arg @ref LL_LPTIM_IC1_CAPCTURE_SOURCE_XTLF
  *           @arg @ref LL_LPTIM_IC1_CAPCTURE_SOURCE_RCLP
  *           @arg @ref LL_LPTIM_IC1_CAPCTURE_SOURCE_RC4M_PSC
  */
__STATIC_INLINE uint32_t LL_LPTIM_IC_GetCapctureSourceChannel1(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_CAP1SSEL_Msk));
}

/**
  * @brief    Set Channel 2 Capture Source Select
  * @rmtoll   CCSR    CAP2SSEL    LL_LPTIM_IC_SetCapctureSourceChannel2
  * @param    LPTIMx LPTIM instance
  * @param    CaptureSource This parameter can be one of the following values:
  *           @arg @ref LL_LPTIM_IC2_CAPCTURE_SOURCE_GPTIM1_TRGO
  *           @arg @ref LL_LPTIM_IC2_CAPCTURE_SOURCE_GPTIM2_TRGO
  *           @arg @ref LL_LPTIM_IC2_CAPCTURE_SOURCE_ATIM_TRGO
  *           @arg @ref LL_LPTIM_IC2_CAPCTURE_SOURCE_CHANNEL2
  * @retval   None
  */
__STATIC_INLINE void LL_LPTIM_IC_SetCapctureSourceChannel2(LPTIM_Type *LPTIMx, uint32_t CaptureSource)
{
    MODIFY_REG(LPTIMx->CCSR, LPTIM_CCSR_CAP2SSEL_Msk, CaptureSource);
}

/**
  * @brief    Get Channel 2 Capture Source Select
  * @rmtoll   CCSR    CAP2SSEL    LL_LPTIM_IC_GetCapctureSourceChannel2
  * @param    LPTIMx LPTIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LPTIM_IC2_CAPCTURE_SOURCE_GPTIM1_TRGO
  *           @arg @ref LL_LPTIM_IC2_CAPCTURE_SOURCE_GPTIM2_TRGO
  *           @arg @ref LL_LPTIM_IC2_CAPCTURE_SOURCE_ATIM_TRGO
  *           @arg @ref LL_LPTIM_IC2_CAPCTURE_SOURCE_CHANNEL2
  */
__STATIC_INLINE uint32_t LL_LPTIM_IC_GetCapctureSourceChannel2(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CCSR, LPTIM_CCSR_CAP2SSEL_Msk));
}

/**
  * @brief    Get 32bits-wide Current Counter 
  * @rmtoll   CNT        LL_LPTIM_GetCounter
  * @param    LPTIMx LPTIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_LPTIM_GetCounter(LPTIM_Type *LPTIMx)
{
    return (uint32_t)(READ_BIT(LPTIMx->CNT, 0xffffffffU) >> 0U);
}

/**
  * @}
  */

/** @defgroup LPTIM_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_LPTIM_DeInit(LPTIM_Type *LPTIMx);
void LL_LPTIM_ICModeStructInit(LL_TIM_IC_InitTypeDef *LPTIM_InitStruct);
void LL_LPTIM_OCModeStructInit(LL_TIM_OC_InitTypeDef *LPTIM_InitStruct);
void LL_LPTIM_TimeModeStructInit(LL_LPTIM_TimeInitTypeDef *LPTIM_InitStruct);
ErrorStatus LL_LPTIM_TimeModeInit(LPTIM_Type *LPTIMx, LL_LPTIM_TimeInitTypeDef *LPTIM_InitStruct);
ErrorStatus LL_LPTIM_IC_ModeInit(LPTIM_Type *LPTIMx,uint32_t Channel, LL_TIM_IC_InitTypeDef *LPTIM_InitStruct);
ErrorStatus LL_LPTIM_OC_ModeInit(LPTIM_Type *LPTIMx,uint32_t Channel, LL_TIM_OC_InitTypeDef *LPTIM_InitStruct);
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_LPTIM_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-12-02**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
