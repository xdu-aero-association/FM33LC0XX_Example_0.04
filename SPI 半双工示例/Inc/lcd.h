#ifndef __LCD_H__
#define __LCD_H__

#include <stdint.h>
#include "main.h"
#include "spi.h"

#define WHITE   0xffff
#define RED     0xf800
#define GREEN   0x07e0
#define BLUE    0x001f
#define BLACK   0x0000

void LcdInit(void);

void LcdSetPosition(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2);
void LcdFill(uint16_t x, uint16_t y, uint16_t length, uint16_t height, 
        uint16_t color);
void LcdClear(uint16_t color);

void LcdReadID(uint8_t *id);

#endif
