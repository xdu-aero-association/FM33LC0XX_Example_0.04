#ifndef __STREAM_H__
#define __STREAM_H__

#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    uint16_t maxLen;
    uint16_t length;
    uint16_t pRead;
    uint16_t pWrite;
}DataStream;

int32_t StreamInit(DataStream *stream, uint8_t *buffer, uint16_t length);
int32_t StreamReadData(DataStream *stream, uint8_t *buffer, uint16_t length);
int32_t StreamWriteData(DataStream *stream, uint8_t *buffer, uint16_t length);
uint16_t StreamGetDataSize(DataStream *stream);
uint16_t StreamGetSpaceSize(DataStream *stream);

#endif
