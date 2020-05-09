#include "user_init.h"
#include "main.h"
#include "gpio_interrupt.h"

//引脚中断
void GPIO_IRQHandler(void)
{
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_0))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_0);
        if(LINE_0_N){}//IO口低电平
        if(LINE_0_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_1))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_1);
        if(LINE_1_N){}//IO口低电平
        if(LINE_1_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_2))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_2);
        if(LINE_2_N){}//IO口低电平
        if(LINE_2_P){}//IO口高电平
    }    
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_3))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_3);
        if(LINE_3_N){}//IO口低电平
        if(LINE_3_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_4))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_4);
        if(LINE_4_N){}//IO口低电平
        if(LINE_4_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_5))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_5);
        if(LINE_5_N){}//IO口低电平
        if(LINE_5_P){}//IO口高电平
    }    
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_6))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_6);
        if(LINE_6_N){}//IO口低电平
        if(LINE_6_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_7))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_7);
        if(LINE_7_N){}//IO口低电平
        if(LINE_7_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_8))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_8);
        if(LINE_8_N){}//IO口低电平
        if(LINE_8_P){}//IO口高电平
    }    
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_9))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_9);
        if(LINE_9_N){}//IO口低电平
        if(LINE_9_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_10))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_10);
        if(LINE_10_N){}//IO口低电平
        if(LINE_10_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_11))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_11);
        if(LINE_11_N){}//IO口低电平
        if(LINE_11_P){}//IO口高电平
    }    
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_12))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_12);
        if(LINE_12_N){}//IO口低电平
        if(LINE_12_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_13))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_13);
        if(LINE_13_N){}//IO口低电平
        if(LINE_13_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_14))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_14);
        if(LINE_14_N){}//IO口低电平
        if(LINE_14_P){}//IO口高电平
    }
    if(SET == LL_EXTI_IsActiveFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_15))
    {
        LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_15);
        if(LINE_15_N){}//IO口低电平
        if(LINE_15_P){}//IO口高电平
    }    
}
    

// 外部引脚中断初始化
void GPIO_interrupt_init(void)
{
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};    
    
    //引脚边沿触发选择
    LL_RCC_Enable_SleepmodeExternalInterrupt();//休眠使能外部中断采样
    LL_RCC_SetEXTIClockSource(LL_RCC_EXTERNAL_INTERRUPT_SAMPLING_CLOCK_SELECT_LSCLK);//EXTI中断采样时钟选择
    LL_RCC_Group1_EnableOperationClock(LL_RCC_OPERATION1_CLOCK_EXTI);//EXTI工作时钟使能    
    
    //LINE_0   用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_0_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_0_GPIO, &GPIO_InitStruct);


    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_0, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
    LL_GPIO_SetExitLine0(GPIO_COMMON, LL_GPIO_EXTI_LINE_0_PA0);//中断引脚选择
//    LL_GPIO_SetExitLine0(GPIO_COMMON, LL_GPIO_EXTI_LINE_0_PA1);//中断引脚选择
//    LL_GPIO_SetExitLine0(GPIO_COMMON, LL_GPIO_EXTI_LINE_0_PA2);//中断引脚选择
//    LL_GPIO_SetExitLine0(GPIO_COMMON, LL_GPIO_EXTI_LINE_0_PA3);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_0);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_0, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_0);//清除中断标志
    
    //LINE_1   用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_1_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_1_GPIO, &GPIO_InitStruct);


    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_1, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
    LL_GPIO_SetExitLine1(GPIO_COMMON, LL_GPIO_EXTI_LINE_1_PA4);//中断引脚选择
//    LL_GPIO_SetExitLine1(GPIO_COMMON, LL_GPIO_EXTI_LINE_1_PA5);//中断引脚选择
//    LL_GPIO_SetExitLine1(GPIO_COMMON, LL_GPIO_EXTI_LINE_1_PA6);//中断引脚选择
//    LL_GPIO_SetExitLine1(GPIO_COMMON, LL_GPIO_EXTI_LINE_1_PA7);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_1);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_1, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_1);//清除中断标志
    
    //LINE_2   用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_2_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_2_GPIO, &GPIO_InitStruct);


    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_2, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
    LL_GPIO_SetExitLine2(GPIO_COMMON, LL_GPIO_EXTI_LINE_2_PA8);//中断引脚选择
//    LL_GPIO_SetExitLine2(GPIO_COMMON, LL_GPIO_EXTI_LINE_2_PA9);//中断引脚选择
//    LL_GPIO_SetExitLine2(GPIO_COMMON, LL_GPIO_EXTI_LINE_2_PA10);//中断引脚选择
//    LL_GPIO_SetExitLine2(GPIO_COMMON, LL_GPIO_EXTI_LINE_2_PA11);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_2);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_2, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_2);//清除中断标志    


    //LINE_3   用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_3_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_3_GPIO, &GPIO_InitStruct);


    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_3, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
    LL_GPIO_SetExitLine3(GPIO_COMMON, LL_GPIO_EXTI_LINE_3_PA12);//中断引脚选择
