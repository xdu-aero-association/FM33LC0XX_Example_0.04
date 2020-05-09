/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_atim.h
  * @author  FMSH Application Team
  * @brief   Head file of ATIM LL Module
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
#ifndef __FM33LC0XX_LL_ATIM_H
#define __FM33LC0XX_LL_ATIM_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_ATIM
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup ATIM_LL_ES_INIT ATIM Exported Init structures
  * @{
  */

/**
  * @brief ATIM Init Sturcture definition
  */
typedef struct
{
    /*! 时钟源选择 */    
    uint32_t ClockSource;
    /*! 预分频系数 */       
    uint32_t Prescaler;        
    /*! 计数模式 */   
    uint32_t CounterMode;      
    /*! 自动重装载值 */   
    uint32_t Autoreload;
    /*! 预装载使能 */   
    uint32_t AutoreloadState;    
    /*! 定时器分频系数与数字滤波器所使用的采样时钟分频比 */   
    uint32_t ClockDivision;
    /*! 重复计数次数 */   
    uint32_t RepetitionCounter;    
                                                         
} LL_ATIM_InitTypeDef;
/**
  * @brief ATIM SlaveMode Init Sturcture definition
  */
typedef struct
{ 
         
    /*! 外部时钟源模式 */
    uint32_t SlaveMode;           
    /*! 输入触发信号选择 */
    uint32_t TriggerSrc; 
    /*! Trigger 延迟*/
    uint32_t TriggerDelay; 
                                                         
} LL_ATIM_SlaveInitTypeDef;

/**
  * @brief  TIM ETR  configuration structure definition.
  */

typedef struct
{
    /*! 外部触发使能 */    
    uint32_t AsExternal; 
   /*! 外部时钟滤波 */   
    uint32_t ETRFilter;       
    /*! 外部时钟分频 */
    uint32_t ETRClockDivision;
    /*! 外部时钟触发极性 */
    uint32_t ETRPolarity;      
                       
} LL_ATIM_ETR_InitTypeDef;

/**
  * @brief  TIM Output Compare configuration structure definition.
  */
typedef struct
{
    /*! 比较输出模式 */    
    uint32_t OCMode; 
    /*! 比较互补输出使能 */
    uint32_t OCNState;
    /*! 比较输出极性 */
    uint32_t OCPolarity; 
    /*! 比较互补输出极性 */
    uint32_t OCNPolarity;    
    /*! 比较输出通道快速模式使能 */
    uint32_t OCFastMode;       
    /*! 输出比较预装载 */
    uint32_t OCPreload;        
    /*! 通道比较值 */
    uint32_t CompareValue; 
    /*! 输出空闲状态电平 */
    uint32_t OCIdleState;    
    /*! ETR清0使能 */                                                 
    uint32_t OCETRFStatus;
    /*! 互补输出空闲状态电平 */
    uint32_t OCNIdleState;
  
} LL_ATIM_OC_InitTypeDef;
/**
  * @brief  TIM Input Capture configuration structure definition.
  */

typedef struct
{
    /*! 输入捕获使能 */    
    uint32_t CaptureState; 
    /*! 输入捕获极性 */    
    uint32_t ICPolarity;    
    /*! 通道映射激活的输入选择 */
    uint32_t ICActiveInput; 
    /*! 输入分频 */
    uint32_t ICPrescaler;   
    /*! 输入滤波 */
    uint32_t ICFilter;      
                       
} LL_ATIM_IC_InitTypeDef;

/**
  * @brief  BDTR (Break and Dead Time) structure definition
  */
typedef struct
{
    /*! 运行状态下的输出关闭状态 */    
    uint32_t OSSRState;      
    /*! 空闲状态下的输出关闭状态 */ 
    uint32_t OSSIState;      
    /*! 寄存器写保护等级 */
    uint32_t LockLevel;      
    /*! 死区时间 */
    uint32_t DeadTime;
    /*! 刹车使能 */
    uint32_t BreakState;
    /*! 刹车信号滤波 */
    uint32_t BreakFilter;
    /*! 刹车信号极性 */
    uint32_t BreakPolarity;
    /*! 刹车后计数器重装后自动输出使能*/
    uint32_t AutomaticOutput;
    /*! 刹车信号1门控 */
    uint32_t GatedBrakeSignal_1;
    /*! 刹车信号2门控 */
    uint32_t GatedBrakeSignal_2;
    /*! 两路刹车信号控制逻辑 */
    uint32_t BrakeSignalCombined;
                            
} LL_ATIM_BDTR_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup ATIM_LL_Exported_Constants ATIM Exported Constants
  * @{
  */
#define    LL_ATIM_CHANNEL_1                                      (0x0U << 0U)
#define    LL_ATIM_CHANNEL_2                                      (0x1U << 0U)
#define    LL_ATIM_CHANNEL_3                                      (0x2U << 0U)
#define    LL_ATIM_CHANNEL_4                                      (0x3U << 0U)

#define    LL_ATIM_CLOCKDIVISION_DIV1                             (0x0U << ATIM_CR1_CKD_Pos)
#define    LL_ATIM_CLOCKDIVISION_DIV2                             (0x1U << ATIM_CR1_CKD_Pos)
#define    LL_ATIM_CLOCKDIVISION_DIV4                             (0x2U << ATIM_CR1_CKD_Pos)

#define    LL_ATIM_COUNTER_ALIGNED_EDGE                           (0x0U << ATIM_CR1_CMS_Pos)
#define    LL_ATIM_COUNTER_ALIGNED_CENTER_DOWN                    (0x1U << ATIM_CR1_CMS_Pos)
#define    LL_ATIM_COUNTER_ALIGNED_CENTER_UP                      (0x2U << ATIM_CR1_CMS_Pos)
#define    LL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN                 (0x3U << ATIM_CR1_CMS_Pos)

#define    LL_ATIM_COUNTER_DIRECT_UP                              (0x0U << ATIM_CR1_DIR_Pos)
#define    LL_ATIM_COUNTER_DIRECT_DOWN                            (0x1U << ATIM_CR1_DIR_Pos)

#define    LL_ATIM_ONEPULSEMODE_REPETITIVE                        (0x0U << ATIM_CR1_OPM_Pos)
#define    LL_ATIM_ONEPULSEMODE_SINGLE                            (0x1U << ATIM_CR1_OPM_Pos)

#define    LL_ATIM_UPDATESOURCE_REGULAR                           (0x0U << ATIM_CR1_URS_Pos)
#define    LL_ATIM_UPDATESOURCE_COUNTER                           (0x1U << ATIM_CR1_URS_Pos)

#define    LL_ATIM_OCN_IDLESTATE_LOW                              (0x0U << ATIM_CR2_OISN_Pos)
#define    LL_ATIM_OCN_IDLESTATE_HIGH                             (0x1U << ATIM_CR2_OISN_Pos)

#define    LL_ATIM_OC_IDLESTATE_LOW                                (0x0U << ATIM_CR2_OIS_Pos)
#define    LL_ATIM_OC_IDLESTATE_HIGH                               (0x1U << ATIM_CR2_OIS_Pos)

#define    LL_ATIM_TRGO_RESET                                     (0x0U << ATIM_CR2_MMS_Pos)
#define    LL_ATIM_TRGO_ENABLE                                    (0x1U << ATIM_CR2_MMS_Pos)
#define    LL_ATIM_TRGO_UPDATE                                    (0x2U << ATIM_CR2_MMS_Pos)
#define    LL_ATIM_TRGO_CC1IF                                     (0x3U << ATIM_CR2_MMS_Pos)
#define    LL_ATIM_TRGO_OC1REF                                    (0x4U << ATIM_CR2_MMS_Pos)
#define    LL_ATIM_TRGO_OC2REF                                    (0x5U << ATIM_CR2_MMS_Pos)
#define    LL_ATIM_TRGO_OC3REF                                    (0x6U << ATIM_CR2_MMS_Pos)
#define    LL_ATIM_TRGO_OC4REF                                    (0x7U << ATIM_CR2_MMS_Pos)

#define    LL_ATIM_CCDMAREQUEST_CC                                (0x0U << ATIM_CR2_CCDS_Pos)
#define    LL_ATIM_CCDMAREQUEST_UPDATE                            (0x1U << ATIM_CR2_CCDS_Pos)

#define    LL_ATIM_ETR_POLARITY_NONINVERTED                       (0x0U << ATIM_SMCR_ETP_Pos)
#define    LL_ATIM_ETR_POLARITY_NINVERTED                         (0x1U << ATIM_SMCR_ETP_Pos)

#define    LL_ATIM_ETR_PRESCALER_DIV1                             (0x0U << ATIM_SMCR_ETPS_Pos)
#define    LL_ATIM_ETR_PRESCALER_DIV2                             (0x1U << ATIM_SMCR_ETPS_Pos)
#define    LL_ATIM_ETR_PRESCALER_DIV4                             (0x2U << ATIM_SMCR_ETPS_Pos)
#define    LL_ATIM_ETR_PRESCALER_DIV8                             (0x3U << ATIM_SMCR_ETPS_Pos)

#define    LL_ATIM_ETR_FILTER_FDIV1                               (0x0U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV1_N2                            (0x1U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV1_N4                            (0x2U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV1_N8                            (0x3U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV2_N6                            (0x4U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV2_N8                            (0x5U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV4_N6                            (0x6U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV4_N8                            (0x7U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV8_N6                            (0x8U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV8_N8                            (0x9U << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV16_N5                           (0xaU << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV16_N6                           (0xbU << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV16_N8                           (0xcU << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV32_N5                           (0xdU << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV32_N6                           (0xeU << ATIM_SMCR_ETF_Pos)
#define    LL_ATIM_ETR_FILTER_FDIV32_N8                           (0xfU << ATIM_SMCR_ETF_Pos)

#define    LL_ATIM_TIM_TS_ITR0                                    (0x0U << ATIM_SMCR_TS_Pos)
#define    LL_ATIM_TIM_TS_ITR1                                    (0x1U << ATIM_SMCR_TS_Pos)
#define    LL_ATIM_TIM_TS_ITR2                                    (0x2U << ATIM_SMCR_TS_Pos)
#define    LL_ATIM_TIM_TS_ITR3                                    (0x3U << ATIM_SMCR_TS_Pos)
#define    LL_ATIM_TIM_TS_TI1F_ED                                 (0x4U << ATIM_SMCR_TS_Pos)
#define    LL_ATIM_TIM_TS_TI1FP1                                  (0x5U << ATIM_SMCR_TS_Pos)
#define    LL_ATIM_TIM_TS_TI2FP1                                  (0x6U << ATIM_SMCR_TS_Pos)
#define    LL_ATIM_TIM_TS_ETRF                                    (0x7U << ATIM_SMCR_TS_Pos)

#define    LL_ATIM_SLAVE_MODE_PROHIBITED                          (0x0U << ATIM_SMCR_SMS_Pos)
#define    LL_ATIM_SLAVE_MODE_TI1FP1_TI2FP2_CNT                   (0x1U << ATIM_SMCR_SMS_Pos)
#define    LL_ATIM_SLAVE_MODE_TI2FP2_TI1FP1_CNT                   (0x2U << ATIM_SMCR_SMS_Pos)
#define    LL_ATIM_SLAVE_MODE_TI2FP2_CNT_TI1FP1_CNT               (0x3U << ATIM_SMCR_SMS_Pos)
#define    LL_ATIM_SLAVE_MODE_TRGI_RISE_RST                       (0x4U << ATIM_SMCR_SMS_Pos)
#define    LL_ATIM_SLAVE_MODE_TRGI_HIGH_RUN                       (0x5U << ATIM_SMCR_SMS_Pos)
#define    LL_ATIM_SLAVE_MODE_TRGI_RISE_RUN                       (0x6U << ATIM_SMCR_SMS_Pos)
#define    LL_ATIM_SLAVE_MODE_TRGI_CLK                            (0x7U << ATIM_SMCR_SMS_Pos)

#define    LL_ATIM_DMABURST_LENGTH_1TRANSFER                      (0x0U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_2TRANSFERS                     (0x1U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_3TRANSFERS                     (0x2U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_4TRANSFERS                     (0x3U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_5TRANSFERS                     (0x4U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_6TRANSFERS                     (0x5U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_7TRANSFERS                     (0x6U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_8TRANSFERS                     (0x7U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_9TRANSFERS                     (0x8U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_10TRANSFERS                    (0x9U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_11TRANSFERS                    (0xaU << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_12TRANSFERS                    (0xbU << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_13TRANSFERS                    (0xcU << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_14TRANSFERS                    (0xdU << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_15TRANSFERS                    (0xeU << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_16TRANSFERS                    (0xfU << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_17TRANSFERS                    (0x10U << ATIM_DCR_DBL_Pos)
#define    LL_ATIM_DMABURST_LENGTH_18TRANSFERS                    (0x11U << ATIM_DCR_DBL_Pos)

#define    LL_ATIM_DMABURST_BASEADDR_CR1                          (0x0U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_CR2                          (0x1U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_SMCR                         (0x2U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_DIER                         (0x3U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_SR                           (0x4U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_EGR                          (0x5U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_CCMR1                        (0x6U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_CCMR2                        (0x7U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_CCER                         (0x8U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_CNT                          (0x9U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_PSC                          (0xaU << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_ARR                          (0xbU << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_RCR                          (0xcU << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_CCR1                         (0xdU << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_CCR2                         (0xeU << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_CCR3                         (0xfU << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_CCR4                         (0x10U << ATIM_DCR_DBA_Pos)
#define    LL_ATIM_DMABURST_BASEADDR_BDTR                         (0x11U << ATIM_DCR_DBA_Pos)

#define    LL_ATIM_OC_MODE_FROZEN                                 (0x0U << ATIM_CCMR_OCM_Pos)
#define    LL_ATIM_OC_MODE_ACTIVE                                 (0x1U << ATIM_CCMR_OCM_Pos)
#define    LL_ATIM_OC_MODE_INACTIVE                               (0x2U << ATIM_CCMR_OCM_Pos)
#define    LL_ATIM_OC_MODE_TOGGLE                                 (0x3U << ATIM_CCMR_OCM_Pos)
#define    LL_ATIM_OC_MODE_FORCED_INACTIVE                        (0x4U << ATIM_CCMR_OCM_Pos)
#define    LL_ATIM_OC_MODE_FORCED_ACTIVE                          (0x5U << ATIM_CCMR_OCM_Pos)
#define    LL_ATIM_OC_MODE_PWM1                                   (0x6U << ATIM_CCMR_OCM_Pos)
#define    LL_ATIM_OC_MODE_PWM2                                   (0x7U << ATIM_CCMR_OCM_Pos)

#define    LL_ATIM_IC_FILTER_FDIV1                                (0x0U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV1_N2                             (0x1U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV1_N4                             (0x2U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV1_N8                             (0x3U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV2_N6                             (0x4U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV2_N8                             (0x5U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV4_N6                             (0x6U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV4_N8                             (0x7U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV8_N6                             (0x8U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV8_N8                             (0x9U << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV16_N5                            (0xaU << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV16_N6                            (0xbU << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV16_N8                            (0xcU << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV32_N5                            (0xdU << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV32_N6                            (0xeU << ATIM_CCMR_ICF_Pos)
#define    LL_ATIM_IC_FILTER_FDIV32_N8                            (0xfU << ATIM_CCMR_ICF_Pos)

#define    LL_ATIM_IC_PRESCALER_DIV_1                             (0x0U << ATIM_CCMR_ICPSC_Pos)
#define    LL_ATIM_IC_PRESCALER_DIV_2                             (0x1U << ATIM_CCMR_ICPSC_Pos)
#define    LL_ATIM_IC_PRESCALER_DIV_4                             (0x2U << ATIM_CCMR_ICPSC_Pos)
#define    LL_ATIM_IC_PRESCALER_DIV_8                             (0x3U << ATIM_CCMR_ICPSC_Pos)

#define    LL_ATIM_CC_MODE_OUTPUT                                 (0x0U << ATIM_CCMR_CCS_Pos)
#define    LL_ATIM_CC1_MODE_INPUT_TI1                             (0x1U << ATIM_CCMR_CCS_Pos)
#define    LL_ATIM_CC1_MODE_INPUT_TI2                             (0x2U << ATIM_CCMR_CCS_Pos)
#define    LL_ATIM_CC2_MODE_INPUT_TI2                             (0x1U << ATIM_CCMR_CCS_Pos)
#define    LL_ATIM_CC2_MODE_INPUT_TI1                             (0x2U << ATIM_CCMR_CCS_Pos)
#define    LL_ATIM_CC3_MODE_INPUT_TI3                             (0x1U << ATIM_CCMR_CCS_Pos)
#define    LL_ATIM_CC3_MODE_INPUT_TI4                             (0x2U << ATIM_CCMR_CCS_Pos)
#define    LL_ATIM_CC4_MODE_INPUT_TI4                             (0x1U << ATIM_CCMR_CCS_Pos)
#define    LL_ATIM_CC4_MODE_INPUT_TI3                             (0x2U << ATIM_CCMR_CCS_Pos)
#define    LL_ATIM_CC_MODE_INPUT_TRC                              (0x3U << ATIM_CCMR_CCS_Pos)

#define    LL_ATIM_OCN_POLARITY_HIGH                              (0x0U << ATIM_CCER_CCNP_Pos)
#define    LL_ATIM_OCN_POLARITY_LOW                               (0x1U << ATIM_CCER_CCNP_Pos)

#define    LL_ATIM_OC_POLARITY_HIGH                               (0x0U << ATIM_CCER_CCOP_Pos)
#define    LL_ATIM_OC_POLARITY_LOW                                (0x1U << ATIM_CCER_CCOP_Pos)

#define    LL_ATIM_IC_POLARITY_RISING                             (0x0U << ATIM_CCER_CCIP_Pos)
#define    LL_ATIM_IC_POLARITY_FALLING                            (0x1U << ATIM_CCER_CCIP_Pos)

#define    LL_ATIM_BREAK_POLARITY_LOW                             (0x0U << ATIM_BDTR_BKP_Pos)
#define    LL_ATIM_BREAK_POLARITY_HIGH                            (0x1U << ATIM_BDTR_BKP_Pos)

#define    LL_ATIM_OSSR_DISABLE                                   (0x0U << ATIM_BDTR_OSSR_Pos)
#define    LL_ATIM_OSSR_ENABLE                                    (0x1U << ATIM_BDTR_OSSR_Pos)

#define    LL_ATIM_OSSI_DISABLE                                   (0x0U << ATIM_BDTR_OSSI_Pos)
#define    LL_ATIM_OSSI_ENABLE                                    (0x1U << ATIM_BDTR_OSSI_Pos)

#define    LL_ATIM_LOCKLEVEL_OFF                                  (0x0U << ATIM_BDTR_LOCK_Pos)
#define    LL_ATIM_LOCKLEVEL_1                                    (0x1U << ATIM_BDTR_LOCK_Pos)
#define    LL_ATIM_LOCKLEVEL_2                                    (0x2U << ATIM_BDTR_LOCK_Pos)
#define    LL_ATIM_LOCKLEVEL_3                                    (0x3U << ATIM_BDTR_LOCK_Pos)

#define    LL_ATIM_BREAK1_GATE_LOW                                (0x0U << ATIM_BKCR_BRK1GATE_Pos)
#define    LL_ATIM_BREAK1_GATE_AUTO                               (0x1U << ATIM_BKCR_BRK1GATE_Pos)

#define    LL_ATIM_BREAK2_GATE_LOW                                (0x0U << ATIM_BKCR_BRK2GATE_Pos)
#define    LL_ATIM_BREAK2_GATE_AUTO                               (0x1U << ATIM_BKCR_BRK2GATE_Pos)

#define    LL_ATIM_BRK_FILTER_FDIV1                               (0x0U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV1_N2                            (0x1U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV1_N4                            (0x2U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV1_N8                            (0x3U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV2_N6                            (0x4U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV2_N8                            (0x5U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV4_N6                            (0x6U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV4_N8                            (0x7U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV8_N6                            (0x8U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV8_N8                            (0x9U << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV16_N5                           (0xaU << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV16_N6                           (0xbU << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV16_N8                           (0xcU << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV32_N5                           (0xdU << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV32_N6                           (0xeU << ATIM_BKCR_BRKF_Pos)
#define    LL_ATIM_BRK_FILTER_FDIV32_N8                           (0xfU << ATIM_BKCR_BRKF_Pos)

#define    LL_ATIM_BRK_COMBINATION_OR                             (0x0U << ATIM_BKCR_BRKCOMB_Pos)
#define    LL_ATIM_BRK_COMBINATION_XR                             (0x1U << ATIM_BKCR_BRKCOMB_Pos)
/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup ATIM_LL_Exported_Functions ATIM Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CR1    CKD    LL_ATIM_SetClockDivision
  * @param    TIMx TIM instance
  * @param    ClockDivision This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CLOCKDIVISION_DIV1
  *           @arg @ref LL_ATIM_CLOCKDIVISION_DIV2
  *           @arg @ref LL_ATIM_CLOCKDIVISION_DIV4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetClockDivision(ATIM_Type* TIMx, uint32_t ClockDivision)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_CKD_Msk, ClockDivision);
}

