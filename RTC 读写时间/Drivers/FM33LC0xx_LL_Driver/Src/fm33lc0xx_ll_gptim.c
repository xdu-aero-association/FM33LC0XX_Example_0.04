/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_gptim.c
  * @author  FMSH Application Team
  * @brief   Src file of GPTIM LL Module
  *******************************************************************************************************
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
  *******************************************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "fm33lc0xx_ll_rcc.h"
#include "fm33lc0xx_ll_rmu.h"
#include "fm33lc0xx_ll_gptim.h"
#include "fm33_assert.h"

/** @addtogroup FM33LC0xx_LL_Driver_GPTIM
  * @{
  */
  
  
/** @addtogroup TIM_LL_Private_Macros
  * @{
  */


#define IS_GPTIM_INSTANCE(TIMx)                     (((TIMx) == GPTIM0) \
                                                        ||((TIMx) == GPTIM1))

#define IS_LL_GPTIM_COUNTERMODE(__VALUE__)          (((__VALUE__) == LL_GPTIM_COUNTER_DIRECT_UP) \
                                                       || ((__VALUE__) == LL_GPTIM_COUNTER_DIRECT_DOWN) \
                                                       || ((__VALUE__) == LL_GPTIM_COUNTER_ALIGNED_CENTER_DOWN   ) \
                                                       || ((__VALUE__) == LL_GPTIM_COUNTER_ALIGNED_CENTER_UP     ) \
                                                       || ((__VALUE__) == LL_GPTIM_COUNTER_ALIGNED_CENTER_UP_DOWN))

#define IS_LL_GPTIM_CLOCKDIVISION(__VALUE__)        (((__VALUE__) == LL_GPTIM_CLOCKDIVISION_DIV1) \
                                                     || ((__VALUE__) == LL_GPTIM_CLOCKDIVISION_DIV2) \
                                                     || ((__VALUE__) == LL_GPTIM_CLOCKDIVISION_DIV4))


#define IS_LL_GPTIM_CC_MODE(__VALUE__)               (((__VALUE__) ==   LL_GPTIM_CC_MODE_OUTPUT) \
                                                       ||((__VALUE__) == LL_GPTIM_CC1_MODE_INPUT_TI1) \
                                                       || ((__VALUE__) == LL_GPTIM_CC1_MODE_INPUT_TI2) \
                                                       || ((__VALUE__) == LL_GPTIM_CC2_MODE_INPUT_TI2) \
                                                       || ((__VALUE__) == LL_GPTIM_CC2_MODE_INPUT_TI1) \
                                                       || ((__VALUE__) == LL_GPTIM_CC3_MODE_INPUT_TI3) \
                                                       || ((__VALUE__) == LL_GPTIM_CC3_MODE_INPUT_TI4) \
                                                       || ((__VALUE__) == LL_GPTIM_CC4_MODE_INPUT_TI3) \
                                                       || ((__VALUE__) == LL_GPTIM_CC4_MODE_INPUT_TI4) \
                                                       || ((__VALUE__) == LL_GPTIM_CC_MODE_INPUT_TRC))
                                      
#define IS_LL_GPTIM_IC_FILTER(__VALUE__)            (((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV1) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV1_N2) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV1_N4) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV1_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV2_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV2_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV4_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV4_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV8_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV8_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV16_N5) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV16_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV16_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV32_N5) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV32_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_FILTER_FDIV32_N8))

#define IS_LL_GPTIM_CHANNEL(__VALUE__)              (((__VALUE__) == LL_GPTIM_CHANNEL_1)\
                                                    || ((__VALUE__) == LL_GPTIM_CHANNEL_2)\
                                                    || ((__VALUE__) == LL_GPTIM_CHANNEL_3)\
                                                    || ((__VALUE__) == LL_GPTIM_CHANNEL_4))
                                        
                                        
                                        
