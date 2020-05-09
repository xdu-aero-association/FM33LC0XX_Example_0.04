#include "lptim.h"
#include "main.h"
#include "user_init.h"

void LPTIM_IRQHandler(void)
{
    if ((LL_LPTIM_IsEnabled_CounterOver(LPTIM) == ENABLE) &&
        (LL_LPTIM_IsActiveFlag_CounterOver(LPTIM) == SET))
    {
        LL_LPTIM_ClearFlag_CounterOver(LPTIM);       //清除标志     
        LED0_TOG();
    }	
}

void LptimInit(void)
{
    LL_LPTIM_TimeInitTypeDef  LPTIM_InitStruct={0};
    
    LPTIM_InitStruct.PrescalerClockSource = LL_LPTIM_PRESCALER_INPUT_LPTIM_CLK;   //时钟输入选择CLKSEL的时钟
    
    LPTIM_InitStruct.ClockSource = LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_LSCLK;     //CLKSEL时钟源选择LSCLK

	  LPTIM_InitStruct.Prescaler = LL_LPTIM_CLOCKDIVISION_DIV1;                     //计数时钟不分频

	  LPTIM_InitStruct.Mode = LL_LPTIM_OPERATION_MODE_NORMAL;                       //普通定时器模式

	  LPTIM_InitStruct.OneState = LL_LPTIM_ONE_STATE_TIMER_CONTINUE;                //连续计数模式

	 // LPTIM_InitStruct.Edge = LL_LPTIM_EXTERNAL_INPUT_TRIGGER_RINSING;           //外部触发信号配置       
    
   // LPTIM_InitStruct.Polarity = LL_LPTIM_EXTERNAL_INPUT_POlARITY_RISING;        //外部触发信号配置 
   
    LL_LPTIM_TimeModeInit(LPTIM,&LPTIM_InitStruct);
    
    LL_LPTIM_SetAutoReload(LPTIM,32767);    //设置目标值
    
    LL_LPTIM_ClearFlag_CounterOver(LPTIM);   //清除溢出标志
    
    LL_LPTIM_EnableIT_CounterOver(LPTIM);   //溢出中断使能
    NVIC_DisableIRQ(LPTIM_IRQn);
    NVIC_SetPriority(LPTIM_IRQn,2);//设置中断优先级
    NVIC_EnableIRQ(LPTIM_IRQn);    //使能NVIC
    
    LL_LPTIM_Enable(LPTIM);   //使能LPTIM
}

