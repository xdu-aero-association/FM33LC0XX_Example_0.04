/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_atim.c
  * @author  FMSH Application Team
  * @brief   Src file of ATIM LL Module
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
#include "fm33lc0xx_ll_atim.h"
#include "fm33_assert.h"

/** @addtogroup FM33LC0xx_LL_Driver_ATIM
  * @{
  */
  
/** @addtogroup TIM_LL_Private_Macros
  * @{
  */


#define IS_ATIM_INSTANCE(TIMx)                     ((TIMx) == ATIM)

#define IS_ATIM_CLKSRC(__VALUE__)                  (((__VALUE__) == LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_APBCLK2) \
                                                      || ((__VALUE__) == LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_USBPHYBCK120M) \
                                                      || ((__VALUE__) == LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_PLLx2))


#define IS_LL_ATIM_COUNTERMODE(__VALUE__)          (((__VALUE__) == LL_ATIM_COUNTER_DIRECT_UP) \
                                                       || ((__VALUE__) == LL_ATIM_COUNTER_DIRECT_DOWN) \
                                                       || ((__VALUE__) == LL_ATIM_COUNTER_ALIGNED_CENTER_DOWN   ) \
                                                       || ((__VALUE__) == LL_ATIM_COUNTER_ALIGNED_CENTER_UP     ) \
                                                       || ((__VALUE__) == LL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN))

#define IS_LL_ATIM_CLOCKDIVISION(__VALUE__)        (((__VALUE__) == LL_ATIM_CLOCKDIVISION_DIV1) \
                                                     || ((__VALUE__) == LL_ATIM_CLOCKDIVISION_DIV2) \
                                                     || ((__VALUE__) == LL_ATIM_CLOCKDIVISION_DIV4))


#define IS_LL_ATIM_CC_MODE(__VALUE__)               (((__VALUE__) ==   LL_ATIM_CC_MODE_OUTPUT) \
                                                      || ((__VALUE__) == LL_ATIM_CC_MODE_INPUT_TI1) \
                                                      || ((__VALUE__) == LL_ATIM_CC_MODE_INPUT_TI2) \
                                                      || ((__VALUE__) == LL_ATIM_CC_MODE_INPUT_TRC))
                                      
#define IS_LL_ATIM_IC_FILTER(__VALUE__)            (((__VALUE__) == LL_ATIM_IC_FILTER_FDIV1) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV1_N2) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV1_N4) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV1_N8) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV2_N6) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV2_N8) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV4_N6) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV4_N8) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV8_N6) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV8_N8) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV16_N5) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV16_N6) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV16_N8) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV32_N5) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV32_N6) \
                                                     || ((__VALUE__) == LL_ATIM_IC_FILTER_FDIV32_N8))

#define IS_LL_ATIM_CHANNEL(__VALUE__)              (((__VALUE__) == LL_ATIM_CHANNEL_1)\
                                                    || ((__VALUE__) == LL_ATIM_CHANNEL_2)\
                                                    || ((__VALUE__) == LL_ATIM_CHANNEL_3)\
                                                    || ((__VALUE__) == LL_ATIM_CHANNEL_4))
                                        
                                        
                                        
#define IS_LL_ATIM_SLAVE_MODE(__VALUE__)           (((__VALUE__) == LL_ATIM_SLAVE_MODE_PROHIBITED)\
                                                    || ((__VALUE__) == LL_ATIM_SLAVE_MODE_TI1FP1_TI2FP2_CNT)\
                                                    || ((__VALUE__) == LL_ATIM_SLAVE_MODE_TI2FP2_TI1FP1_CNT)\
                                                    || ((__VALUE__) == LL_ATIM_SLAVE_MODE_TI2FP2_CNT_TI1FP1_CNT)\
                                                    || ((__VALUE__) == LL_ATIM_SLAVE_MODE_TRGI_RISE_RST)\
                                                    || ((__VALUE__) == LL_ATIM_SLAVE_MODE_TRGI_HIGH_RUN)\
                                                    || ((__VALUE__) == LL_ATIM_SLAVE_MODE_TRGI_RISE_RUN)\
                                                    || ((__VALUE__) == LL_ATIM_SLAVE_MODE_TRGI_CLK))


#define IS_LL_ATIM_TRIGGER_SRC(__VALUE__)          (((__VALUE__) ==LL_ATIM_TIM_TS_ITR0 )\
                                                        ||((__VALUE__) ==LL_ATIM_TIM_TS_ITR1 )\
                                                        ||((__VALUE__) ==LL_ATIM_TIM_TS_ITR2)\
                                                        ||((__VALUE__) ==LL_ATIM_TIM_TS_ITR3)\
                                                        ||((__VALUE__) ==LL_ATIM_TIM_TS_TI1F_ED)\
                                                        ||((__VALUE__) ==LL_ATIM_TIM_TS_TI1FP1)\
                                                        ||((__VALUE__) ==LL_ATIM_TIM_TS_TI2FP1)\
                                                        ||((__VALUE__) ==LL_ATIM_TIM_TS_ETRF))    