#define IS_LL_GPTIM_SLAVE_MODE(__VALUE__)           (((__VALUE__) == LL_GPTIM_SLAVE_MODE_PROHIBITED)\
                                                    || ((__VALUE__) == LL_GPTIM_SLAVE_MODE_TI1FP1_TI2FP2_CNT)\
                                                    || ((__VALUE__) == LL_GPTIM_SLAVE_MODE_TI2FP2_TI1FP1_CNT)\
                                                    || ((__VALUE__) == LL_GPTIM_SLAVE_MODE_TI2FP2_CNT_TI1FP1_CNT)\
                                                    || ((__VALUE__) == LL_GPTIM_SLAVE_MODE_TRGI_RISE_RST)\
                                                    || ((__VALUE__) == LL_GPTIM_SLAVE_MODE_TRGI_HIGH_RUN)\
                                                    || ((__VALUE__) == LL_GPTIM_SLAVE_MODE_TRGI_RISE_RUN)\
                                                    || ((__VALUE__) == LL_GPTIM_SLAVE_MODE_TRGI_CLK))


#define IS_LL_GPTIM_TRIGGER_SRC(__VALUE__)          (((__VALUE__) ==LL_GPTIM_TIM_TS_ITR0 )\
                                                        ||((__VALUE__) ==LL_GPTIM_TIM_TS_ITR1 )\
                                                        ||((__VALUE__) ==LL_GPTIM_TIM_TS_ITR2)\
                                                        ||((__VALUE__) ==LL_GPTIM_TIM_TS_ITR3)\
                                                        ||((__VALUE__) ==LL_GPTIM_TIM_TS_TI1F_ED)\
                                                        ||((__VALUE__) ==LL_GPTIM_TIM_TS_TI1FP1)\
                                                        ||((__VALUE__) ==LL_GPTIM_TIM_TS_TI2FP1)\
                                                        ||((__VALUE__) ==LL_GPTIM_TIM_TS_ETRF))    



#define IS_LL_GPTIM_ETP_FILTER(__VALUE__)           (((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV1) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV1_N2) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV1_N4) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV1_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV2_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV2_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV4_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV4_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV8_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV8_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV16_N5) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV16_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV16_N8) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV32_N5) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV32_N6) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_FILTER_FDIV32_N8))


#define IS_LL_GPTIM_ETR_PSC(__VALUE__)               (((__VALUE__) == LL_GPTIM_ETR_PRESCALER_DIV1) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_PRESCALER_DIV2) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_PRESCALER_DIV4) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_PRESCALER_DIV8))
                                 
                                 

#define IS_LL_GPTIM_ETR_POLARITY(__VALUE__)         (((__VALUE__) == LL_GPTIM_ETR_POLARITY_NONINVERTED) \
                                                     || ((__VALUE__) == LL_GPTIM_ETR_POLARITY_NINVERTED)) 

                                   
#define IS_LL_GPTIM_OCPOLARITY(__VALUE__)           (((__VALUE__) == LL_GPTIM_OC_POLARITY_NOMAL) \
                                                    || ((__VALUE__) == LL_GPTIM_OC_POLARITY_REVERSE))
                                                    
#define IS_LL_GPTIM_IC_POLARITY(__VALUE__)          (((__VALUE__) == LL_GPTIM_IC_POLARITY_RISING) \
                                                       || ((__VALUE__) == LL_GPTIM_IC_POLARITY_FALLING))
    
                                       
 
#define IS_LL_GPTIM_IC_PRESCALER(__VALUE__)         (((__VALUE__) == LL_GPTIM_IC_PRESCALER_DIV_1) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_PRESCALER_DIV_2) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_PRESCALER_DIV_4) \
                                                     || ((__VALUE__) == LL_GPTIM_IC_PRESCALER_DIV_8))