//    LL_GPIO_SetExitLine3(GPIO_COMMON, LL_GPIO_EXTI_LINE_3_PA13);//中断引脚选择
//    LL_GPIO_SetExitLine3(GPIO_COMMON, LL_GPIO_EXTI_LINE_3_PA14);//中断引脚选择
//    LL_GPIO_SetExitLine3(GPIO_COMMON, LL_GPIO_EXTI_LINE_3_PA15);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_3);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_3, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_3);//清除中断标志

    //LINE_4   用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_4_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_4_GPIO, &GPIO_InitStruct);


    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_4, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
//    LL_GPIO_SetExitLine4(GPIO_COMMON, LL_GPIO_EXTI_LINE_4_PB0);//中断引脚选择（带usb版本芯片没有）
//    LL_GPIO_SetExitLine4(GPIO_COMMON, LL_GPIO_EXTI_LINE_4_PB1);//中断引脚选择（带usb版本芯片没有）
    LL_GPIO_SetExitLine4(GPIO_COMMON, LL_GPIO_EXTI_LINE_4_PB2);//中断引脚选择
//    LL_GPIO_SetExitLine4(GPIO_COMMON, LL_GPIO_EXTI_LINE_4_PB3);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_4);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_4, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_4);//清除中断标志
    
    //LINE_5   用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_5_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_5_GPIO, &GPIO_InitStruct);


    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_5, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
//    LL_GPIO_SetExitLine5(GPIO_COMMON, LL_GPIO_EXTI_LINE_5_PB4);//中断引脚选择
//    LL_GPIO_SetExitLine5(GPIO_COMMON, LL_GPIO_EXTI_LINE_5_PB5);//中断引脚选择
//    LL_GPIO_SetExitLine5(GPIO_COMMON, LL_GPIO_EXTI_LINE_5_PB6);//中断引脚选择
    LL_GPIO_SetExitLine5(GPIO_COMMON, LL_GPIO_EXTI_LINE_5_PB7);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_5);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_5, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_5);//清除中断标志

    //LINE_6   用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_6_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_6_GPIO, &GPIO_InitStruct);


    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_6, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
//    LL_GPIO_SetExitLine6(GPIO_COMMON, LL_GPIO_EXTI_LINE_6_PB8);//中断引脚选择
//    LL_GPIO_SetExitLine6(GPIO_COMMON, LL_GPIO_EXTI_LINE_6_PB9);//中断引脚选择
//    LL_GPIO_SetExitLine6(GPIO_COMMON, LL_GPIO_EXTI_LINE_6_PB10);//中断引脚选择
    LL_GPIO_SetExitLine6(GPIO_COMMON, LL_GPIO_EXTI_LINE_6_PB11);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_6);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_6, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_6);//清除中断标志
    
    //LINE_7   用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_7_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_7_GPIO, &GPIO_InitStruct);


    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_7, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
    LL_GPIO_SetExitLine7(GPIO_COMMON, LL_GPIO_EXTI_LINE_7_PB12);//中断引脚选择
//    LL_GPIO_SetExitLine7(GPIO_COMMON, LL_GPIO_EXTI_LINE_7_PB13);//中断引脚选择
//    LL_GPIO_SetExitLine7(GPIO_COMMON, LL_GPIO_EXTI_LINE_7_PB14);//中断引脚选择
//    LL_GPIO_SetExitLine7(GPIO_COMMON, LL_GPIO_EXTI_LINE_7_PB15);//中断引脚选择（带usb版本芯片没有）    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_7);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_7, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_7);//清除中断标志    


    //LINE_8  用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_8_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_8_GPIO, &GPIO_InitStruct);
    
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_8, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
//    LL_GPIO_SetExitLine8(GPIO_COMMON, LL_GPIO_EXTI_LINE_8_PC0);//中断引脚选择
//    LL_GPIO_SetExitLine8(GPIO_COMMON, LL_GPIO_EXTI_LINE_8_PC1);//中断引脚选择
//    LL_GPIO_SetExitLine8(GPIO_COMMON, LL_GPIO_EXTI_LINE_8_PC2);//中断引脚选择
    LL_GPIO_SetExitLine8(GPIO_COMMON, LL_GPIO_EXTI_LINE_8_PC3);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_8);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_8, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_8);//清除中断标志    
    
    //LINE_9  用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_9_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_9_GPIO, &GPIO_InitStruct);

    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_9, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