#define IS_LL_ATIM_ETP_FILTER(__VALUE__)           (((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV1) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV1_N2) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV1_N4) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV1_N8) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV2_N6) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV2_N8) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV4_N6) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV4_N8) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV8_N6) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV8_N8) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV16_N5) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV16_N6) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV16_N8) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV32_N5) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV32_N6) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_FILTER_FDIV32_N8))


#define IS_LL_ATIM_ETR_PSC(__VALUE__)               (((__VALUE__) == LL_ATIM_ETR_PRESCALER_DIV1) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_PRESCALER_DIV2) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_PRESCALER_DIV4) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_PRESCALER_DIV8))
                                 
                                 

#define IS_LL_ATIM_ETR_POLARITY(__VALUE__)         (((__VALUE__) == LL_ATIM_ETR_POLARITY_NONINVERTED) \
                                                     || ((__VALUE__) == LL_ATIM_ETR_POLARITY_NINVERTED)) 

                                   
                                                    
#define IS_LL_ATIM_IC_POLARITY(__VALUE__)          (((__VALUE__) == LL_ATIM_IC_POLARITY_RISING) \
                                                       || ((__VALUE__) == LL_ATIM_IC_POLARITY_FALLING))



#define IS_LL_ATIM_IC_ACTIVEINPUT(__VALUE__)          (((__VALUE__) == LL_ATIM_CC1_MODE_INPUT_TI1) \
                                                       || ((__VALUE__) == LL_ATIM_CC1_MODE_INPUT_TI2) \
                                                       || ((__VALUE__) == LL_ATIM_CC2_MODE_INPUT_TI2) \
                                                       || ((__VALUE__) == LL_ATIM_CC2_MODE_INPUT_TI1) \
                                                       || ((__VALUE__) == LL_ATIM_CC3_MODE_INPUT_TI3) \
                                                       || ((__VALUE__) == LL_ATIM_CC3_MODE_INPUT_TI4) \
                                                       || ((__VALUE__) == LL_ATIM_CC4_MODE_INPUT_TI3) \
                                                       || ((__VALUE__) == LL_ATIM_CC4_MODE_INPUT_TI4) \
                                                       || ((__VALUE__) == LL_ATIM_CC_MODE_INPUT_TRC))
                                       
 
#define IS_LL_ATIM_IC_PRESCALER(__VALUE__)         (((__VALUE__) == LL_ATIM_IC_PRESCALER_DIV_1) \
                                                     || ((__VALUE__) == LL_ATIM_IC_PRESCALER_DIV_2) \
                                                     || ((__VALUE__) == LL_ATIM_IC_PRESCALER_DIV_4) \
                                                     || ((__VALUE__) == LL_ATIM_IC_PRESCALER_DIV_8))



#define IS_LL_ATIM_OC_POLARITY(__VALUE__)          (((__VALUE__) == LL_ATIM_OC_POLARITY_HIGH) \
                                                    || ((__VALUE__) == LL_ATIM_OC_POLARITY_LOW))



#define IS_LL_ATIM_OC_MODE(__VALUE__)               (((__VALUE__) ==   LL_ATIM_OC_MODE_FROZEN) \
                                                      || ((__VALUE__) == LL_ATIM_OC_MODE_ACTIVE) \
                                                      || ((__VALUE__) == LL_ATIM_OC_MODE_INACTIVE) \
                                                      || ((__VALUE__) == LL_ATIM_OC_MODE_TOGGLE) \
                                                      || ((__VALUE__) == LL_ATIM_OC_MODE_FORCED_INACTIVE) \
                                                      || ((__VALUE__) == LL_ATIM_OC_MODE_FORCED_ACTIVE) \
                                                      || ((__VALUE__) == LL_ATIM_OC_MODE_PWM1) \
                                                      || ((__VALUE__) == LL_ATIM_OC_MODE_PWM2))

#define IS_LL_ATIM_AUTORELOAB_STATE(__VALUE__)          (((__VALUE__) == ENABLE) \
                                                    || ((__VALUE__) == DISABLE))
                                                    
#define IS_LL_ATIM_OC_FASTMODE(__VALUE__)          (((__VALUE__) == ENABLE) \
                                                    || ((__VALUE__) == DISABLE))

#define IS_LL_ATIM_OC_PRELOAD(__VALUE__)          (((__VALUE__) == ENABLE) \
                                                    || ((__VALUE__) == DISABLE))
                                                    
#define IS_LL_ATIM_OC_ETR_CLEARN(__VALUE__)        (((__VALUE__) == ENABLE) \
                                                    || ((__VALUE__) == DISABLE))

