/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_adc.h
  * @author  FMSH Application Team
  * @brief   Head file of ADC LL Module
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
#ifndef __FM33LC0XX_LL_ADC_H
#define __FM33LC0XX_LL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_ADC
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup ADC_LL_ES_INIT ADC Exported Init structures
  * @{
  */

/**
  * @brief LL ADC Init Sturcture definition
  */
typedef  struct
{
    uint32_t AdcClockSource;
    
    uint32_t AdcClockPrescaler;

}LL_ADC_CommonInitTypeDef;	
	
typedef struct
{ 
    
  uint32_t ADC_ContinuousConvMode;    
    
  uint32_t ADC_AutoMode;

  uint32_t ADC_WaitMode;

  uint32_t ADC_OverrunMode;
                                                                                
  uint32_t ADC_ScanDirection;
                                                                                
  uint32_t ADC_ExternalTrigConv;

  uint32_t ADC_SamplingTimeControl;

  uint32_t ADC_SamplingStartControl;
                                  
  uint32_t ADC_Channel_Swap_Wiat;                 
                                          
  uint32_t ADC_Channel_Fast_Time; 

  uint32_t ADC_Channel_Slow_Time;

  FunState ADC_Oversampling;

  uint32_t ADC_OverSampingRatio;

  uint32_t ADC_OversamplingShift;                                        
                                          
}LL_ADC_InitTypeDef;	
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Constants ADC Exported Constants
  * @{
  */
#define    LL_ADC_EXTERNAL_CH_0                                   (0x1U << 0U)
#define    LL_ADC_EXTERNAL_CH_1                                   (0x1U << 1U)
#define    LL_ADC_EXTERNAL_CH_2                                   (0x1U << 2U)
#define    LL_ADC_EXTERNAL_CH_3                                   (0x1U << 3U)
#define    LL_ADC_EXTERNAL_CH_4                                   (0x1U << 4U)
#define    LL_ADC_EXTERNAL_CH_5                                   (0x1U << 5U)
#define    LL_ADC_EXTERNAL_CH_6                                   (0x1U << 6U)
#define    LL_ADC_EXTERNAL_CH_7                                   (0x1U << 7U)
#define    LL_ADC_EXTERNAL_CH_8                                   (0x1U << 8U)
#define    LL_ADC_EXTERNAL_CH_9                                   (0x1U << 9U)
#define    LL_ADC_EXTERNAL_CH_10                                  (0x1U << 10U)
#define    LL_ADC_EXTERNAL_CH_11                                  (0x1U << 11U)
#define    LL_ADC_EXTERNAL_CH_ALL                                 (0xfffU << 0U)
#define    LL_ADC_INTERNAL_CH_TEMPSENSOR                          (0x1U << 16U)
#define    LL_ADC_INTERNAL_CH_VREF                                (0x1U << 17U)
#define    LL_ADC_INTERNAL_CH_ALL                                 (0x3U << 16U)
#define    LL_ADC_OUTPUT_CH_OPA1                                  (0x1U << 18U)
#define    LL_ADC_OUTPUT_CH_OPA2                                  (0x1U << 19U)
#define    LL_ADC_OUTPUT_CH_ALL                                   (0x3U << 18U)

#define    LL_ADC_SAMPLING_TIME_CONTROL_BY_REG                    (0x0U << ADC_CR_EXSAMP_Pos)
#define    LL_ADC_SAMPLING_TIME_CONTROL_BY_IO_INPUT               (0x1U << ADC_CR_EXSAMP_Pos)

#define    LL_ADC_SAMPLING_START_CONTROL_BY_REG                   (0x0U << ADC_CR_EXSYNC_Pos)
#define    LL_ADC_SAMPLING_START_CONTROL_BY_IO_INPUT              (0x1U << ADC_CR_EXSYNC_Pos)

#define    LL_ADC_TRIG_EXT_PA8                                    (0x0U << ADC_CFGR_EXTS_Pos)
#define    LL_ADC_TRIG_EXT_PB9                                    (0x1U << ADC_CFGR_EXTS_Pos)
#define    LL_ADC_TRIG_EXT_ATIM_TRGO                              (0x3U << ADC_CFGR_EXTS_Pos)
#define    LL_ADC_TRIG_EXT_GPTIM1_TRGO                            (0x4U << ADC_CFGR_EXTS_Pos)
#define    LL_ADC_TRIG_EXT_GPTIM2_TRGO                            (0x5U << ADC_CFGR_EXTS_Pos)
#define    LL_ADC_TRIG_EXT_RTC_TRGO                               (0x7U << ADC_CFGR_EXTS_Pos)
#define    LL_ADC_TRIG_EXT_BSTIM1_TRGO                            (0x8U << ADC_CFGR_EXTS_Pos)
#define    LL_ADC_TRIG_EXT_COMP1_TRGO                             (0xaU << ADC_CFGR_EXTS_Pos)
#define    LL_ADC_TRIG_EXT_COMP2_TRGO                             (0xbU << ADC_CFGR_EXTS_Pos)

#define    LL_ADC_CONV_SINGLE                                     (0x0U << ADC_CFGR_CONT_Pos)
#define    LL_ADC_CONV_CONTINUOUS                                 (0x1U << ADC_CFGR_CONT_Pos)

#define    LL_ADC_AWD_CHANNEL_0_REG                               (0x0U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_1_REG                               (0x1U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_2_REG                               (0x2U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_3_REG                               (0x3U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_4_REG                               (0x4U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_5_REG                               (0x5U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_6_REG                               (0x6U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_7_REG                               (0x7U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_8_REG                               (0x8U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_9_REG                               (0x9U << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_10_REG                              (0xaU << ADC_CFGR_AWDCH_Pos)
#define    LL_ADC_AWD_CHANNEL_11_REG                              (0xbU << ADC_CFGR_AWDCH_Pos)

#define    LL_ADC_AWD_ALL_CHANNELS_REG                            (0x0U << ADC_CFGR_AWDSC_Pos)
#define    LL_ADC_AWD_SINGLE_CHANNEL_REG                          (0x1U << ADC_CFGR_AWDSC_Pos)

#define    LL_ADC_OVR_DATA_PRESERVED                              (0x0U << ADC_CFGR_OVRM_Pos)
#define    LL_ADC_OVR_DATA_OVERWRITTEN                            (0x1U << ADC_CFGR_OVRM_Pos)

#define    LL_ADC_EXT_TRIGGER_NONE                                (0x0U << ADC_CFGR_TRGCFG_Pos)
#define    LL_ADC_EXT_TRIGGER_RISING                              (0x1U << ADC_CFGR_TRGCFG_Pos)
#define    LL_ADC_EXT_TRIGGER_FALLING                             (0x2U << ADC_CFGR_TRGCFG_Pos)
#define    LL_ADC_EXT_TRIGGER_BOTHEDGE                            (0x3U << ADC_CFGR_TRGCFG_Pos)

#define    LL_ADC_SEQ_SCAN_DIR_FORWARD                            (0x0U << ADC_CFGR_SCANDIR_Pos)
#define    LL_ADC_SEQ_SCAN_DIR_BACKWARD                           (0x1U << ADC_CFGR_SCANDIR_Pos)

#define    LL_ADC_WAIT_MODE_NO_WAIT                               (0x0U << ADC_CFGR_WAIT_Pos)
#define    LL_ADC_WAIT_MODE_WAIT                                  (0x1U << ADC_CFGR_WAIT_Pos)

#define    LL_ADC_SINGLE_CONV_MODE_AUTO                           (0x0U << ADC_CFGR_SEMI_Pos)
#define    LL_ADC_SINGLE_CONV_MODE_SEMIAUTO                       (0x1U << ADC_CFGR_SEMI_Pos)

#define    LL_ADC_OVERSAMPLING_2X                                 (0x0U << ADC_CFGR_OVSR_Pos)
#define    LL_ADC_OVERSAMPLING_4X                                 (0x1U << ADC_CFGR_OVSR_Pos)
#define    LL_ADC_OVERSAMPLING_8X                                 (0x2U << ADC_CFGR_OVSR_Pos)
#define    LL_ADC_OVERSAMPLING_16X                                (0x3U << ADC_CFGR_OVSR_Pos)
#define    LL_ADC_OVERSAMPLING_32X                                (0x4U << ADC_CFGR_OVSR_Pos)
#define    LL_ADC_OVERSAMPLING_64X                                (0x5U << ADC_CFGR_OVSR_Pos)
#define    LL_ADC_OVERSAMPLING_128X                               (0x6U << ADC_CFGR_OVSR_Pos)
#define    LL_ADC_OVERSAMPLING_256X                               (0x7U << ADC_CFGR_OVSR_Pos)

#define    LL_ADC_OVERSAMPLING_RESULT_ORIGINAL                    (0x0U << ADC_CFGR_OVSS_Pos)
#define    LL_ADC_OVERSAMPLING_RESULT_DIV2                        (0x1U << ADC_CFGR_OVSS_Pos)
#define    LL_ADC_OVERSAMPLING_RESULT_DIV4                        (0x2U << ADC_CFGR_OVSS_Pos)
#define    LL_ADC_OVERSAMPLING_RESULT_DIV8                        (0x3U << ADC_CFGR_OVSS_Pos)
#define    LL_ADC_OVERSAMPLING_RESULT_DIV16                       (0x4U << ADC_CFGR_OVSS_Pos)
#define    LL_ADC_OVERSAMPLING_RESULT_DIV32                       (0x5U << ADC_CFGR_OVSS_Pos)
#define    LL_ADC_OVERSAMPLING_RESULT_DIV64                       (0x6U << ADC_CFGR_OVSS_Pos)
#define    LL_ADC_OVERSAMPLING_RESULT_DIV128                      (0x7U << ADC_CFGR_OVSS_Pos)
#define    LL_ADC_OVERSAMPLING_RESULT_DIV256                      (0x8U << ADC_CFGR_OVSS_Pos)

#define    LL_ADC_DMA_TRANSFER_MODE_SINGLE                        (0x0U << ADC_CFGR_DMACFG_Pos)
#define    LL_ADC_DMA_TRANSFER_MODE_CIRCLE                        (0x1U << ADC_CFGR_DMACFG_Pos)

#define    LL_ADC_SLOW_CH_SAMPLING_TIME_4_ADCCLK                  (0x0U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_6_ADCCLK                  (0x1U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_9_ADCCLK                  (0x2U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_10_ADCCLK                 (0x3U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_16_ADCCLK                 (0x4U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_24_ADCCLK                 (0x5U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_32_ADCCLK                 (0x6U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_48_ADCCLK                 (0x7U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_96_ADCCLK                 (0x8U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_128_ADCCLK                (0x9U << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_192_ADCCLK                (0xaU << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_256_ADCCLK                (0xbU << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_384_ADCCLK                (0xcU << ADC_SMTR_SMTS1_Pos)
#define    LL_ADC_SLOW_CH_SAMPLING_TIME_SOFTWARE_CONTROL          (0xdU << ADC_SMTR_SMTS1_Pos)

#define    LL_ADC_FAST_CH_SAMPLING_TIME_4_ADCCLK                  (0x0U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_6_ADCCLK                  (0x1U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_9_ADCCLK                  (0x2U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_10_ADCCLK                 (0x3U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_16_ADCCLK                 (0x4U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_24_ADCCLK                 (0x5U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK                 (0x6U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_48_ADCCLK                 (0x7U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_96_ADCCLK                 (0x8U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_128_ADCCLK                (0x9U << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_192_ADCCLK                (0xaU << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_256_ADCCLK                (0xbU << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_384_ADCCLK                (0xcU << ADC_SMTR_SMTS2_Pos)
#define    LL_ADC_FAST_CH_SAMPLING_TIME_SOFTWARE_CONTROL          (0xdU << ADC_SMTR_SMTS2_Pos)

#define    LL_ADC_SAMPLEING_INTERVAL_2_CYCLE                      (0x0U << ADC_SMTR_CHCG_Pos)
#define    LL_ADC_SAMPLEING_INTERVAL_3_CYCLES                     (0x3U << ADC_SMTR_CHCG_Pos)
#define    LL_ADC_SAMPLEING_INTERVAL_4_CYCLES                     (0x4U << ADC_SMTR_CHCG_Pos)
#define    LL_ADC_SAMPLEING_INTERVAL_5_CYCLES                     (0x5U << ADC_SMTR_CHCG_Pos)
#define    LL_ADC_SAMPLEING_INTERVAL_6_CYCLES                     (0x6U << ADC_SMTR_CHCG_Pos)
#define    LL_ADC_SAMPLEING_INTERVAL_7_CYCLES                     (0x7U << ADC_SMTR_CHCG_Pos)
#define    LL_ADC_SAMPLEING_INTERVAL_8_CYCLES                     (0x8U << ADC_SMTR_CHCG_Pos)
#define    LL_ADC_SAMPLEING_INTERVAL_9_CYCLES                     (0x9U << ADC_SMTR_CHCG_Pos)
#define    LL_ADC_SAMPLEING_INTERVAL_10_CYCLES                    (0xaU << ADC_SMTR_CHCG_Pos)
#define    LL_ADC_SAMPLEING_INTERVAL_11_CYCLES                    (0xbU << ADC_SMTR_CHCG_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Functions ADC Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CR    ADEN    LL_ADC_Enable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_Enable(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR, ADC_CR_ADEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    ADEN    LL_ADC_Disable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_Disable(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CR, ADC_CR_ADEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    ADEN    LL_ADC_IsEnabled
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabled(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR, ADC_CR_ADEN_Msk) == ADC_CR_ADEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    START    LL_ADC_StartConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_StartConversion(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR, ADC_CR_START_Msk);
}

/**
  * @brief    
  * @rmtoll   SAMPT    SAMPT_S    LL_ADC_SoftwareStopSampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SoftwareStopSampling(ADC_Type *ADCx)
{
    SET_BIT(ADCx->SAMPT, ADC_SAMPT_SAMPT_S_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    EXSAMP    LL_ADC_SetSamplingTimeControlMode
  * @param    ADCx ADC instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_ADC_SAMPLING_TIME_CONTROL_BY_REG
  *           @arg @ref LL_ADC_SAMPLING_TIME_CONTROL_BY_IO_INPUT
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetSamplingTimeControlMode(ADC_Type *ADCx, uint32_t Mode)
{
    MODIFY_REG(ADCx->CR, ADC_CR_EXSAMP_Msk, Mode);
}

/**
  * @brief    
  * @rmtoll   CR    EXSAMP    LL_ADC_GetSamplingTimeControlMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_SAMPLING_TIME_CONTROL_BY_REG
  *           @arg @ref LL_ADC_SAMPLING_TIME_CONTROL_BY_IO_INPUT
  */
__STATIC_INLINE uint32_t LL_ADC_GetSamplingTimeControlMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR, ADC_CR_EXSAMP_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    EXSYNC    LL_ADC_Set_SamplingStartControlMode
  * @param    ADCx ADC instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_ADC_SAMPLING_START_CONTROL_BY_REG
  *           @arg @ref LL_ADC_SAMPLING_START_CONTROL_BY_IO_INPUT
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_Set_SamplingStartControlMode(ADC_Type *ADCx, uint32_t Mode)
{
    MODIFY_REG(ADCx->CR, ADC_CR_EXSYNC_Msk, Mode);
}

/**
  * @brief    
  * @rmtoll   CR    EXSYNC    LL_ADC_Get_SamplingStartControlMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_SAMPLING_START_CONTROL_BY_REG
  *           @arg @ref LL_ADC_SAMPLING_START_CONTROL_BY_IO_INPUT
  */
__STATIC_INLINE uint32_t LL_ADC_Get_SamplingStartControlMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR, ADC_CR_EXSYNC_Msk));
}

