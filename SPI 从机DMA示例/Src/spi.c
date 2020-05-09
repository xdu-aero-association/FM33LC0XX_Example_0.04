#include "spi.h"

#include <stdbool.h>
#include <string.h>
#include "spi.h"

#define LENGTH      16
uint8_t rData[LENGTH];
uint8_t wData[LENGTH];

bool isBusy = false;

static void SpiDmaReady(uint32_t wAddr, uint32_t rAddr, uint16_t length)
{
    LL_DMA_Disable_Channel(DMA, LL_DMA_CHANNEL_3);
    LL_DMA_Disable_Channel(DMA, LL_DMA_CHANNEL_4);
    
    LL_DMA_SetTransmissionSize(DMA, length - 1, LL_DMA_CHANNEL_4);
    LL_DMA_SetChannelMemAddr(DMA, wAddr, LL_DMA_CHANNEL_4);
    LL_DMA_SetTransmissionSize(DMA, length - 1, LL_DMA_CHANNEL_3);
    LL_DMA_SetChannelMemAddr(DMA, rAddr, LL_DMA_CHANNEL_3);
    
    LL_SPI_TxBuffClear(SPI1);
    LL_SPI_RxBuffClear(SPI1);
    
    LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_4);
    LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_3);
}

void SpiInit(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_SPI_InitTypeDef SPI_InitStruct = {0};
    LL_DMA_InitTypeDef DMA_InitStruct = {0};
    
    SPI_InitStruct.BitOrder = LL_SPI_BIT_ORDER_MSB_FIRST;
    SPI_InitStruct.ClockPhase = LL_SPI_SPI_PHASE_1EDGE;
    SPI_InitStruct.ClockPolarity = LL_SPI_SPI_POLARITY_LOW;
    SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.Mode = LL_SPI_WORK_MODE_SLAVE;
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
    
    LL_RCC_SetEXTIClockSource(
        LL_RCC_EXTERNAL_INTERRUPT_SAMPLING_CLOCK_SELECT_HCLK);
    LL_RCC_Group1_EnableOperationClock(LL_RCC_OPERATION1_CLOCK_EXTI);
    LL_GPIO_SetExitLine6(GPIO_COMMON, LL_GPIO_EXTI_LINE_6_PB8);
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_6);
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_6);
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_6, 
        LL_GPIO_EXTI_TRIGGER_BOTHEDGE);
    
    NVIC_DisableIRQ(GPIO_IRQn);
    NVIC_SetPriority(GPIO_IRQn, 2);
    NVIC_EnableIRQ(GPIO_IRQn);
    
    SpiDmaReady((uint32_t)wData, (uint32_t)rData, LENGTH);
}

void GPIO_IRQHandler(void)
{
    if ((LL_EXTI_GetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_6) != 
        LL_GPIO_EXTI_TRIGGER_NONE) && 
        (LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_6)))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_6);
        if (LL_EXTI_IsEXTILineSet(GPIO_COMMON, LL_GPIO_EXTI_LINE_6))
        {
            // SSN HIGH
            if (isBusy == false)
            {
                isBusy = true;
                memcpy(wData, rData, LENGTH);
                
                isBusy = false;
                SpiDmaReady((uint32_t)wData, (uint32_t)rData, LENGTH);
            }
        }
        else
        {
            // SSN LOW
            if (isBusy == false)
            {
                
            }
        }
    }
}

