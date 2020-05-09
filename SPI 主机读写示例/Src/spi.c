#include "spi.h"

#define SPI1_1
//#define SPI1_2
//#define SPI2_1

#if ((defined SPI1_1) || (defined SPI1_2))
void SpiInit(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_SPI_InitTypeDef SPI_InitStruct = {0};
    
    SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2;
    SPI_InitStruct.BitOrder = LL_SPI_BIT_ORDER_MSB_FIRST;
    SPI_InitStruct.ClockPhase = LL_SPI_SPI_PHASE_1EDGE;
    SPI_InitStruct.ClockPolarity = LL_SPI_SPI_POLARITY_LOW;
    SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.Mode = LL_SPI_WORK_MODE_MASTER;
    SPI_InitStruct.NSS = LL_SPI_SSN_MODE_SOFTWARE;
    SPI_InitStruct.TransferMode = LL_SPI_MODE_FULL_DUPLEX;
    LL_SPI_Init(SPI1, &SPI_InitStruct);
    
    LL_SPI_TxBuffClear(SPI1);
    LL_SPI_RxBuffClear(SPI1);
    
#if (defined SPI1_1)
    GPIO_InitStruct.Pin = LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 |
        LL_GPIO_PIN_11;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = ENABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
#else
    GPIO_InitStruct.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | LL_GPIO_PIN_4 |
        LL_GPIO_PIN_5;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = ENABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    
    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
#endif
}

uint32_t SpiWriteAndRead(uint32_t data)
{
    LL_SPI_ResetSSNPin(SPI1);
    
    LL_SPI_WriteTxBuff(SPI1, data);
    while (!(LL_SPI_IsActiveFlag_TxBufffEmpty(SPI1)));
    while (!(LL_SPI_IsActiveFlag_RxBufffFull(SPI1)));
    data = LL_SPI_ReadRxBuff(SPI1);
    
    LL_SPI_SetSSNPin(SPI1);
    return data;
}

void SpiWriteData(uint8_t *data, uint16_t length)
{
    LL_SPI_ResetSSNPin(SPI1);
    while (length--)
    {
        LL_SPI_WriteTxBuff(SPI1, *data); data++;
        while (!(LL_SPI_IsActiveFlag_TxBufffEmpty(SPI1)));
    }
    while (!(LL_SPI_IsActiveFlag_RxBufffFull(SPI1)));
    LL_SPI_SetSSNPin(SPI1);
}

void SpiReadData(uint8_t *data, uint16_t length)
{
    LL_SPI_ResetSSNPin(SPI1);
    while (length--)
    {
        LL_SPI_WriteTxBuff(SPI1, 0x55);
        while (!(LL_SPI_IsActiveFlag_RxBufffFull(SPI1)));
        *data = LL_SPI_ReadRxBuff(SPI1); data++;
    }
    LL_SPI_SetSSNPin(SPI1);
}
#else
void SpiInit(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_SPI_InitTypeDef SPI_InitStruct = {0};
    
    SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2;
    SPI_InitStruct.BitOrder = LL_SPI_BIT_ORDER_MSB_FIRST;
    SPI_InitStruct.ClockPhase = LL_SPI_SPI_PHASE_1EDGE;
    SPI_InitStruct.ClockPolarity = LL_SPI_SPI_POLARITY_LOW;
    SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.Mode = LL_SPI_WORK_MODE_MASTER;
    SPI_InitStruct.NSS = LL_SPI_SSN_MODE_SOFTWARE;
    SPI_InitStruct.TransferMode = LL_SPI_MODE_FULL_DUPLEX;
    LL_SPI_Init(SPI2, &SPI_InitStruct);
    
    LL_SPI_TxBuffClear(SPI2);
    LL_SPI_RxBuffClear(SPI2);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_7 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9 |
        LL_GPIO_PIN_10;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = ENABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

uint32_t SpiWriteAndRead(uint32_t data)
{
    LL_SPI_ResetSSNPin(SPI2);
    
    LL_SPI_WriteTxBuff(SPI2, data);
    while (!(LL_SPI_IsActiveFlag_TxBufffEmpty(SPI2)));
    while (!(LL_SPI_IsActiveFlag_RxBufffFull(SPI2)));
    data = LL_SPI_ReadRxBuff(SPI2);
    
    LL_SPI_SetSSNPin(SPI2);
    return data;
}

void SpiWriteData(uint8_t *data, uint16_t length)
{
    LL_SPI_ResetSSNPin(SPI2);
    while (length--)
    {
        LL_SPI_WriteTxBuff(SPI2, *data); data++;
        while (!(LL_SPI_IsActiveFlag_TxBufffEmpty(SPI2)));
    }
    LL_SPI_SetSSNPin(SPI2);
}

void SpiReadData(uint8_t *data, uint16_t length)
{
    LL_SPI_ResetSSNPin(SPI2);
    while (length--)
    {
        LL_SPI_WriteTxBuff(SPI1, 0x00);
        while (!(LL_SPI_IsActiveFlag_RxBufffFull(SPI2)));
        *data = LL_SPI_ReadRxBuff(SPI2); data++;
    }
    LL_SPI_SetSSNPin(SPI2);
}
#endif