/**
  * @brief    
  * @rmtoll   DR    DATA    LL_ADC_DMA_GetRegAddr
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ADC_DMA_GetRegAddr(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DR, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CFGR    EXTS    LL_ADC_SetTriggerSource
  * @param    ADCx ADC instance
  * @param    TriggerSource This parameter can be one of the following values:
  *           @arg @ref LL_ADC_TRIG_EXT_PA8
  *           @arg @ref LL_ADC_TRIG_EXT_PB9
  *           @arg @ref LL_ADC_TRIG_EXT_ATIM_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_GPTIM1_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_GPTIM2_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_RTC_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_BSTIM1_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_COMP1_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_COMP2_TRGO
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetTriggerSource(ADC_Type *ADCx, uint32_t TriggerSource)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_EXTS_Msk, TriggerSource);
}

/**
  * @brief    
  * @rmtoll   CFGR    EXTS    LL_ADC_GetTriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_TRIG_EXT_PA8
  *           @arg @ref LL_ADC_TRIG_EXT_PB9
  *           @arg @ref LL_ADC_TRIG_EXT_ATIM_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_GPTIM1_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_GPTIM2_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_RTC_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_BSTIM1_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_COMP1_TRGO
  *           @arg @ref LL_ADC_TRIG_EXT_COMP2_TRGO
  */
