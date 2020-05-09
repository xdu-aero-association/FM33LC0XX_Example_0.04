#ifndef __SPI_H__
#define __SPI_H__

#include "main.h"

void SpiInit(void);
uint32_t SpiWriteAndRead(uint32_t data);
void SpiWriteData(uint8_t *data, uint16_t length);
void SpiReadData(uint8_t *data, uint16_t length);

#endif
