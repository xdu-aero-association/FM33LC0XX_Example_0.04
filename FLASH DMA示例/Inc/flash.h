#ifndef __FLASH_H__
#define __FLASH_H__

#include "main.h"

void FlashReadDma(uint32_t addr, uint8_t *buffer, uint32_t length);
void FlashWriteDma(uint32_t addr, uint8_t *buffer);

#endif
