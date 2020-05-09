#include "TestSVD.h"
#include "user_init.h"

#define SPOWERON	0
#define SPOWEROFF	1

uint8_t SVDState; //svd检测状态

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
	NVIC_DisableIRQ(SVD_IRQn);
	
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
	  	
		if(RESET == LL_SVD_IsActiveFlag_SVDOutPut(SVD))// SVD内部滤波后的电压检测标志，仅在使能数字滤波时有意义；软件避免写此寄存器。
		{	
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_0);
		}	
   
		DelayMs(50);//软件延时
	}




}