/**
  * @brief    
  * @rmtoll   CR1    CKD    LL_ATIM_GetClockDivision
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_CLOCKDIVISION_DIV1
  *           @arg @ref LL_ATIM_CLOCKDIVISION_DIV2
  *           @arg @ref LL_ATIM_CLOCKDIVISION_DIV4
  */
__STATIC_INLINE uint32_t LL_ATIM_GetClockDivision(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_CKD_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    ARPE    LL_ATIM_EnableARRPreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableARRPreload(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->CR1, ATIM_CR1_ARPE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    ARPE    LL_ATIM_IsEnabledARRPreload
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledARRPreload(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_ARPE_Msk) == ATIM_CR1_ARPE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    ARPE    LL_ATIM_DisableARRPreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableARRPreload(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->CR1, ATIM_CR1_ARPE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    CMS    LL_ATIM_SetCounterAlignedMode
  * @param    TIMx TIM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_COUNTER_ALIGNED_EDGE
  *           @arg @ref LL_ATIM_COUNTER_ALIGNED_CENTER_DOWN
  *           @arg @ref LL_ATIM_COUNTER_ALIGNED_CENTER_UP
  *           @arg @ref LL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetCounterAlignedMode(ATIM_Type* TIMx, uint32_t mode)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_CMS_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR1    CMS    LL_ATIM_GetCounterAlignedMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_COUNTER_ALIGNED_EDGE
  *           @arg @ref LL_ATIM_COUNTER_ALIGNED_CENTER_DOWN
  *           @arg @ref LL_ATIM_COUNTER_ALIGNED_CENTER_UP
  *           @arg @ref LL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN
  */
__STATIC_INLINE uint32_t LL_ATIM_GetCounterAlignedMode(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_CMS_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    DIR    LL_ATIM_SetCounterDirection
  * @param    TIMx TIM instance
  * @param    direct This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_COUNTER_DIRECT_UP
  *           @arg @ref LL_ATIM_COUNTER_DIRECT_DOWN
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetCounterDirection(ATIM_Type* TIMx, uint32_t direct)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_DIR_Msk, direct);
}

/**
  * @brief    
  * @rmtoll   CR1    DIR    LL_ATIM_GetCounterDirection
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_COUNTER_DIRECT_UP
  *           @arg @ref LL_ATIM_COUNTER_DIRECT_DOWN
  */
__STATIC_INLINE uint32_t LL_ATIM_GetCounterDirection(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_DIR_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    OPM    LL_ATIM_SetOnePulseMode
  * @param    TIMx TIM instance
  * @param    OnePulseMode This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_ONEPULSEMODE_REPETITIVE
  *           @arg @ref LL_ATIM_ONEPULSEMODE_SINGLE
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetOnePulseMode(ATIM_Type* TIMx, uint32_t OnePulseMode)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_OPM_Msk, OnePulseMode);
}

/**
  * @brief    
  * @rmtoll   CR1    OPM    LL_ATIM_GetOnePulseMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_ONEPULSEMODE_REPETITIVE
  *           @arg @ref LL_ATIM_ONEPULSEMODE_SINGLE
  */
__STATIC_INLINE uint32_t LL_ATIM_GetOnePulseMode(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_OPM_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    URS    LL_ATIM_SetUpdateSource
  * @param    TIMx TIM instance
  * @param    UpdateSource This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_UPDATESOURCE_REGULAR
  *           @arg @ref LL_ATIM_UPDATESOURCE_COUNTER
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetUpdateSource(ATIM_Type* TIMx, uint32_t UpdateSource)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_URS_Msk, UpdateSource);
}

