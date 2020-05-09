#include "TestI2C.h"
#include "user_init.h"
struct I2COpStruct{
	uint8_t *Buf;//数据指针
	uint8_t Len;	//数据长度
	uint8_t Opc;	//已操作数据长度
	uint8_t Opt; //操作类型
	uint8_t Ops; //操作状态 
};
struct I2COpStruct I2COp;

#define	I2CREAD		1	//I2C读操作
#define	I2CWRITE	0	//I2C写操作

#define I2COPBUSY	1	//I2C中断收发操作中
#define I2COPFINISH	0	//I2C中断收发完成

#define	STARTBIT		0	
#define	RESTARTBIT	1
#define	STOPBIT			2

#define DEVICE_FM38025T     0x64	//FM38025T的器件地址
#define ADDRLEN_FM38025T	1		//FM38025T的数据地址长度为1字节


void I2C_IRQHandler(void)
{
	static uint8_t ACKFlag;
	
	if(SET == LL_I2C_MasterMode_IsActiveFlag_TransmitCompleted(I2C))
	{
		LL_I2C_MasterMode_ClearFlag_TransmitCompleted(I2C);//清中断标志
		if(I2COp.Opt == I2CWRITE)//发送处理
		{
			if(I2COp.Opc < I2COp.Len)//数据没发完
			{
				//发送一个字节
				LL_I2C_MasterMode_WriteDataBuff(I2C,I2COp.Buf[I2COp.Opc]);//写发送缓冲寄存器
				I2COp.Opc++;
			}
			else
			{
				LL_I2C_MasterMode_DisableIT_TransmitCompleted(I2C);//关闭I2C中断
				LL_I2C_MasterMode_Enable_I2C_Stop(I2C);//发送停止位
				while(!LL_I2C_MasterMode_IsActiveFlag_Stop(I2C));
				I2COp.Ops = I2COPFINISH;//发送完成
			}
		}
	}
	
	if(SET == LL_I2C_MasterMode_IsActiveFlag_ReceiveCompleted(I2C))
	{
		LL_I2C_MasterMode_ClearFlag_ReceiveCompleted(I2C);
		if(ACKFlag==0)
		{
			if(I2COp.Opt == I2CREAD)//接收处理
			{
				
				I2COp.Buf[I2COp.Opc] = LL_I2C_MasterMode_ReadDataBuff(I2C);//读接收缓冲
				I2COp.Opc++;

				if( I2COp.Opc < (I2COp.Len-1) )
				{	
					LL_I2C_MasterMode_SetMasterRespond(I2C,LL_I2C_SSP_MASTER_RESPOND_ACK);//主机将给从机的回应为0
					LL_I2C_MasterMode_EnableReceive(I2C);//打开接收使能
				}
				else
				{
					LL_I2C_MasterMode_SetMasterRespond(I2C,LL_I2C_SSP_MASTER_RESPOND_NACK);	//主机将给从机的回应为1
					ACKFlag = 1;
					LL_I2C_MasterMode_EnableReceive(I2C);//打开接收使能
				}
					
			}
		}
		else
		{
			ACKFlag = 0;
			I2COp.Buf[I2COp.Opc] = LL_I2C_MasterMode_ReadDataBuff(I2C);///读接收缓冲
			LL_I2C_MasterMode_DisableIT_ReceiveCompleted(I2C);//关闭I2C中断
			LL_I2C_MasterMode_Enable_I2C_Stop(I2C);//发送停止位
			while(!LL_I2C_MasterMode_IsActiveFlag_Stop(I2C));
			I2COp.Ops = I2COPFINISH;//接受完成			
		}
	}
}