#define IS_LL_ATIM_OCN_STATE(__VALUE__)          (((__VALUE__) == ENABLE)\
                                                    || ((__VALUE__) == DISABLE))

#define IS_LL_ATIM_OC_IDLESTATE(__VALUE__)          (((__VALUE__) == LL_ATIM_OC_IDLESTATE_LOW) \
                                                    || ((__VALUE__) == LL_ATIM_OC_IDLESTATE_HIGH))
                                                    
#define IS_LL_ATIM_OC_NIDLESTATE(__VALUE__)        (((__VALUE__) == LL_ATIM_OCN_IDLESTATE_LOW) \
                                                    || ((__VALUE__) == LL_ATIM_OCN_IDLESTATE_HIGH))


#define IS_LL_ATIM_OC_NPOLARITY(__VALUE__)        (((__VALUE__) == LL_ATIM_OCN_POLARITY_HIGH) \
                                                    || ((__VALUE__) == LL_ATIM_OCN_POLARITY_LOW))


 
#define IS_LL_ATIM_BDTR_FILTER(__VALUE__)           (((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV1) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV1_N2) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV1_N4) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV1_N8) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV2_N6) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV2_N8) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV4_N6) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV4_N8) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV8_N6) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV8_N8) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV16_N5) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV16_N6) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV16_N8) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV32_N5) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV32_N6) \
                                                     || ((__VALUE__) == LL_ATIM_BRK_FILTER_FDIV32_N8))

#define IS_LL_ATIM_OSSR_STATE(__VALUE__) (((__VALUE__) == LL_ATIM_OSSR_DISABLE) \
                                     || ((__VALUE__) == LL_ATIM_OSSR_ENABLE))

#define IS_LL_ATIM_OSSI_STATE(__VALUE__) (((__VALUE__) == LL_ATIM_OSSI_DISABLE) \
                                      || ((__VALUE__) == LL_ATIM_OSSI_ENABLE))

#define IS_LL_ATIM_LOCK_LEVEL(__VALUE__) (((__VALUE__) == LL_ATIM_LOCKLEVEL_OFF) \
                                      || ((__VALUE__) == LL_ATIM_LOCKLEVEL_1)   \
                                      || ((__VALUE__) == LL_ATIM_LOCKLEVEL_2)   \
                                      || ((__VALUE__) == LL_ATIM_LOCKLEVEL_3))

#define IS_LL_ATIM_BREAK_POLARITY(__VALUE__) (((__VALUE__) == LL_ATIM_BREAK_POLARITY_LOW) \
                                          || ((__VALUE__) == LL_ATIM_BREAK_POLARITY_HIGH))

#define IS_LL_ATIM_AUTOMATIC_OUTPUT_STATE(__VALUE__)    (((__VALUE__) == DISABLE) \
                                                        || ((__VALUE__) == ENABLE))

#define IS_LL_ATIM_TRIGGER_DELAY(__VALUE__)              (((__VALUE__) == DISABLE) \
                                                        || ((__VALUE__) == ENABLE))

#define IS_LL_ATIM_IC_CAPTURE_STATE(__VALUE__)           (((__VALUE__) == DISABLE) \
                                                        || ((__VALUE__) == ENABLE))








/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/
/** @defgroup TIM_LL_Private_Functions TIM Private Functions
  * @{
  */
static ErrorStatus  OCConfig(ATIM_Type *TIMx, uint32_t Channel, LL_ATIM_OC_InitTypeDef* TIM_OC_InitStruct );
/**
  * @}
  */

/** @addtogroup TIM_LL_EF_Init
  * @{
  */

