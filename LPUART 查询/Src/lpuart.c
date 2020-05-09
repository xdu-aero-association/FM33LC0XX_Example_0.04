#include "lpuart.h"
#include "main.h"

void LPUART_Init(LPUART_Type* LPUARTx)
{
    LL_LPUART_InitTypeDef  InitStructer;
    LL_GPIO_InitTypeDef  GPIO_InitStruct = {0};
    volatile uint8_t tmp08;
      
    if(LPUARTx==LPUART0)
    {
        GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = ENABLE;
        GPIO_InitStruct.RemapPin = ENABLE;      
        LL_GPIO_Init(GPIOA,&GPIO_InitStruct);
        
        GPIO_InitStruct.Pin = LL_GPIO_PIN_14;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = DISABLE;
        GPIO_InitStruct.RemapPin = ENABLE;
        LL_GPIO_Init(GPIOA,&GPIO_InitStruct);
    }
    else
    {
        GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = ENABLE;
        GPIO_InitStruct.RemapPin = ENABLE;     
        LL_GPIO_Init(GPIOB,&GPIO_InitStruct);
      
        GPIO_InitStruct.Pin = LL_GPIO_PIN_14;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = DISABLE;
        GPIO_InitStruct.RemapPin = ENABLE;      
        LL_GPIO_Init(GPIOB,&GPIO_InitStruct);
    }
    
    InitStructer.BaudRate            = LL_LPUART_BAUDRATE_9600;
	  InitStructer.DataWidth           = LL_LPUART_DATAWIDTH_8B;
	  InitStructer.StopBits            = LL_LPUART_STOP_1BITS;
	  InitStructer.Parity              = LL_LPUART_PARITY_EVEN ;
	  InitStructer.TransferDirection   = LL_LPUART_DIRECTION_TX_RX;
    LL_LPUART_Init(LPUARTx,&InitStructer);     
    
}

void LPUART_Test(LPUART_Type* LPUARTx)
{
    uint8_t TestTxData[12] = {0x55,0x5A,0x53};
    uint8_t i;
	  volatile uint8_t tmp;
    
    
    for(i=0; i<3; i++)
	  {
      LL_LPUART_TransmitData(LPUARTx,TestTxData[i]);//将发送数据写入发送寄存器
      while(LL_LPUART_IsActiveFlag_TXSE(LPUARTx)==0);//等待发送完成
      LL_LPUART_ClearFlag_TXSE(LPUARTx);
	  }  
 
    while(1)
	  {
		  if(LL_LPUART_IsActiveFlag_RXBF(LPUARTx))		//等待接收到一个字节
		  { 
			  tmp = LL_LPUART_ReceiveData(LPUARTx);		//LPUART接收数据
        LL_LPUART_ClearFlag_RXBF(LPUARTx);    
		  } 
	  }   
}
