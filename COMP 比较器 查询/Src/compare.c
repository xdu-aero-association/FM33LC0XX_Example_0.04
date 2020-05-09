#include "user_init.h"
#include "compare.h"

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
    LL_VREF_EnableVREF(VREF);//打开1.22V
    LL_OPA_EnableVrefBuffer(OPA1);//使能
    LL_OPA_DisableByPassVrefBuffer(OPA1);//不bypass
    LL_OPA_SetNegtiveInputChannel(OPA1, LL_OPA_NEGTIVE_INPUT_CHANNEL_OPA_VREF);

    COMP_InitStruct.Edge             = LL_COMP_COMPARATOR_INTERRUPT_EDGE_BOTH;//中断沿
    COMP_InitStruct.Polarity         = LL_COMP_COMPARAROT_OUTPUT_POLARITY_NORMAL;//正常极性
    COMP_InitStruct.NegativeInput    = LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF_DIV_2;//INN
    COMP_InitStruct.PositiveInput    = LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP2;//INP
    COMP_InitStruct.DigitalFilter    = ENABLE;//滤波
    LL_COMP_Init(COMP1, &COMP_InitStruct);

    LL_COMP_DisableITComper1(COMP_COMMON);//0：禁止中断     
    LL_COMP_Enable(COMP1);//使能比较器1
}

//比较器2寄存器初始化
void COMP2_Init(void)
{
LL_COMP_InitTypeDef COMP_InitStruct;
    
    //如果与内部VREF、1/2VREF比较。需打开VREF，如果引脚间比较就不需要打开VREF
    LL_VREF_EnableVREF(VREF);//打开1.22V
    LL_OPA_EnableVrefBuffer(OPA1);//使能
    LL_OPA_DisableByPassVrefBuffer(OPA1);//不bypass
    LL_OPA_SetNegtiveInputChannel(OPA2, LL_OPA_NEGTIVE_INPUT_CHANNEL_OPA_VREF);

    COMP_InitStruct.Edge             = LL_COMP_COMPARATOR_INTERRUPT_EDGE_BOTH;//中断沿
    COMP_InitStruct.Polarity         = LL_COMP_COMPARAROT_OUTPUT_POLARITY_NORMAL;//正常极性
    COMP_InitStruct.NegativeInput    = LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF_DIV_2;//INN
    COMP_InitStruct.PositiveInput    = LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP1;//INP
    COMP_InitStruct.DigitalFilter    = ENABLE;//滤波
    LL_COMP_Init(COMP2, &COMP_InitStruct);

    LL_COMP_DisableITComper2(COMP_COMMON);//0：禁止中断     
    LL_COMP_Enable(COMP2);//使能比较器2
}