/**
  * @brief    
  * @rmtoll   CR1    URS    LL_ATIM_GetUpdateSource
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_UPDATESOURCE_REGULAR
  *           @arg @ref LL_ATIM_UPDATESOURCE_COUNTER
  */
__STATIC_INLINE uint32_t LL_ATIM_GetUpdateSource(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_URS_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    UDIS    LL_ATIM_EnableUpdateEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableUpdateEvent(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->CR1, ATIM_CR1_UDIS_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    UDIS    LL_ATIM_IsEnabledUpdateEvent
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledUpdateEvent(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_UDIS_Msk) == ATIM_CR1_UDIS_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    UDIS    LL_ATIM_DisableUpdateEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableUpdateEvent(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->CR1, ATIM_CR1_UDIS_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    CEN    LL_ATIM_EnableCounter
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableCounter(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->CR1, ATIM_CR1_CEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    CEN    LL_ATIM_IsEnabledCounter
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledCounter(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_CEN_Msk) == ATIM_CR1_CEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    CEN    LL_ATIM_DisableCounter
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableCounter(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->CR1, ATIM_CR1_CEN_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    OISN    LL_ATIM_Set_OCN_SetIdleState
  * @param    TIMx TIM instance
  * @param    OCNIdleState This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_OCN_IDLESTATE_LOW
  *           @arg @ref LL_ATIM_OCN_IDLESTATE_HIGH
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Set_OCN_SetIdleState(ATIM_Type* TIMx, uint32_t OCNIdleState, uint32_t Channel)
{
    MODIFY_REG(TIMx->CR2, ATIM_CR2_OISN_Msk<<Channel, OCNIdleState); 
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    OISN    LL_ATIM_Get_OCN_SetIdleState
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_OCN_IDLESTATE_LOW
  *           @arg @ref LL_ATIM_OCN_IDLESTATE_HIGH
  */
__STATIC_INLINE uint32_t LL_ATIM_Get_OCN_SetIdleState(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, (ATIM_CR2_OISN_Msk << Channel))); 
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    OIS    LL_ATIM_Set_OC_SetIdleState
  * @param    TIMx TIM instance
  * @param    OCIdleState This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_OC_IDLESTATE_LOW
  *           @arg @ref LL_ATIM_OC_IDLESTATE_HIGH
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Set_OC_SetIdleState(ATIM_Type* TIMx, uint32_t OCIdleState, uint32_t Channel)
{
    MODIFY_REG(TIMx->CR2, (ATIM_CR2_OIS_Msk<<Channel), OCIdleState); 
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    OIS    LL_ATIM_Get_OC_SetIdleState
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_OC_IDLESTATE_LOW
  *           @arg @ref LL_ATIM_OC_IDLESTATE_HIGH
  */
__STATIC_INLINE uint32_t LL_ATIM_Get_OC_SetIdleState(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, (ATIM_CR2_OIS_Msk<<Channel))); 
}

/**
  * @brief    
  * @rmtoll   CR2    MMS    LL_ATIM_SetTriggerOutput
  * @param    TIMx TIM instance
  * @param    TimerSynchronization This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_TRGO_RESET
  *           @arg @ref LL_ATIM_TRGO_ENABLE
  *           @arg @ref LL_ATIM_TRGO_UPDATE
  *           @arg @ref LL_ATIM_TRGO_CC1IF
  *           @arg @ref LL_ATIM_TRGO_OC1REF
  *           @arg @ref LL_ATIM_TRGO_OC2REF
  *           @arg @ref LL_ATIM_TRGO_OC3REF
  *           @arg @ref LL_ATIM_TRGO_OC4REF
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetTriggerOutput(ATIM_Type* TIMx, uint32_t TimerSynchronization)
{
    MODIFY_REG(TIMx->CR2, ATIM_CR2_MMS_Msk, TimerSynchronization);
}

/**
  * @brief    
  * @rmtoll   CR2    MMS    LL_ATIM_GetTriggerOutput
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_TRGO_RESET
  *           @arg @ref LL_ATIM_TRGO_ENABLE
  *           @arg @ref LL_ATIM_TRGO_UPDATE
  *           @arg @ref LL_ATIM_TRGO_CC1IF
  *           @arg @ref LL_ATIM_TRGO_OC1REF
  *           @arg @ref LL_ATIM_TRGO_OC2REF
  *           @arg @ref LL_ATIM_TRGO_OC3REF
  *           @arg @ref LL_ATIM_TRGO_OC4REF
  */
__STATIC_INLINE uint32_t LL_ATIM_GetTriggerOutput(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, ATIM_CR2_MMS_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    CCDS    LL_ATIM_SetDMAReqTrigger
  * @param    TIMx TIM instance
  * @param    DMAReqTrigger This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CCDMAREQUEST_CC
  *           @arg @ref LL_ATIM_CCDMAREQUEST_UPDATE
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetDMAReqTrigger(ATIM_Type* TIMx, uint32_t DMAReqTrigger)
{
    MODIFY_REG(TIMx->CR2, ATIM_CR2_CCDS_Msk, DMAReqTrigger);
}

/**
  * @brief    
  * @rmtoll   CR2    CCDS    LL_ATIM_GetDMAReqTrigger
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_CCDMAREQUEST_CC
  *           @arg @ref LL_ATIM_CCDMAREQUEST_UPDATE
  */
__STATIC_INLINE uint32_t LL_ATIM_GetDMAReqTrigger(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, ATIM_CR2_CCDS_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    ETP    LL_ATIM_SetETRPolarity
  * @param    TIMx TIM instance
  * @param    Polarity This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_ETR_POLARITY_NONINVERTED
  *           @arg @ref LL_ATIM_ETR_POLARITY_NINVERTED
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetETRPolarity(ATIM_Type* TIMx, uint32_t Polarity)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_ETP_Msk, Polarity);
}

/**
  * @brief    
  * @rmtoll   SMCR    ETP    LL_ATIM_GetETRPolarity
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_ETR_POLARITY_NONINVERTED
  *           @arg @ref LL_ATIM_ETR_POLARITY_NINVERTED
  */
__STATIC_INLINE uint32_t LL_ATIM_GetETRPolarity(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_ETP_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    ECE    LL_ATIM_EnableExternalClock
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableExternalClock(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->SMCR, ATIM_SMCR_ECE_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    ECE    LL_ATIM_IsEnabledExternalClock
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledExternalClock(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_ECE_Msk) == ATIM_SMCR_ECE_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    ECE    LL_ATIM_DisableExternalClock
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableExternalClock(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->SMCR, ATIM_SMCR_ECE_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    ETPS    LL_ATIM_SetETRExtrenalTriggerPsc
  * @param    TIMx TIM instance
  * @param    Psc This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_ETR_PRESCALER_DIV1
  *           @arg @ref LL_ATIM_ETR_PRESCALER_DIV2
  *           @arg @ref LL_ATIM_ETR_PRESCALER_DIV4
  *           @arg @ref LL_ATIM_ETR_PRESCALER_DIV8
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetETRExtrenalTriggerPsc(ATIM_Type* TIMx, uint32_t Psc)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_ETPS_Msk, Psc);
}

/**
  * @brief    
  * @rmtoll   SMCR    ETPS    LL_ATIM_GetETRExtrenalTriggerPsc
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_ETR_PRESCALER_DIV1
  *           @arg @ref LL_ATIM_ETR_PRESCALER_DIV2
  *           @arg @ref LL_ATIM_ETR_PRESCALER_DIV4
  *           @arg @ref LL_ATIM_ETR_PRESCALER_DIV8
  */
__STATIC_INLINE uint32_t LL_ATIM_GetETRExtrenalTriggerPsc(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_ETPS_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    ETF    LL_ATIM_SetETRExtrenalTriggerFilter
  * @param    TIMx TIM instance
  * @param    Filter This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV1
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV1_N2
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV1_N4
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV1_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV2_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV2_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV4_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV4_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV8_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV8_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV16_N5
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV16_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV16_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV32_N5
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV32_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV32_N8
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetETRExtrenalTriggerFilter(ATIM_Type* TIMx, uint32_t Filter)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_ETF_Msk, Filter);
}

/**
  * @brief    
  * @rmtoll   SMCR    ETF    LL_ATIM_GetETRExtrenalTriggerFilter
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV1
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV1_N2
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV1_N4
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV1_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV2_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV2_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV4_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV4_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV8_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV8_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV16_N5
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV16_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV16_N8
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV32_N5
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV32_N6
  *           @arg @ref LL_ATIM_ETR_FILTER_FDIV32_N8
  */
__STATIC_INLINE uint32_t LL_ATIM_GetETRExtrenalTriggerFilter(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_ETF_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    MSM    LL_ATIM_EnableMasterSlaveMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableMasterSlaveMode(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->SMCR, ATIM_SMCR_MSM_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    MSM    LL_ATIM_IsEnabledMasterSlaveMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledMasterSlaveMode(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_MSM_Msk) == ATIM_SMCR_MSM_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    MSM    LL_ATIM_DisableMasterSlaveMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableMasterSlaveMode(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->SMCR, ATIM_SMCR_MSM_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    TS    LL_ATIM_SetTriggerInput
  * @param    TIMx TIM instance
  * @param    TriggerInput This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_TIM_TS_ITR0
  *           @arg @ref LL_ATIM_TIM_TS_ITR1
  *           @arg @ref LL_ATIM_TIM_TS_ITR2
  *           @arg @ref LL_ATIM_TIM_TS_ITR3
  *           @arg @ref LL_ATIM_TIM_TS_TI1F_ED
  *           @arg @ref LL_ATIM_TIM_TS_TI1FP1
  *           @arg @ref LL_ATIM_TIM_TS_TI2FP1
  *           @arg @ref LL_ATIM_TIM_TS_ETRF
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetTriggerInput(ATIM_Type* TIMx, uint32_t TriggerInput)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_TS_Msk, TriggerInput);
}

/**
  * @brief    
  * @rmtoll   SMCR    TS    LL_ATIM_GetTriggerInput
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_TIM_TS_ITR0
  *           @arg @ref LL_ATIM_TIM_TS_ITR1
  *           @arg @ref LL_ATIM_TIM_TS_ITR2
  *           @arg @ref LL_ATIM_TIM_TS_ITR3
  *           @arg @ref LL_ATIM_TIM_TS_TI1F_ED
  *           @arg @ref LL_ATIM_TIM_TS_TI1FP1
  *           @arg @ref LL_ATIM_TIM_TS_TI2FP1
  *           @arg @ref LL_ATIM_TIM_TS_ETRF
  */
__STATIC_INLINE uint32_t LL_ATIM_GetTriggerInput(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_TS_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    SMS    LL_ATIM_SetSlaveMode
  * @param    TIMx TIM instance
  * @param    EncoderMode This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_SLAVE_MODE_PROHIBITED
  *           @arg @ref LL_ATIM_SLAVE_MODE_TI1FP1_TI2FP2_CNT
  *           @arg @ref LL_ATIM_SLAVE_MODE_TI2FP2_TI1FP1_CNT
  *           @arg @ref LL_ATIM_SLAVE_MODE_TI2FP2_CNT_TI1FP1_CNT
  *           @arg @ref LL_ATIM_SLAVE_MODE_TRGI_RISE_RST
  *           @arg @ref LL_ATIM_SLAVE_MODE_TRGI_HIGH_RUN
  *           @arg @ref LL_ATIM_SLAVE_MODE_TRGI_RISE_RUN
  *           @arg @ref LL_ATIM_SLAVE_MODE_TRGI_CLK
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetSlaveMode(ATIM_Type* TIMx, uint32_t EncoderMode)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_SMS_Msk, EncoderMode);
}

/**
  * @brief    
  * @rmtoll   SMCR    SMS    LL_ATIM_GetSlaveMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_SLAVE_MODE_PROHIBITED
  *           @arg @ref LL_ATIM_SLAVE_MODE_TI1FP1_TI2FP2_CNT
  *           @arg @ref LL_ATIM_SLAVE_MODE_TI2FP2_TI1FP1_CNT
  *           @arg @ref LL_ATIM_SLAVE_MODE_TI2FP2_CNT_TI1FP1_CNT
  *           @arg @ref LL_ATIM_SLAVE_MODE_TRGI_RISE_RST
  *           @arg @ref LL_ATIM_SLAVE_MODE_TRGI_HIGH_RUN
  *           @arg @ref LL_ATIM_SLAVE_MODE_TRGI_RISE_RUN
  *           @arg @ref LL_ATIM_SLAVE_MODE_TRGI_CLK
  */
__STATIC_INLINE uint32_t LL_ATIM_GetSlaveMode(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_SMS_Msk));
}

/**
  * @brief    
  * @rmtoll   DIER    CC1BURSTEN    LL_ATIM_EnableCC1BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableCC1BurstMode(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CC1BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC1BURSTEN    LL_ATIM_IsEnabledCC1BurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledCC1BurstMode(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_CC1BURSTEN_Msk) == ATIM_DIER_CC1BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC1BURSTEN    LL_ATIM_DisableCC1BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableCC1BurstMode(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CC1BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC2BURSTEN    LL_ATIM_EnableCC2BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableCC2BurstMode(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CC2BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC2BURSTEN    LL_ATIM_IsEnabledCC2BurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledCC2BurstMode(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_CC2BURSTEN_Msk) == ATIM_DIER_CC2BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC2BURSTEN    LL_ATIM_DisableCC2BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableCC2BurstMode(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CC2BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC3BURSTEN    LL_ATIM_EnableCC3BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableCC3BurstMode(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CC3BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC3BURSTEN    LL_ATIM_IsEnabledCC3BurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledCC3BurstMode(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_CC3BURSTEN_Msk) == ATIM_DIER_CC3BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC3BURSTEN    LL_ATIM_DisableCC3BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableCC3BurstMode(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CC3BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC4BURSTEN    LL_ATIM_EnableCC4BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableCC4BurstMode(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CC4BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC4BURSTEN    LL_ATIM_IsEnabledCC4BurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledCC4BurstMode(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_CC4BURSTEN_Msk) == ATIM_DIER_CC4BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC4BURSTEN    LL_ATIM_DisableCC4BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableCC4BurstMode(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CC4BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TDE    LL_ATIM_EnableDMAReq_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableDMAReq_TRIG(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_TDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TDE    LL_ATIM_IsEnabledDMAReq_TRIG
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledDMAReq_TRIG(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_TDE_Msk) == ATIM_DIER_TDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TDE    LL_ATIM_DisableDMAReq_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableDMAReq_TRIG(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_TDE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMDE    LL_ATIM_EnableDMAReq_ComEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableDMAReq_ComEvent(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_COMDE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMDE    LL_ATIM_IsEnabledDMAReq_ComEvent
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledDMAReq_ComEvent(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_COMDE_Msk) == ATIM_DIER_COMDE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMDE    LL_ATIM_DisableDMAReq_ComEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableDMAReq_ComEvent(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_COMDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CCDE    LL_ATIM_EnableDMAReq
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableDMAReq(ATIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CCDE_Msk << Channel ); 
}

/**
  * @brief    
  * @rmtoll   DIER    CCDE    LL_ATIM_IsEnabledDMAReq
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledDMAReq(ATIM_Type* TIMx, uint32_t Channel)
{
     return (uint32_t)(READ_BIT(TIMx->DIER, (ATIM_DIER_CCDE_Msk << Channel)) == (ATIM_DIER_CCDE_Msk << Channel));
}

/**
  * @brief    
  * @rmtoll   DIER    CCDE    LL_ATIM_DisableDMAReq
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableDMAReq(ATIM_Type* TIMx, uint32_t Channel)
{
     CLEAR_BIT(TIMx->DIER, ATIM_DIER_CCDE_Msk << Channel);  
}

/**
  * @brief    
  * @rmtoll   DIER    UDE    LL_ATIM_EnableDMAReq_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableDMAReq_UPDATE(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_UDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    UDE    LL_ATIM_IsEnabledDMAReq_UPDATE
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledDMAReq_UPDATE(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_UDE_Msk) == ATIM_DIER_UDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    UDE    LL_ATIM_DisableDMAReq_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableDMAReq_UPDATE(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_UDE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    BIE    LL_ATIM_EnableIT_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableIT_BRK(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_BIE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    BIE    LL_ATIM_IsEnabledIT_BRK
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledIT_BRK(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_BIE_Msk) == ATIM_DIER_BIE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    BIE    LL_ATIM_DisableIT_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableIT_BRK(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_BIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TIE    LL_ATIM_EnableIT_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableIT_TRIG(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_TIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TIE    LL_ATIM_IsEnabledIT_TRIG
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledIT_TRIG(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_TIE_Msk) == ATIM_DIER_TIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TIE    LL_ATIM_DisableIT_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableIT_TRIG(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_TIE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMIE    LL_ATIM_EnableIT_COM
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableIT_COM(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_COMIE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMIE    LL_ATIM_IsEnabledIT_COM
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledIT_COM(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_COMIE_Msk) == ATIM_DIER_COMIE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMIE    LL_ATIM_DisableIT_COM
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableIT_COM(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_COMIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CCIE    LL_ATIM_EnableIT_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableIT_CC(ATIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CCIE_Msk << Channel ); 
}

/**
  * @brief    
  * @rmtoll   DIER    CCIE    LL_ATIM_IsEnabledIT_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledIT_CC(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->DIER,(ATIM_DIER_CCIE_Msk << Channel )) == (ATIM_DIER_CCIE_Msk << Channel));  
}

/**
  * @brief    
  * @rmtoll   DIER    CCIE    LL_ATIM_DisableIT_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableIT_CC(ATIM_Type* TIMx, uint32_t Channel)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CCIE_Msk << Channel ); 
}

/**
  * @brief    
  * @rmtoll   DIER    UIE    LL_ATIM_EnableIT_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableIT_UPDATE(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_UIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    UIE    LL_ATIM_IsEnabledIT_UPDATE
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledIT_UPDATE(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_UIE_Msk) == ATIM_DIER_UIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    UIE    LL_ATIM_DisableIT_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableIT_UPDATE(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_UIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    CCOF    LL_ATIM_IsActiveFlag_CCOVR
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsActiveFlag_CCOVR(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, (ATIM_ISR_CCOF_Msk << Channel)) == (ATIM_ISR_CCOF_Msk << Channel)); 
}

/**
  * @brief    
  * @rmtoll   ISR    CCOF    LL_ATIM_ClearFlag_CCOVR
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_ClearFlag_CCOVR(ATIM_Type* TIMx, uint32_t Channel)
{
    WRITE_REG(TIMx->ISR, (ATIM_ISR_CCOF_Msk << Channel));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    BIF    LL_ATIM_IsActiveFlag_BRK
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsActiveFlag_BRK(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_BIF_Msk) == (ATIM_ISR_BIF_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    BIF    LL_ATIM_ClearFlag_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_ClearFlag_BRK(ATIM_Type* TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_BIF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    TIF    LL_ATIM_IsActiveFlag_TRIG
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsActiveFlag_TRIG(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_TIF_Msk) == (ATIM_ISR_TIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    TIF    LL_ATIM_ClearFlag_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_ClearFlag_TRIG(ATIM_Type* TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_TIF_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    COMIF    LL_ATIM_IsActiveFlag_COM
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsActiveFlag_COM(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_COMIF_Msk) == (ATIM_ISR_COMIF_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    COMIF    LL_ATIM_ClearFlag_COM
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_ClearFlag_COM(ATIM_Type* TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_COMIF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    CCIF    LL_ATIM_IsActiveFlag_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsActiveFlag_CC(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, (ATIM_ISR_CCIF_Msk << Channel)) == (ATIM_ISR_CCIF_Msk << Channel));  
}

/**
  * @brief    
  * @rmtoll   ISR    CCIF    LL_ATIM_ClearFlag_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_ClearFlag_CC(ATIM_Type* TIMx, uint32_t Channel)
{
    WRITE_REG(TIMx->ISR, (ATIM_ISR_CCIF_Msk << Channel)); 
}

/**
  * @brief    
  * @rmtoll   ISR    UIF    LL_ATIM_IsActiveFlag_UPDATE
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsActiveFlag_UPDATE(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_UIF_Msk) == (ATIM_ISR_UIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    UIF    LL_ATIM_ClearFlag_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_ClearFlag_UPDATE(ATIM_Type* TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_UIF_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   EGR    BG    LL_ATIM_GenerateEvent_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_GenerateEvent_BRK(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_BG_Msk);
}

/**
  * @brief    
  * @rmtoll   EGR    TG    LL_ATIM_GenerateEvent_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_GenerateEvent_TRIG(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_TG_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   EGR    COMG    LL_ATIM_GenerateEvent_COM
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_GenerateEvent_COM(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_COMG_Msk);
}

/**
  * @brief    
  * @rmtoll   EGR    CCG    LL_ATIM_GenerateEvent
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_GenerateEvent(ATIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->EGR,ATIM_EGR_CCG_Msk << Channel ); 
}

/**
  * @brief    
  * @rmtoll   EGR    UG    LL_ATIM_GenerateEvent_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_GenerateEvent_UPDATE(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_UG_Msk);
}

/**
  * @brief    
  * @rmtoll   CNT        LL_ATIM_SetCounter
  * @param    TIMx TIM instance
  * @param    counter 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetCounter(ATIM_Type* TIMx, uint32_t counter)
{
    MODIFY_REG(TIMx->CNT, (0xffffU << 0U), (counter << 0U));
}

/**
  * @brief    
  * @rmtoll   CNT        LL_ATIM_GetCounter
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetCounter(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CNT, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   PSC        LL_ATIM_SetPrescaler
  * @param    TIMx TIM instance
  * @param    Prescaler 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetPrescaler(ATIM_Type* TIMx, uint32_t Prescaler)
{
    MODIFY_REG(TIMx->PSC, (0xffffU << 0U), (Prescaler << 0U));
}

/**
  * @brief    
  * @rmtoll   PSC        LL_ATIM_GetPrescaler
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetPrescaler(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->PSC, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   ARR        LL_ATIM_SetAutoReload
  * @param    TIMx TIM instance
  * @param    AutoReload 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetAutoReload(ATIM_Type* TIMx, uint32_t AutoReload)
{
    MODIFY_REG(TIMx->ARR, (0xffffU << 0U), (AutoReload << 0U));
}

/**
  * @brief    
  * @rmtoll   ARR        LL_ATIM_GetAutoReload
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetAutoReload(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ARR, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCR1        LL_ATIM_SetCompareCH1
  * @param    TIMx TIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetCompareCH1(ATIM_Type* TIMx, uint32_t CompareValue)
{
    MODIFY_REG(TIMx->CCR1, (0xffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    
  * @rmtoll   CCR1        LL_ATIM_GetCompareCH1
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetCompareCH1(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR1, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCR2        LL_ATIM_SetCompareCH2
  * @param    TIMx TIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetCompareCH2(ATIM_Type* TIMx, uint32_t CompareValue)
{
    MODIFY_REG(TIMx->CCR2, (0xffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    
  * @rmtoll   CCR2        LL_ATIM_GetCompareCH2
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetCompareCH2(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR2, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCR3        LL_ATIM_SetCompareCH3
  * @param    TIMx TIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetCompareCH3(ATIM_Type* TIMx, uint32_t CompareValue)
{
    MODIFY_REG(TIMx->CCR3, (0xffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    
  * @rmtoll   CCR3        LL_ATIM_GetCompareCH3
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetCompareCH3(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR3, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCR4        LL_ATIM_SetCompareCH4
  * @param    TIMx TIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetCompareCH4(ATIM_Type* TIMx, uint32_t CompareValue)
{
    MODIFY_REG(TIMx->CCR4, (0xffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    
  * @rmtoll   CCR4        LL_ATIM_GetCompareCH4
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetCompareCH4(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR4, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   DCR    DBL    LL_ATIM_SetConfigDMABurstLenth
  * @param    TIMx TIM instance
  * @param    lenth This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_1TRANSFER
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_2TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_3TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_4TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_5TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_6TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_7TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_8TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_9TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_10TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_11TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_12TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_13TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_14TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_15TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_16TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_17TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_18TRANSFERS
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetConfigDMABurstLenth(ATIM_Type* TIMx, uint32_t lenth)
{
    MODIFY_REG(TIMx->DCR, ATIM_DCR_DBL_Msk, lenth);
}

/**
  * @brief    
  * @rmtoll   DCR    DBL    LL_ATIM_GetConfigDMABurstLenth
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_1TRANSFER
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_2TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_3TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_4TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_5TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_6TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_7TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_8TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_9TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_10TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_11TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_12TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_13TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_14TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_15TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_16TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_17TRANSFERS
  *           @arg @ref LL_ATIM_DMABURST_LENGTH_18TRANSFERS
  */
__STATIC_INLINE uint32_t LL_ATIM_GetConfigDMABurstLenth(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DCR, ATIM_DCR_DBL_Msk));
}

