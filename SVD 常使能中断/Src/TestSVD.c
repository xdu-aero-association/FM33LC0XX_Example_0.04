#include "TestSVD.h"
#include "user_init.h"

#define SPOWERON	0
#define SPOWEROFF	1

uint8_t SVDState; //svd检测状态

void SVD_IRQHandler(void)
{
	if(SET == LL_SVD_IsActiveFlag_PowerFallFlag(SVD) )//欠压中断
	{
		LL_PMU_ClearFlag_PowerFallFlag(SVD);
		SVDState = SPOWEROFF;
	}
	else if(SET == LL_SVD_IsActiveFlag_PowerRiseFlag(SVD))//过压中断
	{
		LL_PMU_ClearFlag_PowerFallFlag(SVD);
		SVDState = SPOWERON;
	}
}

void Init_SVD(void)
{
	SVD_InitTypeDef   SVD_InitStruct={0};
	
	SVD_InitStruct.Mode            = LL_SVD_WORK_MODE_ALWAYS;
	SVD_InitStruct.Interval        = LL_SVD_INTERVEL_ENABLE_PERIOD_62MS;
	SVD_InitStruct.Threshold       = LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP8;
	SVD_InitStruct.SVSChannel      = DISABLE;
	SVD_InitStruct.VrefSelect      = LL_SVD_REFERENCE_VOLTAGE_1_2_VOLT;
	SVD_InitStruct.DigitalFilter   = ENABLE;
   
	LL_SVD_Init(SVD,&SVD_InitStruct);
    
	LL_PMU_ClearFlag_PowerRiseFlag(SVD);
	LL_PMU_ClearFlag_PowerFallFlag(SVD);
	LL_SVD_EnableITPowerRise(SVD);
	LL_SVD_EnableITPowerFall(SVD);
    
	NVIC_DisableIRQ(SVD_IRQn);			//NVIC中断控制器配置
	NVIC_SetPriority(SVD_IRQn,2);
	NVIC_EnableIRQ(SVD_IRQn);	
    
	LL_SVD_EnableSVD(SVD); 
	
}

void Test_SVD(void)
{
	SVDState = SPOWERON;
	Init_SVD();
	for( ; ; )
	{		
		LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_0);
		DelayMs(50);//软件延时
	  	
		
		if(SVDState == SPOWEROFF)
		{	
			DelayMs(1);//使用中断方式检测掉电时注意去抖，去抖不可太严，否则有可能错过欠压中断导致无法进行相关处理
			if(RESET ==  LL_SVD_IsActiveFlag_SVDOutPut(SVD))// SVD内部滤波后的电压检测标志，仅在使能数字滤波时有意义；软件避免写此寄存器。
			{
				LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_0);
			}
			else
			{
				SVDState = SPOWERON;
			}
		}		
   
		DelayMs(50);//软件延时
	}


}