__STATIC_INLINE uint32_t LL_ADC_GetTriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_EXTS_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    CONT    LL_ADC_SetContinuousMode
  * @param    ADCx ADC instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_ADC_CONV_SINGLE
  *           @arg @ref LL_ADC_CONV_CONTINUOUS
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetContinuousMode(ADC_Type *ADCx, uint32_t Mode)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_CONT_Msk, Mode);
}

/**
  * @brief    
  * @rmtoll   CFGR    CONT    LL_ADC_GetContinuousMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_CONV_SINGLE
  *           @arg @ref LL_ADC_CONV_CONTINUOUS
  */
__STATIC_INLINE uint32_t LL_ADC_GetContinuousMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_CONT_Msk));
}

/**
  * @brief    
  * @rmtoll   IER    EOCIE    LL_ADC_EnableIT_EOC
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnableIT_EOC(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_EOCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    EOSIE    LL_ADC_EnableIT_EOS
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnableIT_EOS(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_EOSIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    OVRIE    LL_ADC_EnableIT_OVR
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnableIT_OVR(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_OVRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    AWD_ULIE    LL_ADC_EnableIT_AWD_UL
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnableIT_AWD_UL(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_AWD_ULIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    AWD_AHIE    LL_ADC_EnableIT_AWD_AH
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnableIT_AWD_AH(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_AWD_AHIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    EOCIE    LL_ADC_DisableIT_EOC
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableIT_EOC(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_EOCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    EOSIE    LL_ADC_DisableIT_EOS
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableIT_EOS(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_EOSIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    OVRIE    LL_ADC_DisableIT_OVR
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableIT_OVR(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_OVRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    AWD_ULIE    LL_ADC_DisableIT_AWD_UL
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableIT_AWD_UL(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_AWD_ULIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    AWD_AHIE    LL_ADC_DisableIT_AWD_AH
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableIT_AWD_AH(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_AWD_AHIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    EOCIE    LL_ADC_IsEnabledIT_EOC
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_EOC(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_EOCIE_Msk) == ADC_IER_EOCIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    EOSIE    LL_ADC_IsEnabledIT_EOS
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_EOS(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_EOSIE_Msk) == ADC_IER_EOSIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    OVRIE    LL_ADC_IsEnabledIT_OVR
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_OVR(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_OVRIE_Msk) == ADC_IER_OVRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    AWD_ULIE    LL_ADC_IsEnabledIT_AWD_UL
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_AWD_UL(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_AWD_ULIE_Msk) == ADC_IER_AWD_ULIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    AWD_AHIE    LL_ADC_IsEnabledIT_AWD_AH
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_AWD_AH(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_AWD_AHIE_Msk) == ADC_IER_AWD_AHIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    EOC    LL_ADC_IsActiveFlag_EOC
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_EOC(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_EOC_Msk) == (ADC_ISR_EOC_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    EOS    LL_ADC_IsActiveFlag_EOS
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_EOS(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_EOS_Msk) == (ADC_ISR_EOS_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    OVR    LL_ADC_IsActiveFlag_OVR
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_OVR(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_OVR_Msk) == (ADC_ISR_OVR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    BUSY    LL_ADC_IsActiveFlag_BUSY
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_BUSY(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_BUSY_Msk) == (ADC_ISR_BUSY_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    AWD_UL    LL_ADC_IsActiveFlag_AWD_UL
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_AWD_UL(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_AWD_UL_Msk) == (ADC_ISR_AWD_UL_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    AWD_AH    LL_ADC_IsActiveFlag_AWD_AH
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_AWD_AH(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_AWD_AH_Msk) == (ADC_ISR_AWD_AH_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    EOC    LL_ADC_ClearFlag_EOC
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_ClearFlag_EOC(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_EOC_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    EOS    LL_ADC_ClearFlag_EOS
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_ClearFlag_EOS(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_EOS_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    OVR    LL_ADC_ClearFlag_OVR
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_ClearFlag_OVR(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_OVR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    AWD_UL    LL_ADC_ClearFlag_AWD_UL
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_ClearFlag_AWD_UL(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_AWD_UL_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    AWD_AH    LL_ADC_ClearFlag_AWD_AH
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_ClearFlag_AWD_AH(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_AWD_AH_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    AWDCH    LL_ADC_SetAnalogWDMonitChannelSelect
  * @param    ADCx ADC instance
  * @param    AWDChannelGroup This parameter can be one of the following values:
  *           @arg @ref LL_ADC_AWD_CHANNEL_0_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_1_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_2_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_3_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_4_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_5_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_6_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_7_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_8_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_9_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_10_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_11_REG
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetAnalogWDMonitChannelSelect(ADC_Type *ADCx, uint32_t AWDChannelGroup)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_AWDCH_Msk, AWDChannelGroup);
}

/**
  * @brief    
  * @rmtoll   CFGR    AWDCH    LL_ADC_GetAnalogWDMonitChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_AWD_CHANNEL_0_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_1_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_2_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_3_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_4_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_5_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_6_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_7_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_8_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_9_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_10_REG
  *           @arg @ref LL_ADC_AWD_CHANNEL_11_REG
  */
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDMonitChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_AWDCH_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    AWDSC    LL_ADC_SetAnalogWDMonitChannelMode
  * @param    ADCx ADC instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG
  *           @arg @ref LL_ADC_AWD_SINGLE_CHANNEL_REG
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetAnalogWDMonitChannelMode(ADC_Type *ADCx, uint32_t Mode)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_AWDSC_Msk, Mode);
}

