#include "lpuart.h"
#include "main.h"
#include "user_init.h"

LPUARTOpTypeDef LPUARTOp;

uint8_t TestTxData[12] = {0x61,0x35,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0x11,0x12};

void LPUART0_IRQHandler(void)
{
	uint8_t temp;
	
	//接收中断处理
	if((ENABLE == LL_LPUART_IsEnabledIT_RXBF(LPUART0))
		&&(SET == LL_LPUART_IsActiveFlag_RXBF(LPUART0)))//接收数据匹配中断
	{
		temp = LL_LPUART_ReceiveData(LPUART0);   
	}
	
	//发送中断处理
	if((ENABLE == LL_LPUART_IsEnabledIT_TXSE(LPUART0))
		&&(SET == LL_LPUART_IsActiveFlag_TXSE(LPUART0)))
	{
		//清除发送中断标志
    LL_LPUART_ClearFlag_TXSE(LPUART0);
    
    //发送指定长度的数据
		if(LPUARTOp.TxOpc < LPUARTOp.TxLen)
		{
			LL_LPUART_TransmitData(LPUART0,LPUARTOp.TxBuf[LPUARTOp.TxOpc]); //发送一个数据
		}
	
    LPUARTOp.TxOpc++;
	}
}

void LPUART1_IRQHandler(void)
{
	uint8_t temp;
	
	//接收中断处理
	if((ENABLE == LL_LPUART_IsEnabledIT_RXBF(LPUART1))
		&&(SET == LL_LPUART_IsActiveFlag_RXBF(LPUART1)))//接收数据匹配中断
	{
		temp = LL_LPUART_ReceiveData(LPUART1);   
	}
	
	//发送中断处理
	if((ENABLE == LL_LPUART_IsEnabledIT_TXSE(LPUART1))
		&&(SET == LL_LPUART_IsActiveFlag_TXSE(LPUART1)))
	{
		//发送指定长度的数据
		if(LPUARTOp.TxOpc < LPUARTOp.TxLen)
		{
			LL_LPUART_TransmitData(LPUART1,LPUARTOp.TxBuf[LPUARTOp.TxOpc]); //发送一个数据
		}
		//清除发送中断标志
    LL_LPUART_ClearFlag_TXSE(LPUART1);
    LPUARTOp.TxOpc++;
	}
}

void LPUART_Init(LPUART_Type* LPUARTx)
{
    LL_LPUART_InitTypeDef  InitStructer;
    LL_GPIO_InitTypeDef  GPIO_InitStruct = {0};
    volatile uint8_t tmp08;
      
    if(LPUARTx==LPUART0)
    {
        GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;              //数字功能
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;     //推挽输出
        GPIO_InitStruct.Pull = ENABLE;                            //接收使能上拉
        GPIO_InitStruct.RemapPin = ENABLE;                        //使能额外数字功能
        LL_GPIO_Init(GPIOA,&GPIO_InitStruct);                     //PA13
        
        GPIO_InitStruct.Pin = LL_GPIO_PIN_14;                     
        GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;               //数字功能
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;      //推挽输出
        GPIO_InitStruct.Pull = DISABLE;                            //发送不上拉
        GPIO_InitStruct.RemapPin = ENABLE;                         //使能额外数字功能    
        LL_GPIO_Init(GPIOA,&GPIO_InitStruct);                      //PA14
    }
    if(LPUARTx==LPUART1)
    {
        GPIO_InitStruct.Pin = LL_GPIO_PIN_13;                           
        GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;                //数字功能
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;       //推挽输出
        GPIO_InitStruct.Pull = ENABLE;                              //接收使能上拉
        GPIO_InitStruct.RemapPin = ENABLE;                          //使能额外数字功能  
        LL_GPIO_Init(GPIOB,&GPIO_InitStruct);                       //PB13
      
        GPIO_InitStruct.Pin = LL_GPIO_PIN_14;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;                //数字功能
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;       //推挽输出
        GPIO_InitStruct.Pull = DISABLE;                             //发送不上拉
        GPIO_InitStruct.RemapPin = ENABLE;                          //使能额外数字功能  
        LL_GPIO_Init(GPIOB,&GPIO_InitStruct);                       //PB14
    }
    
    InitStructer.BaudRate            = LL_LPUART_BAUDRATE_9600;  //波特率9600
	  InitStructer.DataWidth           = LL_LPUART_DATAWIDTH_8B;   //8位数据位
	  InitStructer.StopBits            = LL_LPUART_STOP_1BITS;     //1位停止位
	  InitStructer.Parity              = LL_LPUART_PARITY_EVEN ;   //偶校验
	  InitStructer.TransferDirection   = LL_LPUART_DIRECTION_TX_RX;   //使能发送和接收
    LL_LPUART_Init(LPUARTx,&InitStructer);     
}

void LPUART_Test(LPUART_Type* LPUARTx)
{       
    if(LPUARTx==LPUART0)
    {
      NVIC_DisableIRQ(LPUART0_IRQn);
      NVIC_SetPriority(LPUART0_IRQn,2);//中断优先级配置
      NVIC_EnableIRQ(LPUART0_IRQn);     //使能NVIC
    }
    if(LPUARTx==LPUART1)
    {
      NVIC_DisableIRQ(LPUART1_IRQn);
      NVIC_SetPriority(LPUART1_IRQn,2);//中断优先级配置
      NVIC_EnableIRQ(LPUART1_IRQn);     //使能NVIC
    }
    
    LL_LPUART_SetDataRecvedWakeupMode(LPUARTx,LL_LPUART_WAKE_UP_AFTER_CHECK);//接收中断加校验
    
    LPUARTOp.TxBuf = TestTxData;    //发送数据
    LPUARTOp.TxLen = 12;            //发送长度
    LPUARTOp.TxOpc = 0 + 1;         //准备发送的序号
    
    LL_LPUART_ClearFlag_TXSE(LPUARTx);   //清除发送中断标志  
    LL_LPUART_EnabledIT_TXSE(LPUARTx);   //发送寄存器空且移位寄存器空中断使能
    LL_LPUART_TransmitData(LPUARTx,LPUARTOp.TxBuf[0]); //启动第一个数据的发送
    
    DelayMs(100);
    
    LL_LPUART_DisableIT_TXSE(LPUARTx);   //禁止发送中断
    LL_LPUART_EnabledIT_RXBF(LPUARTx);   //使能接收中断
}
