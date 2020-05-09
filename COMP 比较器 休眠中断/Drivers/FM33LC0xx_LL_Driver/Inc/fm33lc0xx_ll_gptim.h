/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_gptim.h
  * @author  FMSH Application Team
  * @brief   Head file of GPTIM LL Module
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
#ifndef __FM33LC0XX_LL_GPTIM_H
#define __FM33LC0XX_LL_GPTIM_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_GPTIM
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup GPTIM_LL_ES_INIT GPTIM Exported Init structures
  * @{
  */

/**
  * @brief LL GPTIM Init Sturcture definition
  */
/**
  * @brief  TIM Time Base configuration structure definition.
  */
typedef struct
{
    /*! 预分频系数 */  
    uint32_t Prescaler;        
    /*! 计数模式 */
    uint32_t CounterMode;      
    /*! 自动重装载值 */
    uint32_t Autoreload;
    /*! 预装载使能 */   
    uint32_t AutoreloadState;     
    /*!定时器分频系数与数字滤波器所使用的采样时钟分频比*/
    uint32_t ClockDivision;     
                                                         
} LL_GPTIM_InitTypeDef;
/**
  * @brief GTIM SlaveMode Init Sturcture definition
  */
typedef struct
{ 
    /*! TRx 源*/
    uint32_t ITRxSrc;
    /*! 外部时钟源模式 */
    uint32_t SlaveMode;           
    /*! 输入触发信号选择 */
    uint32_t TriggerSrc; 
    /*! Trigger 延迟*/
    uint32_t TriggerDelay; 
                                                         
} LL_GPTIM_SlaveInitTypeDef;
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
                       
} LL_GPTIM_IC_InitTypeDef;
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
                       
} LL_GPTIM_ETR_InitTypeDef;

/**
  * @brief  TIM Output Compare configuration structure definition.
  */
typedef struct
{
    /*! 比较输出模式 */   
    uint32_t OCMode;  
    /*! 比较输出通道快速模式使能 */
    uint32_t OCFastMode;       
    /*! 输出比较预装载 */
    uint32_t OCPreload;        
    /*! 通道比较值 */
    uint32_t CompareValue; 
    /*! 比较输出极性 */
    uint32_t OCPolarity;   
    /*! ETR清0使能 */
    uint32_t OCETRFStatus; 
                        
} LL_GPTIM_OC_InitTypeDef;