/**
  * @brief    
  * @rmtoll   DCR    DBA    LL_ATIM_SetConfigDMABurstAddress
  * @param    TIMx TIM instance
  * @param    address This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CR1
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CR2
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_SMCR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_DIER
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_SR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_EGR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCMR1
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCMR2
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCER
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CNT
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_PSC
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_ARR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_RCR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCR1
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCR2
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCR3
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCR4
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_BDTR
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetConfigDMABurstAddress(ATIM_Type* TIMx, uint32_t address)
{
    MODIFY_REG(TIMx->DCR, ATIM_DCR_DBA_Msk, address);
}

/**
  * @brief    
  * @rmtoll   DCR    DBA    LL_ATIM_GetConfigDMABurstAddress
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CR1
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CR2
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_SMCR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_DIER
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_SR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_EGR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCMR1
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCMR2
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCER
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CNT
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_PSC
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_ARR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_RCR
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCR1
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCR2
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCR3
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_CCR4
  *           @arg @ref LL_ATIM_DMABURST_BASEADDR_BDTR
  */
__STATIC_INLINE uint32_t LL_ATIM_GetConfigDMABurstAddress(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DCR, ATIM_DCR_DBA_Msk));
}

/**
  * @brief    
  * @rmtoll   DMAR        LL_ATIM_SetConfigDMAR
  * @param    TIMx TIM instance
  * @param    Addr 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetConfigDMAR(ATIM_Type* TIMx, uint32_t Addr)
{
    MODIFY_REG(TIMx->DMAR, (0xffffU << 0U), (Addr << 0U));
}

/**
  * @brief    
  * @rmtoll   DMAR        LL_ATIM_GetConfigDMAR
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetConfigDMAR(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DMAR, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCMR    OCCE    LL_ATIM_Enable_Clear
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Enable_Clear(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        SET_BIT(TIMx->CCMR1,(ATIM_CCMR_OCCE_Msk << (Channel*8)));
    }
    else
    {
        SET_BIT(TIMx->CCMR2,(ATIM_CCMR_OCCE_Msk << ((Channel-2)*8)));
    }      
}

/**
  * @brief    
  * @rmtoll   CCMR    OCCE    LL_ATIM_IsEnabled_Clear
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabled_Clear(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1,(ATIM_CCMR_OCCE_Msk << (Channel*8))) == (ATIM_CCMR_OCCE_Msk << (Channel*8)));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2,(ATIM_CCMR_OCCE_Msk << ((Channel-2)*8))) == (ATIM_CCMR_OCCE_Msk << ((Channel-2)*8)));
    }    
}

/**
  * @brief    
  * @rmtoll   CCMR    OCCE    LL_ATIM_Disable_Clear
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Disable_Clear(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        CLEAR_BIT(TIMx->CCMR1,(ATIM_CCMR_OCCE_Msk << (Channel*8)));
    }
    else
    {
        CLEAR_BIT(TIMx->CCMR2,(ATIM_CCMR_OCCE_Msk << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCM    LL_ATIM_SetOCMode
  * @param    TIMx TIM instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_OC_MODE_FROZEN
  *           @arg @ref LL_ATIM_OC_MODE_ACTIVE
  *           @arg @ref LL_ATIM_OC_MODE_INACTIVE
  *           @arg @ref LL_ATIM_OC_MODE_TOGGLE
  *           @arg @ref LL_ATIM_OC_MODE_FORCED_INACTIVE
  *           @arg @ref LL_ATIM_OC_MODE_FORCED_ACTIVE
  *           @arg @ref LL_ATIM_OC_MODE_PWM1
  *           @arg @ref LL_ATIM_OC_MODE_PWM2
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetOCMode(ATIM_Type* TIMx, uint32_t Mode, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1,(ATIM_CCMR_OCM_Msk << (Channel*8)),(Mode << (Channel*8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2,(ATIM_CCMR_OCM_Msk << ((Channel-2)*8)),(Mode << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCM    LL_ATIM_GetOCMode
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_OC_MODE_FROZEN
  *           @arg @ref LL_ATIM_OC_MODE_ACTIVE
  *           @arg @ref LL_ATIM_OC_MODE_INACTIVE
  *           @arg @ref LL_ATIM_OC_MODE_TOGGLE
  *           @arg @ref LL_ATIM_OC_MODE_FORCED_INACTIVE
  *           @arg @ref LL_ATIM_OC_MODE_FORCED_ACTIVE
  *           @arg @ref LL_ATIM_OC_MODE_PWM1
  *           @arg @ref LL_ATIM_OC_MODE_PWM2
  */
