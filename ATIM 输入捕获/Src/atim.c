#include "atim.h"
#include "main.h"

void ATIM_Init(void)
{
    LL_ATIM_InitTypeDef        InitStructer;    
    
    InitStructer.ClockSource           = LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_APBCLK2;  //时钟源选择APB2
    InitStructer.Prescaler             = 7999;                                         //分频系数8000
    InitStructer.CounterMode           = LL_ATIM_COUNTER_DIRECT_UP;                    //向上计数
    InitStructer.Autoreload            = 999;                                          //自动重装载值1000
    InitStructer.ClockDivision         = LL_ATIM_CLOCKDIVISION_DIV1;                   //死区和滤波设置
    InitStructer.RepetitionCounter     = 0;                                            //重复计数
    InitStructer.AutoreloadState       = DISABLE;                                      //自动重装载禁止preload
    LL_ATIM_Init(ATIM,&InitStructer);
    
    NVIC_DisableIRQ(ATIM_IRQn);
    NVIC_SetPriority(ATIM_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(ATIM_IRQn);	
  
    LL_ATIM_ClearFlag_UPDATE(ATIM);  //清除计数器中断标志位
  
    LL_ATIM_EnableIT_UPDATE(ATIM); //开启计数器中断
 
    LL_ATIM_EnableCounter(ATIM); //使能定时器
}

void ATIM_PWM_Init(void)
{
    LL_ATIM_InitTypeDef        InitStructer1;    
    LL_ATIM_OC_InitTypeDef     InitStructer2;
    LL_ATIM_BDTR_InitTypeDef   InitStructer3;
    LL_GPIO_InitTypeDef         GPIO_InitStruct={0};
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    LL_GPIO_Init(GPIOB,&GPIO_InitStruct);  //CH1 
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    GPIO_InitStruct.RemapPin = ENABLE;
    LL_GPIO_Init(GPIOB,&GPIO_InitStruct);  //CH1N
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_11;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.RemapPin = ENABLE;
    LL_GPIO_Init(GPIOD,&GPIO_InitStruct); //BRK1
    
    InitStructer1.ClockSource           = LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_APBCLK2;  //时钟源选择APB2
    InitStructer1.Prescaler             = 7999;                                         //分频系数8000
    InitStructer1.CounterMode           = LL_ATIM_COUNTER_DIRECT_UP;                    //向上计数
    InitStructer1.Autoreload            = 999;                                          //自动重装载值1000
    InitStructer1.ClockDivision         = LL_ATIM_CLOCKDIVISION_DIV1;                   //死区和滤波分频
    InitStructer1.RepetitionCounter     = 0;                                            //重复计数
    InitStructer1.AutoreloadState       = ENABLE;                                       //预装载preload使能                        
    LL_ATIM_Init(ATIM,&InitStructer1);
    
    InitStructer2.OCMode       = LL_ATIM_OC_MODE_PWM1;                     //输出比较模式PWM1
    InitStructer2.OCETRFStatus = DISABLE;                                  //OC1REF不受ETR影响
    InitStructer2.OCFastMode   = DISABLE;                                  //关闭快速使能  
    InitStructer2.CompareValue = 500;                                      //比较值500
    InitStructer2.OCPolarity   = LL_ATIM_OC_POLARITY_HIGH;                 //OC 高电平有效
    InitStructer2.OCPreload    = DISABLE;                                  //OC preload 无效
    InitStructer2.OCIdleState  = LL_ATIM_OC_IDLESTATE_HIGH;                //OC IDLE时为高电平
    InitStructer2.OCNIdleState = LL_ATIM_OCN_IDLESTATE_HIGH;               //OCN IDLE时为高电平
    InitStructer2.OCNPolarity  = LL_ATIM_OCN_POLARITY_HIGH;                //OCN 高电平有效
    InitStructer2.OCNState     = ENABLE;                                   //使能互补输出通道
    LL_ATIM_OC_Init(ATIM,LL_ATIM_CHANNEL_1,&InitStructer2);
    
    InitStructer3.DeadTime            = 10;                                 //死区时间配置
    InitStructer3.LockLevel           = LL_ATIM_LOCKLEVEL_OFF;              //寄存器写保护关闭
    InitStructer3.OSSRState           = LL_ATIM_OSSR_DISABLE;               //OSSR=0
    InitStructer3.OSSIState           = LL_ATIM_OSSI_DISABLE;               //OSSI=0
    InitStructer3.BreakFilter         = LL_ATIM_BRK_FILTER_FDIV1;           //刹车信号滤波配置
    InitStructer3.BreakPolarity       = LL_ATIM_BREAK_POLARITY_HIGH;        //刹车信号高电平有效
    InitStructer3.AutomaticOutput     = DISABLE;                            //MOE由软件置位
    InitStructer3.GatedBrakeSignal_1  = LL_ATIM_BREAK1_GATE_AUTO;           //刹车信号1不门控
    InitStructer3.GatedBrakeSignal_2  = LL_ATIM_BREAK2_GATE_AUTO;           //刹车信号2不门控
    InitStructer3.BrakeSignalCombined = LL_ATIM_BRK_COMBINATION_OR;         //刹车信号1和2或
    InitStructer3.BreakState          = DISABLE;                            //刹车信号禁止
    LL_ATIM_BDTR_Init(ATIM,&InitStructer3);
 
    LL_ATIM_EnableCounter(ATIM); //使能定时器
    
    LL_ATIM_Enable_AllOutputs(ATIM);//主控输出使能
}

void ATIM_CAPTURE_Init(void)
{   
    LL_ATIM_InitTypeDef        InitStructer1;    
    LL_ATIM_IC_InitTypeDef     InitStructer2;
    LL_ATIM_SlaveInitTypeDef   InitStructer3;
    LL_GPIO_InitTypeDef         GPIO_InitStruct={0};
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    
    LL_GPIO_Init(GPIOB,&GPIO_InitStruct);  //CH1 
    
    InitStructer1.ClockSource           = LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_APBCLK2;//时钟源 APB2
    InitStructer1.Prescaler             = 7999;                                       //分频8000
    InitStructer1.CounterMode           = LL_ATIM_COUNTER_DIRECT_UP;                  //向上计数
    InitStructer1.Autoreload            = 65535;                                      //自动装载值65536
    InitStructer1.ClockDivision         = LL_ATIM_CLOCKDIVISION_DIV1;                 // 死区和数字滤波分频
    InitStructer1.RepetitionCounter     = 0;                                          //重复计数0
    InitStructer1.AutoreloadState       = ENABLE;                                     //自动重装载ARPE使能
    LL_ATIM_Init(ATIM,&InitStructer1);
    
    InitStructer3.SlaveMode     = LL_ATIM_SLAVE_MODE_TRGI_RISE_RST;   //从机复位模式
    InitStructer3.TriggerSrc    = LL_ATIM_TIM_TS_TI1FP1;              //触发源选择 TI1FP1
    InitStructer3.TriggerDelay  = DISABLE;                            //TRGI延迟禁止
    LL_ATIM_SlaveMode_Init(ATIM,&InitStructer3);
    
    InitStructer2.ICPolarity    = LL_ATIM_IC_POLARITY_RISING;          //上升沿捕获
    InitStructer2.ICActiveInput = LL_ATIM_CC1_MODE_INPUT_TI1;          //CC1配置为输入，IC1映射到TI1
    InitStructer2.ICPrescaler   = LL_ATIM_IC_PRESCALER_DIV_1;          //输入捕捉分频
    InitStructer2.ICFilter      = LL_ATIM_IC_FILTER_FDIV1;             //输入捕捉滤波配置
    InitStructer2.CaptureState  = ENABLE;                              //使能CC1通道
    LL_ATIM_IC_Init(ATIM,LL_ATIM_CHANNEL_1,&InitStructer2);
    
    InitStructer2.ICPolarity    = LL_ATIM_IC_POLARITY_FALLING;         //下降沿捕获
    InitStructer2.ICActiveInput = LL_ATIM_CC2_MODE_INPUT_TI1;          //CC2配置为输入，IC1映射到TI1
    LL_ATIM_IC_Init(ATIM,LL_ATIM_CHANNEL_2,&InitStructer2);
    
    NVIC_DisableIRQ(ATIM_IRQn);
    NVIC_SetPriority(ATIM_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(ATIM_IRQn);
    
    LL_ATIM_ClearFlag_CC(ATIM,LL_ATIM_CHANNEL_1);     //清除CC1捕捉标志      
    LL_ATIM_EnableIT_CC(ATIM,LL_ATIM_CHANNEL_1);      //使能CC1捕捉中断
    
    LL_ATIM_EnableCounter(ATIM); //使能定时器
}