#define IS_LL_GPTIM_IC_ACTIVEINPUT(__VALUE__)          (((__VALUE__) == LL_GPTIM_CC1_MODE_INPUT_TI1) \
                                                       || ((__VALUE__) == LL_GPTIM_CC1_MODE_INPUT_TI2) \
                                                       || ((__VALUE__) == LL_GPTIM_CC2_MODE_INPUT_TI2) \
                                                       || ((__VALUE__) == LL_GPTIM_CC2_MODE_INPUT_TI1) \
                                                       || ((__VALUE__) == LL_GPTIM_CC3_MODE_INPUT_TI3) \
                                                       || ((__VALUE__) == LL_GPTIM_CC3_MODE_INPUT_TI4) \
                                                       || ((__VALUE__) == LL_GPTIM_CC4_MODE_INPUT_TI3) \
                                                       || ((__VALUE__) == LL_GPTIM_CC4_MODE_INPUT_TI4) \
                                                       || ((__VALUE__) == LL_GPTIM_CC_MODE_INPUT_TRC))
                                                       
#define IS_LL_GPTIM_OC_POLARITY(__VALUE__)          (((__VALUE__) == LL_GPTIM_OC_POLARITY_NOMAL) \
                                                    || ((__VALUE__) == LL_GPTIM_OC_POLARITY_REVERSE))



#define IS_LL_GPTIM_OC_MODE(__VALUE__)               (((__VALUE__) ==   LL_GPTIM_OC_MODE_FROZEN) \
                                                      || ((__VALUE__) == LL_GPTIM_OC_MODE_ACTIVE) \
                                                      || ((__VALUE__) == LL_GPTIM_OC_MODE_INACTIVE) \
                                                      || ((__VALUE__) == LL_GPTIM_OC_MODE_TOGGLE) \
                                                      || ((__VALUE__) == LL_GPTIM_OC_MODE_FORCED_INACTIVE) \
                                                      || ((__VALUE__) == LL_GPTIM_OC_MODE_FORCED_ACTIVE) \
                                                      || ((__VALUE__) == LL_GPTIM_OC_MODE_PWM1) \
                                                      || ((__VALUE__) == LL_GPTIM_OC_MODE_PWM2))
                                                      
#define IS_LL_GPTIM_OC_FASTMODE(__VALUE__)          (((__VALUE__) == ENABLE) \
                                                    || ((__VALUE__) == DISABLE))

#define IS_LL_GPTIM_OC_PRELOAD(__VALUE__)           (((__VALUE__) == ENABLE) \
                                                    || ((__VALUE__) == DISABLE))
                                                    
#define IS_LL_GPTIM_OC_ETR_CLEARN(__VALUE__)        (((__VALUE__) == ENABLE) \
                                                    || ((__VALUE__) == DISABLE)) 
     

#define IS_LL_GPTIM_TRIGGER_DELAY(__VALUE__)       (((__VALUE__) == DISABLE) \
                                                    || ((__VALUE__) == ENABLE))
                                                        
                                                        
#define IS_LL_GPTIM_IC_CAPTURE_STATE(__VALUE__)    (((__VALUE__) == DISABLE) \
                                                     || ((__VALUE__) == ENABLE))                                                        
/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/
/** @defgroup TIM_LL_Private_Functions TIM Private Functions
  * @{
  */
static ErrorStatus  OCConfig(GPTIM_Type *TIMx, uint32_t Channel, LL_GPTIM_OC_InitTypeDef *TIM_OC_InitStruct );
static ErrorStatus  SetITRxInputSrc(GPTIM_Type *TIMx,uint32_t ITRx,uint32_t ITRx_Src);
/**
  * @}
  */

/** @addtogroup TIM_LL_EF_Init
  * @{
  */

