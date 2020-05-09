#include "user_init.h"
#include "main.h"
#include "wkup.h"

void NMI_Handler(void)
{
    //NWKUP默认连接到了cpu的NMI不可屏蔽中断，不受NVIC控制，不受全局中断使能控制，唤醒后必然进NMI中断
    if( SET == LL_PMU_IsActiveFlag_WakeupPIN(PMU , LL_PMU_WKUP0PIN) )
    {    
        LL_PMU_ClearFlag_WakeupPIN(PMU , LL_PMU_WKUP0PIN);
    }
//    if( SET == LL_PMU_IsActiveFlag_WakeupPIN(PMU , LL_PMU_WKUP1PIN) )
//    {    
//        LL_PMU_ClearFlag_WakeupPIN(PMU , LL_PMU_WKUP1PIN);
//    }
//    if( SET == LL_PMU_IsActiveFlag_WakeupPIN(PMU , LL_PMU_WKUP2PIN) )
//    {    
//        LL_PMU_ClearFlag_WakeupPIN(PMU , LL_PMU_WKUP2PIN);
//    }
//    if( SET == LL_PMU_IsActiveFlag_WakeupPIN(PMU , LL_PMU_WKUP3PIN) )
//    {    
//        LL_PMU_ClearFlag_WakeupPIN(PMU , LL_PMU_WKUP3PIN);
//    }
//    if( SET == LL_PMU_IsActiveFlag_WakeupPIN(PMU , LL_PMU_WKUP4PIN) )
//    {    
//        LL_PMU_ClearFlag_WakeupPIN(PMU , LL_PMU_WKUP4PIN);
//    }
//    if( SET == LL_PMU_IsActiveFlag_WakeupPIN(PMU , LL_PMU_WKUP5PIN) )
//    {    
//        LL_PMU_ClearFlag_WakeupPIN(PMU , LL_PMU_WKUP5PIN);
//    }
//    if( SET == LL_PMU_IsActiveFlag_WakeupPIN(PMU , LL_PMU_WKUP6PIN) )
//    {    
//        LL_PMU_ClearFlag_WakeupPIN(PMU , LL_PMU_WKUP6PIN);
//    }
//    if( SET == LL_PMU_IsActiveFlag_WakeupPIN(PMU , LL_PMU_WKUP7PIN) )
//    {    
//        LL_PMU_ClearFlag_WakeupPIN(PMU , LL_PMU_WKUP7PIN);
//    }    
}

