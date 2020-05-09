/**
  ****************************************************************************************************
  * @file    fm33lc0xx_ll_lptim.c
  * @author  FMSH Application Team
  * @brief   Src file of LPTIM LL Module
  ****************************************************************************************************
  * @attention
  *
  * Copyright (c) [2019] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under the Mulan PSL v1.
  * can use this software according to the terms and conditions of the Mulan PSL v1.
  * You may obtain a copy of Mulan PSL v1 at:
  * http://license.coscl.org.cn/MulanPSL
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
  * PURPOSE.
  * See the Mulan PSL v1 for more details.
  *
  ****************************************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "fm33lc0xx_ll_rcc.h"
#include "fm33lc0xx_ll_lptim.h"
#include "fm33_assert.h"

/** @addtogroup FM33LC0xx_LL_Driver_LPTIM
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup LPTIME_LL_Private_Macros
  * @{
  */

#define         IS_LPTIM_INSTANCE(INSTANCE)                          (((INSTANCE) == LPTIM))
                                                             
#define         IS_LL_LPTIM_OPERATION_CLOCKSOURCE(__VALUE__)            (((__VALUE__) == LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_APBCLK1)||\
                                                                         ((__VALUE__) == LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_LSCLK)||\
                                                                         ((__VALUE__) == LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_RCLP)||\
                                                                         ((__VALUE__) == LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_RC4M_PSC))

#define         IS_LL_LPTIM_PRESCALER_CLOCLSOURCE(__VALUE__)            (((__VALUE__) == LL_LPTIM_PRESCALER_INPUT_LPTIM_CLK)||\
                                                                         ((__VALUE__) == LL_LPTIM_PRESCALER_INPUT_LPTIM_INPUT))                                                             
                                                         
#define         IS_LL_LPTIM_PRESCALER(__VALUE__)                        (((__VALUE__) == LL_LPTIM_CLOCKDIVISION_DIV1)||\
                                                                         ((__VALUE__) == LL_LPTIM_CLOCKDIVISION_DIV2)||\
                                                                         ((__VALUE__) == LL_LPTIM_CLOCKDIVISION_DIV4)||\
                                                                         ((__VALUE__) == LL_LPTIM_CLOCKDIVISION_DIV8)||\
                                                                         ((__VALUE__) == LL_LPTIM_CLOCKDIVISION_DIV16)||\
                                                                         ((__VALUE__) == LL_LPTIM_CLOCKDIVISION_DIV32)||\
                                                                         ((__VALUE__) == LL_LPTIM_CLOCKDIVISION_DIV64)||\
                                                                         ((__VALUE__) == LL_LPTIM_CLOCKDIVISION_DIV128))
                                                      
#define         IS_LL_LPTIM_MODE(__VALUE__)                             (((__VALUE__) == LL_LPTIM_OPERATION_MODE_NORMAL)||\
                                                                         ((__VALUE__) == LL_LPTIM_OPERATION_MODE_TRIGGER_CNT)||\
                                                                         ((__VALUE__) == LL_LPTIM_OPERATION_MODE_TIMEOUT)||\
                                                                         ((__VALUE__) == LL_LPTIM_OPERATION_MODE_EXTERNAL_ASYN_PULSE_CNT))
                                                             
#define         IS_LL_LPTIM_TRIGEER_POLARITY(__VALUE__)                 (((__VALUE__) == LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_RINSING)||\
                                                                         ((__VALUE__) == LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_FALLING)||\
                                                                         ((__VALUE__) == LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_BOTHEDGE))
                                                             
#define         IS_LL_LPTIM_ONESTATE(__VALUE__)                         (((__VALUE__) == LL_LPTIM_ONE_STATE_TIMER_CONTINUE)||\
                                                                         ((__VALUE__) == LL_LPTIM_ONE_STATE_TIMER_SINGLE)) 
                                                             
#define         IS_LL_LPTIM_COUNT_POLARITY(__VALUE__)                   (((__VALUE__) == LL_LPTIM_EXTERNAL_INPUT_COUNT_POLARITY_RISING)||\
                                                                         ((__VALUE__) == LL_LPTIM_EXTERNAL_INPUT_COUNT_POLARITY_FALLING))
                                                                                                                     
                                                             
#define         IS_LL_LPTIM_ICPOLARITY(__VALUE__)                       (((__VALUE__) == LL_LPTIM_IC_POLARITY_EDGE_RISING)||\
                                                                         ((__VALUE__) == LL_LPTIM_IC_POLARITY_EDGE_FALLING)||\
                                                                         ((__VALUE__) == LL_LPTIM_IC_POLARITY_EDGE_BOTHEDGE))  