/**
  * @brief  复位对应GPTIMx寄存器.
  * @param  GPTIMx 
  * @retval ErrorStatus枚举值:
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_GPTIM_DeInit(GPTIM_Type *TIMx)
{
    ErrorStatus result = PASS;

    /* Check the parameters */
    assert_param(IS_GPTIM_INSTANCE(TIMx));
    /* 使能外设复位 */
    LL_RCC_EnablePeripheralReset();
    if(TIMx == GPTIM0)
    {
        /* 使能外设复位 */
        LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB1_PERIPHERAL_RST_GTTIM0);
        LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB1_PERIPHERAL_RST_GTTIM0);
        /* 关闭外设时钟 */
        LL_RCC_Group4_DisableBusClock(LL_RCC_BUS4_CLOCK_GTIM0);
    }
    else if(TIMx == GPTIM1)
    {
        /* 使能外设复位 */
        LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB1_PERIPHERAL_RST_GTTIM1);
        LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB1_PERIPHERAL_RST_GTTIM1);
        /* 关闭外设时钟 */
        LL_RCC_Group4_DisableBusClock(LL_RCC_BUS4_CLOCK_GTIM1);
    }
    else
    {
        result = FAIL;
    }
    /* 锁定外设复位 */
    LL_RCC_DisablePeripheralReset();
    return result;
}
/**
  * @brief  配置基本定时器时基单元（内部时钟源）.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref LL_GPTIM_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus LL_GPTIM_Init(GPTIM_Type *TIMx, LL_GPTIM_InitTypeDef *TIM_InitStruct)
{

    /* 参数检查 */
    assert_param(IS_GPTIM_INSTANCE(TIMx));
    assert_param(IS_LL_GPTIM_COUNTERMODE(TIM_InitStruct->CounterMode));
    assert_param(IS_LL_GPTIM_CLOCKDIVISION(TIM_InitStruct->ClockDivision));
    /* 时钟总线使能配置 */
    if(TIMx == GPTIM0)
    {
        LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_GTIM0);
    }
    else
    {
        LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_GTIM1);
    }
    /* 计数器计数模式配置 */
    switch(TIM_InitStruct->CounterMode)
    {
        /* 中心对称模式 */
        case LL_GPTIM_COUNTER_ALIGNED_CENTER_DOWN   :   
        case LL_GPTIM_COUNTER_ALIGNED_CENTER_UP     : 
        case LL_GPTIM_COUNTER_ALIGNED_CENTER_UP_DOWN:
        LL_GPTIM_SetCounterAlignedMode(TIMx,TIM_InitStruct->CounterMode);
        break;
        default:
        /* 边沿模式 */
        LL_GPTIM_SetCounterDirection(TIMx,TIM_InitStruct->CounterMode);
        LL_GPTIM_SetCounterAlignedMode(TIMx,LL_GPTIM_COUNTER_ALIGNED_EDGE);
        break;
    }
    /* 自动重装载值 */
    LL_GPTIM_SetAutoReload(TIMx,TIM_InitStruct->Autoreload );
    /* 定时器分频系数与数字滤波器所使用的采样时钟分频比 */
    LL_GPTIM_SetClockDivision(TIMx,TIM_InitStruct->ClockDivision);
    /* 时钟分频 */
    LL_GPTIM_SetPrescaler(TIMx,TIM_InitStruct->Prescaler);
    /* 预装载配置 */
    if(TIM_InitStruct->AutoreloadState == ENABLE)
    {
        LL_GPTIM_EnableARRPreload(TIMx);
    }
    else
    {
        LL_GPTIM_DisableARRPreload(TIMx);
    }
    /* 手动触发更新事件，将配置值写入 */
    LL_GPTIM_GenerateEvent_UPDATE(TIMx);
    
    return PASS;
}

/**
  * @brief	设置 LL_GPTIM_InitTypeDef 为默认配置
  * @param 	TIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_GPTIM_InitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_GPTIM_StructInit(LL_GPTIM_InitTypeDef *TIM_InitStruct)
{
  /* Set the default configuration */
  TIM_InitStruct->Prescaler         = (uint16_t)0x0000;
  TIM_InitStruct->AutoreloadState   = DISABLE;
  TIM_InitStruct->CounterMode       = LL_GPTIM_COUNTER_DIRECT_UP;
  TIM_InitStruct->Autoreload        = 0xFFFFU;
  TIM_InitStruct->ClockDivision     = LL_GPTIM_CLOCKDIVISION_DIV1;
}

