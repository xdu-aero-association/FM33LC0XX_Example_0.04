#include "crc.h"

uint16_t CRC16_CCITT(uint8_t *data, uint32_t length)
{
    LL_CRC_InitTypeDef CRC_InitStruct;
    LL_DMA_InitTypeDef DMA_InitStruct;

    DMA_InitStruct.CircMode = DISABLE;
    DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_BYTE;
    DMA_InitStruct.Direction = LL_DMA_DIR_RAM_TO_PERIPHERAL;
    DMA_InitStruct.MemoryAddressIncMode = LL_DMA_INCREMENTAL_INCREASE;
    DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;
    DMA_InitStruct.PeriphAddress = LL_DMA_PERIPHERAL_FUNCTION5;
    DMA_InitStruct.MemoryAddress = (uint32_t)data;
    DMA_InitStruct.NbData = length - 1;
    LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_0);
    
    LL_DMA_Enable_DMA(DMA);
    
    CRC_InitStruct.CalculatMode = LL_CRC_CALCULA_MODE_SERIAL;
    CRC_InitStruct.DataWidth = LL_CRC_CRC_DR_WIDTH_BYTE;
    CRC_InitStruct.InitVel = 0x0000;
    CRC_InitStruct.Polynomial = 0x1021;
    CRC_InitStruct.PolynomialWidth = LL_CRC_POLYNOMIAL_WIDTH_16BIT;
    CRC_InitStruct.ReflectIn = LL_CRC_INPUT_REFLECTE_MODE_BYTE;
    CRC_InitStruct.ReflectOut = LL_CRC_OUPUT_REFLECTE_MODE_REVERSE;
    CRC_InitStruct.XorReg = 0x0000;
    CRC_InitStruct.XorRegState = DISABLE;
    LL_CRC_Init(CRC, &CRC_InitStruct);

    LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_0);
    LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_0);
    while (!LL_DMA_IsActiveFlag_Finished(DMA, LL_DMA_CHANNEL_0));
    LL_DMA_Disable_DMA(DMA);
    
    return LL_CRC_GetDataReg(CRC) & 0xffff;
}

uint16_t CRC16_CCITT_WORD(uint32_t *data, uint32_t length)
{
    LL_CRC_InitTypeDef CRC_InitStruct;
    LL_DMA_InitTypeDef DMA_InitStruct;
    
    DMA_InitStruct.CircMode = DISABLE;
    DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_WORD;
    DMA_InitStruct.Direction = LL_DMA_DIR_RAM_TO_PERIPHERAL;
    DMA_InitStruct.MemoryAddressIncMode = LL_DMA_INCREMENTAL_INCREASE;
    DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;
    DMA_InitStruct.PeriphAddress = LL_DMA_PERIPHERAL_FUNCTION5;
    DMA_InitStruct.MemoryAddress = (uint32_t)data;
    DMA_InitStruct.NbData = length - 1;
    LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_0);
    
    LL_DMA_Enable_DMA(DMA);
    
    CRC_InitStruct.CalculatMode = LL_CRC_CALCULA_MODE_SERIAL;
    CRC_InitStruct.DataWidth = LL_CRC_CRC_DR_WIDTH_WORD;
    CRC_InitStruct.InitVel = 0x0000;
    CRC_InitStruct.Polynomial = 0x1021;
    CRC_InitStruct.PolynomialWidth = LL_CRC_POLYNOMIAL_WIDTH_16BIT;
    CRC_InitStruct.ReflectIn = LL_CRC_INPUT_REFLECTE_MODE_WORD;
    CRC_InitStruct.ReflectOut = LL_CRC_OUPUT_REFLECTE_MODE_REVERSE;
    CRC_InitStruct.XorReg = 0x0000;
    CRC_InitStruct.XorRegState = DISABLE;
    LL_CRC_Init(CRC, &CRC_InitStruct);

    LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_0);
    LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_0);
    while (!LL_DMA_IsActiveFlag_Finished(DMA, LL_DMA_CHANNEL_0));
    LL_DMA_Disable_DMA(DMA);
    
    return LL_CRC_GetDataReg(CRC) & 0xffff;
}