/**
  * @brief  复位对应ATIMx寄存器.
  * @param  ATIMx 
  * @retval ErrorStatus枚举值:
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_ATIM_DeInit(ATIM_Type *TIMx)
{
    ErrorStatus result = PASS;

    /* Check the parameters */
    assert_param(IS_ATIM_INSTANCE(TIMx));
    /* 使能外设复位 */
    LL_RCC_EnablePeripheralReset();
    /* 使能外设复位 */
    LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ATIM);
    LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ATIM);
    /* 关闭外设时钟 */
    LL_RCC_Group4_DisableBusClock(LL_RCC_BUS4_CLOCK_ATIM);
    LL_RCC_Group1_DisableOperationClock(LL_RCC_OPERATION1_CLOCK_ATIM);
    /* 锁定外设复位 */
    LL_RCC_DisablePeripheralReset();
    return result;
}
/**
  * @brief  配置基本定时器时基单元（内部时钟源）.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref LL_ATIM_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus LL_ATIM_Init(ATIM_Type *TIMx, LL_ATIM_InitTypeDef *TIM_InitStruct)
{

    /* 参数检查 */
    assert_param(IS_ATIM_INSTANCE(TIMx));
    assert_param(IS_LL_ATIM_COUNTERMODE(TIM_InitStruct->CounterMode));
    assert_param(IS_LL_ATIM_CLOCKDIVISION(TIM_InitStruct->ClockDivision));
    assert_param(IS_LL_ATIM_AUTORELOAB_STATE(TIM_InitStruct->AutoreloadState));
    assert_param(IS_ATIM_CLKSRC(TIM_InitStruct->ClockSource));
    
    /* 时钟总线使能配置 */ 
    LL_RCC_SetATIMClockSource(TIM_InitStruct->ClockSource);
    LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_ATIM);
    LL_RCC_Group1_EnableOperationClock(LL_RCC_OPERATION1_CLOCK_ATIM);
    /* 设置重复计数值 */
    LL_ATIM_SetConfigRepeatCnt(TIMx, TIM_InitStruct->RepetitionCounter);
    /* 计数器计数模式配置 */
    switch(TIM_InitStruct->CounterMode)
    {
        /* 中心对称模式 */
        case LL_ATIM_COUNTER_ALIGNED_CENTER_DOWN   :   
        case LL_ATIM_COUNTER_ALIGNED_CENTER_UP     : 
        case LL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN:
        LL_ATIM_SetCounterAlignedMode(TIMx,TIM_InitStruct->CounterMode);
        break;
        default:
        /* 边沿模式 */
        LL_ATIM_SetCounterDirection(TIMx,TIM_InitStruct->CounterMode);
        LL_ATIM_SetCounterAlignedMode(TIMx,LL_ATIM_COUNTER_ALIGNED_EDGE);
        break;
    }
    /* 自动重装载值 */
    LL_ATIM_SetAutoReload(TIMx,TIM_InitStruct->Autoreload );
    /* 定时器分频系数与数字滤波器所使用的采样时钟分频比 */
    LL_ATIM_SetClockDivision(TIMx,TIM_InitStruct->ClockDivision);
    /* 时钟分频 */
    LL_ATIM_SetPrescaler(TIMx,TIM_InitStruct->Prescaler);
    /* 预装载配置 */
    if(TIM_InitStruct->AutoreloadState == ENABLE)
    {
        LL_ATIM_EnableARRPreload(TIMx);
    }
    else
    {
        LL_ATIM_DisableARRPreload(TIMx);
    }
    /* 手动触发更新事件，将配置值写入 */
    LL_ATIM_GenerateEvent_UPDATE(TIMx);
    
    return PASS;
}

/**
  * @brief	设置 LL_ATIM_InitTypeDef 为默认配置
  * @param 	TIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_ATIM_InitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_ATIM_StructInit(LL_ATIM_InitTypeDef *TIM_InitStruct)
{
  /* Set the default configuration */
  TIM_InitStruct->ClockSource           = LL_RCC_ATIME_OPERATION_CLOCK_SOURCE_APBCLK2;
  TIM_InitStruct->Prescaler             = (uint16_t)0x0000;
  TIM_InitStruct->CounterMode           = LL_ATIM_COUNTER_DIRECT_UP;
  TIM_InitStruct->Autoreload            = 0xFFFFU;
  TIM_InitStruct->ClockDivision         = LL_ATIM_CLOCKDIVISION_DIV1;
  TIM_InitStruct->RepetitionCounter     = 0;
  TIM_InitStruct->AutoreloadState       = DISABLE;
}

