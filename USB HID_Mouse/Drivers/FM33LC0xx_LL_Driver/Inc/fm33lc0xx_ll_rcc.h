/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_rcc.h
  * @author  FMSH Application Team
  * @brief   Head file of RCC LL Module
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
#ifndef __FM33LC0XX_LL_RCC_H
#define __FM33LC0XX_LL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_RCC
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup RCC_LL_ES_INIT RCC Exported Init structures
  * @{
  */

/**
  * @brief LL RCC Init Sturcture definition
  */
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Constants RCC Exported Constants
  * @{
  */
#define    LL_RCC_BUS1_CLOCK_LPTIM                                (0x1U << 0U)
#define    LL_RCC_BUS1_CLOCK_USB                                  (0x1U << 1U)
#define    LL_RCC_BUS1_CLOCK_RTC                                  (0x1U << 2U)
#define    LL_RCC_BUS1_CLOCK_PMU                                  (0x1U << 3U)
#define    LL_RCC_BUS1_CLOCK_SCU                                  (0x1U << 4U)
#define    LL_RCC_BUS1_CLOCK_IWDT                                 (0x1U << 5U)
#define    LL_RCC_BUS1_CLOCK_ANAC                                 (0x1U << 6U)
#define    LL_RCC_BUS1_CLOCK_GPIO                                 (0x1U << 7U)
#define    LL_RCC_BUS1_CLOCK_DCU                                  (0x1U << 31U)
#define    LL_RCC_BUS2_CLOCK_CRC                                  (0x1U << 0U)
#define    LL_RCC_BUS2_CLOCK_RNG                                  (0x1U << 1U)
#define    LL_RCC_BUS2_CLOCK_AES                                  (0x1U << 2U)
#define    LL_RCC_BUS2_CLOCK_LCD                                  (0x1U << 3U)
#define    LL_RCC_BUS2_CLOCK_DMA                                  (0x1U << 4U)
#define    LL_RCC_BUS2_CLOCK_FLASH                                (0x1U << 5U)
#define    LL_RCC_BUS2_CLOCK_RAMBIST                              (0x1U << 6U)
#define    LL_RCC_BUS2_CLOCK_WWDT                                 (0x1U << 7U)
#define    LL_RCC_BUS2_CLOCK_ADC                                  (0x1U << 8U)
#define    LL_RCC_BUS2_CLOCK_HDIV                                 (0x1U << 9U)
#define    LL_RCC_BUS3_CLOCK_SPI1                                 (0x1U << 0U)
#define    LL_RCC_BUS3_CLOCK_SPI2                                 (0x1U << 1U)
#define    LL_RCC_BUS3_CLOCK_UART0                                (0x1U << 8U)
#define    LL_RCC_BUS3_CLOCK_UART1                                (0x1U << 9U)
#define    LL_RCC_BUS3_CLOCK_UART4                                (0x1U << 12U)
#define    LL_RCC_BUS3_CLOCK_UART5                                (0x1U << 13U)
#define    LL_RCC_BUS3_CLOCK_UARTIR                               (0x1U << 14U)
#define    LL_RCC_BUS3_CLOCK_LPUART0                              (0x1U << 15U)
#define    LL_RCC_BUS3_CLOCK_U7816                                (0x1U << 16U)
#define    LL_RCC_BUS3_CLOCK_LPUART1                              (0x1U << 18U)
#define    LL_RCC_BUS3_CLOCK_I2C                                  (0x1U << 24U)
#define    LL_RCC_BUS4_CLOCK_BTIM                                 (0x1U << 0U)
#define    LL_RCC_BUS4_CLOCK_GTIM0                                (0x1U << 2U)
#define    LL_RCC_BUS4_CLOCK_GTIM1                                (0x1U << 3U)
#define    LL_RCC_BUS4_CLOCK_ATIM                                 (0x1U << 4U)
#define    LL_RCC_OPERATION1_CLOCK_EXTI                           (0x1U << 31U)
#define    LL_RCC_OPERATION1_CLOCK_LPUART1                        (0x1U << 29U)
#define    LL_RCC_OPERATION1_CLOCK_LPUART0                        (0x1U << 28U)
#define    LL_RCC_OPERATION1_CLOCK_I2C                            (0x1U << 20U)
#define    LL_RCC_OPERATION1_CLOCK_ATIM                           (0x1U << 15U)
#define    LL_RCC_OPERATION1_CLOCK_UART1                          (0x1U << 9U)
#define    LL_RCC_OPERATION1_CLOCK_UART0                          (0x1U << 8U)
#define    LL_RCC_OPERATION2_CLOCK_USB                            (0x1U << 23U)
#define    LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM            (0x1U << 22U)
#define    LL_RCC_OPERATION2_CLOCK_RNG                            (0x1U << 21U)
#define    LL_RCC_OPERATION2_CLOCK_ADC                            (0x1U << 20U)
#define    LL_RCC_OPERATION2_CLOCK_LPTIM                          (0x1U << 12U)
#define    LL_RCC_OPERATION2_CLOCK_BSTIM                          (0x1U << 4U)
//RESET
#define    LL_RCC_AHB_PERIPHERAL_RST_DMA                          (0x1U << 0U)
#define    LL_RCC_AHB_PERIPHERAL_RST_USB                          (0x1U << 1U)
#define    LL_RCC_APB1_PERIPHERAL_RST_UART5                       (0x1U << 31U)
#define    LL_RCC_APB1_PERIPHERAL_RST_UART4                       (0x1U << 30U)
#define    LL_RCC_APB1_PERIPHERAL_RST_GTTIM1                      (0x1U << 25U)
#define    LL_RCC_APB1_PERIPHERAL_RST_GTTIM0                      (0x1U << 24U)
#define    LL_RCC_APB1_PERIPHERAL_RST_LCD                         (0x1U << 16U)
#define    LL_RCC_APB1_PERIPHERAL_RST_U7816                       (0x1U << 14U)
#define    LL_RCC_APB1_PERIPHERAL_RST_SPI2                        (0x1U << 10U)
#define    LL_RCC_APB1_PERIPHERAL_RST_LPUART0                     (0x1U << 6U)
#define    LL_RCC_APB1_PERIPHERAL_RST_I2C                         (0x1U << 3U)
#define    LL_RCC_APB1_PERIPHERAL_RST_LPTIM                       (0x1U << 0U)
#define    LL_RCC_APB2_PERIPHERAL_RST_ATIM                        (0x1U << 31U)
#define    LL_RCC_APB2_PERIPHERAL_RST_BSTIM                       (0x1U << 28U)
#define    LL_RCC_APB2_PERIPHERAL_RST_ADC_CR                      (0x1U << 24U)
#define    LL_RCC_APB2_PERIPHERAL_RST_ADC                         (0x1U << 23U)
#define    LL_RCC_APB2_PERIPHERAL_RST_OPA                         (0x1U << 22U)
#define    LL_RCC_APB2_PERIPHERAL_RST_HDV                         (0x1U << 19U)
#define    LL_RCC_APB2_PERIPHERAL_RST_AES                         (0x1U << 18U)
#define    LL_RCC_APB2_PERIPHERAL_RST_CRC                         (0x1U << 17U)
#define    LL_RCC_APB2_PERIPHERAL_RST_RNG                         (0x1U << 16U)
#define    LL_RCC_APB2_PERIPHERAL_RST_UART1                       (0x1U << 12U)
#define    LL_RCC_APB2_PERIPHERAL_RST_UART0                       (0x1U << 11U)
#define    LL_RCC_APB2_PERIPHERAL_RST_SPI1                        (0x1U << 9U)
#define    LL_RCC_APB2_PERIPHERAL_RST_UCIR                        (0x1U << 8U)
#define    LL_RCC_APB2_PERIPHERAL_RST_LPUART1                     (0x1U << 7U)

#define    LL_RCC_APB2_DIV_1                                      (0x0U << RCC_SYSCLKCR_APBPRES2_Pos)
#define    LL_RCC_APB2_DIV_2                                      (0x4U << RCC_SYSCLKCR_APBPRES2_Pos)
#define    LL_RCC_APB2_DIV_4                                      (0x5U << RCC_SYSCLKCR_APBPRES2_Pos)
#define    LL_RCC_APB2_DIV_8                                      (0x6U << RCC_SYSCLKCR_APBPRES2_Pos)
#define    LL_RCC_APB2_DIV_16                                     (0x7U << RCC_SYSCLKCR_APBPRES2_Pos)

#define    LL_RCC_APB1_DIV_1                                      (0x0U << RCC_SYSCLKCR_APBPRES1_Pos)
#define    LL_RCC_APB1_DIV_2                                      (0x4U << RCC_SYSCLKCR_APBPRES1_Pos)
#define    LL_RCC_APB1_DIV_4                                      (0x5U << RCC_SYSCLKCR_APBPRES1_Pos)
#define    LL_RCC_APB1_DIV_8                                      (0x6U << RCC_SYSCLKCR_APBPRES1_Pos)
#define    LL_RCC_APB1_DIV_16                                     (0x7U << RCC_SYSCLKCR_APBPRES1_Pos)

#define    LL_RCC_SYSCLK_DIV_1                                    (0x0U << RCC_SYSCLKCR_AHBPRES_Pos)
#define    LL_RCC_SYSCLK_DIV_2                                    (0x4U << RCC_SYSCLKCR_AHBPRES_Pos)
#define    LL_RCC_SYSCLK_DIV_4                                    (0x5U << RCC_SYSCLKCR_AHBPRES_Pos)
#define    LL_RCC_SYSCLK_DIV_8                                    (0x6U << RCC_SYSCLKCR_AHBPRES_Pos)
#define    LL_RCC_SYSCLK_DIV_16                                   (0x7U << RCC_SYSCLKCR_AHBPRES_Pos)

#define    LL_RCC_SYSTICK_CLKSOURCE_SCLK                          (0x0U << RCC_SYSCLKCR_STCLKSEL_Pos)
#define    LL_RCC_SYSTICK_CLKSOURCE_LSCLK                         (0x1U << RCC_SYSCLKCR_STCLKSEL_Pos)
#define    LL_RCC_SYSTICK_CLKSOURCE_RC4M                          (0x2U << RCC_SYSCLKCR_STCLKSEL_Pos)
#define    LL_RCC_SYSTICK_CLKSOURCE_SYSCLK                        (0x3U << RCC_SYSCLKCR_STCLKSEL_Pos)

#define    LL_RCC_USB_CLOCK_SELECT_48M                            (0x0U << RCC_SYSCLKCR_BCKOSEL_Pos)
#define    LL_RCC_USB_CLOCK_SELECT_120M                           (0x1U << RCC_SYSCLKCR_BCKOSEL_Pos)

#define    LL_RCC_SYSTEM_CLKSOURCE_RCHF                           (0x0U << RCC_SYSCLKCR_SYSCLKSEL_Pos)
#define    LL_RCC_SYSTEM_CLKSOURCE_XTHF                           (0x1U << RCC_SYSCLKCR_SYSCLKSEL_Pos)
#define    LL_RCC_SYSTEM_CLKSOURCE_PLL                            (0x2U << RCC_SYSCLKCR_SYSCLKSEL_Pos)
#define    LL_RCC_SYSTEM_CLKSOURCE_RC4MPSC                        (0x4U << RCC_SYSCLKCR_SYSCLKSEL_Pos)
#define    LL_RCC_SYSTEM_CLKSOURCE_XTLF                           (0x5U << RCC_SYSCLKCR_SYSCLKSEL_Pos)
#define    LL_RCC_SYSTEM_CLKSOURCE_RCLP                           (0x6U << RCC_SYSCLKCR_SYSCLKSEL_Pos)
#define    LL_RCC_SYSTEM_CLKSOURCE_USBCLK                         (0x7U << RCC_SYSCLKCR_SYSCLKSEL_Pos)

#define    LL_RCC_RCHF_FREQUENCY_8MHZ                             (0x0U << RCC_RCHFCR_FSEL_Pos)
#define    LL_RCC_RCHF_FREQUENCY_16MHZ                            (0x1U << RCC_RCHFCR_FSEL_Pos)
#define    LL_RCC_RCHF_FREQUENCY_24MHZ                            (0x2U << RCC_RCHFCR_FSEL_Pos)

#define    LL_RCC_PLLSOURCE_RCHF                                  (0x0U << RCC_PLLCR_INSEL_Pos)
#define    LL_RCC_PLLSOURCE_XTHF                                  (0x1U << RCC_PLLCR_INSEL_Pos)

#define    LL_RCC_PLL_MUL_MIN                                     (0x1FU)
#define    LL_RCC_PLL_MUL_MAX                                     (0x40U)

#define    LL_RCC_PLLSOURCE_DIV1                                  (0x0U << RCC_PLLCR_REFPRSC_Pos)
#define    LL_RCC_PLLSOURCE_DIV2                                  (0x1U << RCC_PLLCR_REFPRSC_Pos)
#define    LL_RCC_PLLSOURCE_DIV4                                  (0x2U << RCC_PLLCR_REFPRSC_Pos)
#define    LL_RCC_PLLSOURCE_DIV8                                  (0x3U << RCC_PLLCR_REFPRSC_Pos)
#define    LL_RCC_PLLSOURCE_DIV12                                 (0x4U << RCC_PLLCR_REFPRSC_Pos)
#define    LL_RCC_PLLSOURCE_DIV16                                 (0x5U << RCC_PLLCR_REFPRSC_Pos)
#define    LL_RCC_PLLSOURCE_DIV24                                 (0x6U << RCC_PLLCR_REFPRSC_Pos)
#define    LL_RCC_PLLSOURCE_DIV32                                 (0x7U << RCC_PLLCR_REFPRSC_Pos)

#define    LL_RCC_PLL_DIGITAL_DOMAIN_OUTPUT_MUL_1                 (0x0U << RCC_PLLCR_OSEL_Pos)
#define    LL_RCC_PLL_DIGITAL_DOMAIN_OUTPUT_MUL_2                 (0x1U << RCC_PLLCR_OSEL_Pos)

#define    LL_RCC_RCLP_UNDER_SLEEP_OPEN                           (0x0U << RCC_LPOSCCR_LPM_LPO_OFF_Pos)
#define    LL_RCC_RCLP_UNDER_SLEEP_CLOSE                          (0x1U << RCC_LPOSCCR_LPM_LPO_OFF_Pos)

#define    LL_RCC_XTLF_BACKUP_CLOCK_SWITCH_TO_RCLP                (0x5AU << RCC_XTLFCR_BKSW_Pos)
#define    LL_RCC_XTLF_BACKUP_CLOCK_SWITCH_TO_XTLF                (0x0U << RCC_XTLFCR_BKSW_Pos)

#define    LL_RCC_XTLF_FDET_ENABLE                                (0x5U << RCC_XTLFCR_EN_Pos)
#define    LL_RCC_XTLF_FDET_DISABLE                               (0xAU << RCC_XTLFCR_EN_Pos)

#define    LL_RCC_XTLF_CURRENT_SELECT_450NA                       (0x0U << RCC_XTLFCR_IPW_Pos)
#define    LL_RCC_XTLF_CURRENT_SELECT_400NA                       (0x1U << RCC_XTLFCR_IPW_Pos)
#define    LL_RCC_XTLF_CURRENT_SELECT_350NA                       (0x2U << RCC_XTLFCR_IPW_Pos)
#define    LL_RCC_XTLF_CURRENT_SELECT_300NA                       (0x3U << RCC_XTLFCR_IPW_Pos)
#define    LL_RCC_XTLF_CURRENT_SELECT_250NA                       (0x4U << RCC_XTLFCR_IPW_Pos)
#define    LL_RCC_XTLF_CURRENT_SELECT_200NA                       (0x5U << RCC_XTLFCR_IPW_Pos)
#define    LL_RCC_XTLF_CURRENT_SELECT_150NA                       (0x6U << RCC_XTLFCR_IPW_Pos)
#define    LL_RCC_XTLF_CURRENT_SELECT_100NA                       (0x7U << RCC_XTLFCR_IPW_Pos)

#define    LL_RCC_XTHF_OSCILLA_STRENTH_WEAKEST                    (0x0U << RCC_XTHFCR_CFG_Pos)
#define    LL_RCC_XTHF_OSCILLA_STRENTH_STRONGEST                  (0x7U << RCC_XTHFCR_CFG_Pos)

#define    LL_RCC_RC4M_OUTPUT_PRESCALER_DIV1                      (0x0U << RCC_RCMFCR_PSC_Pos)
#define    LL_RCC_RC4M_OUTPUT_PRESCALER_DIV4                      (0x1U << RCC_RCMFCR_PSC_Pos)
#define    LL_RCC_RC4M_OUTPUT_PRESCALER_DIV8                      (0x2U << RCC_RCMFCR_PSC_Pos)
#define    LL_RCC_RC4M_OUTPUT_PRESCALER_DIV16                     (0x3U << RCC_RCMFCR_PSC_Pos)

#define    LL_RCC_EXTERNAL_INTERRUPT_SAMPLING_CLOCK_SELECT_LSCLK  (0x1U << RCC_OPCCR1_EXTICKS_Pos)
#define    LL_RCC_EXTERNAL_INTERRUPT_SAMPLING_CLOCK_SELECT_HCLK   (0x0U << RCC_OPCCR1_EXTICKS_Pos)

#define    LL_RCC_LPUART_OPERTION_CLOCK_SOURCE_LSCLK              (0x0U)
#define    LL_RCC_LPUART_OPERTION_CLOCK_SOURCE_RCHF               (0x1U)
#define    LL_RCC_LPUART_OPERTION_CLOCK_SOURCE_RC4M               (0x2U)


#define    LL_RCC_BEEP_OPERATION_CLOCK_SOURCE_XTLF                (0x0U << RCC_OPCCR1_BEEPCKS_Pos)
#define    LL_RCC_BEEP_OPERATION_CLOCK_SOURCE_RCLP                (0x1U << RCC_OPCCR1_BEEPCKS_Pos)

#define    LL_RCC_I2C_OPERATION_CLOCK_SOURCE_APBCLK1              (0x0U << RCC_OPCCR1_I2CCKS_Pos)
#define    LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RCHF                 (0x1U << RCC_OPCCR1_I2CCKS_Pos)
#define    LL_RCC_I2C_OPERATION_CLOCK_SOURCE_SYSCLK               (0x2U << RCC_OPCCR1_I2CCKS_Pos)
#define    LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RC4M_PSC             (0x3U << RCC_OPCCR1_I2CCKS_Pos)

#define    LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_APBCLK2            (0x0U << RCC_OPCCR1_ATCKS_Pos)
#define    LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_USBPHYBCK120M      (0x1U << RCC_OPCCR1_ATCKS_Pos)
#define    LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_PLLx2              (0x3U << RCC_OPCCR1_ATCKS_Pos)

#define    LL_RCC_UART_OPERATION_CLOCK_SOURCE_APBCLK1             (0x0U)
#define    LL_RCC_UART_OPERATION_CLOCK_SOURCE_RCHF                (0x1U)
#define    LL_RCC_UART_OPERATION_CLOCK_SOURCE_SYSCLK              (0x3U)
#define    LL_RCC_UART_OPERATION_CLOCK_SOURCE_RC4M_PSC            (0x4U)

#define    LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV1              (0x0U << RCC_OPCCR2_RNGPRSC_Pos)
#define    LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV2              (0x1U << RCC_OPCCR2_RNGPRSC_Pos)
#define    LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV4              (0x2U << RCC_OPCCR2_RNGPRSC_Pos)
#define    LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV8              (0x3U << RCC_OPCCR2_RNGPRSC_Pos)
#define    LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV16             (0x4U << RCC_OPCCR2_RNGPRSC_Pos)
#define    LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV32             (0x5U << RCC_OPCCR2_RNGPRSC_Pos)

#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV1              (0x0U << RCC_OPCCR2_ADCPRSC_Pos)
#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV2              (0x1U << RCC_OPCCR2_ADCPRSC_Pos)
#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV4              (0x2U << RCC_OPCCR2_ADCPRSC_Pos)
#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV8              (0x3U << RCC_OPCCR2_ADCPRSC_Pos)
#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV16             (0x4U << RCC_OPCCR2_ADCPRSC_Pos)
#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV32             (0x5U << RCC_OPCCR2_ADCPRSC_Pos)

#define    LL_RCC_USB_OPERATION_CLOCK_PRESCALLER_XTLF             (0x0U << RCC_OPCCR2_USBCKS_Pos)
#define    LL_RCC_USB_OPERATION_CLOCK_PRESCALLER_XTHF             (0x1U << RCC_OPCCR2_USBCKS_Pos)

#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RC4M_PSC         (0x0U << RCC_OPCCR2_ADCCKS_Pos)
#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RCHF             (0x1U << RCC_OPCCR2_ADCCKS_Pos)
#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_XTHF             (0x2U << RCC_OPCCR2_ADCCKS_Pos)
#define    LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_PLL              (0x3U << RCC_OPCCR2_ADCCKS_Pos)

#define    LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_APBCLK1            (0x0U << RCC_OPCCR2_LPTCKS_Pos)
#define    LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_LSCLK              (0x1U << RCC_OPCCR2_LPTCKS_Pos)
#define    LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_RCLP               (0x2U << RCC_OPCCR2_LPTCKS_Pos)
#define    LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_RC4M_PSC           (0x3U << RCC_OPCCR2_LPTCKS_Pos)

#define    LL_RCC_BSTIM_OPERATION_CLK_SOURCE_APBCLK2              (0x0U << RCC_OPCCR2_BTCKS_Pos)
#define    LL_RCC_BSTIM_OPERATION_CLK_SOURCE_LSCLK                (0x1U << RCC_OPCCR2_BTCKS_Pos)
#define    LL_RCC_BSTIM_OPERATION_CLK_SOURCE_RCLP                 (0x2U << RCC_OPCCR2_BTCKS_Pos)
#define    LL_RCC_BSTIM_OPERATION_CLK_SOURCE_RC4M_PSC             (0x3U << RCC_OPCCR2_BTCKS_Pos)

#define    LL_RCC_AHB_MASTER_PRIORITY_DMA_FIRST                   (0x0U << RCC_AHBMCR_MPRIL_Pos)
#define    LL_RCC_AHB_MASTER_PRIORITY_CPU_FIRST                   (0x1U << RCC_AHBMCR_MPRIL_Pos)

#define    LL_RCC_LSCLK_SELECT_RCLP                               (0x55U << RCC_LSCLKSEL_SEL_Pos)
#define    LL_RCC_LSCLK_SELECT_XTLF                               (0xAAU << RCC_LSCLKSEL_SEL_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Functions RCC Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   IER    HFDET_IE    LL_RCC_EnableIT_XTHF_Fail
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_EnableIT_XTHF_Fail(void)
{
    SET_BIT(FDET->IER, FDET_IER_HFDET_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    HFDET_IE    LL_RCC_IsEnabledIT_XTHF_Fail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_XTHF_Fail(void)
{
    return (uint32_t)(READ_BIT(FDET->IER, FDET_IER_HFDET_IE_Msk) == FDET_IER_HFDET_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    HFDET_IE    LL_RCC_DisableIT_XTHF_Fail
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_DisableIT_XTHF_Fail(void)
{
    CLEAR_BIT(FDET->IER, FDET_IER_HFDET_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    LFDET_IE    LL_RCC_EnableIT_XTLF_Fail
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_EnableIT_XTLF_Fail(void)
{
    SET_BIT(FDET->IER, FDET_IER_LFDET_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    LFDET_IE    LL_RCC_IsEnabledIT_XTLF_Fail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_XTLF_Fail(void)
{
    return (uint32_t)(READ_BIT(FDET->IER, FDET_IER_LFDET_IE_Msk) == FDET_IER_LFDET_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    LFDET_IE    LL_RCC_DisableIT_XTLF_Fail
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_DisableIT_XTLF_Fail(void)
{
    CLEAR_BIT(FDET->IER, FDET_IER_LFDET_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    HFDETO    LL_RCC_IsActiveFlag_XTHF_Vibrating
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_XTHF_Vibrating(void)
{
    return (uint32_t)(READ_BIT(FDET->ISR, FDET_ISR_HFDETO_Msk) == (FDET_ISR_HFDETO_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    LFDETO    LL_RCC_IsActiveFlag_XTLF_Vibrating
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_XTLF_Vibrating(void)
{
    return (uint32_t)(READ_BIT(FDET->ISR, FDET_ISR_LFDETO_Msk) == (FDET_ISR_LFDETO_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    HFDETIF    LL_RCC_IsActiveFlag_XTHF_Fail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_XTHF_Fail(void)
{
    return (uint32_t)(READ_BIT(FDET->ISR, FDET_ISR_HFDETIF_Msk) == (FDET_ISR_HFDETIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    HFDETIF    LL_RCC_ClearFlag_XTHF_Fail
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_XTHF_Fail(void)
{
    WRITE_REG(FDET->ISR, FDET_ISR_HFDETIF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    LFDETIF    LL_RCC_IsActiveFlag_XTLF_Fail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_XTLF_Fail(void)
{
    return (uint32_t)(READ_BIT(FDET->ISR, FDET_ISR_LFDETIF_Msk) == (FDET_ISR_LFDETIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    LFDETIF    LL_RCC_ClearFlag_XTLF_Fail
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_XTLF_Fail(void)
{
    WRITE_REG(FDET->ISR, FDET_ISR_LFDETIF_Msk);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    LSCATS    LL_RCC_Enable_LSCLK_AutoSwitch
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Enable_LSCLK_AutoSwitch(void)
{
    SET_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_LSCATS_Msk);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    LSCATS    LL_RCC_IsEnabled_LSCLK_AutoSwitch
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabled_LSCLK_AutoSwitch(void)
{
    return (uint32_t)(READ_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_LSCATS_Msk) == RCC_SYSCLKCR_LSCATS_Msk);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    LSCATS    LL_RCC_Disable_LSCLK_AutoSwitch
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Disable_LSCLK_AutoSwitch(void)
{
    CLEAR_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_LSCATS_Msk);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    LL_RCC_Enable_SleepmodeExternalInterrupt
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Enable_SleepmodeExternalInterrupt(void)
{
    SET_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    LL_RCC_IsEnabled_SleepmodeExternalInterrupt
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabled_SleepmodeExternalInterrupt(void)
{
    return (uint32_t)(READ_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_SLP_ENEXTI_Msk) == RCC_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    LL_RCC_Disable_SleepmodeExternalInterrupt
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Disable_SleepmodeExternalInterrupt(void)
{
    CLEAR_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    APBPRES2    LL_RCC_SetAPB2Prescaler
  * @param    Prescaler This parameter can be one of the following values:
  *           @arg @ref LL_RCC_APB2_DIV_1
  *           @arg @ref LL_RCC_APB2_DIV_2
  *           @arg @ref LL_RCC_APB2_DIV_4
  *           @arg @ref LL_RCC_APB2_DIV_8
  *           @arg @ref LL_RCC_APB2_DIV_16
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetAPB2Prescaler(uint32_t Prescaler)
{
    MODIFY_REG(RCC->SYSCLKCR, RCC_SYSCLKCR_APBPRES2_Msk, Prescaler);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    APBPRES2    LL_RCC_GetAPB2Prescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_APB2_DIV_1
  *           @arg @ref LL_RCC_APB2_DIV_2
  *           @arg @ref LL_RCC_APB2_DIV_4
  *           @arg @ref LL_RCC_APB2_DIV_8
  *           @arg @ref LL_RCC_APB2_DIV_16
  */
__STATIC_INLINE uint32_t LL_RCC_GetAPB2Prescaler(void)
{
    return (uint32_t)(READ_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_APBPRES2_Msk));
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    APBPRES1    LL_RCC_SetAPB1Prescaler
  * @param    Prescaler This parameter can be one of the following values:
  *           @arg @ref LL_RCC_APB1_DIV_1
  *           @arg @ref LL_RCC_APB1_DIV_2
  *           @arg @ref LL_RCC_APB1_DIV_4
  *           @arg @ref LL_RCC_APB1_DIV_8
  *           @arg @ref LL_RCC_APB1_DIV_16
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetAPB1Prescaler(uint32_t Prescaler)
{
    MODIFY_REG(RCC->SYSCLKCR, RCC_SYSCLKCR_APBPRES1_Msk, Prescaler);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    APBPRES1    LL_RCC_GetAPB1Prescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_APB1_DIV_1
  *           @arg @ref LL_RCC_APB1_DIV_2
  *           @arg @ref LL_RCC_APB1_DIV_4
  *           @arg @ref LL_RCC_APB1_DIV_8
  *           @arg @ref LL_RCC_APB1_DIV_16
  */
__STATIC_INLINE uint32_t LL_RCC_GetAPB1Prescaler(void)
{
    return (uint32_t)(READ_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_APBPRES1_Msk));
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    AHBPRES    LL_RCC_SetAHBPrescaler
  * @param    Prescaler This parameter can be one of the following values:
  *           @arg @ref LL_RCC_SYSCLK_DIV_1
  *           @arg @ref LL_RCC_SYSCLK_DIV_2
  *           @arg @ref LL_RCC_SYSCLK_DIV_4
  *           @arg @ref LL_RCC_SYSCLK_DIV_8
  *           @arg @ref LL_RCC_SYSCLK_DIV_16
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetAHBPrescaler(uint32_t Prescaler)
{
    MODIFY_REG(RCC->SYSCLKCR, RCC_SYSCLKCR_AHBPRES_Msk, Prescaler);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    AHBPRES    LL_RCC_GetAHBPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_SYSCLK_DIV_1
  *           @arg @ref LL_RCC_SYSCLK_DIV_2
  *           @arg @ref LL_RCC_SYSCLK_DIV_4
  *           @arg @ref LL_RCC_SYSCLK_DIV_8
  *           @arg @ref LL_RCC_SYSCLK_DIV_16
  */
__STATIC_INLINE uint32_t LL_RCC_GetAHBPrescaler(void)
{
    return (uint32_t)(READ_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_AHBPRES_Msk));
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    STCLKSEL    LL_RCC_SetSystickClockSource
  * @param    SystickSource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_SYSTICK_CLKSOURCE_SCLK
  *           @arg @ref LL_RCC_SYSTICK_CLKSOURCE_LSCLK
  *           @arg @ref LL_RCC_SYSTICK_CLKSOURCE_RC4M
  *           @arg @ref LL_RCC_SYSTICK_CLKSOURCE_SYSCLK
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetSystickClockSource(uint32_t SystickSource)
{
    MODIFY_REG(RCC->SYSCLKCR, RCC_SYSCLKCR_STCLKSEL_Msk, SystickSource);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    STCLKSEL    LL_RCC_GetSystickClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_SYSTICK_CLKSOURCE_SCLK
  *           @arg @ref LL_RCC_SYSTICK_CLKSOURCE_LSCLK
  *           @arg @ref LL_RCC_SYSTICK_CLKSOURCE_RC4M
  *           @arg @ref LL_RCC_SYSTICK_CLKSOURCE_SYSCLK
  */
__STATIC_INLINE uint32_t LL_RCC_GetSystickClockSource(void)
{
    return (uint32_t)(READ_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_STCLKSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    BCKOSEL    LL_RCC_SetUSBClockSource
  * @param    Source This parameter can be one of the following values:
  *           @arg @ref LL_RCC_USB_CLOCK_SELECT_48M
  *           @arg @ref LL_RCC_USB_CLOCK_SELECT_120M
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetUSBClockSource(uint32_t Source)
{
    MODIFY_REG(RCC->SYSCLKCR, RCC_SYSCLKCR_BCKOSEL_Msk, Source);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    BCKOSEL    LL_RCC_GetUSBClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_USB_CLOCK_SELECT_48M
  *           @arg @ref LL_RCC_USB_CLOCK_SELECT_120M
  */
__STATIC_INLINE uint32_t LL_RCC_GetUSBClockSource(void)
{
    return (uint32_t)(READ_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_BCKOSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    SYSCLKSEL    LL_RCC_SetSystemClockSource
  * @param    SystickSource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_RCHF
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_XTHF
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_PLL
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_RC4MPSC
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_XTLF
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_RCLP
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_USBCLK
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetSystemClockSource(uint32_t SystickSource)
{
    MODIFY_REG(RCC->SYSCLKCR, RCC_SYSCLKCR_SYSCLKSEL_Msk, SystickSource);
}

/**
  * @brief    
  * @rmtoll   SYSCLKCR    SYSCLKSEL    LL_RCC_GetSystemClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_RCHF
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_XTHF
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_PLL
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_RC4MPSC
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_XTLF
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_RCLP
  *           @arg @ref LL_RCC_SYSTEM_CLKSOURCE_USBCLK
  */
__STATIC_INLINE uint32_t LL_RCC_GetSystemClockSource(void)
{
    return (uint32_t)(READ_BIT(RCC->SYSCLKCR, RCC_SYSCLKCR_SYSCLKSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   RCHFCR    FSEL    LL_RCC_SetRCHFFrequency
  * @param    Freq This parameter can be one of the following values:
  *           @arg @ref LL_RCC_RCHF_FREQUENCY_8MHZ
  *           @arg @ref LL_RCC_RCHF_FREQUENCY_16MHZ
  *           @arg @ref LL_RCC_RCHF_FREQUENCY_24MHZ
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetRCHFFrequency(uint32_t Freq)
{
    MODIFY_REG(RCC->RCHFCR, RCC_RCHFCR_FSEL_Msk, Freq);
}

/**
  * @brief    
  * @rmtoll   RCHFCR    FSEL    LL_RCC_GetRCHFFrequency
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_RCHF_FREQUENCY_8MHZ
  *           @arg @ref LL_RCC_RCHF_FREQUENCY_16MHZ
  *           @arg @ref LL_RCC_RCHF_FREQUENCY_24MHZ
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCHFFrequency(void)
{
    return (uint32_t)(READ_BIT(RCC->RCHFCR, RCC_RCHFCR_FSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   RCHFCR    EN    LL_RCC_Enable_RCHF
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Enable_RCHF(void)
{
    SET_BIT(RCC->RCHFCR, RCC_RCHFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   RCHFCR    EN    LL_RCC_IsEnabled_RCHF
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabled_RCHF(void)
{
    return (uint32_t)(READ_BIT(RCC->RCHFCR, RCC_RCHFCR_EN_Msk) == RCC_RCHFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   RCHFCR    EN    LL_RCC_Disable_RCHF
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Disable_RCHF(void)
{
    CLEAR_BIT(RCC->RCHFCR, RCC_RCHFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   RCMFTR    TRIM    LL_RCC_SetRC4MTrimValue
  * @param    TrimValue TrimValue The value of RC4M trim
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetRC4MTrimValue(uint32_t TrimValue)
{
    MODIFY_REG(RCC->RCMFTR, (0x7FU << 0U), (TrimValue << 0U));
}

/**
  * @brief    
  * @rmtoll   RCMFTR    TRIM    LL_RCC_GetRC4MTrimValue
  * @retval   The Value of RC4M trim
  */
__STATIC_INLINE uint32_t LL_RCC_GetRC4MTrimValue(void)
{
    return (uint32_t)(READ_BIT(RCC->RCMFTR, 0x7FU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   PLLCR    EN    LL_RCC_PLL_Enable
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_PLL_Enable(void)
{
    SET_BIT(RCC->PLLCR, RCC_PLLCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   PLLCR    EN    LL_RCC_PLL_Disable
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_PLL_Disable(void)
{
    CLEAR_BIT(RCC->PLLCR, RCC_PLLCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   PLLCR    EN    LL_RCC_PLL_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_PLL_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(RCC->PLLCR, RCC_PLLCR_EN_Msk) == RCC_PLLCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   PLLCR    LOCKED    LL_RCC_PLL_IsReady
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_PLL_IsReady(void)
{
    return (uint32_t)(READ_BIT(RCC->PLLCR, RCC_PLLCR_LOCKED_Msk) == (RCC_PLLCR_LOCKED_Msk));
}

/**
  * @brief    
  * @rmtoll   PLLCR    INSEL    LL_RCC_SetPLLSource
  * @param    PllSource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_PLLSOURCE_RCHF
  *           @arg @ref LL_RCC_PLLSOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetPLLSource(uint32_t PllSource)
{
    MODIFY_REG(RCC->PLLCR, RCC_PLLCR_INSEL_Msk, PllSource);
}

/**
  * @brief    
  * @rmtoll   PLLCR    INSEL    LL_RCC_GetPLLSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_PLLSOURCE_RCHF
  *           @arg @ref LL_RCC_PLLSOURCE_XTHF
  */
__STATIC_INLINE uint32_t LL_RCC_GetPLLSource(void)
{
    return (uint32_t)(READ_BIT(RCC->PLLCR, RCC_PLLCR_INSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   PLLCR    DB    LL_RCC_SetPLLMultiplier
  * @param    PLLMul This parameter can be Between parameters of the following values:
  *           @arg @ref LL_RCC_PLL_MUL_MIN
  *           @arg @ref LL_RCC_PLL_MUL_MAX
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetPLLMultiplier(uint32_t PLLMul)
{
    MODIFY_REG(RCC->PLLCR, RCC_PLLCR_DB_Msk, PLLMul << RCC_PLLCR_DB_Pos);
}

/**
  * @brief    
  * @rmtoll   PLLCR    DB    LL_RCC_GetPLLMultiplier
  * @retval   Returned value can be Between parameters of the following values:
  *           @arg @ref LL_RCC_PLL_MUL_MIN
  *           @arg @ref LL_RCC_PLL_MUL_MAX
  */
__STATIC_INLINE uint32_t LL_RCC_GetPLLMultiplier(void)
{
    return (uint32_t)(READ_BIT(RCC->PLLCR, RCC_PLLCR_DB_Msk) >> RCC_PLLCR_DB_Pos);
}

/**
  * @brief    
  * @rmtoll   PLLCR    REFPRSC    LL_RCC_SetPLLPrescaler
  * @param    PLLDiv This parameter can be one of the following values:
  *           @arg @ref LL_RCC_PLLSOURCE_DIV1
  *           @arg @ref LL_RCC_PLLSOURCE_DIV2
  *           @arg @ref LL_RCC_PLLSOURCE_DIV4
  *           @arg @ref LL_RCC_PLLSOURCE_DIV8
  *           @arg @ref LL_RCC_PLLSOURCE_DIV12
  *           @arg @ref LL_RCC_PLLSOURCE_DIV16
  *           @arg @ref LL_RCC_PLLSOURCE_DIV24
  *           @arg @ref LL_RCC_PLLSOURCE_DIV32
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetPLLPrescaler(uint32_t PLLDiv)
{
    MODIFY_REG(RCC->PLLCR, RCC_PLLCR_REFPRSC_Msk, PLLDiv);
}

/**
  * @brief    
  * @rmtoll   PLLCR    REFPRSC    LL_RCC_GetPLLPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_PLLSOURCE_DIV1
  *           @arg @ref LL_RCC_PLLSOURCE_DIV2
  *           @arg @ref LL_RCC_PLLSOURCE_DIV4
  *           @arg @ref LL_RCC_PLLSOURCE_DIV8
  *           @arg @ref LL_RCC_PLLSOURCE_DIV12
  *           @arg @ref LL_RCC_PLLSOURCE_DIV16
  *           @arg @ref LL_RCC_PLLSOURCE_DIV24
  *           @arg @ref LL_RCC_PLLSOURCE_DIV32
  */
__STATIC_INLINE uint32_t LL_RCC_GetPLLPrescaler(void)
{
    return (uint32_t)(READ_BIT(RCC->PLLCR, RCC_PLLCR_REFPRSC_Msk));
}

/**
  * @brief    
  * @rmtoll   PLLCR    OSEL    LL_RCC_SetPLLDigitalDomainOutput
  * @param    DigitalDomainOutput This parameter can be one of the following values:
  *           @arg @ref LL_RCC_PLL_DIGITAL_DOMAIN_OUTPUT_MUL_1
  *           @arg @ref LL_RCC_PLL_DIGITAL_DOMAIN_OUTPUT_MUL_2
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetPLLDigitalDomainOutput(uint32_t DigitalDomainOutput)
{
    MODIFY_REG(RCC->PLLCR, RCC_PLLCR_OSEL_Msk, DigitalDomainOutput);
}

/**
  * @brief    
  * @rmtoll   PLLCR    OSEL    LL_RCC_GetPLLDigitalDomainOutput
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_PLL_DIGITAL_DOMAIN_OUTPUT_MUL_1
  *           @arg @ref LL_RCC_PLL_DIGITAL_DOMAIN_OUTPUT_MUL_2
  */
__STATIC_INLINE uint32_t LL_RCC_GetPLLDigitalDomainOutput(void)
{
    return (uint32_t)(READ_BIT(RCC->PLLCR, RCC_PLLCR_OSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   PLLCR    OSEL    LL_RCC_GetPLLDigitalDomainOutput
  * @param    Source This parameter can be one of the following values:
  *           @arg @ref LL_RCC_PLLSOURCE_RCHF
  *           @arg @ref LL_RCC_PLLSOURCE_XTHF
  * @param    PLL_R This parameter can be one of the following values:
  *           @arg @ref LL_RCC_PLLSOURCE_DIV1
  *           @arg @ref LL_RCC_PLLSOURCE_DIV2
  *           @arg @ref LL_RCC_PLLSOURCE_DIV4
  *           @arg @ref LL_RCC_PLLSOURCE_DIV8
  *           @arg @ref LL_RCC_PLLSOURCE_DIV12
  *           @arg @ref LL_RCC_PLLSOURCE_DIV16
  *           @arg @ref LL_RCC_PLLSOURCE_DIV24
  *           @arg @ref LL_RCC_PLLSOURCE_DIV32
  * @param    PLL_DB This parameter can be Between parameters of the following values:
  *           @arg @ref LL_RCC_PLL_MUL_MIN
  *           @arg @ref LL_RCC_PLL_MUL_MAX

  * @param    PLL_O This parameter can be one of the following values:
  *           @arg @ref LL_RCC_PLL_DIGITAL_DOMAIN_OUTPUT_MUL_1
  *           @arg @ref LL_RCC_PLL_DIGITAL_DOMAIN_OUTPUT_MUL_2
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_PLL_ConfigDomain_SYS(uint32_t Source, uint32_t PLL_R, uint32_t PLL_DB, uint32_t PLL_O)
{
  MODIFY_REG(RCC->PLLCR, RCC_PLLCR_DB_Msk | RCC_PLLCR_REFPRSC_Msk | RCC_PLLCR_OSEL_Msk | RCC_PLLCR_INSEL_Msk,
             (PLL_DB << RCC_PLLCR_DB_Pos) | PLL_R | PLL_O | Source);
}

/**
  * @brief    
  * @rmtoll   LPOSCCR    LPOENB    LL_RCC_IsActiveFlag_RCLP_Enable
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_RCLP_Enable(void)
{
    return (uint32_t)(READ_BIT(RCC->LPOSCCR, RCC_LPOSCCR_LPOENB_Msk) == (RCC_LPOSCCR_LPOENB_Msk));
}

/**
  * @brief    
  * @rmtoll   LPOSCCR    LPM_LPO_OFF    LL_RCC_SetSleepModeRCLPWorkMode
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_RCC_RCLP_UNDER_SLEEP_OPEN
  *           @arg @ref LL_RCC_RCLP_UNDER_SLEEP_CLOSE
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetSleepModeRCLPWorkMode(uint32_t mode)
{
    MODIFY_REG(RCC->LPOSCCR, RCC_LPOSCCR_LPM_LPO_OFF_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   LPOSCCR    LPM_LPO_OFF    LL_RCC_GetSleepModeRCLPWorkMode
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_RCLP_UNDER_SLEEP_OPEN
  *           @arg @ref LL_RCC_RCLP_UNDER_SLEEP_CLOSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetSleepModeRCLPWorkMode(void)
{
    return (uint32_t)(READ_BIT(RCC->LPOSCCR, RCC_LPOSCCR_LPM_LPO_OFF_Msk));
}

/**
  * @brief    
  * @rmtoll   LPOSCCR    LPO_CHOP_EN    LL_RCC_Enabled_RCLPChopper
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Enabled_RCLPChopper(void)
{
    SET_BIT(RCC->LPOSCCR, RCC_LPOSCCR_LPO_CHOP_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   LPOSCCR    LPO_CHOP_EN    LL_RCC_IsEnabled_RCLPChopper
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabled_RCLPChopper(void)
{
    return (uint32_t)(READ_BIT(RCC->LPOSCCR, RCC_LPOSCCR_LPO_CHOP_EN_Msk) == RCC_LPOSCCR_LPO_CHOP_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   LPOSCCR    LPO_CHOP_EN    LL_RCC_Disabled_RCLPChopper
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Disabled_RCLPChopper(void)
{
    CLEAR_BIT(RCC->LPOSCCR, RCC_LPOSCCR_LPO_CHOP_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   LPOSCTR    TRIM    LL_RCC_SetRCLPTRIM
  * @param    TrimValue TrimValue The value of RCLP trim
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetRCLPTRIM(uint32_t TrimValue)
{
    MODIFY_REG(RCC->LPOSCTR, (0xFFU << 0U), (TrimValue << 0U));
}

/**
  * @brief    
  * @rmtoll   LPOSCTR    TRIM    LL_RCC_GetRCLPTRIM
  * @retval   The Value of RCLP trim
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCLPTRIM(void)
{
    return (uint32_t)(READ_BIT(RCC->LPOSCTR, 0xFFU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   XTLFCR    EN    LL_RCC_Enable_XTLF
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Enable_XTLF(void)
{
    MODIFY_REG(RCC->XTLFCR, RCC_XTLFCR_EN_Msk, LL_RCC_XTLF_FDET_ENABLE);
}

/**
  * @brief    
  * @rmtoll   XTLFCR    EN    LL_RCC_Disable_XTLF
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Disable_XTLF(void)
{ 
    MODIFY_REG(RCC->XTLFCR, RCC_XTLFCR_EN_Msk, LL_RCC_XTLF_FDET_DISABLE);
}
/**
  * @brief    
  * @rmtoll   XTLFCR    IPW    LL_RCC_SetXTLFCurrent
  * @param    CurrentValue This parameter can be one of the following values:
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_450NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_400NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_350NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_300NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_250NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_200NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_150NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_100NA
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetXTLFCurrent(uint32_t CurrentValue)
{
    MODIFY_REG(RCC->XTLFCR, RCC_XTLFCR_IPW_Msk, CurrentValue);
}

/**
  * @brief    
  * @rmtoll   XTLFCR    IPW    LL_RCC_GetXTLFCurrent
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_450NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_400NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_350NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_300NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_250NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_200NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_150NA
  *           @arg @ref LL_RCC_XTLF_CURRENT_SELECT_100NA
  */
__STATIC_INLINE uint32_t LL_RCC_GetXTLFCurrent(void)
{
    return (uint32_t)(READ_BIT(RCC->XTLFCR, RCC_XTLFCR_IPW_Msk));
}

/**
  * @brief    
  * @rmtoll   XTHFCR    CFG    LL_RCC_SetXTHFOscilaStrenth
  * @param    OscilaStrenth This parameter can be one of the following values:
  *           @arg @ref LL_RCC_XTHF_OSCILLA_STRENTH_WEAKEST
  *           @arg @ref LL_RCC_XTHF_OSCILLA_STRENTH_STRONGEST
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetXTHFOscilaStrenth(uint32_t OscilaStrenth)
{
    MODIFY_REG(RCC->XTHFCR, RCC_XTHFCR_CFG_Msk, OscilaStrenth);
}

/**
  * @brief    
  * @rmtoll   XTHFCR    CFG    LL_RCC_GetXTHFOscilaStrenth
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_XTHF_OSCILLA_STRENTH_WEAKEST
  *           @arg @ref LL_RCC_XTHF_OSCILLA_STRENTH_STRONGEST
  */
__STATIC_INLINE uint32_t LL_RCC_GetXTHFOscilaStrenth(void)
{
    return (uint32_t)(READ_BIT(RCC->XTHFCR, RCC_XTHFCR_CFG_Msk));
}

/**
  * @brief    
  * @rmtoll   XTHFCR    EN    LL_RCC_XTHF_Enable
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_XTHF_Enable(void)
{
    SET_BIT(RCC->XTHFCR, RCC_XTHFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   XTHFCR    EN    LL_RCC_XTHF_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_XTHF_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(RCC->XTHFCR, RCC_XTHFCR_EN_Msk) == RCC_XTHFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   XTHFCR    EN    LL_RCC_XTHF_Disable
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_XTHF_Disable(void)
{
    CLEAR_BIT(RCC->XTHFCR, RCC_XTHFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   RCMFCR    PSC    LL_RCC_SetRC4MOutputPrescaler
  * @param    Prescaler This parameter can be one of the following values:
  *           @arg @ref LL_RCC_RC4M_OUTPUT_PRESCALER_DIV1
  *           @arg @ref LL_RCC_RC4M_OUTPUT_PRESCALER_DIV4
  *           @arg @ref LL_RCC_RC4M_OUTPUT_PRESCALER_DIV8
  *           @arg @ref LL_RCC_RC4M_OUTPUT_PRESCALER_DIV16
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetRC4MOutputPrescaler(uint32_t Prescaler)
{
    MODIFY_REG(RCC->RCMFCR, RCC_RCMFCR_PSC_Msk, Prescaler);
}

/**
  * @brief    
  * @rmtoll   RCMFCR    PSC    LL_RCC_GetRC4MOutputPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_RC4M_OUTPUT_PRESCALER_DIV1
  *           @arg @ref LL_RCC_RC4M_OUTPUT_PRESCALER_DIV4
  *           @arg @ref LL_RCC_RC4M_OUTPUT_PRESCALER_DIV8
  *           @arg @ref LL_RCC_RC4M_OUTPUT_PRESCALER_DIV16
  */
__STATIC_INLINE uint32_t LL_RCC_GetRC4MOutputPrescaler(void)
{
    return (uint32_t)(READ_BIT(RCC->RCMFCR, RCC_RCMFCR_PSC_Msk));
}

/**
  * @brief    
  * @rmtoll   RCMFCR    EN    LL_RCC_RC4M_Enable
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_RC4M_Enable(void)
{
    SET_BIT(RCC->RCMFCR, RCC_RCMFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   RCMFCR    EN    LL_RCC_RC4M_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_RC4M_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(RCC->RCMFCR, RCC_RCMFCR_EN_Msk) == RCC_RCMFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   RCMFCR    EN    LL_RCC_RC4M_Disable
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_RC4M_Disable(void)
{
    CLEAR_BIT(RCC->RCMFCR, RCC_RCMFCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   RCHFTR    TRIM    LL_RCC_SetRCHFTrimValue
  * @param    TrimValue TrimValue The value of RCHF trim
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetRCHFTrimValue(uint32_t TrimValue)
{
    MODIFY_REG(RCC->RCHFTR, (0x7FU << 0U), (TrimValue << 0U));
}

/**
  * @brief    
  * @rmtoll   RCHFTR    TRIM    LL_RCC_GetRCHFTrimValue
  * @retval   The value of RCHF trim
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCHFTrimValue(void)
{
    return (uint32_t)(READ_BIT(RCC->RCHFTR, 0x7FU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   PCLKCR1        LL_RCC_Group1_EnableBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS1_CLOCK_LPTIM
  *           @arg @ref LL_RCC_BUS1_CLOCK_USB
  *           @arg @ref LL_RCC_BUS1_CLOCK_RTC
  *           @arg @ref LL_RCC_BUS1_CLOCK_PMU
  *           @arg @ref LL_RCC_BUS1_CLOCK_SCU
  *           @arg @ref LL_RCC_BUS1_CLOCK_IWDT
  *           @arg @ref LL_RCC_BUS1_CLOCK_ANAC
  *           @arg @ref LL_RCC_BUS1_CLOCK_GPIO
  *           @arg @ref LL_RCC_BUS1_CLOCK_DCU
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group1_EnableBusClock(uint32_t Peripheral)
{
    SET_BIT(RCC->PCLKCR1, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR2        LL_RCC_Group2_EnableBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS2_CLOCK_CRC
  *           @arg @ref LL_RCC_BUS2_CLOCK_RNG
  *           @arg @ref LL_RCC_BUS2_CLOCK_AES
  *           @arg @ref LL_RCC_BUS2_CLOCK_LCD
  *           @arg @ref LL_RCC_BUS2_CLOCK_DMA
  *           @arg @ref LL_RCC_BUS2_CLOCK_FLASH
  *           @arg @ref LL_RCC_BUS2_CLOCK_RAMBIST
  *           @arg @ref LL_RCC_BUS2_CLOCK_WWDT
  *           @arg @ref LL_RCC_BUS2_CLOCK_ADC
  *           @arg @ref LL_RCC_BUS2_CLOCK_HDIV
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group2_EnableBusClock(uint32_t Peripheral)
{
    SET_BIT(RCC->PCLKCR2, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR3        LL_RCC_Group3_EnableBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS3_CLOCK_SPI1
  *           @arg @ref LL_RCC_BUS3_CLOCK_SPI2
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART0
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART1
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART4
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART5
  *           @arg @ref LL_RCC_BUS3_CLOCK_UARTIR
  *           @arg @ref LL_RCC_BUS3_CLOCK_LPUART0
  *           @arg @ref LL_RCC_BUS3_CLOCK_U7816
  *           @arg @ref LL_RCC_BUS3_CLOCK_LPUART1
  *           @arg @ref LL_RCC_BUS3_CLOCK_I2C
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group3_EnableBusClock(uint32_t Peripheral)
{
    SET_BIT(RCC->PCLKCR3, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR4        LL_RCC_Group4_EnableBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS4_CLOCK_BTIM
  *           @arg @ref LL_RCC_BUS4_CLOCK_GTIM0
  *           @arg @ref LL_RCC_BUS4_CLOCK_GTIM1
  *           @arg @ref LL_RCC_BUS4_CLOCK_ATIM
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group4_EnableBusClock(uint32_t Peripheral)
{
    SET_BIT(RCC->PCLKCR4, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR1        LL_RCC_Group1_DisableBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS1_CLOCK_LPTIM
  *           @arg @ref LL_RCC_BUS1_CLOCK_USB
  *           @arg @ref LL_RCC_BUS1_CLOCK_RTC
  *           @arg @ref LL_RCC_BUS1_CLOCK_PMU
  *           @arg @ref LL_RCC_BUS1_CLOCK_SCU
  *           @arg @ref LL_RCC_BUS1_CLOCK_IWDT
  *           @arg @ref LL_RCC_BUS1_CLOCK_ANAC
  *           @arg @ref LL_RCC_BUS1_CLOCK_GPIO
  *           @arg @ref LL_RCC_BUS1_CLOCK_DCU
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group1_DisableBusClock(uint32_t Peripheral)
{
    CLEAR_BIT(RCC->PCLKCR1, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR2        LL_RCC_Group2_DisableBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS2_CLOCK_CRC
  *           @arg @ref LL_RCC_BUS2_CLOCK_RNG
  *           @arg @ref LL_RCC_BUS2_CLOCK_AES
  *           @arg @ref LL_RCC_BUS2_CLOCK_LCD
  *           @arg @ref LL_RCC_BUS2_CLOCK_DMA
  *           @arg @ref LL_RCC_BUS2_CLOCK_FLASH
  *           @arg @ref LL_RCC_BUS2_CLOCK_RAMBIST
  *           @arg @ref LL_RCC_BUS2_CLOCK_WWDT
  *           @arg @ref LL_RCC_BUS2_CLOCK_ADC
  *           @arg @ref LL_RCC_BUS2_CLOCK_HDIV
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group2_DisableBusClock(uint32_t Peripheral)
{
    CLEAR_BIT(RCC->PCLKCR2, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR3        LL_RCC_Group3_DisableBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS3_CLOCK_SPI1
  *           @arg @ref LL_RCC_BUS3_CLOCK_SPI2
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART0
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART1
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART4
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART5
  *           @arg @ref LL_RCC_BUS3_CLOCK_UARTIR
  *           @arg @ref LL_RCC_BUS3_CLOCK_LPUART0
  *           @arg @ref LL_RCC_BUS3_CLOCK_U7816
  *           @arg @ref LL_RCC_BUS3_CLOCK_LPUART1
  *           @arg @ref LL_RCC_BUS3_CLOCK_I2C
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group3_DisableBusClock(uint32_t Peripheral)
{
    CLEAR_BIT(RCC->PCLKCR3, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR4        LL_RCC_Group4_DisableBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS4_CLOCK_BTIM
  *           @arg @ref LL_RCC_BUS4_CLOCK_GTIM0
  *           @arg @ref LL_RCC_BUS4_CLOCK_GTIM1
  *           @arg @ref LL_RCC_BUS4_CLOCK_ATIM
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group4_DisableBusClock(uint32_t Peripheral)
{
    CLEAR_BIT(RCC->PCLKCR4, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR1        LL_RCC_Group1_IsEnabledBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS1_CLOCK_LPTIM
  *           @arg @ref LL_RCC_BUS1_CLOCK_USB
  *           @arg @ref LL_RCC_BUS1_CLOCK_RTC
  *           @arg @ref LL_RCC_BUS1_CLOCK_PMU
  *           @arg @ref LL_RCC_BUS1_CLOCK_SCU
  *           @arg @ref LL_RCC_BUS1_CLOCK_IWDT
  *           @arg @ref LL_RCC_BUS1_CLOCK_ANAC
  *           @arg @ref LL_RCC_BUS1_CLOCK_GPIO
  *           @arg @ref LL_RCC_BUS1_CLOCK_DCU
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_Group1_IsEnabledBusClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(RCC->PCLKCR1, ((Peripheral & 0xFFFFFFFF) << 0x0U)) == ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR2        LL_RCC_Group2_IsEnabledBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS2_CLOCK_CRC
  *           @arg @ref LL_RCC_BUS2_CLOCK_RNG
  *           @arg @ref LL_RCC_BUS2_CLOCK_AES
  *           @arg @ref LL_RCC_BUS2_CLOCK_LCD
  *           @arg @ref LL_RCC_BUS2_CLOCK_DMA
  *           @arg @ref LL_RCC_BUS2_CLOCK_FLASH
  *           @arg @ref LL_RCC_BUS2_CLOCK_RAMBIST
  *           @arg @ref LL_RCC_BUS2_CLOCK_WWDT
  *           @arg @ref LL_RCC_BUS2_CLOCK_ADC
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_Group2_IsEnabledBusClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(RCC->PCLKCR2, ((Peripheral & 0xFFFFFFFF) << 0x0U)) == ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR3        LL_RCC_Group3_IsEnabledBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS3_CLOCK_SPI1
  *           @arg @ref LL_RCC_BUS3_CLOCK_SPI2
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART0
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART1
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART4
  *           @arg @ref LL_RCC_BUS3_CLOCK_UART5
  *           @arg @ref LL_RCC_BUS3_CLOCK_UARTIR
  *           @arg @ref LL_RCC_BUS3_CLOCK_LPUART0
  *           @arg @ref LL_RCC_BUS3_CLOCK_U7816
  *           @arg @ref LL_RCC_BUS3_CLOCK_LPUART1
  *           @arg @ref LL_RCC_BUS3_CLOCK_I2C
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_Group3_IsEnabledBusClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(RCC->PCLKCR3, ((Peripheral & 0xFFFFFFFF) << 0x0U)) == ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   PCLKCR4        LL_RCC_Group4_IsEnabledBusClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BUS4_CLOCK_BTIM
  *           @arg @ref LL_RCC_BUS4_CLOCK_GTIM0
  *           @arg @ref LL_RCC_BUS4_CLOCK_GTIM1
  *           @arg @ref LL_RCC_BUS4_CLOCK_ATIM
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_Group4_IsEnabledBusClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(RCC->PCLKCR4, ((Peripheral & 0xFFFFFFFF) << 0x0U)) == ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   OPCCR1        LL_RCC_Group1_EnableOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_EXTI
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_LPUART1
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_LPUART0
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_I2C
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_ATIM
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_UART1
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_UART0
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group1_EnableOperationClock(uint32_t Peripheral)
{
    SET_BIT(RCC->OPCCR1, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   OPCCR2        LL_RCC_Group2_EnableOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_RNG
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_ADC
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_LPTIM
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_BSTIM
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group2_EnableOperationClock(uint32_t Peripheral)
{
    SET_BIT(RCC->OPCCR2, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   OPCCR1        LL_RCC_Group1_DisableOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_EXTI
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_LPUART1
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_LPUART0
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_I2C
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_ATIM
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_UART1
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group1_DisableOperationClock(uint32_t Peripheral)
{
    CLEAR_BIT(RCC->OPCCR1, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   OPCCR2        LL_RCC_Group2_DisableOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_RNG
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_ADC
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_LPTIM
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_BSTIM
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_Group2_DisableOperationClock(uint32_t Peripheral)
{
    CLEAR_BIT(RCC->OPCCR2, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   OPCCR1        LL_RCC_Group1_IsEnabledOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_EXTI
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_LPUART1
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_LPUART0
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_I2C
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_ATIM
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_UART1
  *           @arg @ref LL_RCC_OPERATION1_CLOCK_UART0
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_Group1_IsEnabledOperationClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR1, ((Peripheral & 0xFFFFFFFF) << 0x0U)) == ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   OPCCR2        LL_RCC_Group2_IsEnabledOperationClock
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_RNG
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_ADC
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_LPTIM
  *           @arg @ref LL_RCC_OPERATION2_CLOCK_BSTIM
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_Group2_IsEnabledOperationClock(uint32_t Peripheral)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR2, ((Peripheral & 0xFFFFFFFF) << 0x0U)) == ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   OPCCR1    EXTICKS    LL_RCC_SetEXTIClockSource
  * @param    EXTISource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_EXTERNAL_INTERRUPT_SAMPLING_CLOCK_SELECT_LSCLK
  *           @arg @ref LL_RCC_EXTERNAL_INTERRUPT_SAMPLING_CLOCK_SELECT_HCLK
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetEXTIClockSource(uint32_t EXTISource)
{
    MODIFY_REG(RCC->OPCCR1, RCC_OPCCR1_EXTICKS_Msk, EXTISource);
}

/**
  * @brief    
  * @rmtoll   OPCCR1    EXTICKS    LL_RCC_GetEXTIClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_EXTERNAL_INTERRUPT_SAMPLING_CLOCK_SELECT_LSCLK
  *           @arg @ref LL_RCC_EXTERNAL_INTERRUPT_SAMPLING_CLOCK_SELECT_HCLK
  */
__STATIC_INLINE uint32_t LL_RCC_GetEXTIClockSource(void)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR1, RCC_OPCCR1_EXTICKS_Msk));
}

/**
  * @brief    
  * @rmtoll   OPCCR1    LPUARTCKS    LL_RCC_SetLPUARTClockSource
  * @param    Uartx This parameter can be one of the following values:
  *           @arg @ref LPUART0
  *           @arg @ref LPUART1
  * @param    LPUART0Source This parameter can be one of the following values:
  *           @arg @ref LL_RCC_LPUART_OPERTION_CLOCK_SOURCE_LSCLK
  *           @arg @ref LL_RCC_LPUART_OPERTION_CLOCK_SOURCE_RCHF
  *           @arg @ref LL_RCC_LPUART_OPERTION_CLOCK_SOURCE_RC4M
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetLPUARTClockSource(LPUART_Type* Uartx,uint32_t Source)
{
    if(Uartx == LPUART0)
    {
        MODIFY_REG(RCC->OPCCR1, RCC_OPCCR1_LPUART0CKS_Msk, Source<<RCC_OPCCR1_LPUART0CKS_Pos);
    }
    else if(Uartx == LPUART1)
    {
        MODIFY_REG(RCC->OPCCR1, RCC_OPCCR1_LPUART1CKS_Msk, Source<<RCC_OPCCR1_LPUART1CKS_Pos);
    }
    
}

/**
  * @brief    
  * @rmtoll   OPCCR1    LPUARTCKS    LL_RCC_GetLPUARTClockSource
  * @param    Uartx This parameter can be one of the following values:
  *           @arg @ref LPUART0
  *           @arg @ref LPUART1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_LPUART_OPERTION_CLOCK_SOURCE_LSCLK
  *           @arg @ref LL_RCC_LPUART_OPERTION_CLOCK_SOURCE_RCHF
  *           @arg @ref LL_RCC_LPUART_OPERTION_CLOCK_SOURCE_RC4M
  */
__STATIC_INLINE uint32_t LL_RCC_GetLPUARTClockSource(LPUART_Type* Uartx)
{
    if(Uartx == LPUART0)
    {
        return (uint32_t)(READ_BIT(RCC->OPCCR1, RCC_OPCCR1_LPUART0CKS_Msk) >>RCC_OPCCR1_LPUART0CKS_Pos );

    }
    else if(Uartx == LPUART1)
    {
        return (uint32_t)(READ_BIT(RCC->OPCCR1, RCC_OPCCR1_LPUART1CKS_Msk) >>RCC_OPCCR1_LPUART1CKS_Pos );
    }
    else
    {
        return 0;
    }
    
}

/**
  * @brief    
  * @rmtoll   OPCCR1    I2CCKS    LL_RCC_SetI2CClockSource
  * @param    I2CSource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_I2C_OPERATION_CLOCK_SOURCE_APBCLK1
  *           @arg @ref LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RCHF
  *           @arg @ref LL_RCC_I2C_OPERATION_CLOCK_SOURCE_SYSCLK
  *           @arg @ref LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RC4M_PSC
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetI2CClockSource(uint32_t I2CSource)
{
    MODIFY_REG(RCC->OPCCR1, RCC_OPCCR1_I2CCKS_Msk, I2CSource);
}

/**
  * @brief    
  * @rmtoll   OPCCR1    I2CCKS    LL_RCC_GetI2CClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_I2C_OPERATION_CLOCK_SOURCE_APBCLK1
  *           @arg @ref LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RCHF
  *           @arg @ref LL_RCC_I2C_OPERATION_CLOCK_SOURCE_SYSCLK
  *           @arg @ref LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RC4M_PSC
  */
__STATIC_INLINE uint32_t LL_RCC_GetI2CClockSource(void)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR1, RCC_OPCCR1_I2CCKS_Msk));
}

/**
  * @brief    
  * @rmtoll   OPCCR1    ATCKS    LL_RCC_SetATIMClockSource
  * @param    ATIMSource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_APBCLK2
  *           @arg @ref LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_USBPHYBCK120M
  *           @arg @ref LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_PLLx2
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetATIMClockSource(uint32_t ATIMSource)
{
    MODIFY_REG(RCC->OPCCR1, RCC_OPCCR1_ATCKS_Msk, ATIMSource);
}

/**
  * @brief    
  * @rmtoll   OPCCR1    ATCKS    LL_RCC_GetATIMClockSource
  * @param    ATIMSource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_APBCLK2
  *           @arg @ref LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_USBPHYBCK120M
  *           @arg @ref LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_PLLx2
  * @retval   None
  */
__STATIC_INLINE uint32_t LL_RCC_GetATIMClockSource(uint32_t ATIMSource)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR1, RCC_OPCCR1_ATCKS_Msk));
}

/**
  * @brief    
  * @rmtoll   OPCCR1    UARTCKS    LL_RCC_SetUARTClockSource
  * @param    Uartx This parameter can be one of the following values:
  *           @arg @ref UART0
  *           @arg @ref UART1
  * @param    UART1Source This parameter can be one of the following values:
  *           @arg @ref LL_RCC_UART_OPERATION_CLOCK_SOURCE_APBCLK1
  *           @arg @ref LL_RCC_UART_OPERATION_CLOCK_SOURCE_RCHF
  *           @arg @ref LL_RCC_UART_OPERATION_CLOCK_SOURCE_SYSCLK
  *           @arg @ref LL_RCC_UART_OPERATION_CLOCK_SOURCE_RC4M_PSC
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetUARTClockSource(UART_Type* Uartx,uint32_t Source)
{
    if(Uartx == UART0)
    {
        MODIFY_REG(RCC->OPCCR1, RCC_OPCCR1_UART0CKS_Msk, Source<<RCC_OPCCR1_UART0CKS_Pos);
    }
    else if(Uartx == UART1)
    {
        MODIFY_REG(RCC->OPCCR1, RCC_OPCCR1_UART1CKS_Msk, Source<<RCC_OPCCR1_UART1CKS_Pos);
    }
}

/**
  * @brief    
  * @rmtoll   OPCCR1    UART1CKS    LL_RCC_GetUARTClockSource
  * @param    Uartx This parameter can be one of the following values:
  *           @arg @ref UART0
  *           @arg @ref UART1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_UART_OPERATION_CLOCK_SOURCE_APBCLK1
  *           @arg @ref LL_RCC_UART_OPERATION_CLOCK_SOURCE_RCHF
  *           @arg @ref LL_RCC_UART_OPERATION_CLOCK_SOURCE_SYSCLK
  *           @arg @ref LL_RCC_UART_OPERATION_CLOCK_SOURCE_RC4M_PSC
  */
__STATIC_INLINE uint32_t LL_RCC_GetUARTClockSource(UART_Type* Uartx)
{
    if(Uartx == UART0)
    {
        return (uint32_t)(READ_BIT(RCC->OPCCR1, RCC_OPCCR1_UART0CKS_Msk)>>RCC_OPCCR1_UART0CKS_Pos);
    }
    else if(Uartx == UART1)
    {
        return (uint32_t)(READ_BIT(RCC->OPCCR1, RCC_OPCCR1_UART1CKS_Msk)>>RCC_OPCCR1_UART1CKS_Pos); 
    }
    else
    {
        return 0;
    }
}
/**
  * @brief    
  * @rmtoll   OPCCR2    RNGPRSC    LL_RCC_SetRNGPrescaler
  * @param    Prescaler This parameter can be one of the following values:
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV1
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV2
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV4
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV8
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV16
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV32
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetRNGPrescaler(uint32_t Prescaler)
{
    MODIFY_REG(RCC->OPCCR2, RCC_OPCCR2_RNGPRSC_Msk, Prescaler);
}

/**
  * @brief    
  * @rmtoll   OPCCR2    RNGPRSC    LL_RCC_GetRNGPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV1
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV2
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV4
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV8
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV16
  *           @arg @ref LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV32
  */
__STATIC_INLINE uint32_t LL_RCC_GetRNGPrescaler(void)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR2, RCC_OPCCR2_RNGPRSC_Msk));
}

/**
  * @brief    
  * @rmtoll   OPCCR2    ADCPRSC    LL_RCC_SetADCPrescaler
  * @param    Prescaler This parameter can be one of the following values:
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV1
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV2
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV4
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV8
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV16
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV32
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetADCPrescaler(uint32_t Prescaler)
{
    MODIFY_REG(RCC->OPCCR2, RCC_OPCCR2_ADCPRSC_Msk, Prescaler);
}

/**
  * @brief    
  * @rmtoll   OPCCR2    ADCPRSC    LL_RCC_GetADCPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV1
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV2
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV4
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV8
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV16
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV32
  */
__STATIC_INLINE uint32_t LL_RCC_GetADCPrescaler(void)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR2, RCC_OPCCR2_ADCPRSC_Msk));
}

/**
  * @brief    
  * @rmtoll   OPCCR2    ADCCKS    LL_RCC_SetADCClockSource
  * @param    ADCSource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RC4M_PSC
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RCHF
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_XTHF
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_PLL
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetADCClockSource(uint32_t ADCSource)
{
    MODIFY_REG(RCC->OPCCR2, RCC_OPCCR2_ADCCKS_Msk, ADCSource);
}

/**
  * @brief    
  * @rmtoll   OPCCR2    ADCCKS    LL_RCC_GetADCClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RC4M_PSC
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RCHF
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_XTHF
  *           @arg @ref LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_PLL
  */
__STATIC_INLINE uint32_t LL_RCC_GetADCClockSource(void)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR2, RCC_OPCCR2_ADCCKS_Msk));
}

/**
  * @brief    
  * @rmtoll   OPCCR2    LPTCKS    LL_RCC_SetLPTIMClockSource
  * @param    LPTIMSource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_APBCLK1
  *           @arg @ref LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_LSCLK
  *           @arg @ref LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_RCLP
  *           @arg @ref LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_RC4M_PSC
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetLPTIMClockSource(uint32_t LPTIMSource)
{
    MODIFY_REG(RCC->OPCCR2, RCC_OPCCR2_LPTCKS_Msk, LPTIMSource);
}

/**
  * @brief    
  * @rmtoll   OPCCR2    LPTCKS    LL_RCC_GetLPTIMClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_APBCLK1
  *           @arg @ref LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_LSCLK
  *           @arg @ref LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_RCLP
  *           @arg @ref LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_RC4M_PSC
  */
__STATIC_INLINE uint32_t LL_RCC_GetLPTIMClockSource(void)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR2, RCC_OPCCR2_LPTCKS_Msk));
}

/**
  * @brief    
  * @rmtoll   OPCCR2    BTCKS    LL_RCC_SetBSTIMClockSource
  * @param    BSTIMSource This parameter can be one of the following values:
  *           @arg @ref LL_RCC_BSTIM_OPERATION_CLK_SOURCE_APBCLK2
  *           @arg @ref LL_RCC_BSTIM_OPERATION_CLK_SOURCE_LSCLK
  *           @arg @ref LL_RCC_BSTIM_OPERATION_CLK_SOURCE_RCLP
  *           @arg @ref LL_RCC_BSTIM_OPERATION_CLK_SOURCE_RC4M_PSC
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetBSTIMClockSource(uint32_t BSTIMSource)
{
    MODIFY_REG(RCC->OPCCR2, RCC_OPCCR2_BTCKS_Msk, BSTIMSource);
}

/**
  * @brief    
  * @rmtoll   OPCCR2    BTCKS    LL_RCC_GetBSTIMClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_BSTIM_OPERATION_CLK_SOURCE_APBCLK2
  *           @arg @ref LL_RCC_BSTIM_OPERATION_CLK_SOURCE_LSCLK
  *           @arg @ref LL_RCC_BSTIM_OPERATION_CLK_SOURCE_RCLP
  *           @arg @ref LL_RCC_BSTIM_OPERATION_CLK_SOURCE_RC4M_PSC
  */
__STATIC_INLINE uint32_t LL_RCC_GetBSTIMClockSource(void)
{
    return (uint32_t)(READ_BIT(RCC->OPCCR2, RCC_OPCCR2_BTCKS_Msk));
}

/**
  * @brief    
  * @rmtoll   AHBMCR    MPRIL    LL_RCC_SetAHBMasterPriority
  * @param    Priority This parameter can be one of the following values:
  *           @arg @ref LL_RCC_AHB_MASTER_PRIORITY_DMA_FIRST
  *           @arg @ref LL_RCC_AHB_MASTER_PRIORITY_CPU_FIRST
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetAHBMasterPriority(uint32_t Priority)
{
    MODIFY_REG(RCC->AHBMCR, RCC_AHBMCR_MPRIL_Msk, Priority);
}

/**
  * @brief    
  * @rmtoll   AHBMCR    MPRIL    LL_RCC_GetAHBMasterPriority
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RCC_AHB_MASTER_PRIORITY_DMA_FIRST
  *           @arg @ref LL_RCC_AHB_MASTER_PRIORITY_CPU_FIRST
  */
__STATIC_INLINE uint32_t LL_RCC_GetAHBMasterPriority(void)
{
    return (uint32_t)(READ_BIT(RCC->AHBMCR, RCC_AHBMCR_MPRIL_Msk));
}

/**
  * @brief    
  * @rmtoll   LSCLKSEL    SEL    LL_RCC_SetLSCLKClockSource
  * @param    Source This parameter can be one of the following values:
  *           @arg @ref LL_RCC_LSCLK_SELECT_RCLP
  *           @arg @ref LL_RCC_LSCLK_SELECT_XTLF
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetLSCLKClockSource(uint32_t Source)
{
    MODIFY_REG(RCC->LSCLKSEL, RCC_LSCLKSEL_SEL_Msk, Source);
}

/**
  * @brief    
  * @rmtoll   LKPCR    RST_EN    LL_RCC_IsEnabledLockUpReset
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledLockUpReset(void)
{
    return (uint32_t)(READ_BIT(RCC->LKPCR, RCC_LKPCR_RST_EN_Msk) == RCC_LKPCR_RST_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   LKPCR    RST_EN    LL_RCC_DisableLockUpReset
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_DisableLockUpReset(void)
{
    CLEAR_BIT(RCC->LKPCR, RCC_LKPCR_RST_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   LKPCR    RST_EN    LL_RCC_EnableLockUpReset
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_EnableLockUpReset(void)
{
    SET_BIT(RCC->LKPCR, RCC_LKPCR_RST_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   SOFTRST        LL_RCC_SetChipReset
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_SetChipReset(void)
{
    WRITE_REG(RCC->SOFTRST,SOFTWARERESET_KEY); 
}

/**
  * @brief    
  * @rmtoll   RSTFR    MDFN_FLAG    LL_RCC_IsActiveFlag_MDFN_FLAG
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_MDFN_FLAG(void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_MDFN_FLAG_Msk) == (RCC_RSTFR_MDFN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    NRSTN_FLAG    LL_RCC_IsActiveFlag_NRSTN_FLAG
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_NRSTN_FLAG(void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_NRSTN_FLAG_Msk) == (RCC_RSTFR_NRSTN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    NRSTN_FLAG    LL_RCC_ClearFlag_NRSTN_FLAG
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_NRSTN_FLAG(void)
{
    WRITE_REG(RCC->RSTFR, RCC_RSTFR_NRSTN_FLAG_Msk);
}

/**
  * @brief    
  * @rmtoll   RSTFR    TESTN_FLAG    LL_RCC_IsActiveFlag_TESTN_FLAG
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_TESTN_FLAG(void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_TESTN_FLAG_Msk) == (RCC_RSTFR_TESTN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    TESTN_FLAG    LL_RCC_ClearFlag_TESTN_FLAG
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_TESTN_FLAG(void)
{
    WRITE_REG(RCC->RSTFR, RCC_RSTFR_TESTN_FLAG_Msk);
}

/**
  * @brief    
  * @rmtoll   RSTFR    PORN_FLAG    LL_RCC_IsActiveFlag_PORN_FLAG
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PORN_FLAG(void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_PORN_FLAG_Msk) == (RCC_RSTFR_PORN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    PORN_FLAG    LL_RCC_ClearFlag_PORN_FLAG
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_PORN_FLAG(void)
{
    WRITE_REG(RCC->RSTFR, RCC_RSTFR_PORN_FLAG_Msk);
}

/**
  * @brief    
  * @rmtoll   RSTFR    PDRN_FLAG    LL_RCC_IsActiveFlag_PDRN_FLAG 
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PDRN_FLAG (void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_PDRN_FLAG_Msk) == (RCC_RSTFR_PDRN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    PDRN_FLAG    LL_RCC_ClearFlag_PDRN_FLAG 
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_PDRN_FLAG (void)
{
    WRITE_REG(RCC->RSTFR, RCC_RSTFR_PDRN_FLAG_Msk);
}

/**
  * @brief    
  * @rmtoll   RSTFR    SOFTN_FLAG    LL_RCC_IsActiveFlag_SOFTN_FLAG
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_SOFTN_FLAG(void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_SOFTN_FLAG_Msk) == (RCC_RSTFR_SOFTN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    SOFTN_FLAG    LL_RCC_ClearFlag_SOFTN_FLAG
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_SOFTN_FLAG(void)
{
    WRITE_REG(RCC->RSTFR, RCC_RSTFR_SOFTN_FLAG_Msk);
}

/**
  * @brief    
  * @rmtoll   RSTFR    IWDTN_FLAG    LL_RCC_IsActiveFlag_IWDTN_FLAG
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_IWDTN_FLAG(void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_IWDTN_FLAG_Msk) == (RCC_RSTFR_IWDTN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    IWDTN_FLAG    LL_RCC_ClearFlag_IWDTN_FLAG
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_IWDTN_FLAG(void)
{
    WRITE_REG(RCC->RSTFR, RCC_RSTFR_IWDTN_FLAG_Msk);
}

/**
  * @brief    
  * @rmtoll   RSTFR    WWDTN_FLAG    LL_RCC_IsActiveFlag_WWDTN_FLAG
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_WWDTN_FLAG(void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_WWDTN_FLAG_Msk) == (RCC_RSTFR_WWDTN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    WWDTN_FLAG    LL_RCC_ClearFlag_WWDTN_FLAG
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_WWDTN_FLAG(void)
{
    WRITE_REG(RCC->RSTFR, RCC_RSTFR_WWDTN_FLAG_Msk);
}

/**
  * @brief    
  * @rmtoll   RSTFR    LKUPN_FLAG    LL_RCC_IsActiveFlag_LKUPN_FLAG
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LKUPN_FLAG(void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_LKUPN_FLAG_Msk) == (RCC_RSTFR_LKUPN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    LKUPN_FLAG    LL_RCC_ClearFlag_LKUPN_FLAG
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_LKUPN_FLAG(void)
{
    WRITE_REG(RCC->RSTFR, RCC_RSTFR_LKUPN_FLAG_Msk);
}

/**
  * @brief    
  * @rmtoll   RSTFR    NVICN_FLAG    LL_RCC_IsActiveFlag_NVICN_FLAG
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_NVICN_FLAG(void)
{
    return (uint32_t)(READ_BIT(RCC->RSTFR, RCC_RSTFR_NVICN_FLAG_Msk) == (RCC_RSTFR_NVICN_FLAG_Msk));
}

/**
  * @brief    
  * @rmtoll   RSTFR    NVICN_FLAG    LL_RCC_ClearFlag_NVICN_FLAG
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_NVICN_FLAG(void)
{
    WRITE_REG(RCC->RSTFR, RCC_RSTFR_NVICN_FLAG_Msk);
}

/**
  * @brief    
  * @rmtoll   PRSTEN        LL_RCC_DisablePeripheralReset
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_DisablePeripheralReset(void)
{
    WRITE_REG(RCC->PRSTEN,(~PERHRSTEN_KEY)); 
}

/**
  * @brief    
  * @rmtoll   PRSTEN        LL_RCC_EnablePeripheralReset
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_EnablePeripheralReset(void)
{
    WRITE_REG(RCC->PRSTEN,PERHRSTEN_KEY); 
}

/**
  * @brief    
  * @rmtoll   AHBRSTCR        LL_RCC_EnableResetAHBPeripheral
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_AHB_PERIPHERAL_RST_DMA
  *           @arg @ref LL_RCC_AHB_PERIPHERAL_RST_USB
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_EnableResetAHBPeripheral(uint32_t Peripheral)
{
    SET_BIT(RCC->AHBRSTCR, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   APBRSTCR1        LL_RCC_EnableResetAPB1Peripheral
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_UART5        
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_UART4        
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_GTTIM1       
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_GTTIM0       
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_LCD          
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_U7816        
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_SPI2         
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_LPUART0      
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_IIC         
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_LPTIM 
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_EnableResetAPB1Peripheral(uint32_t Peripheral)
{
    SET_BIT(RCC->APBRSTCR1, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   APBRSTCR2        LL_RCC_EnableResetAPB2Peripheral
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_ATIM
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_BSTIM
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_ADC_CR
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_ADC
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_OPA
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_HDV
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_AES
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_CRC
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_RNG
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_UART1
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_UART0
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_SPI1
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_UCIR
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_LPUART1
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_EnableResetAPB2Peripheral(uint32_t Peripheral)
{
    SET_BIT(RCC->APBRSTCR2, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   AHBRSTCR        LL_RCC_DisableResetAHBPeripheral
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_AHB_PERIPHERAL_RST_DMA
  *           @arg @ref LL_RCC_AHB_PERIPHERAL_RST_USB
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_DisableResetAHBPeripheral(uint32_t Peripheral)
{
    CLEAR_BIT(RCC->AHBRSTCR, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   APBRSTCR1        LL_RCC_DisableResetAPB1Peripheral
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_UART5        
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_UART4        
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_GTTIM1       
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_GTTIM0       
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_LCD          
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_U7816        
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_SPI2         
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_LPUART0      
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_IIC         
  *           @arg @ref LL_RCC_APB1_PERIPHERAL_RST_LPTIM         
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_DisableResetAPB1Peripheral(uint32_t Peripheral)
{
    CLEAR_BIT(RCC->APBRSTCR1, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   APBRSTCR2        LL_RCC_DisableResetAPB2Peripheral
  * @param    Peripheral This parameter can be one of the following values:
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_ATIM
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_BSTIM
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_ADC_CR
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_ADC
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_OPA
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_HDV
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_AES
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_CRC
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_RNG
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_UART1
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_UART0
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_SPI1
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_UCIR
  *           @arg @ref LL_RCC_APB2_PERIPHERAL_RST_LPUART1
  * @retval   None
  */
__STATIC_INLINE void LL_RCC_DisableResetAPB2Peripheral(uint32_t Peripheral)
{
    CLEAR_BIT(RCC->APBRSTCR2, ((Peripheral & 0xFFFFFFFF) << 0x0U));
}

/**
  * @}
  */

/** @defgroup RCC_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
uint32_t LL_RCC_GetPLLClockFreq(void);
uint32_t LL_RCC_GetRCHFClockFreq(void);
uint32_t LL_RCC_GetRC4MClockFreq(void);
uint32_t LL_RCC_GetSystemClockFreq(void);
uint32_t LL_RCC_GetAPB1ClockFreq(uint32_t AHB_Frequency);
uint32_t LL_RCC_GetAPB2ClockFreq(uint32_t AHB_Frequency);
uint32_t LL_RCC_GetAHBClockFreq(uint32_t SYSCLK_Frequency);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_RCC_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-09-16**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
