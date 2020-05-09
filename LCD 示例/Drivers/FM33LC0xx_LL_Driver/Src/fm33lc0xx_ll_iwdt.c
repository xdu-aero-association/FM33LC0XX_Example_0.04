/**
  ****************************************************************************************************
  * @file    fm33lc0xx_ll_iwdt.c
  * @author  FMSH Application Team
  * @brief   Src file of IWDT LL Module
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
#include "fm33lc0xx_ll_iwdt.h"
#include "fm33_assert.h"
/** @addtogroup FM33LC0xx_LL_Driver_IWDT
  * @{
  */

/** @addtogroup Private_Macros
  * @{
  */
#define         IS_IWDT_INSTANCE(INTANCE)                    ((INTANCE) == IWDT)

#define         IS_LL_IWDT_WINDOWSVEL(__VALUE__)                ((__VALUE__) < 0xFFF)

#define         IS_LL_IWDT_OVERFLOWPERIOD(__VALUE__)            (((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_125MS)||\
                                                                 ((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_250MS)||\
                                                                 ((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_500MS)||\
                                                                 ((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_1000MS)||\
                                                                 ((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_2000MS)||\
                                                                 ((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_4000MS)||\
                                                                 ((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_8000MS)||\
                                                                 ((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_16000MS))
/**
  * @}
  */
  
/** @addtogroup IWDT_LL_EF_Init
  * @{
  */ 
  
/**
  * @brief	复位IWDT外设
  *
  * @note   此函数只能用于配制前复位外设，因为IWDT开启后不可以关闭
  *
  * @param	外设入口地址
  *
  * @retval	返回错误状态，可能值：
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_IWDT_DeInit(IWDT_Type* IWDTx)
{

    assert_param(IS_IWDT_INSTANCE(IWDTx));
    
    return PASS;
}
/**
  * @brief	根据 IWDT_InitStruct 初始化对应外设的寄存器值. 
  *         
  * @note 	IWTD使能后将无法关闭，直到下一次芯片复位
  *      	      
  * @param	IWDTx  外设入口地址
  * @param 	IWDT_InitStruct 是 @ref LL_IWDT_InitTypeDef结构体，它包含指定IWDT外设的配置信息	  
  *         
  * @retval	ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS 配置成功        
  */
ErrorStatus LL_IWDT_Init(IWDT_Type* IWDTx,LL_IWDT_InitTypeDef *IWDT_InitStruct)
{
    ErrorStatus status = PASS;

    /* 入口参数检查 */
    assert_param(IS_IWDT_INSTANCE(IWDTx));
    assert_param(IS_LL_IWDT_WINDOWSVEL(IWDT_InitStruct->IwdtWindows));
    assert_param(IS_LL_IWDT_OVERFLOWPERIOD(IWDT_InitStruct->OverflowPeriod));
    /* 开启总线时钟 */
    LL_RCC_Group1_EnableBusClock(LL_RCC_BUS1_CLOCK_IWDT);
    /* 配置独立看门狗溢出周期 */
    LL_IWDG_SetCounterPeriod(IWDTx,IWDT_InitStruct->OverflowPeriod);
    /* 配置独立看门狗清狗窗口*/
    LL_IWDG_SetIwdtWindows(IWDTx,IWDT_InitStruct->IwdtWindows);
    /* 启动看门狗 */
    LL_IWDG_ReloadCounter(IWDTx);
    
    return status;
}
/**
  * @brief	设置 IWDT_InitStruct 为默认配置
  * @param 	IWDT_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_IWDT_InitTypeDef 结构体 
  *         
  * @retval	None
  */
void LL_IWDT_StructInit(LL_IWDT_InitTypeDef *IWDT_InitStruct)
{
    /* 默认不使用窗口 */
    IWDT_InitStruct->IwdtWindows    = 0;
    /*最长溢出时间*/
    IWDT_InitStruct->OverflowPeriod = LL_IWDT_IWDT_OVERFLOW_PERIOD_500MS;
}
/** 
  *@} 
  */
  
/** 
  *@} 
  */
/*************************************************************END OF FILE************************************************************/