/**
  * @brief  配置基本定时器外部时钟源模式，包括编码器模式.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref LL_GPTIM_SlaveInitTypeDef 结构体 
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus LL_GPTIM_SlaveMode_Init(GPTIM_Type *TIMx, LL_GPTIM_SlaveInitTypeDef *TIM_InitStruct)
{

    
    /* 参数检查 */
    assert_param(IS_GPTIM_INSTANCE(TIMx)); 
    assert_param(IS_LL_GPTIM_SLAVE_MODE(TIM_InitStruct->SlaveMode));
    assert_param(IS_LL_GPTIM_TRIGGER_SRC(TIM_InitStruct->TriggerSrc));
    assert_param(IS_LL_GPTIM_TRIGGER_DELAY(TIM_InitStruct->TriggerDelay));
    /* 时钟总线使能配置 */
    if(TIMx == GPTIM0)
    {
        LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_GTIM0);
    }
    else
    {
        LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_GTIM1);
    }
    /* 触发延迟默认关闭 */
    LL_GPTIM_DisableMasterSlaveMode(TIMx);
    /* 关闭从模式以能写入TS */  
    LL_GPTIM_SetSlaveMode(TIMx,0);
    /* 从模式输入源选择 */
    LL_GPTIM_SetTriggerInput(TIMx,TIM_InitStruct->TriggerSrc);
    /* ITRx 输入源选择 */
    if(TIM_InitStruct->TriggerSrc <= LL_GPTIM_TIM_TS_ITR3)
    {
        /* 内部触发ITRx源选择 */
        SetITRxInputSrc(TIMx,TIM_InitStruct->TriggerSrc,TIM_InitStruct->ITRxSrc);
    }
    /* 从模式选择 */
    LL_GPTIM_SetSlaveMode(TIMx,TIM_InitStruct->SlaveMode);
    /* 触发延迟默认关闭 */
    if(TIM_InitStruct->TriggerDelay == ENABLE)
    {
        LL_GPTIM_EnableMasterSlaveMode(TIMx);
    }
    /* 手动触发更新事件，将配置值写入 */
    LL_GPTIM_GenerateEvent_UPDATE(TIMx);
    return PASS;
}
/**
  * @brief	设置 内部触发源选择配置
  * @param  TIMx Timer Instance
  * @param 	ITRx 内部触发信号源  
  * @param 	ITRx_的源选择不同的ITRx对应的源完全不同，参考芯片手册.
  * @retval	None
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
static ErrorStatus SetITRxInputSrc(GPTIM_Type *TIMx,uint32_t ITRx,uint32_t ITRx_Src)
{
    ErrorStatus result = PASS;
    /* 不同的ITRx对应的输入源不同，这里加以区分*/
    if(TIMx == GPTIM0)
    {
        /* 配置ITRx源 */
        switch(ITRx)
        {
            case LL_GPTIM_TIM_TS_ITR0:
                LL_GPTIM_SetGPTIM0ITR0Input(TIMx,ITRx_Src);
                break;
            case LL_GPTIM_TIM_TS_ITR1:
                LL_GPTIM_SetGPTIM0ITR1Input(TIMx,ITRx_Src);
                break;
            case LL_GPTIM_TIM_TS_ITR2:
                LL_GPTIM_SetGPTIM0ITR2Input(TIMx,ITRx_Src);
                break;
            case LL_GPTIM_TIM_TS_ITR3:
                LL_GPTIM_SetGPTIM0ITR3Input(TIMx,ITRx_Src);
                break;
            default:
                result = FAIL;
                break;
        }
    }
    else
    {
        /* 配置ITRx源 */
        switch(ITRx)
        {
            case LL_GPTIM_TIM_TS_ITR0:
                LL_GPTIM_SetGPTIM1ITR0Input(TIMx,ITRx_Src);
                break;
            case LL_GPTIM_TIM_TS_ITR1:
                LL_GPTIM_SetGPTIM1ITR1Input(TIMx,ITRx_Src);
                break;
            case LL_GPTIM_TIM_TS_ITR2:
                LL_GPTIM_SetGPTIM1ITR2Input(TIMx,ITRx_Src);
                break;
            case LL_GPTIM_TIM_TS_ITR3:
                LL_GPTIM_SetGPTIM1ITR3Input(TIMx,ITRx_Src);
                break;
            default:
                result = FAIL;
                break;
        }    
    }
   return  result;   
}
/**
  * @brief	设置 LL_GPTIM_SlaveInitTypeDef 为默认配置
  * @param 	TIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_GPTIM_SlaveInitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_GPTIM_SlaveModeStructInit(LL_GPTIM_SlaveInitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->ITRxSrc       = 0;
    TIM_InitStruct->SlaveMode     = LL_GPTIM_SLAVE_MODE_PROHIBITED;     
    TIM_InitStruct->TriggerSrc    = LL_GPTIM_TIM_TS_TI1FP1;
    TIM_InitStruct->TriggerDelay  = DISABLE;

}
/**
  * @brief  配置TIM触发输入捕获通道ETR.
  * @param  TIMx Timer Instance
  * @param  ETPolarity   极性
  * @param  ETPrescaler  分频
  * @param  ETR_Filter   滤波
  * @param  TIM_IC_InitStruct 指向一个 @ref LL_GPTIM_IC_InitTypeDef 结构体
  * @retval  TIM_OC_InitStruct pointer to a @ref LL_GPTIM_OC_InitTypeDef structure 
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus  LL_GPTIM_ETR_Init(GPTIM_Type *TIMx, LL_GPTIM_ETR_InitTypeDef* TIM_InitStruct)
{
  
    assert_param(IS_LL_GPTIM_ETP_FILTER(TIM_InitStruct->ETRFilter));
    assert_param(IS_LL_GPTIM_ETR_PSC(TIM_InitStruct->ETRClockDivision));                                                      
    assert_param(IS_LL_GPTIM_ETR_POLARITY(TIM_InitStruct->ETRPolarity));

    /* 时钟总线使能配置 */
    if(TIMx == GPTIM0)
    {
        LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_GTIM0);
    }
    else
    {
        LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_GTIM1);
    }
    /* 外部时钟极性 */
    LL_GPTIM_SetETRPolarity(TIMx,TIM_InitStruct->ETRPolarity);
    /* 外部时钟滤波 */
    LL_GPTIM_SetETRExtrenalTriggerFilter(TIMx,TIM_InitStruct->ETRFilter);
    /* 外部时钟分频 */
    LL_GPTIM_SetETRExtrenalTriggerPsc(TIMx,TIM_InitStruct->ETRClockDivision);
    if(TIM_InitStruct->AsExternal == ENABLE)
    {
        LL_GPTIM_EnableExternalClock(TIMx);
    }
    else
    {
        LL_GPTIM_DisableExternalClock(TIMx);
    }
    /* 手动触发更新事件，将配置值写入 */
    LL_GPTIM_GenerateEvent_UPDATE(TIMx);
    return PASS;
}