/**
  * @brief  配置基本定时器从模式，包括编码器模式.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref LL_ATIM_SlaveInitTypeDef 结构体 
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */ 
ErrorStatus LL_ATIM_SlaveMode_Init(ATIM_Type *TIMx, LL_ATIM_SlaveInitTypeDef *TIM_InitStruct)
{

    /* 参数检查 */
    assert_param(IS_ATIM_INSTANCE(TIMx)); 
    assert_param(IS_LL_ATIM_TRIGGER_DELAY(TIM_InitStruct->TriggerDelay));
    assert_param(IS_LL_ATIM_TRIGGER_SRC(TIM_InitStruct->TriggerSrc));
    /* 时钟总线使能配置 */
    LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_ATIM);
    LL_RCC_Group1_EnableOperationClock(LL_RCC_OPERATION1_CLOCK_ATIM);
    /* 触发延迟默认关闭 */
    LL_ATIM_DisableMasterSlaveMode(TIMx);
    /* 关闭从模式以能写入TS */  
    LL_ATIM_SetSlaveMode(TIMx,0);
    /* 从模式输入源选择 */
    LL_ATIM_SetTriggerInput(TIMx,TIM_InitStruct->TriggerSrc);
    /* 从模式选择 */
    LL_ATIM_SetSlaveMode(TIMx,TIM_InitStruct->SlaveMode);
    /* 触发延迟默认关闭 */
    if(TIM_InitStruct->TriggerDelay == ENABLE)
    {
        LL_ATIM_EnableMasterSlaveMode(TIMx);
    }
    /* 手动触发更新事件，将配置值写入 */
    LL_ATIM_GenerateEvent_UPDATE(TIMx);
    
    return PASS;
}
/**
  * @brief	设置 LL_ATIM_SlaveInitTypeDef 为默认配置
  * @param 	TIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_ATIM_SlaveInitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_ATIM_SlaveModeStructInit(LL_ATIM_SlaveInitTypeDef *TIM_InitStruct)
{
      
    TIM_InitStruct->SlaveMode     = LL_ATIM_SLAVE_MODE_PROHIBITED;     
    TIM_InitStruct->TriggerSrc    = LL_ATIM_TIM_TS_TI1FP1;
    TIM_InitStruct->TriggerDelay  = DISABLE;

}

/**
  * @brief  配置TIM的输入捕获通道.
  * @param  TIMx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_ATIM_CHANNEL_0
  *         @arg @ref LL_ATIM_CHANNEL_1
  *         @arg @ref LL_ATIM_CHANNEL_2
  *         @arg @ref LL_ATIM_CHANNEL_3
  * @param  TIM_IC_InitStruct 指向一个 @ref LL_ATIM_IC_InitTypeDef 结构体
  * @retval  TIM_OC_InitStruct pointer to a @ref LL_ATIM_OC_InitTypeDef structure 
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus  LL_ATIM_IC_Init(ATIM_Type *TIMx,uint32_t Channel,LL_ATIM_IC_InitTypeDef* IC_InitStruct)
{
    /* 参数检查 */
    assert_param(IS_LL_ATIM_CHANNEL(Channel));
    assert_param(IS_LL_ATIM_IC_CAPTURE_STATE(IC_InitStruct->CaptureState));
    assert_param(IS_LL_ATIM_IC_POLARITY(IC_InitStruct->ICPolarity));
    assert_param(IS_LL_ATIM_IC_ACTIVEINPUT(IC_InitStruct->ICActiveInput));                             
    assert_param(IS_LL_ATIM_IC_PRESCALER(IC_InitStruct->ICPrescaler));
    assert_param(IS_LL_ATIM_IC_FILTER(IC_InitStruct->ICFilter));
    /* 时钟总线使能配置 */
    LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_ATIM);
    LL_RCC_Group1_EnableOperationClock(LL_RCC_OPERATION1_CLOCK_ATIM);  
    /* 通道关闭 */
    LL_ATIM_DisableNormalChannelOutput(TIMx,Channel);
    /*捕获极性 */
    LL_ATIM_SetICPolartyChannel(TIMx,IC_InitStruct->ICPolarity,Channel);
    /* 捕获映射通道 */
    LL_ATIM_SetChannelMode(TIMx,IC_InitStruct->ICActiveInput,Channel);
    /* 捕获预分频 */
    LL_ATIM_SetICModePrescaler(TIMx,IC_InitStruct->ICPrescaler,Channel);
    /* 捕获滤波器 */
    LL_ATIM_SetICModeFilter(TIMx,IC_InitStruct->ICFilter,Channel);
    if(IC_InitStruct->CaptureState == ENABLE)
    {
        LL_ATIM_EnableChannelCapture(TIMx,Channel);
    }
    /* 手动触发更新事件，将配置值写入 */
    LL_ATIM_GenerateEvent_UPDATE(TIMx);
    return PASS;
}
/**
  * @brief	设置 LL_ATIM_IC_InitTypeDef 为默认配置
  * @param 	TIM_ICInitStruct 指向需要将值设置为默认配置的结构体 @ref LL_ATIM_IC_InitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_ATIM_IC_StructInit(LL_ATIM_IC_InitTypeDef *TIM_ICInitStruct)
{
  /* 默认配置 */  
  TIM_ICInitStruct->ICPolarity    = LL_ATIM_IC_POLARITY_RISING;
  TIM_ICInitStruct->ICActiveInput = LL_ATIM_CC1_MODE_INPUT_TI1;
  TIM_ICInitStruct->ICPrescaler   = LL_ATIM_IC_PRESCALER_DIV_1;
  TIM_ICInitStruct->ICFilter      = LL_ATIM_IC_FILTER_FDIV1;
  TIM_ICInitStruct->CaptureState  = DISABLE;
}
/**
  * @brief  配置TIM触发输入捕获通道ETR.
  * @param  TIMx Timer Instance
  * @param  ETPolarity   极性
  * @param  ETPrescaler  分频
  * @param  ETR_Filter   滤波
  * @param  TIM_IC_InitStruct 指向一个 @ref LL_ATIM_IC_InitTypeDef 结构体
  * @retval  TIM_OC_InitStruct pointer to a @ref LL_ATIM_OC_InitTypeDef structure 
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus  LL_ATIM_ETR_Init(ATIM_Type *TIMx, LL_ATIM_ETR_InitTypeDef* TIM_InitStruct)
{
  
    assert_param(IS_LL_ATIM_ETP_FILTER(TIM_InitStruct->ETRFilter));
    assert_param(IS_LL_ATIM_ETR_PSC(TIM_InitStruct->ETRClockDivision));                                                      
    assert_param(IS_LL_ATIM_ETR_POLARITY(TIM_InitStruct->ETRPolarity));
                                          
    /* 时钟总线使能配置 */
    LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_ATIM);
    LL_RCC_Group1_EnableOperationClock(LL_RCC_OPERATION1_CLOCK_ATIM);
    /* 外部时钟极性 */
    LL_ATIM_SetETRPolarity(TIMx,TIM_InitStruct->ETRPolarity);
    /* 外部时钟滤波 */
    LL_ATIM_SetETRExtrenalTriggerFilter(TIMx,TIM_InitStruct->ETRFilter);
    /* 外部时钟分频 */
    LL_ATIM_SetETRExtrenalTriggerPsc(TIMx,TIM_InitStruct->ETRClockDivision);
    if(TIM_InitStruct->AsExternal == ENABLE)
    {
        LL_ATIM_EnableExternalClock(TIMx);
    }
    else
    {
        LL_ATIM_DisableExternalClock(TIMx);
    }
    /* 手动触发更新事件，将配置值写入 */
    LL_ATIM_GenerateEvent_UPDATE(TIMx);
    return PASS;
}

