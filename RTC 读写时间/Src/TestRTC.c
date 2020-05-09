#include "TestRTC.h"
#include "user_init.h"

void RTC_Init(void)
{	

	LL_RTC_InitTypeDef 	 TempTime;
    
	TempTime.Year   = 0x20;
	TempTime.Month  = 0x02;
	TempTime.Day    = 0x21;	
	TempTime.Week   = 0x04;	
	TempTime.Hour   = 0x09;
	TempTime.Minute = 0x00;
	TempTime.Second = 0x00;	
	LL_RTC_Init(RTC,&TempTime);

	NVIC_DisableIRQ(RTC_IRQn);				//NVIC中断控制器配置
}

uint8_t RTC_GetRTC(LL_RTC_InitTypeDef* InitStructer)
{
	uint8_t n, i;
	uint8_t Result = 1;

	LL_RTC_InitTypeDef TempTime1,TempTime2;
	
	for(n=0 ;n<3; n++)
	{
		LL_RTC_GetTime(RTC,&TempTime1);//读一次时间
		LL_RTC_GetTime(RTC,&TempTime2);//再读一次时间
		
		for(i=0; i<7; i++)//两者一致, 表示读取成功
		{
			if(((uint32_t*)(&TempTime1))[i] != ((uint32_t*)(&TempTime2))[i]) break;
		}
		if(i == 7)
		{
			Result = 0;
			memcpy((uint32_t*)(InitStructer), (uint32_t*)(&TempTime1), 7*sizeof(uint32_t));//读取正确则更新新的时间		
			break;
		}
	}
	return Result;
}

uint8_t RTC_SetRTC(LL_RTC_InitTypeDef* InitStructer)
{
	uint8_t n, i;
	uint8_t Result;
	LL_RTC_InitTypeDef TempTime1;
	
	for(n=0 ;n<3; n++)
	{
		LL_RTC_ConfigTime(RTC,InitStructer);	
		Result = RTC_GetRTC(&TempTime1);	//读取确认设置结果
		if(Result == 0)
		{
			Result = 1;
			for(i=0; i<7; i++)//两者一致, 表示设置成功
			{
				if(((uint32_t*)(&TempTime1))[i] != ((uint32_t*)(InitStructer))[i]) 
					break;
			}
			if(i == 7)
			{
				Result = 0;
				break;
			}
		}
	}
	return Result;
}

void Test_RTC(void)
{
	LL_RTC_InitTypeDef 	 InitTime;
	LL_RTC_InitTypeDef 	 GetTime;
	
	RTC_Init();
	InitTime.Year   = 0x20;
	InitTime.Month  = 0x02;
	InitTime.Day    = 0x21;	
	InitTime.Week   = 0x04;	
	InitTime.Hour   = 0x15;
	InitTime.Minute = 0x00;
	InitTime.Second = 0x00;	

	RTC_SetRTC(&InitTime);
	DelayMs(1000);
	RTC_GetRTC(&GetTime);

}

