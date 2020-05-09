#ifndef __USER_INIT_H__
#define __USER_INIT_H__

#include "main.h"

// 8M: LL_RCC_RCHF_FREQUENCY_8MHZ
// 16M: LL_RCC_RCHF_FREQUENCY_16MHZ
// 24M: LL_RCC_RCHF_FREQUENCY_24MHZ
#define RCHF_CLOCK  LL_RCC_RCHF_FREQUENCY_8MHZ

#define LED0_GPIO   GPIOC
#define LED0_PIN    LL_GPIO_PIN_0

#define LED0_ON()   LL_GPIO_ResetOutputPin(LED0_GPIO, LED0_PIN)
#define LED0_OFF()  LL_GPIO_SetOutputPin(LED0_GPIO, LED0_PIN)
#define LED0_TOG()  LL_GPIO_ToggleOutputPin(LED0_GPIO, LED0_PIN)

extern uint32_t systemClock;

void UserInit(void);

void DelayUs(uint32_t count);
void DelayMs(uint32_t count);

#endif