// WKUP引脚中断初始化
void WKUP_init(void)
{
LL_GPIO_InitTypeDef GPIO_InitStruct = {0};    

    //WKUP0
    //PA15设为输入 
    GPIO_InitStruct.Pin = LL_GPIO_PIN_15;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    //WKUP 使能
    LL_GPIO_SetWkupEntry(GPIO_COMMON, LL_GPIO_WKUP_INT_ENTRY_NMI);//NMI中断入口
    LL_GPIO_SetWkupPolarity(GPIO_COMMON, LL_GPIO_WKUP_0, LL_GPIO_WKUP_POLARITY_FALLING);//下降沿唤醒
    LL_GPIO_EnableWkup(GPIO_COMMON, LL_GPIO_WKUP_0);//使能NWKUP功能
    
//    //WKUP1
//    //PA10设为输入 
//    GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
//    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
//    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
//    GPIO_InitStruct.Pull = DISABLE;
//    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//    //WKUP 使能
//    LL_GPIO_SetWkupEntry(GPIO_COMMON, LL_GPIO_WKUP_INT_ENTRY_NMI);//NMI中断入口
//    LL_GPIO_SetWkupPolarity(GPIO_COMMON, LL_GPIO_WKUP_1, LL_GPIO_WKUP_POLARITY_FALLING);//下降沿唤醒
//    LL_GPIO_EnableWkup(GPIO_COMMON, LL_GPIO_WKUP_1);//使能NWKUP功能    
    
//    //WKUP2
//    //PB2设为输入 
//    GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
//    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
//    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
//    GPIO_InitStruct.Pull = DISABLE;
//    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//    //WKUP 使能
//    LL_GPIO_SetWkupEntry(GPIO_COMMON, LL_GPIO_WKUP_INT_ENTRY_NMI);//NMI中断入口
//    LL_GPIO_SetWkupPolarity(GPIO_COMMON, LL_GPIO_WKUP_2, LL_GPIO_WKUP_POLARITY_FALLING);//下降沿唤醒
//    LL_GPIO_EnableWkup(GPIO_COMMON, LL_GPIO_WKUP_2);//使能NWKUP功能    

//    //WKUP3
//    //PB12设为输入 
//    GPIO_InitStruct.Pin = LL_GPIO_PIN_12;
//    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
//    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
//    GPIO_InitStruct.Pull = DISABLE;
//    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//    //WKUP 使能
//    LL_GPIO_SetWkupEntry(GPIO_COMMON, LL_GPIO_WKUP_INT_ENTRY_NMI);//NMI中断入口
//    LL_GPIO_SetWkupPolarity(GPIO_COMMON, LL_GPIO_WKUP_3, LL_GPIO_WKUP_POLARITY_FALLING);//下降沿唤醒
//    LL_GPIO_EnableWkup(GPIO_COMMON, LL_GPIO_WKUP_3);//使能NWKUP功能    
    
//    //WKUP4
//    //PC6设为输入 
//    GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
//    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
//    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
//    GPIO_InitStruct.Pull = DISABLE;
//    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
//    //WKUP 使能
//    LL_GPIO_SetWkupEntry(GPIO_COMMON, LL_GPIO_WKUP_INT_ENTRY_NMI);//NMI中断入口
//    LL_GPIO_SetWkupPolarity(GPIO_COMMON, LL_GPIO_WKUP_4, LL_GPIO_WKUP_POLARITY_FALLING);//下降沿唤醒
//    LL_GPIO_EnableWkup(GPIO_COMMON, LL_GPIO_WKUP_4);//使能NWKUP功能        
    
//    //WKUP5
//    //PC10设为输入 
//    GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
//    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
//    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
//    GPIO_InitStruct.Pull = DISABLE;
//    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
//    //WKUP 使能
//    LL_GPIO_SetWkupEntry(GPIO_COMMON, LL_GPIO_WKUP_INT_ENTRY_NMI);//NMI中断入口
//    LL_GPIO_SetWkupPolarity(GPIO_COMMON, LL_GPIO_WKUP_5, LL_GPIO_WKUP_POLARITY_FALLING);//下降沿唤醒
//    LL_GPIO_EnableWkup(GPIO_COMMON, LL_GPIO_WKUP_5);//使能NWKUP功能    

//    //WKUP6
//    //PD11设为输入 
//    GPIO_InitStruct.Pin = LL_GPIO_PIN_11;
//    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
//    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
//    GPIO_InitStruct.Pull = DISABLE;
//    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
//    //WKUP 使能
//    LL_GPIO_SetWkupEntry(GPIO_COMMON, LL_GPIO_WKUP_INT_ENTRY_NMI);//NMI中断入口
//    LL_GPIO_SetWkupPolarity(GPIO_COMMON, LL_GPIO_WKUP_6, LL_GPIO_WKUP_POLARITY_FALLING);//下降沿唤醒
//    LL_GPIO_EnableWkup(GPIO_COMMON, LL_GPIO_WKUP_6);//使能NWKUP功能    
    
//    //WKUP7
//    //PD6设为输入 
//    GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
//    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
//    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
//    GPIO_InitStruct.Pull = DISABLE;
//    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
//    //WKUP 使能
//    LL_GPIO_SetWkupEntry(GPIO_COMMON, LL_GPIO_WKUP_INT_ENTRY_NMI);//NMI中断入口
//    LL_GPIO_SetWkupPolarity(GPIO_COMMON, LL_GPIO_WKUP_7, LL_GPIO_WKUP_POLARITY_FALLING);//下降沿唤醒
//    LL_GPIO_EnableWkup(GPIO_COMMON, LL_GPIO_WKUP_7);//使能NWKUP功能    

}


/*
//以下是wkup使用38号中断入口进行中断 只列举了wkup0 ，wkup1~7请参照上面NMI中断自己加
void WKUP_IRQHandler(void)
{
    if( SET == LL_PMU_IsActiveFlag_WakeupPIN(PMU , LL_PMU_WKUP0PIN) )
    {    
        LL_PMU_ClearFlag_WakeupPIN(PMU , LL_PMU_WKUP0PIN);
    }
}

// 外部引脚中断初始化
void WKUP_init(void)
{
LL_GPIO_InitTypeDef GPIO_InitStruct = {0};    

    //WKUP0
    //PA15设为输入 
    GPIO_InitStruct.Pin = LL_GPIO_PIN_15;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = DISABLE;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    //WKUP 使能
    LL_GPIO_SetWkupEntry(GPIO_COMMON, LL_GPIO_WKUP_INT_ENTRY_NUM_38);//NMI中断入口
    LL_GPIO_SetWkupPolarity(GPIO_COMMON, LL_GPIO_WKUP_0, LL_GPIO_WKUP_POLARITY_FALLING);//下降沿唤醒

	//NVIC中断配置
	NVIC_DisableIRQ(WKUP_IRQn);
	NVIC_SetPriority(WKUP_IRQn,2);//中断优先级配置
	NVIC_EnableIRQ(WKUP_IRQn);	

    //使能NWKUP功能
    LL_GPIO_EnableWkup(GPIO_COMMON, LL_GPIO_WKUP_0);
}
*/