#define         IS_LL_LPTIM_OCPOLARITY(__VALUE__)                       (((__VALUE__) == LL_LPTIM_OC_POLARITY_LOW_TO_HIGH)||\
                                                                         ((__VALUE__) == LL_LPTIM_OC_POLARITY_HIGH_TO_LOW))
                                                             
/**
  * @}
  */
  
/** @addtogroup LPTIM_LL_EF_Init
  * @{
  */
/**
  * @brief	复位LPTIM 外设
  * @param	外设入口地址
  * @retval	返回错误状态，可能值：
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_LPTIM_DeInit(LPTIM_Type *LPTIMx)
{
    ErrorStatus status = FAIL;
    
	assert_param(IS_LPTIM_INSTANCE(LPTIMx));
	/* 使能外设复位 */
	LL_RCC_EnablePeripheralReset();
    
    /*复位LPTIM*/
    LL_RCC_EnableResetAPB1Peripheral(LL_RCC_APB1_PERIPHERAL_RST_LPTIM);
    LL_RCC_DisableResetAPB1Peripheral(LL_RCC_APB1_PERIPHERAL_RST_LPTIM);
    /* 关闭外设总线时钟和工作时钟 */
	LL_RCC_Group1_DisableBusClock(LL_RCC_BUS1_CLOCK_LPTIM);
	LL_RCC_Group2_DisableOperationClock(LL_RCC_OPERATION2_CLOCK_LPTIM);
    /* 锁定外设复位功能 */
    LL_RCC_DisablePeripheralReset();
    
    status = PASS;
    return status;
}
/**
  * @brief	根据需要功能配置LPTIM寄存器使之工作的定时器功能模式下 
  *         
  * @note 	其中LL_LPTIM_OPERATION_MODE_EXTERNAL_ASYN_PAUSE_CNT 模式需要外部脉冲提供给LPTIM模块作为工作时钟，此时
  *      	LPTIM完全工作在异步模式下。      
  * @param	LPTIM  外设入口地址
  * @param 	LPTIM_InitStruct向一LL_LPTIM_TimeInitTypeDef结构体，它包含指定LPTIM外设的配置信息	  
  *         
  * @retval	ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功        
  */
ErrorStatus LL_LPTIM_TimeModeInit(LPTIM_Type *LPTIMx, LL_LPTIM_TimeInitTypeDef *LPTIM_InitStruct)
{
    ErrorStatus status = PASS;
	/* 检查入口参数 */
	assert_param(IS_LPTIM_INSTANCE(LPTIMx));
    assert_param(IS_LL_LPTIM_OPERATION_CLOCKSOURCE(LPTIM_InitStruct->ClockSource));
    assert_param(IS_LL_LPTIM_PRESCALER_CLOCLSOURCE(LPTIM_InitStruct->PrescalerClockSource));
    assert_param(IS_LL_LPTIM_PRESCALER(LPTIM_InitStruct->Prescaler));
    assert_param(IS_LL_LPTIM_MODE(LPTIM_InitStruct->Mode));
    assert_param(IS_LL_LPTIM_TRIGEER_POLARITY(LPTIM_InitStruct->TriggerPolarity));
    assert_param(IS_LL_LPTIM_ONESTATE(LPTIM_InitStruct->OneState));
    assert_param(IS_LL_LPTIM_COUNT_POLARITY(LPTIM_InitStruct->CountPolarity));
    /* 使能总线时钟 */
	LL_RCC_Group1_EnableBusClock(LL_RCC_BUS1_CLOCK_LPTIM);
    /* 使能操作时钟 */
	LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_LPTIM);
    /* 配置分频器的时钟源 */
	LL_LPTIM_SetPrescalerInput(LPTIMx,LPTIM_InitStruct->PrescalerClockSource);
    /* 配置时钟分频 */
	LL_LPTIM_SetColckDivision(LPTIMx,LPTIM_InitStruct->Prescaler);
    /* 配置定时器工作模式 */
	LL_LPTIM_SetOperationMode(LPTIMx,LPTIM_InitStruct->Mode);
    /* 单次计数模式 */
    LL_LPTIM_Set_OneStateTimer(LPTIMx,LPTIM_InitStruct->OneState);
    
	/* 配置定时器不同模式下的特殊寄存器 */
	switch(LPTIM_InitStruct->Mode)
	{
        case LL_LPTIM_OPERATION_MODE_NORMAL:
            /* 配置时钟源 */
            LL_RCC_SetLPTIMClockSource(LPTIM_InitStruct->ClockSource);
			break;
		case LL_LPTIM_OPERATION_MODE_TRIGGER_CNT:
            /* 配置时钟源 */
            LL_RCC_SetLPTIMClockSource(LPTIM_InitStruct->ClockSource);
            /* 配置外部触发边沿 */
			LL_LPTIM_SetTriggerExternalInput(LPTIMx,LPTIM_InitStruct->TriggerPolarity);
			break;
             
		case LL_LPTIM_OPERATION_MODE_EXTERNAL_ASYN_PULSE_CNT:
            /* 配置外部计数边沿 */
			LL_LPTIM_SetPolarityExternalInput(LPTIMx,LPTIM_InitStruct->CountPolarity);
            /* 开启外部输入滤波 */
			LL_LPTIM_EnableExternalTriggerAnalogFilter(LPTIMx);
			break;
		case LL_LPTIM_OPERATION_MODE_TIMEOUT:
            /* 配置外部输入有效边沿 */
			LL_LPTIM_SetTriggerExternalInput(LPTIMx,LPTIM_InitStruct->TriggerPolarity);
			break;
        default:status = FAIL;
            break;
	}
    return status;
}
/**
  * @brief	设置 LPTIM_InitStruct 为默认配置
  * @param 	LPTIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_LPTIM_TimeInitTypeDef 结构体 
  *         
  * @retval	None
  */
