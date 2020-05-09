/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_bstim.c
  * @author  FMSH Application Team
  * @brief   Src file of BSTIM LL Module
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
#include "fm33lc0xx_ll_bstim.h"
#include "fm33_assert.h"

/** @addtogroup FM33LC0xx_LL_Driver_BSTIM
  * @{
  */
  
/** @addtogroup Private_Macros
  * @{
  */
#define         IS_LL_BSTIM_INSTANCE(INTANCE)                       ((INTANCE) == BSTIM)

#define         IS_LL_BSTIM_PRESCALER(__VALUE__)                    ((__VALUE__) <= 0x0000FFFF)

#define         IS_LL_BSTIM_AUTORELOAN(__VALUE__)                   ((__VALUE__) <= 0x0000FFFF)


#define         IS_LL_BSTIM_AUTORELOAN_MODE(__VALUE__)              (((__VALUE__) == ENABLE)||\
                                                                    ((__VALUE__) == DISABLE))

#define         IS_LL_BSTIM_CLOCK_SRC(__VALUE__)                    (((__VALUE__) == LL_RCC_BSTIM_OPERATION_CLK_SOURCE_APBCLK2)||\
                                                                    ((__VALUE__) == LL_RCC_BSTIM_OPERATION_CLK_SOURCE_RCLP)||\
                                                                    ((__VALUE__) == LL_RCC_BSTIM_OPERATION_CLK_SOURCE_RC4M_PSC)||\
                                                                    ((__VALUE__) == LL_RCC_BSTIM_OPERATION_CLK_SOURCE_LSCLK))

/**
  * @}
  */
  
/** @addtogroup BSTIM_LL_EF_Init
  * @{
  */ 
  
/**
  * @brief  复位对应BSTIM寄存器.
  * @param  BSTIMx 
  * @retval ErrorStatus枚举值:
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_BSTIM_DeInit(BSTIM_Type *BSTIMx)
{
    
    assert_param(IS_LL_BSTIM_INSTANCE(BSTIMx));
    
    /* 使能外设复位 */
    LL_RCC_EnablePeripheralReset();
    /* 复位IIC外设寄存器 */
    LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_BSTIM);
    LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_BSTIM);
    /* 关闭外设总线始时钟和工作时钟 */
    LL_RCC_Group4_DisableBusClock(LL_RCC_BUS4_CLOCK_BTIM);
    LL_RCC_Group2_DisableOperationClock(LL_RCC_OPERATION2_CLOCK_BSTIM);
    /* 锁定外设复位 */
    LL_RCC_DisablePeripheralReset();
    return PASS;
}
/**
  * @brief  根据 BSTIM_InitStruct 的配置信息初始化对应外设入口地址的寄存器值.
  * @param  BSTIMx BSTIMx 
  * @param  BSTIM_InitStruct 指向一个 @ref LL_BSTIM_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS 配置成功  
  */
ErrorStatus LL_BSTIM_Init(BSTIM_Type *BSTIMx,LL_BSTIM_InitTypeDef *BSTIM_InitStruct)
{
    /* 参数检查 */
    assert_param(IS_LL_BSTIM_INSTANCE(BSTIMx));     
    assert_param(IS_LL_BSTIM_CLOCK_SRC(BSTIM_InitStruct->ClockSource));
    assert_param(IS_LL_BSTIM_PRESCALER(BSTIM_InitStruct->Prescaler)); 
    assert_param(IS_LL_BSTIM_AUTORELOAN(BSTIM_InitStruct->Autoreload));
    assert_param(IS_LL_BSTIM_AUTORELOAN_MODE(BSTIM_InitStruct->AutoreloadState));
      
    /* 时钟使能 */                                                          
    LL_RCC_Group4_EnableBusClock(LL_RCC_BUS4_CLOCK_BTIM);
    /* 选择时钟源 */
    LL_RCC_SetBSTIMClockSource(BSTIM_InitStruct->ClockSource);
    LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_BSTIM);
    /* 分频系数 */
    LL_BSTIM_SetCounterPsc(BSTIMx,BSTIM_InitStruct->Prescaler);
    /* 自动重装载值 */
    LL_BSTIM_EnableUpdateEvent(BSTIMx);
    LL_BSTIM_SetCounterAutoReloadValue(BSTIMx,BSTIM_InitStruct->Autoreload);
    if(BSTIM_InitStruct->AutoreloadState == ENABLE)
    {
        LL_BSTIM_EnableAutoReload(BSTIMx);
    }
    else
    {
        LL_BSTIM_DisableAutoReload(BSTIMx);
    }
    LL_BSTIM_GenerateEvent_UPDATE(BSTIMx);
    return PASS;
}
/**
  * @brief	设置 BSTIM_InitStruct 为默认配置
  * @param 	BSTIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_BSTIM_InitTypeDef 结构体  
  *         
  * @retval	None
  */

void LL_BSTIM_StructInit(LL_BSTIM_InitTypeDef *BSTIM_InitStruct)
{
    
    BSTIM_InitStruct->Prescaler         = 0;
    BSTIM_InitStruct->Autoreload        = 0xFFFFFFFF;    
    BSTIM_InitStruct->AutoreloadState   = ENABLE;
    BSTIM_InitStruct->ClockSource       = LL_RCC_BSTIM_OPERATION_CLK_SOURCE_APBCLK2;
    
}
/**
  * @}
  */
  
/**
  * @}
  */


/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-18**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
