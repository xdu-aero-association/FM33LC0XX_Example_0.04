#include "spi.h"

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
    SPI_InitStruct.TransferMode = LL_SPI_MODE_SIMPLEX;
    SPI_InitStruct.TransferDirection = LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_TX;
    LL_SPI_Init(SPI1, &SPI_InitStruct);
    
    LL_SPI_SetDummyCycle(SPI1, LL_SPI_DUMMY_CYCLE_ENABLE);
    LL_SPI_TxBuffClear(SPI1);
    LL_SPI_RxBuffClear(SPI1);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 |
        LL_GPIO_PIN_11;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    LL_SPI_ResetSSNPin(SPI1);
    LL_SPI_SetTransferDirection(SPI1, LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_RX);
    LL_SPI_SetTransferDirection(SPI1, LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_TX);
    LL_SPI_SetSSNPin(SPI1);
}

void SpiData8Bit(void)
{
    while (LL_SPI_IsActiveFlag_SPIBusy(SPI1));
    LL_SPI_Disable(SPI1);
    LL_SPI_SetDataWidth(SPI1, LL_SPI_DATAWIDTH_8BIT);
    LL_SPI_Enable(SPI1);
}

void SpiData16Bit(void)
{
    while (LL_SPI_IsActiveFlag_SPIBusy(SPI1));
    LL_SPI_Disable(SPI1);
    LL_SPI_SetDataWidth(SPI1, LL_SPI_DATAWIDTH_16BIT);
    LL_SPI_Enable(SPI1);
}

void SpiWriteCmd(uint8_t cmd)
{
    LL_SPI_SetDataOrCmdMode(SPI1, LL_SPI_HALFDUPLE_DCN_CMD);
    LL_SPI_ResetSSNPin(SPI1);
    LL_SPI_WriteTxBuff(SPI1, cmd);
    while (!LL_SPI_IsActiveFlag_TxBufffEmpty(SPI1));
    LL_SPI_SetSSNPin(SPI1);
}

void SpiWriteData(uint32_t data)
{
    LL_SPI_ResetSSNPin(SPI1);
    LL_SPI_WriteTxBuff(SPI1, data);
    while (!LL_SPI_IsActiveFlag_TxBufffEmpty(SPI1));
    LL_SPI_SetSSNPin(SPI1);
}

void SpiReadData(uint8_t cmd, uint8_t *data, uint16_t length)
{ 
    LL_SPI_ResetSSNPin(SPI1);
    
    LL_SPI_SetTransferDirection(SPI1, LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_RX);
    
    LL_SPI_SetDataOrCmdMode(SPI1, LL_SPI_HALFDUPLE_DCN_CMD);
    LL_SPI_WriteTxBuff(SPI1, cmd);
    while (!LL_SPI_IsActiveFlag_TxBufffEmpty(SPI1));
    
    LL_SPI_ReadRxBuff(SPI1);
    while (--length)
    {
        while (!LL_SPI_IsActiveFlag_RxBufffFull(SPI1));
        *data = LL_SPI_ReadRxBuff(SPI1); data++;
    }
    
    LL_SPI_SetTransferDirection(SPI1, LL_SPI_SIMPLEX_DIRECTION_HALF_DUPLEX_TX);
    
    LL_SPI_SetSSNPin(SPI1);
}
