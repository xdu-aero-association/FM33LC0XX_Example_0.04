#include "TestRTC.h"
#include "user_init.h"


void RTC_Fsel_Out(uint8_t FselType)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

	LL_RTC_SetTimeMark(RTC,FselType);
	
	GPIO_InitStruct.Pin = LL_GPIO_PIN_11;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = DISABLE;
	LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	LL_GPIO_SetFout0(GPIO_COMMON, LL_GPIO_FOUT0_SELECT_RTCTM);

}

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



void Test_RTC(void)
{

	RTC_Init();				//RTC初始化
	RTC_Fsel_Out(LL_RTC_TIME_MARK_SEC);
}

