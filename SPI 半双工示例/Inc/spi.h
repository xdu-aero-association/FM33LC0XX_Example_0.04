#ifndef __SPI_H__
#define __SPI_H__

#include "main.h"

void SpiInit(void);

void SpiData8Bit(void);
void SpiData16Bit(void);

void SpiWriteCmd(uint8_t cmd);
void SpiWriteData(uint32_t data);
void SpiReadData(uint8_t cmd, uint8_t *data, uint16_t length);

#endif