__STATIC_INLINE uint32_t LL_ATIM_GetOCMode(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_OCM_Msk << (Channel*8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_OCM_Msk << ((Channel-2)*8))));
    } 
}

/**
  * @brief    
  * @rmtoll   CCMR    OCPE    LL_ATIM_Enable_Preload
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Enable_Preload(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        SET_BIT(TIMx->CCMR1,(ATIM_CCMR_OCPE_Msk << (Channel*8)));
    }
    else
    {
        SET_BIT(TIMx->CCMR2,(ATIM_CCMR_OCPE_Msk << ((Channel-2)*8)));
    }   
}

/**
  * @brief    
  * @rmtoll   CCMR    OCPE    LL_ATIM_IsEnabled_Preload
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabled_Preload(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1,(ATIM_CCMR_OCPE_Msk << (Channel*8))) == (ATIM_CCMR_OCPE_Msk << (Channel*8)));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2,(ATIM_CCMR_OCPE_Msk << ((Channel-2)*8))) == (ATIM_CCMR_OCPE_Msk << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCPE    LL_ATIM_Disable_Preload
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Disable_Preload(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        CLEAR_BIT(TIMx->CCMR1,(ATIM_CCMR_OCPE_Msk << (Channel*8)));
    }
    else
    {
        CLEAR_BIT(TIMx->CCMR2,(ATIM_CCMR_OCPE_Msk << ((Channel-2)*8)));
    } 
}

/**
  * @brief    
  * @rmtoll   CCMR    OCFE    LL_ATIM_Enable_FastCompare
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Enable_FastCompare(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        SET_BIT(TIMx->CCMR1,(ATIM_CCMR_OCFE_Msk << (Channel*8)));
    }
    else
    {
        SET_BIT(TIMx->CCMR2,(ATIM_CCMR_OCFE_Msk << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCFE    LL_ATIM_IsEnabled_FastCompare
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabled_FastCompare(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1,(ATIM_CCMR_OCFE_Msk << (Channel*8))) == (ATIM_CCMR_OCFE_Msk << (Channel*8)));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2,(ATIM_CCMR_OCFE_Msk << ((Channel-2)*8))) == (ATIM_CCMR_OCFE_Msk << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCFE    LL_ATIM_Disable_FastCompare
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Disable_FastCompare(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        CLEAR_BIT(TIMx->CCMR1,(ATIM_CCMR_OCFE_Msk << (Channel*8)));
    }
    else
    {
        CLEAR_BIT(TIMx->CCMR2,(ATIM_CCMR_OCFE_Msk << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    ICF    LL_ATIM_SetICModeFilter
  * @param    TIMx TIM instance
  * @param    filter This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV1
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV1_N2
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV1_N4
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV1_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV2_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV2_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV4_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV4_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV8_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV8_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV16_N5
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV16_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV16_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV32_N5
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV32_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV32_N8
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetICModeFilter(ATIM_Type* TIMx, uint32_t filter, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1,(ATIM_CCMR_ICF_Msk << (Channel*8)),(filter << (Channel*8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2,(ATIM_CCMR_ICF_Msk << ((Channel-2)*8)),(filter << ((Channel-2)*8)));
    } 
}

/**
  * @brief    
  * @rmtoll   CCMR    ICF    LL_ATIM_GetICModeFilter
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV1
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV1_N2
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV1_N4
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV1_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV2_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV2_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV4_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV4_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV8_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV8_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV16_N5
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV16_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV16_N8
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV32_N5
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV32_N6
  *           @arg @ref LL_ATIM_IC_FILTER_FDIV32_N8
  */
