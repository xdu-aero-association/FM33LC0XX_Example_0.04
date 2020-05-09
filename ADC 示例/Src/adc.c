#include "adc.h"
#include "user_init.h"

#define ADC_VREF    (*((uint16_t *)(0x1FFFFB08)))   // 30℃ vref1.22采样值

uint64_t GetVSample;
uint32_t Get122VSample;
uint32_t GetV;

void AdcInit(void)
{
LL_GPIO_InitTypeDef         GPIO_InitStruct;	
LL_ADC_CommonInitTypeDef    ADC_CommonInitStruct;
LL_ADC_InitTypeDef          ADC_InitStruct ;

	//配置引脚为模拟功能
	//ADC ADC_0 引脚 PC9 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_9;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	//ADC ADC_1 引脚 PC10 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_10;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	//ADC ADC_2 引脚 PD11 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_11;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	
	//ADC ADC_3 引脚 PD0 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_0;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	//ADC ADC_4 引脚 PD1 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_1;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	
	//ADC ADC_5 引脚 PD2 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_2;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	//ADC ADC_6 引脚 PA13 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_13;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//ADC ADC_7 引脚 PD14 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_14;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	//ADC ADC_8 引脚 PC7 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_7;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	//ADC ADC_9 引脚 PC8 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_8;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	//ADC ADC_10 引脚 PA15 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_15;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	//ADC ADC_11 引脚 PC6 
	GPIO_InitStruct.Pin        = LL_GPIO_PIN_6;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = DISABLE;
	GPIO_InitStruct.RemapPin   = DISABLE;	
	LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	//ADC 时钟设置
	ADC_CommonInitStruct.AdcClockSource    = LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RCHF; //RCHF
	ADC_CommonInitStruct.AdcClockPrescaler = LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV16; //16分频
	LL_ADC_CommonInit(&ADC_CommonInitStruct);
	
	//ADC 寄存器设置
	  ADC_InitStruct.ADC_ContinuousConvMode  = LL_ADC_CONV_SINGLE;//单次模式
    ADC_InitStruct.ADC_AutoMode            = LL_ADC_SINGLE_CONV_MODE_AUTO;//自动
    ADC_InitStruct.ADC_ScanDirection       = LL_ADC_SEQ_SCAN_DIR_FORWARD;//通道正序扫描
    ADC_InitStruct.ADC_ExternalTrigConv    = LL_ADC_EXT_TRIGGER_NONE;//禁止触发信号
    ADC_InitStruct.ADC_OverrunMode 		   = LL_ADC_OVR_DATA_OVERWRITTEN;//覆盖上次数据
    ADC_InitStruct.ADC_WaitMode 		       = LL_ADC_WAIT_MODE_NO_WAIT;//无等待 
    ADC_InitStruct.ADC_SamplingStartControl = LL_ADC_SAMPLING_START_CONTROL_BY_REG;//由START寄存器启动ADC采样
    ADC_InitStruct.ADC_SamplingTimeControl = LL_ADC_SAMPLING_TIME_CONTROL_BY_REG;//由寄存器控制ADC采样时间
    ADC_InitStruct.ADC_Channel_Swap_Wiat   = LL_ADC_SAMPLEING_INTERVAL_11_CYCLES;//通道切换等待时间
    ADC_InitStruct.ADC_Channel_Fast_Time   = LL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK;//快速通道采样时间
    ADC_InitStruct.ADC_Channel_Slow_Time   = LL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK;//慢速通道采样时间
    ADC_InitStruct.ADC_Oversampling        = DISABLE;//过采样关闭
    ADC_InitStruct.ADC_OverSampingRatio    = LL_ADC_OVERSAMPLING_256X;//256倍过采样
    ADC_InitStruct.ADC_OversamplingShift   = LL_ADC_OVERSAMPLING_RESULT_DIV256;//数据右移, /256	
    LL_ADC_Init(ADC, &ADC_InitStruct);

}

uint32_t GetVref1p22Sample(void)
{
uint16_t ADCRdresult;

    LL_VREF_EnableVREFBuffer(VREF);//使能VREF BUFFER
	
	LL_ADC_EnalbleSequencerChannel(ADC, LL_ADC_INTERNAL_CH_VREF);//通道选择VREF
	
	LL_ADC_ClearFlag_EOC(ADC);//清标志			
    LL_ADC_Enable(ADC);   	 // 启动ADC
	LL_ADC_StartConversion(ADC);  // 开始转换

    // 等待转换完成
    while (LL_ADC_IsActiveFlag_EOC(ADC) == RESET);
    LL_ADC_ClearFlag_EOC(ADC);//清标志
	ADCRdresult =LL_ADC_ReadConversionData12(ADC);//获取采样值
	
	LL_ADC_DisableSequencerChannel(ADC, LL_ADC_INTERNAL_CH_VREF);//通道关闭VREF	
    LL_ADC_Disable(ADC);    // 关闭ADC

    LL_VREF_DisableVREFBuffer(VREF);//关闭VREF BUFFER	
		
    // 转换结果 
    return ADCRdresult;
}

uint32_t GetVoltageSample(void)
{
uint16_t ADCRdresult;
	
	LL_ADC_EnalbleSequencerChannel(ADC, LL_ADC_EXTERNAL_CH_0);//通道选择ADC_0
	
	LL_ADC_ClearFlag_EOC(ADC);//清标志			
    LL_ADC_Enable(ADC);   	 // 启动ADC
	LL_ADC_StartConversion(ADC);  // 开始转换

    // 等待转换完成
    while (LL_ADC_IsActiveFlag_EOC(ADC) == RESET);
    LL_ADC_ClearFlag_EOC(ADC);//清标志
	ADCRdresult =LL_ADC_ReadConversionData12(ADC);//获取采样值
	LL_ADC_DisableSequencerChannel(ADC, LL_ADC_EXTERNAL_CH_0);//通道关闭ADC_0
    LL_ADC_Disable(ADC);    // 关闭ADC
		
    // 转换结果 
    return ADCRdresult;
}

uint32_t GetVoltage(void)
{
	Get122VSample = GetVref1p22Sample();		
	GetVSample =GetVoltageSample(); 			
	GetV =  (GetVSample *1000*(ADC_VREF*3))/(Get122VSample*4095); 
	return GetV;
}


