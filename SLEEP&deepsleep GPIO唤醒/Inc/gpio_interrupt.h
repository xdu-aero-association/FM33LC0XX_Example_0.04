/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : gpio_interrupt.h
  * @brief          : Header for gpio_interrupt.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 FMSH.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by FM under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_INTERRUPT_H
#define __GPIO_INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fm33lc0xx_ll_rcc.h"
#include "fm33lc0xx_ll_lptim.h"
#include "fm33lc0xx_ll_lpuart.h"
#include "fm33lc0xx_ll_gpio.h"
#include "fm33lc0xx_ll_uart.h"
#include "fm33lc0xx_ll_vref.h"
#include "fm33lc0xx_ll_iwdt.h"
#include "fm33lc0xx_ll_wwdt.h"
#include "fm33lc0xx_ll_pmu.h"
#include "fm33lc0xx_ll_flash.h"
#include "fm33lc0xx_ll_svd.h"
#include "fm33lc0xx_ll_aes.h"
#include "fm33lc0xx_ll_rmu.h"
#include "fm33lc0xx_ll_rng.h"
#include "fm33lc0xx_ll_opa.h"
#include "fm33lc0xx_ll_comp.h"
#include "fm33lc0xx_ll_hdiv.h"
#include "fm33lc0xx_ll_i2c.h"
#include "fm33lc0xx_ll_spi.h"
#include "fm33lc0xx_ll_u7816.h"
#include "fm33lc0xx_ll_bstim.h"
#include "fm33lc0xx_ll_gptim.h"
#include "fm33lc0xx_ll_atim.h"
#include "fm33lc0xx_ll_crc.h"
#include "fm33lc0xx_ll_dma.h"
#include "fm33lc0xx_ll_rtc.h"
#include "fm33lc0xx_ll_lcd.h"
#include "mf_config.h"


#if defined(USE_FULL_ASSERT)
#include "fm33_assert.h"
#endif /* USE_FULL_ASSERT */

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

//LINE_0 每条LINE 只能选一个引脚
#define LINE_0_GPIO    GPIOA
#define LINE_0_PIN     LL_GPIO_PIN_0
//#define LINE_0_PIN     LL_GPIO_PIN_1
//#define LINE_0_PIN     LL_GPIO_PIN_2
//#define LINE_0_PIN     LL_GPIO_PIN_3

#define LINE_0_P       (SET == LL_GPIO_IsInputPinSet(LINE_0_GPIO, LINE_0_PIN))
#define LINE_0_N       (RESET == LL_GPIO_IsInputPinSet(LINE_0_GPIO, LINE_0_PIN))

//LINE_1 每条LINE 只能选一个引脚
#define LINE_1_GPIO    GPIOA
#define LINE_1_PIN     LL_GPIO_PIN_4
//#define LINE_1_PIN     LL_GPIO_PIN_5
//#define LINE_1_PIN     LL_GPIO_PIN_6
//#define LINE_1_PIN     LL_GPIO_PIN_7

#define LINE_1_P       (SET == LL_GPIO_IsInputPinSet(LINE_1_GPIO, LINE_1_PIN))
#define LINE_1_N       (RESET == LL_GPIO_IsInputPinSet(LINE_1_GPIO, LINE_1_PIN))

//LINE_2 每条LINE 只能选一个引脚
#define LINE_2_GPIO    GPIOA
#define LINE_2_PIN     LL_GPIO_PIN_8
//#define LINE_2_PIN     LL_GPIO_PIN_9
//#define LINE_2_PIN     LL_GPIO_PIN_10
//#define LINE_2_PIN     LL_GPIO_PIN_11

#define LINE_2_P       (SET == LL_GPIO_IsInputPinSet(LINE_2_GPIO, LINE_2_PIN))
#define LINE_2_N       (RESET == LL_GPIO_IsInputPinSet(LINE_2_GPIO, LINE_2_PIN))