//    LL_GPIO_SetExitLine9(GPIO_COMMON, LL_GPIO_EXTI_LINE_9_PC4);//中断引脚选择
//    LL_GPIO_SetExitLine9(GPIO_COMMON, LL_GPIO_EXTI_LINE_9_PC5);//中断引脚选择
//    LL_GPIO_SetExitLine9(GPIO_COMMON, LL_GPIO_EXTI_LINE_9_PC6);//中断引脚选择
    LL_GPIO_SetExitLine9(GPIO_COMMON, LL_GPIO_EXTI_LINE_9_PC7);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_9);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_9, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_9);//清除中断标志    

    //LINE_10  用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_10_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_10_GPIO, &GPIO_InitStruct);
    
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_10, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
//    LL_GPIO_SetExitLine10(GPIO_COMMON, LL_GPIO_EXTI_LINE_10_PC8);//中断引脚选择
//    LL_GPIO_SetExitLine10(GPIO_COMMON, LL_GPIO_EXTI_LINE_10_PC9);//中断引脚选择
//    LL_GPIO_SetExitLine10(GPIO_COMMON, LL_GPIO_EXTI_LINE_10_PC10);//中断引脚选择
    LL_GPIO_SetExitLine10(GPIO_COMMON, LL_GPIO_EXTI_LINE_10_PC11);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_10);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_10, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_10);//清除中断标志    
    
    //LINE_11  用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_11_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_11_GPIO, &GPIO_InitStruct);

    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_11, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_11);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_11, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_11);//清除中断标志        

    //LINE_12  用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_12_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_12_GPIO, &GPIO_InitStruct);
    
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_12, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
//    LL_GPIO_SetExitLine12(GPIO_COMMON, LL_GPIO_EXTI_LINE_12_PD0);//中断引脚选择
//    LL_GPIO_SetExitLine12(GPIO_COMMON, LL_GPIO_EXTI_LINE_12_PD1);//中断引脚选择
//    LL_GPIO_SetExitLine12(GPIO_COMMON, LL_GPIO_EXTI_LINE_12_PD2);//中断引脚选择
    LL_GPIO_SetExitLine12(GPIO_COMMON, LL_GPIO_EXTI_LINE_12_PD3);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_12);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_12, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_12);//清除中断标志    
    
    //LINE_13  用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_13_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_13_GPIO, &GPIO_InitStruct);
    
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_13, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
    LL_GPIO_SetExitLine13(GPIO_COMMON, LL_GPIO_EXTI_LINE_13_PD4);//中断引脚选择
//    LL_GPIO_SetExitLine13(GPIO_COMMON, LL_GPIO_EXTI_LINE_13_PD5);//中断引脚选择
//    LL_GPIO_SetExitLine13(GPIO_COMMON, LL_GPIO_EXTI_LINE_13_PD6);//中断引脚选择
//    LL_GPIO_SetExitLine13(GPIO_COMMON, LL_GPIO_EXTI_LINE_13_PD7);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_13);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_13, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_13);//清除中断标志    
    
    //LINE_14  用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_14_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_14_GPIO, &GPIO_InitStruct);
    
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_14, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    //每条LINE 只能选一个引脚 
//    LL_GPIO_SetExitLine14(GPIO_COMMON, LL_GPIO_EXTI_LINE_14_PD8);//中断引脚选择
//    LL_GPIO_SetExitLine14(GPIO_COMMON, LL_GPIO_EXTI_LINE_14_PD9);//中断引脚选择（XTLF引脚，关闭XTLF）
    LL_GPIO_SetExitLine14(GPIO_COMMON, LL_GPIO_EXTI_LINE_14_PD10);//中断引脚选择（XTLF引脚，关闭XTLF）
//    LL_GPIO_SetExitLine14(GPIO_COMMON, LL_GPIO_EXTI_LINE_14_PD11);//中断引脚选择    
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_14);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_14, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_14);//清除中断标志    

    //LINE_15  用到的GPIO引脚    设为输入 
    GPIO_InitStruct.Pin = LINE_15_PIN;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(LINE_15_GPIO, &GPIO_InitStruct);
    //（带usb版本芯片没有）    
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_15, LL_GPIO_EXTI_TRIGGER_NONE);//关闭边沿触发
    LL_EXTI_EnableDigitalFilter(GPIO_COMMON, LL_GPIO_EXTI_LINE_15);//EXTI数字滤波功能
    LL_EXTI_SetTrigEdge(GPIO_COMMON, LL_GPIO_EXTI_LINE_15, LL_GPIO_EXTI_TRIGGER_BOTHEDGE);//边沿选择    
    LL_EXTI_ClearFlag(GPIO_COMMON, LL_GPIO_EXTI_LINE_15);//清除中断标志    
    
    /*NVIC中断配置*/
    NVIC_DisableIRQ(GPIO_IRQn);
    NVIC_SetPriority(GPIO_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(GPIO_IRQn);
}
