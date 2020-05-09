#include "TestUart.h"


void UART_DMA(uint8_t *buffer, uint32_t length,UART_Type* UARTx)
{
    LL_DMA_InitTypeDef DMA_InitStruct={0};
		
	switch((uint32_t)UARTx)
	{
		case UART0_BASE:
				DMA_InitStruct.PeriphAddress = LL_DMA_PERIPHERAL_FUNCTION2;	
				DMA_InitStruct.MemoryAddress = (uint32_t)buffer;		
				DMA_InitStruct.Direction = LL_DMA_DIR_RAM_TO_PERIPHERAL;	
				DMA_InitStruct.MemoryAddressIncMode = LL_DMA_INCREMENTAL_INCREASE;	
				DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_BYTE;
				DMA_InitStruct.NbData = length - 1;	
				DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;		
				DMA_InitStruct.CircMode = DISABLE;
				LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_2);		
						
				LL_DMA_Enable_DMA(DMA);     
				LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_2);
				LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_2);
			break;
		
		case UART1_BASE:
				DMA_InitStruct.PeriphAddress = LL_DMA_PERIPHERAL_FUNCTION5;	
				DMA_InitStruct.MemoryAddress = (uint32_t)buffer;		
				DMA_InitStruct.Direction = LL_DMA_DIR_RAM_TO_PERIPHERAL;	
				DMA_InitStruct.MemoryAddressIncMode = LL_DMA_INCREMENTAL_INCREASE;	
				DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_BYTE;
				DMA_InitStruct.NbData = length - 1;	
				DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;		
				DMA_InitStruct.CircMode = DISABLE;
				LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_4);		
						
				LL_DMA_Enable_DMA(DMA);     
				LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_4);
				LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_4);
			break;
			
		case UART4_BASE:
				DMA_InitStruct.PeriphAddress = LL_DMA_PERIPHERAL_FUNCTION4;	
				DMA_InitStruct.MemoryAddress = (uint32_t)buffer;		
				DMA_InitStruct.Direction = LL_DMA_DIR_RAM_TO_PERIPHERAL;	
				DMA_InitStruct.MemoryAddressIncMode = LL_DMA_INCREMENTAL_INCREASE;	
				DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_BYTE;
				DMA_InitStruct.NbData = length - 1;	
				DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;		
				DMA_InitStruct.CircMode = DISABLE;
				LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_3);		
						
				LL_DMA_Enable_DMA(DMA);     
				LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_3);
				LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_3);
			break;
		
		case UART5_BASE:
				DMA_InitStruct.PeriphAddress = LL_DMA_PERIPHERAL_FUNCTION4;	
				DMA_InitStruct.MemoryAddress = (uint32_t)buffer;		
				DMA_InitStruct.Direction = LL_DMA_DIR_RAM_TO_PERIPHERAL;	
				DMA_InitStruct.MemoryAddressIncMode = LL_DMA_INCREMENTAL_INCREASE;	
				DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_BYTE;
				DMA_InitStruct.NbData = length - 1;	
				DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;		
				DMA_InitStruct.CircMode = DISABLE;
				LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_6);		
						
				LL_DMA_Enable_DMA(DMA);     
				LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_6);
				LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_6);
			break;
				
		default:
			break;
    }		
      
}

