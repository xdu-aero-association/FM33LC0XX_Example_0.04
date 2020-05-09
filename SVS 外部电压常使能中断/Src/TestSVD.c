#include "TestSVD.h"
#include "user_init.h"

#define SPOWERON	0
#define SPOWEROFF	1

uint8_t SVDState; //svd¼ì²â×´Ì¬


void SVD_IRQHandler(void)
{
	if(SET == LL_SVD_IsActiveFlag_PowerFallFlag(SVD) )//Ç·Ñ¹ÖÐ¶Ï
	{
		LL_SVD_EnableReference(SVD,LL_SVD_REFERENCE_VOLTAGE_1_2_VOLT);
		LL_PMU_ClearFlag_PowerFallFlag(SVD);
		SVDState = SPOWEROFF;
	}
	else if(SET == LL_SVD_IsActiveFlag_PowerRiseFlag(SVD))//¹ýÑ¹ÖÐ¶Ï
	{
		LL_SVD_EnableReference(SVD,LL_SVD_REFERENCE_VOLTAGE_1_1_VOLT);
		LL_PMU_ClearFlag_PowerRiseFlag(SVD);
		SVDState = SPOWERON;
	}
}

void Init_SVS(void)
{
	SVD_InitTypeDef   SVD_InitStruct={0};
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0}; 

	GPIO_InitStruct.Pin        = LL_GPIO_PIN_15;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	SVD_InitStruct.Mode            = LL_SVD_WORK_MODE_ALWAYS;
	SVD_InitStruct.Interval        = LL_SVD_INTERVEL_ENABLE_PERIOD_62MS;
	SVD_InitStruct.Threshold       = LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_SVSBASE;
	SVD_InitStruct.SVSChannel      = ENABLE;
	SVD_InitStruct.VrefSelect      = LL_SVD_REFERENCE_VOLTAGE_1_1_VOLT;
	SVD_InitStruct.DigitalFilter   = ENABLE;
	LL_SVD_Init(SVD,&SVD_InitStruct);
    
	LL_PMU_ClearFlag_PowerRiseFlag(SVD);
	LL_PMU_ClearFlag_PowerFallFlag(SVD);
	LL_SVD_EnableITPowerRise(SVD);
	LL_SVD_EnableITPowerFall(SVD);
    
	NVIC_DisableIRQ(SVD_IRQn);			//NVICÖÐ¶Ï¿ØÖÆÆ÷ÅäÖÃ
	NVIC_SetPriority(SVD_IRQn,2);
	NVIC_EnableIRQ(SVD_IRQn);	
    
	LL_SVD_EnableSVD(SVD); 
	
}

void Test_SVS(void)
{
	SVDState = SPOWERON;
	Init_SVS();
	
	for( ; ; )
	{			
		if(SVDState == SPOWEROFF)
		{	
			LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_0);
			
		}
		else
		{
			LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_0);
		
		} 						
		DelayMs(50);//Èí¼þÑÓÊ±
	}
}
