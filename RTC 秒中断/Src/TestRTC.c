#include "TestRTC.h"
#include "user_init.h"

// RTC读写时间和秒中断示例
void RTC_IRQHandler(void)
{
	if(ENABLE == LL_RTC_IsEnabledIT_Second(RTC) &&
		 SET == LL_RTC_IsActiveFlag_Second(RTC))//查询秒中断标志是否置起
	{
  	LL_GPIO_ToggleOutputPin(GPIOC, LL_GPIO_PIN_0);
		LL_RTC_ClearFlag_Second(RTC);		//清除秒中断标志
	}
}

void RTC_Init(void)
{	

	LL_RTC_InitTypeDef   InitStructer;
    
	InitStructer.Year   = 0x20;
	InitStructer.Month  = 0x02;
	InitStructer.Day    = 0x21;	
	InitStructer.Week   = 0x04;	
	InitStructer.Hour   = 0x15;
	InitStructer.Minute = 0x33;
	InitStructer.Second = 0x00;	
	LL_RTC_Init(RTC,&InitStructer);

	LL_RTC_ClearFlag_Second(RTC);		//清除秒中断标志
	LL_RTC_EnableIT_Second(RTC);

	NVIC_DisableIRQ(RTC_IRQn);				//NVIC中断控制器配置
	NVIC_SetPriority(RTC_IRQn,2);
	NVIC_EnableIRQ(RTC_IRQn);	
}


void Test_RTC(void)
{
	RTC_Init();

}