/**
  * @brief    
  * @rmtoll   CFGR    AWDSC    LL_ADC_GetAnalogWDMonitChannelMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG
  *           @arg @ref LL_ADC_AWD_SINGLE_CHANNEL_REG
  */
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDMonitChannelMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_AWDSC_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    AWDEN    LL_ADC_EnableAnologWD
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnableAnologWD(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR, ADC_CFGR_AWDEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    AWDEN    LL_ADC_DisableAnologWD
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableAnologWD(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR, ADC_CFGR_AWDEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    AWDEN    LL_ADC_IsEnabledAnologWD
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledAnologWD(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_AWDEN_Msk) == ADC_CFGR_AWDEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    OVRM    LL_ADC_SetOverrun
  * @param    ADCx ADC instance
  * @param    Overrun This parameter can be one of the following values:
  *           @arg @ref LL_ADC_OVR_DATA_PRESERVED
  *           @arg @ref LL_ADC_OVR_DATA_OVERWRITTEN
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetOverrun(ADC_Type *ADCx, uint32_t Overrun)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_OVRM_Msk, Overrun);
}

/**
  * @brief    
  * @rmtoll   CFGR    OVRM    LL_ADC_GetOverrun
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_OVR_DATA_PRESERVED
  *           @arg @ref LL_ADC_OVR_DATA_OVERWRITTEN
  */
