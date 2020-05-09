#include "main.h"
#include "u7816.h"
#include "user_init.h"

void U7816_Init(void)
{
    LL_U7816_InitTypeDef   U7816_InitStruct;
    
    LL_GPIO_InitTypeDef    GPIO_InitStruct;
      
    GPIO_InitStruct.Pin = LL_GPIO_PIN_11|LL_GPIO_PIN_12;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    LL_GPIO_Init(GPIOC,&GPIO_InitStruct);    //PC11、PC12 配置为数字功能
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    LL_GPIO_Init(GPIOC,&GPIO_InitStruct);   //PC10配置为GPIO输出功能，用于输出RST信号
  
    U7816_InitStruct.Baud                  = 372-1;                                    //372个ETU组成通信波特率
    U7816_InitStruct.BlockGuard            = DISABLE;                                //接收和发送之间不插入BGT
    U7816_InitStruct.StrongPullUp          = ENABLE;                                 //通道强上拉使能
    U7816_InitStruct.ErrorGuardTime        = LL_U7816_ERROR_GUARD_TIME_X1_ETU;       //ERROR SIGNAL后GUARDTIME为1~1.5ETU
    U7816_InitStruct.ErrorSignalTime       = LL_U7816_ERROR_SIGNAL_WIDTH_X2_ETU;     //ERROR SIGNAL宽度为2ETU
    U7816_InitStruct.ExtraGuardTime        = 0;                                      //发送时插入的额外保护时间为0
    U7816_InitStruct.OutputClockFreqence   = 4000000;                                 //U7816工作时钟           
    U7816_InitStruct.RxAutoErrorSignal     = LL_U7816_AUTO_RESPOND_ERR_SIG_ENABLE;   //接收数据奇偶校验错误回发ERROR SIGNAL
    U7816_InitStruct.Parity                = LL_U7816_PARITY_EVEN;                   //偶校验
    U7816_InitStruct.TxAutoRetry           = LL_U7816_AUTO_RETRY_ENABLE;             //发送数据奇偶校验错误自动回发
    U7816_InitStruct.RetryCnt              = LL_U7816_RETRY_CNT_X1;                  //自动重发次数1次
    U7816_InitStruct.RxGuardTime           = LL_U7816_GUARD_TIME_RX_X2_ETU;          //发送2个GUARD TIME
    U7816_InitStruct.TxGuardTime           = LL_U7816_GUARD_TIME_TX_X2_ETU;          //接收2个GUARD TIME
    U7816_InitStruct.TransferOrder         = LL_U7816_BIT_ORDER_FIRST_LSB;           //正向编码
    LL_U7816_Init(U7816,&U7816_InitStruct);
    
    LL_U7816_EnableClkOutPut(U7816);
}

void Delay_Netu( unsigned char Num )	//Num*1etu
{
	DelayUs(93*Num);	//1etu=93us(4M),或者1etu=186us(2M)
}

//复位响应数据时间为400/f~40000/f即100us~10ms
//返回值: 1为下降沿; 0为无变化
uint8_t Judge_Edge(void)
{
	uint32_t i;

	Delay_Netu(1);

	for( i=0x00; i<100; i++ ) 	//约10ms(4M),或者20ms(2M)
	{
		if( SET == LL_U7816_IsActiveFlag_RxBusy(U7816) ) //正在接收
		{
			return 1;
		}
		Delay_Netu(1);
	}
		
	return 0;
}