void Uartx_Init(UART_Type* UARTx)
{
    
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_UART_InitTypeDef UART_InitStruct = {0};    
    
	switch((uint32_t)UARTx)
	{
		case UART0_BASE:
			//PA13:UART0-RX   PA14:UART0-TX
			GPIO_InitStruct.Pin = LL_GPIO_PIN_13|LL_GPIO_PIN_14;
			GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
			GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
			GPIO_InitStruct.Pull = DISABLE;
			GPIO_InitStruct.RemapPin = DISABLE;
			LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		
			//PA2:UART0-RX   PA3:UART0-TX
//			GPIO_InitStruct.Pin = LL_GPIO_PIN_2|LL_GPIO_PIN_3;
//			GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
//			GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
//			GPIO_InitStruct.Pull = DISABLE;
//			GPIO_InitStruct.RemapPin = DISABLE;
//			LL_GPIO_Init(GPIOA, &GPIO_InitStruct);	
		
			UART_InitStruct.ClockSrc = LL_RCC_UART_OPERATION_CLOCK_SOURCE_APBCLK1;
			break;
		
		case UART1_BASE:
			//PB13:UART1-RX   PB14:UART1-TX
			GPIO_InitStruct.Pin = LL_GPIO_PIN_13|LL_GPIO_PIN_14;
			GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
			GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
			GPIO_InitStruct.Pull = DISABLE;
			GPIO_InitStruct.RemapPin = DISABLE;			
			LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		
			//PC2:UART1-RX   PC3:UART1-TX
//			GPIO_InitStruct.Pin = LL_GPIO_PIN_2|LL_GPIO_PIN_3;
//			GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
//			GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
//			GPIO_InitStruct.Pull = DISABLE;
//			GPIO_InitStruct.RemapPin = DISABLE;
//			LL_GPIO_Init(GPIOC, &GPIO_InitStruct);	
				
			UART_InitStruct.ClockSrc = LL_RCC_UART_OPERATION_CLOCK_SOURCE_APBCLK1;
			break;
			
		case UART4_BASE:
			//PB2:UART4-RX   PB3:UART4-TX
			GPIO_InitStruct.Pin = LL_GPIO_PIN_2|LL_GPIO_PIN_3;
			GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
			GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
			GPIO_InitStruct.Pull = DISABLE;
			GPIO_InitStruct.RemapPin = DISABLE;			
			LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		
			//PA0:UART4-RX   PA1:UART4-TX
//			GPIO_InitStruct.Pin = LL_GPIO_PIN_0|LL_GPIO_PIN_1;
//			GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
//			GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
//			GPIO_InitStruct.Pull = DISABLE;
//			GPIO_InitStruct.RemapPin = DISABLE;
//			LL_GPIO_Init(GPIOA, &GPIO_InitStruct);	
			break;
		
		case UART5_BASE:
			//PD0:UART5-RX   PD1:UART5-TX
			GPIO_InitStruct.Pin = LL_GPIO_PIN_0|LL_GPIO_PIN_1;
			GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
			GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
			GPIO_InitStruct.Pull = DISABLE;
			GPIO_InitStruct.RemapPin = DISABLE;			
			LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
		
			//PC4:UART5-RX   PC5:UART5-TX
//			GPIO_InitStruct.Pin = LL_GPIO_PIN_4|LL_GPIO_PIN_5;
//			GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
//			GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
//			GPIO_InitStruct.Pull = DISABLE;
//			GPIO_InitStruct.RemapPin = DISABLE;
//			LL_GPIO_Init(GPIOC, &GPIO_InitStruct);	
			break;
				
		default:
			break;
    }
	UART_InitStruct.BaudRate = 115200;								//波特率
	UART_InitStruct.DataWidth = LL_UART_DATAWIDTH_8B;				//数据位数
	UART_InitStruct.StopBits = LL_UART_STOPBITS_1;					//停止位
	UART_InitStruct.Parity = LL_UART_PARITY_EVEN;					//奇偶校验
	UART_InitStruct.TransferDirection = LL_UART_DIRECTION_NONE;	//接收-发送不使能
	UART_InitStruct.InfraredModulation = DISABLE;			        
	LL_UART_Init(UARTx, &UART_InitStruct);
}


void Test_Uartx(UART_Type* UARTx)
{
	
	uint8_t TestTxData[11] = "TestUart-TX";

	volatile uint8_t tmp08;
	
	Uartx_Init(UARTx);//初始化uart配置
	UART_DMA(TestTxData,11,UARTx);
	LL_UART_EnableDirectionTx(UARTx);

	//UART0_LL_DMA_CHANNEL_2
	//UART1_LL_DMA_CHANNEL_4
	//UART4_LL_DMA_CHANNEL_3
	//UART5_LL_DMA_CHANNEL_6
	while (!LL_DMA_IsActiveFlag_Finished(DMA, LL_DMA_CHANNEL_2));
	LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_2);
	LL_UART_ClearFlag_TXSE(UARTx);
	
    // 等待发送完成
  while (LL_UART_IsActiveFlag_TXSE(UARTx) == RESET){};
  LL_UART_ClearFlag_TXSE(UARTx);	
	
}