__STATIC_INLINE uint32_t LL_ADC_GetOverrun(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_OVRM_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    IOTRFEN    LL_ADC_EnableTriggerFilter
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnableTriggerFilter(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR, ADC_CFGR_IOTRFEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    IOTRFEN    LL_ADC_DisableTriggerFilter
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableTriggerFilter(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR, ADC_CFGR_IOTRFEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    IOTRFEN    LL_ADC_IsEnabledTriggerFilter
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledTriggerFilter(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_IOTRFEN_Msk) == ADC_CFGR_IOTRFEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    TRGCFG    LL_ADC_SetTriggerEdge
  * @param    ADCx ADC instance
  * @param    ExternalTriggerEdge This parameter can be one of the following values:
  *           @arg @ref LL_ADC_EXT_TRIGGER_NONE
  *           @arg @ref LL_ADC_EXT_TRIGGER_RISING
  *           @arg @ref LL_ADC_EXT_TRIGGER_FALLING
  *           @arg @ref LL_ADC_EXT_TRIGGER_BOTHEDGE
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetTriggerEdge(ADC_Type *ADCx, uint32_t ExternalTriggerEdge)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_TRGCFG_Msk, ExternalTriggerEdge);
}

/**
  * @brief    
  * @rmtoll   CFGR    TRGCFG    LL_ADC_GetTriggerEdge
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_EXT_TRIGGER_NONE
  *           @arg @ref LL_ADC_EXT_TRIGGER_RISING
  *           @arg @ref LL_ADC_EXT_TRIGGER_FALLING
  *           @arg @ref LL_ADC_EXT_TRIGGER_BOTHEDGE
  */
__STATIC_INLINE uint32_t LL_ADC_GetTriggerEdge(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_TRGCFG_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    SCANDIR    LL_ADC_SetSequencerScanDirection
  * @param    ADCx ADC instance
  * @param    ScanDirection This parameter can be one of the following values:
  *           @arg @ref LL_ADC_SEQ_SCAN_DIR_FORWARD
  *           @arg @ref LL_ADC_SEQ_SCAN_DIR_BACKWARD
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetSequencerScanDirection(ADC_Type *ADCx, uint32_t ScanDirection)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_SCANDIR_Msk, ScanDirection);
}

/**
  * @brief    
  * @rmtoll   CFGR    SCANDIR    LL_ADC_GetSequencerScanDirection
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_SEQ_SCAN_DIR_FORWARD
  *           @arg @ref LL_ADC_SEQ_SCAN_DIR_BACKWARD
  */
