#ifndef __CRC_H__
#define __CRC_H__

#include "main.h"

uint8_t CRC7_MMC(uint8_t *data, uint32_t length);
uint8_t CRC8(uint8_t *data, uint32_t length);
uint16_t CRC16_CCITT(uint8_t *data, uint32_t length);
uint32_t CRC32(uint8_t *data, uint32_t length);

uint16_t CRC16_CCITT_WORD(uint32_t *data, uint32_t length);

#endif