void LL_LPTIM_TimeModeStructInit(LL_LPTIM_TimeInitTypeDef *LPTIM_InitStruct)
{
	
	LPTIM_InitStruct->ClockSource = LL_RCC_LPTIM_OPERATION_CLOCK_SOURCE_APBCLK1;

	LPTIM_InitStruct->PrescalerClockSource = LL_LPTIM_PRESCALER_INPUT_LPTIM_CLK; 

	LPTIM_InitStruct->Prescaler = LL_LPTIM_CLOCKDIVISION_DIV1;      

	LPTIM_InitStruct->Mode = LL_LPTIM_OPERATION_MODE_NORMAL;

	LPTIM_InitStruct->OneState = LL_LPTIM_ONE_STATE_TIMER_CONTINUE;

	LPTIM_InitStruct->TriggerPolarity = LL_LPTIM_EXTERNAL_INPUT_TRIGGER_POLARITY_RINSING; 
    
    LPTIM_InitStruct->CountPolarity = LL_LPTIM_EXTERNAL_INPUT_COUNT_POLARITY_RISING;
}

/**
  * @brief	根据需要功能配置LPTIM寄存器工作在输入捕获/输出比较模式 
  *         
  * @note 	用户需要自行选择对应通道的输入映射到那里具体接口
  *        
  * @param	LPTIMx  外设入口地址
* @param 	LPTIM_InitStruct 为 @ref LL_TIM_IC_InitTypeDef结构体，它包含指定LPTIM外设的配置信息	  
  * @param 	Channel 指定LPTIM 输入\输出通道
  *
  * @retval	ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功        
  */
ErrorStatus LL_LPTIM_IC_ModeInit(LPTIM_Type *LPTIMx, uint32_t Channel ,LL_TIM_IC_InitTypeDef *LPTIM_InitStruct)
{
    ErrorStatus status = PASS;
	/* 入口参数检查 */
	assert_param(IS_LPTIM_INSTANCE(LPTIMx));
    assert_param(IS_LL_LPTIM_ICPOLARITY(LPTIM_InitStruct->ICPolarity));
    assert_param(IS_LL_LPTIM_OCPOLARITY(LPTIM_InitStruct->ICSource));
	/* 总线时钟使能 */
	LL_RCC_Group1_EnableBusClock(LL_RCC_BUS1_CLOCK_LPTIM);
    /* 操作时钟使能 */
	LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_LPTIM);
    /* 通道配置 */
	if(Channel == LL_LPTIM_CHANNEL_1)
	{   /* 通道１工作模式配置 */
		LL_LPTIM_CC_Set_ModeChannel1(LPTIMx,LL_LPTIM_CC_MODE_CAPTURE);
        /* 通道１输入边沿极性配置 */
		LL_LPTIM_IC_SetPolarityChannel1(LPTIMx,LPTIM_InitStruct->ICPolarity);
        /* 通道１输出边沿极性配置 */
		LL_LPTIM_IC_SetCapctureSourceChannel1(LPTIMx,LPTIM_InitStruct->ICSource);
	}
    else if(Channel == LL_LPTIM_CHANNEL_2)
	{
        /* 通道2 工作模式配置 */
		LL_LPTIM_CC_Set_ModeChannel2(LPTIMx,LL_LPTIM_CC_MODE_CAPTURE);
        /* 通道２输入边沿极性配置 */
		LL_LPTIM_IC_SetPolarityChannel2(LPTIMx,LPTIM_InitStruct->ICPolarity);
       /* 通道2 输出边沿极性配置 */
		LL_LPTIM_IC_SetCapctureSourceChannel2(LPTIMx,LPTIM_InitStruct->ICSource);
	}
    else
    {
        status = FAIL;
    }
   return status;
}
/**
  * @brief	设置 LPTIM_InitStruct 为默认配置
  * @param 	LPTIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_TIM_IC_InitTypeDef 结构体 
  *         
  * @retval	None
  */
