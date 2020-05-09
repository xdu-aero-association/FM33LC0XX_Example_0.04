#ifndef __SPI_H__
#define __SPI_H__

#include <stdbool.h>
#include "main.h"

void SpiInit(void);

void SpiWriteDataDMA(uint32_t dataAddr, uint16_t length);
void SpiReadDataDMA(uint32_t dataAddr, uint16_t length);
bool SpiWriteDataComplete(void);
bool SpiReadDataComplete(void);

#endif
