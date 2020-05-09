/**************************************************************************//**
 * @file     system_<Device>.c
 * @brief    CMSIS Cortex-M# Device Peripheral Access Layer Source File for
 *           Device <Device>
 * @version  V3.10
 * @date     23. November 2012
 *
 * @note
 *
 ******************************************************************************/
/* Copyright (c) 2012 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


#include "fm33lc0xx.h"
/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
/* ToDo: add here your necessary defines for device initialization
         following is an example for different system frequencies             */

/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
/* ToDo: initialize SystemCoreClock with the system core clock frequency value
         achieved after system intitialization.
         This means system core clock frequency after call to SystemInit()    */
uint32_t SystemCoreClock = __SYSTEM_CLOCK;  /*!< System Clock Frequency (Core Clock)*/


/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{

}
/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit (void)
{
    uint32_t temp;
    /*trim*/ 
    temp = *(uint32_t*)(0x1FFFFB40U);
   
    if(!((temp>>16)&temp))
    {
        RCC->RCHFTR = (0x7F&temp);
    }
    temp = *(uint32_t*)(0x1FFFFB44U);
    if((((temp>>16)^temp)&0xFF) == 0xFF)
    {
        RCC->RCMFTR = (0x7F&temp);
    }
    /*  */
    RCC->PLLCR = (uint32_t)0x00000000U;
    RCC->SYSCLKCR = (uint32_t)0x0A000000U;
     /* PAD RCC*/
    RCC->PCLKCR1 |=  (0x1U << 7U);
    #ifdef USE_LSCLK_CLOCK_SRC_XTLF           
        GPIOD->FCR |= 0x3C0000; 
        /* XTLF*/
        RCC->XTLFCR  = (uint32_t)(0x00000000U);
        /* XTLF*/
        RCC->XTLFCR  |= (uint32_t)(0x00000005U<<8);
        for(temp = 2000;temp>0;temp--);
        /* LSCLKXTLF*/
        RCC->LSCLKSEL = 0xAA;
        /* LSCXTLF*/
        RCC->SYSCLKCR |= 0x8000000U;
    #else
        RCC->SYSCLKCR &= 0x7FFFFFFU;
        RCC->LSCLKSEL = 0x55;
    #endif
    /*PDR*/
    RMU->PDRCR |=0x01;
    /*BOR*/
    RMU->BORCR &=0xFE;
    
    /* DEBUG IWDT WWDT */
    DBG->CR =0x03;
    
} 