void LL_LPTIM_ICModeStructInit(LL_TIM_IC_InitTypeDef *LPTIM_InitStruct)
{      
	LPTIM_InitStruct->ICPolarity = LL_LPTIM_IC_POLARITY_EDGE_RISING;       
	LPTIM_InitStruct->ICSource  = LL_LPTIM_IC1_CAPCTURE_SOURCE_CHANNEL1 ;
}

/**
  * @brief	根据需要功能配置LPTIM寄存器工作在输入捕获/输出比较模式 
  *         
  * @note 	用户需要自行选择对应通道的输入映射到那里具体接口
  *        
  * @param	LPTIMx  外设入口地址
* @param 	LPTIM_InitStruct 为 @ref LL_TIM_OC_InitTypeDef结构体，它包含指定LPTIM外设的配置信息	  
  * @param 	Channel 指定LPTIM 输入\输出通道
  *
  * @retval	ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功        
  */
ErrorStatus LL_LPTIM_OC_ModeInit(LPTIM_Type *LPTIMx,uint32_t Channel, LL_TIM_OC_InitTypeDef *LPTIM_InitStruct)
{
    ErrorStatus status = PASS;
	/* 入口参数检查 */
	assert_param(IS_LPTIM_INSTANCE(LPTIMx));
    assert_param(IS_LL_LPTIM_OCPOLARITY(LPTIM_InitStruct->OCPolarity));
	/* 总线时钟使能 */
	LL_RCC_Group1_EnableBusClock(LL_RCC_BUS1_CLOCK_LPTIM);
    /* 操作时钟使能 */
	LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_LPTIM);
    /* 自动重装载值 */
    LL_LPTIM_SetAutoReload(LPTIMx,LPTIM_InitStruct->OC_Arr);
    /* 通道配置 */
	if(Channel == LL_LPTIM_CHANNEL_1)
	{   /* 通道１工作模式配置 */
		LL_LPTIM_CC_Set_ModeChannel1(LPTIMx,LL_LPTIM_CC_MODE_COMPARE);
        /* 通道１输出边沿极性配置 */
		LL_LPTIM_OC_SetPolarityChannel1(LPTIMx,LPTIM_InitStruct->OCPolarity);
        /* 比较载值 */
        LL_LPTIM_OC_SetCompareCH1(LPTIMx,LPTIM_InitStruct->OC_Ccr);

	}
    else if(Channel == LL_LPTIM_CHANNEL_2)
	{
        /* 通道２工作模式配置 */
		LL_LPTIM_CC_Set_ModeChannel2(LPTIMx,LL_LPTIM_CC_MODE_COMPARE);
        /* 通道２输出边沿极性配置 */
		LL_LPTIM_OC_SetPolarityChannel2(LPTIMx,LPTIM_InitStruct->OCPolarity);
        /* 比较载值 */
        LL_LPTIM_OC_SetCompareCH2(LPTIMx,LPTIM_InitStruct->OC_Ccr);
	}
    else
    {
        status = FAIL;
    }
   return status;
}
/**
  * @brief	设置 LPTIM_InitStruct 为默认配置
  * @param 	LPTIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_TIM_OC_InitTypeDef 结构体 
  *         
  * @retval	None
  */
void LL_LPTIM_OCModeStructInit(LL_TIM_OC_InitTypeDef *LPTIM_InitStruct)
{
    LPTIM_InitStruct->OC_Arr     = 0;
    LPTIM_InitStruct->OC_Ccr     = 0;
	LPTIM_InitStruct->OCPolarity = LL_LPTIM_OC_POLARITY_LOW_TO_HIGH ;
}
/**
  * @}
  */

/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/

