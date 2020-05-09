#include "user_init.h"
#include "compare.h"

void COMPx_IRQHandler(void)
{
    //注意对输入信号的滤波，否则容易误触发中断
    if(SET == LL_COMP_IsActiveComparator1(COMP_COMMON))
    {
        LL_COMP_ClearFlag_Comparator1(COMP_COMMON);    //清除COMP1中断标志
        
        if(SET == LL_COMP_GetComparatorOutput(COMP1))    //比较器1 V+电压高于V-
        {
            LED0_ON();
        }
        else                                //比较器1 V+电压低于V-
        {
            LED0_OFF();
        }    
    }
    
    if(SET == LL_COMP_IsActiveComparator2(COMP_COMMON))
    {
        LL_COMP_ClearFlag_Comparator2(COMP_COMMON);    //清除COMP2中断标志
        
        if(SET == LL_COMP_GetComparatorOutput(COMP2))    //比较器2 V+电压高于V-
        {
            LED0_ON();
        }
        else                                //比较器2 V+电压低于V-
        {
            LED0_OFF();
        }
    }
}

//比较器引脚配置
void COMP_IO_Init(void)
{
LL_GPIO_InitTypeDef    GPIO_InitStruct;

//以下没有用到的引脚，就注释掉
    //COMP1引脚    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_4;//COMP1_INP1
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOD,&GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_5;//COMP1_INP2
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOD,&GPIO_InitStruct);    

    GPIO_InitStruct.Pin = LL_GPIO_PIN_10;//COMP1_INN1
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOA,&GPIO_InitStruct);

    //COMP1输出    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_11;//COMP1_OUT
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOD,&GPIO_InitStruct);        

    //COMP2
    GPIO_InitStruct.Pin = LL_GPIO_PIN_4;//COMP2_INN1
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOA,&GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_5;//COMP2_INN2
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOA,&GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_8;//COMP2_INP1
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOA,&GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_9;//COMP2_INP2
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOA,&GPIO_InitStruct);    

    //COMP2输出    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_12;//COMP2_OUT
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOB,&GPIO_InitStruct);    
}

//比较器1寄存器初始化
void COMP1_Init(void)
{
LL_COMP_InitTypeDef COMP_InitStruct;
    
    //如果与内部VREF、1/2VREF比较。需打开VREF，如果引脚间比较就不需要打开VREF
    //VREF与VREF_BUFF 约4uA
    LL_VREF_EnableVREF(VREF);//打开1.22V
    LL_OPA_EnableVrefBuffer(OPA1);//使能
    LL_OPA_DisableByPassVrefBuffer(OPA1);//不bypass
    LL_OPA_SetNegtiveInputChannel(OPA1, LL_OPA_NEGTIVE_INPUT_CHANNEL_OPA_VREF);

    COMP_InitStruct.Edge             = LL_COMP_COMPARATOR_INTERRUPT_EDGE_BOTH;//中断沿
    COMP_InitStruct.Polarity         = LL_COMP_COMPARAROT_OUTPUT_POLARITY_NORMAL;//正常极性
    COMP_InitStruct.NegativeInput    = LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF;//INN
    COMP_InitStruct.PositiveInput    = LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP2;//INP
    COMP_InitStruct.DigitalFilter    = DISABLE;//不滤波
    LL_COMP_Init(COMP1, &COMP_InitStruct);

    LL_COMP_EnableITComper1(COMP_COMMON);//1：允许中断
    /*NVIC中断配置*/
    NVIC_DisableIRQ(COMPx_IRQn);
    NVIC_SetPriority(COMPx_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(COMPx_IRQn);    
    LL_COMP_Enable(COMP1);//使能比较器1
}

//比较器2寄存器初始化
void COMP2_Init(void)
{
LL_COMP_InitTypeDef COMP_InitStruct;
    
    //如果与内部VREF、1/2VREF比较。需打开VREF，如果引脚间比较就不需要打开VREF
    //VREF与VREF_BUFF 约4uA
    LL_VREF_EnableVREF(VREF);//打开1.22V
    LL_OPA_EnableVrefBuffer(OPA1);//使能
    LL_OPA_DisableByPassVrefBuffer(OPA1);//不bypass
    LL_OPA_SetNegtiveInputChannel(OPA2, LL_OPA_NEGTIVE_INPUT_CHANNEL_OPA_VREF);

    COMP_InitStruct.Edge             = LL_COMP_COMPARATOR_INTERRUPT_EDGE_BOTH;//中断沿
    COMP_InitStruct.Polarity         = LL_COMP_COMPARAROT_OUTPUT_POLARITY_NORMAL;//正常极性
    COMP_InitStruct.NegativeInput    = LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_COMP_INN1;//INN
    COMP_InitStruct.PositiveInput    = LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP1;//INP
    COMP_InitStruct.DigitalFilter    = DISABLE;//不滤波
    LL_COMP_Init(COMP2, &COMP_InitStruct);

    LL_COMP_EnableITComper2(COMP_COMMON);//1：允许中断
    /*NVIC中断配置*/
    NVIC_DisableIRQ(COMPx_IRQn);
    NVIC_SetPriority(COMPx_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(COMPx_IRQn);        
    LL_COMP_Enable(COMP2);//使能比较器2
}


