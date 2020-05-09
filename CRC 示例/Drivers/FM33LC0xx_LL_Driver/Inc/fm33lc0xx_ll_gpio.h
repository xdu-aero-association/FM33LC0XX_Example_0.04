/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_gpio.h
  * @author  FMSH Application Team
  * @brief   Head file of GPIO LL Module
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
#ifndef __FM33LC0XX_LL_GPIO_H
#define __FM33LC0XX_LL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_GPIO
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup GPIO_LL_ES_INIT GPIO Exported Init structures
  * @{
  */

/**
  * @brief LL GPIO Init Sturcture definition
  */
typedef struct
{
    /*! PIN */
    uint32_t Pin;          
    /*! 功能模式 */
    uint32_t Mode;
    /*! 输出类型 */      
    uint32_t OutputType;
    /*! 上拉使能 */                                           
    uint32_t Pull;
    /*! 数字功能重定向 */
    uint32_t RemapPin;  
                                                      
} LL_GPIO_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Constants GPIO Exported Constants
  * @{
  */
#define    LL_GPIO_PIN_0                                          (0x1U << 0U)
#define    LL_GPIO_PIN_1                                          (0x1U << 1U)
#define    LL_GPIO_PIN_2                                          (0x1U << 2U)
#define    LL_GPIO_PIN_3                                          (0x1U << 3U)
#define    LL_GPIO_PIN_4                                          (0x1U << 4U)
#define    LL_GPIO_PIN_5                                          (0x1U << 5U)
#define    LL_GPIO_PIN_6                                          (0x1U << 6U)
#define    LL_GPIO_PIN_7                                          (0x1U << 7U)
#define    LL_GPIO_PIN_8                                          (0x1U << 8U)
#define    LL_GPIO_PIN_9                                          (0x1U << 9U)
#define    LL_GPIO_PIN_10                                         (0x1U << 10U)
#define    LL_GPIO_PIN_11                                         (0x1U << 11U)
#define    LL_GPIO_PIN_12                                         (0x1U << 12U)
#define    LL_GPIO_PIN_13                                         (0x1U << 13U)
#define    LL_GPIO_PIN_14                                         (0x1U << 14U)
#define    LL_GPIO_PIN_15                                         (0x1U << 15U)
#define    LL_GPIO_PIN_ALL                                        (0xFFFFU << 0U)
#define    LL_GPIO_PIN_ALL_EXCEPTSWD                              (0xFE7FU << 0U)
#define    LL_GPIO_EXTI_LINE_0                                    (0x1U << 0U)
#define    LL_GPIO_EXTI_LINE_1                                    (0x1U << 1U)
#define    LL_GPIO_EXTI_LINE_2                                    (0x1U << 2U)
#define    LL_GPIO_EXTI_LINE_3                                    (0x1U << 3U)
#define    LL_GPIO_EXTI_LINE_4                                    (0x1U << 4U)
#define    LL_GPIO_EXTI_LINE_5                                    (0x1U << 5U)
#define    LL_GPIO_EXTI_LINE_6                                    (0x1U << 6U)
#define    LL_GPIO_EXTI_LINE_7                                    (0x1U << 7U)
#define    LL_GPIO_EXTI_LINE_8                                    (0x1U << 8U)
#define    LL_GPIO_EXTI_LINE_9                                    (0x1U << 9U)
#define    LL_GPIO_EXTI_LINE_10                                   (0x1U << 10U)
#define    LL_GPIO_EXTI_LINE_11                                   (0x1U << 11U)
#define    LL_GPIO_EXTI_LINE_12                                   (0x1U << 12U)
#define    LL_GPIO_EXTI_LINE_13                                   (0x1U << 13U)
#define    LL_GPIO_EXTI_LINE_14                                   (0x1U << 14U)
#define    LL_GPIO_EXTI_LINE_15                                   (0x1U << 15U)
#define    LL_GPIO_EXTI_LINE_ALL                                  (0xFFFFU << 0U)

#define    LL_GPIO_EXTI_LINE_0_PA0                                (0x0U << 0U)
#define    LL_GPIO_EXTI_LINE_0_PA1                                (0x1U << 0U)
#define    LL_GPIO_EXTI_LINE_0_PA2                                (0x2U << 0U)
#define    LL_GPIO_EXTI_LINE_0_PA3                                (0x3U << 0U)
#define    LL_GPIO_EXTI_LINE_1_PA4                                (0x0U << 2U)
#define    LL_GPIO_EXTI_LINE_1_PA5                                (0x1U << 2U)
#define    LL_GPIO_EXTI_LINE_1_PA6                                (0x2U << 2U)
#define    LL_GPIO_EXTI_LINE_1_PA7                                (0x3U << 2U)
#define    LL_GPIO_EXTI_LINE_2_PA8                                (0x0U << 4U)
#define    LL_GPIO_EXTI_LINE_2_PA9                                (0x1U << 4U)
#define    LL_GPIO_EXTI_LINE_2_PA10                               (0x2U << 4U)
#define    LL_GPIO_EXTI_LINE_2_PA11                               (0x3U << 4U)
#define    LL_GPIO_EXTI_LINE_3_PA12                               (0x0U << 6U)
#define    LL_GPIO_EXTI_LINE_3_PA13                               (0x1U << 6U)
#define    LL_GPIO_EXTI_LINE_3_PA14                               (0x2U << 6U)
#define    LL_GPIO_EXTI_LINE_3_PA15                               (0x3U << 6U)
#define    LL_GPIO_EXTI_LINE_4_PB0                                (0x0U << 8U)
#define    LL_GPIO_EXTI_LINE_4_PB1                                (0x1U << 8U)
#define    LL_GPIO_EXTI_LINE_4_PB2                                (0x2U << 8U)
#define    LL_GPIO_EXTI_LINE_4_PB3                                (0x3U << 8U)
#define    LL_GPIO_EXTI_LINE_5_PB4                                (0x0U << 10U)
#define    LL_GPIO_EXTI_LINE_5_PB5                                (0x1U << 10U)
#define    LL_GPIO_EXTI_LINE_5_PB6                                (0x2U << 10U)
#define    LL_GPIO_EXTI_LINE_5_PB7                                (0x3U << 10U)
#define    LL_GPIO_EXTI_LINE_6_PB8                                (0x0U << 12U)
#define    LL_GPIO_EXTI_LINE_6_PB9                                (0x1U << 12U)
#define    LL_GPIO_EXTI_LINE_6_PB10                               (0x2U << 12U)
#define    LL_GPIO_EXTI_LINE_6_PB11                               (0x3U << 12U)
#define    LL_GPIO_EXTI_LINE_7_PB12                               (0x0U << 14U)
#define    LL_GPIO_EXTI_LINE_7_PB13                               (0x1U << 14U)
#define    LL_GPIO_EXTI_LINE_7_PB14                               (0x2U << 14U)
#define    LL_GPIO_EXTI_LINE_7_PB15                               (0x3U << 14U)
#define    LL_GPIO_EXTI_LINE_8_PC0                                (0x0U << 16U)
#define    LL_GPIO_EXTI_LINE_8_PC1                                (0x1U << 16U)
#define    LL_GPIO_EXTI_LINE_8_PC2                                (0x2U << 16U)
#define    LL_GPIO_EXTI_LINE_8_PC3                                (0x3U << 16U)
#define    LL_GPIO_EXTI_LINE_9_PC4                                (0x0U << 18U)
#define    LL_GPIO_EXTI_LINE_9_PC5                                (0x1U << 18U)
#define    LL_GPIO_EXTI_LINE_9_PC6                                (0x2U << 18U)
#define    LL_GPIO_EXTI_LINE_9_PC7                                (0x3U << 18U)
#define    LL_GPIO_EXTI_LINE_10_PC8                               (0x0U << 20U)
#define    LL_GPIO_EXTI_LINE_10_PC9                               (0x1U << 20U)
#define    LL_GPIO_EXTI_LINE_10_PC10                              (0x2U << 20U)
#define    LL_GPIO_EXTI_LINE_10_PC11                              (0x3U << 20U)
#define    LL_GPIO_EXTI_LINE_12_PD0                               (0x0U << 24U)
#define    LL_GPIO_EXTI_LINE_12_PD1                               (0x1U << 24U)
#define    LL_GPIO_EXTI_LINE_12_PD2                               (0x2U << 24U)
#define    LL_GPIO_EXTI_LINE_12_PD3                               (0x3U << 24U)
#define    LL_GPIO_EXTI_LINE_13_PD4                               (0x0U << 26U)
#define    LL_GPIO_EXTI_LINE_13_PD5                               (0x1U << 26U)
#define    LL_GPIO_EXTI_LINE_13_PD6                               (0x2U << 26U)
#define    LL_GPIO_EXTI_LINE_13_PD7                               (0x3U << 26U)
#define    LL_GPIO_EXTI_LINE_14_PD8                               (0x0U << 28U)
#define    LL_GPIO_EXTI_LINE_14_PD9                               (0x1U << 28U)
#define    LL_GPIO_EXTI_LINE_14_PD10                              (0x2U << 28U)
#define    LL_GPIO_EXTI_LINE_14_PD11                              (0x3U << 28U)
#define    LL_GPIO_WKUP_0                                         (0x1U << 0U)
#define    LL_GPIO_WKUP_1                                         (0x1U << 1U)
#define    LL_GPIO_WKUP_2                                         (0x1U << 2U)
#define    LL_GPIO_WKUP_3                                         (0x1U << 3U)
#define    LL_GPIO_WKUP_4                                         (0x1U << 4U)
#define    LL_GPIO_WKUP_5                                         (0x1U << 5U)
#define    LL_GPIO_WKUP_6                                         (0x1U << 6U)
#define    LL_GPIO_WKUP_7                                         (0x1U << 7U)



#define    LL_GPIO_MODE_INPUT                                     (0x0U << GPIO_FCR_Pos)
#define    LL_GPIO_MODE_OUTPUT                                    (0x1U << GPIO_FCR_Pos)
#define    LL_GPIO_MODE_DIGITAL                                   (0x2U << GPIO_FCR_Pos)
#define    LL_GPIO_MODE_ANALOG                                    (0x3U << GPIO_FCR_Pos)

#define    LL_GPIO_EXTI_TRIGGER_RISING                            (0x0U << GPIO_EXTIEDS_Pos)
#define    LL_GPIO_EXTI_TRIGGER_FALLING                           (0x1U << GPIO_EXTIEDS_Pos)
#define    LL_GPIO_EXTI_TRIGGER_BOTHEDGE                          (0x2U << GPIO_EXTIEDS_Pos)
#define    LL_GPIO_EXTI_TRIGGER_NONE                              (0x3U << GPIO_EXTIEDS_Pos)

#define    LL_GPIO_FOUT1_SELECT_XTLF                              (0x0U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_RCLP                              (0x1U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_RCHF_DIV64                        (0x2U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_LSCLK                             (0x3U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_AHBCLK_DIV64                      (0x4U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_RTCTM                             (0x5U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_PLLOUTPUT_DIV64                   (0x6U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_RTCCLK64HZ                        (0x7U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_APBCLK_DIV64                      (0x8U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_PLLOUTPUT                         (0x9U << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_RC4M_PSC                          (0xAU << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_RCHF                              (0xBU << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_XTHF_DIV64                        (0xCU << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_ADCCLK_DIV64                      (0xDU << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_CLK_8K                            (0xEU << GPIO_FOUTSEL_FOUT1_Pos)
#define    LL_GPIO_FOUT1_SELECT_COMP2_OUTPUT                      (0xFU << GPIO_FOUTSEL_FOUT1_Pos)

#define    LL_GPIO_FOUT0_SELECT_XTLF                              (0x0U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_RCLP                              (0x1U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_RCHF_DIV64                        (0x2U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_LSCLK                             (0x3U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_AHBCLK_DIV64                      (0x4U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_RTCTM                             (0x5U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_PLLOUTPUT_DIV64                   (0x6U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_RTCCLK64HZ                        (0x7U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_APBCLK_DIV64                      (0x8U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_PLLOUTPUT                         (0x9U << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_RC4M_PSC                          (0xAU << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_RCHF                              (0xBU << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_XTHF_DIV64                        (0xCU << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_COMP1_OUTPUT                      (0xDU << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_CLK_8K                            (0xEU << GPIO_FOUTSEL_FOUT0_Pos)
#define    LL_GPIO_FOUT0_SELECT_ADC_CLK                           (0xFU << GPIO_FOUTSEL_FOUT0_Pos)

#define    LL_GPIO_OUTPUT_PUSHPULL                                (0)
#define    LL_GPIO_OUTPUT_OPENDRAIN                               (1)
#define    LL_GPIO_WKUP_POLARITY_RISING                           (0x1U << 8)
#define    LL_GPIO_WKUP_POLARITY_FALLING                          (0x0U << 8)
/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Functions GPIO Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   INEN        LL_GPIO_EnablePinInput
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_EnablePinInput(GPIO_Type *GPIOx, uint32_t Pin)
{
    SET_BIT(GPIOx->INEN, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   INEN        LL_GPIO_DisablePinInput
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_DisablePinInput(GPIO_Type *GPIOx, uint32_t Pin)
{
    CLEAR_BIT(GPIOx->INEN, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   INEN        LL_GPIO_IsEnabledPinInput
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsEnabledPinInput(GPIO_Type *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->INEN, ((Pin & 0xFFFF) << 0x0U)) == ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PUEN        LL_GPIO_EnablePinPullup
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_EnablePinPullup(GPIO_Type *GPIOx, uint32_t Pin)
{
    SET_BIT(GPIOx->PUEN, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PUEN        LL_GPIO_DisablePinPullup
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_DisablePinPullup(GPIO_Type *GPIOx, uint32_t Pin)
{
    CLEAR_BIT(GPIOx->PUEN, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PUEN        LL_GPIO_IsEnabledPinPullup
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsEnabledPinPullup(GPIO_Type *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->PUEN, ((Pin & 0xFFFF) << 0x0U)) == ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   ODEN        LL_GPIO_EnablePinOpendrain
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_EnablePinOpendrain(GPIO_Type *GPIOx, uint32_t Pin)
{
    SET_BIT(GPIOx->ODEN, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   ODEN        LL_GPIO_DisablePinOpendrain
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_DisablePinOpendrain(GPIO_Type *GPIOx, uint32_t Pin)
{
    CLEAR_BIT(GPIOx->ODEN, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   ODEN        LL_GPIO_IsEnabledPinOpendrain
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsEnabledPinOpendrain(GPIO_Type *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->ODEN, ((Pin & 0xFFFF) << 0x0U)) == ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   DFS        LL_GPIO_EnablePinRemap
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_EnablePinRemap(GPIO_Type *GPIOx, uint32_t Pin)
{
    SET_BIT(GPIOx->DFS, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   DFS        LL_GPIO_DisablePinRemap
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_DisablePinRemap(GPIO_Type *GPIOx, uint32_t Pin)
{
    CLEAR_BIT(GPIOx->DFS, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   DFS        LL_GPIO_IsEnabledPinRemap
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsEnabledPinRemap(GPIO_Type *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->DFS, ((Pin & 0xFFFF) << 0x0U)) == ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   ANEN        LL_GPIO_EnablePinAnalog
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  *           @arg @ref LL_GPIO_EXTI_LINE_0
  *           @arg @ref LL_GPIO_EXTI_LINE_1
  *           @arg @ref LL_GPIO_EXTI_LINE_2
  *           @arg @ref LL_GPIO_EXTI_LINE_3
  *           @arg @ref LL_GPIO_EXTI_LINE_4
  *           @arg @ref LL_GPIO_EXTI_LINE_7
  *           @arg @ref LL_GPIO_EXTI_LINE_8
  *           @arg @ref LL_GPIO_EXTI_LINE_9
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_EnablePinAnalog(GPIO_Type *GPIOx, uint32_t Pin)
{
    SET_BIT(GPIOx->ANEN, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   ANEN        LL_GPIO_DisablePinAnalog
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_DisablePinAnalog(GPIO_Type *GPIOx, uint32_t Pin)
{
    CLEAR_BIT(GPIOx->ANEN, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   ANEN        LL_GPIO_IsEnabledPinAnalog
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsEnabledPinAnalog(GPIO_Type *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->ANEN, ((Pin & 0xFFFF) << 0x0U)) == ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   FCR        LL_GPIO_SetPinMode
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_MODE_INPUT
  *           @arg @ref LL_GPIO_MODE_OUTPUT
  *           @arg @ref LL_GPIO_MODE_DIGITAL
  *           @arg @ref LL_GPIO_MODE_ANALOG
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetPinMode(GPIO_Type *GPIOx, uint32_t Pin, uint32_t Mode)
{
    MODIFY_REG(GPIOx->FCR, ((Pin * Pin) * GPIO_FCR), ((Pin * Pin) * Mode));
}

/**
  * @brief    
  * @rmtoll   FCR        LL_GPIO_GetPinMode
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPIO_MODE_INPUT
  *           @arg @ref LL_GPIO_MODE_OUTPUT
  *           @arg @ref LL_GPIO_MODE_DIGITAL
  *           @arg @ref LL_GPIO_MODE_ANALOG
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinMode(GPIO_Type *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->FCR, ((Pin * Pin) * GPIO_FCR)) / (Pin * Pin));
}

/**
  * @brief    
  * @rmtoll   DO        LL_GPIO_WriteOutputPort
  * @param    GPIOx GPIO Port
  * @param    PortValue Level value for each pin of the port
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_WriteOutputPort(GPIO_Type *GPIOx, uint32_t PortValue)
{
    MODIFY_REG(GPIOx->DO, (0xFFFFU << 0U), (PortValue << 0U));
}

/**
  * @brief    
  * @rmtoll   DO        LL_GPIO_ReadOutputPort
  * @param    GPIOx GPIO Port
  * @retval   Output data register value of port
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadOutputPort(GPIO_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->DO, 0xFFFFU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   DO        LL_GPIO_IsOutputPinSet
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsOutputPinSet(GPIO_Type *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->DO, ((Pin & 0xFFFF) << 0x0U)) == ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   DO        LL_GPIO_ToggleOutputPin
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_ToggleOutputPin(GPIO_Type *GPIOx, uint32_t Pin)
{
    WRITE_REG(GPIOx->DO, READ_REG(GPIOx->DO) ^ Pin);
}

/**
  * @brief    
  * @rmtoll   DIN        LL_GPIO_ReadInputPort
  * @param    GPIOx GPIO Port
  * @retval   Input data register value of port
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadInputPort(GPIO_Type *GPIOx)
{
    return (uint32_t)(READ_BIT(GPIOx->DIN, 0xFFFFU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   DIN        LL_GPIO_IsInputPinSet
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsInputPinSet(GPIO_Type *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->DIN, ((Pin & 0xFFFF) << 0x0U)) == ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   DSET        LL_GPIO_SetOutputPin
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetOutputPin(GPIO_Type *GPIOx, uint32_t Pin)
{
    SET_BIT(GPIOx->DSET, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   DRST        LL_GPIO_ResetOutputPin
  * @param    GPIOx GPIO Port
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_PIN_0
  *           @arg @ref LL_GPIO_PIN_1
  *           @arg @ref LL_GPIO_PIN_2
  *           @arg @ref LL_GPIO_PIN_3
  *           @arg @ref LL_GPIO_PIN_4
  *           @arg @ref LL_GPIO_PIN_5
  *           @arg @ref LL_GPIO_PIN_6
  *           @arg @ref LL_GPIO_PIN_7
  *           @arg @ref LL_GPIO_PIN_8
  *           @arg @ref LL_GPIO_PIN_9
  *           @arg @ref LL_GPIO_PIN_10
  *           @arg @ref LL_GPIO_PIN_11
  *           @arg @ref LL_GPIO_PIN_12
  *           @arg @ref LL_GPIO_PIN_13
  *           @arg @ref LL_GPIO_PIN_14
  *           @arg @ref LL_GPIO_PIN_15
  *           @arg @ref LL_GPIO_PIN_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_ResetOutputPin(GPIO_Type *GPIOx, uint32_t Pin)
{
    SET_BIT(GPIOx->DRST, ((Pin & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   EXTIEDS        LL_EXTI_SetTrigEdge
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTILine This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_0
  *           @arg @ref LL_GPIO_EXTI_LINE_1
  *           @arg @ref LL_GPIO_EXTI_LINE_2
  *           @arg @ref LL_GPIO_EXTI_LINE_3
  *           @arg @ref LL_GPIO_EXTI_LINE_4
  *           @arg @ref LL_GPIO_EXTI_LINE_5
  *           @arg @ref LL_GPIO_EXTI_LINE_6
  *           @arg @ref LL_GPIO_EXTI_LINE_7
  *           @arg @ref LL_GPIO_EXTI_LINE_8
  *           @arg @ref LL_GPIO_EXTI_LINE_9
  *           @arg @ref LL_GPIO_EXTI_LINE_10
  *           @arg @ref LL_GPIO_EXTI_LINE_11
  *           @arg @ref LL_GPIO_EXTI_LINE_12
  *           @arg @ref LL_GPIO_EXTI_LINE_13
  *           @arg @ref LL_GPIO_EXTI_LINE_14
  *           @arg @ref LL_GPIO_EXTI_LINE_15
  * @param    TrigEdge This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_TRIGGER_RISING
  *           @arg @ref LL_GPIO_EXTI_TRIGGER_FALLING
  *           @arg @ref LL_GPIO_EXTI_TRIGGER_BOTHEDGE
  *           @arg @ref LL_GPIO_EXTI_TRIGGER_NONE
  * @retval   None
  */
__STATIC_INLINE void LL_EXTI_SetTrigEdge(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTILine, uint32_t TrigEdge)
{
    MODIFY_REG(GPIO_Common->EXTIEDS, ((EXTILine * EXTILine) * GPIO_EXTIEDS), ((EXTILine * EXTILine) * TrigEdge));
}

/**
  * @brief    
  * @rmtoll   EXTIEDS        LL_EXTI_GetTrigEdge
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTILine This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_0
  *           @arg @ref LL_GPIO_EXTI_LINE_1
  *           @arg @ref LL_GPIO_EXTI_LINE_2
  *           @arg @ref LL_GPIO_EXTI_LINE_3
  *           @arg @ref LL_GPIO_EXTI_LINE_4
  *           @arg @ref LL_GPIO_EXTI_LINE_5
  *           @arg @ref LL_GPIO_EXTI_LINE_6
  *           @arg @ref LL_GPIO_EXTI_LINE_7
  *           @arg @ref LL_GPIO_EXTI_LINE_8
  *           @arg @ref LL_GPIO_EXTI_LINE_9
  *           @arg @ref LL_GPIO_EXTI_LINE_10
  *           @arg @ref LL_GPIO_EXTI_LINE_11
  *           @arg @ref LL_GPIO_EXTI_LINE_12
  *           @arg @ref LL_GPIO_EXTI_LINE_13
  *           @arg @ref LL_GPIO_EXTI_LINE_14
  *           @arg @ref LL_GPIO_EXTI_LINE_15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_TRIGGER_RISING
  *           @arg @ref LL_GPIO_EXTI_TRIGGER_FALLING
  *           @arg @ref LL_GPIO_EXTI_TRIGGER_BOTHEDGE
  *           @arg @ref LL_GPIO_EXTI_TRIGGER_NONE
  */
__STATIC_INLINE uint32_t LL_EXTI_GetTrigEdge(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTILine)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTIEDS, ((EXTILine * EXTILine) * GPIO_EXTIEDS)) / (EXTILine * EXTILine));
}

/**
  * @brief    
  * @rmtoll   EXTIDF        LL_EXTI_EnableDigitalFilter
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTILine This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_0
  *           @arg @ref LL_GPIO_EXTI_LINE_1
  *           @arg @ref LL_GPIO_EXTI_LINE_2
  *           @arg @ref LL_GPIO_EXTI_LINE_3
  *           @arg @ref LL_GPIO_EXTI_LINE_4
  *           @arg @ref LL_GPIO_EXTI_LINE_5
  *           @arg @ref LL_GPIO_EXTI_LINE_6
  *           @arg @ref LL_GPIO_EXTI_LINE_7
  *           @arg @ref LL_GPIO_EXTI_LINE_8
  *           @arg @ref LL_GPIO_EXTI_LINE_9
  *           @arg @ref LL_GPIO_EXTI_LINE_10
  *           @arg @ref LL_GPIO_EXTI_LINE_11
  *           @arg @ref LL_GPIO_EXTI_LINE_12
  *           @arg @ref LL_GPIO_EXTI_LINE_13
  *           @arg @ref LL_GPIO_EXTI_LINE_14
  *           @arg @ref LL_GPIO_EXTI_LINE_15
  *           @arg @ref LL_GPIO_EXTI_LINE_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_EXTI_EnableDigitalFilter(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTILine)
{
    SET_BIT(GPIO_Common->EXTIDF, ((EXTILine & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   EXTIDF        LL_EXTI_DisableDigitalFilter
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTILine This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_0
  *           @arg @ref LL_GPIO_EXTI_LINE_1
  *           @arg @ref LL_GPIO_EXTI_LINE_2
  *           @arg @ref LL_GPIO_EXTI_LINE_3
  *           @arg @ref LL_GPIO_EXTI_LINE_4
  *           @arg @ref LL_GPIO_EXTI_LINE_5
  *           @arg @ref LL_GPIO_EXTI_LINE_6
  *           @arg @ref LL_GPIO_EXTI_LINE_7
  *           @arg @ref LL_GPIO_EXTI_LINE_8
  *           @arg @ref LL_GPIO_EXTI_LINE_9
  *           @arg @ref LL_GPIO_EXTI_LINE_10
  *           @arg @ref LL_GPIO_EXTI_LINE_11
  *           @arg @ref LL_GPIO_EXTI_LINE_12
  *           @arg @ref LL_GPIO_EXTI_LINE_13
  *           @arg @ref LL_GPIO_EXTI_LINE_14
  *           @arg @ref LL_GPIO_EXTI_LINE_15
  *           @arg @ref LL_GPIO_EXTI_LINE_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_EXTI_DisableDigitalFilter(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTILine)
{
    CLEAR_BIT(GPIO_Common->EXTIDF, ((EXTILine & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   EXTIDF        LL_EXTI_IsEnabledDigitalFilter
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTILine This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_0
  *           @arg @ref LL_GPIO_EXTI_LINE_1
  *           @arg @ref LL_GPIO_EXTI_LINE_2
  *           @arg @ref LL_GPIO_EXTI_LINE_3
  *           @arg @ref LL_GPIO_EXTI_LINE_4
  *           @arg @ref LL_GPIO_EXTI_LINE_5
  *           @arg @ref LL_GPIO_EXTI_LINE_6
  *           @arg @ref LL_GPIO_EXTI_LINE_7
  *           @arg @ref LL_GPIO_EXTI_LINE_8
  *           @arg @ref LL_GPIO_EXTI_LINE_9
  *           @arg @ref LL_GPIO_EXTI_LINE_10
  *           @arg @ref LL_GPIO_EXTI_LINE_11
  *           @arg @ref LL_GPIO_EXTI_LINE_12
  *           @arg @ref LL_GPIO_EXTI_LINE_13
  *           @arg @ref LL_GPIO_EXTI_LINE_14
  *           @arg @ref LL_GPIO_EXTI_LINE_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_EXTI_IsEnabledDigitalFilter(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTILine)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTIDF, ((EXTILine & 0xFFFF) << 0x0U)) == ((EXTILine & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   EXTIISR        LL_EXTI_IsActiveFlag
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTILine This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_0
  *           @arg @ref LL_GPIO_EXTI_LINE_1
  *           @arg @ref LL_GPIO_EXTI_LINE_2
  *           @arg @ref LL_GPIO_EXTI_LINE_3
  *           @arg @ref LL_GPIO_EXTI_LINE_4
  *           @arg @ref LL_GPIO_EXTI_LINE_5
  *           @arg @ref LL_GPIO_EXTI_LINE_6
  *           @arg @ref LL_GPIO_EXTI_LINE_7
  *           @arg @ref LL_GPIO_EXTI_LINE_8
  *           @arg @ref LL_GPIO_EXTI_LINE_9
  *           @arg @ref LL_GPIO_EXTI_LINE_10
  *           @arg @ref LL_GPIO_EXTI_LINE_11
  *           @arg @ref LL_GPIO_EXTI_LINE_12
  *           @arg @ref LL_GPIO_EXTI_LINE_13
  *           @arg @ref LL_GPIO_EXTI_LINE_14
  *           @arg @ref LL_GPIO_EXTI_LINE_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_EXTI_IsActiveFlag(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTILine)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTIISR, ((EXTILine & 0xFFFF) << 0x0U)) == ((EXTILine & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   EXTIISR        LL_EXTI_ClearFlag
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTILine This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_0
  *           @arg @ref LL_GPIO_EXTI_LINE_1
  *           @arg @ref LL_GPIO_EXTI_LINE_2
  *           @arg @ref LL_GPIO_EXTI_LINE_3
  *           @arg @ref LL_GPIO_EXTI_LINE_4
  *           @arg @ref LL_GPIO_EXTI_LINE_5
  *           @arg @ref LL_GPIO_EXTI_LINE_6
  *           @arg @ref LL_GPIO_EXTI_LINE_7
  *           @arg @ref LL_GPIO_EXTI_LINE_8
  *           @arg @ref LL_GPIO_EXTI_LINE_9
  *           @arg @ref LL_GPIO_EXTI_LINE_10
  *           @arg @ref LL_GPIO_EXTI_LINE_11
  *           @arg @ref LL_GPIO_EXTI_LINE_12
  *           @arg @ref LL_GPIO_EXTI_LINE_13
  *           @arg @ref LL_GPIO_EXTI_LINE_14
  *           @arg @ref LL_GPIO_EXTI_LINE_15
  *           @arg @ref LL_GPIO_EXTI_LINE_ALL
  * @retval   None
  */
__STATIC_INLINE void LL_EXTI_ClearFlag(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTILine)
{
    WRITE_REG(GPIO_Common->EXTIISR, ((EXTILine & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   EXTIDI        LL_EXTI_IsEXTILineSet
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTILine This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_0
  *           @arg @ref LL_GPIO_EXTI_LINE_1
  *           @arg @ref LL_GPIO_EXTI_LINE_2
  *           @arg @ref LL_GPIO_EXTI_LINE_3
  *           @arg @ref LL_GPIO_EXTI_LINE_4
  *           @arg @ref LL_GPIO_EXTI_LINE_5
  *           @arg @ref LL_GPIO_EXTI_LINE_6
  *           @arg @ref LL_GPIO_EXTI_LINE_7
  *           @arg @ref LL_GPIO_EXTI_LINE_8
  *           @arg @ref LL_GPIO_EXTI_LINE_9
  *           @arg @ref LL_GPIO_EXTI_LINE_10
  *           @arg @ref LL_GPIO_EXTI_LINE_11
  *           @arg @ref LL_GPIO_EXTI_LINE_12
  *           @arg @ref LL_GPIO_EXTI_LINE_13
  *           @arg @ref LL_GPIO_EXTI_LINE_14
  *           @arg @ref LL_GPIO_EXTI_LINE_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_EXTI_IsEXTILineSet(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTILine)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTIDI, ((EXTILine & 0xFFFF) << 0x0U)) == ((EXTILine & 0xFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   EXTIDI        LL_EXTI_ReadEXTILines
  * @param    GPIO_Common GPIO_Common instance
  * @retval   EXTI data register value of port
  */
__STATIC_INLINE uint32_t LL_EXTI_ReadEXTILines(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTIDI, 0xFFFFU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   FOUTSEL    FOUT0    LL_GPIO_SetFout0
  * @param    GPIO_Common GPIO_Common instance
  * @param    FoutSel This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_FOUT0_SELECT_XTLF             
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RCLP             
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RCHF_DIV64       
  *           @arg @ref LL_GPIO_FOUT0_SELECT_LSCLK            
  *           @arg @ref LL_GPIO_FOUT0_SELECT_AHBCLK_DIV64     
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RTCTM            
  *           @arg @ref LL_GPIO_FOUT0_SELECT_PLLOUTPUT_DIV64  
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RTCCLK64Hz       
  *           @arg @ref LL_GPIO_FOUT0_SELECT_APBCLK_DIV64     
  *           @arg @ref LL_GPIO_FOUT0_SELECT_PLLOUTPUT        
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RC4M_PSC         
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RCHF             
  *           @arg @ref LL_GPIO_FOUT0_SELECT_XTHF_DIV64       
  *           @arg @ref LL_GPIO_FOUT0_SELECT_COMP1_OUTPUT     
  *           @arg @ref LL_GPIO_FOUT0_SELECT_CLK_8K           
  *           @arg @ref LL_GPIO_FOUT0_SELECT_ADC_CLK          
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetFout0(GPIO_COMMON_Type *GPIO_Common, uint32_t FoutSel)
{
    MODIFY_REG(GPIO_Common->FOUTSEL, GPIO_FOUTSEL_FOUT0_Msk, FoutSel);
}

/**
  * @brief    
  * @rmtoll   FOUTSEL    FOUT0    LL_GPIO_GetFout0
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPIO_FOUT0_SELECT_XTLF             
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RCLP             
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RCHF_DIV64       
  *           @arg @ref LL_GPIO_FOUT0_SELECT_LSCLK            
  *           @arg @ref LL_GPIO_FOUT0_SELECT_AHBCLK_DIV64     
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RTCTM            
  *           @arg @ref LL_GPIO_FOUT0_SELECT_PLLOUTPUT_DIV64  
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RTCCLK64Hz       
  *           @arg @ref LL_GPIO_FOUT0_SELECT_APBCLK_DIV64     
  *           @arg @ref LL_GPIO_FOUT0_SELECT_PLLOUTPUT        
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RC4M_PSC         
  *           @arg @ref LL_GPIO_FOUT0_SELECT_RCHF             
  *           @arg @ref LL_GPIO_FOUT0_SELECT_XTHF_DIV64       
  *           @arg @ref LL_GPIO_FOUT0_SELECT_COMP1_OUTPUT     
  *           @arg @ref LL_GPIO_FOUT0_SELECT_CLK_8K           
  *           @arg @ref LL_GPIO_FOUT0_SELECT_ADC_CLK          
  */
__STATIC_INLINE uint32_t LL_GPIO_GetFout0(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->FOUTSEL, GPIO_FOUTSEL_FOUT0_Msk));
}

/**
  * @brief    
  * @rmtoll   FOUTSEL    FOUT1    LL_GPIO_SetFout1
  * @param    GPIO_Common GPIO_Common instance
  * @param    FoutSel This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_FOUT1_SELECT_XTLF
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RCLP
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RCHF_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_LSCLK
  *           @arg @ref LL_GPIO_FOUT1_SELECT_AHBCLK_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RTCTM
  *           @arg @ref LL_GPIO_FOUT1_SELECT_PLLOUTPUT_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RTCCLK64Hz
  *           @arg @ref LL_GPIO_FOUT1_SELECT_APBCLK_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_PLLOUTPUT
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RC4M_PSC
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RCHF
  *           @arg @ref LL_GPIO_FOUT1_SELECT_XTHF_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_COMP1_OUTPUT
  *           @arg @ref LL_GPIO_FOUT1_SELECT_CLK_8K
  *           @arg @ref LL_GPIO_FOUT1_SELECT_COMP2_OUTPUT
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetFout1(GPIO_COMMON_Type *GPIO_Common, uint32_t FoutSel)
{
    MODIFY_REG(GPIO_Common->FOUTSEL, GPIO_FOUTSEL_FOUT1_Msk, FoutSel);
}

/**
  * @brief    
  * @rmtoll   FOUTSEL    FOUT1    LL_GPIO_GetFout1
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPIO_FOUT1_SELECT_XTLF
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RCLP
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RCHF_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_LSCLK
  *           @arg @ref LL_GPIO_FOUT1_SELECT_AHBCLK_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RTCTM
  *           @arg @ref LL_GPIO_FOUT1_SELECT_PLLOUTPUT_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RTCCLK64Hz
  *           @arg @ref LL_GPIO_FOUT1_SELECT_APBCLK_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_PLLOUTPUT
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RC4M_PSC
  *           @arg @ref LL_GPIO_FOUT1_SELECT_RCHF
  *           @arg @ref LL_GPIO_FOUT1_SELECT_XTHF_DIV64
  *           @arg @ref LL_GPIO_FOUT1_SELECT_COMP1_OUTPUT
  *           @arg @ref LL_GPIO_FOUT1_SELECT_CLK_8K
  *           @arg @ref LL_GPIO_FOUT1_SELECT_COMP2_OUTPUT
  */
__STATIC_INLINE uint32_t LL_GPIO_GetFout1(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->FOUTSEL, GPIO_FOUTSEL_FOUT1_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI0    LL_GPIO_SetExitLine0
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_0_PA0
  *           @arg @ref LL_GPIO_EXTI_LINE_0_PA1
  *           @arg @ref LL_GPIO_EXTI_LINE_0_PA2
  *           @arg @ref LL_GPIO_EXTI_LINE_0_PA3
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine0(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI0_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI0    LL_GPIO_GetExitLine0
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine0(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI0_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI1    LL_GPIO_SetExitLine1
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_1_PA4
  *           @arg @ref LL_GPIO_EXTI_LINE_1_PA5
  *           @arg @ref LL_GPIO_EXTI_LINE_1_PA6
  *           @arg @ref LL_GPIO_EXTI_LINE_1_PA7
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine1(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI1_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI1    LL_GPIO_GetExitLine1
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine1(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI1_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI2    LL_GPIO_SetExitLine2
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_2_PA8
  *           @arg @ref LL_GPIO_EXTI_LINE_2_PA9
  *           @arg @ref LL_GPIO_EXTI_LINE_2_PA10
  *           @arg @ref LL_GPIO_EXTI_LINE_2_PA11
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine2(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI2_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI2    LL_GPIO_GetExitLine2
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine2(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI2_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI3    LL_GPIO_SetExitLine3
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_3_PA12
  *           @arg @ref LL_GPIO_EXTI_LINE_3_PA13
  *           @arg @ref LL_GPIO_EXTI_LINE_3_PA14
  *           @arg @ref LL_GPIO_EXTI_LINE_3_PA15
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine3(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI3_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI3    LL_GPIO_GetExitLine3
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine3(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI3_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI4    LL_GPIO_SetExitLine4
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_4_PB0
  *           @arg @ref LL_GPIO_EXTI_LINE_4_PB1
  *           @arg @ref LL_GPIO_EXTI_LINE_4_PB2
  *           @arg @ref LL_GPIO_EXTI_LINE_4_PB3
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine4(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI4_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI4    LL_GPIO_GetExitLine4
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine4(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI4_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI5    LL_GPIO_SetExitLine5
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_5_PB4
  *           @arg @ref LL_GPIO_EXTI_LINE_5_PB5
  *           @arg @ref LL_GPIO_EXTI_LINE_5_PB6
  *           @arg @ref LL_GPIO_EXTI_LINE_5_PB7
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine5(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI5_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI5    LL_GPIO_GetExitLine5
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine5(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI5_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI6    LL_GPIO_SetExitLine6
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_6_PB8
  *           @arg @ref LL_GPIO_EXTI_LINE_6_PB9
  *           @arg @ref LL_GPIO_EXTI_LINE_6_PB10
  *           @arg @ref LL_GPIO_EXTI_LINE_6_PB11
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine6(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI6_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI6    LL_GPIO_GetExitLine6
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine6(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI6_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI7    LL_GPIO_SetExitLine7
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_7_PB12
  *           @arg @ref LL_GPIO_EXTI_LINE_7_PB13
  *           @arg @ref LL_GPIO_EXTI_LINE_7_PB14
  *           @arg @ref LL_GPIO_EXTI_LINE_7_PB15
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine7(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI7_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI7    LL_GPIO_GetExitLine7
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine7(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI7_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI8    LL_GPIO_SetExitLine8
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_8_PC0
  *           @arg @ref LL_GPIO_EXTI_LINE_8_PC1
  *           @arg @ref LL_GPIO_EXTI_LINE_8_PC2
  *           @arg @ref LL_GPIO_EXTI_LINE_8_PC3
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine8(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI8_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI8    LL_GPIO_GetExitLine8
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine8(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI8_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI9    LL_GPIO_SetExitLine9
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_9_PC4
  *           @arg @ref LL_GPIO_EXTI_LINE_9_PC5
  *           @arg @ref LL_GPIO_EXTI_LINE_9_PC6
  *           @arg @ref LL_GPIO_EXTI_LINE_9_PC7
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine9(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI9_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI9    LL_GPIO_GetExitLine9
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine9(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI9_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI10    LL_GPIO_SetExitLine10
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_10_PC8
  *           @arg @ref LL_GPIO_EXTI_LINE_10_PC9
  *           @arg @ref LL_GPIO_EXTI_LINE_10_PC10
  *           @arg @ref LL_GPIO_EXTI_LINE_10_PC11
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine10(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI10_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI10    LL_GPIO_GetExitLine10
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine10(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI10_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI12    LL_GPIO_SetExitLine12
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_12_PD0
  *           @arg @ref LL_GPIO_EXTI_LINE_12_PD1
  *           @arg @ref LL_GPIO_EXTI_LINE_12_PD2
  *           @arg @ref LL_GPIO_EXTI_LINE_12_PD3
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine12(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI12_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI12    LL_GPIO_GetExitLine12
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine12(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI12_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI13    LL_GPIO_SetExitLine13
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_13_PD4
  *           @arg @ref LL_GPIO_EXTI_LINE_13_PD5
  *           @arg @ref LL_GPIO_EXTI_LINE_13_PD6
  *           @arg @ref LL_GPIO_EXTI_LINE_13_PD7
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine13(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI13_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI13    LL_GPIO_GetExitLine13
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine13(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI13_Msk));
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI14    LL_GPIO_SetExitLine14
  * @param    GPIO_Common GPIO_Common instance
  * @param    EXTIPin This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_EXTI_LINE_14_PD8
  *           @arg @ref LL_GPIO_EXTI_LINE_14_PD9
  *           @arg @ref LL_GPIO_EXTI_LINE_14_PD10
  *           @arg @ref LL_GPIO_EXTI_LINE_14_PD11
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetExitLine14(GPIO_COMMON_Type *GPIO_Common, uint32_t EXTIPin)
{
    MODIFY_REG(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI14_Msk, EXTIPin);
}

/**
  * @brief    
  * @rmtoll   EXTISEL    EXTI14    LL_GPIO_GetExitLine14
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_GPIO_GetExitLine14(GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->EXTISEL, GPIO_EXTISEL_EXTI14_Msk));
}

/**
  * @brief    
  * @rmtoll   PINWKEN    EN    LL_GPIO_IsEnabledWkup
  * @param    GPIO_Common GPIO_Common instance
  * @param    Wkupx This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_WKUP_0
  *           @arg @ref LL_GPIO_WKUP_1
  *           @arg @ref LL_GPIO_WKUP_2
  *           @arg @ref LL_GPIO_WKUP_3
  *           @arg @ref LL_GPIO_WKUP_4
  *           @arg @ref LL_GPIO_WKUP_5
  *           @arg @ref LL_GPIO_WKUP_6
  *           @arg @ref LL_GPIO_WKUP_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsEnabledWkup(GPIO_COMMON_Type *GPIO_Common, uint32_t Wkupx)
{
    return (uint32_t)(READ_BIT(GPIO_Common->PINWKEN, ((Wkupx & 0xff) << 0x0U)) == ((Wkupx & 0xff) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PINWKEN    EN    LL_GPIO_EnableWkup
  * @param    GPIO_Common GPIO_Common instance
  * @param    Wkupx This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_WKUP_0
  *           @arg @ref LL_GPIO_WKUP_1
  *           @arg @ref LL_GPIO_WKUP_2
  *           @arg @ref LL_GPIO_WKUP_3
  *           @arg @ref LL_GPIO_WKUP_4
  *           @arg @ref LL_GPIO_WKUP_5
  *           @arg @ref LL_GPIO_WKUP_6
  *           @arg @ref LL_GPIO_WKUP_7
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_EnableWkup(GPIO_COMMON_Type *GPIO_Common, uint32_t Wkupx)
{
    SET_BIT(GPIO_Common->PINWKEN, ((Wkupx & 0xff) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PINWKEN    EN    LL_GPIO_DisableWkup
  * @param    GPIO_Common GPIO_Common instance
  * @param    Wkupx This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_WKUP_0
  *           @arg @ref LL_GPIO_WKUP_1
  *           @arg @ref LL_GPIO_WKUP_2
  *           @arg @ref LL_GPIO_WKUP_3
  *           @arg @ref LL_GPIO_WKUP_4
  *           @arg @ref LL_GPIO_WKUP_5
  *           @arg @ref LL_GPIO_WKUP_6
  *           @arg @ref LL_GPIO_WKUP_7
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_DisableWkup(GPIO_COMMON_Type *GPIO_Common, uint32_t Wkupx)
{
    CLEAR_BIT(GPIO_Common->PINWKEN, ((Wkupx & 0xff) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PINWKEN    WKISEL    LL_GPIO_GetWkupEntry 
  * @param    GPIO_Common GPIO_Common instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPIO_WKUP_INT_ENTRY_NMI
  *           @arg @ref LL_GPIO_WKUP_INT_ENTRY_NUM_38
  */
__STATIC_INLINE uint32_t LL_GPIO_GetWkupEntry (GPIO_COMMON_Type *GPIO_Common)
{
    return (uint32_t)(READ_BIT(GPIO_Common->PINWKEN, GPIO_PINWKEN_WKISEL_Msk));
}

/**
  * @brief    
  * @rmtoll   PINWKEN    WKISEL    LL_GPIO_SetWkupEntry
  * @param    GPIO_Common GPIO_Common instance
  * @param    Wkupx This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_WKUP_INT_ENTRY_NMI
  *           @arg @ref LL_GPIO_WKUP_INT_ENTRY_NUM_38
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetWkupEntry(GPIO_COMMON_Type *GPIO_Common, uint32_t Wkupx)
{
    MODIFY_REG(GPIO_Common->PINWKEN, GPIO_PINWKEN_WKISEL_Msk, Wkupx);
}

/**
  * @brief    
  * @rmtoll   PINWKEN        LL_GPIO_SetWkupPolarity
  * @param    GPIO_Common GPIO_Common instance
  * @param    Wkupx This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_WKUP_0
  *           @arg @ref LL_GPIO_WKUP_1
  *           @arg @ref LL_GPIO_WKUP_2
  *           @arg @ref LL_GPIO_WKUP_3
  *           @arg @ref LL_GPIO_WKUP_4
  *           @arg @ref LL_GPIO_WKUP_5
  *           @arg @ref LL_GPIO_WKUP_6
  *           @arg @ref LL_GPIO_WKUP_7
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_WKUP_POLARITY_RISING
  *           @arg @ref LL_GPIO_WKUP_POLARITY_FALLING
  * @retval   None
  */
__STATIC_INLINE void LL_GPIO_SetWkupPolarity(GPIO_COMMON_Type *GPIO_Common, uint32_t Wkupx, uint32_t Mode)
{
    MODIFY_REG(GPIO_Common->PINWKEN, (Wkupx  * 0x100), (Wkupx * Mode));
}

/**
  * @brief    
  * @rmtoll   PINWKEN        LL_GPIO_GetWkupPolarity
  * @param    GPIO_Common GPIO_Common instance
  * @param    Wkupx This parameter can be one of the following values:
  *           @arg @ref LL_GPIO_WKUP_0
  *           @arg @ref LL_GPIO_WKUP_1
  *           @arg @ref LL_GPIO_WKUP_2
  *           @arg @ref LL_GPIO_WKUP_3
  *           @arg @ref LL_GPIO_WKUP_4
  *           @arg @ref LL_GPIO_WKUP_5
  *           @arg @ref LL_GPIO_WKUP_6
  *           @arg @ref LL_GPIO_WKUP_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_GPIO_WKUP_POLARITY_RISING
  *           @arg @ref LL_GPIO_WKUP_POLARITY_FALLING
  */
__STATIC_INLINE uint32_t LL_GPIO_GetWkupPolarity(GPIO_COMMON_Type *GPIO_Common, uint32_t Wkupx)
{
    return (uint32_t)(READ_BIT(GPIO_Common->PINWKEN, (Wkupx * 0x100)) / Wkupx);
}

/**
  * @}
  */

/** @defgroup GPIO_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_GPIO_DeInit(GPIO_Type *GPIOx);  
void LL_GPIO_StructInit(LL_GPIO_InitTypeDef *GPIO_InitStruct);
ErrorStatus LL_GPIO_Init(GPIO_Type *GPIOx, LL_GPIO_InitTypeDef *GPIO_InitStruct);
void LL_GPIO_ALLPIN_LPM_MODE(void);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_GPIO_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-09-16**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
