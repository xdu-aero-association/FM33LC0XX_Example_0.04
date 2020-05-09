
/****************************************************************************************************//**
 * @file     FM33LC0XX.h
 *
 * @brief    CMSIS Cortex-M0 Peripheral Access Layer Header File for
 *           FM33LC0XX from Keil.
 *
 * @version  V0.0.1
 * @date     13. august 2019
 *
 * @note     Generated with SVDConv V2.87e 
 *           from CMSIS SVD File 'FM33LC0XX.SVD' Version 1.0,
 *
 * @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
 *           processor based microcontroller, but can be equally used for other
 *           suitable processor architectures. This file can be freely distributed.
 *           Modifications to this file shall be clearly marked.
 *           
 *           THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. 
 *
 *******************************************************************************************************/


/** @addtogroup Keil
  * @{
  */

/** @addtogroup FM33LC0XX
  * @{
  */

#ifndef __FM33LC0XX_H
#define __FM33LC0XX_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
  * @brief Configuration of the Cortex-M0 Processor and Core Peripherals 
  */
#define __CM0_REV                    0x0100U /*!< Cortex-M0 Core Revision                                               */
#define __MPU_PRESENT                0U      /*!< MPU present or not                                                    */
#define __VTOR_PRESENT               1U      /*!< VTOR present or not                                                   */
#define __NVIC_PRIO_BITS             2U      /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig       0U      /*!< Set to 1 if different SysTick Config is used                          */


/**
 * @brief FM33LC0XX Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */
typedef enum {
/******  Cortex-M0 Processor Exceptions Numbers ****************************************************************/
  Reset_IRQn                    = -15,     /*!<  1  Reset Vector, invoked on Power up and warm reset           */
  NMI_IRQn                      = -14,     /*!<  2  Non maskable Interrupt, cannot be stopped or preempted     */
  HardFault_IRQn                = -13,     /*!<  3  Hard Fault, all classes of Fault                           */
  SVCall_IRQn                   = -5,      /*!<  11  System Service Call via SVC instruction                   */
  PendSV_IRQn                   = -2,      /*!<  14  Pendable request for system service                       */
  SysTick_IRQn                  = -1,      /*!<  15  System Tick Timer                                         */
/******  FM33LC0XX specific Interrupt Numbers ******************************************************************/
  WWDT_IRQn                     = 0,       /*!<  0    Window WatchDog Interrupt                                */
  SVD_IRQn                      = 1,       /*!<  1    SVD Interrupt                                            */
  RTC_IRQn                      = 2,       /*!<  2    RTC Interrupt                                            */
  FLASH_IRQn                    = 3,       /*!<  3    FLASH global Interrupt                                   */ 
  LFDET_IRQn                    = 4,       /*!<  4    LFDET Interrupt                                          */
  ADC_IRQn                      = 5,       /*!<  5    ADC Interrupt                                            */
  IWDT_IRQn                     = 6,       /*!<  6    IWDT Interrupt                                           */
  SPI1_IRQn                     = 7,       /*!<  7    SPI1 Interrupt                                           */
  SPI2_IRQn                     = 8,       /*!<  8    SPI2 Interrupt                                           */
  LCD_IRQn                      = 9,       /*!<  9    LCD Interrupt                                            */
  UART0_IRQn                    = 10,      /*!<  10   UART0 global Interrupt                                   */
  UART1_IRQn                    = 11,      /*!<  11   UART1 global Interrupt                                   */
  UART4_IRQn                    = 12,      /*!<  12   UART4 global Interrupt                                   */
  UART5_IRQn                    = 13,      /*!<  13   UART5 global Interrupt                                   */ 
  HFDET_IRQn                    = 14,      /*!<  14   HFDET Interrupt                                          */
  U7816_IRQn                    = 15,      /*!<  15   U7816 Interrupt                                          */
  LPUART1_IRQn                  = 16,      /*!<  16   LPUART1 Interrupt                                        */
  I2C_IRQn                      = 17,      /*!<  17   I2C global Interrupt                                     */
  USB_IRQn                      = 18,      /*!<  18   USB Interrupt                                            */
  AES_IRQn                      = 19,      /*!<  19   AES Interrupt                                            */ 
  LPTIM_IRQn                    = 20,      /*!<  20   LPTIM Interrupt                                          */
  DMA_IRQn                      = 21,      /*!<  21   DMA Interrupt                                            */
  WKUP_IRQn                     = 22,      /*!<  22   WKUP Interrupt                                           */
  OPAx_IRQn                     = 23,      /*!<  23   OPAx Interrupt                                           */
  BSTIM_IRQn                    = 24,      /*!<  24   BSTIM Interrupt                                          */
  COMPx_IRQn                    = 25,      /*!<  25   COMPx Interrupt                                          */
  GPTIM0_IRQn                   = 26,      /*!<  26   GTIM0 global Interrupt                                   */
  GPTIM1_IRQn                   = 27,      /*!<  27   GTIM1 global Interrupt                                   */
  ATIM_IRQn                     = 28,      /*!<  28   ATIM global Interrupt                                    */
  VREF_IRQn                     = 29,      /*!<  29   VREF Interrupt                                           */
  GPIO_IRQn                     = 30,      /*!<  30   GPIO Interrupt                                           */
  LPUART0_IRQn                  = 31       /*!<  31   LPUART0 Interrupt                                        */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */


#include "core_cm0plus.h"                            /*!< Cortex-M0 processor and core peripherals                           */
#include "system_fm33lc0xx.h"                        /*!< FM33LC0XX System                                                        */
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Analog to Digital Converter  
  */
typedef struct
{
  __IO uint32_t ISR;              /*!< ADC Interrupt and Status Register,                   Address offset: 0x00 */
  __IO uint32_t IER;              /*!< ADC Interrupt Enable Register,                       Address offset: 0x04 */
  __IO uint32_t CR;               /*!< ADC Control Register,                                Address offset: 0x08 */
  __IO uint32_t CFGR;             /*!< ADC Config Register,                                 Address offset: 0x0C */
  __IO uint32_t SMTR;             /*!< ADC Sampling Time Register,                          Address offset: 0x10 */
  __IO uint32_t CHER;             /*!< ADC Channel Enable Register,                         Address offset: 0x14 */
  __IO uint32_t DR;               /*!< ADC Data Register,                                   Address offset: 0x18 */
  __IO uint32_t SAMPT;            /*!< ADC Calibration Register,                            Address offset: 0x1C */
  __IO uint32_t HLTR;             /*!< ADC analog watchdog Threshold Register,              Address offset: 0x20 */
} ADC_Type;

typedef struct
{
  __IO uint32_t CR;               /*!< AES Control Register,                                Address offset: 0x00 */
  __IO uint32_t IER;              /*!< AES Interrupt Enable Register,                       Address offset: 0x04 */
  __IO uint32_t ISR;              /*!< AES Interrupt Status Register,                       Address offset: 0x08 */
  __IO uint32_t DIR;              /*!< AES Data Input Register,                             Address offset: 0x0C */
  __IO uint32_t DOR;              /*!< AES Data Output Register,                            Address offset: 0x10 */
  __IO uint32_t KEY0;             /*!< AES Key Register 0,                                  Address offset: 0x14 */
  __IO uint32_t KEY1;             /*!< AES Key Register 1,                                  Address offset: 0x18 */
  __IO uint32_t KEY2;             /*!< AES Key Register 2,                                  Address offset: 0x1C */
  __IO uint32_t KEY3;             /*!< AES Key Register 3,                                  Address offset: 0x20 */    
  __IO uint32_t KEY4;             /*!< AES Key Register 4,                                  Address offset: 0x24 */    
  __IO uint32_t KEY5;             /*!< AES Key Register 5,                                  Address offset: 0x28 */    
  __IO uint32_t KEY6;             /*!< AES Key Register 6,                                  Address offset: 0x2C */
  __IO uint32_t KEY7;             /*!< AES Key Register 7,                                  Address offset: 0x30 */
  __IO uint32_t IVR0;             /*!< AES Initial Vector Register 0,                       Address offset: 0x34 */
  __IO uint32_t IVR1;             /*!< AES Initial Vector Register 1,                       Address offset: 0x38 */
  __IO uint32_t IVR2;             /*!< AES Initial Vector Register 2,                       Address offset: 0x3C */
  __IO uint32_t IVR3;             /*!< AES Initial Vector Register 3,                       Address offset: 0x40 */
} AES_Type;

typedef struct
{
  __IO uint32_t CR1;              /*!< ATIM Control Register1,                              Address offset: 0x00 */
  __IO uint32_t CR2;              /*!< ATIM Control Register2,                              Address offset: 0x04 */
  __IO uint32_t SMCR;             /*!< ATIM Slave Mode Control Register,                    Address offset: 0x08 */
  __IO uint32_t DIER;             /*!< ATIM DMA and Interrupt Enable Register,              Address offset: 0x0C */
  __IO uint32_t ISR;              /*!< ATIM Interrupt Status Register,                      Address offset: 0x10 */
  __IO uint32_t EGR;              /*!< ATIM Event Generation Register,                      Address offset: 0x14 */
  __IO uint32_t CCMR1;            /*!< ATIM Capture/Compare Mode Register1,                 Address offset: 0x18 */
  __IO uint32_t CCMR2;            /*!< ATIM Capture/Compare Mode Register2,                 Address offset: 0x1C */
  __IO uint32_t CCER;             /*!< ATIM Capture/Compare Enable Register,                Address offset: 0x20 */
  __IO uint32_t CNT;              /*!< ATIM Counter Register,                               Address offset: 0x24 */
  __IO uint32_t PSC;              /*!< ATIM Prescaler Register,                             Address offset: 0x28 */
  __IO uint32_t ARR;              /*!< ATIM Auto-Reload Register,                           Address offset: 0x2C */
  __IO uint32_t RCR;              /*!< ATIM Repetition Counter Register,                    Address offset: 0x30 */
  __IO uint32_t CCR1;             /*!< ATIM Capture/Compare Register1,                      Address offset: 0x34 */
  __IO uint32_t CCR2;             /*!< ATIM Capture/Compare Register2,                      Address offset: 0x38 */
  __IO uint32_t CCR3;             /*!< ATIM Capture/Compare Register3,                      Address offset: 0x3C */
  __IO uint32_t CCR4;             /*!< ATIM Capture/Compare Register4,                      Address offset: 0x40 */
  __IO uint32_t BDTR;             /*!< ATIM Break and Deadtime Register,                    Address offset: 0x44 */
  __IO uint32_t DCR;              /*!< ATIM DMA Control Register,                           Address offset: 0x48 */
  __IO uint32_t DMAR;             /*!< ATIM DMA Access Register,                            Address offset: 0x4C */
  __IO uint32_t RSV0;             /*!< RESERVED REGISTER0,                                  Address offset: 0x50 */
  __IO uint32_t RSV1;             /*!< RESERVED REGISTER1,                                  Address offset: 0x54 */
  __IO uint32_t RSV2;             /*!< RESERVED REGISTER2,                                  Address offset: 0x58 */
  __IO uint32_t RSV3;             /*!< RESERVED REGISTER3,                                  Address offset: 0x5C */
  __IO uint32_t BKCR;             /*!< ATIM Break Control Register,                         Address offset: 0x60 */
} ATIM_Type;

typedef struct
{
  __IO uint32_t CR1;              /*!< BSTIM Control Register1,                             Address offset: 0x00 */
  __IO uint32_t CR2;              /*!< BSTIM Control Register2,                             Address offset: 0x04 */
  __IO uint32_t RSV0;             /*!< RESERVED REGISTER0,                                  Address offset: 0x08 */
  __IO uint32_t IER;              /*!< BSTIM Interrupt Enable Register,                     Address offset: 0x0C */
  __IO uint32_t ISR;              /*!< BSTIM Interrupt Status Register,                     Address offset: 0x10 */
  __IO uint32_t EGR;              /*!< BSTIM Event Generation Register,                     Address offset: 0x14 */
  __IO uint32_t RSV1;             /*!< RESERVED REGISTER1,                                  Address offset: 0x18 */
  __IO uint32_t RSV2;             /*!< RESERVED REGISTER2,                                  Address offset: 0x1C */
  __IO uint32_t RSV3;             /*!< RESERVED REGISTER3,                                  Address offset: 0x20 */
  __IO uint32_t CNT;              /*!< BSTIM Counter Register,                              Address offset: 0x24 */
  __IO uint32_t PSC;              /*!< BSTIM Prescaler Register,                            Address offset: 0x28 */
  __IO uint32_t ARR;              /*!< BSTIM Auto-Reload Register,                          Address offset: 0x2C */
} BSTIM_Type;

typedef struct
{
  __IO uint32_t CR;              /*!< ComparatorControl Register 1,                        Address offset: 0x00 */

} COMP_Type;

typedef struct
{
  __IO uint32_t ICR;             /*!< Comparator Interrupt Config Register,                Address offset: 0x08 */
  __IO uint32_t ISR;             /*!< Comparator Interrupt Status Register,                Address offset: 0x0C */
} COMP_COMMON_Type;

typedef struct
{
  __IO uint32_t DR;               /*!< CRC Data Register,                                   Address offset: 0x00 */
  __IO uint32_t CR;               /*!< CRC Control Register,                                Address offset: 0x04 */
  __IO uint32_t LFSR;             /*!< CRC Linear Feedback Shift Register,                  Address offset: 0x08 */
  __IO uint32_t XOR;              /*!< CRC output XOR Register,                             Address offset: 0x0C */
  __IO uint32_t RSV0;             /*!< RESERVED REGISTER0,                                  Address offset: 0x10 */
  __IO uint32_t RSV1;             /*!< RESERVED REGISTER1,                                  Address offset: 0x14 */
  __IO uint32_t RSV2;             /*!< RESERVED REGISTER2,                                  Address offset: 0x18 */
  __IO uint32_t POLY;             /*!< CRC Polynominal Register,                            Address offset: 0x1C */
} CRC_Type;

typedef struct
{
  __IO uint32_t RSV;
  __IO uint32_t CR;               /*!< Debug Configuration Register */
  __IO uint32_t HDFR;             /*!< HardFault Flag Register*/
    
} DBG_Type;

typedef struct
{
  __IO uint32_t GCR;              /*!< DMA Global Control Register         ,                Address offset: 0x00 */
  __IO uint32_t CH0CR;            /*!< Channel 0 Control Register          ,                Address offset: 0x04 */
  __IO uint32_t CH0MAD;           /*!< Channel 0 Memory Address Register   ,                Address offset: 0x08 */
  __IO uint32_t CH1CR;            /*!< Channel 1 Control Register          ,                Address offset: 0x0C */
  __IO uint32_t CH1MAD;           /*!< Channel 1 Memory Address Register   ,                Address offset: 0x10 */    
  __IO uint32_t CH2CR;            /*!< Channel 2 Control Register          ,                Address offset: 0x14 */
  __IO uint32_t CH2MAD;           /*!< Channel 2 Memory Address Register   ,                Address offset: 0x18 */
  __IO uint32_t CH3CR;            /*!< Channel 3 Control Register          ,                Address offset: 0x1C */
  __IO uint32_t CH3MAD;           /*!< Channel 3 Memory Address Register   ,                Address offset: 0x20 */
  __IO uint32_t CH4CR;            /*!< Channel 4 Control Register          ,                Address offset: 0x24 */
  __IO uint32_t CH4MAD;           /*!< Channel 4 Memory Address Register   ,                Address offset: 0x28 */
  __IO uint32_t CH5CR;            /*!< Channel 5 Control Register          ,                Address offset: 0x2C */
  __IO uint32_t CH5MAD;           /*!< Channel 5 Memory Address Register   ,                Address offset: 0x30 */
  __IO uint32_t CH6CR;            /*!< Channel 6 Control Register          ,                Address offset: 0x34 */
  __IO uint32_t CH6MAD;           /*!< Channel 6 Memory Address Register   ,                Address offset: 0x38 */
  __IO uint32_t CH7CR;            /*!< Channel 7 Control Register          ,                Address offset: 0x3C */
  __IO uint32_t CH7FLSAD;         /*!< Channel 7 Flash Address Register    ,                Address offset: 0x40 */
  __IO uint32_t CH7RAMAD;         /*!< Channel 7 RAM Address Register      ,                Address offset: 0x44 */
  __IO uint32_t ISR;              /*!< DMA Interrupt Status Register       ,                Address offset: 0x48 */
} DMA_Type;

typedef struct
{
  __IO uint32_t IER;              /*!< XTLF Oscillation Fail Detection Interrupt Enable Register, Address offset: 0x00 */
  __IO uint32_t ISR;              /*!< XTLF Oscillation Fail Detection Interrupt Status Register, Address offset: 0x04 */
}FDET_Type;


typedef struct
{
  __IO uint32_t RDCR;             /*!< Flash Read Control Register,                         Address offset: 0x00 */
  __IO uint32_t PFCR;             /*!< Flash Prefetch Control Register,                     Address offset: 0x04 */
  __I  uint32_t OPTBR;            /*!< Flash Option Bytes Register,                         Address offset: 0x08 */
  __IO uint32_t ACLOCK1;          /*!< Flash Application Code Lock Register 1,              Address offset: 0x0C */
  __IO uint32_t ACLOCK2;          /*!< Flash Application Code Lock Register 2,              Address offset: 0x10 */
  __IO uint32_t EPCR;             /*!< Flash Erase/Program Control Register,                Address offset: 0x14 */
  __IO uint32_t KEY;              /*!< Flash Key Register,                                  Address offset: 0x18 */
  __IO uint32_t IER;              /*!< Flash Interrupt Enable Register,                     Address offset: 0x1C */
  __IO uint32_t ISR;              /*!< Flash Interrupt Status Register,                     Address offset: 0x20 */    
} FLASH_Type;

typedef struct
{
  __IO uint32_t INEN;             /*!< Input Enable Register          */
  __IO uint32_t PUEN;             /*!< Pull-Up Enable Register        */
  __IO uint32_t ODEN;             /*!< Open-Drain Enable Register     */
  __IO uint32_t FCR;              /*!< Function Control Register      */
  __IO uint32_t DO;               /*!< Data Output Register           */    
  __O  uint32_t DSET;             /*!< Data Set Register              */
  __O  uint32_t DRST;             /*!< Data Reset Register            */
  __I uint32_t  DIN;              /*!< Data Input RegisterR           */
  __IO uint32_t DFS;              /*!< Digital Function Select        */
  __IO uint32_t RSV;              /*!< RESERVED REGISTER              */
  __IO uint32_t ANEN;             /*!< Analog channel Enable Register */
} GPIO_Type;

typedef struct
{
  __IO uint32_t EXTISEL;          /*!< External Interrupt input Select Register            */
  __IO uint32_t EXTIEDS;          /*!< External Interrupt Edge Select and Enable Register  */
  __IO uint32_t EXTIDF;           /*!< External Interrupt Digital Filter Register          */
  __IO uint32_t EXTIISR;          /*!< External Interrupt and Status Register              */
  __IO uint32_t EXTIDI;           /*!< External Interrupt Data Input Register              */    
  __IO uint32_t RSV0[59];         /*!< RESERVED REGISTER                                   */
  __IO uint32_t FOUTSEL;          /*!< Frequency Output Select Register                    */
  __IO uint32_t RSV1[63];         /*!< RESERVED REGISTER                                   */
  __IO uint32_t PINWKEN;          /*!< Wakeup Enable Register                              */
} GPIO_COMMON_Type;

typedef struct
{
  __IO uint32_t CR1;              /*!< GPTIM Control Register1,                             Address offset: 0x00 */
  __IO uint32_t CR2;              /*!< GPTIM Control Register2,                             Address offset: 0x04 */
  __IO uint32_t SMCR;             /*!< GPTIM Slave Mode Control Register,                   Address offset: 0x08 */
  __IO uint32_t DIER;             /*!< GPTIM DMA and Interrupt Enable Register,             Address offset: 0x0C */
  __IO uint32_t ISR;              /*!< GPTIM Interrupt Status Register,                     Address offset: 0x10 */
  __IO uint32_t EGR;              /*!< GPTIM EVENT GENERATE REGISTER,                       Address offset: 0x14 */
  __IO uint32_t CCMR1;            /*!< GPTIM Capture/Compare Mode Register1,                Address offset: 0x18 */
  __IO uint32_t CCMR2;            /*!< GPTIM Capture/Compare Mode Register2,                Address offset: 0x1C */
  __IO uint32_t CCER;             /*!< GPTIM Capture/Compare Enable Register,               Address offset: 0x20 */
  __IO uint32_t CNT;              /*!< GPTIM Counter Register,                              Address offset: 0x24 */
  __IO uint32_t PSC;              /*!< GPTIM Prescaler Register,                            Address offset: 0x28 */
  __IO uint32_t ARR;              /*!< GPTIM Auto-Reload Register,                          Address offset: 0x2C */
  __IO uint32_t RSV0;             /*!< RESERVED REGISTER0,                                  Address offset: 0x30 */
  __IO uint32_t CCR1;             /*!< GPTIM Capture/Compare Register1,                     Address offset: 0x34 */
  __IO uint32_t CCR2;             /*!< GPTIM Capture/Compare Register2,                     Address offset: 0x38 */
  __IO uint32_t CCR3;             /*!< GPTIM Capture/Compare Register3,                     Address offset: 0x3C */
  __IO uint32_t CCR4;             /*!< GPTIM Capture/Compare Register4,                     Address offset: 0x40 */
  __IO uint32_t RSV1;             /*!< RESERVED REGISTER1,                                  Address offset: 0x44 */
  __IO uint32_t DCR;              /*!< GPTIM DMA CONTROL REGISTER,                          Address offset: 0x48 */
  __IO uint32_t DMAR;             /*!< GPTIM DMA access Register,                           Address offset: 0x4C */
  __IO uint32_t RSV2;             /*!< RESERVED REGISTER2,                                  Address offset: 0x50 */
  __IO uint32_t RSV3;             /*!< RESERVED REGISTER3,                                  Address offset: 0x54 */
  __IO uint32_t RSV4;             /*!< RESERVED REGISTER4,                                  Address offset: 0x58 */
  __IO uint32_t RSV5;             /*!< RESERVED REGISTER5,                                  Address offset: 0x5C */
  __IO uint32_t ITRSEL;           /*!< GPTIM  Internal Trigger Select Register,             Address offset: 0x60 */
} GPTIM_Type;

typedef struct
{
  __IO uint32_t END;              /*!< Dividend Register,                                   Address offset: 0x00 */
  __IO uint32_t SOR;              /*!< Divisor Regsiter,                                    Address offset: 0x04 */
  __IO uint32_t QUOT;             /*!< Quotient Register,                                   Address offset: 0x08 */
  __IO uint32_t REMD;             /*!< Reminder Register,                                   Address offset: 0x0C */
  __IO uint32_t SR;               /*!< Status Register,                                     Address offset: 0x10 */   
} HDIV_Type;


typedef struct
{
  __IO uint32_t MSPCFGR;          /*!< I2C Master Config Register,                          Address offset: 0x00 */
  __IO uint32_t MSPCR;            /*!< I2C Master Control Register,                         Address offset: 0x04 */
  __IO uint32_t MSPIER;           /*!< I2C Master Intterupt Enable Register,                Address offset: 0x08 */
  __IO uint32_t MSPISR;           /*!< I2C Master Interrupt Status Register,                Address offset: 0x0C */
  __IO uint32_t MSPSR;            /*!< I2C Master Status Register,                          Address offset: 0x10 */
  __IO uint32_t MSPBGR;           /*!< I2C Master Baud rate Generator Register,             Address offset: 0x14 */
  __IO uint32_t MSPBUF;           /*!< I2C Master transfer Buffer,                          Address offset: 0x18 */
  __IO uint32_t MSPTCR;           /*!< I2C Master Timing Control Register,                  Address offset: 0x1C */    
  __IO uint32_t MSPTOR;           /*!< I2C Master Time-Out Register,                        Address offset: 0x20 */    
  __IO uint32_t SSPCR;            /*!< I2C Slave Control Register,                          Address offset: 0x24 */        
  __IO uint32_t SSPIER;           /*!< I2C Slave Interrupt Enable Register,                 Address offset: 0x28 */        
  __IO uint32_t SSPISR;           /*!< I2C Slave Interrupt Status Register,                 Address offset: 0x2C */        
  __IO uint32_t SSPSR;            /*!< I2C Slave Status Register,                           Address offset: 0x30 */    
  __IO uint32_t SSPBUF;           /*!< I2C Slave transfer Buffer,                           Address offset: 0x34 */
  __IO uint32_t SSPADR;           /*!< I2C Slave Address Register,                          Address offset: 0x38 */        
} I2C_Type;

typedef struct
{
  __IO uint32_t SERV;             /*!< IWDT Service Register,                               Address offset: 0x00 */
  __IO uint32_t CR;               /*!< IWDT Config Register,                                Address offset: 0x04 */
  __I  uint32_t CNT;              /*!< IWDT Counter Register,                               Address offset: 0x08 */
  __IO uint32_t WIN;              /*!< IWDT Window Register,                                Address offset: 0x0C */
  __IO uint32_t IER;              /*!< IWDT Status Register,                                Address offset: 0x10 */
  __IO uint32_t ISR;              /*!< IWDT Status Register,                                Address offset: 0x10 */
} IWDT_Type;

typedef struct
{
  __IO uint32_t CR;               /*!< LCD Control Register,                                Address offset: 0x00 */
  __IO uint32_t TEST;             /*!< LCD test Register,                                   Address offset: 0x04 */
  __IO uint32_t FCR;              /*!< LCD Frequency Control Register,                      Address offset: 0x08 */
  __IO uint32_t FLKT;             /*!< LCD Flick Time Register,                             Address offset: 0x0C */  
  __IO uint32_t RSV0;             /*!< NULL,                                                Address offset: 0x10 */
  __IO uint32_t IER;              /*!< LCD Interrupt Enable Register,                       Address offset: 0x14 */
  __IO uint32_t ISR;              /*!< LCD Interrupt Status Register,                       Address offset: 0x18 */
  __IO uint32_t RSV1;             /*!< NULL,                                                Address offset: 0x1C */    
  __IO uint32_t RSV2;             /*!< NULL,                                                Address offset: 0x20 */    
  __IO uint32_t DATA0;            /*!< LCD data buffer registers 0,                         Address offset: 0x24 */    
  __IO uint32_t DATA1;            /*!< LCD data buffer registers 1,                         Address offset: 0x28 */
  __IO uint32_t DATA2;            /*!< LCD data buffer registers 2,                         Address offset: 0x2C */
  __IO uint32_t DATA3;            /*!< LCD data buffer registers 3,                         Address offset: 0x30 */
  __IO uint32_t DATA4;            /*!< LCD data buffer registers 4,                         Address offset: 0x34 */
  __IO uint32_t DATA5;            /*!< LCD data buffer registers 5,                         Address offset: 0x38 */
  __IO uint32_t DATA6;            /*!< LCD data buffer registers 6,                         Address offset: 0x3C */
  __IO uint32_t DATA7;            /*!< LCD data buffer registers 7,                         Address offset: 0x40 */
  __IO uint32_t RSV3;             /*!< NULL,                                                Address offset: 0x44 */
  __IO uint32_t RSV4;             /*!< NULL,                                                Address offset: 0x48 */
  __IO uint32_t RSV5;             /*!< NULL,                                                Address offset: 0x4C */
  __IO uint32_t COMEN;            /*!< LCD COM Enable Register,                             Address offset: 0x50 */
  __IO uint32_t SEGEN0;           /*!< LCD SEG Enable Register0,                            Address offset: 0x54 */
} LCD_Type;

typedef struct
{
  __IO uint32_t CFGR;             /*!< LPTIM Config Register,                               Address offset: 0x00 */
  __IO uint32_t CNT;              /*!< LPTIM Counter Register,                              Address offset: 0x04 */
  __IO uint32_t CCSR;             /*!< LPTIM Capture/Compare Control and Status Register,   Address offset: 0x08 */
  __IO uint32_t ARR;              /*!< LPTIM Auto-Reload Register,                          Address offset: 0x0C */
  __IO uint32_t IER;              /*!< LPTIM Interrupt Enable Register,                     Address offset: 0x10 */
  __IO uint32_t ISR;              /*!< LPTIM Interrupt Status Register,                     Address offset: 0x14 */
  __IO uint32_t CR;               /*!< LPTIM Control Register,                              Address offset: 0x18 */    
  __IO uint32_t RSV;              /*!< RESERVED REGISTER,                                   Address offset: 0x1C */
  __IO uint32_t CCR1;             /*!< LPTIM Capture/Compare Register1,                     Address offset: 0x20 */
  __IO uint32_t CCR2;             /*!< LPTIM Capture/Compare Register2,                     Address offset: 0x24 */
} LPTIM_Type;

typedef struct
{
  __IO uint32_t CSR;              /*!< LPUART Control Status Register,                      Address offset: 0x00 */
  __IO uint32_t IER;              /*!< LPUART Interrupt Enable Register,                    Address offset: 0x04 */
  __IO uint32_t ISR;              /*!< LPUART Interrupt Status Register,                    Address offset: 0x08 */
  __IO uint32_t BMR;              /*!< LPUART Baud rate Modulation Register,                Address offset: 0x0C */
  __IO uint32_t RXBUF;            /*!< LPUART Receive Buffer Register,                      Address offset: 0x10 */
  __IO uint32_t TXBUF;            /*!< LPUART Transmit Buffer Register,                     Address offset: 0x14 */
  __IO uint32_t DMR;              /*!< LPUART  data Matching Register,                      Address offset: 0x18 */    
} LPUART_Type;


typedef struct
{
  __IO uint32_t CR;               /*!< OPA Control Register               */
  __IO uint32_t CALR;             /*!< OPA Calibration Register           */
  __IO uint32_t IER;              /*!< OPA Interrupt Enable Register      */
  __IO uint32_t ISR;              /*!< OPA Interrupt Status Register      */
} OPA_Type;

typedef struct
{
  __IO uint32_t CR;               /*!< Power Management Control Register  */
  __IO uint32_t WKTR;             /*!< Wakeup Time Register               */
  __IO uint32_t WKFR;             /*!< Wakeup Source Flags Register       */
  __IO uint32_t IER;              /*!< PMU Interrupt Enable Register      */
  __IO uint32_t ISR;              /*!< PMU Interrupt and Status Register  */
} PMU_Type;

typedef struct
{
  __IO uint32_t LKPCR;            /*!< Lockup reset Control Register               ,        Address offset: 0x00 */
  __IO uint32_t SOFTRST;          /*!< Software Reset Register                     ,        Address offset: 0x04 */
  __IO uint32_t RSTFR;            /*!< Reset Flag Register                         ,        Address offset: 0x08 */
  __IO uint32_t SYSCLKCR;         /*!< System Clock Control Register               ,        Address offset: 0x0C */
  __IO uint32_t RCHFCR;           /*!< RCHF Control Register                       ,        Address offset: 0x10 */
  __IO uint32_t RCHFTR;           /*!< RCHF Trim Register                          ,        Address offset: 0x14 */
  __IO uint32_t PLLCR;            /*!< PLL Control Register                        ,        Address offset: 0x18 */
  __IO uint32_t LPOSCCR;          /*!< LPOSC Control Register                      ,        Address offset: 0x1C */
  __IO uint32_t LPOSCTR;          /*!< LPOSC Trim Register                         ,        Address offset: 0x20 */
  __IO uint32_t XTLFCR;           /*!< XTLF CONFIG REGISTER                        ,        Address offset: 0x24 */
  __IO uint32_t PCLKCR1;          /*!< Peripheral bus Clock Control Register1      ,        Address offset: 0x28 */
  __IO uint32_t PCLKCR2;          /*!< Peripheral bus Clock Control Register2      ,        Address offset: 0x2C */
  __IO uint32_t PCLKCR3;          /*!< Peripheral bus Clock Control Register3      ,        Address offset: 0x30 */
  __IO uint32_t PCLKCR4;          /*!< Peripheral bus Clock Control Register4      ,        Address offset: 0x34 */
  __IO uint32_t LSCLKSEL;         /*!< LSCLK Select Register                       ,        Address offset: 0x38 */
  __IO uint32_t RSV0;             /*!< RESERVED REGISTER 1                         ,        Address offset: 0x3C */
  __IO uint32_t RSV1;             /*!< RESERVED REGISTER 2                         ,        Address offset: 0x40 */
  __IO uint32_t AHBMCR;           /*!< AHB Master Control Register                 ,        Address offset: 0x44 */
  __IO uint32_t RSV2;             /*!< RESERVED REGISTER 3                         ,        Address offset: 0x48 */
  __IO uint32_t RSV3;             /*!< RESERVED REGISTER 4                         ,        Address offset: 0x4C */
  __IO uint32_t PRSTEN;           /*!< Peripheral Reset Enable Register            ,        Address offset: 0x50 */
  __IO uint32_t AHBRSTCR;         /*!< AHB Peripherals Reset Control Register      ,        Address offset: 0x54 */
  __IO uint32_t APBRSTCR1;        /*!< APB Peripherals Reset Control Register1     ,        Address offset: 0x58 */
  __IO uint32_t APBRSTCR2;        /*!< APB Peripherals Reset Control Register2     ,        Address offset: 0x5C */
  __IO uint32_t XTHFCR;           /*!< XTHF Control Register                       ,        Address offset: 0x60 */
  __IO uint32_t RCMFCR;           /*!< RCMF Control Register                       ,        Address offset: 0x64 */
  __IO uint32_t RCMFTR;           /*!< RCHF Trim Register                          ,        Address offset: 0x68 */    
  __IO uint32_t OPCCR1;           /*!< Peripheral Operation Clock Control Register1,        Address offset: 0x6C */    
  __IO uint32_t OPCCR2;           /*!< Peripheral Operation Clock Control Register2,        Address offset: 0x70 */
  __IO uint32_t PHYCR;            /*!< PHY Control Register                        ,        Address offset: 0x74 */
  __IO uint32_t PHYBCKCR;         /*!< PHY BCK Control Register                    ,        Address offset: 0x78 */
} RCC_Type;


typedef struct
{
  __IO uint32_t PDRCR;            /*!< PDR Control Register  */
  __IO uint32_t BORCR;            /*!< BOR Control Register  */
}RMU_Type;

typedef struct
{
  __IO uint32_t CR;               /*!< RNG CONTROL REGISTER, */
} RNGCTL_Type;

typedef struct
{
  __IO uint32_t RSV0;             /*!< RESERVED REGISTER,                                   Address offset: 0x00 */
  __IO uint32_t DOR;              /*!< RNG OUTPUT REGISTER,                                 Address offset: 0x04 */
  __IO uint32_t RSV1;             /*!< RESERVED REGISTER,                                   Address offset: 0x08 */
  __IO uint32_t RSV2;             /*!< RESERVED REGISTER,                                   Address offset: 0x0C */
  __IO uint32_t SR;               /*!< RNG FLAG REGISTER,                                   Address offset: 0x10 */    
  __IO uint32_t CRCCR;            /*!< RNG CRC CONTROL REGISTER,                            Address offset: 0x14 */    
  __IO uint32_t CRCDIR;           /*!< RNG CRC INPUT REGISTER,                              Address offset: 0x18 */    
  __IO uint32_t CRCSR;            /*!< RNG CRC FLAG REGISTER,                               Address offset: 0x1C */        
} RNG_Type;

typedef struct
{
  __IO uint32_t WER;              /*!< RTC Write Enable Register,                           Address offset: 0x00 */
  __IO uint32_t IER;              /*!< RTC Interrupt Enable Register,                       Address offset: 0x04 */
  __IO uint32_t ISR;              /*!< RTC Interrupt Status Register,                       Address offset: 0x08 */
  __IO uint32_t BCDSEC;           /*!< RTC SECOND IN BCD REGISTER,                          Address offset: 0x0C */
  __IO uint32_t BCDMIN;           /*!< RTC MINITE IN BCD REGISTER,                          Address offset: 0x10 */
  __IO uint32_t BCDHOUR;          /*!< RTC HOUR IN BCD REGISTER,                            Address offset: 0x14 */
  __IO uint32_t BCDDAY;           /*!< RTC DAY IN BCD REGISTER,                             Address offset: 0x18 */
  __IO uint32_t BCDWEEK;          /*!< RTC WEEK IN BCD REGISTER,                            Address offset: 0x1C */    
  __IO uint32_t BCDMONTH;         /*!< RTC MONTH IN BCD REGISTER,                           Address offset: 0x20 */    
  __IO uint32_t BCDYEAR;          /*!< RTC YEAR IN BCD REGISTER,                            Address offset: 0x24 */    
  __IO uint32_t ALARM;            /*!< RTC Alarm Register,                                  Address offset: 0x28 */
  __IO uint32_t TMSEL;            /*!< RTC Time Mark Select,                                Address offset: 0x2C */
  __IO uint32_t ADJUST;           /*!< RTC time Adjust Register,                            Address offset: 0x30 */
  __IO uint32_t ADSIGN;           /*!< RTC time Adjust Sign Register,                       Address offset: 0x34 */
  __IO uint32_t RSV0;             /*!< NULL,                                                Address offset: 0x38 */
  __IO uint32_t SBSCNT;           /*!< RTC Sub-Second Counter,                              Address offset: 0x3C */
  __IO uint32_t RSV1[12];         /*!< NULL,                                                Address offset: 0x40 */
  __IO uint32_t BKR0;             /*!< RTC BACKUP REGISTER0,                                Address offset: 0x70 */
  __IO uint32_t BKR1;             /*!< RTC BACKUP REGISTER1,                                Address offset: 0x74 */
  __IO uint32_t BKR2;             /*!< RTC BACKUP REGISTER2,                                Address offset: 0x78 */
  __IO uint32_t BKR3;             /*!< RTC BACKUP REGISTER3,                                Address offset: 0x7C */
  __IO uint32_t BKR4;             /*!< RTC BACKUP REGISTER4,                                Address offset: 0x80 */
  __IO uint32_t BKR5;             /*!< RTC BACKUP REGISTER5,                                Address offset: 0x84 */
  __IO uint32_t BKR6;             /*!< RTC BACKUP REGISTER6,                                Address offset: 0x88 */
  __IO uint32_t BKR7;             /*!< RTC BACKUP REGISTER7,                                Address offset: 0x8C */
} RTC_Type;

typedef struct
{
  __IO uint32_t CR1;              /*!< SPI1 Control Register1         */
  __IO uint32_t CR2;              /*!< SPI1 Control Register2         */
  __IO uint32_t CR3;              /*!< SPI1 Control Register3         */
  __IO uint32_t IER;              /*!< SPI1 Interrupt Enable Register */
  __IO uint32_t ISR;              /*!< SPI1 Status Register           */    
  __IO uint32_t TXBUF;            /*!< SPI1 Transmit Buffer           */
  __IO uint32_t RXBUF;            /*!< SPI1 Receive Buffer            */
} SPI_Type;


typedef struct
{
  __IO uint32_t CFGR;             /*!< SVD Config Register,                                 Address offset: 0x24 */
  __IO uint32_t CR;               /*!< SVD Control Register,                                Address offset: 0x28 */
  __IO uint32_t IER;              /*!< SVD Interrupt Enable Register,                       Address offset: 0x2C */
  __IO uint32_t ISR;              /*!< SVD Interrupt Status Register,                       Address offset: 0x30 */
  __IO uint32_t VSR;              /*!< SVD reference Voltage Select Register,               Address offset: 0x34 */
} SVD_Type;

typedef struct
{
  __IO uint32_t CR;               /*!< U7816 Control Register,                              Address offset: 0x00 */
  __IO uint32_t FFR;              /*!< U7816 Frame Format Register,                         Address offset: 0x04 */
  __IO uint32_t EGTR;             /*!< U7816 Extra Guard Time Register,                     Address offset: 0x08 */
  __IO uint32_t PSC;              /*!< U7816 Prescaler Register,                            Address offset: 0x0C */
  __IO uint32_t BGR;              /*!< U7816 Baud rate Generator Register,                  Address offset: 0x10 */
  __IO uint32_t RXBUF;            /*!< U7816 Receive Buffer,                                Address offset: 0x14 */
  __IO uint32_t TXBUF;            /*!< U7816 Transmit Buffer,                               Address offset: 0x18 */
  __IO uint32_t IER;              /*!< U7816 Interrupt Enable Register,                     Address offset: 0x1C */
  __IO uint32_t ISR;              /*!< U7816 Interrupt Status Register,                     Address offset: 0x20 */
} U7816_Type;

typedef struct
{
  __IO uint32_t RSV0;             /*!< RESERVED REGISTER0,                                  Address offset: 0x00 */
  __IO uint32_t RSV1;             /*!< RESERVED REGISTER1,                                  Address offset: 0x04 */
  __IO uint32_t GAHBCFG;          /*!< USB AHB Global Config Register,                      Address offset: 0x08 */
  __IO uint32_t GUSBCFG;          /*!< USB Global Config Register,                          Address offset: 0x0C */
  __IO uint32_t GRSTCTL;          /*!< USB Global Reset Control Register,                   Address offset: 0x10 */
  __IO uint32_t GINTSTS;          /*!< USB Global Interrupt Status Register,                Address offset: 0x14 */
  __IO uint32_t GINTMSK;          /*!< USB Global Interrupt Mask Register,                  Address offset: 0x18 */
  __IO uint32_t GRXSTSR;          /*!< USB Receive Status Debug Read Register,              Address offset: 0x1C */
  __IO uint32_t GRXSTSP;          /*!< USB Receive Status and Pop Register,                 Address offset: 0x20 */
  __IO uint32_t GRXFSIZ;          /*!< USB Receive FIFO size Register,                      Address offset: 0x24 */    
  __IO uint32_t GNPTXFSIZ;        /*!< USB Non-Periodic Transmit FIFO size Register,        Address offset: 0x28 */    
  __IO uint32_t RSV2[10];         /*!< Reserved                                                                  */
  __IO uint32_t GLPMCFG;          /*!< USB Low-Power-Mode config Register,                  Address offset: 0x54 */    
  __IO uint32_t RSV3[490];        /*!< Reserved                                                                  */
  __IO uint32_t DCFG;             /*!< USB Device Config Register,                          Address offset: 0x800*/
  __IO uint32_t DCTL;             /*!< USB Device Control Register,                         Address offset: 0x804*/
  __IO uint32_t DSTS;             /*!< USB Device Status Register,                          Address offset: 0x808*/
  __IO uint32_t DIEPMSK;          /*!< USB Device In Endpoint Interrupt Mask Register,      Address offset: 0x810*/
  __IO uint32_t DOEPMSK;          /*!< USB Device OUT Endpoint Interrupt Mask Registe,      Address offset: 0x814*/
  __IO uint32_t DAINT;            /*!< USB Device All Endpoint Interrupt Register,          Address offset: 0x818*/
  __IO uint32_t DAINTMSK;         /*!< USB Device All Endpoint Interrupt Mask Register,     Address offset: 0x81C*/
  __IO uint32_t RSV4[5];          /*!< Reserved                                                                  */
  __IO uint32_t DIEPEMPMSK;       /*!< USB Device IN endpoint FIFO empty interrupt Mask Register,Address offset: 0x834 */
  __IO uint32_t RSV5[50];         /*!< Reserved                                                                  */
  __IO uint32_t DIEPCTL0;         /*!< USB Device In Endpoint 0 Control Register,           Address offset: 0x900*/
  __IO uint32_t RSV6;             /*!< Reserved                                                                  */
  __IO uint32_t DIEPINT0;         /*!< USB Device In Endpoint 0 Interrupt Register,         Address offset: 0x908*/
  __IO uint32_t RSV7;             /*!< Reserved                                                                  */
  __IO uint32_t DIEPTSIZ0;        /*!< USB Device IN Endpoint 0 Transfer Size Register,     Address offset: 0x910*/
  __IO uint32_t RSV8;             /*!< Reserved                                                                  */
  __IO uint32_t DTXFSTS0;         /*!< USB Device In Endpoint 0 Tranmit FIFO Status Register,Address offset: 0x918 */
  __IO uint32_t RSV9;             /*!< Reserved                                                                  */
  __IO uint32_t DIEPCTL1;         /*!< USB Device In Endpoint 1 Control Register,           Address offset: 0x920*/
  __IO uint32_t RSV10;            /*!< Reserved                                                                  */
  __IO uint32_t DIEPINT1;         /*!< USB Device In Endpoint 1 Interrupt Register,         Address offset: 0x928*/
  __IO uint32_t RSV11;            /*!< Reserved                                                                  */
  __IO uint32_t DIEPTSIZ1;        /*!< USB Device IN Endpoint 1 Transfer Size Register,     Address offset: 0x930*/
  __IO uint32_t RSV12;            /*!< Reserved                                                                  */
  __IO uint32_t DTXFSTS1;         /*!< USB Device In Endpoint 1 Tranmit FIFO Status Register,Address offset: 0x938 */
  __IO uint32_t RSV13;            /*!< Reserved                                                                  */
  __IO uint32_t DIEPCTL2;         /*!< USB Device In Endpoint 2 Control Register,           Address offset: 0x940*/
  __IO uint32_t RSV14;            /*!< Reserved                                                                  */
  __IO uint32_t DIEPINT2;         /*!< USB Device In Endpoint 2 Interrupt Register,         Address offset: 0x948*/
  __IO uint32_t RSV15;            /*!< Reserved                                                                  */
  __IO uint32_t DIEPTSIZ2;        /*!< USB Device In Endpoint 2 Tranmit FIFO Status Register,Address offset: 0x950 */
  __IO uint32_t RSV16;            /*!< Reserved                                                                  */
  __IO uint32_t DTXFSTS2;         /*!< USB Device In Endpoint 2 Tranmit FIFO Status Register,Address offset: 0x958 */
  __IO uint32_t RSV17[105];       /*!< Reserved                                                                  */
  __IO uint32_t DOEPCTL0;         /*!< USB Device Out Endpoint 0 Control Register,          Address offset: 0xB00*/
  __IO uint32_t RSV18;            /*!< Reserved                                                                  */
  __IO uint32_t DOEPINT0;         /*!< USB Device Out Endpoint 0 Interrupt Register,        Address offset: 0xB08*/
  __IO uint32_t RSV19;            /*!< Reserved                                                                  */
  __IO uint32_t DOEPTSIZ0;        /*!< USB Device Out Endpoint 0 Transfer Size  Register,   Address offset: 0xB10*/
  __IO uint32_t RSV20;            /*!< Reserved                                                                  */
  __IO uint32_t RSV21;            /*!< Reserved                                                                  */
  __IO uint32_t RSV22;            /*!< Reserved                                                                  */
  __IO uint32_t DOEPCTL1;         /*!< USB Device Out Endpoint 1 Control Register,          Address offset: 0xB20*/
  __IO uint32_t RSV23;            /*!< Reserved                                                                  */
  __IO uint32_t DOEPINT1;         /*!< USB Device Out Endpoint 1 Interrupt Register,        Address offset: 0xB28*/
  __IO uint32_t RSV24;            /*!< Reserved                                                                  */
  __IO uint32_t DOEPTSIZ1;        /*!< USB Device Out Endpoint 1 Transfer Size  Register,   Address offset: 0xB30*/
  __IO uint32_t RSV25;            /*!< Reserved                                                                  */
  __IO uint32_t RSV26;            /*!< Reserved                                                                  */
  __IO uint32_t RSV27;            /*!< Reserved                                                                  */
  __IO uint32_t DOEPCTL2;         /*!< USB Device Out Endpoint 2 Control Register,          Address offset: 0xB40*/
  __IO uint32_t RSV28;            /*!< Reserved                                                                  */
  __IO uint32_t DOEPINT2;         /*!< USB Device Out Endpoint 2 Interrupt Register,        Address offset: 0xB48*/
  __IO uint32_t RSV29;            /*!< Reserved                                                                  */
  __IO uint32_t DOEPTSIZ2;        /*!< USB Device Out Endpoint 2 Transfer Size  Register,   Address offset: 0xB50*/
  __IO uint32_t RSV30[171];       /*!< Reserved                                                                  */
  __IO uint32_t PCGCCTL;          /*!< USB Power Control Global Control Register,           Address offset: 0xE00*/
} USB_Type;

typedef struct 
{
  __IO uint32_t IRCR;             /*!< Infrared modulation Control Register */          
} UART_COMMON_Type;
     
typedef struct 
{
  __IO uint32_t CSR;              /*!< UART Control Status Register      */
  __IO uint32_t IER;              /*!< UART  Interrupt Enable Register   */
  __IO uint32_t ISR;              /*!< UART Interrupt Status Register    */
  __IO uint32_t TODR;             /*!< UART Time-Out and Delay Register  */
  __IO uint32_t RXBUF;            /*!< UART  Receive Buffer              */
  __IO uint32_t TXBUF;            /*!< UART Transmit Buffer              */
  __IO uint32_t BGR;              /*!< UART Baud rate Generator Register */
} UART_Type; 


typedef struct
{
  __IO uint32_t CR;               /*!< VREF Control Register             */
  __IO uint32_t SR;               /*!< VREF Status Register              */
  __IO uint32_t IER;              /*!< VREF Interrupt Enable Register    */
  __IO uint32_t BUFCR;            /*!< VREF Interrupt Enable Register    */
} VREF_Type;

typedef struct
{
  __IO uint32_t CR;               /*!< WWDT Control Register,                               Address offset: 0x00 */
  __IO uint32_t CFGR;             /*!< WWDT Config Register,                                Address offset: 0x04 */
  __IO uint32_t CNT;              /*!< WWDT Counter Register,                               Address offset: 0x08 */
  __IO uint32_t IER;              /*!< WWDT Interrupt Enable Register,                      Address offset: 0x0C */
  __IO uint32_t ISR;              /*!< WWDT Interrupt Status Register,                      Address offset: 0x10 */
  __IO uint32_t PSC;              /*!< WWDT Prescaler Register,                             Address offset: 0x14 */    
} WWDT_Type;



/** @addtogroup Peripheral_memory_map
  * @{
  */       
#define FLASH_BASE            0x00000000UL /*!< FLASH(up to 1 MB) base address in the alias region      */    
#define SRAM_BASE             0x20000000UL
#define PERIPH_BASE           0x40000000UL

/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

/*!< Peripheral memory map */
#define DBG_BASE              (PERIPH_BASE + 0x00000000UL)
#define PMU_BASE              (PERIPH_BASE + 0x00000100UL)
#define RCC_BASE              (PERIPH_BASE + 0x00000200UL)
#define DMA_BASE              (PERIPH_BASE + 0x00000400UL)
#define GPIOA_BASE            (PERIPH_BASE + 0x00000C00UL)
#define GPIOB_BASE            (PERIPH_BASE + 0x00000C40UL)
#define GPIOC_BASE            (PERIPH_BASE + 0x00000C80UL)
#define GPIOD_BASE            (PERIPH_BASE + 0x00000CC0UL)
#define GPIO_COMMON_BASE      (PERIPH_BASE + 0x00000D00UL)
#define FLASH_R_BASE          (PERIPH_BASE + 0x00001000UL)
#define U7816_BASE            (PERIPH_BASE + 0x00010000UL)
#define LPUART0_BASE          (PERIPH_BASE + 0x00010400UL)
#define SPI2_BASE             (PERIPH_BASE + 0x00010800UL)
#define LCD_BASE              (PERIPH_BASE + 0x00010C00UL)    
#define RTC_BASE              (PERIPH_BASE + 0x00011000UL)
#define IWDT_BASE             (PERIPH_BASE + 0x00011400UL)    
#define WWDT_BASE             (PERIPH_BASE + 0x00011800UL)
#define UART0_BASE            (PERIPH_BASE + 0x00011C00UL)
#define UART1_BASE            (PERIPH_BASE + 0x00012000UL)
#define I2C_BASE              (PERIPH_BASE + 0x00012400UL)
#define LPTIM_BASE            (PERIPH_BASE + 0x00013400UL)
#define GPTIM0_BASE           (PERIPH_BASE + 0x00013800UL)
#define GPTIM1_BASE           (PERIPH_BASE + 0x00013C00UL)
#define CRC_BASE              (PERIPH_BASE + 0x00018000UL)    
#define LPUART1_BASE          (PERIPH_BASE + 0x00018400UL)
#define SPI1_BASE             (PERIPH_BASE + 0x00018C00UL)
#define HDIV_BASE             (PERIPH_BASE + 0x00019000UL)
#define UART_COMMON_BASE      (PERIPH_BASE + 0x00019C00UL)    
#define UART4_BASE            (PERIPH_BASE + 0x0001A000UL)    
#define UART5_BASE            (PERIPH_BASE + 0x0001A400UL)    
#define RMU_BASE              (PERIPH_BASE + 0x0001A800UL)
#define VREF_BASE             (PERIPH_BASE + 0x0001A80CUL)
#define SVD_BASE              (PERIPH_BASE + 0x0001A824UL)
#define FDET_BASE             (PERIPH_BASE + 0x0001A838UL)
#define OPA1_BASE             (PERIPH_BASE + 0x0001A844UL)
#define OPA2_BASE             (PERIPH_BASE + 0x0001A854UL)
#define RNGCTL_BASE           (PERIPH_BASE + 0x0001A868UL)
#define COMP1_BASE            (PERIPH_BASE + 0x0001A870UL)
#define COMP2_BASE            (PERIPH_BASE + 0x0001A874UL)
#define COMP_COMMON_BASE      (PERIPH_BASE + 0x0001A878UL)
#define ADC_BASE              (PERIPH_BASE + 0x0001AC00UL)
#define AES_BASE              (PERIPH_BASE + 0x0001B800UL)
#define RNG_BASE              (PERIPH_BASE + 0x0001BC00UL)
#define ATIM_BASE             (PERIPH_BASE + 0x0001B000UL)
#define BSTIM_BASE            (PERIPH_BASE + 0x0001B400UL)
#define USB_BASE              (PERIPH_BASE + 0x10000000UL)
/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define DBG                   ((DBG_Type *) DBG_BASE)
#define PMU                   ((PMU_Type *) PMU_BASE)
#define VREF                  ((VREF_Type *) VREF_BASE)
#define RCC                   ((RCC_Type *) RCC_BASE)
#define RMU                   ((RMU_Type *) RMU_BASE)
#define DMA                   ((DMA_Type *) DMA_BASE)
#define GPIOA                 ((GPIO_Type *) GPIOA_BASE)
#define GPIOB                 ((GPIO_Type *) GPIOB_BASE)
#define GPIOC                 ((GPIO_Type *) GPIOC_BASE)
#define GPIOD                 ((GPIO_Type *) GPIOD_BASE)
#define GPIO_COMMON           ((GPIO_COMMON_Type *) GPIO_COMMON_BASE)
#define FLASH                 ((FLASH_Type *) FLASH_R_BASE)
#define CRC                   ((CRC_Type *) CRC_BASE)
#define LPUART0               ((LPUART_Type *) LPUART0_BASE)
#define LPUART1               ((LPUART_Type *) LPUART1_BASE)
#define SPI1                  ((SPI_Type *) SPI1_BASE)
#define SPI2                  ((SPI_Type *) SPI2_BASE)
#define LCD                   ((LCD_Type *) LCD_BASE)
#define RTC                   ((RTC_Type *) RTC_BASE)
#define IWDT                  ((IWDT_Type *) IWDT_BASE)
#define WWDT                  ((WWDT_Type *) WWDT_BASE)
#define U7816                 ((U7816_Type *) U7816_BASE)
#define UART_COMMON           ((UART_COMMON_Type *) UART_COMMON_BASE)
#define UART0                 ((UART_Type *) UART0_BASE)
#define UART1                 ((UART_Type *) UART1_BASE)
#define UART4                 ((UART_Type *) UART4_BASE)
#define UART5                 ((UART_Type *) UART5_BASE)
#define I2C                   ((I2C_Type *) I2C_BASE)
#define FDET                  ((FDET_Type *) FDET_BASE)
#define SVD                   ((SVD_Type *) SVD_BASE)
#define OPA1                  ((OPA_Type *) OPA1_BASE)
#define OPA2                  ((OPA_Type *) OPA2_BASE)
#define LPTIM                 ((LPTIM_Type *) LPTIM_BASE)
#define AES                   ((AES_Type *) AES_BASE)
#define RNG                   ((RNG_Type *) RNG_BASE)
#define RNGCTL                ((RNGCTL_Type *) RNGCTL_BASE)
#define ATIM                  ((ATIM_Type *) ATIM_BASE)
#define GPTIM0                ((GPTIM_Type *) GPTIM0_BASE)
#define GPTIM1                ((GPTIM_Type *) GPTIM1_BASE)
#define BSTIM                 ((BSTIM_Type *) BSTIM_BASE)
#define ADC                   ((ADC_Type *) ADC_BASE)
#define COMP1                 ((COMP_Type *) COMP1_BASE)
#define COMP2                 ((COMP_Type *) COMP2_BASE)
#define COMP_COMMON          ((COMP_COMMON_Type*)COMP_COMMON_BASE)
#define HDIV                  ((HDIV_Type *) HDIV_BASE)
#define USB                   ((USB_Type *) USB_BASE)
/* ================================================================================ */
/* ================             Peripheral include                 ================ */
/* ================================================================================ */

/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group FM33LC0XX */
/** @} */ /* End of group Keil */

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/
/*
 * @brief Specific device feature definitions (not present on all devices in the FM33LC0XX series)
 */
#define ADC_CR_ADEN_Pos                    (0U)
#define ADC_CR_ADEN_Msk                    (0x1U << ADC_CR_ADEN_Pos)
#define ADC_CR_ADEN                        ADC_CR_ADEN_Msk
#define ADC_CR_START_Pos                   (1U)
#define ADC_CR_START_Msk                   (0x1U << ADC_CR_START_Pos)
#define ADC_CR_START                       ADC_CR_START_Msk
#define ADC_SAMPT_SAMPT_S_Pos              (0U)
#define ADC_SAMPT_SAMPT_S_Msk              (0x1U << ADC_SAMPT_SAMPT_S_Pos)
#define ADC_SAMPT_SAMPT_S                  ADC_SAMPT_SAMPT_S_Msk
#define ADC_CR_EXSAMP_Pos                  (9U)
#define ADC_CR_EXSAMP_Msk                  (0x1U << ADC_CR_EXSAMP_Pos)
#define ADC_CR_EXSAMP                      ADC_CR_EXSAMP_Msk
#define ADC_CR_EXSYNC_Pos                  (8U)
#define ADC_CR_EXSYNC_Msk                  (0x1U << ADC_CR_EXSYNC_Pos)
#define ADC_CR_EXSYNC                      ADC_CR_EXSYNC_Msk
#define ADC_DR_DATA_Pos                    (0U)
#define ADC_DR_DATA_Msk                    (0xffffU << ADC_DR_DATA_Pos)
#define ADC_DR_DATA                        ADC_DR_DATA_Msk
#define ADC_CFGR_EXTS_Pos                  (4U)
#define ADC_CFGR_EXTS_Msk                  (0xfU << ADC_CFGR_EXTS_Pos)
#define ADC_CFGR_EXTS                      ADC_CFGR_EXTS_Msk
#define ADC_CFGR_CONT_Pos                  (9U)
#define ADC_CFGR_CONT_Msk                  (0x1U << ADC_CFGR_CONT_Pos)
#define ADC_CFGR_CONT                      ADC_CFGR_CONT_Msk
#define ADC_IER_EOCIE_Pos                  (0U)
#define ADC_IER_EOCIE_Msk                  (0x1U << ADC_IER_EOCIE_Pos)
#define ADC_IER_EOCIE                      ADC_IER_EOCIE_Msk
#define ADC_IER_EOSIE_Pos                  (1U)
#define ADC_IER_EOSIE_Msk                  (0x1U << ADC_IER_EOSIE_Pos)
#define ADC_IER_EOSIE                      ADC_IER_EOSIE_Msk
#define ADC_IER_OVRIE_Pos                  (2U)
#define ADC_IER_OVRIE_Msk                  (0x1U << ADC_IER_OVRIE_Pos)
#define ADC_IER_OVRIE                      ADC_IER_OVRIE_Msk
#define ADC_IER_AWD_ULIE_Pos               (5U)
#define ADC_IER_AWD_ULIE_Msk               (0x1U << ADC_IER_AWD_ULIE_Pos)
#define ADC_IER_AWD_ULIE                   ADC_IER_AWD_ULIE_Msk
#define ADC_IER_AWD_AHIE_Pos               (6U)
#define ADC_IER_AWD_AHIE_Msk               (0x1U << ADC_IER_AWD_AHIE_Pos)
#define ADC_IER_AWD_AHIE                   ADC_IER_AWD_AHIE_Msk
#define ADC_ISR_EOC_Pos                    (0U)
#define ADC_ISR_EOC_Msk                    (0x1U << ADC_ISR_EOC_Pos)
#define ADC_ISR_EOC                        ADC_ISR_EOC_Msk
#define ADC_ISR_EOS_Pos                    (1U)
#define ADC_ISR_EOS_Msk                    (0x1U << ADC_ISR_EOS_Pos)
#define ADC_ISR_EOS                        ADC_ISR_EOS_Msk
#define ADC_ISR_OVR_Pos                    (2U)
#define ADC_ISR_OVR_Msk                    (0x1U << ADC_ISR_OVR_Pos)
#define ADC_ISR_OVR                        ADC_ISR_OVR_Msk
#define ADC_ISR_BUSY_Pos                   (3U)
#define ADC_ISR_BUSY_Msk                   (0x1U << ADC_ISR_BUSY_Pos)
#define ADC_ISR_BUSY                       ADC_ISR_BUSY_Msk
#define ADC_ISR_AWD_UL_Pos                 (5U)
#define ADC_ISR_AWD_UL_Msk                 (0x1U << ADC_ISR_AWD_UL_Pos)
#define ADC_ISR_AWD_UL                     ADC_ISR_AWD_UL_Msk
#define ADC_ISR_AWD_AH_Pos                 (6U)
#define ADC_ISR_AWD_AH_Msk                 (0x1U << ADC_ISR_AWD_AH_Pos)
#define ADC_ISR_AWD_AH                     ADC_ISR_AWD_AH_Msk
#define ADC_CFGR_AWDCH_Pos                 (26U)
#define ADC_CFGR_AWDCH_Msk                 (0xfU << ADC_CFGR_AWDCH_Pos)
#define ADC_CFGR_AWDCH                     ADC_CFGR_AWDCH_Msk
#define ADC_CFGR_AWDSC_Pos                 (25U)
#define ADC_CFGR_AWDSC_Msk                 (0x1U << ADC_CFGR_AWDSC_Pos)
#define ADC_CFGR_AWDSC                     ADC_CFGR_AWDSC_Msk
#define ADC_CFGR_AWDEN_Pos                 (24U)
#define ADC_CFGR_AWDEN_Msk                 (0x1U << ADC_CFGR_AWDEN_Pos)
#define ADC_CFGR_AWDEN                     ADC_CFGR_AWDEN_Msk
#define ADC_CFGR_OVRM_Pos                  (8U)
#define ADC_CFGR_OVRM_Msk                  (0x1U << ADC_CFGR_OVRM_Pos)
#define ADC_CFGR_OVRM                      ADC_CFGR_OVRM_Msk
#define ADC_CFGR_IOTRFEN_Pos               (14U)
#define ADC_CFGR_IOTRFEN_Msk               (0x1U << ADC_CFGR_IOTRFEN_Pos)
#define ADC_CFGR_IOTRFEN                   ADC_CFGR_IOTRFEN_Msk
#define ADC_CFGR_TRGCFG_Pos                (12U)
#define ADC_CFGR_TRGCFG_Msk                (0x3U << ADC_CFGR_TRGCFG_Pos)
#define ADC_CFGR_TRGCFG                    ADC_CFGR_TRGCFG_Msk
#define ADC_CFGR_SCANDIR_Pos               (2U)
#define ADC_CFGR_SCANDIR_Msk               (0x1U << ADC_CFGR_SCANDIR_Pos)
#define ADC_CFGR_SCANDIR                   ADC_CFGR_SCANDIR_Msk
#define ADC_CFGR_WAIT_Pos                  (10U)
#define ADC_CFGR_WAIT_Msk                  (0x1U << ADC_CFGR_WAIT_Pos)
#define ADC_CFGR_WAIT                      ADC_CFGR_WAIT_Msk
#define ADC_CFGR_SEMI_Pos                  (11U)
#define ADC_CFGR_SEMI_Msk                  (0x1U << ADC_CFGR_SEMI_Pos)
#define ADC_CFGR_SEMI                      ADC_CFGR_SEMI_Msk
#define ADC_HLTR_AWD_LT_Pos                (0U)
#define ADC_HLTR_AWD_LT_Msk                (0xfffU << ADC_HLTR_AWD_LT_Pos)
#define ADC_HLTR_AWD_LT                    ADC_HLTR_AWD_LT_Msk
#define ADC_HLTR_AWD_HT_Pos                (16U)
#define ADC_HLTR_AWD_HT_Msk                (0xfffU << ADC_HLTR_AWD_HT_Pos)
#define ADC_HLTR_AWD_HT                    ADC_HLTR_AWD_HT_Msk
#define ADC_CFGR_OVSEN_Pos                 (16U)
#define ADC_CFGR_OVSEN_Msk                 (0x1U << ADC_CFGR_OVSEN_Pos)
#define ADC_CFGR_OVSEN                     ADC_CFGR_OVSEN_Msk
#define ADC_CFGR_OVSR_Pos                  (17U)
#define ADC_CFGR_OVSR_Msk                  (0x7U << ADC_CFGR_OVSR_Pos)
#define ADC_CFGR_OVSR                      ADC_CFGR_OVSR_Msk
#define ADC_CFGR_OVSS_Pos                  (20U)
#define ADC_CFGR_OVSS_Msk                  (0xfU << ADC_CFGR_OVSS_Pos)
#define ADC_CFGR_OVSS                      ADC_CFGR_OVSS_Msk
#define ADC_CFGR_DMAEN_Pos                 (0U)
#define ADC_CFGR_DMAEN_Msk                 (0x1U << ADC_CFGR_DMAEN_Pos)
#define ADC_CFGR_DMAEN                     ADC_CFGR_DMAEN_Msk
#define ADC_CFGR_DMACFG_Pos                (1U)
#define ADC_CFGR_DMACFG_Msk                (0x1U << ADC_CFGR_DMACFG_Pos)
#define ADC_CFGR_DMACFG                    ADC_CFGR_DMACFG_Msk
#define ADC_SMTR_SMTS1_Pos                 (0U)
#define ADC_SMTR_SMTS1_Msk                 (0xfU << ADC_SMTR_SMTS1_Pos)
#define ADC_SMTR_SMTS1                     ADC_SMTR_SMTS1_Msk
#define ADC_SMTR_SMTS2_Pos                 (4U)
#define ADC_SMTR_SMTS2_Msk                 (0xfU << ADC_SMTR_SMTS2_Pos)
#define ADC_SMTR_SMTS2                     ADC_SMTR_SMTS2_Msk
#define ADC_SMTR_CHCG_Pos                  (8U)
#define ADC_SMTR_CHCG_Msk                  (0xfU << ADC_SMTR_CHCG_Pos)
#define ADC_SMTR_CHCG                      ADC_SMTR_CHCG_Msk

/******************************************************************************/
/*                                                                            */
/*                                   AES                                      */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for AES_CR register  ********************/
#define AES_CR_EN_Pos                      (0U)
#define AES_CR_EN_Msk                      (0x1UL << AES_CR_EN_Pos)
#define AES_CR_EN                          AES_CR_EN_Msk
#define AES_CR_DATATYP_Pos                 (1U)
#define AES_CR_DATATYP_Msk                 (0x3UL << AES_CR_DATATYP_Pos)
#define AES_CR_DATATYP                     AES_CR_DATATYP_Msk
#define AES_CR_MODE_Pos                    (3U)
#define AES_CR_MODE_Msk                    (0x3UL << AES_CR_MODE_Pos)
#define AES_CR_MODE                        AES_CR_MODE_Msk
#define AES_CR_CHMOD_Pos                   (5U)
#define AES_CR_CHMOD_Msk                   (0x3UL << AES_CR_CHMOD_Pos)
#define AES_CR_CHMOD                       AES_CR_CHMOD_Msk
#define AES_CR_DMAIEN_Pos                  (11U)
#define AES_CR_DMAIEN_Msk                  (0x1UL << AES_CR_DMAIEN_Pos)
#define AES_CR_DMAIEN                      AES_CR_DMAIEN_Msk
#define AES_CR_DMAOEN_Pos                  (12U)
#define AES_CR_DMAOEN_Msk                  (0x1UL << AES_CR_DMAOEN_Pos)
#define AES_CR_DMAOEN                      AES_CR_DMAOEN_Msk
#define AES_CR_KEYLEN_Pos                  (13U)
#define AES_CR_KEYLEN_Msk                  (0x3UL << AES_CR_KEYLEN_Pos)
#define AES_CR_KEYLEN                      AES_CR_KEYLEN_Msk

/********************  Bit definition for AES_IER register  *******************/
#define AES_IER_CCF_IE_Pos                 (0U)
#define AES_IER_CCF_IE_Msk                 (0x1UL << AES_IER_CCF_IE_Pos)
#define AES_IER_CCF_IE                     AES_IER_CCF_IE_Msk
#define AES_IER_RDERR_IE_Pos               (1U)
#define AES_IER_RDERR_IE_Msk               (0x1UL << AES_IER_RDERR_IE_Pos)
#define AES_IER_RDERR_IE                   AES_IER_RDERR_IE_Msk
#define AES_IER_WRERR_IE_Pos               (2U)
#define AES_IER_WRERR_IE_Msk               (0x1UL << AES_IER_WRERR_IE_Pos)
#define AES_IER_WRERR_IE                   AES_IER_WRERR_IE_Msk

/********************  Bit definition for AES_ISR register  *******************/
#define AES_ISR_CCF_Pos                    (0U)
#define AES_ISR_CCF_Msk                    (0x1UL << AES_ISR_CCF_Pos)
#define AES_ISR_CCF                        AES_ISR_CCF_Msk
#define AES_ISR_RDERR_Pos                  (1U)
#define AES_ISR_RDERR_Msk                  (0x1UL << AES_ISR_RDERR_Pos)
#define AES_ISR_RDERR                      AES_ISR_RDERR_Msk
#define AES_ISR_WRERR_Pos                  (2U)
#define AES_ISR_WRERR_Msk                  (0x1UL << AES_ISR_WRERR_Pos)
#define AES_ISR_WRERR                      AES_ISR_WRERR_Msk

#define ATIM_CR1_CKD_Pos                   (8U)
#define ATIM_CR1_CKD_Msk                   (0x3UL << ATIM_CR1_CKD_Pos)
#define ATIM_CR1_CKD                       ATIM_CR1_CKD_Msk
#define ATIM_CR1_ARPE_Pos                  (7U)
#define ATIM_CR1_ARPE_Msk                  (0x1UL << ATIM_CR1_ARPE_Pos)
#define ATIM_CR1_ARPE                      ATIM_CR1_ARPE_Msk
#define ATIM_CR1_CMS_Pos                   (5U)
#define ATIM_CR1_CMS_Msk                   (0x3UL << ATIM_CR1_CMS_Pos)
#define ATIM_CR1_CMS                       ATIM_CR1_CMS_Msk
#define ATIM_CR1_DIR_Pos                   (4U)
#define ATIM_CR1_DIR_Msk                   (0x1UL << ATIM_CR1_DIR_Pos)
#define ATIM_CR1_DIR                       ATIM_CR1_DIR_Msk
#define ATIM_CR1_OPM_Pos                   (3U)
#define ATIM_CR1_OPM_Msk                   (0x1UL << ATIM_CR1_OPM_Pos)
#define ATIM_CR1_OPM                       ATIM_CR1_OPM_Msk
#define ATIM_CR1_URS_Pos                   (2U)
#define ATIM_CR1_URS_Msk                   (0x1UL << ATIM_CR1_URS_Pos)
#define ATIM_CR1_URS                       ATIM_CR1_URS_Msk
#define ATIM_CR1_UDIS_Pos                  (1U)
#define ATIM_CR1_UDIS_Msk                  (0x1UL << ATIM_CR1_UDIS_Pos)
#define ATIM_CR1_UDIS                      ATIM_CR1_UDIS_Msk
#define ATIM_CR1_CEN_Pos                   (0U)
#define ATIM_CR1_CEN_Msk                   (0x1UL << ATIM_CR1_CEN_Pos)
#define ATIM_CR1_CEN                       ATIM_CR1_CEN_Msk
#define ATIM_CR2_OISN_Pos                  (9U)
#define ATIM_CR2_OISN_Msk                  (0x1UL << ATIM_CR2_OISN_Pos)
#define ATIM_CR2_OISN                      ATIM_CR2_OISN_Msk
#define ATIM_CR2_OIS_Pos                   (8U)
#define ATIM_CR2_OIS_Msk                   (0x1UL << ATIM_CR2_OIS_Pos)
#define ATIM_CR2_OIS                       ATIM_CR2_OIS_Msk
#define ATIM_CR2_TI1S_Pos                  (7U)
#define ATIM_CR2_TI1S_Msk                  (0x1UL << ATIM_CR2_TI1S_Pos)
#define ATIM_CR2_TI1S                      ATIM_CR2_TI1S_Msk
#define ATIM_CR2_MMS_Pos                   (4U)
#define ATIM_CR2_MMS_Msk                   (0x7UL << ATIM_CR2_MMS_Pos)
#define ATIM_CR2_MMS                       ATIM_CR2_MMS_Msk
#define ATIM_CR2_CCDS_Pos                  (3U)
#define ATIM_CR2_CCDS_Msk                  (0x1UL << ATIM_CR2_CCDS_Pos)
#define ATIM_CR2_CCDS                      ATIM_CR2_CCDS_Msk
#define ATIM_SMCR_ETP_Pos                  (15U)
#define ATIM_SMCR_ETP_Msk                  (0x1UL << ATIM_SMCR_ETP_Pos)
#define ATIM_SMCR_ETP                      ATIM_SMCR_ETP_Msk
#define ATIM_SMCR_ECE_Pos                  (14U)
#define ATIM_SMCR_ECE_Msk                  (0x1UL << ATIM_SMCR_ECE_Pos)
#define ATIM_SMCR_ECE                      ATIM_SMCR_ECE_Msk
#define ATIM_SMCR_ETPS_Pos                 (12U)
#define ATIM_SMCR_ETPS_Msk                 (0x3UL << ATIM_SMCR_ETPS_Pos)
#define ATIM_SMCR_ETPS                     ATIM_SMCR_ETPS_Msk
#define ATIM_SMCR_ETF_Pos                  (8U)
#define ATIM_SMCR_ETF_Msk                  (0xFUL << ATIM_SMCR_ETF_Pos)
#define ATIM_SMCR_ETF                      ATIM_SMCR_ETF_Msk
#define ATIM_SMCR_MSM_Pos                  (7U)
#define ATIM_SMCR_MSM_Msk                  (0x1UL << ATIM_SMCR_MSM_Pos)
#define ATIM_SMCR_MSM                      ATIM_SMCR_MSM_Msk
#define ATIM_SMCR_TS_Pos                   (4U)
#define ATIM_SMCR_TS_Msk                   (0x7UL << ATIM_SMCR_TS_Pos)
#define ATIM_SMCR_TS                       ATIM_SMCR_TS_Msk
#define ATIM_SMCR_SMS_Pos                  (0U)
#define ATIM_SMCR_SMS_Msk                  (0x7UL << ATIM_SMCR_SMS_Pos)
#define ATIM_SMCR_SMS                      ATIM_SMCR_SMS_Msk
#define ATIM_DIER_CC1BURSTEN_Pos           (16U)
#define ATIM_DIER_CC1BURSTEN_Msk           (0x1UL << ATIM_DIER_CC1BURSTEN_Pos)
#define ATIM_DIER_CC1BURSTEN               ATIM_DIER_CC1BURSTEN_Msk
#define ATIM_DIER_CC2BURSTEN_Pos           (17U)
#define ATIM_DIER_CC2BURSTEN_Msk           (0x1UL << ATIM_DIER_CC2BURSTEN_Pos)
#define ATIM_DIER_CC2BURSTEN               ATIM_DIER_CC2BURSTEN_Msk
#define ATIM_DIER_CC3BURSTEN_Pos           (18U)
#define ATIM_DIER_CC3BURSTEN_Msk           (0x1UL << ATIM_DIER_CC3BURSTEN_Pos)
#define ATIM_DIER_CC3BURSTEN               ATIM_DIER_CC3BURSTEN_Msk
#define ATIM_DIER_CC4BURSTEN_Pos           (19U)
#define ATIM_DIER_CC4BURSTEN_Msk           (0x1UL << ATIM_DIER_CC4BURSTEN_Pos)
#define ATIM_DIER_CC4BURSTEN               ATIM_DIER_CC4BURSTEN_Msk
#define ATIM_DIER_TDE_Pos                  (14U)
#define ATIM_DIER_TDE_Msk                  (0x1UL << ATIM_DIER_TDE_Pos)
#define ATIM_DIER_TDE                      ATIM_DIER_TDE_Msk
#define ATIM_DIER_COMDE_Pos                (13U)
#define ATIM_DIER_COMDE_Msk                (0x1UL << ATIM_DIER_COMDE_Pos)
#define ATIM_DIER_COMDE                    ATIM_DIER_COMDE_Msk
#define ATIM_DIER_CCDE_Pos                 (9U)
#define ATIM_DIER_CCDE_Msk                 (0x1UL << ATIM_DIER_CCDE_Pos)
#define ATIM_DIER_CCDE                     ATIM_DIER_CCDE_Msk
#define ATIM_DIER_UDE_Pos                  (8U)
#define ATIM_DIER_UDE_Msk                  (0x1UL << ATIM_DIER_UDE_Pos)
#define ATIM_DIER_UDE                      ATIM_DIER_UDE_Msk
#define ATIM_DIER_BIE_Pos                  (7U)
#define ATIM_DIER_BIE_Msk                  (0x1UL << ATIM_DIER_BIE_Pos)
#define ATIM_DIER_BIE                      ATIM_DIER_BIE_Msk
#define ATIM_DIER_TIE_Pos                  (6U)
#define ATIM_DIER_TIE_Msk                  (0x1UL << ATIM_DIER_TIE_Pos)
#define ATIM_DIER_TIE                      ATIM_DIER_TIE_Msk
#define ATIM_DIER_COMIE_Pos                (5U)
#define ATIM_DIER_COMIE_Msk                (0x1UL << ATIM_DIER_COMIE_Pos)
#define ATIM_DIER_COMIE                    ATIM_DIER_COMIE_Msk
#define ATIM_DIER_CCIE_Pos                 (1U)
#define ATIM_DIER_CCIE_Msk                 (0x1UL << ATIM_DIER_CCIE_Pos)
#define ATIM_DIER_CCIE                     ATIM_DIER_CCIE_Msk
#define ATIM_DIER_UIE_Pos                  (0U)
#define ATIM_DIER_UIE_Msk                  (0x1UL << ATIM_DIER_UIE_Pos)
#define ATIM_DIER_UIE                      ATIM_DIER_UIE_Msk
#define ATIM_ISR_CCOF_Pos                  (9U)
#define ATIM_ISR_CCOF_Msk                  (0x1UL << ATIM_ISR_CCOF_Pos)
#define ATIM_ISR_CCOF                      ATIM_ISR_CCOF_Msk
#define ATIM_ISR_BIF_Pos                   (7U)
#define ATIM_ISR_BIF_Msk                   (0x1UL << ATIM_ISR_BIF_Pos)
#define ATIM_ISR_BIF                       ATIM_ISR_BIF_Msk
#define ATIM_ISR_TIF_Pos                   (6U)
#define ATIM_ISR_TIF_Msk                   (0x1UL << ATIM_ISR_TIF_Pos)
#define ATIM_ISR_TIF                       ATIM_ISR_TIF_Msk
#define ATIM_ISR_COMIF_Pos                 (5U)
#define ATIM_ISR_COMIF_Msk                 (0x1UL << ATIM_ISR_COMIF_Pos)
#define ATIM_ISR_COMIF                     ATIM_ISR_COMIF_Msk
#define ATIM_ISR_CCIF_Pos                  (1U)
#define ATIM_ISR_CCIF_Msk                  (0x1UL << ATIM_ISR_CCIF_Pos)
#define ATIM_ISR_CCIF                      ATIM_ISR_CCIF_Msk
#define ATIM_ISR_UIF_Pos                   (0U)
#define ATIM_ISR_UIF_Msk                   (0x1UL << ATIM_ISR_UIF_Pos)
#define ATIM_ISR_UIF                       ATIM_ISR_UIF_Msk
#define ATIM_EGR_BG_Pos                    (7U)
#define ATIM_EGR_BG_Msk                    (0x1UL << ATIM_EGR_BG_Pos)
#define ATIM_EGR_BG                        ATIM_EGR_BG_Msk
#define ATIM_EGR_TG_Pos                    (6U)
#define ATIM_EGR_TG_Msk                    (0x1UL << ATIM_EGR_TG_Pos)
#define ATIM_EGR_TG                        ATIM_EGR_TG_Msk
#define ATIM_EGR_COMG_Pos                  (5U)
#define ATIM_EGR_COMG_Msk                  (0x1UL << ATIM_EGR_COMG_Pos)
#define ATIM_EGR_COMG                      ATIM_EGR_COMG_Msk
#define ATIM_EGR_CCG_Pos                   (1U)
#define ATIM_EGR_CCG_Msk                   (0x1UL << ATIM_EGR_CCG_Pos)
#define ATIM_EGR_CCG                       ATIM_EGR_CCG_Msk
#define ATIM_EGR_UG_Pos                    (0U)
#define ATIM_EGR_UG_Msk                    (0x1UL << ATIM_EGR_UG_Pos)
#define ATIM_EGR_UG                        ATIM_EGR_UG_Msk
#define ATIM_DCR_DBL_Pos                   (8U)
#define ATIM_DCR_DBL_Msk                   (0x1FUL << ATIM_DCR_DBL_Pos)
#define ATIM_DCR_DBL                       ATIM_DCR_DBL_Msk
#define ATIM_DCR_DBA_Pos                   (0U)
#define ATIM_DCR_DBA_Msk                   (0x1FUL << ATIM_DCR_DBA_Pos)
#define ATIM_DCR_DBA                       ATIM_DCR_DBA_Msk
#define ATIM_CCMR_OCCE_Pos                 (7U)
#define ATIM_CCMR_OCCE_Msk                 (0x1UL << ATIM_CCMR_OCCE_Pos)
#define ATIM_CCMR_OCCE                     ATIM_CCMR_OCCE_Msk
#define ATIM_CCMR_OCM_Pos                  (4U)
#define ATIM_CCMR_OCM_Msk                  (0x7UL << ATIM_CCMR_OCM_Pos)
#define ATIM_CCMR_OCM                      ATIM_CCMR_OCM_Msk
#define ATIM_CCMR_OCPE_Pos                 (3U)
#define ATIM_CCMR_OCPE_Msk                 (0x1UL << ATIM_CCMR_OCPE_Pos)
#define ATIM_CCMR_OCPE                     ATIM_CCMR_OCPE_Msk
#define ATIM_CCMR_OCFE_Pos                 (2U)
#define ATIM_CCMR_OCFE_Msk                 (0x1UL << ATIM_CCMR_OCFE_Pos)
#define ATIM_CCMR_OCFE                     ATIM_CCMR_OCFE_Msk
#define ATIM_CCMR_ICF_Pos                  (4U)
#define ATIM_CCMR_ICF_Msk                  (0xFUL << ATIM_CCMR_ICF_Pos)
#define ATIM_CCMR_ICF                      ATIM_CCMR_ICF_Msk
#define ATIM_CCMR_ICPSC_Pos                (2U)
#define ATIM_CCMR_ICPSC_Msk                (0x3UL << ATIM_CCMR_ICPSC_Pos)
#define ATIM_CCMR_ICPSC                    ATIM_CCMR_ICPSC_Msk
#define ATIM_CCMR_CCS_Pos                  (0U)
#define ATIM_CCMR_CCS_Msk                  (0x3UL << ATIM_CCMR_CCS_Pos)
#define ATIM_CCMR_CCS                      ATIM_CCMR_CCS_Msk
#define ATIM_CCER_CCNP_Pos                 (3U)
#define ATIM_CCER_CCNP_Msk                 (0x1UL << ATIM_CCER_CCNP_Pos)
#define ATIM_CCER_CCNP                     ATIM_CCER_CCNP_Msk
#define ATIM_CCER_CCNE_Pos                 (2U)
#define ATIM_CCER_CCNE_Msk                 (0x1UL << ATIM_CCER_CCNE_Pos)
#define ATIM_CCER_CCNE                     ATIM_CCER_CCNE_Msk
#define ATIM_CCER_CCOP_Pos                 (1U)
#define ATIM_CCER_CCOP_Msk                 (0x1UL << ATIM_CCER_CCOP_Pos)
#define ATIM_CCER_CCOP                     ATIM_CCER_CCOP_Msk
#define ATIM_CCER_CCIP_Pos                 (1U)
#define ATIM_CCER_CCIP_Msk                 (0x1UL << ATIM_CCER_CCIP_Pos)
#define ATIM_CCER_CCIP                     ATIM_CCER_CCIP_Msk
#define ATIM_CCER_CCE_Pos                  (0U)
#define ATIM_CCER_CCE_Msk                  (0x1UL << ATIM_CCER_CCE_Pos)
#define ATIM_CCER_CCE                      ATIM_CCER_CCE_Msk
#define ATIM_BDTR_MOE_Pos                  (15U)
#define ATIM_BDTR_MOE_Msk                  (0x1UL << ATIM_BDTR_MOE_Pos)
#define ATIM_BDTR_MOE                      ATIM_BDTR_MOE_Msk
#define ATIM_BDTR_AOE_Pos                  (14U)
#define ATIM_BDTR_AOE_Msk                  (0x1UL << ATIM_BDTR_AOE_Pos)
#define ATIM_BDTR_AOE                      ATIM_BDTR_AOE_Msk
#define ATIM_BDTR_BKP_Pos                  (13U)
#define ATIM_BDTR_BKP_Msk                  (0x1UL << ATIM_BDTR_BKP_Pos)
#define ATIM_BDTR_BKP                      ATIM_BDTR_BKP_Msk
#define ATIM_BDTR_BKE_Pos                  (12U)
#define ATIM_BDTR_BKE_Msk                  (0x1UL << ATIM_BDTR_BKE_Pos)
#define ATIM_BDTR_BKE                      ATIM_BDTR_BKE_Msk
#define ATIM_BDTR_OSSR_Pos                 (11U)
#define ATIM_BDTR_OSSR_Msk                 (0x1UL << ATIM_BDTR_OSSR_Pos)
#define ATIM_BDTR_OSSR                     ATIM_BDTR_OSSR_Msk
#define ATIM_BDTR_OSSI_Pos                 (10U)
#define ATIM_BDTR_OSSI_Msk                 (0x1UL << ATIM_BDTR_OSSI_Pos)
#define ATIM_BDTR_OSSI                     ATIM_BDTR_OSSI_Msk
#define ATIM_BDTR_LOCK_Pos                 (8U)
#define ATIM_BDTR_LOCK_Msk                 (0x3UL << ATIM_BDTR_LOCK_Pos)
#define ATIM_BDTR_LOCK                     ATIM_BDTR_LOCK_Msk
#define ATIM_BDTR_DTG_Pos                  (0U)
#define ATIM_BDTR_DTG_Msk                  (0xFFUL << ATIM_BDTR_DTG_Pos)
#define ATIM_BDTR_DTG                      ATIM_BDTR_DTG_Msk
#define ATIM_BKCR_BRK1GATE_Pos             (8U)
#define ATIM_BKCR_BRK1GATE_Msk             (0x1UL << ATIM_BKCR_BRK1GATE_Pos)
#define ATIM_BKCR_BRK1GATE                 ATIM_BKCR_BRK1GATE_Msk
#define ATIM_BKCR_BRK2GATE_Pos             (9U)
#define ATIM_BKCR_BRK2GATE_Msk             (0x1UL << ATIM_BKCR_BRK2GATE_Pos)
#define ATIM_BKCR_BRK2GATE                 ATIM_BKCR_BRK2GATE_Msk
#define ATIM_BKCR_BRKF_Pos                 (4U)
#define ATIM_BKCR_BRKF_Msk                 (0xFUL << ATIM_BKCR_BRKF_Pos)
#define ATIM_BKCR_BRKF                     ATIM_BKCR_BRKF_Msk
#define ATIM_BKCR_BRKCOMB_Pos              (3U)
#define ATIM_BKCR_BRKCOMB_Msk              (0x1UL << ATIM_BKCR_BRKCOMB_Pos)
#define ATIM_BKCR_BRKCOMB                  ATIM_BKCR_BRKCOMB_Msk
#define ATIM_BKCR_HFDET_BRKEN_Pos          (2U)
#define ATIM_BKCR_HFDET_BRKEN_Msk          (0x1UL << ATIM_BKCR_HFDET_BRKEN_Pos)
#define ATIM_BKCR_HFDET_BRKEN              ATIM_BKCR_HFDET_BRKEN_Msk
#define ATIM_BKCR_SVD_BRKEN_Pos            (1U)
#define ATIM_BKCR_SVD_BRKEN_Msk            (0x1UL << ATIM_BKCR_SVD_BRKEN_Pos)
#define ATIM_BKCR_SVD_BRKEN                ATIM_BKCR_SVD_BRKEN_Msk
#define ATIM_BKCR_COMP_BRKEN_Pos           (0U)
#define ATIM_BKCR_COMP_BRKEN_Msk           (0x1UL << ATIM_BKCR_COMP_BRKEN_Pos)
#define ATIM_BKCR_COMP_BRKEN               ATIM_BKCR_COMP_BRKEN_Msk

/******************************************************************************/
/*                                                                            */
/*                                   Comparator                               */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for Comparator register  ******************/

#define COMP_CR_CMPO_Pos                   (8U)
#define COMP_CR_CMPO_Msk                   (0x1U << COMP_CR_CMPO_Pos)
#define COMP_CR_CMPO                       COMP_CR_CMPO_Msk
#define COMP_CR_POL_Pos                    (5U)
#define COMP_CR_POL_Msk                    (0x1U << COMP_CR_POL_Pos)
#define COMP_CR_POL                        COMP_CR_POL_Msk

#define COMP_CR_VPSEL_Pos                  (3U)
#define COMP_CR_VPSEL_Msk                  (0x3U << COMP_CR_VPSEL_Pos)
#define COMP_CR_VPSEL                      COMP_CR_VPSEL_Msk
#define COMP_CR_VNSEL_Pos                  (1U)
#define COMP_CR_VNSEL_Msk                  (0x3U << COMP_CR_VNSEL_Pos)
#define COMP_CR_VNSEL                      COMP_CR_VNSEL_Msk

#define COMP_CR_CMPEN_Pos                  (0U)
#define COMP_CR_CMPEN_Msk                  (0x1U << COMP_CR_CMPEN_Pos)
#define COMP_CR_CMPEN                      COMP_CR_CMPEN_Msk
#define COMP_ICR_CMP1DF_Pos                (8U)
#define COMP_ICR_CMP1DF_Msk                (0x1U << COMP_ICR_CMP1DF_Pos)
#define COMP_ICR_CMP1DF                    COMP_ICR_CMP1DF_Msk
#define COMP_ICR_CMP2DF_Pos                (9U)
#define COMP_ICR_CMP2DF_Msk                (0x1U << COMP_ICR_CMP2DF_Pos)
#define COMP_ICR_CMP2DF                    COMP_ICR_CMP2DF_Msk
#define COMP_ICR_CMP1IE_Pos                (0U)
#define COMP_ICR_CMP1IE_Msk                (0x1U << COMP_ICR_CMP1IE_Pos)
#define COMP_ICR_CMP1IE                    COMP_ICR_CMP1IE_Msk
#define COMP_ICR_CMP2IE_Pos                (1U)
#define COMP_ICR_CMP2IE_Msk                (0x1U << COMP_ICR_CMP2IE_Pos)
#define COMP_ICR_CMP2IE                    COMP_ICR_CMP2IE_Msk
#define COMP_ICR_CMP2SEL_Pos               (4U)
#define COMP_ICR_CMP2SEL_Msk               (0x3U << COMP_ICR_CMP2SEL_Pos)
#define COMP_ICR_CMP2SEL                   COMP_ICR_CMP2SEL_Msk
#define COMP_ICR_CMP1SEL_Pos               (2U)
#define COMP_ICR_CMP1SEL_Msk               (0x3U << COMP_ICR_CMP1SEL_Pos)
#define COMP_ICR_CMP1SEL                   COMP_ICR_CMP1SEL_Msk
#define COMP_ISR_CMP2IF_Pos                (1U)
#define COMP_ISR_CMP2IF_Msk                (0x1U << COMP_ISR_CMP2IF_Pos)
#define COMP_ISR_CMP2IF                    COMP_ISR_CMP2IF_Msk
#define COMP_ISR_CMP1IF_Pos                (0U)
#define COMP_ISR_CMP1IF_Msk                (0x1U << COMP_ISR_CMP1IF_Pos)
#define COMP_ISR_CMP1IF                    COMP_ISR_CMP1IF_Msk
/******************************************************************************/
/*                                                                            */
/*                                   FDET                                     */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for FDET_IER register  ******************/
#define FDET_IER_LFDET_IE_Pos              (0U)
#define FDET_IER_LFDET_IE_Msk              (0x1UL << FDET_IER_LFDET_IE_Pos)
#define FDET_IER_LFDET_IE                  FDET_IER_LFDET_IE_Msk
#define FDET_IER_HFDET_IE_Pos              (1U)
#define FDET_IER_HFDET_IE_Msk              (0x1UL << FDET_IER_HFDET_IE_Pos)
#define FDET_IER_HFDET_IE                  FDET_IER_HFDET_IE_Msk

/********************  Bit definition for FDET_ISR register  ******************/
#define FDET_ISR_LFDETIF_Pos               (0U)
#define FDET_ISR_LFDETIF_Msk               (0x1UL << FDET_ISR_LFDETIF_Pos)
#define FDET_ISR_LFDETIF                   FDET_ISR_LFDETIF_Msk
#define FDET_ISR_HFDETIF_Pos               (1U)
#define FDET_ISR_HFDETIF_Msk               (0x1UL << FDET_ISR_HFDETIF_Pos)
#define FDET_ISR_HFDETIF                   FDET_ISR_HFDETIF_Msk
#define FDET_ISR_LFDETO_Pos                (8U)
#define FDET_ISR_LFDETO_Msk                (0x1UL << FDET_ISR_LFDETO_Pos)
#define FDET_ISR_LFDETO                    FDET_ISR_LFDETO_Msk
#define FDET_ISR_HFDETO_Pos                (9U)
#define FDET_ISR_HFDETO_Msk                (0x1UL << FDET_ISR_HFDETO_Pos)
#define FDET_ISR_HFDETO                    FDET_ISR_HFDETO_Msk

/******************************************************************************/
/*                                                                            */
/*                                   FLASH                                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for FLASH_RDCR register  ****************/
#define FLASH_RDCR_WAIT_Pos                (0U)
#define FLASH_RDCR_WAIT_Msk                (0x3UL << FLASH_RDCR_WAIT_Pos)
#define FLASH_RDCR_WAIT                    FLASH_RDCR_WAIT_Msk

/********************  Bit definition for FLASH_PFCR register  ****************/
#define FLASH_PFCR_PRFTEN_Pos              (0U)
#define FLASH_PFCR_PRFTEN_Msk              (0x1UL << FLASH_PFCR_PRFTEN_Pos)
#define FLASH_PFCR_PRFTEN                  FLASH_PFCR_PRFTEN_Msk

/********************  Bit definition for FLASH_OPTBR register  ***************/
#define FLASH_OPTBR_DBRDPEN_Pos            (0U)
#define FLASH_OPTBR_DBRDPEN_Msk            (0x3UL << FLASH_OPTBR_DBRDPEN_Pos)
#define FLASH_OPTBR_DBRDPEN                FLASH_OPTBR_DBRDPEN_Msk
#define FLASH_OPTBR_ACLOCKEN_Pos           (2U)
#define FLASH_OPTBR_ACLOCKEN_Msk           (0x3UL << FLASH_OPTBR_ACLOCKEN_Pos)
#define FLASH_OPTBR_ACLOCKEN               FLASH_OPTBR_ACLOCKEN_Msk
#define FLASH_OPTBR_BTSEN_Pos              (8U)
#define FLASH_OPTBR_BTSEN_Msk              (0x3UL << FLASH_OPTBR_BTSEN_Pos)
#define FLASH_OPTBR_BTSEN                  FLASH_OPTBR_BTSEN_Msk
#define FLASH_OPTBR_DFLSEN_Pos             (10U)
#define FLASH_OPTBR_DFLSEN_Msk             (0x1UL << FLASH_OPTBR_DFLSEN_Pos)
#define FLASH_OPTBR_DFLSEN                 FLASH_OPTBR_DFLSEN_Msk
#define FLASH_OPTBR_IFLOCK_Pos             (17U)
#define FLASH_OPTBR_IFLOCK_Msk             (0x3UL << FLASH_OPTBR_IFLOCK_Pos)
#define FLASH_OPTBR_IFLOCK                 FLASH_OPTBR_IFLOCK_Msk
#define FLASH_OPTBR_IWDTSLP_Pos            (31U)
#define FLASH_OPTBR_IWDTSLP_Msk            (0x1UL << FLASH_OPTBR_IWDTSLP_Pos)
#define FLASH_OPTBR_IWDTSLP                FLASH_OPTBR_IWDTSLP_Msk

/********************  Bit definition for FLASH_EPCR register  ****************/
#define FLASH_EPCR_EREQ_Pos                (0U)
#define FLASH_EPCR_EREQ_Msk                (0x1UL << FLASH_EPCR_EREQ_Pos)
#define FLASH_EPCR_EREQ                    FLASH_EPCR_EREQ_Msk
#define FLASH_EPCR_PREQ_Pos                (1U)
#define FLASH_EPCR_PREQ_Msk                (0x1UL << FLASH_EPCR_PREQ_Pos)
#define FLASH_EPCR_PREQ                    FLASH_EPCR_PREQ_Msk
#define FLASH_EPCR_ERTYPE_Pos              (8U)
#define FLASH_EPCR_ERTYPE_Msk              (0x3UL << FLASH_EPCR_ERTYPE_Pos)
#define FLASH_EPCR_ERTYPE                  FLASH_EPCR_ERTYPE_Msk

/********************  Bit definition for FLASH_IER register  *****************/
#define FLASH_IER_ERDIE_Pos                (0U)
#define FLASH_IER_ERDIE_Msk                (0x1UL << FLASH_IER_ERDIE_Pos)
#define FLASH_IER_ERDIE                    FLASH_IER_ERDIE_Msk
#define FLASH_IER_PRDIE_Pos                (1U)
#define FLASH_IER_PRDIE_Msk                (0x1UL << FLASH_IER_PRDIE_Pos)
#define FLASH_IER_PRDIE                    FLASH_IER_PRDIE_Msk
#define FLASH_IER_CKIE_Pos                 (8U)
#define FLASH_IER_CKIE_Msk                 (0x1UL << FLASH_IER_CKIE_Pos)
#define FLASH_IER_CKIE                     FLASH_IER_CKIE_Msk
#define FLASH_IER_KEYIE_Pos                (9U)
#define FLASH_IER_KEYIE_Msk                (0x1UL << FLASH_IER_KEYIE_Pos)
#define FLASH_IER_KEYIE                    FLASH_IER_KEYIE_Msk
#define FLASH_IER_AUTHIE_Pos               (10U)
#define FLASH_IER_AUTHIE_Msk               (0x1UL << FLASH_IER_AUTHIE_Pos)
#define FLASH_IER_AUTHIE                   FLASH_IER_AUTHIE_Msk
#define FLASH_IER_OPTIE_Pos                (11U)
#define FLASH_IER_OPTIE_Msk                (0x1UL << FLASH_IER_OPTIE_Pos)
#define FLASH_IER_OPTIE                    FLASH_IER_OPTIE_Msk

/********************  Bit definition for FLASH_ISR register  *****************/
#define FLASH_ISR_ERD_Pos                  (0U)
#define FLASH_ISR_ERD_Msk                  (0x1UL << FLASH_ISR_ERD_Pos)
#define FLASH_ISR_ERD                      FLASH_ISR_ERD_Msk
#define FLASH_ISR_PRD_Pos                  (1U)
#define FLASH_ISR_PRD_Msk                  (0x1UL << FLASH_ISR_PRD_Pos)
#define FLASH_ISR_PRD                      FLASH_ISR_PRD_Msk
#define FLASH_ISR_CKERR_Pos                (8U)
#define FLASH_ISR_CKERR_Msk                (0x1UL << FLASH_ISR_CKERR_Pos)
#define FLASH_ISR_CKERR                    FLASH_ISR_CKERR_Msk
#define FLASH_ISR_KEYERR_Pos               (9U)
#define FLASH_ISR_KEYERR_Msk               (0x1UL << FLASH_ISR_KEYERR_Pos)
#define FLASH_ISR_KEYERR                   FLASH_ISR_KEYERR_Msk
#define FLASH_ISR_AUTHERR_Pos              (10U)
#define FLASH_ISR_AUTHERR_Msk              (0x1UL << FLASH_ISR_AUTHERR_Pos)
#define FLASH_ISR_AUTHERR                  FLASH_ISR_AUTHERR_Msk
#define FLASH_ISR_OPTERR_Pos               (11U)
#define FLASH_ISR_OPTERR_Msk               (0x1UL << FLASH_ISR_OPTERR_Pos)
#define FLASH_ISR_OPTERR                   FLASH_ISR_OPTERR_Msk
#define FLASH_ISR_BTSTA_Pos                (16U)
#define FLASH_ISR_BTSTA_Msk                (0x1UL << FLASH_ISR_BTSTA_Pos)
#define FLASH_ISR_BTSTA                    FLASH_ISR_BTSTA_Msk
#define FLASH_ISR_KEYSTA_Pos               (17U)
#define FLASH_ISR_KEYSTA_Msk               (0x7UL << FLASH_ISR_KEYSTA_Pos)
#define FLASH_ISR_KEYSTA                   FLASH_ISR_KEYSTA_Msk

#define HDIV_SR_DIV_BY_0_Pos               (1U)
#define HDIV_SR_DIV_BY_0_Msk               (0x1UL << HDIV_SR_DIV_BY_0_Pos)
#define HDIV_SR_DIV_BY_0                   HDIV_SR_DIV_BY_0_Msk
#define HDIV_SR_BUSY_Pos                   (0U)
#define HDIV_SR_BUSY_Msk                   (0x1UL << HDIV_SR_BUSY_Pos)
#define HDIV_SR_BUSY                       HDIV_SR_BUSY_Msk

#define I2C_MSPCFGR_MSPEN_Pos              (0U)
#define I2C_MSPCFGR_MSPEN_Msk              (0x1UL << I2C_MSPCFGR_MSPEN_Pos)
#define I2C_MSPCFGR_MSPEN                  I2C_MSPCFGR_MSPEN_Msk
#define I2C_MSPCFGR_TOEN_Pos               (1U)
#define I2C_MSPCFGR_TOEN_Msk               (0x1UL << I2C_MSPCFGR_TOEN_Pos)
#define I2C_MSPCFGR_TOEN                   I2C_MSPCFGR_TOEN_Msk
#define I2C_MSPCFGR_MSP_DMAEN_Pos          (16U)
#define I2C_MSPCFGR_MSP_DMAEN_Msk          (0x1UL << I2C_MSPCFGR_MSP_DMAEN_Pos)
#define I2C_MSPCFGR_MSP_DMAEN              I2C_MSPCFGR_MSP_DMAEN_Msk
#define I2C_MSPCFGR_AUTOEND_Pos            (17U)
#define I2C_MSPCFGR_AUTOEND_Msk            (0x1UL << I2C_MSPCFGR_AUTOEND_Pos)
#define I2C_MSPCFGR_AUTOEND                I2C_MSPCFGR_AUTOEND_Msk
#define I2C_MSPCR_RCEN_Pos                 (3U)
#define I2C_MSPCR_RCEN_Msk                 (0x1UL << I2C_MSPCR_RCEN_Pos)
#define I2C_MSPCR_RCEN                     I2C_MSPCR_RCEN_Msk
#define I2C_MSPCR_PEN_Pos                  (2U)
#define I2C_MSPCR_PEN_Msk                  (0x1UL << I2C_MSPCR_PEN_Pos)
#define I2C_MSPCR_PEN                      I2C_MSPCR_PEN_Msk
#define I2C_MSPCR_RSEN_Pos                 (1U)
#define I2C_MSPCR_RSEN_Msk                 (0x1UL << I2C_MSPCR_RSEN_Pos)
#define I2C_MSPCR_RSEN                     I2C_MSPCR_RSEN_Msk
#define I2C_MSPCR_SEN_Pos                  (0U)
#define I2C_MSPCR_SEN_Msk                  (0x1UL << I2C_MSPCR_SEN_Pos)
#define I2C_MSPCR_SEN                      I2C_MSPCR_SEN_Msk
#define I2C_MSPIER_WCOLE_Pos               (6U)
#define I2C_MSPIER_WCOLE_Msk               (0x1UL << I2C_MSPIER_WCOLE_Pos)
#define I2C_MSPIER_WCOLE                   I2C_MSPIER_WCOLE_Msk
#define I2C_MSPIER_OVTE_Pos                (5U)
#define I2C_MSPIER_OVTE_Msk                (0x1UL << I2C_MSPIER_OVTE_Pos)
#define I2C_MSPIER_OVTE                    I2C_MSPIER_OVTE_Msk
#define I2C_MSPIER_SE_Pos                  (4U)
#define I2C_MSPIER_SE_Msk                  (0x1UL << I2C_MSPIER_SE_Pos)
#define I2C_MSPIER_SE                      I2C_MSPIER_SE_Msk
#define I2C_MSPIER_PE_Pos                  (3U)
#define I2C_MSPIER_PE_Msk                  (0x1UL << I2C_MSPIER_PE_Pos)
#define I2C_MSPIER_PE                      I2C_MSPIER_PE_Msk
#define I2C_MSPIER_NACKE_Pos               (2U)
#define I2C_MSPIER_NACKE_Msk               (0x1UL << I2C_MSPIER_NACKE_Pos)
#define I2C_MSPIER_NACKE                   I2C_MSPIER_NACKE_Msk
#define I2C_MSPIER_TXIE_Pos                (1U)
#define I2C_MSPIER_TXIE_Msk                (0x1UL << I2C_MSPIER_TXIE_Pos)
#define I2C_MSPIER_TXIE                    I2C_MSPIER_TXIE_Msk
#define I2C_MSPIER_RXIE_Pos                (0U)
#define I2C_MSPIER_RXIE_Msk                (0x1UL << I2C_MSPIER_RXIE_Pos)
#define I2C_MSPIER_RXIE                    I2C_MSPIER_RXIE_Msk
#define I2C_MSPISR_WCOL_Pos                (6U)
#define I2C_MSPISR_WCOL_Msk                (0x1UL << I2C_MSPISR_WCOL_Pos)
#define I2C_MSPISR_WCOL                    I2C_MSPISR_WCOL_Msk
#define I2C_MSPISR_OVT_Pos                 (5U)
#define I2C_MSPISR_OVT_Msk                 (0x1UL << I2C_MSPISR_OVT_Pos)
#define I2C_MSPISR_OVT                     I2C_MSPISR_OVT_Msk
#define I2C_MSPISR_S_Pos                   (4U)
#define I2C_MSPISR_S_Msk                   (0x1UL << I2C_MSPISR_S_Pos)
#define I2C_MSPISR_S                       I2C_MSPISR_S_Msk
#define I2C_MSPISR_P_Pos                   (3U)
#define I2C_MSPISR_P_Msk                   (0x1UL << I2C_MSPISR_P_Pos)
#define I2C_MSPISR_P                       I2C_MSPISR_P_Msk
#define I2C_MSPISR_NACK_Pos                (2U)
#define I2C_MSPISR_NACK_Msk                (0x1UL << I2C_MSPISR_NACK_Pos)
#define I2C_MSPISR_NACK                    I2C_MSPISR_NACK_Msk
#define I2C_MSPISR_TXIF_Pos                (1U)
#define I2C_MSPISR_TXIF_Msk                (0x1UL << I2C_MSPISR_TXIF_Pos)
#define I2C_MSPISR_TXIF                    I2C_MSPISR_TXIF_Msk
#define I2C_MSPISR_RXIF_Pos                (0U)
#define I2C_MSPISR_RXIF_Msk                (0x1UL << I2C_MSPISR_RXIF_Pos)
#define I2C_MSPISR_RXIF                    I2C_MSPISR_RXIF_Msk
#define I2C_MSPSR_BUSY_Pos                 (5U)
#define I2C_MSPSR_BUSY_Msk                 (0x1UL << I2C_MSPSR_BUSY_Pos)
#define I2C_MSPSR_BUSY                     I2C_MSPSR_BUSY_Msk
#define I2C_MSPSR_RW_Pos                   (4U)
#define I2C_MSPSR_RW_Msk                   (0x1UL << I2C_MSPSR_RW_Pos)
#define I2C_MSPSR_RW                       I2C_MSPSR_RW_Msk
#define I2C_MSPSR_BF_Pos                   (2U)
#define I2C_MSPSR_BF_Msk                   (0x1UL << I2C_MSPSR_BF_Pos)
#define I2C_MSPSR_BF                       I2C_MSPSR_BF_Msk
#define I2C_MSPSR_ACKMO_Pos                (0U)
#define I2C_MSPSR_ACKMO_Msk                (0x1UL << I2C_MSPSR_ACKMO_Pos)
#define I2C_MSPSR_ACKMO                    I2C_MSPSR_ACKMO_Msk
#define I2C_MSPBGR_MSPBGRH_Pos             (16U)
#define I2C_MSPBGR_MSPBGRH_Msk             (0x1FFUL << I2C_MSPBGR_MSPBGRH_Pos)
#define I2C_MSPBGR_MSPBGRH                 I2C_MSPBGR_MSPBGRH_Msk
#define I2C_MSPBGR_MSPBGRL_Pos             (0U)
#define I2C_MSPBGR_MSPBGRL_Msk             (0x1FFUL << I2C_MSPBGR_MSPBGRL_Pos)
#define I2C_MSPBGR_MSPBGRL                 I2C_MSPBGR_MSPBGRL_Msk
#define I2C_MSPBUF_MSPBUFF_Pos             (0U)
#define I2C_MSPBUF_MSPBUFF_Msk             (0xFFUL << I2C_MSPBUF_MSPBUFF_Pos)
#define I2C_MSPBUF_MSPBUFF                 I2C_MSPBUF_MSPBUFF_Msk
#define I2C_MSPTCR_SDAHD_Pos               (0U)
#define I2C_MSPTCR_SDAHD_Msk               (0x1FFUL << I2C_MSPTCR_SDAHD_Pos)
#define I2C_MSPTCR_SDAHD                   I2C_MSPTCR_SDAHD_Msk
#define I2C_MSPTOR_TIMEOUT_Pos             (0U)
#define I2C_MSPTOR_TIMEOUT_Msk             (0xFFFUL << I2C_MSPTOR_TIMEOUT_Pos)
#define I2C_MSPTOR_TIMEOUT                 I2C_MSPTOR_TIMEOUT_Msk
#define I2C_SSPCR_SCLSEN_Pos               (9U)
#define I2C_SSPCR_SCLSEN_Msk               (0x1UL << I2C_SSPCR_SCLSEN_Pos)
#define I2C_SSPCR_SCLSEN                   I2C_SSPCR_SCLSEN_Msk
#define I2C_SSPCR_SSP_DMAEN_Pos            (8U)
#define I2C_SSPCR_SSP_DMAEN_Msk            (0x1UL << I2C_SSPCR_SSP_DMAEN_Pos)
#define I2C_SSPCR_SSP_DMAEN                I2C_SSPCR_SSP_DMAEN_Msk
#define I2C_SSPCR_ACKEN_Pos                (4U)
#define I2C_SSPCR_ACKEN_Msk                (0x1UL << I2C_SSPCR_ACKEN_Pos)
#define I2C_SSPCR_ACKEN                    I2C_SSPCR_ACKEN_Msk
#define I2C_SSPCR_SDAO_DLYEN_Pos           (3U)
#define I2C_SSPCR_SDAO_DLYEN_Msk           (0x1UL << I2C_SSPCR_SDAO_DLYEN_Pos)
#define I2C_SSPCR_SDAO_DLYEN               I2C_SSPCR_SDAO_DLYEN_Msk
#define I2C_SSPCR_SCLI_ANFEN_Pos           (2U)
#define I2C_SSPCR_SCLI_ANFEN_Msk           (0x1UL << I2C_SSPCR_SCLI_ANFEN_Pos)
#define I2C_SSPCR_SCLI_ANFEN               I2C_SSPCR_SCLI_ANFEN_Msk
#define I2C_SSPCR_A10EN_Pos                (1U)
#define I2C_SSPCR_A10EN_Msk                (0x1UL << I2C_SSPCR_A10EN_Pos)
#define I2C_SSPCR_A10EN                    I2C_SSPCR_A10EN_Msk
#define I2C_SSPCR_SSPEN_Pos                (0U)
#define I2C_SSPCR_SSPEN_Msk                (0x1UL << I2C_SSPCR_SSPEN_Pos)
#define I2C_SSPCR_SSPEN                    I2C_SSPCR_SSPEN_Msk
#define I2C_SSPIER_ADEE_Pos                (7U)
#define I2C_SSPIER_ADEE_Msk                (0x1UL << I2C_SSPIER_ADEE_Pos)
#define I2C_SSPIER_ADEE                    I2C_SSPIER_ADEE_Msk
#define I2C_SSPIER_SE_Pos                  (6U)
#define I2C_SSPIER_SE_Msk                  (0x1UL << I2C_SSPIER_SE_Pos)
#define I2C_SSPIER_SE                      I2C_SSPIER_SE_Msk
#define I2C_SSPIER_PE_Pos                  (5U)
#define I2C_SSPIER_PE_Msk                  (0x1UL << I2C_SSPIER_PE_Pos)
#define I2C_SSPIER_PE                      I2C_SSPIER_PE_Msk
#define I2C_SSPIER_WCOLE_Pos               (4U)
#define I2C_SSPIER_WCOLE_Msk               (0x1UL << I2C_SSPIER_WCOLE_Pos)
#define I2C_SSPIER_WCOLE                   I2C_SSPIER_WCOLE_Msk
#define I2C_SSPIER_SSPOVE_Pos              (3U)
#define I2C_SSPIER_SSPOVE_Msk              (0x1UL << I2C_SSPIER_SSPOVE_Pos)
#define I2C_SSPIER_SSPOVE                  I2C_SSPIER_SSPOVE_Msk
#define I2C_SSPIER_ADME_Pos                (2U)
#define I2C_SSPIER_ADME_Msk                (0x1UL << I2C_SSPIER_ADME_Pos)
#define I2C_SSPIER_ADME                    I2C_SSPIER_ADME_Msk
#define I2C_SSPIER_TXIE_Pos                (1U)
#define I2C_SSPIER_TXIE_Msk                (0x1UL << I2C_SSPIER_TXIE_Pos)
#define I2C_SSPIER_TXIE                    I2C_SSPIER_TXIE_Msk
#define I2C_SSPIER_RXIE_Pos                (0U)
#define I2C_SSPIER_RXIE_Msk                (0x1UL << I2C_SSPIER_RXIE_Pos)
#define I2C_SSPIER_RXIE                    I2C_SSPIER_RXIE_Msk
#define I2C_SSPISR_ADE_Pos                 (7U)
#define I2C_SSPISR_ADE_Msk                 (0x1UL << I2C_SSPISR_ADE_Pos)
#define I2C_SSPISR_ADE                     I2C_SSPISR_ADE_Msk
#define I2C_SSPISR_S_Pos                   (6U)
#define I2C_SSPISR_S_Msk                   (0x1UL << I2C_SSPISR_S_Pos)
#define I2C_SSPISR_S                       I2C_SSPISR_S_Msk
#define I2C_SSPISR_P_Pos                   (5U)
#define I2C_SSPISR_P_Msk                   (0x1UL << I2C_SSPISR_P_Pos)
#define I2C_SSPISR_P                       I2C_SSPISR_P_Msk
#define I2C_SSPISR_WCOL_Pos                (4U)
#define I2C_SSPISR_WCOL_Msk                (0x1UL << I2C_SSPISR_WCOL_Pos)
#define I2C_SSPISR_WCOL                    I2C_SSPISR_WCOL_Msk
#define I2C_SSPISR_SSPOV_Pos               (3U)
#define I2C_SSPISR_SSPOV_Msk               (0x1UL << I2C_SSPISR_SSPOV_Pos)
#define I2C_SSPISR_SSPOV                   I2C_SSPISR_SSPOV_Msk
#define I2C_SSPISR_ADM_Pos                 (2U)
#define I2C_SSPISR_ADM_Msk                 (0x1UL << I2C_SSPISR_ADM_Pos)
#define I2C_SSPISR_ADM                     I2C_SSPISR_ADM_Msk
#define I2C_SSPISR_TXI_Pos                 (1U)
#define I2C_SSPISR_TXI_Msk                 (0x1UL << I2C_SSPISR_TXI_Pos)
#define I2C_SSPISR_TXI                     I2C_SSPISR_TXI_Msk
#define I2C_SSPISR_RXI_Pos                 (0U)
#define I2C_SSPISR_RXI_Msk                 (0x1UL << I2C_SSPISR_RXI_Pos)
#define I2C_SSPISR_RXI                     I2C_SSPISR_RXI_Msk
#define I2C_SSPSR_BUSY_Pos                 (3U)
#define I2C_SSPSR_BUSY_Msk                 (0x1UL << I2C_SSPSR_BUSY_Pos)
#define I2C_SSPSR_BUSY                     I2C_SSPSR_BUSY_Msk
#define I2C_SSPSR_RW_Pos                   (2U)
#define I2C_SSPSR_RW_Msk                   (0x1UL << I2C_SSPSR_RW_Pos)
#define I2C_SSPSR_RW                       I2C_SSPSR_RW_Msk
#define I2C_SSPSR_DA_Pos                   (1U)
#define I2C_SSPSR_DA_Msk                   (0x1UL << I2C_SSPSR_DA_Pos)
#define I2C_SSPSR_DA                       I2C_SSPSR_DA_Msk
#define I2C_SSPSR_BF_Pos                   (0U)
#define I2C_SSPSR_BF_Msk                   (0x1UL << I2C_SSPSR_BF_Pos)
#define I2C_SSPSR_BF                       I2C_SSPSR_BF_Msk

/******************************************************************************/
/*                                                                            */
/*                                   IWDT                                     */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for IWDT_CR register  *******************/
#define IWDT_CR_OVP_Pos                    (0U)
#define IWDT_CR_OVP_Msk                    (0x7UL << IWDT_CR_OVP_Pos)
#define IWDT_CR_OVP                        IWDT_CR_OVP_Msk
#define IWDT_CR_FREEZE_Pos                 (11U)
#define IWDT_CR_FREEZE_Msk                 (0x1UL << IWDT_CR_FREEZE_Pos)
#define IWDT_CR_FREEZE                     IWDT_CR_FREEZE_Msk

/********************  Bit definition for IWDT_CR register  *******************/
#define IWDT_IER_IE_Pos                    (0U)
#define IWDT_IER_IE_Msk                    (0x1UL << IWDT_IER_IE_Pos)
#define IWDT_IER_IE                        IWDT_IER_IE_Msk

/********************  Bit definition for IWDT_CR register  *******************/
#define IWDT_ISR_WINF_Pos                  (0U)
#define IWDT_ISR_WINF_Msk                  (0x1UL << IWDT_ISR_WINF_Pos)
#define IWDT_ISR_WINF                      IWDT_ISR_WINF_Msk

#define IWDT_RELOAD_KEY                    (0x12345A5AUL)


#define LCD_CR_IC_CTRL_Pos                 (16U)
#define LCD_CR_IC_CTRL_Msk                 (0x3U << LCD_CR_IC_CTRL_Pos)
#define LCD_CR_IC_CTRL                     LCD_CR_IC_CTRL_Msk
#define LCD_CR_ENMODE_Pos                  (15U)
#define LCD_CR_ENMODE_Msk                  (0x1U << LCD_CR_ENMODE_Pos)
#define LCD_CR_ENMODE                      LCD_CR_ENMODE_Msk
#define LCD_CR_FLICK_Pos                   (14U)
#define LCD_CR_FLICK_Msk                   (0x1U << LCD_CR_FLICK_Pos)
#define LCD_CR_FLICK                       LCD_CR_FLICK_Msk
#define LCD_CR_BIAS_Pos                    (8U)
#define LCD_CR_BIAS_Msk                    (0xfU << LCD_CR_BIAS_Pos)
#define LCD_CR_BIAS                        LCD_CR_BIAS_Msk
#define LCD_CR_BIASMD_Pos                  (5U)
#define LCD_CR_BIASMD_Msk                  (0x1U << LCD_CR_BIASMD_Pos)
#define LCD_CR_BIASMD                      LCD_CR_BIASMD_Msk
#define LCD_CR_ANTIPOLAR_Pos               (4U)
#define LCD_CR_ANTIPOLAR_Msk               (0x1U << LCD_CR_ANTIPOLAR_Pos)
#define LCD_CR_ANTIPOLAR                   LCD_CR_ANTIPOLAR_Msk
#define LCD_CR_WFT_Pos                     (3U)
#define LCD_CR_WFT_Msk                     (0x1U << LCD_CR_WFT_Pos)
#define LCD_CR_WFT                         LCD_CR_WFT_Msk
#define LCD_CR_LMUX_Pos                    (1U)
#define LCD_CR_LMUX_Msk                    (0x3U << LCD_CR_LMUX_Pos)
#define LCD_CR_LMUX                        LCD_CR_LMUX_Msk
#define LCD_CR_EN_Pos                      (0U)
#define LCD_CR_EN_Msk                      (0x1U << LCD_CR_EN_Pos)
#define LCD_CR_EN                          LCD_CR_EN_Msk
#define LCD_TEST_LCCTRL_Pos                (7U)
#define LCD_TEST_LCCTRL_Msk                (0x1U << LCD_TEST_LCCTRL_Pos)
#define LCD_TEST_LCCTRL                    LCD_TEST_LCCTRL_Msk
#define LCD_TEST_TESTEN_Pos                (0U)
#define LCD_TEST_TESTEN_Msk                (0x1U << LCD_TEST_TESTEN_Pos)
#define LCD_TEST_TESTEN                    LCD_TEST_TESTEN_Msk
#define LCD_FCR_DF_Pos                     (0U)
#define LCD_FCR_DF_Msk                     (0xffU << LCD_FCR_DF_Pos)
#define LCD_FCR_DF                         LCD_FCR_DF_Msk
#define LCD_FLKT_TOFF_Pos                  (8U)
#define LCD_FLKT_TOFF_Msk                  (0xffU << LCD_FLKT_TOFF_Pos)
#define LCD_FLKT_TOFF                      LCD_FLKT_TOFF_Msk
#define LCD_FLKT_TON_Pos                   (0U)
#define LCD_FLKT_TON_Msk                   (0xffU << LCD_FLKT_TON_Pos)
#define LCD_FLKT_TON                       LCD_FLKT_TON_Msk
#define LCD_IER_DONIE_Pos                  (1U)
#define LCD_IER_DONIE_Msk                  (0x1U << LCD_IER_DONIE_Pos)
#define LCD_IER_DONIE                      LCD_IER_DONIE_Msk
#define LCD_IER_DOFFIE_Pos                 (0U)
#define LCD_IER_DOFFIE_Msk                 (0x1U << LCD_IER_DOFFIE_Pos)
#define LCD_IER_DOFFIE                     LCD_IER_DOFFIE_Msk
#define LCD_ISR_DONIF_Pos                  (1U)
#define LCD_ISR_DONIF_Msk                  (0x1U << LCD_ISR_DONIF_Pos)
#define LCD_ISR_DONIF                      LCD_ISR_DONIF_Msk
#define LCD_ISR_DOFFIF_Pos                 (0U)
#define LCD_ISR_DOFFIF_Msk                 (0x1U << LCD_ISR_DOFFIF_Pos)
#define LCD_ISR_DOFFIF                     LCD_ISR_DOFFIF_Msk
#define LCD_DATA0_DSDA_Pos                 (0U)
#define LCD_DATA0_DSDA_Msk                 (0xffffffffU << LCD_DATA0_DSDA_Pos)
#define LCD_DATA0_DSDA                     LCD_DATA0_DSDA_Msk

/******************************************************************************/
/*                                                                            */
/*                                   LPUART                                   */
/*                                                                            */
/******************************************************************************/
#define LPUART_CSR_BUSY_Pos                (24U)
#define LPUART_CSR_BUSY_Msk                (0x1UL << LPUART_CSR_BUSY_Pos)
#define LPUART_CSR_BUSY                    LPUART_CSR_BUSY_Msk
#define LPUART_CSR_WKBYTECFG_Pos           (19U)
#define LPUART_CSR_WKBYTECFG_Msk           (0x1UL << LPUART_CSR_WKBYTECFG_Pos)
#define LPUART_CSR_WKBYTECFG               LPUART_CSR_WKBYTECFG_Msk
#define LPUART_CSR_RXEV_Pos                (16U)
#define LPUART_CSR_RXEV_Msk                (0x3UL << LPUART_CSR_RXEV_Pos)
#define LPUART_CSR_RXEV                    LPUART_CSR_RXEV_Msk
#define LPUART_CSR_IOSWAP_Pos              (11U)
#define LPUART_CSR_IOSWAP_Msk              (0x1UL << LPUART_CSR_IOSWAP_Pos)
#define LPUART_CSR_IOSWAP                  LPUART_CSR_IOSWAP_Msk
#define LPUART_CSR_DMATXIFCFG_Pos          (10U)
#define LPUART_CSR_DMATXIFCFG_Msk          (0x1UL << LPUART_CSR_DMATXIFCFG_Pos)
#define LPUART_CSR_DMATXIFCFG              LPUART_CSR_DMATXIFCFG_Msk
#define LPUART_CSR_BITORD_Pos              (9U)
#define LPUART_CSR_BITORD_Msk              (0x1UL << LPUART_CSR_BITORD_Pos)
#define LPUART_CSR_BITORD                  LPUART_CSR_BITORD_Msk
#define LPUART_CSR_STOPCFG_Pos             (8U)
#define LPUART_CSR_STOPCFG_Msk             (0x1UL << LPUART_CSR_STOPCFG_Pos)
#define LPUART_CSR_STOPCFG                 LPUART_CSR_STOPCFG_Msk
#define LPUART_CSR_PDSEL_Pos               (6U)
#define LPUART_CSR_PDSEL_Msk               (0x3UL << LPUART_CSR_PDSEL_Pos)
#define LPUART_CSR_PDSEL                   LPUART_CSR_PDSEL_Msk
#define LPUART_CSR_PARITY_Pos              (4U)
#define LPUART_CSR_PARITY_Msk              (0x3UL << LPUART_CSR_PARITY_Pos)
#define LPUART_CSR_PARITY                  LPUART_CSR_PARITY_Msk
#define LPUART_CSR_RXPOL_Pos               (3U)
#define LPUART_CSR_RXPOL_Msk               (0x1UL << LPUART_CSR_RXPOL_Pos)
#define LPUART_CSR_RXPOL                   LPUART_CSR_RXPOL_Msk
#define LPUART_CSR_TXPOL_Pos               (2U)
#define LPUART_CSR_TXPOL_Msk               (0x1UL << LPUART_CSR_TXPOL_Pos)
#define LPUART_CSR_TXPOL                   LPUART_CSR_TXPOL_Msk
#define LPUART_CSR_RXEN_Pos                (1U)
#define LPUART_CSR_RXEN_Msk                (0x1UL << LPUART_CSR_RXEN_Pos)
#define LPUART_CSR_RXEN                    LPUART_CSR_RXEN_Msk
#define LPUART_CSR_TXEN_Pos                (0U)
#define LPUART_CSR_TXEN_Msk                (0x1UL << LPUART_CSR_TXEN_Pos)
#define LPUART_CSR_TXEN                    LPUART_CSR_TXEN_Msk
#define LPUART_IER_RXEV_IE_Pos             (12U)
#define LPUART_IER_RXEV_IE_Msk             (0x1UL << LPUART_IER_RXEV_IE_Pos)
#define LPUART_IER_RXEV_IE                 LPUART_IER_RXEV_IE_Msk
#define LPUART_IER_RXERR_IE_Pos            (10U)
#define LPUART_IER_RXERR_IE_Msk            (0x1UL << LPUART_IER_RXERR_IE_Pos)
#define LPUART_IER_RXERR_IE                LPUART_IER_RXERR_IE_Msk
#define LPUART_IER_RXBF_IE_Pos             (8U)
#define LPUART_IER_RXBF_IE_Msk             (0x1UL << LPUART_IER_RXBF_IE_Pos)
#define LPUART_IER_RXBF_IE                 LPUART_IER_RXBF_IE_Msk
#define LPUART_IER_TXBE_IE_Pos             (1U)
#define LPUART_IER_TXBE_IE_Msk             (0x1UL << LPUART_IER_TXBE_IE_Pos)
#define LPUART_IER_TXBE_IE                 LPUART_IER_TXBE_IE_Msk
#define LPUART_IER_TXSE_IE_Pos             (0U)
#define LPUART_IER_TXSE_IE_Msk             (0x1UL << LPUART_IER_TXSE_IE_Pos)
#define LPUART_IER_TXSE_IE                 LPUART_IER_TXSE_IE_Msk
#define LPUART_ISR_RXEVF_Pos               (24U)
#define LPUART_ISR_RXEVF_Msk               (0x1UL << LPUART_ISR_RXEVF_Pos)
#define LPUART_ISR_RXEVF                   LPUART_ISR_RXEVF_Msk
#define LPUART_ISR_TXOV_Pos                (19U)
#define LPUART_ISR_TXOV_Msk                (0x1UL << LPUART_ISR_TXOV_Pos)
#define LPUART_ISR_TXOV                    LPUART_ISR_TXOV_Msk
#define LPUART_ISR_PERR_Pos                (18U)
#define LPUART_ISR_PERR_Msk                (0x1UL << LPUART_ISR_PERR_Pos)
#define LPUART_ISR_PERR                    LPUART_ISR_PERR_Msk
#define LPUART_ISR_FERR_Pos                (17U)
#define LPUART_ISR_FERR_Msk                (0x1UL << LPUART_ISR_FERR_Pos)
#define LPUART_ISR_FERR                    LPUART_ISR_FERR_Msk
#define LPUART_ISR_OERR_Pos                (16U)
#define LPUART_ISR_OERR_Msk                (0x1UL << LPUART_ISR_OERR_Pos)
#define LPUART_ISR_OERR                    LPUART_ISR_OERR_Msk
#define LPUART_ISR_RXBF_Pos                (8U)
#define LPUART_ISR_RXBF_Msk                (0x1UL << LPUART_ISR_RXBF_Pos)
#define LPUART_ISR_RXBF                    LPUART_ISR_RXBF_Msk
#define LPUART_ISR_TXBE_Pos                (1U)
#define LPUART_ISR_TXBE_Msk                (0x1UL << LPUART_ISR_TXBE_Pos)
#define LPUART_ISR_TXBE                    LPUART_ISR_TXBE_Msk
#define LPUART_ISR_TXSE_Pos                (0U)
#define LPUART_ISR_TXSE_Msk                (0x1UL << LPUART_ISR_TXSE_Pos)
#define LPUART_ISR_TXSE                    LPUART_ISR_TXSE_Msk
#define LPUART_BMR_BAUD_Pos                (0U)
#define LPUART_BMR_BAUD_Msk                (0x7UL << LPUART_BMR_BAUD_Pos)
#define LPUART_BMR_BAUD                    LPUART_BMR_BAUD_Msk
#define LPUART_BMR_MCTL_Pos                (16U)
#define LPUART_BMR_MCTL_Msk                (0xFFFUL << LPUART_BMR_MCTL_Pos)
#define LPUART_BMR_MCTL                    LPUART_BMR_MCTL_Msk

#define OPA_CR_BUFFEN_Pos                  (31U)
#define OPA_CR_BUFFEN_Msk                  (0x1UL << OPA_CR_BUFFEN_Pos)
#define OPA_CR_BUFFEN                      OPA_CR_BUFFEN_Msk
#define OPA_CR_BUFBYP_Pos                  (30U)
#define OPA_CR_BUFBYP_Msk                  (0x1UL << OPA_CR_BUFBYP_Pos)
#define OPA_CR_BUFBYP                      OPA_CR_BUFBYP_Msk
#define OPA_CR_VNSEL_Pos                   (9U)
#define OPA_CR_VNSEL_Msk                   (0x7UL << OPA_CR_VNSEL_Pos)
#define OPA_CR_VNSEL                       OPA_CR_VNSEL_Msk
#define OPA_CR_VPSEL_Pos                   (8U)
#define OPA_CR_VPSEL_Msk                   (0x1UL << OPA_CR_VPSEL_Pos)
#define OPA_CR_VPSEL                       OPA_CR_VPSEL_Msk
#define OPA_CR_DF_Pos                      (7U)
#define OPA_CR_DF_Msk                      (0x1UL << OPA_CR_DF_Pos)
#define OPA_CR_DF                          OPA_CR_DF_Msk
#define OPA_CR_VN_EXC_Pos                  (6U)
#define OPA_CR_VN_EXC_Msk                  (0x1UL << OPA_CR_VN_EXC_Pos)
#define OPA_CR_VN_EXC                      OPA_CR_VN_EXC_Msk
#define OPA_CR_PGA_GAIN_Pos                (4U)
#define OPA_CR_PGA_GAIN_Msk                (0x3UL << OPA_CR_PGA_GAIN_Pos)
#define OPA_CR_PGA_GAIN                    OPA_CR_PGA_GAIN_Msk
#define OPA_CR_MOD_Pos                     (2U)
#define OPA_CR_MOD_Msk                     (0x3UL << OPA_CR_MOD_Pos)
#define OPA_CR_MOD                         OPA_CR_MOD_Msk
#define OPA_CR_LPM_Pos                     (1U)
#define OPA_CR_LPM_Msk                     (0x1UL << OPA_CR_LPM_Pos)
#define OPA_CR_LPM                         OPA_CR_LPM_Msk
#define OPA_CR_EN_Pos                      (0U)
#define OPA_CR_EN_Msk                      (0x1UL << OPA_CR_EN_Pos)
#define OPA_CR_EN                          OPA_CR_EN_Msk
#define OPA_CALR_NCAL_EN_Pos               (31U)
#define OPA_CALR_NCAL_EN_Msk               (0x1UL << OPA_CALR_NCAL_EN_Pos)
#define OPA_CALR_NCAL_EN                   OPA_CALR_NCAL_EN_Msk
#define OPA_CALR_NCAL_Pos                  (16U)
#define OPA_CALR_NCAL_Msk                  (0x1FUL << OPA_CALR_NCAL_Pos)
#define OPA_CALR_NCAL                      OPA_CALR_NCAL_Msk
#define OPA_CALR_PCAL_EN_Pos               (15U)
#define OPA_CALR_PCAL_EN_Msk               (0x1UL << OPA_CALR_PCAL_EN_Pos)
#define OPA_CALR_PCAL_EN                   OPA_CALR_PCAL_EN_Msk
#define OPA_CALR_PCAL_Pos                  (0U)
#define OPA_CALR_PCAL_Msk                  (0x1FUL << OPA_CALR_PCAL_Pos)
#define OPA_CALR_PCAL                      OPA_CALR_PCAL_Msk
#define OPA_IER_FIE_Pos                    (1U)
#define OPA_IER_FIE_Msk                    (0x1UL << OPA_IER_FIE_Pos)
#define OPA_IER_FIE                        OPA_IER_FIE_Msk
#define OPA_IER_RIE_Pos                    (0U)
#define OPA_IER_RIE_Msk                    (0x1UL << OPA_IER_RIE_Pos)
#define OPA_IER_RIE                        OPA_IER_RIE_Msk
#define OPA_ISR_FIF_Pos                    (1U)
#define OPA_ISR_FIF_Msk                    (0x1UL << OPA_ISR_FIF_Pos)
#define OPA_ISR_FIF                        OPA_ISR_FIF_Msk
#define OPA_ISR_RIF_Pos                    (0U)
#define OPA_ISR_RIF_Msk                    (0x1UL << OPA_ISR_RIF_Pos)
#define OPA_ISR_RIF                        OPA_ISR_RIF_Msk
#define OPA_ISR_OUT_Pos                    (2U)
#define OPA_ISR_OUT_Msk                    (0x1UL << OPA_ISR_OUT_Pos)
#define OPA_ISR_OUT                        OPA_ISR_OUT_Msk

/******************************************************************************/
/*                                                                            */
/*                                   PMU                                      */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PMU_CR register  ********************/
#define PMU_CR_PMOD_Pos                    (0U)
#define PMU_CR_PMOD_Msk                    (0x3UL << PMU_CR_PMOD_Pos)
#define PMU_CR_PMOD                        PMU_CR_PMOD_Msk
#define PMU_CR_CVS_Pos                     (8U)
#define PMU_CR_CVS_Msk                     (0x1UL << PMU_CR_CVS_Pos)
#define PMU_CR_CVS                         PMU_CR_CVS_Msk
#define PMU_CR_SLPDP_Pos                   (9U)
#define PMU_CR_SLPDP_Msk                   (0x1UL << PMU_CR_SLPDP_Pos)
#define PMU_CR_SLPDP                       PMU_CR_SLPDP_Msk
#define PMU_CR_WKFSEL_Pos                  (10U)
#define PMU_CR_WKFSEL_Msk                  (0x3UL << PMU_CR_WKFSEL_Pos)
#define PMU_CR_WKFSEL                      PMU_CR_WKFSEL_Msk
#define PMU_CR_LDO15EN_Pos                 (17U)
#define PMU_CR_LDO15EN_Msk                 (0x1UL << PMU_CR_LDO15EN_Pos)
#define PMU_CR_LDO15EN                     PMU_CR_LDO15EN_Msk
#define PMU_CR_LDO_LPM_Pos                 (18U)
#define PMU_CR_LDO_LPM_Msk                 (0x3UL << PMU_CR_LDO_LPM_Pos)
#define PMU_CR_LDO_LPM                     PMU_CR_LDO_LPM_Msk

/********************  Bit definition for PMU_WKTR register  ******************/
#define PMU_WKTR_T1A_Pos                   (0U)
#define PMU_WKTR_T1A_Msk                   (0x3UL << PMU_WKTR_T1A_Pos)
#define PMU_WKTR_T1A                       PMU_WKTR_T1A_Msk
#define PMU_WKTR_STPCLR_Pos                (2U)
#define PMU_WKTR_STPCLR_Msk                (0x1UL << PMU_WKTR_STPCLR_Pos)
#define PMU_WKTR_STPCLR                    PMU_WKTR_STPCLR_Msk
#define PMU_WKTR_HDTIM_Pos                 (30U)
#define PMU_WKTR_HDTIM_Msk                 (0x3UL << PMU_WKTR_HDTIM_Pos)
#define PMU_WKTR_HDTIM                     PMU_WKTR_HDTIM_Msk

/********************  Bit definition for PMU_WKFR register  ******************/
#define PMU_WKFR_WKPXF_Pos                 (0U)
#define PMU_WKFR_WKPXF_Msk                 (0xFFUL << PMU_WKFR_WKPXF_Pos)
#define PMU_WKFR_WKPXF                     PMU_WKFR_WKPXF_Msk
#define PMU_WKFR_DBGWKF_Pos                (8U)
#define PMU_WKFR_DBGWKF_Msk                (0x1UL << PMU_WKFR_DBGWKF_Pos)
#define PMU_WKFR_DBGWKF                    PMU_WKFR_DBGWKF_Msk
#define PMU_WKFR_BSTWKF_Pos                (9U)
#define PMU_WKFR_BSTWKF_Msk                (0x1UL << PMU_WKFR_BSTWKF_Pos)
#define PMU_WKFR_BSTWKF                    PMU_WKFR_BSTWKF_Msk
#define PMU_WKFR_LPTWKF_Pos                (10U)
#define PMU_WKFR_LPTWKF_Msk                (0x1UL << PMU_WKFR_LPTWKF_Pos)
#define PMU_WKFR_LPTWKF                    PMU_WKFR_LPTWKF_Msk
#define PMU_WKFR_OPA1WKF_Pos               (16U)
#define PMU_WKFR_OPA1WKF_Msk               (0x1UL << PMU_WKFR_OPA1WKF_Pos)
#define PMU_WKFR_OPA1WKF                   PMU_WKFR_OPA1WKF_Msk
#define PMU_WKFR_OPA2WKF_Pos               (17U)
#define PMU_WKFR_OPA2WKF_Msk               (0x1UL << PMU_WKFR_OPA2WKF_Pos)
#define PMU_WKFR_OPA2WKF                   PMU_WKFR_OPA2WKF_Msk
#define PMU_WKFR_UART0WKF_Pos              (18U)
#define PMU_WKFR_UART0WKF_Msk              (0x1UL << PMU_WKFR_UART0WKF_Pos)
#define PMU_WKFR_UART0WKF                  PMU_WKFR_UART0WKF_Msk
#define PMU_WKFR_UART1WKF_Pos              (19U)
#define PMU_WKFR_UART1WKF_Msk              (0x1UL << PMU_WKFR_UART1WKF_Pos)
#define PMU_WKFR_UART1WKF                  PMU_WKFR_UART1WKF_Msk
#define PMU_WKFR_LPU0WKF_Pos               (20U)
#define PMU_WKFR_LPU0WKF_Msk               (0x1UL << PMU_WKFR_LPU0WKF_Pos)
#define PMU_WKFR_LPU0WKF                   PMU_WKFR_LPU0WKF_Msk
#define PMU_WKFR_LPU1WKF_Pos               (21U)
#define PMU_WKFR_LPU1WKF_Msk               (0x1UL << PMU_WKFR_LPU1WKF_Pos)
#define PMU_WKFR_LPU1WKF                   PMU_WKFR_LPU1WKF_Msk
#define PMU_WKFR_I2CWKF_Pos                (23U)
#define PMU_WKFR_I2CWKF_Msk                (0x1UL << PMU_WKFR_I2CWKF_Pos)
#define PMU_WKFR_I2CWKF                    PMU_WKFR_I2CWKF_Msk
#define PMU_WKFR_IOWKF_Pos                 (24U)
#define PMU_WKFR_IOWKF_Msk                 (0x1UL << PMU_WKFR_IOWKF_Pos)
#define PMU_WKFR_IOWKF                     PMU_WKFR_IOWKF_Msk
#define PMU_WKFR_VREFWKF_Pos               (25U)
#define PMU_WKFR_VREFWKF_Msk               (0x1UL << PMU_WKFR_VREFWKF_Pos)
#define PMU_WKFR_VREFWKF                   PMU_WKFR_VREFWKF_Msk
#define PMU_WKFR_LFDETWKF_Pos              (26U)
#define PMU_WKFR_LFDETWKF_Msk              (0x1UL << PMU_WKFR_LFDETWKF_Pos)
#define PMU_WKFR_LFDETWKF                  PMU_WKFR_LFDETWKF_Msk
#define PMU_WKFR_SVDWKF_Pos                (27U)
#define PMU_WKFR_SVDWKF_Msk                (0x1UL << PMU_WKFR_SVDWKF_Pos)
#define PMU_WKFR_SVDWKF                    PMU_WKFR_SVDWKF_Msk
#define PMU_WKFR_RTCWKF_Pos                (28U)
#define PMU_WKFR_RTCWKF_Msk                (0x1UL << PMU_WKFR_RTCWKF_Pos)
#define PMU_WKFR_RTCWKF                    PMU_WKFR_RTCWKF_Msk
#define PMU_WKFR_ADCWKF_Pos                (31U)
#define PMU_WKFR_ADCWKF_Msk                (0x1UL << PMU_WKFR_ADCWKF_Pos)
#define PMU_WKFR_ADCWKF                    PMU_WKFR_ADCWKF_Msk

/********************  Bit definition for PMU_IER register  *******************/
#define PMU_IER_RTCEIE_Pos                 (0U)
#define PMU_IER_RTCEIE_Msk                 (0x1UL << PMU_IER_RTCEIE_Pos)
#define PMU_IER_RTCEIE                     PMU_IER_RTCEIE_Msk
#define PMU_IER_SLPEIE_Pos                 (1U)
#define PMU_IER_SLPEIE_Msk                 (0x1UL << PMU_IER_SLPEIE_Pos)
#define PMU_IER_SLPEIE                     PMU_IER_SLPEIE_Msk
#define PMU_IER_LPACTEIE_Pos               (2U)
#define PMU_IER_LPACTEIE_Msk               (0x1UL << PMU_IER_LPACTEIE_Pos)
#define PMU_IER_LPACTEIE                   PMU_IER_LPACTEIE_Msk
#define PMU_IER_LPRUNEIE_Pos               (3U)
#define PMU_IER_LPRUNEIE_Msk               (0x1UL << PMU_IER_LPRUNEIE_Pos)
#define PMU_IER_LPRUNEIE                   PMU_IER_LPRUNEIE_Msk

/********************  Bit definition for PMU_ISR register  *******************/
#define PMU_ISR_RTCEIF_Pos                 (0U)
#define PMU_ISR_RTCEIF_Msk                 (0x1UL << PMU_ISR_RTCEIF_Pos)
#define PMU_ISR_RTCEIF                     PMU_ISR_RTCEIF_Msk
#define PMU_ISR_SLPEIF_Pos                 (1U)
#define PMU_ISR_SLPEIF_Msk                 (0x1UL << PMU_ISR_SLPEIF_Pos)
#define PMU_ISR_SLPEIF                     PMU_ISR_SLPEIF_Msk
#define PMU_ISR_LPACTEIF_Pos               (2U)
#define PMU_ISR_LPACTEIF_Msk               (0x1UL << PMU_ISR_LPACTEIF_Pos)
#define PMU_ISR_LPACTEIF                   PMU_ISR_LPACTEIF_Msk
#define PMU_ISR_SLPUNEIE_Pos               (3U)
#define PMU_ISR_SLPUNEIE_Msk               (0x1UL << PMU_ISR_SLPUNEIE_Pos)
#define PMU_ISR_SLPUNEIE                   PMU_ISR_SLPUNEIE_Msk

/******************************************************************************/
/*                                                                            */
/*                                   RCC                                      */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_SYSCLKCR register  **************/
#define RCC_SYSCLKCR_SYSCLKSEL_Pos         (0U)
#define RCC_SYSCLKCR_SYSCLKSEL_Msk         (0x7UL << RCC_SYSCLKCR_SYSCLKSEL_Pos)
#define RCC_SYSCLKCR_SYSCLKSEL             RCC_SYSCLKCR_SYSCLKSEL_Msk
#define RCC_SYSCLKCR_BCKOSEL_Pos           (3U)
#define RCC_SYSCLKCR_BCKOSEL_Msk           (0x1UL << RCC_SYSCLKCR_BCKOSEL_Pos)
#define RCC_SYSCLKCR_BCKOSEL               RCC_SYSCLKCR_BCKOSEL_Msk
#define RCC_SYSCLKCR_STCLKSEL_Pos          (6U)
#define RCC_SYSCLKCR_STCLKSEL_Msk          (0x3UL << RCC_SYSCLKCR_STCLKSEL_Pos)
#define RCC_SYSCLKCR_STCLKSEL              RCC_SYSCLKCR_STCLKSEL_Msk
#define RCC_SYSCLKCR_APBPRES1_Pos          (16U)
#define RCC_SYSCLKCR_APBPRES1_Msk          (0x7UL << RCC_SYSCLKCR_APBPRES1_Pos)
#define RCC_SYSCLKCR_APBPRES1              RCC_SYSCLKCR_APBPRES1_Msk
#define RCC_SYSCLKCR_AHBPRES_Pos           (8U)
#define RCC_SYSCLKCR_AHBPRES_Msk           (0x7UL << RCC_SYSCLKCR_AHBPRES_Pos)
#define RCC_SYSCLKCR_AHBPRES               RCC_SYSCLKCR_AHBPRES_Msk
#define RCC_SYSCLKCR_APBPRES2_Pos          (19U)
#define RCC_SYSCLKCR_APBPRES2_Msk          (0x7UL << RCC_SYSCLKCR_APBPRES2_Pos)
#define RCC_SYSCLKCR_APBPRES2              RCC_SYSCLKCR_APBPRES2_Msk
#define RCC_SYSCLKCR_SLP_ENEXTI_Pos        (25U)
#define RCC_SYSCLKCR_SLP_ENEXTI_Msk        (0x1UL << RCC_SYSCLKCR_SLP_ENEXTI_Pos)
#define RCC_SYSCLKCR_SLP_ENEXTI            RCC_SYSCLKCR_SLP_ENEXTI_Msk
#define RCC_SYSCLKCR_LSCATS_Pos            (27U)
#define RCC_SYSCLKCR_LSCATS_Msk            (0x1UL << RCC_SYSCLKCR_LSCATS_Pos)
#define RCC_SYSCLKCR_LSCATS                RCC_SYSCLKCR_LSCATS_Msk

/********************  Bit definition for RCC_RCHFCR register  ****************/
#define RCC_RCHFCR_EN_Pos                  (0U)
#define RCC_RCHFCR_EN_Msk                  (0x1UL << RCC_RCHFCR_EN_Pos)
#define RCC_RCHFCR_EN                      RCC_RCHFCR_EN_Msk
#define RCC_RCHFCR_FSEL_Pos                (16U)
#define RCC_RCHFCR_FSEL_Msk                (0xFUL << RCC_RCHFCR_FSEL_Pos)
#define RCC_RCHFCR_FSEL                    RCC_RCHFCR_FSEL_Msk

/********************  Bit definition for RCC_RCMFTR register  ****************/
#define RCC_RCMFTR_TRIM_Pos                (0U)
#define RCC_RCMFTR_TRIM_Msk                (0x7FUL << RCC_RCMFTR_TRIM_Pos)
#define RCC_RCMFTR_TRIM                    RCC_RCMFTR_TRIM_Msk

/********************  Bit definition for RCC_PLLCR register  *****************/
#define RCC_PLLCR_EN_Pos                   (0U)
#define RCC_PLLCR_EN_Msk                   (0x1UL << RCC_PLLCR_EN_Pos)
#define RCC_PLLCR_EN                       RCC_PLLCR_EN_Msk
#define RCC_PLLCR_INSEL_Pos                (1U)
#define RCC_PLLCR_INSEL_Msk                (0x1UL << RCC_PLLCR_INSEL_Pos)
#define RCC_PLLCR_INSEL                    RCC_PLLCR_INSEL_Msk
#define RCC_PLLCR_OSEL_Pos                 (3U)
#define RCC_PLLCR_OSEL_Msk                 (0x1UL << RCC_PLLCR_OSEL_Pos)
#define RCC_PLLCR_OSEL                     RCC_PLLCR_OSEL_Msk
#define RCC_PLLCR_REFPRSC_Pos              (4U)
#define RCC_PLLCR_REFPRSC_Msk              (0x7UL << RCC_PLLCR_REFPRSC_Pos)
#define RCC_PLLCR_REFPRSC                  RCC_PLLCR_REFPRSC_Msk
#define RCC_PLLCR_LOCKED_Pos               (7U)
#define RCC_PLLCR_LOCKED_Msk               (0x1UL << RCC_PLLCR_LOCKED_Pos)
#define RCC_PLLCR_LOCKED                   RCC_PLLCR_LOCKED_Msk
#define RCC_PLLCR_DB_Pos                   (16U)
#define RCC_PLLCR_DB_Msk                   (0x7FUL << RCC_PLLCR_DB_Pos)
#define RCC_PLLCR_DB                       RCC_PLLCR_DB_Msk

/********************  Bit definition for RCC_LPOSCTR register  ***************/
#define RCC_LPOSCTR_TRIM_Pos               (0U)
#define RCC_LPOSCTR_TRIM_Msk               (0xFFUL << RCC_LPOSCTR_TRIM_Pos)
#define RCC_LPOSCTR_TRIM                   RCC_LPOSCTR_TRIM_Msk

/********************  Bit definition for RCC_LPOSCCR register  ***************/
#define RCC_LPOSCCR_LPM_LPO_OFF_Pos        (0U)
#define RCC_LPOSCCR_LPM_LPO_OFF_Msk        (0x1UL << RCC_LPOSCCR_LPM_LPO_OFF_Pos)
#define RCC_LPOSCCR_LPM_LPO_OFF            RCC_LPOSCCR_LPM_LPO_OFF_Msk
#define RCC_LPOSCCR_LPOENB_Pos             (1U)
#define RCC_LPOSCCR_LPOENB_Msk             (0x1UL << RCC_LPOSCCR_LPOENB_Pos)
#define RCC_LPOSCCR_LPOENB                 RCC_LPOSCCR_LPOENB_Msk
#define RCC_LPOSCCR_LPO_CHOP_EN_Pos        (2U)
#define RCC_LPOSCCR_LPO_CHOP_EN_Msk        (0x1UL << RCC_LPOSCCR_LPO_CHOP_EN_Pos)
#define RCC_LPOSCCR_LPO_CHOP_EN            RCC_LPOSCCR_LPO_CHOP_EN_Msk

/********************  Bit definition for RCC_XTLFCR register  ****************/
#define RCC_XTLFCR_IPW_Pos                 (0U)
#define RCC_XTLFCR_IPW_Msk                 (0x7UL << RCC_XTLFCR_IPW_Pos)
#define RCC_XTLFCR_IPW                     RCC_XTLFCR_IPW_Msk
#define RCC_XTLFCR_EN_Pos                  (8U)
#define RCC_XTLFCR_EN_Msk                  (0xFUL << RCC_XTLFCR_EN_Pos)
#define RCC_XTLFCR_EN                      RCC_XTLFCR_EN_Msk
#define RCC_XTLFCR_BKSW_Pos                (16U)
#define RCC_XTLFCR_BKSW_Msk                (0xFFUL << RCC_XTLFCR_BKSW_Pos)
#define RCC_XTLFCR_BKSW                    RCC_XTLFCR_BKSW_Msk

/********************  Bit definition for RCC_XTHFCR register  ****************/
#define RCC_XTHFCR_EN_Pos                  (0U)
#define RCC_XTHFCR_EN_Msk                  (0x1UL << RCC_XTHFCR_EN_Pos)
#define RCC_XTHFCR_EN                      RCC_XTHFCR_EN_Msk
#define RCC_XTHFCR_CFG_Pos                 (8U)
#define RCC_XTHFCR_CFG_Msk                 (0x7UL << RCC_XTHFCR_CFG_Pos)
#define RCC_XTHFCR_CFG                     RCC_XTHFCR_CFG_Msk

/********************  Bit definition for RCC_RCMFCR register  ****************/
#define RCC_RCMFCR_PSC_Pos                 (16U)
#define RCC_RCMFCR_PSC_Msk                 (0x3UL << RCC_RCMFCR_PSC_Pos)
#define RCC_RCMFCR_PSC                     RCC_RCMFCR_PSC_Msk
#define RCC_RCMFCR_EN_Pos                  (0U)
#define RCC_RCMFCR_EN_Msk                  (0x1UL << RCC_RCMFCR_EN_Pos)
#define RCC_RCMFCR_EN                      RCC_RCMFCR_EN_Msk

/********************  Bit definition for RCC_RCHFTR register  ****************/
#define RCC_RCHFTR_TRIM_Pos                (0U)
#define RCC_RCHFTR_TRIM_Msk                (0x7FUL << RCC_RCHFTR_TRIM_Pos)
#define RCC_RCHFTR_TRIM                    RCC_RCHFTR_TRIM_Msk

/********************  Bit definition for RCC_OPCCR1 register  ****************/
#define RCC_OPCCR1_UART0CKS_Pos            (0U)
#define RCC_OPCCR1_UART0CKS_Msk            (0x3UL << RCC_OPCCR1_UART0CKS_Pos)
#define RCC_OPCCR1_UART0CKS                RCC_OPCCR1_UART0CKS_Msk
#define RCC_OPCCR1_UART1CKS_Pos            (2U)
#define RCC_OPCCR1_UART1CKS_Msk            (0x3UL << RCC_OPCCR1_UART1CKS_Pos)
#define RCC_OPCCR1_UART1CKS                RCC_OPCCR1_UART1CKS_Msk
#define RCC_OPCCR1_ATCKS_Pos               (6U)
#define RCC_OPCCR1_ATCKS_Msk               (0x3UL << RCC_OPCCR1_ATCKS_Pos)
#define RCC_OPCCR1_ATCKS                   RCC_OPCCR1_ATCKS_Msk
#define RCC_OPCCR1_I2CCKS_Pos              (16U)
#define RCC_OPCCR1_I2CCKS_Msk              (0x3UL << RCC_OPCCR1_I2CCKS_Pos)
#define RCC_OPCCR1_I2CCKS                  RCC_OPCCR1_I2CCKS_Msk
#define RCC_OPCCR1_BEEPCKS_Pos             (18U)
#define RCC_OPCCR1_BEEPCKS_Msk             (0x1UL << RCC_OPCCR1_BEEPCKS_Pos)
#define RCC_OPCCR1_BEEPCKS                 RCC_OPCCR1_BEEPCKS_Msk
#define RCC_OPCCR1_LPUART0CKS_Pos          (24U)
#define RCC_OPCCR1_LPUART0CKS_Msk          (0x3UL << RCC_OPCCR1_LPUART0CKS_Pos)
#define RCC_OPCCR1_LPUART0CKS              RCC_OPCCR1_LPUART0CKS_Msk
#define RCC_OPCCR1_LPUART1CKS_Pos          (26U)
#define RCC_OPCCR1_LPUART1CKS_Msk          (0x3UL << RCC_OPCCR1_LPUART1CKS_Pos)
#define RCC_OPCCR1_LPUART1CKS              RCC_OPCCR1_LPUART1CKS_Msk
#define RCC_OPCCR1_EXTICKS_Pos             (30U)
#define RCC_OPCCR1_EXTICKS_Msk             (0x1UL << RCC_OPCCR1_EXTICKS_Pos)
#define RCC_OPCCR1_EXTICKS                 RCC_OPCCR1_EXTICKS_Msk

/********************  Bit definition for RCC_OPCCR2 register  ****************/
#define RCC_OPCCR2_BTCKS_Pos               (0U)
#define RCC_OPCCR2_BTCKS_Msk               (0x3UL << RCC_OPCCR2_BTCKS_Pos)
#define RCC_OPCCR2_BTCKS                   RCC_OPCCR2_BTCKS_Msk
#define RCC_OPCCR2_LPTCKS_Pos              (8U)
#define RCC_OPCCR2_LPTCKS_Msk              (0x3UL << RCC_OPCCR2_LPTCKS_Pos)
#define RCC_OPCCR2_LPTCKS                  RCC_OPCCR2_LPTCKS_Msk
#define RCC_OPCCR2_ADCCKS_Pos              (16U)
#define RCC_OPCCR2_ADCCKS_Msk              (0x3UL << RCC_OPCCR2_ADCCKS_Pos)
#define RCC_OPCCR2_ADCCKS                  RCC_OPCCR2_ADCCKS_Msk
#define RCC_OPCCR2_USBCKS_Pos              (23U)
#define RCC_OPCCR2_USBCKS_Msk              (0x1UL << RCC_OPCCR2_USBCKS_Pos)
#define RCC_OPCCR2_USBCKS                  RCC_OPCCR2_USBCKS_Msk
#define RCC_OPCCR2_ADCPRSC_Pos             (24U)
#define RCC_OPCCR2_ADCPRSC_Msk             (0x7UL << RCC_OPCCR2_ADCPRSC_Pos)
#define RCC_OPCCR2_ADCPRSC                 RCC_OPCCR2_ADCPRSC_Msk
#define RCC_OPCCR2_RNGPRSC_Pos             (28U)
#define RCC_OPCCR2_RNGPRSC_Msk             (0x7UL << RCC_OPCCR2_RNGPRSC_Pos)
#define RCC_OPCCR2_RNGPRSC                 RCC_OPCCR2_RNGPRSC_Msk

/********************  Bit definition for RCC_AHBMCR register  ****************/
#define RCC_AHBMCR_MPRIL_Pos               (0U)
#define RCC_AHBMCR_MPRIL_Msk               (0x1UL << RCC_AHBMCR_MPRIL_Pos)
#define RCC_AHBMCR_MPRIL                   RCC_AHBMCR_MPRIL_Msk

/********************  Bit definition for RCC_LSCLKSEL register  **************/
#define RCC_LSCLKSEL_SEL_Pos               (0U)
#define RCC_LSCLKSEL_SEL_Msk               (0xFFUL << RCC_LSCLKSEL_SEL_Pos)
#define RCC_LSCLKSEL_SEL                   RCC_LSCLKSEL_SEL_Msk

/********************  Bit definition for RCC_LKPCR register  *****************/
#define RCC_LKPCR_RST_EN_Pos               (1U)
#define RCC_LKPCR_RST_EN_Msk               (0x1UL << RCC_LKPCR_RST_EN_Pos)
#define RCC_LKPCR_RST_EN                   RCC_LKPCR_RST_EN_Msk

/********************  Bit definition for RCC_RSTFR register  *****************/
#define RCC_RSTFR_NVICN_FLAG_Pos           (0U)
#define RCC_RSTFR_NVICN_FLAG_Msk           (0x1UL << RCC_RSTFR_NVICN_FLAG_Pos)
#define RCC_RSTFR_NVICN_FLAG               RCC_RSTFR_NVICN_FLAG_Msk
#define RCC_RSTFR_LKUPN_FLAG_Pos           (1U)
#define RCC_RSTFR_LKUPN_FLAG_Msk           (0x1UL << RCC_RSTFR_LKUPN_FLAG_Pos)
#define RCC_RSTFR_LKUPN_FLAG               RCC_RSTFR_LKUPN_FLAG_Msk
#define RCC_RSTFR_WWDTN_FLAG_Pos           (2U)
#define RCC_RSTFR_WWDTN_FLAG_Msk           (0x1UL << RCC_RSTFR_WWDTN_FLAG_Pos)
#define RCC_RSTFR_WWDTN_FLAG               RCC_RSTFR_WWDTN_FLAG_Msk
#define RCC_RSTFR_IWDTN_FLAG_Pos           (4U)
#define RCC_RSTFR_IWDTN_FLAG_Msk           (0x1UL << RCC_RSTFR_IWDTN_FLAG_Pos)
#define RCC_RSTFR_IWDTN_FLAG               RCC_RSTFR_IWDTN_FLAG_Msk
#define RCC_RSTFR_SOFTN_FLAG_Pos           (5U)
#define RCC_RSTFR_SOFTN_FLAG_Msk           (0x1UL << RCC_RSTFR_SOFTN_FLAG_Pos)
#define RCC_RSTFR_SOFTN_FLAG               RCC_RSTFR_SOFTN_FLAG_Msk
#define RCC_RSTFR_PDRN_FLAG_Pos            (8U)
#define RCC_RSTFR_PDRN_FLAG_Msk            (0x1UL << RCC_RSTFR_PDRN_FLAG_Pos)
#define RCC_RSTFR_PDRN_FLAG                RCC_RSTFR_PDRN_FLAG_Msk
#define RCC_RSTFR_PORN_FLAG_Pos            (9U)
#define RCC_RSTFR_PORN_FLAG_Msk            (0x1UL << RCC_RSTFR_PORN_FLAG_Pos)
#define RCC_RSTFR_PORN_FLAG                RCC_RSTFR_PORN_FLAG_Msk
#define RCC_RSTFR_TESTN_FLAG_Pos           (10U)
#define RCC_RSTFR_TESTN_FLAG_Msk           (0x1UL << RCC_RSTFR_TESTN_FLAG_Pos)
#define RCC_RSTFR_TESTN_FLAG               RCC_RSTFR_TESTN_FLAG_Msk
#define RCC_RSTFR_NRSTN_FLAG_Pos           (11U)
#define RCC_RSTFR_NRSTN_FLAG_Msk           (0x1UL << RCC_RSTFR_NRSTN_FLAG_Pos)
#define RCC_RSTFR_NRSTN_FLAG               RCC_RSTFR_NRSTN_FLAG_Msk
#define RCC_RSTFR_MDFN_FLAG_Pos            (12U)
#define RCC_RSTFR_MDFN_FLAG_Msk            (0x1UL << RCC_RSTFR_MDFN_FLAG_Pos)
#define RCC_RSTFR_MDFN_FLAG                RCC_RSTFR_MDFN_FLAG_Msk

#define PERHRSTEN_KEY                      (0x13579BDFUL)
#define SOFTWARERESET_KEY                  (0x5C5CAABBUL)

/******************************************************************************/
/*                                                                            */
/*                                   RMU                                      */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RMU_PDRCR register  *****************/
#define RMU_PDRCR_EN_Pos                   (0U)
#define RMU_PDRCR_EN_Msk                   (0x1U << RMU_PDRCR_EN_Pos)
#define RMU_PDRCR_EN                       RMU_PDRCR_EN_Msk
#define RMU_PDRCR_CFG_Pos                  (1U)
#define RMU_PDRCR_CFG_Msk                  (0x3U << RMU_PDRCR_CFG_Pos)
#define RMU_PDRCR_CFG                      RMU_PDRCR_CFG_Msk

/********************  Bit definition for RMU_BORCR register  *****************/
#define RMU_BORCR_OFF_BOR_1P2_Pos          (0U)
#define RMU_BORCR_OFF_BOR_1P2_Msk          (0x1U << RMU_BORCR_OFF_BOR_1P2_Pos)
#define RMU_BORCR_OFF_BOR_1P2              RMU_BORCR_OFF_BOR_1P2_Msk
#define RMU_BORCR_OFF_BOR_1P0_Pos          (1U)
#define RMU_BORCR_OFF_BOR_1P0_Msk          (0x1U << RMU_BORCR_OFF_BOR_1P0_Pos)
#define RMU_BORCR_OFF_BOR_1P0              RMU_BORCR_OFF_BOR_1P0_Msk
#define RMU_BORCR_CFG_Pos                  (2U)
#define RMU_BORCR_CFG_Msk                  (0x3U << RMU_BORCR_CFG_Pos)
#define RMU_BORCR_CFG                      RMU_BORCR_CFG_Msk

/******************************************************************************/
/*                                                                            */
/*                                   RNG                                      */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RNG_CR register  ********************/
#define RNG_CR_EN_Pos                      (0U)
#define RNG_CR_EN_Msk                      (0x1UL << RNG_CR_EN_Pos)
#define RNG_CR_EN                          RNG_CR_EN_Msk

/********************  Bit definition for RNG_SR register  ********************/
#define RNG_SR_RNF_Pos                     (0U)
#define RNG_SR_RNF_Msk                     (0x1UL << RNG_SR_RNF_Pos)
#define RNG_SR_RNF                         RNG_SR_RNF_Msk
#define RNG_SR_LFSREN_Pos                  (1U)
#define RNG_SR_LFSREN_Msk                  (0x1UL << RNG_SR_LFSREN_Pos)
#define RNG_SR_LFSREN                      RNG_SR_LFSREN_Msk

/********************  Bit definition for RNG_CRCCR register  *****************/
#define RNG_CRCCR_CRCEN_Pos                (0U)
#define RNG_CRCCR_CRCEN_Msk                (0x1UL << RNG_CRCCR_CRCEN_Pos)
#define RNG_CRCCR_CRCEN                    RNG_CRCCR_CRCEN_Msk

/********************  Bit definition for RNG_CRCSR register  *****************/
#define RNG_CRCSR_CRCDONE_Pos              (0U)
#define RNG_CRCSR_CRCDONE_Msk              (0x1UL << RNG_CRCSR_CRCDONE_Pos)
#define RNG_CRCSR_CRCDONE                  RNG_CRCSR_CRCDONE_Msk

/******************************************************************************/
/*                                                                            */
/*                                   SVD                                      */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SVD_CFGR register  ******************/
#define SVD_CFGR_ITVL_Pos                  (0U)
#define SVD_CFGR_ITVL_Msk                  (0x3UL << SVD_CFGR_ITVL_Pos)
#define SVD_CFGR_ITVL                      SVD_CFGR_ITVL_Msk
#define SVD_CFGR_MOD_Pos                   (2U)
#define SVD_CFGR_MOD_Msk                   (0x1UL << SVD_CFGR_MOD_Pos)
#define SVD_CFGR_MOD                       SVD_CFGR_MOD_Msk
#define SVD_CFGR_DFEN_Pos                  (3U)
#define SVD_CFGR_DFEN_Msk                  (0x1UL << SVD_CFGR_DFEN_Pos)
#define SVD_CFGR_DFEN                      SVD_CFGR_DFEN_Msk
#define SVD_CFGR_LVL_Pos                   (4U)
#define SVD_CFGR_LVL_Msk                   (0xFUL << SVD_CFGR_LVL_Pos)
#define SVD_CFGR_LVL                       SVD_CFGR_LVL_Msk
#define SVD_CFGR_ADSVD_EN_Pos              (8U)
#define SVD_CFGR_ADSVD_EN_Msk              (0x1UL << SVD_CFGR_ADSVD_EN_Pos)
#define SVD_CFGR_ADSVD_EN                  SVD_CFGR_ADSVD_EN_Msk
#define SVD_CFGR_ADSVD_SEL_Pos             (9U)
#define SVD_CFGR_ADSVD_SEL_Msk             (0x7UL << SVD_CFGR_ADSVD_SEL_Pos)
#define SVD_CFGR_ADSVD_SEL                 SVD_CFGR_ADSVD_SEL_Msk

/********************  Bit definition for SVD_CR register  ********************/
#define SVD_CR_EN_Pos                      (0U)
#define SVD_CR_EN_Msk                      (0x1UL << SVD_CR_EN_Pos)
#define SVD_CR_EN                          SVD_CR_EN_Msk
#define SVD_CR_SVSEN_Pos                   (1U)
#define SVD_CR_SVSEN_Msk                   (0x1UL << SVD_CR_SVSEN_Pos)
#define SVD_CR_SVSEN                       SVD_CR_SVSEN_Msk

/********************  Bit definition for SVD_IER register  *******************/
#define SVD_IER_PRIE_Pos                   (0U)
#define SVD_IER_PRIE_Msk                   (0x1UL << SVD_IER_PRIE_Pos)
#define SVD_IER_PRIE                       SVD_IER_PRIE_Msk
#define SVD_IER_PFIE_Pos                   (1U)
#define SVD_IER_PFIE_Msk                   (0x1UL << SVD_IER_PFIE_Pos)
#define SVD_IER_PFIE                       SVD_IER_PFIE_Msk

/********************  Bit definition for SVD_ISR register  *******************/
#define SVD_ISR_PRF_Pos                    (0U)
#define SVD_ISR_PRF_Msk                    (0x1UL << SVD_ISR_PRF_Pos)
#define SVD_ISR_PRF                        SVD_ISR_PRF_Msk
#define SVD_ISR_PFF_Pos                    (1U)
#define SVD_ISR_PFF_Msk                    (0x1UL << SVD_ISR_PFF_Pos)
#define SVD_ISR_PFF                        SVD_ISR_PFF_Msk
#define SVD_ISR_SVDR_Pos                   (7U)
#define SVD_ISR_SVDR_Msk                   (0x1UL << SVD_ISR_SVDR_Pos)
#define SVD_ISR_SVDR                       SVD_ISR_SVDR_Msk
#define SVD_ISR_SVDO_Pos                   (8U)
#define SVD_ISR_SVDO_Msk                   (0x1UL << SVD_ISR_SVDO_Pos)
#define SVD_ISR_SVDO                       SVD_ISR_SVDO_Msk
#define SVD_ISR_ADLVDO_Pos                 (9U)
#define SVD_ISR_ADLVDO_Msk                 (0x1UL << SVD_ISR_ADLVDO_Pos)
#define SVD_ISR_ADLVDO                     SVD_ISR_ADLVDO_Msk

/********************  Bit definition for SVD_VSR register  *******************/
#define SVD_VSR_EN_Pos                     (0U)
#define SVD_VSR_EN_Msk                     (0x7UL << SVD_VSR_EN_Pos)
#define SVD_VSR_EN                         SVD_VSR_EN_Msk

#define U7816_CR_TXEN_Pos                  (5U)
#define U7816_CR_TXEN_Msk                  (0x1UL << U7816_CR_TXEN_Pos)
#define U7816_CR_TXEN                      U7816_CR_TXEN_Msk
#define U7816_CR_RXEN_Pos                  (4U)
#define U7816_CR_RXEN_Msk                  (0x1UL << U7816_CR_RXEN_Pos)
#define U7816_CR_RXEN                      U7816_CR_RXEN_Msk
#define U7816_CR_CKOEN_Pos                 (3U)
#define U7816_CR_CKOEN_Msk                 (0x1UL << U7816_CR_CKOEN_Pos)
#define U7816_CR_CKOEN                     U7816_CR_CKOEN_Msk
#define U7816_CR_HPUAT_Pos                 (2U)
#define U7816_CR_HPUAT_Msk                 (0x1UL << U7816_CR_HPUAT_Pos)
#define U7816_CR_HPUAT                     U7816_CR_HPUAT_Msk
#define U7816_CR_HPUEN_Pos                 (1U)
#define U7816_CR_HPUEN_Msk                 (0x1UL << U7816_CR_HPUEN_Pos)
#define U7816_CR_HPUEN                     U7816_CR_HPUEN_Msk
#define U7816_FFR_SFREN_Pos                (11U)
#define U7816_FFR_SFREN_Msk                (0x1UL << U7816_FFR_SFREN_Pos)
#define U7816_FFR_SFREN                    U7816_FFR_SFREN_Msk
#define U7816_FFR_ERSW_Pos                 (9U)
#define U7816_FFR_ERSW_Msk                 (0x3UL << U7816_FFR_ERSW_Pos)
#define U7816_FFR_ERSW                     U7816_FFR_ERSW_Msk
#define U7816_FFR_ERSGD_Pos                (8U)
#define U7816_FFR_ERSGD_Msk                (0x1UL << U7816_FFR_ERSGD_Pos)
#define U7816_FFR_ERSGD                    U7816_FFR_ERSGD_Msk
#define U7816_CR_BGT_Pos                   (7U)
#define U7816_CR_BGT_Msk                   (0x1UL << U7816_CR_BGT_Pos)
#define U7816_CR_BGT                       U7816_CR_BGT_Msk
#define U7816_FFR_REP_T_Pos                (6U)
#define U7816_FFR_REP_T_Msk                (0x1UL << U7816_FFR_REP_T_Pos)
#define U7816_FFR_REP_T                    U7816_FFR_REP_T_Msk
#define U7816_FFR_PAR_Pos                  (4U)
#define U7816_FFR_PAR_Msk                  (0x3UL << U7816_FFR_PAR_Pos)
#define U7816_FFR_PAR                      U7816_FFR_PAR_Msk
#define U7816_FFR_RFREN_Pos                (3U)
#define U7816_FFR_RFREN_Msk                (0x1UL << U7816_FFR_RFREN_Pos)
#define U7816_FFR_RFREN                    U7816_FFR_RFREN_Msk
#define U7816_FFR_TREPEN_Pos               (2U)
#define U7816_FFR_TREPEN_Msk               (0x1UL << U7816_FFR_TREPEN_Pos)
#define U7816_FFR_TREPEN                   U7816_FFR_TREPEN_Msk
#define U7816_FFR_RREPEN_Pos               (1U)
#define U7816_FFR_RREPEN_Msk               (0x1UL << U7816_FFR_RREPEN_Pos)
#define U7816_FFR_RREPEN                   U7816_FFR_RREPEN_Msk
#define U7816_FFR_DICONV_Pos               (0U)
#define U7816_FFR_DICONV_Msk               (0x1UL << U7816_FFR_DICONV_Pos)
#define U7816_FFR_DICONV                   U7816_FFR_DICONV_Msk
#define U7816_IER_RXIE_Pos                 (2U)
#define U7816_IER_RXIE_Msk                 (0x1UL << U7816_IER_RXIE_Pos)
#define U7816_IER_RXIE                     U7816_IER_RXIE_Msk
#define U7816_IER_TXIE_Pos                 (1U)
#define U7816_IER_TXIE_Msk                 (0x1UL << U7816_IER_TXIE_Pos)
#define U7816_IER_TXIE                     U7816_IER_TXIE_Msk
#define U7816_IER_LSIE_Pos                 (0U)
#define U7816_IER_LSIE_Msk                 (0x1UL << U7816_IER_LSIE_Pos)
#define U7816_IER_LSIE                     U7816_IER_LSIE_Msk
#define U7816_ISR_WAIT_PRT_Pos             (18U)
#define U7816_ISR_WAIT_PRT_Msk             (0x1UL << U7816_ISR_WAIT_PRT_Pos)
#define U7816_ISR_WAIT_PRT                 U7816_ISR_WAIT_PRT_Msk
#define U7816_ISR_TXBUSY_Pos               (17U)
#define U7816_ISR_TXBUSY_Msk               (0x1UL << U7816_ISR_TXBUSY_Pos)
#define U7816_ISR_TXBUSY                   U7816_ISR_TXBUSY_Msk
#define U7816_ISR_RXBUSY_Pos               (16U)
#define U7816_ISR_RXBUSY_Msk               (0x1UL << U7816_ISR_RXBUSY_Pos)
#define U7816_ISR_RXBUSY                   U7816_ISR_RXBUSY_Msk
#define U7816_ISR_TPARERR_Pos              (11U)
#define U7816_ISR_TPARERR_Msk              (0x1UL << U7816_ISR_TPARERR_Pos)
#define U7816_ISR_TPARERR                  U7816_ISR_TPARERR_Msk
#define U7816_ISR_RPARERR_Pos              (10U)
#define U7816_ISR_RPARERR_Msk              (0x1UL << U7816_ISR_RPARERR_Pos)
#define U7816_ISR_RPARERR                  U7816_ISR_RPARERR_Msk
#define U7816_ISR_FRERR_Pos                (9U)
#define U7816_ISR_FRERR_Msk                (0x1UL << U7816_ISR_FRERR_Pos)
#define U7816_ISR_FRERR                    U7816_ISR_FRERR_Msk
#define U7816_ISR_OVERR_Pos                (8U)
#define U7816_ISR_OVERR_Msk                (0x1UL << U7816_ISR_OVERR_Pos)
#define U7816_ISR_OVERR                    U7816_ISR_OVERR_Msk
#define U7816_ISR_RXIF_Pos                 (2U)
#define U7816_ISR_RXIF_Msk                 (0x1UL << U7816_ISR_RXIF_Pos)
#define U7816_ISR_RXIF                     U7816_ISR_RXIF_Msk
#define U7816_ISR_TXIF_Pos                 (1U)
#define U7816_ISR_TXIF_Msk                 (0x1UL << U7816_ISR_TXIF_Pos)
#define U7816_ISR_TXIF                     U7816_ISR_TXIF_Msk
#define U7816_ISR_ERRIF_Pos                (0U)
#define U7816_ISR_ERRIF_Msk                (0x1UL << U7816_ISR_ERRIF_Pos)
#define U7816_ISR_ERRIF                    U7816_ISR_ERRIF_Msk

#define UART_IRCR_IRFLAG_Pos               (15U)
#define UART_IRCR_IRFLAG_Msk               (0x1UL << UART_IRCR_IRFLAG_Pos)
#define UART_IRCR_IRFLAG                   UART_IRCR_IRFLAG_Msk
#define UART_IRCR_TH_Pos                   (11U)
#define UART_IRCR_TH_Msk                   (0xFUL << UART_IRCR_TH_Pos)
#define UART_IRCR_TH                       UART_IRCR_TH_Msk
#define UART_IRCR_TZBRG_Pos                (0U)
#define UART_IRCR_TZBRG_Msk                (0x7FFUL << UART_IRCR_TZBRG_Pos)
#define UART_IRCR_TZBRG                    UART_IRCR_TZBRG_Msk
#define UART_CSR_BUSY_Pos                  (24U)
#define UART_CSR_BUSY_Msk                  (0x1UL << UART_CSR_BUSY_Pos)
#define UART_CSR_BUSY                      UART_CSR_BUSY_Msk
#define UART_CSR_TXIREN_Pos                (17U)
#define UART_CSR_TXIREN_Msk                (0x1UL << UART_CSR_TXIREN_Pos)
#define UART_CSR_TXIREN                    UART_CSR_TXIREN_Msk
#define UART_CSR_RXTOEN_Pos                (16U)
#define UART_CSR_RXTOEN_Msk                (0x1UL << UART_CSR_RXTOEN_Pos)
#define UART_CSR_RXTOEN                    UART_CSR_RXTOEN_Msk
#define UART_CSR_IOSWAP_Pos                (12U)
#define UART_CSR_IOSWAP_Msk                (0x1UL << UART_CSR_IOSWAP_Pos)
#define UART_CSR_IOSWAP                    UART_CSR_IOSWAP_Msk
#define UART_CSR_NEWUP_Pos                 (11U)
#define UART_CSR_NEWUP_Msk                 (0x1UL << UART_CSR_NEWUP_Pos)
#define UART_CSR_NEWUP                     UART_CSR_NEWUP_Msk
#define UART_CSR_DMATXIFCFG_Pos            (10U)
#define UART_CSR_DMATXIFCFG_Msk            (0x1UL << UART_CSR_DMATXIFCFG_Pos)
#define UART_CSR_DMATXIFCFG                UART_CSR_DMATXIFCFG_Msk
#define UART_CSR_BITORD_Pos                (9U)
#define UART_CSR_BITORD_Msk                (0x1UL << UART_CSR_BITORD_Pos)
#define UART_CSR_BITORD                    UART_CSR_BITORD_Msk
#define UART_CSR_STOPCFG_Pos               (8U)
#define UART_CSR_STOPCFG_Msk               (0x1UL << UART_CSR_STOPCFG_Pos)
#define UART_CSR_STOPCFG                   UART_CSR_STOPCFG_Msk
#define UART_CSR_PDSEL_Pos                 (6U)
#define UART_CSR_PDSEL_Msk                 (0x3UL << UART_CSR_PDSEL_Pos)
#define UART_CSR_PDSEL                     UART_CSR_PDSEL_Msk
#define UART_CSR_PARITY_Pos                (4U)
#define UART_CSR_PARITY_Msk                (0x3UL << UART_CSR_PARITY_Pos)
#define UART_CSR_PARITY                    UART_CSR_PARITY_Msk
#define UART_CSR_RXPOL_Pos                 (3U)
#define UART_CSR_RXPOL_Msk                 (0x1UL << UART_CSR_RXPOL_Pos)
#define UART_CSR_RXPOL                     UART_CSR_RXPOL_Msk
#define UART_CSR_TXPOL_Pos                 (2U)
#define UART_CSR_TXPOL_Msk                 (0x1UL << UART_CSR_TXPOL_Pos)
#define UART_CSR_TXPOL                     UART_CSR_TXPOL_Msk
#define UART_CSR_RXEN_Pos                  (1U)
#define UART_CSR_RXEN_Msk                  (0x1UL << UART_CSR_RXEN_Pos)
#define UART_CSR_RXEN                      UART_CSR_RXEN_Msk
#define UART_CSR_TXEN_Pos                  (0U)
#define UART_CSR_TXEN_Msk                  (0x1UL << UART_CSR_TXEN_Pos)
#define UART_CSR_TXEN                      UART_CSR_TXEN_Msk
#define UART_IER_RXTOIE_Pos                (11U)
#define UART_IER_RXTOIE_Msk                (0x1UL << UART_IER_RXTOIE_Pos)
#define UART_IER_RXTOIE                    UART_IER_RXTOIE_Msk
#define UART_IER_RXERRIE_Pos               (10U)
#define UART_IER_RXERRIE_Msk               (0x1UL << UART_IER_RXERRIE_Pos)
#define UART_IER_RXERRIE                   UART_IER_RXERRIE_Msk
#define UART_IER_RXBFIE_Pos                (8U)
#define UART_IER_RXBFIE_Msk                (0x1UL << UART_IER_RXBFIE_Pos)
#define UART_IER_RXBFIE                    UART_IER_RXBFIE_Msk
#define UART_IER_NEWUPIE_Pos               (7U)
#define UART_IER_NEWUPIE_Msk               (0x1UL << UART_IER_NEWUPIE_Pos)
#define UART_IER_NEWUPIE                   UART_IER_NEWUPIE_Msk
#define UART_IER_TXBEIE_Pos                (1U)
#define UART_IER_TXBEIE_Msk                (0x1UL << UART_IER_TXBEIE_Pos)
#define UART_IER_TXBEIE                    UART_IER_TXBEIE_Msk
#define UART_IER_TXSEIE_Pos                (0U)
#define UART_IER_TXSEIE_Msk                (0x1UL << UART_IER_TXSEIE_Pos)
#define UART_IER_TXSEIE                    UART_IER_TXSEIE_Msk
#define UART_ISR_PERR_Pos                  (18U)
#define UART_ISR_PERR_Msk                  (0x1UL << UART_ISR_PERR_Pos)
#define UART_ISR_PERR                      UART_ISR_PERR_Msk
#define UART_ISR_FERR_Pos                  (17U)
#define UART_ISR_FERR_Msk                  (0x1UL << UART_ISR_FERR_Pos)
#define UART_ISR_FERR                      UART_ISR_FERR_Msk
#define UART_ISR_RXERR_Pos                 (16U)
#define UART_ISR_RXERR_Msk                 (0x1UL << UART_ISR_RXERR_Pos)
#define UART_ISR_RXERR                     UART_ISR_RXERR_Msk
#define UART_ISR_RXTO_Pos                  (11U)
#define UART_ISR_RXTO_Msk                  (0x1UL << UART_ISR_RXTO_Pos)
#define UART_ISR_RXTO                      UART_ISR_RXTO_Msk
#define UART_ISR_RXBF_Pos                  (8U)
#define UART_ISR_RXBF_Msk                  (0x1UL << UART_ISR_RXBF_Pos)
#define UART_ISR_RXBF                      UART_ISR_RXBF_Msk
#define UART_ISR_NEWUP_Pos                 (7U)
#define UART_ISR_NEWUP_Msk                 (0x1UL << UART_ISR_NEWUP_Pos)
#define UART_ISR_NEWUP                     UART_ISR_NEWUP_Msk
#define UART_ISR_TXBE_Pos                  (1U)
#define UART_ISR_TXBE_Msk                  (0x1UL << UART_ISR_TXBE_Pos)
#define UART_ISR_TXBE                      UART_ISR_TXBE_Msk
#define UART_ISR_TXSE_Pos                  (0U)
#define UART_ISR_TXSE_Msk                  (0x1UL << UART_ISR_TXSE_Pos)
#define UART_ISR_TXSE                      UART_ISR_TXSE_Msk
#define UART_TODR_TXDLY_LEN_Pos            (8U)
#define UART_TODR_TXDLY_LEN_Msk            (0xFFUL << UART_TODR_TXDLY_LEN_Pos)
#define UART_TODR_TXDLY_LEN                UART_TODR_TXDLY_LEN_Msk
#define UART_TODR_RXDLY_LEN_Pos            (0U)
#define UART_TODR_RXDLY_LEN_Msk            (0xFFUL << UART_TODR_RXDLY_LEN_Pos)
#define UART_TODR_RXDLY_LEN                UART_TODR_RXDLY_LEN_Msk


#define VREF_CR_VREF_EN_Pos                (0U)
#define VREF_CR_VREF_EN_Msk                (0x1U << VREF_CR_VREF_EN_Pos)
#define VREF_CR_VREF_EN                    VREF_CR_VREF_EN_Msk
#define VREF_CR_PTAT_EN_Pos                (1U)
#define VREF_CR_PTAT_EN_Msk                (0x1U << VREF_CR_PTAT_EN_Pos)
#define VREF_CR_PTAT_EN                    VREF_CR_PTAT_EN_Msk
#define VREF_SR_FLAG_Pos                   (8U)
#define VREF_SR_FLAG_Msk                   (0x1U << VREF_SR_FLAG_Pos)
#define VREF_SR_FLAG                       VREF_SR_FLAG_Msk
#define VREF_SR_RDY_Pos                    (1U)
#define VREF_SR_RDY_Msk                    (0x1U << VREF_SR_RDY_Pos)
#define VREF_SR_RDY                        VREF_SR_RDY_Msk
#define VREF_SR_IF_Pos                     (0U)
#define VREF_SR_IF_Msk                     (0x1U << VREF_SR_IF_Pos)
#define VREF_SR_IF                         VREF_SR_IF_Msk
#define VREF_IER_IE_Pos                    (0U)
#define VREF_IER_IE_Msk                    (0x1U << VREF_IER_IE_Pos)
#define VREF_IER_IE                        VREF_IER_IE_Msk
#define VREF_BUFCR_VPTATBUFFER_OUTEN_Pos   (3U)
#define VREF_BUFCR_VPTATBUFFER_OUTEN_Msk   (0x1U << VREF_BUFCR_VPTATBUFFER_OUTEN_Pos)
#define VREF_BUFCR_VPTATBUFFER_OUTEN       VREF_BUFCR_VPTATBUFFER_OUTEN_Msk
#define VREF_BUFCR_VPTATBUFFER_EN_Pos      (2U)
#define VREF_BUFCR_VPTATBUFFER_EN_Msk      (0x1U << VREF_BUFCR_VPTATBUFFER_EN_Pos)
#define VREF_BUFCR_VPTATBUFFER_EN          VREF_BUFCR_VPTATBUFFER_EN_Msk
#define VREF_BUFCR_VREFBUFFER_OUTEN_Pos    (1U)
#define VREF_BUFCR_VREFBUFFER_OUTEN_Msk    (0x1U << VREF_BUFCR_VREFBUFFER_OUTEN_Pos)
#define VREF_BUFCR_VREFBUFFER_OUTEN        VREF_BUFCR_VREFBUFFER_OUTEN_Msk
#define VREF_BUFCR_VREFBUFFER_EN_Pos       (0U)
#define VREF_BUFCR_VREFBUFFER_EN_Msk       (0x1U << VREF_BUFCR_VREFBUFFER_EN_Pos)
#define VREF_BUFCR_VREFBUFFER_EN           VREF_BUFCR_VREFBUFFER_EN_Msk
/******************************************************************************/
/*                                                                            */
/*                                   WWDT                                     */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for WWDT_CR register  *******************/
#define WWDT_CR_CON_Pos                    (0U)
#define WWDT_CR_CON_Msk                    (0xFFUL << WWDT_CR_CON_Pos)
#define WWDT_CR_CON                        WWDT_CR_CON_Msk

/********************  Bit definition for WWDT_CFGR register  *****************/
#define WWDT_CFGR_CFG_Pos                  (0U)
#define WWDT_CFGR_CFG_Msk                  (0x7UL << WWDT_CFGR_CFG_Pos)
#define WWDT_CFGR_CFG                      WWDT_CFGR_CFG_Msk

/********************  Bit definition for WWDT_IER register  ******************/
#define WWDT_IER_IE_Pos                    (0U)
#define WWDT_IER_IE_Msk                    (0x1UL << WWDT_IER_IE_Pos)
#define WWDT_IER_IE                        WWDT_IER_IE_Msk

/********************  Bit definition for WWDT_ISR register  ******************/
#define WWDT_ISR_NOVF_Pos                  (0U)
#define WWDT_ISR_NOVF_Msk                  (0x1UL << WWDT_ISR_NOVF_Pos)
#define WWDT_ISR_NOVF                      WWDT_ISR_NOVF_Msk

/********************  Bit definition for WWDT_PSC register  ******************/
#define WWDT_PSC_DIV_CNT_Pos               (0U)
#define WWDT_PSC_DIV_CNT_Msk               (0xFFFUL << WWDT_PSC_DIV_CNT_Pos)
#define WWDT_PSC_DIV_CNT                   WWDT_PSC_DIV_CNT_Msk


#define SPI_CR1_IOSWAP_Pos                 (11U)
#define SPI_CR1_IOSWAP_Msk                 (0x1UL << SPI_CR1_IOSWAP_Pos)
#define SPI_CR1_IOSWAP                     SPI_CR1_IOSWAP_Msk
#define SPI_CR1_MSPA_Pos                   (10U)
#define SPI_CR1_MSPA_Msk                   (0x1UL << SPI_CR1_MSPA_Pos)
#define SPI_CR1_MSPA                       SPI_CR1_MSPA_Msk
#define SPI_CR1_SSPA_Pos                   (9U)
#define SPI_CR1_SSPA_Msk                   (0x1UL << SPI_CR1_SSPA_Pos)
#define SPI_CR1_SSPA                       SPI_CR1_SSPA_Msk
#define SPI_CR1_MM_Pos                     (8U)
#define SPI_CR1_MM_Msk                     (0x1UL << SPI_CR1_MM_Pos)
#define SPI_CR1_MM                         SPI_CR1_MM_Msk
#define SPI_CR1_WAIT_Pos                   (6U)
#define SPI_CR1_WAIT_Msk                   (0x3UL << SPI_CR1_WAIT_Pos)
#define SPI_CR1_WAIT                       SPI_CR1_WAIT_Msk
#define SPI_CR1_BAUD_Pos                   (3U)
#define SPI_CR1_BAUD_Msk                   (0x7UL << SPI_CR1_BAUD_Pos)
#define SPI_CR1_BAUD                       SPI_CR1_BAUD_Msk
#define SPI_CR1_LSBF_Pos                   (2U)
#define SPI_CR1_LSBF_Msk                   (0x1UL << SPI_CR1_LSBF_Pos)
#define SPI_CR1_LSBF                       SPI_CR1_LSBF_Msk
#define SPI_CR1_CPOL_Pos                   (1U)
#define SPI_CR1_CPOL_Msk                   (0x1UL << SPI_CR1_CPOL_Pos)
#define SPI_CR1_CPOL                       SPI_CR1_CPOL_Msk
#define SPI_CR1_CPHA_Pos                   (0U)
#define SPI_CR1_CPHA_Msk                   (0x1UL << SPI_CR1_CPHA_Pos)
#define SPI_CR1_CPHA                       SPI_CR1_CPHA_Msk
#define SPI_CR2_DUMMY_EN_Pos               (15U)
#define SPI_CR2_DUMMY_EN_Msk               (0x1UL << SPI_CR2_DUMMY_EN_Pos)
#define SPI_CR2_DUMMY_EN                   SPI_CR2_DUMMY_EN_Msk
#define SPI_CR2_RXO_Pos                    (11U)
#define SPI_CR2_RXO_Msk                    (0x1UL << SPI_CR2_RXO_Pos)
#define SPI_CR2_RXO                        SPI_CR2_RXO_Msk
#define SPI_CR2_DLEN_Pos                   (9U)
#define SPI_CR2_DLEN_Msk                   (0x3UL << SPI_CR2_DLEN_Pos)
#define SPI_CR2_DLEN                       SPI_CR2_DLEN_Msk
#define SPI_CR2_HALFDUPLEX_Pos             (8U)
#define SPI_CR2_HALFDUPLEX_Msk             (0x1UL << SPI_CR2_HALFDUPLEX_Pos)
#define SPI_CR2_HALFDUPLEX                 SPI_CR2_HALFDUPLEX_Msk
#define SPI_CR2_HD_RW_Pos                  (7U)
#define SPI_CR2_HD_RW_Msk                  (0x1UL << SPI_CR2_HD_RW_Pos)
#define SPI_CR2_HD_RW                      SPI_CR2_HD_RW_Msk
#define SPI_CR2_CMD8B_Pos                  (6U)
#define SPI_CR2_CMD8B_Msk                  (0x1UL << SPI_CR2_CMD8B_Pos)
#define SPI_CR2_CMD8B                      SPI_CR2_CMD8B_Msk
#define SPI_CR2_SSNM_Pos                   (5U)
#define SPI_CR2_SSNM_Msk                   (0x1UL << SPI_CR2_SSNM_Pos)
#define SPI_CR2_SSNM                       SPI_CR2_SSNM_Msk
#define SPI_CR2_TXO_AC_Pos                 (4U)
#define SPI_CR2_TXO_AC_Msk                 (0x1UL << SPI_CR2_TXO_AC_Pos)
#define SPI_CR2_TXO_AC                     SPI_CR2_TXO_AC_Msk
#define SPI_CR2_TXO_Pos                    (3U)
#define SPI_CR2_TXO_Msk                    (0x1UL << SPI_CR2_TXO_Pos)
#define SPI_CR2_TXO                        SPI_CR2_TXO_Msk
#define SPI_CR2_SSN_Pos                    (2U)
#define SPI_CR2_SSN_Msk                    (0x1UL << SPI_CR2_SSN_Pos)
#define SPI_CR2_SSN                        SPI_CR2_SSN_Msk
#define SPI_CR2_SSNSEN_Pos                 (1U)
#define SPI_CR2_SSNSEN_Msk                 (0x1UL << SPI_CR2_SSNSEN_Pos)
#define SPI_CR2_SSNSEN                     SPI_CR2_SSNSEN_Msk
#define SPI_CR2_SPIEN_Pos                  (0U)
#define SPI_CR2_SPIEN_Msk                  (0x1UL << SPI_CR2_SPIEN_Pos)
#define SPI_CR2_SPIEN                      SPI_CR2_SPIEN_Msk
#define SPI_CR3_TXBFC_Pos                  (3U)
#define SPI_CR3_TXBFC_Msk                  (0x1UL << SPI_CR3_TXBFC_Pos)
#define SPI_CR3_TXBFC                      SPI_CR3_TXBFC_Msk
#define SPI_CR3_RXBFC_Pos                  (2U)
#define SPI_CR3_RXBFC_Msk                  (0x1UL << SPI_CR3_RXBFC_Pos)
#define SPI_CR3_RXBFC                      SPI_CR3_RXBFC_Msk
#define SPI_CR3_MERRC_Pos                  (1U)
#define SPI_CR3_MERRC_Msk                  (0x1UL << SPI_CR3_MERRC_Pos)
#define SPI_CR3_MERRC                      SPI_CR3_MERRC_Msk
#define SPI_CR3_SERRC_Pos                  (0U)
#define SPI_CR3_SERRC_Msk                  (0x1UL << SPI_CR3_SERRC_Pos)
#define SPI_CR3_SERRC                      SPI_CR3_SERRC_Msk
#define SPI_IER_ERRIE_Pos                  (2U)
#define SPI_IER_ERRIE_Msk                  (0x1UL << SPI_IER_ERRIE_Pos)
#define SPI_IER_ERRIE                      SPI_IER_ERRIE_Msk
#define SPI_IER_TXIE_Pos                   (1U)
#define SPI_IER_TXIE_Msk                   (0x1UL << SPI_IER_TXIE_Pos)
#define SPI_IER_TXIE                       SPI_IER_TXIE_Msk
#define SPI_IER_RXIE_Pos                   (0U)
#define SPI_IER_RXIE_Msk                   (0x1UL << SPI_IER_RXIE_Pos)
#define SPI_IER_RXIE                       SPI_IER_RXIE_Msk
#define SPI_ISR_DCN_TX_Pos                 (12U)
#define SPI_ISR_DCN_TX_Msk                 (0x1UL << SPI_ISR_DCN_TX_Pos)
#define SPI_ISR_DCN_TX                     SPI_ISR_DCN_TX_Msk
#define SPI_ISR_RXCOL_Pos                  (10U)
#define SPI_ISR_RXCOL_Msk                  (0x1UL << SPI_ISR_RXCOL_Pos)
#define SPI_ISR_RXCOL                      SPI_ISR_RXCOL_Msk
#define SPI_ISR_TXCOL_Pos                  (9U)
#define SPI_ISR_TXCOL_Msk                  (0x1UL << SPI_ISR_TXCOL_Pos)
#define SPI_ISR_TXCOL                      SPI_ISR_TXCOL_Msk
#define SPI_ISR_BUSY_Pos                   (8U)
#define SPI_ISR_BUSY_Msk                   (0x1UL << SPI_ISR_BUSY_Pos)
#define SPI_ISR_BUSY                       SPI_ISR_BUSY_Msk
#define SPI_ISR_MERR_Pos                   (6U)
#define SPI_ISR_MERR_Msk                   (0x1UL << SPI_ISR_MERR_Pos)
#define SPI_ISR_MERR                       SPI_ISR_MERR_Msk
#define SPI_ISR_SERR_Pos                   (5U)
#define SPI_ISR_SERR_Msk                   (0x1UL << SPI_ISR_SERR_Pos)
#define SPI_ISR_SERR                       SPI_ISR_SERR_Msk
#define SPI_ISR_TXBE_Pos                   (1U)
#define SPI_ISR_TXBE_Msk                   (0x1UL << SPI_ISR_TXBE_Pos)
#define SPI_ISR_TXBE                       SPI_ISR_TXBE_Msk
#define SPI_ISR_RXBF_Pos                   (0U)
#define SPI_ISR_RXBF_Msk                   (0x1UL << SPI_ISR_RXBF_Pos)
#define SPI_ISR_RXBF                       SPI_ISR_RXBF_Msk

#define DMA_GCR_ADDRERR_EN_Pos             (1U)
#define DMA_GCR_ADDRERR_EN_Msk             (0x1UL << DMA_GCR_ADDRERR_EN_Pos)
#define DMA_GCR_ADDRERR_EN                 DMA_GCR_ADDRERR_EN_Msk
#define DMA_GCR_EN_Pos                     (0U)
#define DMA_GCR_EN_Msk                     (0x1UL << DMA_GCR_EN_Pos)
#define DMA_GCR_EN                         DMA_GCR_EN_Msk
#define DMA_CHCR_TSIZE_Pos                 (16U)
#define DMA_CHCR_TSIZE_Msk                 (0xFFFFUL << DMA_CHCR_TSIZE_Pos)
#define DMA_CHCR_TSIZE                     DMA_CHCR_TSIZE_Msk
#define DMA_CHCR_PRI_Pos                   (12U)
#define DMA_CHCR_PRI_Msk                   (0x3UL << DMA_CHCR_PRI_Pos)
#define DMA_CHCR_PRI                       DMA_CHCR_PRI_Msk
#define DMA_CHCR_INC_Pos                   (11U)
#define DMA_CHCR_INC_Msk                   (0x1UL << DMA_CHCR_INC_Pos)
#define DMA_CHCR_INC                       DMA_CHCR_INC_Msk

#define DMA_CH7CR_RAM_INC_Pos              (9U)
#define DMA_CH7CR_RAM_INC_Msk              (0x1UL << DMA_CH7CR_RAM_INC_Pos)
#define DMA_CH7CR_RAM_INC                  DMA_CH7CR_RAM_INC_Msk
#define DMA_CH7CR_FLASH_INC_Pos            (8U)
#define DMA_CH7CR_FLASH_INC_Msk            (0x1UL << DMA_CH7CR_FLASH_INC_Pos)
#define DMA_CH7CR_INC                      DMA_CH7CR_FLASH_INC_Msk

#define DMA_CHCR_SSEL_Pos                  (8U)
#define DMA_CHCR_SSEL_Msk                  (0x7UL << DMA_CHCR_SSEL_Pos)
#define DMA_CHCR_SSEL                      DMA_CHCR_SSEL_Msk
#define DMA_CHCR_DIR_Pos                   (6U)
#define DMA_CHCR_DIR_Msk                   (0x1UL << DMA_CHCR_DIR_Pos)
#define DMA_CHCR_DIR                       DMA_CHCR_DIR_Msk
#define DMA_CH7CR_DIR_Pos                  (10U)
#define DMA_CH7CR_DIR_Msk                  (0x1UL << DMA_CH7CR_DIR_Pos)
#define DMA_CH7CR_DIR                      DMA_CH7CR_DIR_Msk
#define DMA_CHCR_BDW_Pos                   (4U)
#define DMA_CHCR_BDW_Msk                   (0x3UL << DMA_CHCR_BDW_Pos)
#define DMA_CHCR_BDW                       DMA_CHCR_BDW_Msk
#define DMA_CHCR_CIRC_Pos                  (3U)
#define DMA_CHCR_CIRC_Msk                  (0x1UL << DMA_CHCR_CIRC_Pos)
#define DMA_CHCR_CIRC                      DMA_CHCR_CIRC_Msk
#define DMA_CHCR_FTIE_Pos                  (2U)
#define DMA_CHCR_FTIE_Msk                  (0x1UL << DMA_CHCR_FTIE_Pos)
#define DMA_CHCR_FTIE                      DMA_CHCR_FTIE_Msk
#define DMA_CHCR_HTIE_Pos                  (1U)
#define DMA_CHCR_HTIE_Msk                  (0x1UL << DMA_CHCR_HTIE_Pos)
#define DMA_CHCR_HTIE                      DMA_CHCR_HTIE_Msk
#define DMA_CHCR_EN_Pos                    (0U)
#define DMA_CHCR_EN_Msk                    (0x1UL << DMA_CHCR_EN_Pos)
#define DMA_CHCR_EN                        DMA_CHCR_EN_Msk
#define DMA_ISR_ADDRERR_Pos                (16U)
#define DMA_ISR_ADDRERR_Msk                (0x1UL << DMA_ISR_ADDRERR_Pos)
#define DMA_ISR_ADDRERR                    DMA_ISR_ADDRERR_Msk
#define DMA_ISR_CHFT_Pos                   (8U)
#define DMA_ISR_CHFT_Msk                   (0x1UL << DMA_ISR_CHFT_Pos)
#define DMA_ISR_CHFT                       DMA_ISR_CHFT_Msk
#define DMA_ISR_CHHT_Pos                   (0U)
#define DMA_ISR_CHHT_Msk                   (0x1UL << DMA_ISR_CHHT_Pos)
#define DMA_ISR_CHHT                       DMA_ISR_CHHT_Msk

#define CRC_CR_OPWD_Pos                    (9U)
#define CRC_CR_OPWD_Msk                    (0x1UL << CRC_CR_OPWD_Pos)
#define CRC_CR_OPWD                        CRC_CR_OPWD_Msk
#define CRC_CR_PARA_Pos                    (8U)
#define CRC_CR_PARA_Msk                    (0x1UL << CRC_CR_PARA_Pos)
#define CRC_CR_PARA                        CRC_CR_PARA_Msk
#define CRC_CR_RFLTIN_Pos                  (6U)
#define CRC_CR_RFLTIN_Msk                  (0x3UL << CRC_CR_RFLTIN_Pos)
#define CRC_CR_RFLTIN                      CRC_CR_RFLTIN_Msk
#define CRC_CR_RFLTO_Pos                   (5U)
#define CRC_CR_RFLTO_Msk                   (0x1UL << CRC_CR_RFLTO_Pos)
#define CRC_CR_RFLTO                       CRC_CR_RFLTO_Msk
#define CRC_CR_RES_Pos                     (4U)
#define CRC_CR_RES_Msk                     (0x1UL << CRC_CR_RES_Pos)
#define CRC_CR_RES                         CRC_CR_RES_Msk
#define CRC_CR_BUSY_Pos                    (3U)
#define CRC_CR_BUSY_Msk                    (0x1UL << CRC_CR_BUSY_Pos)
#define CRC_CR_BUSY                        CRC_CR_BUSY_Msk
#define CRC_CR_XOR_Pos                     (2U)
#define CRC_CR_XOR_Msk                     (0x1UL << CRC_CR_XOR_Pos)
#define CRC_CR_XOR                         CRC_CR_XOR_Msk
#define CRC_CR_SEL_Pos                     (0U)
#define CRC_CR_SEL_Msk                     (0x3UL << CRC_CR_SEL_Pos)
#define CRC_CR_SEL                         CRC_CR_SEL_Msk

#define LPTIM_CR_EN_Pos                    (0U)
#define LPTIM_CR_EN_Msk                    (0x1UL << LPTIM_CR_EN_Pos)
#define LPTIM_CR_EN                        LPTIM_CR_EN_Msk
#define LPTIM_CFGR_ETR_AFEN_Pos            (24U)
#define LPTIM_CFGR_ETR_AFEN_Msk            (0x1UL << LPTIM_CFGR_ETR_AFEN_Pos)
#define LPTIM_CFGR_ETR_AFEN                LPTIM_CFGR_ETR_AFEN_Msk
#define LPTIM_CFGR_PSCSEL_Pos              (14U)
#define LPTIM_CFGR_PSCSEL_Msk              (0x1UL << LPTIM_CFGR_PSCSEL_Pos)
#define LPTIM_CFGR_PSCSEL                  LPTIM_CFGR_PSCSEL_Msk
#define LPTIM_CFGR_INSEL_Pos               (13U)
#define LPTIM_CFGR_INSEL_Msk               (0x1UL << LPTIM_CFGR_INSEL_Pos)
#define LPTIM_CFGR_INSEL                   LPTIM_CFGR_INSEL_Msk
#define LPTIM_CFGR_DIVSEL_Pos              (10U)
#define LPTIM_CFGR_DIVSEL_Msk              (0x7UL << LPTIM_CFGR_DIVSEL_Pos)
#define LPTIM_CFGR_DIVSEL                  LPTIM_CFGR_DIVSEL_Msk
#define LPTIM_CFGR_EDGESEL_Pos             (7U)
#define LPTIM_CFGR_EDGESEL_Msk             (0x1UL << LPTIM_CFGR_EDGESEL_Pos)
#define LPTIM_CFGR_EDGESEL                 LPTIM_CFGR_EDGESEL_Msk
#define LPTIM_CFGR_TRIGCFG_Pos             (5U)
#define LPTIM_CFGR_TRIGCFG_Msk             (0x3UL << LPTIM_CFGR_TRIGCFG_Pos)
#define LPTIM_CFGR_TRIGCFG                 LPTIM_CFGR_TRIGCFG_Msk
#define LPTIM_CFGR_ONST_Pos                (2U)
#define LPTIM_CFGR_ONST_Msk                (0x1UL << LPTIM_CFGR_ONST_Pos)
#define LPTIM_CFGR_ONST                    LPTIM_CFGR_ONST_Msk
#define LPTIM_CFGR_TMOD_Pos                (0U)
#define LPTIM_CFGR_TMOD_Msk                (0x3UL << LPTIM_CFGR_TMOD_Pos)
#define LPTIM_CFGR_TMOD                    LPTIM_CFGR_TMOD_Msk
#define LPTIM_IER_CC1IE_Pos                (0U)
#define LPTIM_IER_CC1IE_Msk                (0x1UL << LPTIM_IER_CC1IE_Pos)
#define LPTIM_IER_CC1IE                    LPTIM_IER_CC1IE_Msk
#define LPTIM_IER_CC2IE_Pos                (1U)
#define LPTIM_IER_CC2IE_Msk                (0x1UL << LPTIM_IER_CC2IE_Pos)
#define LPTIM_IER_CC2IE                    LPTIM_IER_CC2IE_Msk
#define LPTIM_IER_OVIE_Pos                 (2U)
#define LPTIM_IER_OVIE_Msk                 (0x1UL << LPTIM_IER_OVIE_Pos)
#define LPTIM_IER_OVIE                     LPTIM_IER_OVIE_Msk
#define LPTIM_IER_TRIGIE_Pos               (3U)
#define LPTIM_IER_TRIGIE_Msk               (0x1UL << LPTIM_IER_TRIGIE_Pos)
#define LPTIM_IER_TRIGIE                   LPTIM_IER_TRIGIE_Msk
#define LPTIM_IER_OVR1IE_Pos               (8U)
#define LPTIM_IER_OVR1IE_Msk               (0x1UL << LPTIM_IER_OVR1IE_Pos)
#define LPTIM_IER_OVR1IE                   LPTIM_IER_OVR1IE_Msk
#define LPTIM_IER_OVR2IE_Pos               (9U)
#define LPTIM_IER_OVR2IE_Msk               (0x1UL << LPTIM_IER_OVR2IE_Pos)
#define LPTIM_IER_OVR2IE                   LPTIM_IER_OVR2IE_Msk
#define LPTIM_ISR_CC1IF_Pos                (0U)
#define LPTIM_ISR_CC1IF_Msk                (0x1UL << LPTIM_ISR_CC1IF_Pos)
#define LPTIM_ISR_CC1IF                    LPTIM_ISR_CC1IF_Msk
#define LPTIM_ISR_CC2IF_Pos                (1U)
#define LPTIM_ISR_CC2IF_Msk                (0x1UL << LPTIM_ISR_CC2IF_Pos)
#define LPTIM_ISR_CC2IF                    LPTIM_ISR_CC2IF_Msk
#define LPTIM_ISR_OVIF_Pos                 (2U)
#define LPTIM_ISR_OVIF_Msk                 (0x1UL << LPTIM_ISR_OVIF_Pos)
#define LPTIM_ISR_OVIF                     LPTIM_ISR_OVIF_Msk
#define LPTIM_ISR_TRIGIF_Pos               (3U)
#define LPTIM_ISR_TRIGIF_Msk               (0x1UL << LPTIM_ISR_TRIGIF_Pos)
#define LPTIM_ISR_TRIGIF                   LPTIM_ISR_TRIGIF_Msk
#define LPTIM_ISR_CAP1OVR_Pos              (8U)
#define LPTIM_ISR_CAP1OVR_Msk              (0x1UL << LPTIM_ISR_CAP1OVR_Pos)
#define LPTIM_ISR_CAP1OVR                  LPTIM_ISR_CAP1OVR_Msk
#define LPTIM_ISR_CAP2OVR_Pos              (9U)
#define LPTIM_ISR_CAP2OVR_Msk              (0x1UL << LPTIM_ISR_CAP2OVR_Pos)
#define LPTIM_ISR_CAP2OVR                  LPTIM_ISR_CAP2OVR_Msk
#define LPTIM_CCSR_CAPCFG1_Pos             (8U)
#define LPTIM_CCSR_CAPCFG1_Msk             (0x3UL << LPTIM_CCSR_CAPCFG1_Pos)
#define LPTIM_CCSR_CAPCFG1                 LPTIM_CCSR_CAPCFG1_Msk
#define LPTIM_CCSR_CAPCFG2_Pos             (10U)
#define LPTIM_CCSR_CAPCFG2_Msk             (0x3UL << LPTIM_CCSR_CAPCFG2_Pos)
#define LPTIM_CCSR_CAPCFG2                 LPTIM_CCSR_CAPCFG2_Msk
#define LPTIM_CCSR_POLAR1_Pos              (4U)
#define LPTIM_CCSR_POLAR1_Msk              (0x1UL << LPTIM_CCSR_POLAR1_Pos)
#define LPTIM_CCSR_POLAR1                  LPTIM_CCSR_POLAR1_Msk
#define LPTIM_CCSR_POLAR2_Pos              (5U)
#define LPTIM_CCSR_POLAR2_Msk              (0x1UL << LPTIM_CCSR_POLAR2_Pos)
#define LPTIM_CCSR_POLAR2                  LPTIM_CCSR_POLAR2_Msk
#define LPTIM_CCSR_CC2S_Pos                (2U)
#define LPTIM_CCSR_CC2S_Msk                (0x3UL << LPTIM_CCSR_CC2S_Pos)
#define LPTIM_CCSR_CC2S                    LPTIM_CCSR_CC2S_Msk
#define LPTIM_CCSR_CC1S_Pos                (0U)
#define LPTIM_CCSR_CC1S_Msk                (0x3UL << LPTIM_CCSR_CC1S_Pos)
#define LPTIM_CCSR_CC1S                    LPTIM_CCSR_CC1S_Msk
#define LPTIM_CCSR_CAP1EDGE_Pos            (12U)
#define LPTIM_CCSR_CAP1EDGE_Msk            (0x1UL << LPTIM_CCSR_CAP1EDGE_Pos)
#define LPTIM_CCSR_CAP1EDGE                LPTIM_CCSR_CAP1EDGE_Msk
#define LPTIM_CCSR_CAP2EDGE_Pos            (13U)
#define LPTIM_CCSR_CAP2EDGE_Msk            (0x1UL << LPTIM_CCSR_CAP2EDGE_Pos)
#define LPTIM_CCSR_CAP2EDGE                LPTIM_CCSR_CAP2EDGE_Msk
#define LPTIM_CCSR_CAP1SSEL_Pos            (16U)
#define LPTIM_CCSR_CAP1SSEL_Msk            (0x3UL << LPTIM_CCSR_CAP1SSEL_Pos)
#define LPTIM_CCSR_CAP1SSEL                LPTIM_CCSR_CAP1SSEL_Msk
#define LPTIM_CCSR_CAP2SSEL_Pos            (18U)
#define LPTIM_CCSR_CAP2SSEL_Msk            (0x3UL << LPTIM_CCSR_CAP2SSEL_Pos)
#define LPTIM_CCSR_CAP2SSEL                LPTIM_CCSR_CAP2SSEL_Msk

#define GPTIM_CR1_CKD_Pos                  (8U)
#define GPTIM_CR1_CKD_Msk                  (0x3UL << GPTIM_CR1_CKD_Pos)
#define GPTIM_CR1_CKD                      GPTIM_CR1_CKD_Msk
#define GPTIM_CR1_ARPE_Pos                 (7U)
#define GPTIM_CR1_ARPE_Msk                 (0x1UL << GPTIM_CR1_ARPE_Pos)
#define GPTIM_CR1_ARPE                     GPTIM_CR1_ARPE_Msk
#define GPTIM_CR1_CMS_Pos                  (5U)
#define GPTIM_CR1_CMS_Msk                  (0x3UL << GPTIM_CR1_CMS_Pos)
#define GPTIM_CR1_CMS                      GPTIM_CR1_CMS_Msk
#define GPTIM_CR1_DIR_Pos                  (4U)
#define GPTIM_CR1_DIR_Msk                  (0x1UL << GPTIM_CR1_DIR_Pos)
#define GPTIM_CR1_DIR                      GPTIM_CR1_DIR_Msk
#define GPTIM_CR1_OPM_Pos                  (3U)
#define GPTIM_CR1_OPM_Msk                  (0x1UL << GPTIM_CR1_OPM_Pos)
#define GPTIM_CR1_OPM                      GPTIM_CR1_OPM_Msk
#define GPTIM_CR1_URS_Pos                  (2U)
#define GPTIM_CR1_URS_Msk                  (0x1UL << GPTIM_CR1_URS_Pos)
#define GPTIM_CR1_URS                      GPTIM_CR1_URS_Msk
#define GPTIM_CR1_UDIS_Pos                 (1U)
#define GPTIM_CR1_UDIS_Msk                 (0x1UL << GPTIM_CR1_UDIS_Pos)
#define GPTIM_CR1_UDIS                     GPTIM_CR1_UDIS_Msk
#define GPTIM_CR1_CEN_Pos                  (0U)
#define GPTIM_CR1_CEN_Msk                  (0x1UL << GPTIM_CR1_CEN_Pos)
#define GPTIM_CR1_CEN                      GPTIM_CR1_CEN_Msk
#define GPTIM_CR2_TI1S_Pos                 (7U)
#define GPTIM_CR2_TI1S_Msk                 (0x1UL << GPTIM_CR2_TI1S_Pos)
#define GPTIM_CR2_TI1S                     GPTIM_CR2_TI1S_Msk
#define GPTIM_CR2_MMS_Pos                  (4U)
#define GPTIM_CR2_MMS_Msk                  (0x7UL << GPTIM_CR2_MMS_Pos)
#define GPTIM_CR2_MMS                      GPTIM_CR2_MMS_Msk
#define GPTIM_CR2_CCDS_Pos                 (3U)
#define GPTIM_CR2_CCDS_Msk                 (0x1UL << GPTIM_CR2_CCDS_Pos)
#define GPTIM_CR2_CCDS                     GPTIM_CR2_CCDS_Msk
#define GPTIM_SMCR_ETP_Pos                 (15U)
#define GPTIM_SMCR_ETP_Msk                 (0x1UL << GPTIM_SMCR_ETP_Pos)
#define GPTIM_SMCR_ETP                     GPTIM_SMCR_ETP_Msk
#define GPTIM_SMCR_ECE_Pos                 (14U)
#define GPTIM_SMCR_ECE_Msk                 (0x1UL << GPTIM_SMCR_ECE_Pos)
#define GPTIM_SMCR_ECE                     GPTIM_SMCR_ECE_Msk
#define GPTIM_SMCR_ETPS_Pos                (12U)
#define GPTIM_SMCR_ETPS_Msk                (0x3UL << GPTIM_SMCR_ETPS_Pos)
#define GPTIM_SMCR_ETPS                    GPTIM_SMCR_ETPS_Msk
#define GPTIM_SMCR_ETF_Pos                 (8U)
#define GPTIM_SMCR_ETF_Msk                 (0xFUL << GPTIM_SMCR_ETF_Pos)
#define GPTIM_SMCR_ETF                     GPTIM_SMCR_ETF_Msk
#define GPTIM_SMCR_MSM_Pos                 (7U)
#define GPTIM_SMCR_MSM_Msk                 (0x1UL << GPTIM_SMCR_MSM_Pos)
#define GPTIM_SMCR_MSM                     GPTIM_SMCR_MSM_Msk
#define GPTIM_SMCR_TS_Pos                  (4U)
#define GPTIM_SMCR_TS_Msk                  (0x7UL << GPTIM_SMCR_TS_Pos)
#define GPTIM_SMCR_TS                      GPTIM_SMCR_TS_Msk
#define GPTIM_SMCR_SMS_Pos                 (0U)
#define GPTIM_SMCR_SMS_Msk                 (0x7UL << GPTIM_SMCR_SMS_Pos)
#define GPTIM_SMCR_SMS                     GPTIM_SMCR_SMS_Msk
#define GPTIM_DIER_CC1BURSTEN_Pos          (16U)
#define GPTIM_DIER_CC1BURSTEN_Msk          (0x1UL << GPTIM_DIER_CC1BURSTEN_Pos)
#define GPTIM_DIER_CC1BURSTEN              GPTIM_DIER_CC1BURSTEN_Msk
#define GPTIM_DIER_CC2BURSTEN_Pos          (17U)
#define GPTIM_DIER_CC2BURSTEN_Msk          (0x1UL << GPTIM_DIER_CC2BURSTEN_Pos)
#define GPTIM_DIER_CC2BURSTEN              GPTIM_DIER_CC2BURSTEN_Msk
#define GPTIM_DIER_CC3BURSTEN_Pos          (18U)
#define GPTIM_DIER_CC3BURSTEN_Msk          (0x1UL << GPTIM_DIER_CC3BURSTEN_Pos)
#define GPTIM_DIER_CC3BURSTEN              GPTIM_DIER_CC3BURSTEN_Msk
#define GPTIM_DIER_CC4BURSTEN_Pos          (19U)
#define GPTIM_DIER_CC4BURSTEN_Msk          (0x1UL << GPTIM_DIER_CC4BURSTEN_Pos)
#define GPTIM_DIER_CC4BURSTEN              GPTIM_DIER_CC4BURSTEN_Msk
#define GPTIM_DIER_TDE_Pos                 (14U)
#define GPTIM_DIER_TDE_Msk                 (0x1UL << GPTIM_DIER_TDE_Pos)
#define GPTIM_DIER_TDE                     GPTIM_DIER_TDE_Msk
#define GPTIM_DIER_CCDE_Pos                (9U)
#define GPTIM_DIER_CCDE_Msk                (0x1UL << GPTIM_DIER_CCDE_Pos)
#define GPTIM_DIER_CCDE                    GPTIM_DIER_CCDE_Msk
#define GPTIM_DIER_UDE_Pos                 (8U)
#define GPTIM_DIER_UDE_Msk                 (0x1UL << GPTIM_DIER_UDE_Pos)
#define GPTIM_DIER_UDE                     GPTIM_DIER_UDE_Msk
#define GPTIM_DIER_TIE_Pos                 (6U)
#define GPTIM_DIER_TIE_Msk                 (0x1UL << GPTIM_DIER_TIE_Pos)
#define GPTIM_DIER_TIE                     GPTIM_DIER_TIE_Msk
#define GPTIM_DIER_CCIE_Pos                (1U)
#define GPTIM_DIER_CCIE_Msk                (0x1UL << GPTIM_DIER_CCIE_Pos)
#define GPTIM_DIER_CCIE                    GPTIM_DIER_CCIE_Msk
#define GPTIM_DIER_UIE_Pos                 (0U)
#define GPTIM_DIER_UIE_Msk                 (0x1UL << GPTIM_DIER_UIE_Pos)
#define GPTIM_DIER_UIE                     GPTIM_DIER_UIE_Msk
#define GPTIM_ISR_CCOF_Pos                 (9U)
#define GPTIM_ISR_CCOF_Msk                 (0x1UL << GPTIM_ISR_CCOF_Pos)
#define GPTIM_ISR_CCOF                     GPTIM_ISR_CCOF_Msk
#define GPTIM_ISR_TIF_Pos                  (6U)
#define GPTIM_ISR_TIF_Msk                  (0x1UL << GPTIM_ISR_TIF_Pos)
#define GPTIM_ISR_TIF                      GPTIM_ISR_TIF_Msk
#define GPTIM_ISR_CCIF_Pos                 (1U)
#define GPTIM_ISR_CCIF_Msk                 (0x1UL << GPTIM_ISR_CCIF_Pos)
#define GPTIM_ISR_CCIF                     GPTIM_ISR_CCIF_Msk
#define GPTIM_ISR_UIF_Pos                  (0U)
#define GPTIM_ISR_UIF_Msk                  (0x1UL << GPTIM_ISR_UIF_Pos)
#define GPTIM_ISR_UIF                      GPTIM_ISR_UIF_Msk
#define GPTIM_EGR_TG_Pos                   (6U)
#define GPTIM_EGR_TG_Msk                   (0x1UL << GPTIM_EGR_TG_Pos)
#define GPTIM_EGR_TG                       GPTIM_EGR_TG_Msk
#define GPTIM_EGR_CCG_Pos                  (1U)
#define GPTIM_EGR_CCG_Msk                  (0x1UL << GPTIM_EGR_CCG_Pos)
#define GPTIM_EGR_CCG                      GPTIM_EGR_CCG_Msk
#define GPTIM_EGR_UG_Pos                   (0U)
#define GPTIM_EGR_UG_Msk                   (0x1UL << GPTIM_EGR_UG_Pos)
#define GPTIM_EGR_UG                       GPTIM_EGR_UG_Msk
#define GPTIM_DCR_DBL_Pos                  (8U)
#define GPTIM_DCR_DBL_Msk                  (0x1FUL << GPTIM_DCR_DBL_Pos)
#define GPTIM_DCR_DBL                      GPTIM_DCR_DBL_Msk
#define GPTIM_DCR_DBA_Pos                  (0U)
#define GPTIM_DCR_DBA_Msk                  (0x1FUL << GPTIM_DCR_DBA_Pos)
#define GPTIM_DCR_DBA                      GPTIM_DCR_DBA_Msk
#define GPTIM_ITRSEL_ITR0SEL_Pos           (0U)
#define GPTIM_ITRSEL_ITR0SEL_Msk           (0x3UL << GPTIM_ITRSEL_ITR0SEL_Pos)
#define GPTIM_ITRSEL_ITR0SEL               GPTIM_ITRSEL_ITR0SEL_Msk
#define GPTIM_ITRSEL_ITR1SEL_Pos           (2U)
#define GPTIM_ITRSEL_ITR1SEL_Msk           (0x3UL << GPTIM_ITRSEL_ITR1SEL_Pos)
#define GPTIM_ITRSEL_ITR1SEL               GPTIM_ITRSEL_ITR1SEL_Msk
#define GPTIM_ITRSEL_ITR2SEL_Pos           (4U)
#define GPTIM_ITRSEL_ITR2SEL_Msk           (0x3UL << GPTIM_ITRSEL_ITR2SEL_Pos)
#define GPTIM_ITRSEL_ITR2SEL               GPTIM_ITRSEL_ITR2SEL_Msk
#define GPTIM_ITRSEL_ITR3SEL_Pos           (6U)
#define GPTIM_ITRSEL_ITR3SEL_Msk           (0x3UL << GPTIM_ITRSEL_ITR3SEL_Pos)
#define GPTIM_ITRSEL_ITR3SEL               GPTIM_ITRSEL_ITR3SEL_Msk
#define GPTIM_CCMR_OCCE_Pos                (7U)
#define GPTIM_CCMR_OCCE_Msk                (0x1UL << GPTIM_CCMR_OCCE_Pos)
#define GPTIM_CCMR_OCCE                    GPTIM_CCMR_OCCE_Msk
#define GPTIM_CCMR_OCM_Pos                 (4U)
#define GPTIM_CCMR_OCM_Msk                 (0x7UL << GPTIM_CCMR_OCM_Pos)
#define GPTIM_CCMR_OCM                     GPTIM_CCMR_OCM_Msk
#define GPTIM_CCMR_OCPE_Pos                (3U)
#define GPTIM_CCMR_OCPE_Msk                (0x1UL << GPTIM_CCMR_OCPE_Pos)
#define GPTIM_CCMR_OCPE                    GPTIM_CCMR_OCPE_Msk
#define GPTIM_CCMR_OCFE_Pos                (2U)
#define GPTIM_CCMR_OCFE_Msk                (0x1UL << GPTIM_CCMR_OCFE_Pos)
#define GPTIM_CCMR_OCFE                    GPTIM_CCMR_OCFE_Msk
#define GPTIM_CCMR_ICF_Pos                 (4U)
#define GPTIM_CCMR_ICF_Msk                 (0xFUL << GPTIM_CCMR_ICF_Pos)
#define GPTIM_CCMR_ICF                     GPTIM_CCMR_ICF_Msk
#define GPTIM_CCMR_ICPSC_Pos               (2U)
#define GPTIM_CCMR_ICPSC_Msk               (0x3UL << GPTIM_CCMR_ICPSC_Pos)
#define GPTIM_CCMR_ICPSC                   GPTIM_CCMR_ICPSC_Msk
#define GPTIM_CCMR_CCS_Pos                 (0U)
#define GPTIM_CCMR_CCS_Msk                 (0x3UL << GPTIM_CCMR_CCS_Pos)
#define GPTIM_CCMR_CCS                     GPTIM_CCMR_CCS_Msk
#define GPTIM_CCER_CCOP_Pos                (1U)
#define GPTIM_CCER_CCOP_Msk                (0x1UL << GPTIM_CCER_CCOP_Pos)
#define GPTIM_CCER_CCOP                    GPTIM_CCER_CCOP_Msk
#define GPTIM_CCER_CCIP_Pos                (1U)
#define GPTIM_CCER_CCIP_Msk                (0x1UL << GPTIM_CCER_CCIP_Pos)
#define GPTIM_CCER_CCIP                    GPTIM_CCER_CCIP_Msk
#define GPTIM_CCER_CCE_Pos                 (0U)
#define GPTIM_CCER_CCE_Msk                 (0x1UL << GPTIM_CCER_CCE_Pos)
#define GPTIM_CCER_CCE                     GPTIM_CCER_CCE_Msk

#define BSTIM_CR1_ARPE_Pos                 (7U)
#define BSTIM_CR1_ARPE_Msk                 (0x1UL << BSTIM_CR1_ARPE_Pos)
#define BSTIM_CR1_ARPE                     BSTIM_CR1_ARPE_Msk
#define BSTIM_CR1_OPM_Pos                  (3U)
#define BSTIM_CR1_OPM_Msk                  (0x1UL << BSTIM_CR1_OPM_Pos)
#define BSTIM_CR1_OPM                      BSTIM_CR1_OPM_Msk
#define BSTIM_CR1_URS_Pos                  (2U)
#define BSTIM_CR1_URS_Msk                  (0x1UL << BSTIM_CR1_URS_Pos)
#define BSTIM_CR1_URS                      BSTIM_CR1_URS_Msk
#define BSTIM_CR1_UDIS_Pos                 (1U)
#define BSTIM_CR1_UDIS_Msk                 (0x1UL << BSTIM_CR1_UDIS_Pos)
#define BSTIM_CR1_UDIS                     BSTIM_CR1_UDIS_Msk
#define BSTIM_CR1_CEN_Pos                  (0U)
#define BSTIM_CR1_CEN_Msk                  (0x1UL << BSTIM_CR1_CEN_Pos)
#define BSTIM_CR1_CEN                      BSTIM_CR1_CEN_Msk
#define BSTIM_CR2_MMS_Pos                  (4U)
#define BSTIM_CR2_MMS_Msk                  (0x7UL << BSTIM_CR2_MMS_Pos)
#define BSTIM_CR2_MMS                      BSTIM_CR2_MMS_Msk
#define BSTIM_IER_UIE_Pos                  (0U)
#define BSTIM_IER_UIE_Msk                  (0x1UL << BSTIM_IER_UIE_Pos)
#define BSTIM_IER_UIE                      BSTIM_IER_UIE_Msk
#define BSTIM_ISR_UIF_Pos                  (0U)
#define BSTIM_ISR_UIF_Msk                  (0x1UL << BSTIM_ISR_UIF_Pos)
#define BSTIM_ISR_UIF                      BSTIM_ISR_UIF_Msk
#define BSTIM_EGR_UG_Pos                   (0U)
#define BSTIM_EGR_UG_Msk                   (0x1UL << BSTIM_EGR_UG_Pos)
#define BSTIM_EGR_UG                       BSTIM_EGR_UG_Msk

#define GPIO_FCR_Pos                       (0U)
#define GPIO_FCR_Msk                       (0x3UL << GPIO_FCR_Pos)
#define GPIO_FCR                           GPIO_FCR_Msk
#define GPIO_EXTIEDS_Pos                   (0U)
#define GPIO_EXTIEDS_Msk                   (0x3UL << GPIO_EXTIEDS_Pos)
#define GPIO_EXTIEDS                       GPIO_EXTIEDS_Msk
#define GPIO_FOUTSEL_FOUT0_Pos             (0U)
#define GPIO_FOUTSEL_FOUT0_Msk             (0xFUL << GPIO_FOUTSEL_FOUT0_Pos)
#define GPIO_FOUTSEL_FOUT0                 GPIO_FOUTSEL_FOUT0_Msk
#define GPIO_FOUTSEL_FOUT1_Pos             (4U)
#define GPIO_FOUTSEL_FOUT1_Msk             (0xFUL << GPIO_FOUTSEL_FOUT1_Pos)
#define GPIO_FOUTSEL_FOUT1                 GPIO_FOUTSEL_FOUT1_Msk
#define GPIO_EXTISEL_EXTI0_Pos             (0U)
#define GPIO_EXTISEL_EXTI0_Msk             (0x3U << GPIO_EXTISEL_EXTI0_Pos)
#define GPIO_EXTISEL_EXTI0                 GPIO_EXTISEL_EXTI0_Msk
#define GPIO_EXTISEL_EXTI1_Pos             (2U)
#define GPIO_EXTISEL_EXTI1_Msk             (0x3U << GPIO_EXTISEL_EXTI1_Pos)
#define GPIO_EXTISEL_EXTI1                 GPIO_EXTISEL_EXTI1_Msk
#define GPIO_EXTISEL_EXTI2_Pos             (4U)
#define GPIO_EXTISEL_EXTI2_Msk             (0x3U << GPIO_EXTISEL_EXTI2_Pos)
#define GPIO_EXTISEL_EXTI2                 GPIO_EXTISEL_EXTI2_Msk
#define GPIO_EXTISEL_EXTI3_Pos             (6U)
#define GPIO_EXTISEL_EXTI3_Msk             (0x3U << GPIO_EXTISEL_EXTI3_Pos)
#define GPIO_EXTISEL_EXTI3                 GPIO_EXTISEL_EXTI3_Msk
#define GPIO_EXTISEL_EXTI4_Pos             (8U)
#define GPIO_EXTISEL_EXTI4_Msk             (0x3U << GPIO_EXTISEL_EXTI4_Pos)
#define GPIO_EXTISEL_EXTI4                 GPIO_EXTISEL_EXTI4_Msk
#define GPIO_EXTISEL_EXTI5_Pos             (10U)
#define GPIO_EXTISEL_EXTI5_Msk             (0x3U << GPIO_EXTISEL_EXTI5_Pos)
#define GPIO_EXTISEL_EXTI5                 GPIO_EXTISEL_EXTI5_Msk
#define GPIO_EXTISEL_EXTI6_Pos             (12U)
#define GPIO_EXTISEL_EXTI6_Msk             (0x3U << GPIO_EXTISEL_EXTI6_Pos)
#define GPIO_EXTISEL_EXTI6                 GPIO_EXTISEL_EXTI6_Msk
#define GPIO_EXTISEL_EXTI7_Pos             (14U)
#define GPIO_EXTISEL_EXTI7_Msk             (0x3U << GPIO_EXTISEL_EXTI7_Pos)
#define GPIO_EXTISEL_EXTI7                 GPIO_EXTISEL_EXTI7_Msk
#define GPIO_EXTISEL_EXTI8_Pos             (16U)
#define GPIO_EXTISEL_EXTI8_Msk             (0x3U << GPIO_EXTISEL_EXTI8_Pos)
#define GPIO_EXTISEL_EXTI8                 GPIO_EXTISEL_EXTI8_Msk
#define GPIO_EXTISEL_EXTI9_Pos             (18U)
#define GPIO_EXTISEL_EXTI9_Msk             (0x3U << GPIO_EXTISEL_EXTI9_Pos)
#define GPIO_EXTISEL_EXTI9                 GPIO_EXTISEL_EXTI9_Msk
#define GPIO_EXTISEL_EXTI10_Pos            (20U)
#define GPIO_EXTISEL_EXTI10_Msk            (0x3U << GPIO_EXTISEL_EXTI10_Pos)
#define GPIO_EXTISEL_EXTI10                GPIO_EXTISEL_EXTI10_Msk
#define GPIO_EXTISEL_EXTI12_Pos            (24U)
#define GPIO_EXTISEL_EXTI12_Msk            (0x3U << GPIO_EXTISEL_EXTI12_Pos)
#define GPIO_EXTISEL_EXTI12                GPIO_EXTISEL_EXTI12_Msk
#define GPIO_EXTISEL_EXTI13_Pos            (26U)
#define GPIO_EXTISEL_EXTI13_Msk            (0x3U << GPIO_EXTISEL_EXTI13_Pos)
#define GPIO_EXTISEL_EXTI13                GPIO_EXTISEL_EXTI13_Msk
#define GPIO_EXTISEL_EXTI14_Pos            (28U)
#define GPIO_EXTISEL_EXTI14_Msk            (0x3U << GPIO_EXTISEL_EXTI14_Pos)
#define GPIO_EXTISEL_EXTI14                GPIO_EXTISEL_EXTI14_Msk
#define GPIO_PINWKEN_EN_Pos                (0U)
#define GPIO_PINWKEN_EN_Msk                (0xffU << GPIO_PINWKEN_EN_Pos)
#define GPIO_PINWKEN_EN                    GPIO_PINWKEN_EN_Msk
#define GPIO_PINWKEN_WKISEL_Pos            (31U)
#define GPIO_PINWKEN_WKISEL_Msk            (0x1U << GPIO_PINWKEN_WKISEL_Pos)
#define GPIO_PINWKEN_WKISEL                GPIO_PINWKEN_WKISEL_Msk
#define LL_GPIO_WKUP_INT_ENTRY_NMI         (0x0U << GPIO_PINWKEN_WKISEL_Pos)
#define LL_GPIO_WKUP_INT_ENTRY_NUM_38      (0x1U << GPIO_PINWKEN_WKISEL_Pos)
#define GPIO_PINWKEN_Pos                   (0U)
#define GPIO_PINWKEN_Msk                   (0x1U << GPIO_PINWKEN_Pos)
#define GPIO_PINWKEN                       GPIO_PINWKEN_Msk

#define RTC_IER_ADJ_IE_Pos                 (12U)
#define RTC_IER_ADJ_IE_Msk                 (0x1UL << RTC_IER_ADJ_IE_Pos)
#define RTC_IER_ADJ_IE                     RTC_IER_ADJ_IE_Msk
#define RTC_IER_ALARM_IE_Pos               (11U)
#define RTC_IER_ALARM_IE_Msk               (0x1UL << RTC_IER_ALARM_IE_Pos)
#define RTC_IER_ALARM_IE                   RTC_IER_ALARM_IE_Msk
#define RTC_IER_1KHZ_IE_Pos                (10U)
#define RTC_IER_1KHZ_IE_Msk                (0x1UL << RTC_IER_1KHZ_IE_Pos)
#define RTC_IER_1KHZ_IE                    RTC_IER_1KHZ_IE_Msk
#define RTC_IER_256HZ_IE_Pos               (9U)
#define RTC_IER_256HZ_IE_Msk               (0x1UL << RTC_IER_256HZ_IE_Pos)
#define RTC_IER_256HZ_IE                   RTC_IER_256HZ_IE_Msk
#define RTC_IER_64HZ_IE_Pos                (8U)
#define RTC_IER_64HZ_IE_Msk                (0x1UL << RTC_IER_64HZ_IE_Pos)
#define RTC_IER_64HZ_IE                    RTC_IER_64HZ_IE_Msk
#define RTC_IER_16HZ_IE_Pos                (7U)
#define RTC_IER_16HZ_IE_Msk                (0x1UL << RTC_IER_16HZ_IE_Pos)
#define RTC_IER_16HZ_IE                    RTC_IER_16HZ_IE_Msk
#define RTC_IER_8HZ_IE_Pos                 (6U)
#define RTC_IER_8HZ_IE_Msk                 (0x1UL << RTC_IER_8HZ_IE_Pos)
#define RTC_IER_8HZ_IE                     RTC_IER_8HZ_IE_Msk
#define RTC_IER_4HZ_IE_Pos                 (5U)
#define RTC_IER_4HZ_IE_Msk                 (0x1UL << RTC_IER_4HZ_IE_Pos)
#define RTC_IER_4HZ_IE                     RTC_IER_4HZ_IE_Msk
#define RTC_IER_2HZ_IE_Pos                 (4U)
#define RTC_IER_2HZ_IE_Msk                 (0x1UL << RTC_IER_2HZ_IE_Pos)
#define RTC_IER_2HZ_IE                     RTC_IER_2HZ_IE_Msk
#define RTC_IER_SEC_IE_Pos                 (3U)
#define RTC_IER_SEC_IE_Msk                 (0x1UL << RTC_IER_SEC_IE_Pos)
#define RTC_IER_SEC_IE                     RTC_IER_SEC_IE_Msk
#define RTC_IER_MIN_IE_Pos                 (2U)
#define RTC_IER_MIN_IE_Msk                 (0x1UL << RTC_IER_MIN_IE_Pos)
#define RTC_IER_MIN_IE                     RTC_IER_MIN_IE_Msk
#define RTC_IER_HOUR_IE_Pos                (1U)
#define RTC_IER_HOUR_IE_Msk                (0x1UL << RTC_IER_HOUR_IE_Pos)
#define RTC_IER_HOUR_IE                    RTC_IER_HOUR_IE_Msk
#define RTC_IER_DAY_IE_Pos                 (0U)
#define RTC_IER_DAY_IE_Msk                 (0x1UL << RTC_IER_DAY_IE_Pos)
#define RTC_IER_DAY_IE                     RTC_IER_DAY_IE_Msk
#define RTC_ISR_ADJ_IF_Pos                 (12U)
#define RTC_ISR_ADJ_IF_Msk                 (0x1UL << RTC_ISR_ADJ_IF_Pos)
#define RTC_ISR_ADJ_IF                     RTC_ISR_ADJ_IF_Msk
#define RTC_ISR_ALARM_IF_Pos               (11U)
#define RTC_ISR_ALARM_IF_Msk               (0x1UL << RTC_ISR_ALARM_IF_Pos)
#define RTC_ISR_ALARM_IF                   RTC_ISR_ALARM_IF_Msk
#define RTC_ISR_1KHZ_IF_Pos                (10U)
#define RTC_ISR_1KHZ_IF_Msk                (0x1UL << RTC_ISR_1KHZ_IF_Pos)
#define RTC_ISR_1KHZ_IF                    RTC_ISR_1KHZ_IF_Msk
#define RTC_ISR_256HZ_IF_Pos               (9U)
#define RTC_ISR_256HZ_IF_Msk               (0x1UL << RTC_ISR_256HZ_IF_Pos)
#define RTC_ISR_256HZ_IF                   RTC_ISR_256HZ_IF_Msk
#define RTC_ISR_64HZ_IF_Pos                (8U)
#define RTC_ISR_64HZ_IF_Msk                (0x1UL << RTC_ISR_64HZ_IF_Pos)
#define RTC_ISR_64HZ_IF                    RTC_ISR_64HZ_IF_Msk
#define RTC_ISR_16HZ_IF_Pos                (7U)
#define RTC_ISR_16HZ_IF_Msk                (0x1UL << RTC_ISR_16HZ_IF_Pos)
#define RTC_ISR_16HZ_IF                    RTC_ISR_16HZ_IF_Msk
#define RTC_ISR_8HZ_IF_Pos                 (6U)
#define RTC_ISR_8HZ_IF_Msk                 (0x1UL << RTC_ISR_8HZ_IF_Pos)
#define RTC_ISR_8HZ_IF                     RTC_ISR_8HZ_IF_Msk
#define RTC_ISR_4HZ_IF_Pos                 (5U)
#define RTC_ISR_4HZ_IF_Msk                 (0x1UL << RTC_ISR_4HZ_IF_Pos)
#define RTC_ISR_4HZ_IF                     RTC_ISR_4HZ_IF_Msk
#define RTC_ISR_2HZ_IF_Pos                 (4U)
#define RTC_ISR_2HZ_IF_Msk                 (0x1UL << RTC_ISR_2HZ_IF_Pos)
#define RTC_ISR_2HZ_IF                     RTC_ISR_2HZ_IF_Msk
#define RTC_ISR_SEC_IF_Pos                 (3U)
#define RTC_ISR_SEC_IF_Msk                 (0x1UL << RTC_ISR_SEC_IF_Pos)
#define RTC_ISR_SEC_IF                     RTC_ISR_SEC_IF_Msk
#define RTC_ISR_MIN_IF_Pos                 (2U)
#define RTC_ISR_MIN_IF_Msk                 (0x1UL << RTC_ISR_MIN_IF_Pos)
#define RTC_ISR_MIN_IF                     RTC_ISR_MIN_IF_Msk
#define RTC_ISR_HOUR_IF_Pos                (1U)
#define RTC_ISR_HOUR_IF_Msk                (0x1UL << RTC_ISR_HOUR_IF_Pos)
#define RTC_ISR_HOUR_IF                    RTC_ISR_HOUR_IF_Msk
#define RTC_ISR_DAY_IF_Pos                 (0U)
#define RTC_ISR_DAY_IF_Msk                 (0x1UL << RTC_ISR_DAY_IF_Pos)
#define RTC_ISR_DAY_IF                     RTC_ISR_DAY_IF_Msk
#define RTC_TMSEL_TMSEL_Pos                (0U)
#define RTC_TMSEL_TMSEL_Msk                (0xFUL << RTC_TMSEL_TMSEL_Pos)
#define RTC_TMSEL_TMSEL                    RTC_TMSEL_TMSEL_Msk
#define RTC_ADSIGN_ADSIGN_Pos              (0U)
#define RTC_ADSIGN_ADSIGN_Msk              (0x1UL << RTC_ADSIGN_ADSIGN_Pos)
#define RTC_ADSIGN_ADSIGN                  RTC_ADSIGN_ADSIGN_Msk

#ifdef __cplusplus
}
#endif

#endif  /* FM33LC0XX_H */