/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup GPTIM_LL_Exported_Constants GPTIM Exported Constants
  * @{
  */
#define    LL_GPTIM_CHANNEL_1                                     (0x0U << 0U)
#define    LL_GPTIM_CHANNEL_2                                     (0x1U << 0U)
#define    LL_GPTIM_CHANNEL_3                                     (0x2U << 0U)
#define    LL_GPTIM_CHANNEL_4                                     (0x3U << 0U)

#define    LL_GPTIM_CLOCKDIVISION_DIV1                            (0x0U << GPTIM_CR1_CKD_Pos)
#define    LL_GPTIM_CLOCKDIVISION_DIV2                            (0x1U << GPTIM_CR1_CKD_Pos)
#define    LL_GPTIM_CLOCKDIVISION_DIV4                            (0x2U << GPTIM_CR1_CKD_Pos)

#define    LL_GPTIM_COUNTER_ALIGNED_EDGE                          (0x0U << GPTIM_CR1_CMS_Pos)
#define    LL_GPTIM_COUNTER_ALIGNED_CENTER_DOWN                   (0x1U << GPTIM_CR1_CMS_Pos)
#define    LL_GPTIM_COUNTER_ALIGNED_CENTER_UP                     (0x2U << GPTIM_CR1_CMS_Pos)
#define    LL_GPTIM_COUNTER_ALIGNED_CENTER_UP_DOWN                (0x3U << GPTIM_CR1_CMS_Pos)

#define    LL_GPTIM_COUNTER_DIRECT_UP                             (0x0U << GPTIM_CR1_DIR_Pos)
#define    LL_GPTIM_COUNTER_DIRECT_DOWN                           (0x1U << GPTIM_CR1_DIR_Pos)

#define    LL_GPTIM_ONEPULSEMODE_REPETITIVE                       (0x0U << GPTIM_CR1_OPM_Pos)
#define    LL_GPTIM_ONEPULSEMODE_SINGLE                           (0x1U << GPTIM_CR1_OPM_Pos)

#define    LL_GPTIM_UPDATESOURCE_REGULAR                          (0x0U << GPTIM_CR1_URS_Pos)
#define    LL_GPTIM_UPDATESOURCE_COUNTER                          (0x1U << GPTIM_CR1_URS_Pos)

#define    LL_GPTIM_TRGO_RESET                                    (0x0U << GPTIM_CR2_MMS_Pos)
#define    LL_GPTIM_TRGO_ENABLE                                   (0x1U << GPTIM_CR2_MMS_Pos)
#define    LL_GPTIM_TRGO_UPDATE                                   (0x2U << GPTIM_CR2_MMS_Pos)
#define    LL_GPTIM_TRGO_CC1IF                                    (0x3U << GPTIM_CR2_MMS_Pos)
#define    LL_GPTIM_TRGO_OC1REF                                   (0x4U << GPTIM_CR2_MMS_Pos)
#define    LL_GPTIM_TRGO_OC2REF                                   (0x5U << GPTIM_CR2_MMS_Pos)
#define    LL_GPTIM_TRGO_OC3REF                                   (0x6U << GPTIM_CR2_MMS_Pos)
#define    LL_GPTIM_TRGO_OC4REF                                   (0x7U << GPTIM_CR2_MMS_Pos)

#define    LL_GPTIM_CCDMAREQUEST_CC                               (0x0U << GPTIM_CR2_CCDS_Pos)
#define    LL_GPTIM_CCDMAREQUEST_UPDATE                           (0x1U << GPTIM_CR2_CCDS_Pos)

#define    LL_GPTIM_ETR_POLARITY_NONINVERTED                      (0x0U << GPTIM_SMCR_ETP_Pos)
#define    LL_GPTIM_ETR_POLARITY_NINVERTED                        (0x1U << GPTIM_SMCR_ETP_Pos)

#define    LL_GPTIM_ETR_PRESCALER_DIV1                            (0x0U << GPTIM_SMCR_ETPS_Pos)
#define    LL_GPTIM_ETR_PRESCALER_DIV2                            (0x1U << GPTIM_SMCR_ETPS_Pos)
#define    LL_GPTIM_ETR_PRESCALER_DIV4                            (0x2U << GPTIM_SMCR_ETPS_Pos)
#define    LL_GPTIM_ETR_PRESCALER_DIV8                            (0x3U << GPTIM_SMCR_ETPS_Pos)

#define    LL_GPTIM_ETR_FILTER_FDIV1                              (0x0U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV1_N2                           (0x1U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV1_N4                           (0x2U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV1_N8                           (0x3U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV2_N6                           (0x4U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV2_N8                           (0x5U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV4_N6                           (0x6U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV4_N8                           (0x7U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV8_N6                           (0x8U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV8_N8                           (0x9U << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV16_N5                          (0xaU << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV16_N6                          (0xbU << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV16_N8                          (0xcU << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV32_N5                          (0xdU << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV32_N6                          (0xeU << GPTIM_SMCR_ETF_Pos)
#define    LL_GPTIM_ETR_FILTER_FDIV32_N8                          (0xfU << GPTIM_SMCR_ETF_Pos)

#define    LL_GPTIM_TIM_TS_ITR0                                   (0x0U << GPTIM_SMCR_TS_Pos)
#define    LL_GPTIM_TIM_TS_ITR1                                   (0x1U << GPTIM_SMCR_TS_Pos)
#define    LL_GPTIM_TIM_TS_ITR2                                   (0x2U << GPTIM_SMCR_TS_Pos)
#define    LL_GPTIM_TIM_TS_ITR3                                   (0x3U << GPTIM_SMCR_TS_Pos)
#define    LL_GPTIM_TIM_TS_TI1F_ED                                (0x4U << GPTIM_SMCR_TS_Pos)
#define    LL_GPTIM_TIM_TS_TI1FP1                                 (0x5U << GPTIM_SMCR_TS_Pos)
#define    LL_GPTIM_TIM_TS_TI2FP1                                 (0x6U << GPTIM_SMCR_TS_Pos)
#define    LL_GPTIM_TIM_TS_ETRF                                   (0x7U << GPTIM_SMCR_TS_Pos)

#define    LL_GPTIM_SLAVE_MODE_PROHIBITED                         (0x0U << GPTIM_SMCR_SMS_Pos)
#define    LL_GPTIM_SLAVE_MODE_TI1FP1_TI2FP2_CNT                  (0x1U << GPTIM_SMCR_SMS_Pos)
#define    LL_GPTIM_SLAVE_MODE_TI2FP2_TI1FP1_CNT                  (0x2U << GPTIM_SMCR_SMS_Pos)
#define    LL_GPTIM_SLAVE_MODE_TI2FP2_CNT_TI1FP1_CNT              (0x3U << GPTIM_SMCR_SMS_Pos)
#define    LL_GPTIM_SLAVE_MODE_TRGI_RISE_RST                      (0x4U << GPTIM_SMCR_SMS_Pos)
#define    LL_GPTIM_SLAVE_MODE_TRGI_HIGH_RUN                      (0x5U << GPTIM_SMCR_SMS_Pos)
#define    LL_GPTIM_SLAVE_MODE_TRGI_RISE_RUN                      (0x6U << GPTIM_SMCR_SMS_Pos)
#define    LL_GPTIM_SLAVE_MODE_TRGI_CLK                           (0x7U << GPTIM_SMCR_SMS_Pos)


#define    LL_GPTIM_DMABURST_LENGTH_1TRANSFER                     (0x0U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_2TRANSFERS                    (0x1U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_3TRANSFERS                    (0x2U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_4TRANSFERS                    (0x3U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_5TRANSFERS                    (0x4U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_6TRANSFERS                    (0x5U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_7TRANSFERS                    (0x6U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_8TRANSFERS                    (0x7U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_9TRANSFERS                    (0x8U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_10TRANSFERS                   (0x9U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_11TRANSFERS                   (0xaU << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_12TRANSFERS                   (0xbU << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_13TRANSFERS                   (0xcU << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_14TRANSFERS                   (0xdU << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_15TRANSFERS                   (0xeU << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_16TRANSFERS                   (0xfU << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_17TRANSFERS                   (0x10U << GPTIM_DCR_DBL_Pos)
#define    LL_GPTIM_DMABURST_LENGTH_18TRANSFERS                   (0x11U << GPTIM_DCR_DBL_Pos)

#define    LL_GPTIM_DMABURST_BASEADDR_CR1                         (0x0U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_CR2                         (0x1U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_SMCR                        (0x2U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_DIER                        (0x3U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_SR                          (0x4U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_EGR                         (0x5U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_CCMR1                       (0x6U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_CCMR2                       (0x7U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_CCER                        (0x8U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_CNT                         (0x9U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_PSC                         (0xaU << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_ARR                         (0xbU << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_RCR                         (0xcU << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_CCR1                        (0xdU << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_CCR2                        (0xeU << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_CCR3                        (0xfU << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_CCR4                        (0x10U << GPTIM_DCR_DBA_Pos)
#define    LL_GPTIM_DMABURST_BASEADDR_BDTR                        (0x11U << GPTIM_DCR_DBA_Pos)

#define    LL_GPTIM_ITR0SEL_ATIM_TRGO                             (0x0U << GPTIM_ITRSEL_ITR0SEL_Pos)
#define    LL_GPTIM_ITR0SEL_UART0_RX                              (0x1U << GPTIM_ITRSEL_ITR0SEL_Pos)
#define    LL_GPTIM_ITR0SEL_UART1_RX                              (0x2U << GPTIM_ITRSEL_ITR0SEL_Pos)
#define    LL_GPTIM_ITR0SEL_UART4_RX                              (0x3U << GPTIM_ITRSEL_ITR0SEL_Pos)

#define    LL_GPTIM_ITR1SEL_GPTIM1_TRGO                           (0x0U << GPTIM_ITRSEL_ITR1SEL_Pos)
#define    LL_GPTIM_ITR1SEL_XTHF                                  (0x1U << GPTIM_ITRSEL_ITR1SEL_Pos)
#define    LL_GPTIM_ITR1SEL_RCHF                                  (0x2U << GPTIM_ITRSEL_ITR1SEL_Pos)
#define    LL_GPTIM_ITR1SEL_LPUART0_RX                            (0x3U << GPTIM_ITRSEL_ITR1SEL_Pos)

#define    LL_GPTIM_ITR2SEL_BSTIM_TRGO                            (0x0U << GPTIM_ITRSEL_ITR2SEL_Pos)
#define    LL_GPTIM_ITR2SEL_LPUART1_TX                            (0x1U << GPTIM_ITRSEL_ITR2SEL_Pos)
#define    LL_GPTIM_ITR2SEL_RCLP                                  (0x2U << GPTIM_ITRSEL_ITR2SEL_Pos)
#define    LL_GPTIM_ITR2SEL_XTLF                                  (0x3U << GPTIM_ITRSEL_ITR2SEL_Pos)

#define    LL_GPTIM_ITR3SEL_COMP1_TRGO                            (0x0U << GPTIM_ITRSEL_ITR3SEL_Pos)
#define    LL_GPTIM_ITR3SEL_RC4M                                  (0x1U << GPTIM_ITRSEL_ITR3SEL_Pos)
#define    LL_GPTIM_ITR3SEL_COMP2_TRGO                            (0x2U << GPTIM_ITRSEL_ITR3SEL_Pos)
#define    LL_GPTIM_ITR3SEL_LPT32_TRGO                            (0x3U << GPTIM_ITRSEL_ITR3SEL_Pos)

#define    LL_GPTIM_ITR1SEL_GPTIM0_TRGO                           (0x0U << GPTIM_ITRSEL_ITR1SEL_Pos)
#define    LL_GPTIM_ITR1SEL_ADC_EOC                               (0x3U << GPTIM_ITRSEL_ITR1SEL_Pos)

#define    LL_GPTIM_ITR2SEL_LSCLK                                 (0x1U << GPTIM_ITRSEL_ITR2SEL_Pos)


#define    LL_GPTIM_OC_MODE_FROZEN                                (0x0U << GPTIM_CCMR_OCM_Pos)
#define    LL_GPTIM_OC_MODE_ACTIVE                                (0x1U << GPTIM_CCMR_OCM_Pos)
#define    LL_GPTIM_OC_MODE_INACTIVE                              (0x2U << GPTIM_CCMR_OCM_Pos)
#define    LL_GPTIM_OC_MODE_TOGGLE                                (0x3U << GPTIM_CCMR_OCM_Pos)
#define    LL_GPTIM_OC_MODE_FORCED_INACTIVE                       (0x4U << GPTIM_CCMR_OCM_Pos)
#define    LL_GPTIM_OC_MODE_FORCED_ACTIVE                         (0x5U << GPTIM_CCMR_OCM_Pos)
#define    LL_GPTIM_OC_MODE_PWM1                                  (0x6U << GPTIM_CCMR_OCM_Pos)
#define    LL_GPTIM_OC_MODE_PWM2                                  (0x7U << GPTIM_CCMR_OCM_Pos)

#define    LL_GPTIM_IC_FILTER_FDIV1                               (0x0U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV1_N2                            (0x1U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV1_N4                            (0x2U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV1_N8                            (0x3U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV2_N6                            (0x4U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV2_N8                            (0x5U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV4_N6                            (0x6U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV4_N8                            (0x7U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV8_N6                            (0x8U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV8_N8                            (0x9U << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV16_N5                           (0xaU << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV16_N6                           (0xbU << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV16_N8                           (0xcU << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV32_N5                           (0xdU << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV32_N6                           (0xeU << GPTIM_CCMR_ICF_Pos)
#define    LL_GPTIM_IC_FILTER_FDIV32_N8                           (0xfU << GPTIM_CCMR_ICF_Pos)

#define    LL_GPTIM_IC_PRESCALER_DIV_1                            (0x0U << GPTIM_CCMR_ICPSC_Pos)
#define    LL_GPTIM_IC_PRESCALER_DIV_2                            (0x1U << GPTIM_CCMR_ICPSC_Pos)
#define    LL_GPTIM_IC_PRESCALER_DIV_4                            (0x2U << GPTIM_CCMR_ICPSC_Pos)
#define    LL_GPTIM_IC_PRESCALER_DIV_8                            (0x3U << GPTIM_CCMR_ICPSC_Pos)

#define    LL_GPTIM_CC_MODE_OUTPUT                                (0x0U << GPTIM_CCMR_CCS_Pos)
#define    LL_GPTIM_CC1_MODE_INPUT_TI1                             (0x1U << GPTIM_CCMR_CCS_Pos)
#define    LL_GPTIM_CC1_MODE_INPUT_TI2                             (0x2U << GPTIM_CCMR_CCS_Pos)
#define    LL_GPTIM_CC2_MODE_INPUT_TI2                             (0x1U << GPTIM_CCMR_CCS_Pos)
#define    LL_GPTIM_CC2_MODE_INPUT_TI1                             (0x2U << GPTIM_CCMR_CCS_Pos)
#define    LL_GPTIM_CC3_MODE_INPUT_TI3                             (0x1U << GPTIM_CCMR_CCS_Pos)
#define    LL_GPTIM_CC3_MODE_INPUT_TI4                             (0x2U << GPTIM_CCMR_CCS_Pos)
#define    LL_GPTIM_CC4_MODE_INPUT_TI4                             (0x1U << GPTIM_CCMR_CCS_Pos)
#define    LL_GPTIM_CC4_MODE_INPUT_TI3                             (0x2U << GPTIM_CCMR_CCS_Pos)
#define    LL_GPTIM_CC_MODE_INPUT_TRC                              (0x3U << GPTIM_CCMR_CCS_Pos)

#define    LL_GPTIM_OC_POLARITY_NOMAL                             (0x0U << GPTIM_CCER_CCOP_Pos)
#define    LL_GPTIM_OC_POLARITY_REVERSE                           (0x1U << GPTIM_CCER_CCOP_Pos)

#define    LL_GPTIM_IC_POLARITY_RISING                            (0x0U << GPTIM_CCER_CCIP_Pos)
#define    LL_GPTIM_IC_POLARITY_FALLING                           (0x1U << GPTIM_CCER_CCIP_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup GPTIM_LL_Exported_Functions GPTIM Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CR1    CKD    LL_GPTIM_SetClockDivision
  * @param    TIMx TIM instance
  * @param    ClockDivision This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CLOCKDIVISION_DIV1
  *           @arg @ref LL_GPTIM_CLOCKDIVISION_DIV2
  *           @arg @ref LL_GPTIM_CLOCKDIVISION_DIV4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetClockDivision(GPTIM_Type* TIMx, uint32_t ClockDivision)
{
    MODIFY_REG(TIMx->CR1, GPTIM_CR1_CKD_Msk, ClockDivision);
}

/**
  * @brief    
  * @rmtoll   CR1    CKD    LL_GPTIM_GetClockDivision
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_CLOCKDIVISION_DIV1
  *           @arg @ref LL_GPTIM_CLOCKDIVISION_DIV2
  *           @arg @ref LL_GPTIM_CLOCKDIVISION_DIV4
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetClockDivision(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, GPTIM_CR1_CKD_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    ARPE    LL_GPTIM_EnableARRPreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableARRPreload(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->CR1, GPTIM_CR1_ARPE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    ARPE    LL_GPTIM_IsEnabledARRPreload
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledARRPreload(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, GPTIM_CR1_ARPE_Msk) == GPTIM_CR1_ARPE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    ARPE    LL_GPTIM_DisableARRPreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableARRPreload(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->CR1, GPTIM_CR1_ARPE_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    CMS    LL_GPTIM_SetCounterAlignedMode
  * @param    TIMx TIM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_COUNTER_ALIGNED_EDGE
  *           @arg @ref LL_GPTIM_COUNTER_ALIGNED_CENTER_DOWN
  *           @arg @ref LL_GPTIM_COUNTER_ALIGNED_CENTER_UP
  *           @arg @ref LL_GPTIM_COUNTER_ALIGNED_CENTER_UP_DOWN
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetCounterAlignedMode(GPTIM_Type* TIMx, uint32_t mode)
{
    MODIFY_REG(TIMx->CR1, GPTIM_CR1_CMS_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR1    CMS    LL_GPTIM_GetCounterAlignedMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_COUNTER_ALIGNED_EDGE
  *           @arg @ref LL_GPTIM_COUNTER_ALIGNED_CENTER_DOWN
  *           @arg @ref LL_GPTIM_COUNTER_ALIGNED_CENTER_UP
  *           @arg @ref LL_GPTIM_COUNTER_ALIGNED_CENTER_UP_DOWN
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetCounterAlignedMode(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, GPTIM_CR1_CMS_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    DIR    LL_GPTIM_SetCounterDirection
  * @param    TIMx TIM instance
  * @param    direct This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_COUNTER_DIRECT_UP
  *           @arg @ref LL_GPTIM_COUNTER_DIRECT_DOWN
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetCounterDirection(GPTIM_Type* TIMx, uint32_t direct)
{
    MODIFY_REG(TIMx->CR1, GPTIM_CR1_DIR_Msk, direct);
}

/**
  * @brief    
  * @rmtoll   CR1    DIR    LL_GPTIM_GetCounterDirection
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_COUNTER_DIRECT_UP
  *           @arg @ref LL_GPTIM_COUNTER_DIRECT_DOWN
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetCounterDirection(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, GPTIM_CR1_DIR_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    OPM    LL_GPTIM_SetOnePulseMode
  * @param    TIMx TIM instance
  * @param    OnePulseMode This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ONEPULSEMODE_REPETITIVE
  *           @arg @ref LL_GPTIM_ONEPULSEMODE_SINGLE
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetOnePulseMode(GPTIM_Type* TIMx, uint32_t OnePulseMode)
{
    MODIFY_REG(TIMx->CR1, GPTIM_CR1_OPM_Msk, OnePulseMode);
}

/**
  * @brief    
  * @rmtoll   CR1    OPM    LL_GPTIM_GetOnePulseMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ONEPULSEMODE_REPETITIVE
  *           @arg @ref LL_GPTIM_ONEPULSEMODE_SINGLE
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetOnePulseMode(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, GPTIM_CR1_OPM_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    URS    LL_GPTIM_SetUpdateSource
  * @param    TIMx TIM instance
  * @param    UpdateSource This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_UPDATESOURCE_REGULAR
  *           @arg @ref LL_GPTIM_UPDATESOURCE_COUNTER
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetUpdateSource(GPTIM_Type* TIMx, uint32_t UpdateSource)
{
    MODIFY_REG(TIMx->CR1, GPTIM_CR1_URS_Msk, UpdateSource);
}

/**
  * @brief    
  * @rmtoll   CR1    URS    LL_GPTIM_GetUpdateSource
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_UPDATESOURCE_REGULAR
  *           @arg @ref LL_GPTIM_UPDATESOURCE_COUNTER
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetUpdateSource(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, GPTIM_CR1_URS_Msk));
}

/**
  * @brief    
  * @rmtoll   CR1    UDIS    LL_GPTIM_EnableUpdateEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableUpdateEvent(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->CR1, GPTIM_CR1_UDIS_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    UDIS    LL_GPTIM_IsEnabledUpdateEvent
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledUpdateEvent(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, GPTIM_CR1_UDIS_Msk) == GPTIM_CR1_UDIS_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    UDIS    LL_GPTIM_DisableUpdateEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableUpdateEvent(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->CR1, GPTIM_CR1_UDIS_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    CEN    LL_GPTIM_EnableCounter
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableCounter(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->CR1, GPTIM_CR1_CEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    CEN    LL_GPTIM_IsEnabledCounter
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledCounter(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, GPTIM_CR1_CEN_Msk) == GPTIM_CR1_CEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR1    CEN    LL_GPTIM_DisableCounter
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableCounter(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->CR1, GPTIM_CR1_CEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR2    MMS    LL_GPTIM_SetTriggerOutput
  * @param    TIMx TIM instance
  * @param    TimerSynchronization This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_TRGO_RESET
  *           @arg @ref LL_GPTIM_TRGO_ENABLE
  *           @arg @ref LL_GPTIM_TRGO_UPDATE
  *           @arg @ref LL_GPTIM_TRGO_CC1IF
  *           @arg @ref LL_GPTIM_TRGO_OC1REF
  *           @arg @ref LL_GPTIM_TRGO_OC2REF
  *           @arg @ref LL_GPTIM_TRGO_OC3REF
  *           @arg @ref LL_GPTIM_TRGO_OC4REF
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetTriggerOutput(GPTIM_Type* TIMx, uint32_t TimerSynchronization)
{
    MODIFY_REG(TIMx->CR2, GPTIM_CR2_MMS_Msk, TimerSynchronization);
}

/**
  * @brief    
  * @rmtoll   CR2    MMS    LL_GPTIM_GetTriggerOutput
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_TRGO_RESET
  *           @arg @ref LL_GPTIM_TRGO_ENABLE
  *           @arg @ref LL_GPTIM_TRGO_UPDATE
  *           @arg @ref LL_GPTIM_TRGO_CC1IF
  *           @arg @ref LL_GPTIM_TRGO_OC1REF
  *           @arg @ref LL_GPTIM_TRGO_OC2REF
  *           @arg @ref LL_GPTIM_TRGO_OC3REF
  *           @arg @ref LL_GPTIM_TRGO_OC4REF
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetTriggerOutput(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, GPTIM_CR2_MMS_Msk));
}

/**
  * @brief    
  * @rmtoll   CR2    CCDS    LL_GPTIM_CC_SetDMAReqTrigger
  * @param    TIMx TIM instance
  * @param    DMAReqTrigger This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CCDMAREQUEST_CC
  *           @arg @ref LL_GPTIM_CCDMAREQUEST_UPDATE
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_CC_SetDMAReqTrigger(GPTIM_Type* TIMx, uint32_t DMAReqTrigger)
{
    MODIFY_REG(TIMx->CR2, GPTIM_CR2_CCDS_Msk, DMAReqTrigger);
}

/**
  * @brief    
  * @rmtoll   CR2    CCDS    LL_GPTIM_CC_GetDMAReqTrigger
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_CCDMAREQUEST_CC
  *           @arg @ref LL_GPTIM_CCDMAREQUEST_UPDATE
  */
__STATIC_INLINE uint32_t LL_GPTIM_CC_GetDMAReqTrigger(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, GPTIM_CR2_CCDS_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    ETP    LL_GPTIM_SetETRPolarity
  * @param    TIMx TIM instance
  * @param    Polarity This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ETR_POLARITY_NONINVERTED
  *           @arg @ref LL_GPTIM_ETR_POLARITY_NINVERTED
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetETRPolarity(GPTIM_Type* TIMx, uint32_t Polarity)
{
    MODIFY_REG(TIMx->SMCR, GPTIM_SMCR_ETP_Msk, Polarity);
}

/**
  * @brief    
  * @rmtoll   SMCR    ETP    LL_GPTIM_GetETRPolarity
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ETR_POLARITY_NONINVERTED
  *           @arg @ref LL_GPTIM_ETR_POLARITY_NINVERTED
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetETRPolarity(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, GPTIM_SMCR_ETP_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    ECE    LL_GPTIM_EnableExternalClock
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableExternalClock(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->SMCR, GPTIM_SMCR_ECE_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    ECE    LL_GPTIM_IsEnabledExternalClock
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledExternalClock(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, GPTIM_SMCR_ECE_Msk) == GPTIM_SMCR_ECE_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    ECE    LL_GPTIM_DisableExternalClock
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableExternalClock(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->SMCR, GPTIM_SMCR_ECE_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    ETPS    LL_GPTIM_SetETRExtrenalTriggerPsc
  * @param    TIMx TIM instance
  * @param    Psc This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ETR_PRESCALER_DIV1
  *           @arg @ref LL_GPTIM_ETR_PRESCALER_DIV2
  *           @arg @ref LL_GPTIM_ETR_PRESCALER_DIV4
  *           @arg @ref LL_GPTIM_ETR_PRESCALER_DIV8
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetETRExtrenalTriggerPsc(GPTIM_Type* TIMx, uint32_t Psc)
{
    MODIFY_REG(TIMx->SMCR, GPTIM_SMCR_ETPS_Msk, Psc);
}

/**
  * @brief    
  * @rmtoll   SMCR    ETPS    LL_GPTIM_GetETRExtrenalTriggerPsc
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ETR_PRESCALER_DIV1
  *           @arg @ref LL_GPTIM_ETR_PRESCALER_DIV2
  *           @arg @ref LL_GPTIM_ETR_PRESCALER_DIV4
  *           @arg @ref LL_GPTIM_ETR_PRESCALER_DIV8
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetETRExtrenalTriggerPsc(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, GPTIM_SMCR_ETPS_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    ETF    LL_GPTIM_SetETRExtrenalTriggerFilter
  * @param    TIMx TIM instance
  * @param    Filter This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV1
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV1_N2
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV1_N4
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV1_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV2_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV2_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV4_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV4_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV8_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV8_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV16_N5
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV16_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV16_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV32_N5
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV32_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV32_N8
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetETRExtrenalTriggerFilter(GPTIM_Type* TIMx, uint32_t Filter)
{
    MODIFY_REG(TIMx->SMCR, GPTIM_SMCR_ETF_Msk, Filter);
}

/**
  * @brief    
  * @rmtoll   SMCR    ETF    LL_GPTIM_GetETRExtrenalTriggerFilter
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV1
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV1_N2
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV1_N4
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV1_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV2_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV2_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV4_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV4_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV8_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV8_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV16_N5
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV16_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV16_N8
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV32_N5
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV32_N6
  *           @arg @ref LL_GPTIM_ETR_FILTER_FDIV32_N8
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetETRExtrenalTriggerFilter(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, GPTIM_SMCR_ETF_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    MSM    LL_GPTIM_EnableMasterSlaveMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableMasterSlaveMode(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->SMCR, GPTIM_SMCR_MSM_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    MSM    LL_GPTIM_IsEnabledMasterSlaveMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledMasterSlaveMode(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, GPTIM_SMCR_MSM_Msk) == GPTIM_SMCR_MSM_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    MSM    LL_GPTIM_DisableMasterSlaveMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableMasterSlaveMode(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->SMCR, GPTIM_SMCR_MSM_Msk);
}

/**
  * @brief    
  * @rmtoll   SMCR    TS    LL_GPTIM_SetTriggerInput
  * @param    TIMx TIM instance
  * @param    TriggerInput This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_TIM_TS_ITR0
  *           @arg @ref LL_GPTIM_TIM_TS_ITR1
  *           @arg @ref LL_GPTIM_TIM_TS_ITR2
  *           @arg @ref LL_GPTIM_TIM_TS_ITR3
  *           @arg @ref LL_GPTIM_TIM_TS_TI1F_ED
  *           @arg @ref LL_GPTIM_TIM_TS_TI1FP1
  *           @arg @ref LL_GPTIM_TIM_TS_TI2FP1
  *           @arg @ref LL_GPTIM_TIM_TS_ETRF
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetTriggerInput(GPTIM_Type* TIMx, uint32_t TriggerInput)
{
    MODIFY_REG(TIMx->SMCR, GPTIM_SMCR_TS_Msk, TriggerInput);
}

/**
  * @brief    
  * @rmtoll   SMCR    TS    LL_GPTIM_GetTriggerInput
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_TIM_TS_ITR0
  *           @arg @ref LL_GPTIM_TIM_TS_ITR1
  *           @arg @ref LL_GPTIM_TIM_TS_ITR2
  *           @arg @ref LL_GPTIM_TIM_TS_ITR3
  *           @arg @ref LL_GPTIM_TIM_TS_TI1F_ED
  *           @arg @ref LL_GPTIM_TIM_TS_TI1FP1
  *           @arg @ref LL_GPTIM_TIM_TS_TI2FP1
  *           @arg @ref LL_GPTIM_TIM_TS_ETRF
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetTriggerInput(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, GPTIM_SMCR_TS_Msk));
}

/**
  * @brief    
  * @rmtoll   SMCR    SMS    LL_GPTIM_SetSlaveMode
  * @param    TIMx TIM instance
  * @param    EncoderMode This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_SLAVE_MODE_PROHIBITED
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TI1FP1_TI2FP2_CNT
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TI2FP2_TI1FP1_CNT
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TI2FP2_CNT_TI1FP1_CNT
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TRGI_RISE_RST
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TRGI_HIGH_RUN
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TRGI_RISE_RUN
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TRGI_CLK
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetSlaveMode(GPTIM_Type* TIMx, uint32_t EncoderMode)
{
    MODIFY_REG(TIMx->SMCR, GPTIM_SMCR_SMS_Msk, EncoderMode);
}

/**
  * @brief    
  * @rmtoll   SMCR    SMS    LL_GPTIM_GetSlaveMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_SLAVE_MODE_PROHIBITED
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TI1FP1_TI2FP2_CNT
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TI2FP2_TI1FP1_CNT
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TI2FP2_CNT_TI1FP1_CNT
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TRGI_RISE_RST
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TRGI_HIGH_RUN
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TRGI_RISE_RUN
  *           @arg @ref LL_GPTIM_SLAVE_MODE_TRGI_CLK
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetSlaveMode(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, GPTIM_SMCR_SMS_Msk));
}

/**
  * @brief    
  * @rmtoll   DIER    CC1BURSTEN    LL_GPTIM_EnableCC1BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableCC1BurstMode(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_CC1BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC1BURSTEN    LL_GPTIM_IsEnabledCC1BurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledCC1BurstMode(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, GPTIM_DIER_CC1BURSTEN_Msk) == GPTIM_DIER_CC1BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC1BURSTEN    LL_GPTIM_DisableCC1BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableCC1BurstMode(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_CC1BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC2BURSTEN    LL_GPTIM_EnableCC2BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableCC2BurstMode(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_CC2BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC2BURSTEN    LL_GPTIM_IsEnabledCC2BurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledCC2BurstMode(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, GPTIM_DIER_CC2BURSTEN_Msk) == GPTIM_DIER_CC2BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC2BURSTEN    LL_GPTIM_DisableCC2BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableCC2BurstMode(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_CC2BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC3BURSTEN    LL_GPTIM_EnableCC3BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableCC3BurstMode(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_CC3BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC3BURSTEN    LL_GPTIM_IsEnabledCC3BurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledCC3BurstMode(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, GPTIM_DIER_CC3BURSTEN_Msk) == GPTIM_DIER_CC3BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC3BURSTEN    LL_GPTIM_DisableCC3BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableCC3BurstMode(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_CC3BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC4BURSTEN    LL_GPTIM_EnableCC4BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableCC4BurstMode(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_CC4BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC4BURSTEN    LL_GPTIM_IsEnabledCC4BurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledCC4BurstMode(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, GPTIM_DIER_CC4BURSTEN_Msk) == GPTIM_DIER_CC4BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CC4BURSTEN    LL_GPTIM_DisableCC4BurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableCC4BurstMode(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_CC4BURSTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TDE    LL_GPTIM_EnableDMAReq_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableDMAReq_TRIG(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_TDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TDE    LL_GPTIM_IsEnabledDMAReq_TRIG
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledDMAReq_TRIG(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, GPTIM_DIER_TDE_Msk) == GPTIM_DIER_TDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TDE    LL_GPTIM_DisableDMAReq_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableDMAReq_TRIG(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_TDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CCDE    LL_GPTIM_EnableDMAReq
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableDMAReq(GPTIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_CCDE_Msk << Channel ); 
}

/**
  * @brief    
  * @rmtoll   DIER    CCDE    LL_GPTIM_IsEnabledDMAReq
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledDMAReq(GPTIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, (GPTIM_DIER_CCDE_Msk << Channel)) == (GPTIM_DIER_CCDE_Msk << Channel)); 
}

/**
  * @brief    
  * @rmtoll   DIER    CCDE    LL_GPTIM_DisableDMAReq
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableDMAReq(GPTIM_Type* TIMx, uint32_t Channel)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_CCDE_Msk << Channel); 
}

/**
  * @brief    
  * @rmtoll   DIER    UDE    LL_GPTIM_EnableDMAReq_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableDMAReq_UPDATE(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_UDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    UDE    LL_GPTIM_IsEnabledDMAReq_UPDATE
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledDMAReq_UPDATE(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, GPTIM_DIER_UDE_Msk) == GPTIM_DIER_UDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    UDE    LL_GPTIM_DisableDMAReq_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableDMAReq_UPDATE(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_UDE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TIE    LL_GPTIM_EnableIT_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableIT_TRIG(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_TIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TIE    LL_GPTIM_IsEnabledIT_TRIG
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledIT_TRIG(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, GPTIM_DIER_TIE_Msk) == GPTIM_DIER_TIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    TIE    LL_GPTIM_DisableIT_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableIT_TRIG(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_TIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    CCIE    LL_GPTIM_EnableIT_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableIT_CC(GPTIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_CCIE_Msk << Channel ); 
}

/**
  * @brief    
  * @rmtoll   DIER    CCIE    LL_GPTIM_IsEnabledIT_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledIT_CC(GPTIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->DIER,(GPTIM_DIER_CCIE_Msk << Channel )) == (GPTIM_DIER_CCIE_Msk << Channel)); 
}

/**
  * @brief    
  * @rmtoll   DIER    CCIE    LL_GPTIM_DisableIT_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableIT_CC(GPTIM_Type* TIMx, uint32_t Channel)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_CCIE_Msk << Channel ); 
}

/**
  * @brief    
  * @rmtoll   DIER    UIE    LL_GPTIM_EnableIT_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableIT_UPDATE(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->DIER, GPTIM_DIER_UIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    UIE    LL_GPTIM_IsEnabledIT_UPDATE
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledIT_UPDATE(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, GPTIM_DIER_UIE_Msk) == GPTIM_DIER_UIE_Msk);
}

/**
  * @brief    
  * @rmtoll   DIER    UIE    LL_GPTIM_DisableIT_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableIT_UPDATE(GPTIM_Type* TIMx)
{
    CLEAR_BIT(TIMx->DIER, GPTIM_DIER_UIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    CCOF    LL_GPTIM_IsActiveFlag_CCOVR
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsActiveFlag_CCOVR(GPTIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, (GPTIM_ISR_CCOF_Msk << Channel)) == (GPTIM_ISR_CCOF_Msk << Channel)); 
}

/**
  * @brief    
  * @rmtoll   ISR    CCOF    LL_GPTIM_ClearFlag_CCOVR
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_ClearFlag_CCOVR(GPTIM_Type* TIMx, uint32_t Channel)
{
    WRITE_REG(TIMx->ISR, (GPTIM_ISR_CCOF_Msk << Channel)); 
}

/**
  * @brief    
  * @rmtoll   ISR    TIF    LL_GPTIM_IsActiveFlag_TRIG
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsActiveFlag_TRIG(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, GPTIM_ISR_TIF_Msk) == (GPTIM_ISR_TIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    TIF    LL_GPTIM_ClearFlag_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_ClearFlag_TRIG(GPTIM_Type* TIMx)
{
    WRITE_REG(TIMx->ISR, GPTIM_ISR_TIF_Msk); 
}

/**
  * @brief    
  * @rmtoll   ISR    CCIF    LL_GPTIM_IsActiveFlag_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsActiveFlag_CC(GPTIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, (GPTIM_ISR_CCIF_Msk << Channel)) == (GPTIM_ISR_CCIF_Msk << Channel)); 
}

/**
  * @brief    
  * @rmtoll   ISR    CCIF    LL_GPTIM_ClearFlag_CC
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_ClearFlag_CC(GPTIM_Type* TIMx, uint32_t Channel)
{
    WRITE_REG(TIMx->ISR, (GPTIM_ISR_CCIF_Msk << Channel)); 
}

/**
  * @brief    
  * @rmtoll   ISR    UIF    LL_GPTIM_IsActiveFlag_UPDATE
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsActiveFlag_UPDATE(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, GPTIM_ISR_UIF_Msk) == (GPTIM_ISR_UIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    UIF    LL_GPTIM_ClearFlag_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_ClearFlag_UPDATE(GPTIM_Type* TIMx)
{
    WRITE_REG(TIMx->ISR, GPTIM_ISR_UIF_Msk);
}

/**
  * @brief    
  * @rmtoll   EGR    TG    LL_GPTIM_GenerateEvent_TRIG
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_GenerateEvent_TRIG(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->EGR, GPTIM_EGR_TG_Msk);
}

/**
  * @brief    
  * @rmtoll   EGR    CCG    LL_GPTIM_GenerateEvent
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_GenerateEvent(GPTIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->EGR,GPTIM_EGR_CCG_Msk << Channel );
}

/**
  * @brief    
  * @rmtoll   EGR    UG    LL_GPTIM_GenerateEvent_UPDATE
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_GenerateEvent_UPDATE(GPTIM_Type* TIMx)
{
    SET_BIT(TIMx->EGR, GPTIM_EGR_UG_Msk);
}

/**
  * @brief    
  * @rmtoll   CNT        LL_GPTIM_SetCounter
  * @param    TIMx TIM instance
  * @param    counter 
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetCounter(GPTIM_Type* TIMx, uint32_t counter)
{
    MODIFY_REG(TIMx->CNT, (0xffffU << 0U), (counter << 0U));
}

/**
  * @brief    
  * @rmtoll   CNT        LL_GPTIM_GetCounter
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetCounter(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CNT, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   PSC        LL_GPTIM_SetPrescaler
  * @param    TIMx TIM instance
  * @param    Prescaler 
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetPrescaler(GPTIM_Type* TIMx, uint32_t Prescaler)
{
    MODIFY_REG(TIMx->PSC, (0xffffU << 0U), (Prescaler << 0U));
}

/**
  * @brief    
  * @rmtoll   PSC        LL_GPTIM_GetPrescaler
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetPrescaler(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->PSC, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   ARR        LL_GPTIM_SetAutoReload
  * @param    TIMx TIM instance
  * @param    AutoReload 
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetAutoReload(GPTIM_Type* TIMx, uint32_t AutoReload)
{
    MODIFY_REG(TIMx->ARR, (0xffffU << 0U), (AutoReload << 0U));
}

/**
  * @brief    
  * @rmtoll   ARR        LL_GPTIM_GetAutoReload
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetAutoReload(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ARR, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCR1        LL_GPTIM_SetCompareCH1
  * @param    TIMx TIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetCompareCH1(GPTIM_Type* TIMx, uint32_t CompareValue)
{
    MODIFY_REG(TIMx->CCR1, (0xffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    
  * @rmtoll   CCR1        LL_GPTIM_GetCompareCH1
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetCompareCH1(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR1, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCR2        LL_GPTIM_SetCompareCH2
  * @param    TIMx TIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetCompareCH2(GPTIM_Type* TIMx, uint32_t CompareValue)
{
    MODIFY_REG(TIMx->CCR2, (0xffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    
  * @rmtoll   CCR2        LL_GPTIM_GetCompareCH2
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetCompareCH2(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR2, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCR3        LL_GPTIM_SetCompareCH3
  * @param    TIMx TIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetCompareCH3(GPTIM_Type* TIMx, uint32_t CompareValue)
{
    MODIFY_REG(TIMx->CCR3, (0xffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    
  * @rmtoll   CCR3        LL_GPTIM_GetCompareCH3
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetCompareCH3(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR3, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CCR4        LL_GPTIM_SetCompareCH4
  * @param    TIMx TIM instance
  * @param    CompareValue 
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetCompareCH4(GPTIM_Type* TIMx, uint32_t CompareValue)
{
    MODIFY_REG(TIMx->CCR4, (0xffffU << 0U), (CompareValue << 0U));
}

/**
  * @brief    
  * @rmtoll   CCR4        LL_GPTIM_GetCompareCH4
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetCompareCH4(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR4, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   DCR    DBL    LL_GPTIM_SetConfigDMABurstLenth
  * @param    TIMx TIM instance
  * @param    lenth This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_1TRANSFER
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_2TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_3TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_4TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_5TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_6TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_7TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_8TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_9TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_10TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_11TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_12TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_13TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_14TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_15TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_16TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_17TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_18TRANSFERS
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetConfigDMABurstLenth(GPTIM_Type* TIMx, uint32_t lenth)
{
    MODIFY_REG(TIMx->DCR, GPTIM_DCR_DBL_Msk, lenth);
}

/**
  * @brief    
  * @rmtoll   DCR    DBL    LL_GPTIM_GetConfigDMABurstLenth
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_1TRANSFER
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_2TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_3TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_4TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_5TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_6TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_7TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_8TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_9TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_10TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_11TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_12TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_13TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_14TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_15TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_16TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_17TRANSFERS
  *           @arg @ref LL_GPTIM_DMABURST_LENGTH_18TRANSFERS
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetConfigDMABurstLenth(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DCR, GPTIM_DCR_DBL_Msk));
}

/**
  * @brief    
  * @rmtoll   DCR    DBA    LL_GPTIM_SetConfigDMABurstAddress
  * @param    TIMx TIM instance
  * @param    address This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CR1
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CR2
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_SMCR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_DIER
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_SR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_EGR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCMR1
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCMR2
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCER
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CNT
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_PSC
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_ARR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_RCR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCR1
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCR2
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCR3
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCR4
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_BDTR
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetConfigDMABurstAddress(GPTIM_Type* TIMx, uint32_t address)
{
    MODIFY_REG(TIMx->DCR, GPTIM_DCR_DBA_Msk, address);
}

/**
  * @brief    
  * @rmtoll   DCR    DBA    LL_GPTIM_GetConfigDMABurstAddress
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CR1
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CR2
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_SMCR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_DIER
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_SR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_EGR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCMR1
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCMR2
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCER
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CNT
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_PSC
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_ARR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_RCR
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCR1
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCR2
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCR3
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_CCR4
  *           @arg @ref LL_GPTIM_DMABURST_BASEADDR_BDTR
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetConfigDMABurstAddress(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DCR, GPTIM_DCR_DBA_Msk));
}

/**
  * @brief    
  * @rmtoll   DMAR        LL_GPTIM_SetConfigDMAR
  * @param    TIMx TIM instance
  * @param    Addr 
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetConfigDMAR(GPTIM_Type* TIMx, uint32_t Addr)
{
    MODIFY_REG(TIMx->DMAR, (0xffffU << 0U), (Addr << 0U));
}

/**
  * @brief    
  * @rmtoll   DMAR        LL_GPTIM_GetConfigDMAR
  * @param    TIMx TIM instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetConfigDMAR(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DMAR, 0xffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR0SEL    LL_GPTIM_SetGPTIM0ITR0Input
  * @param    TIMx TIM instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR0SEL_ATIM_TRGO
  *           @arg @ref LL_GPTIM_ITR0SEL_UART0_RX
  *           @arg @ref LL_GPTIM_ITR0SEL_UART1_RX
  *           @arg @ref LL_GPTIM_ITR0SEL_UART4_RX
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetGPTIM0ITR0Input(GPTIM_Type* TIMx, uint32_t Input)
{
    MODIFY_REG(TIMx->ITRSEL, GPTIM_ITRSEL_ITR0SEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR0SEL    LL_GPTIM_GetGPTIM0ITR0Input
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR0SEL_ATIM_TRGO
  *           @arg @ref LL_GPTIM_ITR0SEL_UART0_RX
  *           @arg @ref LL_GPTIM_ITR0SEL_UART1_RX
  *           @arg @ref LL_GPTIM_ITR0SEL_UART4_RX
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetGPTIM0ITR0Input(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ITRSEL, GPTIM_ITRSEL_ITR0SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR1SEL    LL_GPTIM_SetGPTIM0ITR1Input
  * @param    TIMx TIM instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR1SEL_GPTIM1_TRGO
  *           @arg @ref LL_GPTIM_ITR1SEL_XTHF
  *           @arg @ref LL_GPTIM_ITR1SEL_RCHF
  *           @arg @ref LL_GPTIM_ITR1SEL_LPUART0_RX
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetGPTIM0ITR1Input(GPTIM_Type* TIMx, uint32_t Input)
{
    MODIFY_REG(TIMx->ITRSEL, GPTIM_ITRSEL_ITR1SEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR1SEL    LL_GPTIM_GetGPTIM0ITR1Input
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR1SEL_GPTIM1_TRGO
  *           @arg @ref LL_GPTIM_ITR1SEL_XTHF
  *           @arg @ref LL_GPTIM_ITR1SEL_RCHF
  *           @arg @ref LL_GPTIM_ITR1SEL_LPUART0_RX
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetGPTIM0ITR1Input(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ITRSEL, GPTIM_ITRSEL_ITR1SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR2SEL    LL_GPTIM_SetGPTIM0ITR2Input
  * @param    TIMx TIM instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR2SEL_BSTIM_TRGO
  *           @arg @ref LL_GPTIM_ITR2SEL_LPUART1_TX
  *           @arg @ref LL_GPTIM_ITR2SEL_RCLP
  *           @arg @ref LL_GPTIM_ITR2SEL_XTLF
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetGPTIM0ITR2Input(GPTIM_Type* TIMx, uint32_t Input)
{
    MODIFY_REG(TIMx->ITRSEL, GPTIM_ITRSEL_ITR2SEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR2SEL    LL_GPTIM_GetGPTIM0ITR2Input
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR2SEL_BSTIM_TRGO
  *           @arg @ref LL_GPTIM_ITR2SEL_LPUART1_TX
  *           @arg @ref LL_GPTIM_ITR2SEL_RCLP
  *           @arg @ref LL_GPTIM_ITR2SEL_XTLF
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetGPTIM0ITR2Input(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ITRSEL, GPTIM_ITRSEL_ITR2SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR3SEL    LL_GPTIM_SetGPTIM0ITR3Input
  * @param    TIMx TIM instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR3SEL_COMP1_TRGO
  *           @arg @ref LL_GPTIM_ITR3SEL_RC4M
  *           @arg @ref LL_GPTIM_ITR3SEL_COMP2_TRGO
  *           @arg @ref LL_GPTIM_ITR3SEL_LPT32_TRGO
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetGPTIM0ITR3Input(GPTIM_Type* TIMx, uint32_t Input)
{
    MODIFY_REG(TIMx->ITRSEL, GPTIM_ITRSEL_ITR3SEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR3SEL    LL_GPTIM_GetGPTIM0ITR3Input
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR3SEL_COMP1_TRGO
  *           @arg @ref LL_GPTIM_ITR3SEL_RC4M
  *           @arg @ref LL_GPTIM_ITR3SEL_COMP2_TRGO
  *           @arg @ref LL_GPTIM_ITR3SEL_LPT32_TRGO
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetGPTIM0ITR3Input(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ITRSEL, GPTIM_ITRSEL_ITR3SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR0SEL    LL_GPTIM_SetGPTIM1ITR0Input
  * @param    TIMx TIM instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR0SEL_ATIM_TRGO
  *           @arg @ref LL_GPTIM_ITR0SEL_UART0_RX
  *           @arg @ref LL_GPTIM_ITR0SEL_UART1_RX
  *           @arg @ref LL_GPTIM_ITR0SEL_UART4_RX
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetGPTIM1ITR0Input(GPTIM_Type* TIMx, uint32_t Input)
{
    MODIFY_REG(TIMx->ITRSEL, GPTIM_ITRSEL_ITR0SEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR0SEL    LL_GPTIM_GetGPTIM1ITR0Input
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR0SEL_ATIM_TRGO
  *           @arg @ref LL_GPTIM_ITR0SEL_UART0_RX
  *           @arg @ref LL_GPTIM_ITR0SEL_UART1_RX
  *           @arg @ref LL_GPTIM_ITR0SEL_UART4_RX
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetGPTIM1ITR0Input(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ITRSEL, GPTIM_ITRSEL_ITR0SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR1SEL    LL_GPTIM_SetGPTIM1ITR1Input
  * @param    TIMx TIM instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR1SEL_GPTIM0_TRGO
  *           @arg @ref LL_GPTIM_ITR1SEL_XTHF
  *           @arg @ref LL_GPTIM_ITR1SEL_RCHF
  *           @arg @ref LL_GPTIM_ITR1SEL_ADC_EOC
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetGPTIM1ITR1Input(GPTIM_Type* TIMx, uint32_t Input)
{
    MODIFY_REG(TIMx->ITRSEL, GPTIM_ITRSEL_ITR1SEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR1SEL    LL_GPTIM_GetGPTIM1ITR1Input
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR1SEL_GPTIM0_TRGO
  *           @arg @ref LL_GPTIM_ITR1SEL_XTHF
  *           @arg @ref LL_GPTIM_ITR1SEL_RCHF
  *           @arg @ref LL_GPTIM_ITR1SEL_ADC_EOC
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetGPTIM1ITR1Input(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ITRSEL, GPTIM_ITRSEL_ITR1SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR2SEL    LL_GPTIM_SetGPTIM1ITR2Input
  * @param    TIMx TIM instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR2SEL_BSTIM_TRGO
  *           @arg @ref LL_GPTIM_ITR2SEL_LSCLK
  *           @arg @ref LL_GPTIM_ITR2SEL_RCLP
  *           @arg @ref LL_GPTIM_ITR2SEL_XTLF
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetGPTIM1ITR2Input(GPTIM_Type* TIMx, uint32_t Input)
{
    MODIFY_REG(TIMx->ITRSEL, GPTIM_ITRSEL_ITR2SEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR2SEL    LL_GPTIM_GetGPTIM1ITR2Input
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR2SEL_BSTIM_TRGO
  *           @arg @ref LL_GPTIM_ITR2SEL_LSCLK
  *           @arg @ref LL_GPTIM_ITR2SEL_RCLP
  *           @arg @ref LL_GPTIM_ITR2SEL_XTLF
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetGPTIM1ITR2Input(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ITRSEL, GPTIM_ITRSEL_ITR2SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR3SEL    LL_GPTIM_SetGPTIM1ITR3Input
  * @param    TIMx TIM instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR3SEL_COMP1_TRGO
  *           @arg @ref LL_GPTIM_ITR3SEL_RC4M
  *           @arg @ref LL_GPTIM_ITR3SEL_COMP2_TRGO
  *           @arg @ref LL_GPTIM_ITR3SEL_LPT32_TRGO
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetGPTIM1ITR3Input(GPTIM_Type* TIMx, uint32_t Input)
{
    MODIFY_REG(TIMx->ITRSEL, GPTIM_ITRSEL_ITR3SEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   ITRSEL    ITR3SEL    LL_GPTIM_GetGPTIM1ITR3Input
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_ITR3SEL_COMP1_TRGO
  *           @arg @ref LL_GPTIM_ITR3SEL_RC4M
  *           @arg @ref LL_GPTIM_ITR3SEL_COMP2_TRGO
  *           @arg @ref LL_GPTIM_ITR3SEL_LPT32_TRGO
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetGPTIM1ITR3Input(GPTIM_Type* TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ITRSEL, GPTIM_ITRSEL_ITR3SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   CCMR    OCCE    LL_GPTIM_Enable_Clear
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_Enable_Clear(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        SET_BIT(TIMx->CCMR1,(GPTIM_CCMR_OCCE_Msk << (Channel*8)));
    }
    else
    {
        SET_BIT(TIMx->CCMR2,(GPTIM_CCMR_OCCE_Msk << ((Channel-2)*8)));
    }        
}

/**
  * @brief    
  * @rmtoll   CCMR    OCCE    LL_GPTIM_IsEnabled_Clear
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabled_Clear(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1,(GPTIM_CCMR_OCCE_Msk << (Channel*8))) == (GPTIM_CCMR_OCCE_Msk << (Channel*8)));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2,(GPTIM_CCMR_OCCE_Msk << ((Channel-2)*8))) == (GPTIM_CCMR_OCCE_Msk << ((Channel-2)*8)));
    }   
}

/**
  * @brief    
  * @rmtoll   CCMR    OCCE    LL_GPTIM_Disable_Clear
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_Disable_Clear(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        CLEAR_BIT(TIMx->CCMR1,(GPTIM_CCMR_OCCE_Msk << (Channel*8)));
    }
    else
    {
        CLEAR_BIT(TIMx->CCMR2,(GPTIM_CCMR_OCCE_Msk << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCM    LL_GPTIM_SetOCMode
  * @param    TIMx TIM instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_OC_MODE_FROZEN
  *           @arg @ref LL_GPTIM_OC_MODE_ACTIVE
  *           @arg @ref LL_GPTIM_OC_MODE_INACTIVE
  *           @arg @ref LL_GPTIM_OC_MODE_TOGGLE
  *           @arg @ref LL_GPTIM_OC_MODE_FORCED_INACTIVE
  *           @arg @ref LL_GPTIM_OC_MODE_FORCED_ACTIVE
  *           @arg @ref LL_GPTIM_OC_MODE_PWM1
  *           @arg @ref LL_GPTIM_OC_MODE_PWM2
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetOCMode(GPTIM_Type* TIMx, uint32_t Mode, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1,(GPTIM_CCMR_OCM_Msk << (Channel*8)),(Mode << (Channel*8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2,(GPTIM_CCMR_OCM_Msk << ((Channel-2)*8)),(Mode << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCM    LL_GPTIM_GetOCMode
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_OC_MODE_FROZEN
  *           @arg @ref LL_GPTIM_OC_MODE_ACTIVE
  *           @arg @ref LL_GPTIM_OC_MODE_INACTIVE
  *           @arg @ref LL_GPTIM_OC_MODE_TOGGLE
  *           @arg @ref LL_GPTIM_OC_MODE_FORCED_INACTIVE
  *           @arg @ref LL_GPTIM_OC_MODE_FORCED_ACTIVE
  *           @arg @ref LL_GPTIM_OC_MODE_PWM1
  *           @arg @ref LL_GPTIM_OC_MODE_PWM2
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetOCMode(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (GPTIM_CCMR_OCM_Msk << (Channel*8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (GPTIM_CCMR_OCM_Msk << ((Channel-2)*8))));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCPE    LL_GPTIM_Enable_Preload
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_Enable_Preload(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        SET_BIT(TIMx->CCMR1,(GPTIM_CCMR_OCPE_Msk << (Channel*8)));
    }
    else
    {
        SET_BIT(TIMx->CCMR2,(GPTIM_CCMR_OCPE_Msk << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCPE    LL_GPTIM_IsEnabled_Preload
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabled_Preload(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1,(GPTIM_CCMR_OCPE_Msk << (Channel*8))) == (GPTIM_CCMR_OCPE_Msk << (Channel*8)));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2,(GPTIM_CCMR_OCPE_Msk << ((Channel-2)*8))) == (GPTIM_CCMR_OCPE_Msk << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCPE    LL_GPTIM_Disable_Preload
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_Disable_Preload(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        CLEAR_BIT(TIMx->CCMR1,(GPTIM_CCMR_OCPE_Msk << (Channel*8)));
    }
    else
    {
        CLEAR_BIT(TIMx->CCMR2,(GPTIM_CCMR_OCPE_Msk << ((Channel-2)*8)));
    }   
}

/**
  * @brief    
  * @rmtoll   CCMR    OCFE    LL_GPTIM_Enable_FastCompare
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_Enable_FastCompare(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        SET_BIT(TIMx->CCMR1,(GPTIM_CCMR_OCFE_Msk << (Channel*8)));
    }
    else
    {
        SET_BIT(TIMx->CCMR2,(GPTIM_CCMR_OCFE_Msk << ((Channel-2)*8)));
    }   
}

/**
  * @brief    
  * @rmtoll   CCMR    OCFE    LL_GPTIM_IsEnabled_FastCompare
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabled_FastCompare(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1,(GPTIM_CCMR_OCFE_Msk << (Channel*8))) == (GPTIM_CCMR_OCFE_Msk << (Channel*8)));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2,(GPTIM_CCMR_OCFE_Msk << ((Channel-2)*8))) == (GPTIM_CCMR_OCFE_Msk << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    OCFE    LL_GPTIM_Disable_FastCompare
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_Disable_FastCompare(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        CLEAR_BIT(TIMx->CCMR1,(GPTIM_CCMR_OCFE_Msk << (Channel*8)));
    }
    else
    {
        CLEAR_BIT(TIMx->CCMR2,(GPTIM_CCMR_OCFE_Msk << ((Channel-2)*8)));
    }   
}

/**
  * @brief    
  * @rmtoll   CCMR    ICF    LL_GPTIM_SetICModeFilter
  * @param    TIMx TIM instance
  * @param    filter This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV1
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV1_N2
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV1_N4
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV1_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV2_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV2_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV4_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV4_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV8_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV8_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV16_N5
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV16_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV16_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV32_N5
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV32_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV32_N8
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetICModeFilter(GPTIM_Type* TIMx, uint32_t filter, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1,(GPTIM_CCMR_ICF_Msk << (Channel*8)),(filter << (Channel*8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2,(GPTIM_CCMR_ICF_Msk << ((Channel-2)*8)),(filter << ((Channel-2)*8)));
    }   
}

/**
  * @brief    
  * @rmtoll   CCMR    ICF    LL_GPTIM_GetICModeFilter
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV1
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV1_N2
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV1_N4
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV1_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV2_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV2_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV4_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV4_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV8_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV8_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV16_N5
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV16_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV16_N8
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV32_N5
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV32_N6
  *           @arg @ref LL_GPTIM_IC_FILTER_FDIV32_N8
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetICModeFilter(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (GPTIM_CCMR_ICF_Msk << (Channel*8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (GPTIM_CCMR_ICF_Msk << ((Channel-2)*8))));
    }   
}

/**
  * @brief    
  * @rmtoll   CCMR    ICPSC    LL_GPTIM_SetICModePrescaler
  * @param    TIMx TIM instance
  * @param    Psc This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_IC_PRESCALER_DIV_1
  *           @arg @ref LL_GPTIM_IC_PRESCALER_DIV_2
  *           @arg @ref LL_GPTIM_IC_PRESCALER_DIV_4
  *           @arg @ref LL_GPTIM_IC_PRESCALER_DIV_8
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetICModePrescaler(GPTIM_Type* TIMx, uint32_t Psc, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1,(GPTIM_CCMR_ICPSC_Msk << (Channel*8)),(Psc << (Channel*8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2,(GPTIM_CCMR_ICPSC_Msk << ((Channel-2)*8)),(Psc << ((Channel-2)*8)));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    ICPSC    LL_GPTIM_GetICModePrescaler
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_IC_PRESCALER_DIV_1
  *           @arg @ref LL_GPTIM_IC_PRESCALER_DIV_2
  *           @arg @ref LL_GPTIM_IC_PRESCALER_DIV_4
  *           @arg @ref LL_GPTIM_IC_PRESCALER_DIV_8
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetICModePrescaler(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (GPTIM_CCMR_ICPSC_Msk << (Channel*8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (GPTIM_CCMR_ICPSC_Msk << ((Channel-2)*8))));
    }  
}

/**
  * @brief    
  * @rmtoll   CCMR    CCS    LL_GPTIM_SetChannelMode
  * @param    TIMx TIM instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CC_MODE_OUTPUT
  *           @arg @ref LL_GPTIM_CC1_MODE_INPUT_TI1
  *           @arg @ref LL_GPTIM_CC1_MODE_INPUT_TI2
  *           @arg @ref LL_GPTIM_CC2_MODE_INPUT_TI2
  *           @arg @ref LL_GPTIM_CC2_MODE_INPUT_TI1
  *           @arg @ref LL_GPTIM_CC3_MODE_INPUT_TI3
  *           @arg @ref LL_GPTIM_CC3_MODE_INPUT_TI4
  *           @arg @ref LL_GPTIM_CC4_MODE_INPUT_TI4
  *           @arg @ref LL_GPTIM_CC4_MODE_INPUT_TI3
  *           @arg @ref LL_GPTIM_CC_MODE_INPUT_TRC
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetChannelMode(GPTIM_Type* TIMx, uint32_t Mode, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1,(GPTIM_CCMR_CCS_Msk << (Channel*8)),(Mode << (Channel*8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2,(GPTIM_CCMR_CCS_Msk << ((Channel-2)*8)),(Mode << ((Channel-2)*8)));
    }   
}

/**
  * @brief    
  * @rmtoll   CCMR    CCS    LL_GPTIM_GetChannelMode
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_CC_MODE_OUTPUT
  *           @arg @ref LL_GPTIM_CC1_MODE_INPUT_TI1
  *           @arg @ref LL_GPTIM_CC1_MODE_INPUT_TI2
  *           @arg @ref LL_GPTIM_CC2_MODE_INPUT_TI2
  *           @arg @ref LL_GPTIM_CC2_MODE_INPUT_TI1
  *           @arg @ref LL_GPTIM_CC3_MODE_INPUT_TI3
  *           @arg @ref LL_GPTIM_CC3_MODE_INPUT_TI4
  *           @arg @ref LL_GPTIM_CC4_MODE_INPUT_TI4
  *           @arg @ref LL_GPTIM_CC4_MODE_INPUT_TI3
  *           @arg @ref LL_GPTIM_CC_MODE_INPUT_TRC
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetChannelMode(GPTIM_Type* TIMx, uint32_t Channel)
{
    if(Channel<LL_GPTIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (GPTIM_CCMR_CCS_Msk << (Channel*8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (GPTIM_CCMR_CCS_Msk << ((Channel-2)*8))));
    }  
}

/**
  * @brief    
  * @rmtoll   CCER    CCOP    LL_GPTIM_SetOCPolartyChannel
  * @param    TIMx TIM instance
  * @param    Polarty This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_OC_POLARITY_NOMAL
  *           @arg @ref LL_GPTIM_OC_POLARITY_REVERSE
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetOCPolartyChannel(GPTIM_Type* TIMx, uint32_t Polarty, uint32_t Channel)
{
    MODIFY_REG(TIMx->CCER,(GPTIM_CCER_CCOP_Msk << (Channel*4)),(Polarty << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOP    LL_GPTIM_GetOCPolartyChannel
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_OC_POLARITY_NOMAL
  *           @arg @ref LL_GPTIM_OC_POLARITY_REVERSE
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetOCPolartyChannel(GPTIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (GPTIM_CCER_CCOP_Msk << (Channel*4)))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCIP    LL_GPTIM_SetICPolartyChannel
  * @param    TIMx TIM instance
  * @param    Polarty This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_IC_POLARITY_RISING
  *           @arg @ref LL_GPTIM_IC_POLARITY_FALLING
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_SetICPolartyChannel(GPTIM_Type* TIMx, uint32_t Polarty, uint32_t Channel)
{
    MODIFY_REG(TIMx->CCER,(GPTIM_CCER_CCIP_Msk << (Channel*4)),(Polarty << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCIP    LL_GPTIM_GetICPolartyChannel
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPTIM_IC_POLARITY_RISING
  *           @arg @ref LL_GPTIM_IC_POLARITY_FALLING
  */
__STATIC_INLINE uint32_t LL_GPTIM_GetICPolartyChannel(GPTIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (GPTIM_CCER_CCIP_Msk << (Channel*4)))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOE    LL_GPTIM_EnableNormalChannelOutput
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableNormalChannelOutput(GPTIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->CCER,(GPTIM_CCER_CCE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOE    LL_GPTIM_IsEnabledNormalChannelOutput
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledNormalChannelOutput(GPTIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER,(GPTIM_CCER_CCE_Msk << (Channel*4))) == (GPTIM_CCER_CCE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOE    LL_GPTIM_DisableNormalChannelOutput
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableNormalChannelOutput(GPTIM_Type* TIMx, uint32_t Channel)
{
    CLEAR_BIT(TIMx->CCER,(GPTIM_CCER_CCE_Msk << (Channel*4)));  
}
/**
  * @brief    
  * @rmtoll   CCER    CCOE    LL_GPTIM_EnableChannelCapture
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_EnableChannelCapture(GPTIM_Type* TIMx, uint32_t Channel)
{
    SET_BIT(TIMx->CCER,(GPTIM_CCER_CCE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOE    LL_GPTIM_IsEnabledChannelCapture
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPTIM_IsEnabledChannelCapture(GPTIM_Type* TIMx, uint32_t Channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER,(GPTIM_CCER_CCE_Msk << (Channel*4))) == (GPTIM_CCER_CCE_Msk << (Channel*4))); 
}

/**
  * @brief    
  * @rmtoll   CCER    CCOE    LL_GPTIM_DisableChannelCapture
  * @param    TIMx TIM instance
  * @param    Channel This parameter can be one of the following values:
  *           @arg @ref LL_GPTIM_CHANNEL_1
  *           @arg @ref LL_GPTIM_CHANNEL_2
  *           @arg @ref LL_GPTIM_CHANNEL_3
  *           @arg @ref LL_GPTIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void LL_GPTIM_DisableChannelCapture(GPTIM_Type* TIMx, uint32_t Channel)
{
    CLEAR_BIT(TIMx->CCER,(GPTIM_CCER_CCE_Msk << (Channel*4)));  
}
/**
  * @}
  */

/** @defgroup GPTIM_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_GPTIM_DeInit(GPTIM_Type *TIMx);

void LL_GPTIM_StructInit(LL_GPTIM_InitTypeDef *TIM_InitStruct);
void LL_GPTIM_SlaveModeStructInit(LL_GPTIM_SlaveInitTypeDef *TIM_InitStruct);
void LL_GPTIM_OC_StructInit(LL_GPTIM_OC_InitTypeDef *TIM_OC_InitStruct);
void LL_GPTIM_IC_StructInit(LL_GPTIM_IC_InitTypeDef *TIM_ICInitStruct);
void LL_GPTIM_ETRStructInit(LL_GPTIM_ETR_InitTypeDef *TIM_InitStruct);

ErrorStatus LL_GPTIM_Init(GPTIM_Type *TIMx, LL_GPTIM_InitTypeDef *TIM_InitStruct);
ErrorStatus LL_GPTIM_SlaveMode_Init(GPTIM_Type *TIMx, LL_GPTIM_SlaveInitTypeDef *TIM_InitStruct);
ErrorStatus LL_GPTIM_OC_Init(GPTIM_Type *TIMx, uint32_t Channel, LL_GPTIM_OC_InitTypeDef *TIM_OC_InitStruct);
ErrorStatus LL_GPTIM_IC_Init(GPTIM_Type *TIMx, uint32_t Channel, LL_GPTIM_IC_InitTypeDef *TIM_IC_InitStruct);
ErrorStatus LL_GPTIM_ETR_Init(GPTIM_Type *TIMx, LL_GPTIM_ETR_InitTypeDef* TIM_InitStruct);


/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_GPTIM_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-22**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/

