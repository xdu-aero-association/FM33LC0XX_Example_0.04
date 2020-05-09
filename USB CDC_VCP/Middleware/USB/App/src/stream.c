#include "stream.h"

int32_t StreamInit(DataStream *stream, uint8_t *buffer, uint16_t length)
{
    stream->buffer = buffer;
    stream->maxLen = length;
    stream->length = 0;
    stream->pRead = 0;
    stream->pWrite = 0;
    return 0;
}

int32_t StreamReadData(DataStream *stream, uint8_t *buffer, uint16_t length)
{
    uint32_t count;
    
    if (length > stream->length)
    {
        length = stream->length;
    }
    
    count = length;
    while (count--)
    {
        *buffer = *(stream->buffer + stream->pRead);
        buffer++; 
        stream->pRead++;
        stream->pRead %= stream->maxLen;
    }
    stream->length -= length;
    
    return length;
}

int32_t StreamWriteData(DataStream *stream, uint8_t *buffer, uint16_t length)
{
    uint32_t count;
    
    if ((length + stream->length) > stream->maxLen)
    {
        length = stream->maxLen - stream->length;
    }
    
    count = length;
    while (count--)
    {
        *(stream->buffer + stream->pWrite) = *buffer;
        buffer++;
        stream->pWrite++;
        stream->pWrite %= stream->maxLen;
    }
    stream->length += length;
    
    return length;
}

uint16_t StreamGetDataSize(DataStream *stream)
{
    return stream->length;
}

uint16_t StreamGetSpaceSize(DataStream *stream)
{
    return stream->maxLen - stream->length;
}
