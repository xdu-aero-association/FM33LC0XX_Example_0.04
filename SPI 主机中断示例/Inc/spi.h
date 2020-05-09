#ifndef __SPI_H__
#define __SPI_H__

#include <stdbool.h>
#include "main.h"

void SpiInit(void);

void SpiWriteDataIRQ(uint8_t *data, uint16_t length);
void SpiReadDataIRQ(uint8_t *data, uint16_t length);

bool SpiWriteIsComplete(void);
bool SpiReadIsComplete(void);

#endif