void LL_ATIM_ETRStructInit(LL_ATIM_ETR_InitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->AsExternal          = DISABLE;
    TIM_InitStruct->ETRFilter           = LL_ATIM_ETR_FILTER_FDIV1;       
    TIM_InitStruct->ETRPolarity         = LL_ATIM_ETR_POLARITY_NONINVERTED;     
    TIM_InitStruct->ETRClockDivision    = LL_ATIM_ETR_PRESCALER_DIV1;
}
/**
  * @brief  配置TIM的比较输出通道.
  * @param  TIMx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_ATIM_CHANNEL_1
  *         @arg @ref LL_ATIM_CHANNEL_2
  *         @arg @ref LL_ATIM_CHANNEL_3
  *         @arg @ref LL_ATIM_CHANNEL_4
  * @retval TIM_OC_InitStruct pointer to a @ref LL_ATIM_OC_InitTypeDef structure 
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus LL_ATIM_OC_Init(ATIM_Type *TIMx, uint32_t Channel, LL_ATIM_OC_InitTypeDef *TIM_OC_InitStruct)
{
    ErrorStatus result = PASS;
    /* 参数检查 */
    assert_param(IS_ATIM_INSTANCE(TIMx)); 
    assert_param(IS_LL_ATIM_OC_MODE(TIM_OC_InitStruct->OCMode));
    assert_param(IS_LL_ATIM_OC_PRELOAD(TIM_OC_InitStruct->OCPreload));
    assert_param(IS_LL_ATIM_OC_POLARITY(TIM_OC_InitStruct->OCPolarity));
    assert_param(IS_LL_ATIM_OC_FASTMODE(TIM_OC_InitStruct->OCFastMode));
    assert_param(IS_LL_ATIM_OC_ETR_CLEARN(TIM_OC_InitStruct->OCETRFStatus));
    assert_param(IS_LL_ATIM_OCN_STATE(TIM_OC_InitStruct->OCNState)); 
    assert_param(IS_LL_ATIM_OC_IDLESTATE(TIM_OC_InitStruct->OCIdleState));
    assert_param(IS_LL_ATIM_OC_NIDLESTATE(TIM_OC_InitStruct->OCNIdleState));
    assert_param(IS_LL_ATIM_OC_NPOLARITY(TIM_OC_InitStruct->OCNPolarity));

    /* 通道关闭 */
    LL_ATIM_DisableNormalChannelOutput(TIMx,Channel);
    LL_ATIM_DisableReverseChannelOutPut(TIMx,Channel);
	
    /* 通道极性 */
    LL_ATIM_SetOCPolartyNormalChannel(TIMx,TIM_OC_InitStruct->OCPolarity,Channel);
    /* 通道空闲电平 */
    LL_ATIM_Set_OC_SetIdleState(TIMx,TIM_OC_InitStruct->OCIdleState,Channel);
    /* 互补通道空闲电平 */
    LL_ATIM_Set_OCN_SetIdleState(TIMx,TIM_OC_InitStruct->OCNIdleState,Channel); 
    /* 互补通道极性 */
    LL_ATIM_SetOCPolartyReverseChannel(TIMx,TIM_OC_InitStruct->OCNPolarity,Channel);
    /* 捕获映射到输出通道 */
    LL_ATIM_SetChannelMode(TIMx,LL_ATIM_CC_MODE_OUTPUT,Channel);
    /* 输出比较模式寄存器配置 */
    OCConfig(TIMx,Channel,TIM_OC_InitStruct);
    /* 通道使能 */
    LL_ATIM_EnableNormalChannelOutput(TIMx,Channel);
    /* 手动触发更新事件，将配置值写入 */
    LL_ATIM_GenerateEvent_UPDATE(TIMx);
    
    return result;
}
/**
  * @brief	设置 LL_ATIM_OC_InitTypeDef 为默认配置
  * @param 	TIM_OC_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_ATIM_OC_InitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_ATIM_OC_StructInit(LL_ATIM_OC_InitTypeDef *TIM_OC_InitStruct)
{
  /* Set the default configuration */
  TIM_OC_InitStruct->OCMode       = LL_ATIM_OC_MODE_FROZEN;
  TIM_OC_InitStruct->OCETRFStatus = DISABLE;
  TIM_OC_InitStruct->OCFastMode   = DISABLE;
  TIM_OC_InitStruct->CompareValue = 0x00000000U;
  TIM_OC_InitStruct->OCPolarity   = LL_ATIM_OC_POLARITY_HIGH;
  TIM_OC_InitStruct->OCPreload    = DISABLE;
  TIM_OC_InitStruct->OCIdleState  = LL_ATIM_OC_IDLESTATE_LOW;
  TIM_OC_InitStruct->OCNIdleState = LL_ATIM_OCN_IDLESTATE_LOW;
  TIM_OC_InitStruct->OCNPolarity  = LL_ATIM_OCN_POLARITY_HIGH;
  TIM_OC_InitStruct->OCNState     = DISABLE;
}
/**
  * @brief	配置
  * @param  TIMx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_ATIM_CHANNEL_1
  *         @arg @ref LL_ATIM_CHANNEL_2
  *         @arg @ref LL_ATIM_CHANNEL_3
  *         @arg @ref LL_ATIM_CHANNEL_4
  * @param 	TIM_ICInitStruct 指向需要将值设置为默认配置的结构体 @ref LL_ATIM_IC_InitTypeDef 结构体包含配置参数.
  * @retval	None
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
static ErrorStatus OCConfig(ATIM_Type *TIMx, uint32_t Channel,LL_ATIM_OC_InitTypeDef *TIM_OC_InitStruct)
{
    ErrorStatus result = PASS;
    
    /* 配置比较输出通道模式 */
    LL_ATIM_SetOCMode(TIMx,TIM_OC_InitStruct->OCMode,Channel);
    /* 配置TRF清零使能 */
    if(TIM_OC_InitStruct->OCETRFStatus == ENABLE)
    {
        LL_ATIM_Enable_Clear(TIMx,Channel);
    }
    else
    {
        LL_ATIM_Disable_Clear(TIMx,Channel);
    }
    /* 比较输出通道快速模式 */
    if(TIM_OC_InitStruct->OCFastMode == ENABLE )
    {
        LL_ATIM_Enable_FastCompare(TIMx,Channel);
    }
    else
    {
        LL_ATIM_Disable_FastCompare(TIMx,Channel);
    }
    /* 比较输出通道缓冲模式 */
    if(TIM_OC_InitStruct->OCPreload == ENABLE)
    {
        LL_ATIM_Enable_Preload(TIMx,Channel);
    }
    else
    {
        LL_ATIM_Disable_Preload(TIMx,Channel);
    }
    if(TIM_OC_InitStruct->OCNState == ENABLE)
    {
        LL_ATIM_EnableReverseChannelOutPut(TIMx,Channel);
    }
    /* 设置比较值 */
    switch(Channel)
    {
        case LL_ATIM_CHANNEL_1:
            LL_ATIM_SetCompareCH1(TIMx,TIM_OC_InitStruct->CompareValue);
            break;
        case LL_ATIM_CHANNEL_2:
            LL_ATIM_SetCompareCH2(TIMx,TIM_OC_InitStruct->CompareValue);
            break;
        case LL_ATIM_CHANNEL_3:
            LL_ATIM_SetCompareCH3(TIMx,TIM_OC_InitStruct->CompareValue);
            break;
        case LL_ATIM_CHANNEL_4:
            LL_ATIM_SetCompareCH4(TIMx,TIM_OC_InitStruct->CompareValue);
            break;
        default :
            result = FAIL;
            break;

    }
    return result;
}
/**
  * @brief  配置TIM的输入捕获通道.
  * @param  TIMx Timer Instance
  * @param  TIM_IC_InitStruct 指向一个 @ref LL_ATIM_IC_InitTypeDef 结构体
  * @retval  TIM_OC_InitStruct pointer to a @ref LL_ATIM_OC_InitTypeDef structure 
  *			-FAIL 配置过程发生错误        
  *			-PASS 成功  
  */