__STATIC_INLINE uint32_t LL_ADC_GetSequencerScanDirection(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_SCANDIR_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    WAIT    LL_ADC_SetWaitMode
  * @param    ADCx ADC instance
  * @param    WaitMode This parameter can be one of the following values:
  *           @arg @ref LL_ADC_WAIT_MODE_NO_WAIT
  *           @arg @ref LL_ADC_WAIT_MODE_WAIT
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetWaitMode(ADC_Type *ADCx, uint32_t WaitMode)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_WAIT_Msk, WaitMode);
}

/**
  * @brief    
  * @rmtoll   CFGR    WAIT    LL_ADC_GetWaitMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_WAIT_MODE_NO_WAIT
  *           @arg @ref LL_ADC_WAIT_MODE_WAIT
  */
__STATIC_INLINE uint32_t LL_ADC_GetWaitMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_WAIT_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    SEMI    LL_ADC_SetSingleConversionAutoMode
  * @param    ADCx ADC instance
  * @param    AutoMode This parameter can be one of the following values:
  *           @arg @ref LL_ADC_SINGLE_CONV_MODE_AUTO
  *           @arg @ref LL_ADC_SINGLE_CONV_MODE_SEMIAUTO
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetSingleConversionAutoMode(ADC_Type *ADCx, uint32_t AutoMode)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_SEMI_Msk, AutoMode);
}

/**
  * @brief    
  * @rmtoll   CFGR    SEMI    LL_ADC_GetSingleConversionAutoMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_SINGLE_CONV_MODE_AUTO
  *           @arg @ref LL_ADC_SINGLE_CONV_MODE_SEMIAUTO
  */
__STATIC_INLINE uint32_t LL_ADC_GetSingleConversionAutoMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_SEMI_Msk));
}

/**
  * @brief    
  * @rmtoll   HLTR    AWD_LT    LL_ADC_SetAnalogWD_LowThreshold
  * @param    ADCx ADC instance
  * @param    ThresholdValue 
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetAnalogWD_LowThreshold(ADC_Type *ADCx, uint32_t ThresholdValue)
{
    MODIFY_REG(ADCx->HLTR, (0xfffU << 0U), (ThresholdValue << 0U));
}

/**
  * @brief    
  * @rmtoll   HLTR    AWD_LT    LL_ADC_GetAnalogWD_LowThreshold
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWD_LowThreshold(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->HLTR, 0xfffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   HLTR    AWD_HT    LL_ADC_SetAnalogWD_HighThreshold
  * @param    ADCx ADC instance
  * @param    ThresholdValue 
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetAnalogWD_HighThreshold(ADC_Type *ADCx, uint32_t ThresholdValue)
{
    MODIFY_REG(ADCx->HLTR, (0xfffU << 16U), (ThresholdValue << 16U));
}

/**
  * @brief    
  * @rmtoll   HLTR    AWD_HT    LL_ADC_GetAnalogWD_HighThreshold
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWD_HighThreshold(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->HLTR, 0xfffU) >> 16U);
}

/**
  * @brief    
  * @rmtoll   CFGR    OVSEN    LL_ADC_EnableOverSampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnableOverSampling(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR, ADC_CFGR_OVSEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    OVSEN    LL_ADC_DisableOverSampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableOverSampling(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR, ADC_CFGR_OVSEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    OVSEN    LL_ADC_IsEnabledOverSampling
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledOverSampling(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_OVSEN_Msk) == ADC_CFGR_OVSEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    OVSR    LL_ADC_SetOverSamplingRatio
  * @param    ADCx ADC instance
  * @param    OverSamplingRatio This parameter can be one of the following values:
  *           @arg @ref LL_ADC_OVERSAMPLING_2X
  *           @arg @ref LL_ADC_OVERSAMPLING_4X
  *           @arg @ref LL_ADC_OVERSAMPLING_8X
  *           @arg @ref LL_ADC_OVERSAMPLING_16X
  *           @arg @ref LL_ADC_OVERSAMPLING_32X
  *           @arg @ref LL_ADC_OVERSAMPLING_64X
  *           @arg @ref LL_ADC_OVERSAMPLING_128X
  *           @arg @ref LL_ADC_OVERSAMPLING_256X
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetOverSamplingRatio(ADC_Type *ADCx, uint32_t OverSamplingRatio)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_OVSR_Msk, OverSamplingRatio);
}

/**
  * @brief    
  * @rmtoll   CFGR    OVSR    LL_ADC_GetOverSamplingRatio
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_OVERSAMPLING_2X
  *           @arg @ref LL_ADC_OVERSAMPLING_4X
  *           @arg @ref LL_ADC_OVERSAMPLING_8X
  *           @arg @ref LL_ADC_OVERSAMPLING_16X
  *           @arg @ref LL_ADC_OVERSAMPLING_32X
  *           @arg @ref LL_ADC_OVERSAMPLING_64X
  *           @arg @ref LL_ADC_OVERSAMPLING_128X
  *           @arg @ref LL_ADC_OVERSAMPLING_256X
  */
__STATIC_INLINE uint32_t LL_ADC_GetOverSamplingRatio(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_OVSR_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    OVSS    LL_ADC_SetOverSamplingResult
  * @param    ADCx ADC instance
  * @param    OverSamplingShift This parameter can be one of the following values:
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_ORIGINAL
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV2
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV4
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV8
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV16
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV32
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV64
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV128
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV256
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetOverSamplingResult(ADC_Type *ADCx, uint32_t OverSamplingShift)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_OVSS_Msk, OverSamplingShift);
}

