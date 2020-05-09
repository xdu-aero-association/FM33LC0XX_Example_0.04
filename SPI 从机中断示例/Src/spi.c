#include <stdbool.h>
#include <string.h>
#include "spi.h"

#define LENGTH      16

typedef struct {
    uint8_t buffer[LENGTH];
    uint16_t index;
    uint16_t length;
}DATA;

DATA rData;
DATA wData;

bool isBusy = false;

void SpiInit(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_SPI_InitTypeDef SPI_InitStruct = {0};
    
    SPI_InitStruct.BitOrder = LL_SPI_BIT_ORDER_MSB_FIRST;
    SPI_InitStruct.ClockPhase = LL_SPI_SPI_PHASE_1EDGE;
    SPI_InitStruct.ClockPolarity = LL_SPI_SPI_POLARITY_LOW;
    SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.Mode = LL_SPI_WORK_MODE_SLAVE;
    SPI_InitStruct.TransferMode = LL_SPI_MODE_FULL_DUPLEX ;
    LL_SPI_Init(SPI1, &SPI_InitStruct);
    
    LL_SPI_EnabledIT_Receivecomplete(SPI1);
    LL_SPI_EnabledIT_Transmitcomplete(SPI1);
    
    NVIC_DisableIRQ(SPI1_IRQn);
    NVIC_SetPriority(SPI1_IRQn, 0);
    NVIC_EnableIRQ(SPI1_IRQn);
    
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
}

void SPI1_IRQHandler(void)
{
    if ((LL_SPI_IsEnabledIT_Receivecomplete(SPI1)) &&
        (LL_SPI_IsActiveFlag_RxBufffFull(SPI1)))
    {
        if ((rData.length == LENGTH) || 
            (isBusy == true))
        {
            SPI1->RXBUF;
        }
        else
        {
            rData.buffer[rData.index++] = SPI1->RXBUF;
            rData.length++;
        }
    }
    
    if ((LL_SPI_IsEnabledIT_Transmitcomplete(SPI1)) &&
        (LL_SPI_IsActiveFlag_TxBufffEmpty(SPI1)))
    {
        if ((wData.length == 0) || 
            (isBusy == true))
        {
            SPI1->TXBUF = 0xAA;
        }
        else
        {
            SPI1->TXBUF = wData.buffer[wData.index++];
            wData.length--;
        }
    }
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
                memcpy(wData.buffer, rData.buffer, rData.length);
                wData.index = 0; wData.length = rData.length;
                rData.index = 0; rData.length = 0;
                
                isBusy = false;
                LL_SPI_RxBuffClear(SPI1);
                LL_SPI_TxBuffClear(SPI1);
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