__STATIC_INLINE uint32_t LL_ATIM_GetICModeFilter(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_ICF_Msk << (Channel*8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_ICF_Msk << ((Channel-2)*8))));
    } 
}

/**
  * @brief    
  * @rmtoll   CCMR    ICPSC    LL_ATIM_SetICModePrescaler
  * @param    TIMx TIM instance
  * @param    Psc This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_IC_PRESCALER_DIV_1
  *           @arg @ref LL_ATIM_IC_PRESCALER_DIV_2
  *           @arg @ref LL_ATIM_IC_PRESCALER_DIV_4
  *           @arg @ref LL_ATIM_IC_PRESCALER_DIV_8
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetICModePrescaler(ATIM_Type* TIMx, uint32_t Psc, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1,(ATIM_CCMR_ICPSC_Msk << (Channel*8)),(Psc << (Channel*8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2,(ATIM_CCMR_ICPSC_Msk << ((Channel-2)*8)),(Psc << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    ICPSC    LL_ATIM_GetICModePrescaler
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_IC_PRESCALER_DIV_1
  *           @arg @ref LL_ATIM_IC_PRESCALER_DIV_2
  *           @arg @ref LL_ATIM_IC_PRESCALER_DIV_4
  *           @arg @ref LL_ATIM_IC_PRESCALER_DIV_8
  */