ErrorStatus LL_ATIM_BDTR_Init(ATIM_Type *TIMx, LL_ATIM_BDTR_InitTypeDef *TIM_BDTR_InitStruct)
{
    ErrorStatus result = PASS;
    /* 参数检查 */
    assert_param(IS_ATIM_INSTANCE(TIMx));
    assert_param(IS_LL_ATIM_OSSR_STATE(TIM_BDTR_InitStruct->OSSRState));
    assert_param(IS_LL_ATIM_OSSI_STATE(TIM_BDTR_InitStruct->OSSIState));
    assert_param(IS_LL_ATIM_LOCK_LEVEL(TIM_BDTR_InitStruct->LockLevel));
    assert_param(IS_LL_ATIM_BREAK_POLARITY(TIM_BDTR_InitStruct->BreakPolarity));
    assert_param(IS_LL_ATIM_AUTOMATIC_OUTPUT_STATE(TIM_BDTR_InitStruct->AutomaticOutput));
    assert_param(IS_LL_ATIM_BDTR_FILTER(TIM_BDTR_InitStruct->BreakFilter));
    /* 关闭所有输出 */
    LL_ATIM_Disable_AllOutputs(TIMx);
    /* 设置死区时间 */
    LL_ATIM_SetDeadTimeGeneration(TIMx,TIM_BDTR_InitStruct->DeadTime);
    /* 设置寄存器锁定等级 */
    LL_ATIM_SetLockLevel(TIMx,TIM_BDTR_InitStruct->LockLevel);
    /* Idle状态下关闭状态 */
    LL_ATIM_SetOffStates_Idel(TIMx,TIM_BDTR_InitStruct->OSSIState);
    /* run状态下关闭状态 */
    LL_ATIM_SetOffStates_Run(TIMx,TIM_BDTR_InitStruct->OSSRState);
    /* 门控1刹车信号 */
    LL_ATIM_SetBreak1GateState(TIMx,TIM_BDTR_InitStruct->GatedBrakeSignal_1);
    /* 门控2刹车信号 */
    LL_ATIM_SetBreak2GateState(TIMx,TIM_BDTR_InitStruct->GatedBrakeSignal_2);
    /* 门控刹车信号组合方式设置  */
    LL_ATIM_SetBreakSignalCombination(TIMx,TIM_BDTR_InitStruct->BrakeSignalCombined);
    /* 刹车极性设置 */
    LL_ATIM_SetBreakPolarity(TIMx,TIM_BDTR_InitStruct->BreakPolarity);
    /* 更新时间自动设置输出配置，如果刹车事件发生过并且当前功能使能，则下一个更新事件将重新自动输出 */
    
    if(TIM_BDTR_InitStruct->AutomaticOutput == ENABLE)
    {
        LL_ATIM_Enable_AutomaticOutput(TIMx);
    }
    else
    {
        LL_ATIM_Disable_AutomaticOutput(TIMx);
    }
    /* 刹车功能开关配置 */
    if(TIM_BDTR_InitStruct->BreakState == ENABLE)
    {
        LL_ATIM_Enable_BRK(TIMx);
    }
    else
    {
        LL_ATIM_Disable_BRK(TIMx);
    }
    /* 使能全部输出 */
    LL_ATIM_Enable_AllOutputs(TIMx);
    /* 手动触发更新事件，将配置值写入 */
    LL_ATIM_GenerateEvent_UPDATE(TIMx);
    /* 手动触发更新事件，将配置值写入 */
    LL_ATIM_GenerateEvent_COM(TIMx);
    return result;
}
/**
  * @brief	设置 LL_ATIM_IC_InitTypeDef 为默认配置
  * @param 	TIM_ICInitStruct 指向需要将值设置为默认配置的结构体 @ref LL_ATIM_IC_InitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_ATIM_BDTR_StructInit(LL_ATIM_BDTR_InitTypeDef *TIM_BDTR_InitStruct)
{ 
    TIM_BDTR_InitStruct->DeadTime            = 0x00;
    TIM_BDTR_InitStruct->LockLevel           = LL_ATIM_LOCKLEVEL_OFF;
    TIM_BDTR_InitStruct->OSSRState           = LL_ATIM_OSSR_DISABLE;
    TIM_BDTR_InitStruct->OSSIState           = LL_ATIM_OSSI_DISABLE;
    TIM_BDTR_InitStruct->BreakFilter         = LL_ATIM_BRK_FILTER_FDIV1;
    TIM_BDTR_InitStruct->BreakPolarity       = LL_ATIM_BREAK_POLARITY_LOW; 
    TIM_BDTR_InitStruct->AutomaticOutput     = DISABLE;
    TIM_BDTR_InitStruct->GatedBrakeSignal_1  = LL_ATIM_BREAK1_GATE_AUTO;
    TIM_BDTR_InitStruct->GatedBrakeSignal_2  = LL_ATIM_BREAK2_GATE_AUTO;
    TIM_BDTR_InitStruct->BreakState          = DISABLE;
    TIM_BDTR_InitStruct->BrakeSignalCombined = LL_ATIM_BRK_COMBINATION_OR;
}

/**
  * @}
  */
  
/**
  * @}
  */
/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-24**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