/**
  * @brief    
  * @rmtoll   CFGR    OVSS    LL_ADC_GetOverSamplingResult
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_ORIGINAL
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV2
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV4
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV8
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV16
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV32
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV64
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV128
  *           @arg @ref LL_ADC_OVERSAMPLING_RESULT_DIV256
  */
__STATIC_INLINE uint32_t LL_ADC_GetOverSamplingResult(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_OVSS_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    DMAEN    LL_ADC_EnableDMATransfer
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnableDMATransfer(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR, ADC_CFGR_DMAEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    DMAEN    LL_ADC_DisableDMATransfer
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableDMATransfer(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR, ADC_CFGR_DMAEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    DMAEN    LL_ADC_IsEnabledDMATransfer
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledDMATransfer(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_DMAEN_Msk) == ADC_CFGR_DMAEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    DMACFG    LL_ADC_SetDMAMode
  * @param    ADCx ADC instance
  * @param    DMAMode This parameter can be one of the following values:
  *           @arg @ref LL_ADC_DMA_TRANSFER_MODE_SINGLE
  *           @arg @ref LL_ADC_DMA_TRANSFER_MODE_CIRCLE
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetDMAMode(ADC_Type *ADCx, uint32_t DMAMode)
{
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_DMACFG_Msk, DMAMode);
}

/**
  * @brief    
  * @rmtoll   CFGR    DMACFG    LL_ADC_GetDMAMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_DMA_TRANSFER_MODE_SINGLE
  *           @arg @ref LL_ADC_DMA_TRANSFER_MODE_CIRCLE
  */
__STATIC_INLINE uint32_t LL_ADC_GetDMAMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_DMACFG_Msk));
}

/**
  * @brief    
  * @rmtoll   SMTR    SMTS1    LL_ADC_SetSamplingTimeSlowCH
  * @param    ADCx ADC instance
  * @param    SamplingTime This parameter can be one of the following values:
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_6_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_9_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_10_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_24_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_48_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_SOFTWARE_CONTROL
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetSamplingTimeSlowCH(ADC_Type *ADCx, uint32_t SamplingTime)
{
    MODIFY_REG(ADCx->SMTR, ADC_SMTR_SMTS1_Msk, SamplingTime);
}

/**
  * @brief    
  * @rmtoll   SMTR    SMTS1    LL_ADC_GetlSamplingTimeSlowCH
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_6_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_9_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_10_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_24_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_48_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref LL_ADC_SLOW_CH_SAMPLING_TIME_SOFTWARE_CONTROL
  */
__STATIC_INLINE uint32_t LL_ADC_GetlSamplingTimeSlowCH(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SMTR, ADC_SMTR_SMTS1_Msk));
}

/**
  * @brief    
  * @rmtoll   SMTR    SMTS2    LL_ADC_SetSamplingTimeFastCH
  * @param    ADCx ADC instance
  * @param    SamplingTime This parameter can be one of the following values:
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_6_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_9_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_10_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_24_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_48_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_SOFTWARE_CONTROL
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetSamplingTimeFastCH(ADC_Type *ADCx, uint32_t SamplingTime)
{
    MODIFY_REG(ADCx->SMTR, ADC_SMTR_SMTS2_Msk, SamplingTime);
}

/**
  * @brief    
  * @rmtoll   SMTR    SMTS2    LL_ADC_GetSamplingTimeFastCH
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_6_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_9_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_10_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_24_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_48_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref LL_ADC_FAST_CH_SAMPLING_TIME_SOFTWARE_CONTROL
  */
__STATIC_INLINE uint32_t LL_ADC_GetSamplingTimeFastCH(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SMTR, ADC_SMTR_SMTS2_Msk));
}

/**
  * @brief    
  * @rmtoll   SMTR    CHCG    LL_ADC_SetSamplingInterval
  * @param    ADCx ADC instance
  * @param    SamplingInterval This parameter can be one of the following values:
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_2_CYCLE
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_3_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_4_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_5_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_6_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_7_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_8_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_9_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_10_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_11_CYCLES
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_SetSamplingInterval(ADC_Type *ADCx, uint32_t SamplingInterval)
{
    MODIFY_REG(ADCx->SMTR, ADC_SMTR_CHCG_Msk, SamplingInterval);
}

/**
  * @brief    
  * @rmtoll   SMTR    CHCG    LL_ADC_GetSamplingInterval
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_2_CYCLE
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_3_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_4_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_5_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_6_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_7_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_8_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_9_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_10_CYCLES
  *           @arg @ref LL_ADC_SAMPLEING_INTERVAL_11_CYCLES
  */
__STATIC_INLINE uint32_t LL_ADC_GetSamplingInterval(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SMTR, ADC_SMTR_CHCG_Msk));
}