void LL_GPTIM_ETRStructInit(LL_GPTIM_ETR_InitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->AsExternal          = DISABLE;
    TIM_InitStruct->ETRFilter           = LL_GPTIM_ETR_FILTER_FDIV1;       
    TIM_InitStruct->ETRPolarity         = LL_GPTIM_ETR_POLARITY_NONINVERTED;     
    TIM_InitStruct->ETRClockDivision    = LL_GPTIM_ETR_PRESCALER_DIV1;
}

/**
  * @brief  配置TIM的比较输出通道.
  * @param  TIMx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_GPTIM_CHANNEL_0
  *         @arg @ref LL_GPTIM_CHANNEL_1
  *         @arg @ref LL_GPTIM_CHANNEL_2
  *         @arg @ref LL_GPTIM_CHANNEL_3
  * @retval TIM_OC_InitStruct pointer to a @ref LL_GPTIM_OC_InitTypeDef structure 
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus LL_GPTIM_OC_Init(GPTIM_Type *TIMx, uint32_t Channel, LL_GPTIM_OC_InitTypeDef *TIM_OC_InitStruct)
{
    ErrorStatus result = PASS;
    /* 参数检查 */
    assert_param(IS_GPTIM_INSTANCE(TIMx)); 
    assert_param(IS_LL_GPTIM_OC_MODE(TIM_OC_InitStruct->OCMode));
    assert_param(IS_LL_GPTIM_OC_PRELOAD(TIM_OC_InitStruct->OCPreload));
    assert_param(IS_LL_GPTIM_OC_POLARITY(TIM_OC_InitStruct->OCPolarity));
    assert_param(IS_LL_GPTIM_OC_FASTMODE(TIM_OC_InitStruct->OCFastMode));
    assert_param(IS_LL_GPTIM_OC_ETR_CLEARN(TIM_OC_InitStruct->OCETRFStatus));  
    /* 通道关闭 */
    LL_GPTIM_DisableNormalChannelOutput(TIMx,Channel);
    /* 通道极性 */
    LL_GPTIM_SetOCPolartyChannel(TIMx,TIM_OC_InitStruct->OCPolarity,Channel);
    /* 捕获映射到输出通道 */
    LL_GPTIM_SetChannelMode(TIMx,LL_GPTIM_CC_MODE_OUTPUT,Channel);
    /* 输出比较模式寄存器配置 */
    OCConfig(TIMx,Channel,TIM_OC_InitStruct);
    /* 通道使能 */
    LL_GPTIM_EnableNormalChannelOutput(TIMx,Channel);
    /* 手动触发更新事件，将配置值写入 */
    LL_GPTIM_GenerateEvent_UPDATE(TIMx);
    return result;
}
/**
  * @brief	配置
  * @param  TIMx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_GPTIM_CHANNEL_0
  *         @arg @ref LL_GPTIM_CHANNEL_1
  *         @arg @ref LL_GPTIM_CHANNEL_2
  *         @arg @ref LL_GPTIM_CHANNEL_3 
  * @param 	TIM_ICInitStruct 指向需要将值设置为默认配置的结构体 @ref LL_GPTIM_IC_InitTypeDef 结构体包含配置参数.
  * @retval	None
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
static ErrorStatus OCConfig(GPTIM_Type *TIMx, uint32_t Channel,LL_GPTIM_OC_InitTypeDef *TIM_OC_InitStruct)
{
    ErrorStatus result = PASS;
    
    /* 配置比较输出通道模式 */
    LL_GPTIM_SetOCMode(TIMx,TIM_OC_InitStruct->OCMode,Channel);
    /* 配置TRF清零使能 */
    if(TIM_OC_InitStruct->OCETRFStatus == ENABLE)
    {
        LL_GPTIM_Enable_Clear(TIMx,Channel);
    }
    /* 比较输出通道快速模式 */
    if(TIM_OC_InitStruct->OCFastMode == ENABLE )
    {
        LL_GPTIM_Enable_FastCompare(TIMx,Channel);
    }
    /* 比较输出通道缓冲模式 */
    if(TIM_OC_InitStruct->OCPreload == ENABLE)
    {
        LL_GPTIM_Enable_Preload(TIMx,Channel);
    }
    /* 设置比较值 */
    switch(Channel)
    {
        case LL_GPTIM_CHANNEL_1:
            LL_GPTIM_SetCompareCH1(TIMx,TIM_OC_InitStruct->CompareValue);
            break;
        case LL_GPTIM_CHANNEL_2:
            LL_GPTIM_SetCompareCH2(TIMx,TIM_OC_InitStruct->CompareValue);
            break;
        case LL_GPTIM_CHANNEL_3:
            LL_GPTIM_SetCompareCH3(TIMx,TIM_OC_InitStruct->CompareValue);
            break;
        case LL_GPTIM_CHANNEL_4:
            LL_GPTIM_SetCompareCH4(TIMx,TIM_OC_InitStruct->CompareValue);
            break;
        default :
            result = FAIL;
            break;

    }
    return result;
}
/**
  * @brief	设置 LL_GPTIM_OC_InitTypeDef 为默认配置
  * @param 	TIM_OC_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_GPTIM_OC_InitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_GPTIM_OC_StructInit(LL_GPTIM_OC_InitTypeDef *TIM_OC_InitStruct)
{
  /* Set the default configuration */
  TIM_OC_InitStruct->OCMode       = LL_GPTIM_OC_MODE_FROZEN;
  TIM_OC_InitStruct->OCETRFStatus = DISABLE;
  TIM_OC_InitStruct->OCFastMode   = DISABLE;
  TIM_OC_InitStruct->CompareValue = 0x00000000U;
  TIM_OC_InitStruct->OCPolarity   = LL_GPTIM_OC_POLARITY_NOMAL;
  TIM_OC_InitStruct->OCPreload    = DISABLE;

}
/**
  * @brief  配置TIM的输入捕获通道.
  * @param  TIMx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_GPTIM_CHANNEL_0
  *         @arg @ref LL_GPTIM_CHANNEL_1
  *         @arg @ref LL_GPTIM_CHANNEL_2
  *         @arg @ref LL_GPTIM_CHANNEL_3
  * @param  TIM_IC_InitStruct 指向一个 @ref LL_GPTIM_IC_InitTypeDef 结构体
  * @retval  TIM_OC_InitStruct pointer to a @ref LL_GPTIM_OC_InitTypeDef structure 
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus LL_GPTIM_IC_Init(GPTIM_Type *TIMx, uint32_t Channel, LL_GPTIM_IC_InitTypeDef* InitStruct)
{
    ErrorStatus result = PASS;
    
    /* 参数检查 */
    assert_param(IS_LL_GPTIM_CHANNEL(Channel));
    assert_param(IS_LL_GPTIM_IC_CAPTURE_STATE(InitStruct->CaptureState));
    assert_param(IS_LL_GPTIM_IC_POLARITY(InitStruct->ICPolarity));
    assert_param(IS_LL_GPTIM_IC_ACTIVEINPUT(InitStruct->ICActiveInput));                             
    assert_param(IS_LL_GPTIM_IC_PRESCALER(InitStruct->ICPrescaler));
    assert_param(IS_LL_GPTIM_IC_FILTER(InitStruct->ICFilter));
    /* 时钟总线使能配置 */
    if(TIMx == GPTIM0)
    {
        LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_GTIM0);
    }
    else
    {
        LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_GTIM1);
    }  
    /* 通道关闭 */
    LL_GPTIM_DisableNormalChannelOutput(TIMx,Channel);
    /*捕获极性 */
    LL_GPTIM_SetICPolartyChannel(TIMx,InitStruct->ICPolarity,Channel);
    /* 捕获映射通道 */
    LL_GPTIM_SetChannelMode(TIMx,InitStruct->ICActiveInput,Channel);
    /* 捕获预分频 */
    LL_GPTIM_SetICModePrescaler(TIMx,InitStruct->ICPrescaler,Channel);
    /* 捕获滤波器 */
    LL_GPTIM_SetICModeFilter(TIMx,InitStruct->ICFilter,Channel);
    if(InitStruct->CaptureState == ENABLE)
    {
        LL_GPTIM_EnableChannelCapture(TIMx,Channel);
    }
    /* 手动触发更新事件，将配置值写入 */
    LL_GPTIM_GenerateEvent_UPDATE(TIMx);
    return result;
}

/**
  * @brief	设置 LL_GPTIM_IC_InitTypeDef 为默认配置
  * @param 	TIM_ICInitStruct 指向需要将值设置为默认配置的结构体 @ref LL_GPTIM_IC_InitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_GPTIM_IC_StructInit(LL_GPTIM_IC_InitTypeDef *TIM_ICInitStruct)
{
  /* Set the default configuration */  
  TIM_ICInitStruct->ICPolarity    = LL_GPTIM_IC_POLARITY_RISING;
  TIM_ICInitStruct->ICActiveInput = LL_GPTIM_CC1_MODE_INPUT_TI1;
  TIM_ICInitStruct->ICPrescaler   = LL_GPTIM_IC_PRESCALER_DIV_1;
  TIM_ICInitStruct->ICFilter      = LL_GPTIM_IC_FILTER_FDIV1;
  TIM_ICInitStruct->CaptureState  = DISABLE;
}
/**
  * @}
  */
/**
* @}
*/
/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-21**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