//LINE_3 每条LINE 只能选一个引脚
#define LINE_3_GPIO    GPIOA
#define LINE_3_PIN     LL_GPIO_PIN_12
//#define LINE_3_PIN     LL_GPIO_PIN_13
//#define LINE_3_PIN     LL_GPIO_PIN_14
//#define LINE_3_PIN     LL_GPIO_PIN_15

#define LINE_3_P       (SET == LL_GPIO_IsInputPinSet(LINE_3_GPIO, LINE_3_PIN))
#define LINE_3_N       (RESET == LL_GPIO_IsInputPinSet(LINE_3_GPIO, LINE_3_PIN))

//LINE_4 每条LINE 只能选一个引脚
#define LINE_4_GPIO    GPIOB
//#define LINE_4_PIN     LL_GPIO_PIN_0//（带usb版本芯片没有）
//#define LINE_4_PIN     LL_GPIO_PIN_1//（带usb版本芯片没有）
#define LINE_4_PIN     LL_GPIO_PIN_2
//#define LINE_4_PIN     LL_GPIO_PIN_3

#define LINE_4_P       (SET == LL_GPIO_IsInputPinSet(LINE_4_GPIO, LINE_4_PIN))
#define LINE_4_N       (RESET == LL_GPIO_IsInputPinSet(LINE_4_GPIO, LINE_4_PIN))

//LINE_5 每条LINE 只能选一个引脚
#define LINE_5_GPIO    GPIOB
//#define LINE_5_PIN     LL_GPIO_PIN_4
//#define LINE_5_PIN     LL_GPIO_PIN_5
//#define LINE_5_PIN     LL_GPIO_PIN_6
#define LINE_5_PIN     LL_GPIO_PIN_7

#define LINE_5_P       (SET == LL_GPIO_IsInputPinSet(LINE_5_GPIO, LINE_5_PIN))
#define LINE_5_N       (RESET == LL_GPIO_IsInputPinSet(LINE_5_GPIO, LINE_5_PIN))

//LINE_6 每条LINE 只能选一个引脚
#define LINE_6_GPIO    GPIOB
//#define LINE_6_PIN     LL_GPIO_PIN_8
//#define LINE_6_PIN     LL_GPIO_PIN_9
//#define LINE_6_PIN     LL_GPIO_PIN_10
#define LINE_6_PIN     LL_GPIO_PIN_11

#define LINE_6_P       (SET == LL_GPIO_IsInputPinSet(LINE_6_GPIO, LINE_6_PIN))
#define LINE_6_N       (RESET == LL_GPIO_IsInputPinSet(LINE_6_GPIO, LINE_6_PIN))

//LINE_7 每条LINE 只能选一个引脚
#define LINE_7_GPIO    GPIOB
#define LINE_7_PIN     LL_GPIO_PIN_12
//#define LINE_7_PIN     LL_GPIO_PIN_13
//#define LINE_7_PIN     LL_GPIO_PIN_14
//#define LINE_7_PIN     LL_GPIO_PIN_15//（带usb版本芯片没有）

#define LINE_7_P       (SET == LL_GPIO_IsInputPinSet(LINE_7_GPIO, LINE_7_PIN))
#define LINE_7_N       (RESET == LL_GPIO_IsInputPinSet(LINE_7_GPIO, LINE_7_PIN))

//LINE_8 每条LINE 只能选一个引脚
#define LINE_8_GPIO    GPIOC
//#define LINE_8_PIN     LL_GPIO_PIN_0
//#define LINE_8_PIN     LL_GPIO_PIN_1
//#define LINE_8_PIN     LL_GPIO_PIN_2
#define LINE_8_PIN     LL_GPIO_PIN_3

#define LINE_8_P       (SET == LL_GPIO_IsInputPinSet(LINE_8_GPIO, LINE_8_PIN))
#define LINE_8_N       (RESET == LL_GPIO_IsInputPinSet(LINE_8_GPIO, LINE_8_PIN))

//LINE_9 每条LINE 只能选一个引脚
#define LINE_9_GPIO    GPIOC
//#define LINE_9_PIN     LL_GPIO_PIN_4
//#define LINE_9_PIN     LL_GPIO_PIN_5
//#define LINE_9_PIN     LL_GPIO_PIN_6
#define LINE_9_PIN     LL_GPIO_PIN_7