/**
  * @brief    
  * @rmtoll   CHER        LL_ADC_EnalbleSequencerChannel
  * @param    ADCx ADC instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ADC_EXTERNAL_CH_0
  *           @arg @ref LL_ADC_EXTERNAL_CH_1
  *           @arg @ref LL_ADC_EXTERNAL_CH_2
  *           @arg @ref LL_ADC_EXTERNAL_CH_3
  *           @arg @ref LL_ADC_EXTERNAL_CH_4
  *           @arg @ref LL_ADC_EXTERNAL_CH_5
  *           @arg @ref LL_ADC_EXTERNAL_CH_6
  *           @arg @ref LL_ADC_EXTERNAL_CH_7
  *           @arg @ref LL_ADC_EXTERNAL_CH_8
  *           @arg @ref LL_ADC_EXTERNAL_CH_9
  *           @arg @ref LL_ADC_EXTERNAL_CH_10
  *           @arg @ref LL_ADC_EXTERNAL_CH_11
  *           @arg @ref LL_ADC_EXTERNAL_CH_ALL
  *           @arg @ref LL_ADC_INTERNAL_CH_TEMPSENSOR
  *           @arg @ref LL_ADC_INTERNAL_CH_VREF
  *           @arg @ref LL_ADC_INTERNAL_CH_ALL
  *           @arg @ref LL_ADC_OUTPUT_CH_OPA1
  *           @arg @ref LL_ADC_OUTPUT_CH_OPA2
  *           @arg @ref LL_ADC_OUTPUT_CH_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_EnalbleSequencerChannel(ADC_Type *ADCx, uint32_t Channel)
{
    SET_BIT(ADCx->CHER, ((Channel & 0xfffff) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   CHER        LL_ADC_DisableSequencerChannel
  * @param    ADCx ADC instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ADC_EXTERNAL_CH_0
  *           @arg @ref LL_ADC_EXTERNAL_CH_1
  *           @arg @ref LL_ADC_EXTERNAL_CH_2
  *           @arg @ref LL_ADC_EXTERNAL_CH_3
  *           @arg @ref LL_ADC_EXTERNAL_CH_4
  *           @arg @ref LL_ADC_EXTERNAL_CH_5
  *           @arg @ref LL_ADC_EXTERNAL_CH_6
  *           @arg @ref LL_ADC_EXTERNAL_CH_7
  *           @arg @ref LL_ADC_EXTERNAL_CH_8
  *           @arg @ref LL_ADC_EXTERNAL_CH_9
  *           @arg @ref LL_ADC_EXTERNAL_CH_10
  *           @arg @ref LL_ADC_EXTERNAL_CH_11
  *           @arg @ref LL_ADC_EXTERNAL_CH_ALL
  *           @arg @ref LL_ADC_INTERNAL_CH_TEMPSENSOR
  *           @arg @ref LL_ADC_INTERNAL_CH_VREF
  *           @arg @ref LL_ADC_INTERNAL_CH_ALL
  *           @arg @ref LL_ADC_OUTPUT_CH_OPA1
  *           @arg @ref LL_ADC_OUTPUT_CH_OPA2
  *           @arg @ref LL_ADC_OUTPUT_CH_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_ADC_DisableSequencerChannel(ADC_Type *ADCx, uint32_t Channel)
{
    CLEAR_BIT(ADCx->CHER, ((Channel & 0xfffff) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   CHER        LL_ADC_IsEnabledSequencerChannel
  * @param    ADCx ADC instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ADC_EXTERNAL_CH_0
  *           @arg @ref LL_ADC_EXTERNAL_CH_1
  *           @arg @ref LL_ADC_EXTERNAL_CH_2
  *           @arg @ref LL_ADC_EXTERNAL_CH_3
  *           @arg @ref LL_ADC_EXTERNAL_CH_4
  *           @arg @ref LL_ADC_EXTERNAL_CH_5
  *           @arg @ref LL_ADC_EXTERNAL_CH_6
  *           @arg @ref LL_ADC_EXTERNAL_CH_7
  *           @arg @ref LL_ADC_EXTERNAL_CH_8
  *           @arg @ref LL_ADC_EXTERNAL_CH_9
  *           @arg @ref LL_ADC_EXTERNAL_CH_10
  *           @arg @ref LL_ADC_EXTERNAL_CH_11
  *           @arg @ref LL_ADC_EXTERNAL_CH_ALL
  *           @arg @ref LL_ADC_INTERNAL_CH_TEMPSENSOR
  *           @arg @ref LL_ADC_INTERNAL_CH_VREF
  *           @arg @ref LL_ADC_INTERNAL_CH_ALL
  *           @arg @ref LL_ADC_OUTPUT_CH_OPA1
  *           @arg @ref LL_ADC_OUTPUT_CH_OPA2
  *           @arg @ref LL_ADC_OUTPUT_CH_ALL
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledSequencerChannel(ADC_Type *ADCx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(ADCx->CHER, ((Channel & 0xfffff) << 0x0U)) == ((Channel & 0xfffff) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   DR        LL_ADC_ReadConversionData16
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ADC_ReadConversionData16(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DR, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   DR        LL_ADC_ReadConversionData12
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ADC_ReadConversionData12(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DR, 0xffffU) >> 0U);
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_ADC_CommonDeInit(void);
ErrorStatus  LL_ADC_DeInit(ADC_Type *ADCx);
uint32_t GetActualVddaVoltage(ADC_Type *ADCx);
void LL_ADC_StructInit(LL_ADC_InitTypeDef *ADC_InitStruct);
ErrorStatus LL_ADC_Init(ADC_Type *ADCx,LL_ADC_InitTypeDef  *ADC_InitStruct);
void LL_ADC_CommonStructInit(LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
ErrorStatus LL_ADC_CommonInit(LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_ADC_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2020-03-26**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