//最长时间应为9600etu,目前为9600etu,1etu=93us
uint8_t Get_7816_Char( unsigned char *Data )
{
	uint32_t i;	
	
	for( i=0x00; i<10000; i++ ) 	//约900ms(4M),或者1800ms(2M)
	{
//		IWDT_Clr();
		Delay_Netu(1);
		if( SET == LL_U7816_IsActiveFlag_RxComplete(U7816) ) //RX_FLAG已经置位
		{
			*Data = LL_U7816_ReadBuff(U7816);

			return 1; //成功
		}

		if( SET == LL_U7816_IsActiveFlag_Error(U7816) ) //ERROR_FLAG已经置位
		{
		  LL_U7816_ClearFlag_TxParityError(U7816);
      LL_U7816_ClearFlag_RxParityError(U7816);
      LL_U7816_ClearFlag_RxFreamError(U7816);
      LL_U7816_ClearFlag_RxOverFlow(U7816);
			
			return 2; //error
		}
		
	}
	
	return 3;
}

uint8_t Snd_7816_Byte( unsigned char Data )
{
	uint32_t i;

	Delay_Netu(2);				//延时1个etu,保证从设备稳定工作

	LL_U7816_WriteBuff(U7816,Data);
	
	for( i=0x00; i<400; i++ ) 	//约39ms(4M),或者78ms(2M)
	{
//		IWDT_Clr();
		Delay_Netu(1);
		if( SET == LL_U7816_IsActiveFlag_TxBuffEmpty(U7816) )	//TX_FLAG置位
		{
			return 0; //成功
		}

		if( SET == LL_U7816_IsActiveFlag_Error(U7816) )	//ERROR_FLAG置位
		{
		  LL_U7816_ClearFlag_TxParityError(U7816);
      LL_U7816_ClearFlag_RxParityError(U7816);
      LL_U7816_ClearFlag_RxFreamError(U7816);
      LL_U7816_ClearFlag_RxOverFlow(U7816);
			
			return 1; //error
		}
	}
	
	return 1;
}

//触点激活&冷复位
//检测到卡插入后, RST置低电平, VCC上电, 延时一段时间, IO设置为输入态, CLK输出时钟信号(T0时刻)
//在T0后40000~45000个CLK内, 将RST置为高电平(T1时刻), 在T1后的400~40000个CLK内, 复位应答应该开始, 
//若IC卡的复位应答没有在此时间段内开始, 终端将启动释放时序.若收到复位应答, 但不符合协议规范, 则需要热复位
uint8_t ColdReset(void)
{
	uint8_t n, Result, Temp_ATR;	// T0, TD1, TD2;
	uint8_t CardRst8B[13]			;	//CARD复位信息中后13字节
	
	DelayMs(100);//延时100ms
  
  LL_U7816_EnableTx(U7816);
	LL_U7816_EnableRx(U7816);
	LL_U7816_EnableClkOutPut(U7816);
	//----------------------------------------------------------------------------------------------
	Result = LL_U7816_ReadBuff(U7816); //RX启动后, 会产生rx_flag=1, 必须通过读取RXBUF来清除此标志.

	LL_U7816_ClearFlag_TxParityError(U7816);
  LL_U7816_ClearFlag_RxParityError(U7816);
  LL_U7816_ClearFlag_RxFreamError(U7816);
  LL_U7816_ClearFlag_RxOverFlow(U7816);

	LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_10);		//RST输出低电平
	//RST时间保持在40000~45000个CLK;4M频率下应该保持不少于10ms;
	DelayMs(11);//等待RST时间,至少400周期,即100us
	//-------- T1时刻, RST输出高电平 --------
	LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_10);		
	//卡复位完成后才能启动接收,之前IO电平不稳定,
  
	//复位拉起后400~40000个CLK内有ATR返回
	Result = Judge_Edge(); 		//40000个CLK内查看IO口的电平沿变化
	if( Result == 0 ) //IO口没有出现下降沿
	{
		return 2;	//异常: 40000个CLK中没有收到起始位
	}
	
	for(n=0; n<13; n++)
	{
		Result = Get_7816_Char(&Temp_ATR ); //receive TS.
		if( Result != 1 )
		{ 
			return 3; 
		}
		CardRst8B[ n ] = Temp_ATR;
	}
	
	if(CardRst8B[0] != 0x3b)
	{
		return 3; 
	}
	
	return 0;
}