uint8_t I2C_Send_Bit(uint8_t BIT_def ) 
{
	
	switch(BIT_def)
	{
		case STARTBIT:
				LL_I2C_MasterMode_Enable_I2C_Start(I2C);
				while(!LL_I2C_MasterMode_IsActiveFlag_Start(I2C));
			break;
		
		case RESTARTBIT:
				LL_I2C_MasterMode_Enable_I2C_Rstart(I2C);
				while(!LL_I2C_MasterMode_IsActiveFlag_Start(I2C));		
			break;
		
		case STOPBIT:
				LL_I2C_MasterMode_Enable_I2C_Stop(I2C);
				while(!LL_I2C_MasterMode_IsActiveFlag_Stop(I2C));		
			break;
		
		default:
			break;
	}
		
	return 0; //ok

}

uint8_t I2C_Send_Byte( uint8_t x_byte ) 
{

	LL_I2C_MasterMode_WriteDataBuff(I2C,x_byte);
	
	while(!LL_I2C_MasterMode_IsActiveFlag_TransmitCompleted(I2C));
	LL_I2C_MasterMode_ClearFlag_TransmitCompleted(I2C);

	if(!LL_I2C_MasterMode_IsActiveFlag_Nack(I2C))
	{
		return 0;
	}
	else
	{
		LL_I2C_MasterMode_ClearFlag_Nack(I2C);
		return 1;
	}

}

uint8_t I2C_Receive_Byte( uint8_t *x_byte ) 
{

	//i2c en, rcen
	LL_I2C_MasterMode_EnableReceive(I2C);
  while(!LL_I2C_MasterMode_IsActiveFlag_ReceiveCompleted(I2C));
  LL_I2C_MasterMode_ClearFlag_ReceiveCompleted(I2C);
	*x_byte=LL_I2C_MasterMode_ReadDataBuff(I2C);
	return 0;
}

uint8_t Sendaddr( uint8_t Device, uint16_t Addr, uint8_t AddrLen, uint8_t Opt ) 
{
	uint8_t result, Devi_Addr;
	
	Devi_Addr = Device;


	//-------------- start bit -------------
	result = I2C_Send_Bit( STARTBIT );//发送起始位
	if( result != 0 ) return 1; //failure.
	
	//-------------- disable read -------------
	LL_I2C_MasterMode_DisableReceive(I2C);
	//-------------- device addr -------------
	result = I2C_Send_Byte( Devi_Addr ); //发送器件地址
	if( result != 0 ) return 2; //failure.

	//--------------- data addr --------------
	if(AddrLen == 2)
	{
		result = I2C_Send_Byte( Addr>>8 ); //发送数据地址高8位
		if( result != 0 ) return 3; //failure.
	}
	result = I2C_Send_Byte( Addr>>0 ); //发送数据地址低8位
	if( result != 0 ) return 3; //failure.

	if( Opt == I2CREAD ) //读操作
	{
		result = I2C_Send_Bit( RESTARTBIT ); //发送重起始位
		if( result != 0 ) return 5; //failure.
		
		result = I2C_Send_Byte( Devi_Addr|1 ); //发送器件地址,读取
		if( result != 0 ) return 5; //failure.
	}
		
	return 0; //ok
}


uint8_t Wait_for_end( uint8_t Device )
{
	uint8_t result, Devi_Addr;

	Devi_Addr = Device;
	
	Do_DelayStart(); //需要5ms的内部写周期, 循环一次所需时间: 42个Delay()。
	{
		I2C_Send_Bit( STARTBIT );	//发送起始位

		result = I2C_Send_Byte( Devi_Addr ); //发送器件地址

		I2C_Send_Bit( STOPBIT ); //发送停止位

		if( result == 0 ) return 0; //设置地址成功, 写周期结束
    
	}While_DelayMsEnd(5);

	return 1; //设置地址失败
}