#define LINE_9_P       (SET == LL_GPIO_IsInputPinSet(LINE_9_GPIO, LINE_9_PIN))
#define LINE_9_N       (RESET == LL_GPIO_IsInputPinSet(LINE_9_GPIO, LINE_9_PIN))

//LINE_10 每条LINE 只能选一个引脚
#define LINE_10_GPIO    GPIOC
//#define LINE_10_PIN     LL_GPIO_PIN_8
//#define LINE_10_PIN     LL_GPIO_PIN_9
//#define LINE_10_PIN     LL_GPIO_PIN_10
#define LINE_10_PIN     LL_GPIO_PIN_11

#define LINE_10_P       (SET == LL_GPIO_IsInputPinSet(LINE_10_GPIO, LINE_10_PIN))
#define LINE_10_N       (RESET == LL_GPIO_IsInputPinSet(LINE_10_GPIO, LINE_10_PIN))

//LINE_11 每条LINE 只能选一个引脚
#define LINE_11_GPIO    GPIOC
#define LINE_11_PIN     LL_GPIO_PIN_12

#define LINE_11_P       (SET == LL_GPIO_IsInputPinSet(LINE_11_GPIO, LINE_11_PIN))
#define LINE_11_N       (RESET == LL_GPIO_IsInputPinSet(LINE_11_GPIO, LINE_11_PIN))

//LINE_12 每条LINE 只能选一个引脚
#define LINE_12_GPIO    GPIOD
//#define LINE_12_PIN     LL_GPIO_PIN_0
//#define LINE_12_PIN     LL_GPIO_PIN_1
//#define LINE_12_PIN     LL_GPIO_PIN_2
#define LINE_12_PIN     LL_GPIO_PIN_3

#define LINE_12_P       (SET == LL_GPIO_IsInputPinSet(LINE_12_GPIO, LINE_12_PIN))
#define LINE_12_N       (RESET == LL_GPIO_IsInputPinSet(LINE_12_GPIO, LINE_12_PIN))

//LINE_13 每条LINE 只能选一个引脚
#define LINE_13_GPIO    GPIOD
#define LINE_13_PIN     LL_GPIO_PIN_4
//#define LINE_13_PIN     LL_GPIO_PIN_5
//#define LINE_13_PIN     LL_GPIO_PIN_6
//#define LINE_13_PIN     LL_GPIO_PIN_7

#define LINE_13_P       (SET == LL_GPIO_IsInputPinSet(LINE_13_GPIO, LINE_13_PIN))
#define LINE_13_N       (RESET == LL_GPIO_IsInputPinSet(LINE_13_GPIO, LINE_13_PIN))

//LINE_14 每条LINE 只能选一个引脚
#define LINE_14_GPIO    GPIOD
#define LINE_14_PIN     LL_GPIO_PIN_8
//#define LINE_14_PIN     LL_GPIO_PIN_9
//#define LINE_14_PIN     LL_GPIO_PIN_10
//#define LINE_14_PIN     LL_GPIO_PIN_11

#define LINE_14_P       (SET == LL_GPIO_IsInputPinSet(LINE_14_GPIO, LINE_14_PIN))
#define LINE_14_N       (RESET == LL_GPIO_IsInputPinSet(LINE_14_GPIO, LINE_14_PIN))

//LINE_15 每条LINE 只能选一个引脚
#define LINE_15_GPIO    GPIOD
#define LINE_15_PIN     LL_GPIO_PIN_12

#define LINE_15_P       (SET == LL_GPIO_IsInputPinSet(LINE_15_GPIO, LINE_15_PIN))
#define LINE_15_N       (RESET == LL_GPIO_IsInputPinSet(LINE_15_GPIO, LINE_15_PIN))

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void GPIO_interrupt_init(void);// 外部引脚中断初始化

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_INTERRUPT_H */

/************************ (C) COPYRIGHT FMSH *****END OF FILE****/
