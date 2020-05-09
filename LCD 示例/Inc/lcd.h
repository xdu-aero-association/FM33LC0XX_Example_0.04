#ifndef __LCD_H__
#define __LCD_H__

#include <stdbool.h>
#include "main.h"

void LcdInit(void);
void LcdDisplayAll(bool state);
void LcdDisplayBIT(uint32_t x, uint32_t y, bool value);
void LcdDisplayNumber(uint32_t number);


#endif