uint8_t I2C_Write_Bottom_Int(uint8_t Device, uint16_t Addr, uint8_t AddrLen, uint8_t *Buf, uint8_t Len)
{
	uint8_t status;
	
	if(Len > 128) return 0xFF;//一次最多操作128字节
	
	I2COp.Buf = Buf;//数据缓冲区地址
	I2COp.Len = Len;//待发送/接收数据长度
	I2COp.Opc = 0;//已发送/接收数据长度
	I2COp.Opt = I2CWRITE;//读/写操作
	I2COp.Ops = I2COPBUSY;//操作状态
                         	
	status = 0;
	if( Sendaddr( Device, Addr, AddrLen, I2CWRITE ) ) status = 1; //写入失败
	else 
	{
		LL_I2C_MasterMode_ClearFlag_TransmitCompleted(I2C);
		LL_I2C_MasterMode_EnabledIT_TransmitCompleted(I2C);;//开启I2C中断
		//发送一个字节
		LL_I2C_MasterMode_WriteDataBuff(I2C,I2COp.Buf[I2COp.Opc]);//写发送缓冲寄存器
		I2COp.Opc++;
	}	
	return( status );
}

uint8_t I2C_Read_Bottom_Int(uint8_t Device, uint16_t Addr, uint8_t AddrLen, uint8_t *Buf, uint8_t Len)
{
	uint8_t status;
	
	if(Len > 128) return 0xFF;//一次最多操作128字节
	
	I2COp.Buf = Buf;//数据缓冲区地址
	I2COp.Len = Len;//待发送/接收数据长度
	I2COp.Opc = 0;//已发送/接收数据长度
	I2COp.Opt = I2CREAD;//读/写操作
	I2COp.Ops = I2COPBUSY;//操作状态
	
	status = 0;
	if( Sendaddr( Device, Addr, AddrLen, I2CREAD ) ) status = 1; //写入失败
	else 
	{
		LL_I2C_MasterMode_ClearFlag_ReceiveCompleted(I2C); //清中断标志
		LL_I2C_MasterMode_EnabledIT_ReceiveCompleted(I2C);//开启I2C中断
		LL_I2C_MasterMode_EnableReceive(I2C);//打开接收使能
	}

	return( status );
}


void I2C_Init(void)
{
	LL_I2C_MasterMode_InitTypeDef   IICInitStructer;    
	LL_GPIO_InitTypeDef    GPIO_InitStruct={0};
	
	GPIO_InitStruct.Pin = LL_GPIO_PIN_11|LL_GPIO_PIN_12;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
	GPIO_InitStruct.Pull = DISABLE;
	LL_GPIO_Init(GPIOA,&GPIO_InitStruct);
	IICInitStructer.ClockSource = LL_RCC_I2C_OPERATION_CLOCK_SOURCE_APBCLK1;
	IICInitStructer.BaudRate = 100000;
	LL_I2C_MasterMode_Init(I2C,&IICInitStructer);	
	
	NVIC_DisableIRQ(I2C_IRQn);
	NVIC_SetPriority(I2C_IRQn,2);
	NVIC_EnableIRQ(I2C_IRQn);	
}

uint8_t Test_I2C(void)
{
	uint8_t Device = DEVICE_FM38025T;
	uint16_t Addr;
	uint8_t AddrLen = ADDRLEN_FM38025T;
	uint8_t Buf[64];
	uint8_t Len = 0;
	uint8_t Result = 0;
	
	uint8_t TestData[7] = {0x59, 0x59, 0x23, 0x10, 0x31, 0x08, 0x18}; 
	
	
	Addr = 0;
	Len = 7;
	I2C_Init();
	
	memset(Buf, 0, 64);
	Result = I2C_Read_Bottom_Int(Device, Addr, AddrLen, Buf, Len);//读ee测试
	if(Result == 0)while(I2COp.Ops != I2COPFINISH);//等待读取完成
	
	memset(Buf, 0xAA, 64);
	memcpy(Buf, TestData, Len);
	Result = I2C_Write_Bottom_Int(Device, Addr, AddrLen, Buf, Len);//写ee测试
	if(Result == 0)while(I2COp.Ops != I2COPFINISH);//等待发送完成
	DelayMs(5);//软件延时,等待ee内部写完成
	
	memset(Buf, 0, 64);
	Result = I2C_Read_Bottom_Int(Device, Addr, AddrLen, Buf, Len);//读ee测试
	if(Result == 0)while(I2COp.Ops != I2COPFINISH);//等待读取完成
	
	//IWDT_Clr();             //清系统看门狗	
	return Result;
}