__STATIC_INLINE uint32_t LL_ATIM_GetICModePrescaler(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_ICPSC_Msk << (Channel*8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_ICPSC_Msk << ((Channel-2)*8))));
    }   
}

/**
  * @brief    
  * @rmtoll   CCMR    CCS    LL_ATIM_SetChannelMode
  * @param    TIMx TIM instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CC_MODE_OUTPUT
  *           @arg @ref LL_ATIM_CC1_MODE_INPUT_TI1
  *           @arg @ref LL_ATIM_CC1_MODE_INPUT_TI2
  *           @arg @ref LL_ATIM_CC2_MODE_INPUT_TI2
  *           @arg @ref LL_ATIM_CC2_MODE_INPUT_TI1
  *           @arg @ref LL_ATIM_CC3_MODE_INPUT_TI3
  *           @arg @ref LL_ATIM_CC3_MODE_INPUT_TI4
  *           @arg @ref LL_ATIM_CC4_MODE_INPUT_TI3
  *           @arg @ref LL_ATIM_CC4_MODE_INPUT_TI4
  *           @arg @ref LL_ATIM_CC_MODE_INPUT_TRC
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetChannelMode(ATIM_Type* TIMx, uint32_t Mode, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1,(ATIM_CCMR_CCS_Msk << (Channel*8)),(Mode << (Channel*8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2,(ATIM_CCMR_CCS_Msk << ((Channel-2)*8)),(Mode << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    CCS    LL_ATIM_GetChannelMode
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_CC_MODE_OUTPUT
  *           @arg @ref LL_ATIM_CC1_MODE_INPUT_TI1
  *           @arg @ref LL_ATIM_CC1_MODE_INPUT_TI2
  *           @arg @ref LL_ATIM_CC2_MODE_INPUT_TI2
  *           @arg @ref LL_ATIM_CC2_MODE_INPUT_TI1
  *           @arg @ref LL_ATIM_CC3_MODE_INPUT_TI3
  *           @arg @ref LL_ATIM_CC3_MODE_INPUT_TI4
  *           @arg @ref LL_ATIM_CC4_MODE_INPUT_TI3
  *           @arg @ref LL_ATIM_CC4_MODE_INPUT_TI4
  *           @arg @ref LL_ATIM_CC_MODE_INPUT_TRC
  */
