#include "spi.h"

uint8_t *wData, *rData;
uint16_t wLength, rLength;

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
    SPI_InitStruct.TransferMode = LL_SPI_MODE_FULL_DUPLEX ;
    LL_SPI_Init(SPI1, &SPI_InitStruct);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 |
        LL_GPIO_PIN_11;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = ENABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    NVIC_DisableIRQ(SPI1_IRQn);
    NVIC_SetPriority(SPI1_IRQn, 2);
    NVIC_EnableIRQ(SPI1_IRQn);
}

void SpiWriteDataIRQ(uint8_t *data, uint16_t length)
{
    wData = data; wLength = length;
    LL_SPI_TxBuffClear(SPI1);
    LL_SPI_ResetSSNPin(SPI1);
    LL_SPI_EnabledIT_Transmitcomplete(SPI1);
}

void SpiReadDataIRQ(uint8_t *data, uint16_t length)
{
    rData = data; rLength = length - 1;
    LL_SPI_RxBuffClear(SPI1);
    LL_SPI_ResetSSNPin(SPI1);
    LL_SPI_EnabledIT_Receivecomplete(SPI1);
    LL_SPI_WriteTxBuff(SPI1, 0xAA);
}

bool SpiWriteIsComplete(void)
{
    if (wLength == 0)
    {
        return true;
    }
    return false;
}

bool SpiReadIsComplete(void)
{
    if (rLength == 0)
    {
        return true;
    }
    return false;
}

void SPI1_IRQHandler(void)
{
    if ((LL_SPI_IsEnabledIT_Receivecomplete(SPI1)) &&
        (LL_SPI_IsActiveFlag_RxBufffFull(SPI1)))
    {
        if (rLength == 0)
        {
            *rData = LL_SPI_ReadRxBuff(SPI1);
            LL_SPI_DisableIT_Receivecomplete(SPI1);
            LL_SPI_SetSSNPin(SPI1);
        }
        else
        {
            rLength--;
            *rData = LL_SPI_ReadRxBuff(SPI1);
            LL_SPI_WriteTxBuff(SPI1, 0x55);
            rData++;
        }
    }
    
    if ((LL_SPI_IsEnabledIT_Transmitcomplete(SPI1)) &&
        (LL_SPI_IsActiveFlag_TxBufffEmpty(SPI1)))
    {
        if (wLength == 0)
        {
            LL_SPI_DisableIT_Transmitcomplete(SPI1);
            while (!LL_SPI_IsActiveFlag_RxBufffFull(SPI1));
            LL_SPI_SetSSNPin(SPI1);
        }
        else
        {
            wLength--;
            LL_SPI_ReadRxBuff(SPI1);
            LL_SPI_WriteTxBuff(SPI1, *wData);
            wData++;
        }
    }
}
