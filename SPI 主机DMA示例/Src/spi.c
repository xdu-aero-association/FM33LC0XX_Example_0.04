#include "spi.h"

uint8_t *wData, *rData;
uint16_t wLength, rLength;

void SpiInit(void)
{
    LL_SPI_InitTypeDef SPI_InitStruct = {0};
    LL_DMA_InitTypeDef DMA_InitStruct = {0};
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2;
    SPI_InitStruct.BitOrder = LL_SPI_BIT_ORDER_MSB_FIRST;
    SPI_InitStruct.ClockPhase = LL_SPI_SPI_PHASE_1EDGE;
    SPI_InitStruct.ClockPolarity = LL_SPI_SPI_POLARITY_LOW;
    SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.Mode = LL_SPI_WORK_MODE_MASTER;
    SPI_InitStruct.NSS = LL_SPI_SSN_MODE_HARDWARE;
    SPI_InitStruct.TransferMode = LL_SPI_MODE_FULL_DUPLEX ;
    LL_SPI_Init(SPI1, &SPI_InitStruct);
    
    // RX
    DMA_InitStruct.CircMode = DISABLE;
    DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_BYTE;
    DMA_InitStruct.Direction = LL_DMA_DIR_PERIPHERAL_TO_RAM;
    DMA_InitStruct.MemoryAddressIncMode = LL_DMA_INCREMENTAL_INCREASE;
    DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;
    DMA_InitStruct.PeriphAddress = LL_DMA_PERIPHERAL_FUNCTION1;
    LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_3);
    
    // TX
    DMA_InitStruct.CircMode = DISABLE;
    DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_BYTE;
    DMA_InitStruct.Direction = LL_DMA_DIR_RAM_TO_PERIPHERAL;
    DMA_InitStruct.MemoryAddressIncMode = LL_DMA_INCREMENTAL_INCREASE;
    DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;
    DMA_InitStruct.PeriphAddress = LL_DMA_PERIPHERAL_FUNCTION2;
    LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_4);
    
    LL_DMA_Enable_DMA(DMA);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 |
        LL_GPIO_PIN_11;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = ENABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void SpiWriteDataDMA(uint32_t dataAddr, uint16_t length)
{
    LL_SPI_TxBuffClear(SPI1);
    
    LL_DMA_SetTransmissionSize(DMA, length - 1, LL_DMA_CHANNEL_4);
    LL_DMA_SetChannelMemAddr(DMA, dataAddr, LL_DMA_CHANNEL_4);
    
    LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_4);
    LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_4);
}

void SpiReadDataDMA(uint32_t dataAddr, uint16_t length)
{
    LL_SPI_RxBuffClear(SPI1);
    
    LL_DMA_SetTransmissionSize(DMA, length - 1, LL_DMA_CHANNEL_3);
    LL_DMA_SetChannelMemAddr(DMA, dataAddr, LL_DMA_CHANNEL_3);
    
    LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_3);
    LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_3);
}

bool SpiWriteDataComplete(void)
{
    if (LL_DMA_IsActiveFlag_Finished(DMA, LL_DMA_CHANNEL_4))
    {
        return true;
    }
    return false;
}

bool SpiReadDataComplete(void)
{
    if (LL_DMA_IsActiveFlag_Finished(DMA, LL_DMA_CHANNEL_3))
    {
        return true;
    }
    return false;
}