__STATIC_INLINE uint32_t LL_ATIM_GetChannelMode(ATIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_CCS_Msk << (Channel*8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_CCS_Msk << ((Channel-2)*8))));
    }   
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNP    LL_ATIM_SetOCPolartyReverseChannel
  * @param    TIMx TIM instance
  * @param    Polarty This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_OCN_POLARITY_HIGH
  *           @arg @ref LL_ATIM_OCN_POLARITY_LOW
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetOCPolartyReverseChannel(ATIM_Type* TIMx, uint32_t Polarty, uint32_t Channel)
{
    MODIFY_REG(TIMx->CCER,(ATIM_CCER_CCNP_Msk << (Channel*4)),(Polarty << (Channel*4)));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNP    LL_ATIM_GetOCPolartyReverseChannel
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_OCN_POLARITY_HIGH
  *           @arg @ref LL_ATIM_OCN_POLARITY_LOW
  */
__STATIC_INLINE uint32_t LL_ATIM_GetOCPolartReverseChannel(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (ATIM_CCER_CCNP_Msk << (Channel*4)))); 
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNE    LL_ATIM_EnableReverseChannelOutPut
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableReverseChannelOutPut(ATIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->CCER,(ATIM_CCER_CCNE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNE    LL_ATIM_IsEnabledReverseChannelOutPut
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledReverseChannelOutPut(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER,(ATIM_CCER_CCNE_Msk << (Channel*4))) == (ATIM_CCER_CCNE_Msk << (Channel*4)));  
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNE    LL_ATIM_DisableReverseChannelOutPut
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableReverseChannelOutPut(ATIM_Type* TIMx, uint32_t Channel)
{
    CLEAR_BIT(TIMx->CCER,(ATIM_CCER_CCNE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOP    LL_ATIM_SetOCPolartyNormalChannel
  * @param    TIMx TIM instance
  * @param    Polarty This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_OC_POLARITY_HIGH
  *           @arg @ref LL_ATIM_OC_POLARITY_LOW
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetOCPolartyNormalChannel(ATIM_Type* TIMx, uint32_t Polarty, uint32_t Channel)
{
    MODIFY_REG(TIMx->CCER,(ATIM_CCER_CCOP_Msk << (Channel*4)),(Polarty << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOP    LL_ATIM_GetOCPolartyNormalChannel
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_OC_POLARITY_HIGH
  *           @arg @ref LL_ATIM_OC_POLARITY_LOW
  */
__STATIC_INLINE uint32_t LL_ATIM_GetOCPolartyNormalChannel(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (ATIM_CCER_CCOP_Msk << (Channel*4)))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCIP    LL_ATIM_SetICPolartyChannel
  * @param    TIMx TIM instance
  * @param    Polarty This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_IC_POLARITY_RISING
  *           @arg @ref LL_ATIM_IC_POLARITY_FALLING
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetICPolartyChannel(ATIM_Type* TIMx, uint32_t Polarty, uint32_t Channel)
{
    MODIFY_REG(TIMx->CCER,(ATIM_CCER_CCIP_Msk << (Channel*4)),(Polarty << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCIP    LL_ATIM_GetICPolartyChannel
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_IC_POLARITY_RISING
  *           @arg @ref LL_ATIM_IC_POLARITY_FALLING
  */
__STATIC_INLINE uint32_t LL_ATIM_GetICPolartyChannel(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (ATIM_CCER_CCIP_Msk << (Channel*4)))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOE    LL_ATIM_EnableNormalChannelOutput
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableNormalChannelOutput(ATIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->CCER,(ATIM_CCER_CCE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOE    LL_ATIM_IsEnabledNormalChannelOutput
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledNormalChannelOutput(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER,(ATIM_CCER_CCE_Msk << (Channel*4))) == (ATIM_CCER_CCE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCIE    LL_ATIM_DisableNormalChannelOutput
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableNormalChannelOutput(ATIM_Type* TIMx, uint32_t Channel)
{
    CLEAR_BIT(TIMx->CCER,(ATIM_CCER_CCE_Msk << (Channel*4))); 
}
/**
  * @brief    
  * @rmtoll   CCER    CCIE    LL_ATIM_EnableChannelCapture
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_EnableChannelCapture(ATIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->CCER,(ATIM_CCER_CCE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCIE    LL_ATIM_IsEnabledChannelCapture
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabledChannelCapture(ATIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER,(ATIM_CCER_CCE_Msk << (Channel*4))) == (ATIM_CCER_CCE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCIE    LL_ATIM_DisableChannelCapture
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_CHANNEL_1
  *           @arg @ref LL_ATIM_CHANNEL_2
  *           @arg @ref LL_ATIM_CHANNEL_3
  *           @arg @ref LL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_DisableChannelCapture(ATIM_Type* TIMx, uint32_t Channel)
{
    CLEAR_BIT(TIMx->CCER,(ATIM_CCER_CCE_Msk << (Channel*4)));  
}
/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   RCR        LL_ATIM_SetConfigRepeatCnt
  * @param    TIMx TIM instance
  * @param    RepeatCnt 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetConfigRepeatCnt(ATIM_Type* TIMx, uint32_t RepeatCnt)
{
    MODIFY_REG(TIMx->RCR, (0xffU << 0U), (RepeatCnt << 0U));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   RCR        LL_ATIM_GetConfigRepetCnt
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetConfigRepetCnt(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->RCR, 0xffU) >> 0U);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    MOE    LL_ATIM_Enable_AllOutputs
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Enable_AllOutputs(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->BDTR, ATIM_BDTR_MOE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    MOE    LL_ATIM_IsEnabled_AllOutputs
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabled_AllOutputs(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_MOE_Msk) == ATIM_BDTR_MOE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    MOE    LL_ATIM_Disable_AllOutputs
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Disable_AllOutputs(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->BDTR, ATIM_BDTR_MOE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    AOE    LL_ATIM_Enable_AutomaticOutput
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Enable_AutomaticOutput(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->BDTR, ATIM_BDTR_AOE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    AOE    LL_ATIM_IsEnabled_AutomaticOutput
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabled_AutomaticOutput(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_AOE_Msk) == ATIM_BDTR_AOE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    AOE    LL_ATIM_Disable_AutomaticOutput
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Disable_AutomaticOutput(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->BDTR, ATIM_BDTR_AOE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKP    LL_ATIM_SetBreakPolarity
  * @param    TIMx TIM instance
  * @param    Polarity This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_BREAK_POLARITY_LOW
  *           @arg @ref LL_ATIM_BREAK_POLARITY_HIGH
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetBreakPolarity(ATIM_Type* TIMx, uint32_t Polarity)
{
    MODIFY_REG(TIMx->BDTR, ATIM_BDTR_BKP_Msk, Polarity);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKP    LL_ATIM_GetBreakPolarity
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_BREAK_POLARITY_LOW
  *           @arg @ref LL_ATIM_BREAK_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t LL_ATIM_GetBreakPolarity(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_BKP_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKE    LL_ATIM_Enable_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Enable_BRK(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->BDTR, ATIM_BDTR_BKE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKE    LL_ATIM_IsEnabled_BRK
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabled_BRK(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_BKE_Msk) == ATIM_BDTR_BKE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKE    LL_ATIM_Disable_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Disable_BRK(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->BDTR, ATIM_BDTR_BKE_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    OSSR    LL_ATIM_SetOffStates_Run
  * @param    TIMx TIM instance
  * @param    States This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_OSSR_DISABLE
  *           @arg @ref LL_ATIM_OSSR_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetOffStates_Run(ATIM_Type* TIMx, uint32_t States)
{
    MODIFY_REG(TIMx->BDTR, ATIM_BDTR_OSSR_Msk, States);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    OSSR    LL_ATIM_GetOffStates_Run
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_OSSR_DISABLE
  *           @arg @ref LL_ATIM_OSSR_ENABLE
  */
__STATIC_INLINE uint32_t LL_ATIM_GetOffStates_Run(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_OSSR_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    OSSI    LL_ATIM_SetOffStates_Idel
  * @param    TIMx TIM instance
  * @param    States This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_OSSI_DISABLE
  *           @arg @ref LL_ATIM_OSSI_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetOffStates_Idel(ATIM_Type* TIMx, uint32_t States)
{
    MODIFY_REG(TIMx->BDTR, ATIM_BDTR_OSSI_Msk, States);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    OSSI    LL_ATIM_GetOffStates_Idel
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_OSSI_DISABLE
  *           @arg @ref LL_ATIM_OSSI_ENABLE
  */
__STATIC_INLINE uint32_t LL_ATIM_GetOffStates_Idel(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_OSSI_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    LOCK    LL_ATIM_SetLockLevel
  * @param    TIMx TIM instance
  * @param    Locklevel This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_LOCKLEVEL_OFF
  *           @arg @ref LL_ATIM_LOCKLEVEL_1
  *           @arg @ref LL_ATIM_LOCKLEVEL_2
  *           @arg @ref LL_ATIM_LOCKLEVEL_3
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetLockLevel(ATIM_Type* TIMx, uint32_t Locklevel)
{
    MODIFY_REG(TIMx->BDTR, ATIM_BDTR_LOCK_Msk, Locklevel);
}
/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    LOCK    LL_ATIM_GetLockLevel
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_LOCKLEVEL_OFF
  *           @arg @ref LL_ATIM_LOCKLEVEL_1
  *           @arg @ref LL_ATIM_LOCKLEVEL_2
  *           @arg @ref LL_ATIM_LOCKLEVEL_3
  */
__STATIC_INLINE uint32_t LL_ATIM_GetLockLevel(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_LOCK_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    DTG    LL_ATIM_SetDeadTimeGeneration
  * @param    TIMx TIM instance
  * @param    DeadTimeGenerat 
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetDeadTimeGeneration(ATIM_Type* TIMx, uint32_t DeadTimeGenerat)
{
    MODIFY_REG(TIMx->BDTR, (0xffU << 0U), (DeadTimeGenerat << 0U));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    DTG    LL_ATIM_GetDeadTimeGeneration
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_ATIM_GetDeadTimeGeneration(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, 0xffU) >> 0U);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    BRK1GATE    LL_ATIM_SetBreak1GateState
  * @param    TIMx TIM instance
  * @param    State This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_BREAK1_GATE_LOW
  *           @arg @ref LL_ATIM_BREAK1_GATE_AUTO
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetBreak1GateState(ATIM_Type* TIMx, uint32_t State)
{
    MODIFY_REG(TIMx->BKCR, ATIM_BKCR_BRK1GATE_Msk, State);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    BRK1GATE    LL_ATIM_GetBreak1GateState
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_BREAK1_GATE_LOW
  *           @arg @ref LL_ATIM_BREAK1_GATE_AUTO
  */
__STATIC_INLINE uint32_t LL_ATIM_GetBreak1GateState(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BKCR, ATIM_BKCR_BRK1GATE_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    BRK2GATE    LL_ATIM_SetBreak2GateState
  * @param    TIMx TIM instance
  * @param    State This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_BREAK2_GATE_LOW
  *           @arg @ref LL_ATIM_BREAK2_GATE_AUTO
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetBreak2GateState(ATIM_Type* TIMx, uint32_t State)
{
    MODIFY_REG(TIMx->BKCR, ATIM_BKCR_BRK2GATE_Msk, State);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    BRK2GATE    LL_ATIM_GetBreak2GateState
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_BREAK2_GATE_LOW
  *           @arg @ref LL_ATIM_BREAK2_GATE_AUTO
  */
__STATIC_INLINE uint32_t LL_ATIM_GetBreak2GateState(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BKCR, ATIM_BKCR_BRK2GATE_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    BRKF    LL_ATIM_SetBreakFilter
  * @param    TIMx TIM instance
  * @param    Filter This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV1
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV1_N2
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV1_N4
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV1_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV2_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV2_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV4_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV4_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV8_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV8_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV16_N5
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV16_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV16_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV32_N5
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV32_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV32_N8
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetBreakFilter(ATIM_Type* TIMx, uint32_t Filter)
{
    MODIFY_REG(TIMx->BKCR, ATIM_BKCR_BRKF_Msk, Filter);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    BRKF    LL_ATIM_GetBreakFilter
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV1
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV1_N2
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV1_N4
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV1_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV2_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV2_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV4_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV4_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV8_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV8_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV16_N5
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV16_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV16_N8
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV32_N5
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV32_N6
  *           @arg @ref LL_ATIM_BRK_FILTER_FDIV32_N8
  */
__STATIC_INLINE uint32_t LL_ATIM_GetBreakFilter(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BKCR, ATIM_BKCR_BRKF_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    BRKCOMB    LL_ATIM_SetBreakSignalCombination
  * @param    TIMx TIM instance
  * @param    Filter This parameter can be one of the following values:
  *           @arg @ref LL_ATIM_BRK_COMBINATION_OR
  *           @arg @ref LL_ATIM_BRK_COMBINATION_XR
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_SetBreakSignalCombination(ATIM_Type* TIMx, uint32_t Filter)
{
    MODIFY_REG(TIMx->BKCR, ATIM_BKCR_BRKCOMB_Msk, Filter);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    BRKCOMB    LL_ATIM_GetBreakSignalCombination
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_ATIM_BRK_COMBINATION_OR
  *           @arg @ref LL_ATIM_BRK_COMBINATION_XR
  */
__STATIC_INLINE uint32_t LL_ATIM_GetBreakSignalCombination(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BKCR, ATIM_BKCR_BRKCOMB_Msk));
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    HFDET_BRKEN    LL_ATIM_Enable_HFDET_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Enable_HFDET_BRK(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->BKCR, ATIM_BKCR_HFDET_BRKEN_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    HFDET_BRKEN    LL_ATIM_IsEnabled_HFDET_BRK
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabled_HFDET_BRK(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BKCR, ATIM_BKCR_HFDET_BRKEN_Msk) == ATIM_BKCR_HFDET_BRKEN_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    HFDET_BRKEN    LL_ATIM_Disable_HFDET_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Disable_HFDET_BRK(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->BKCR, ATIM_BKCR_HFDET_BRKEN_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    SVD_BRKEN    LL_ATIM_Enable_SVD_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Enable_SVD_BRK(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->BKCR, ATIM_BKCR_SVD_BRKEN_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    SVD_BRKEN    LL_ATIM_IsEnabled_SVD_BRK
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabled_SVD_BRK(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BKCR, ATIM_BKCR_SVD_BRKEN_Msk) == ATIM_BKCR_SVD_BRKEN_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    SVD_BRKEN    LL_ATIM_Disable_SVD_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Disable_SVD_BRK(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->BKCR, ATIM_BKCR_SVD_BRKEN_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    COMP_BRKEN    LL_ATIM_Enable_COMP_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Enable_COMP_BRK(ATIM_Type* TIMx)
{
    SET_BIT(TIMx->BKCR, ATIM_BKCR_COMP_BRKEN_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    COMP_BRKEN    LL_ATIM_IsEnabled_COMP_BRK
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ATIM_IsEnabled_COMP_BRK(ATIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BKCR, ATIM_BKCR_COMP_BRKEN_Msk) == ATIM_BKCR_COMP_BRKEN_Msk);
}

/**
  * @brief    
  * @note     仅仅高级定时器支持
  * @rmtoll   BKCR    COMP_BRKEN    LL_ATIM_Disable_COMP_BRK
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_ATIM_Disable_COMP_BRK(ATIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->BKCR, ATIM_BKCR_COMP_BRKEN_Msk);
}

/**
  * @}
  */

/** @defgroup ATIM_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_ATIM_DeInit(ATIM_Type *TIMx);

void LL_ATIM_StructInit(LL_ATIM_InitTypeDef *TIM_InitStruct);
void LL_ATIM_SlaveModeStructInit(LL_ATIM_SlaveInitTypeDef *TIM_InitStruct);
void LL_ATIM_IC_StructInit(LL_ATIM_IC_InitTypeDef *TIM_ICInitStruct);
void LL_ATIM_OC_StructInit(LL_ATIM_OC_InitTypeDef *TIM_OC_InitStruct);
void LL_ATIM_ETRStructInit(LL_ATIM_ETR_InitTypeDef *TIM_InitStruct);
void LL_ATIM_BDTR_StructInit(LL_ATIM_BDTR_InitTypeDef *TIM_BDTR_InitStruct);
    
ErrorStatus LL_ATIM_Init(ATIM_Type *TIMx, LL_ATIM_InitTypeDef *TIM_InitStruct);
ErrorStatus LL_ATIM_IC_Init(ATIM_Type *TIMx, uint32_t Channel, LL_ATIM_IC_InitTypeDef* IC_InitStruct);
ErrorStatus LL_ATIM_ETR_Init(ATIM_Type *TIMx, LL_ATIM_ETR_InitTypeDef* TIM_InitStruct);
ErrorStatus LL_ATIM_SlaveMode_Init(ATIM_Type *TIMx, LL_ATIM_SlaveInitTypeDef *TIM_InitStruct);
ErrorStatus LL_ATIM_OC_Init(ATIM_Type *TIMx, uint32_t Channel, LL_ATIM_OC_InitTypeDef *TIM_OC_InitStruct);
ErrorStatus LL_ATIM_BDTR_Init(ATIM_Type *TIMx, LL_ATIM_BDTR_InitTypeDef *TIM_BDTR_InitStruct);
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_ATIM_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-24**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
