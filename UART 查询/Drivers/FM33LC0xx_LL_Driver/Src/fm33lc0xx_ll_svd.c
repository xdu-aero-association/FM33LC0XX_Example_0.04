/**
  ****************************************************************************************************
  * @file    fm33lc0xx_ll_svd.c
  * @author  FMSH Application Team
  * @brief   Src file of SVD LL Module
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
#include "fm33lc0xx_ll_svd.h"
#include "fm33_assert.h"

/** @addtogroup FM33LC0xx_LL_Driver_SVD
  * @{
  */
  
/* Private macros ------------------------------------------------------------*/
/** @addtogroup UART_LL_Private_Macros
  * @{
  */
#define         IS_LL_SVD_INSTANCE(INSTANCE)               (((INSTANCE) == SVD))

#define         IS_LL_SVD_MODE(__VALUE__)                  (((__VALUE__) == LL_SVD_WORK_MODE_ALWAYS)||\
                                                            ((__VALUE__) == LL_SVD_WORK_MODE_INTERMITTENT))

#define         IS_LL_SVD_INTERVAL(__VALUE__)              (((__VALUE__) == LL_SVD_INTERVEL_ENABLE_PERIOD_62MS)||\
                                                            ((__VALUE__) == LL_SVD_INTERVEL_ENABLE_PERIOD_256MS)||\
                                                            ((__VALUE__) == LL_SVD_INTERVEL_ENABLE_PERIOD_1000MS)||\
                                                            ((__VALUE__) == LL_SVD_INTERVEL_ENABLE_PERIOD_4000MS))

#define         IS_LL_SVD_THRESHOLD(__VALUE__)             (((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP0)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP1)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP2)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP3)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP4)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP5)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP6)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP7)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP8)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP9)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP10)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP11)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP12)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP13)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP14)||\
                                                            ((__VALUE__) == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_SVSBASE))

#define         IS_LL_SVD_SVSCONFIG(__VALUE__)             (((__VALUE__) == DISABLE)||\
                                                            ((__VALUE__) == ENABLE))
                                                             
#define         IS_LL_SVD_VREFSELECT(__VALUE__)            (((__VALUE__) == LL_SVD_REFERENCE_VOLTAGE_1_0_VOLT)||\
                                                            ((__VALUE__) == LL_SVD_REFERENCE_VOLTAGE_1_1_VOLT)||\
                                                            ((__VALUE__) == LL_SVD_REFERENCE_VOLTAGE_1_2_VOLT)) 
                                                            
#define         IS_LL_SVD_DIGITALFILTER(__VALUE__)         (((__VALUE__) == DISABLE)||\
                                                            ((__VALUE__) == ENABLE))                                                             
/** 
  *@} 
  */
/** @addtogroup SVD_LL_EF_Init
  * @{
  */   
/**
  * @brief	复位SVD 外设寄存器值为复位值
  * @param	外设入口地址
  * @retval	返回错误状态，可能值：
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_SVD_DeInit(SVD_Type* SVDx)
{
    ErrorStatus status = PASS;

    /* 入口参数合法性断言 */
    assert_param(IS_LL_SVD_INSTANCE(SVDx));
	SVDx->CFGR  = 0x00000C08U;
    SVDx->CR    = 0x00000000U; 
    SVDx->IER   = 0x00000000U;
    SVDx->VSR   = 0x00000004U;
    
    return (status);
}


/**
  * @brief	根据 SVD_InitStruct 结构体包含的配置信息配置PMU寄存器 
  *         
  * @note 	为更好的睡眠功耗用户可能需要根据实际应用，调用 @ref fm33lc0xx_ll_RCC.h中的其他接口
  *      	来完成睡眠前的模式配置，包括睡眠行为和唤醒后的行为      
  * @param	PMUx  外设入口地址
  * @param 	SVD_InitStruct 指向一个 @ref SVD_InitTypeDef 类型的结构体，它包含指定LPUART外设的配置信息	  
  *         
  * @retval	ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功        
  */
ErrorStatus LL_SVD_Init(SVD_Type* SVDx, SVD_InitTypeDef *SVD_InitStruct)
{
    ErrorStatus status = FAIL;
	/* 参数合法性检查 */
    assert_param(IS_LL_SVD_INSTANCE(SVDx));
    assert_param(IS_LL_SVD_MODE(SVD_InitStruct->Mode));
    assert_param(IS_LL_SVD_INTERVAL(SVD_InitStruct->Interval));
    assert_param(IS_LL_SVD_THRESHOLD(SVD_InitStruct->Threshold));
    assert_param(IS_LL_SVD_VREFSELECT(SVD_InitStruct->VrefSelect));
    assert_param(IS_LL_SVD_DIGITALFILTER(SVD_InitStruct->DigitalFilter));
    
    LL_RCC_Group1_EnableBusClock(LL_RCC_BUS1_CLOCK_ANAC);
    /* 工作模式  */
    LL_SVD_SetSVDWorkMode(SVDx,SVD_InitStruct->Mode);
    /* 检测阈值 */
    LL_SVD_SetSVDThresholdLevel(SVDx,SVD_InitStruct->Threshold);
    /* 间歇使能间隔 */
    LL_SVD_SetSVDInterValEnablePeriod(SVDx,SVD_InitStruct->Interval);
    /* 参考电压通道选择 */
    LL_SVD_EnableReference(SVD,SVD_InitStruct->VrefSelect);
    /* 外部通道配置 */
    if(SVD_InitStruct->Threshold == LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_SVSBASE)
    {
        LL_SVD_EnableSVDSVSChannel(SVDx);
    }
    else
    {
        LL_SVD_DisableSVDSVSChannel(SVDx);
    }
    /* 数字滤波配置 */
    if(SVD_InitStruct->DigitalFilter == ENABLE)
    {
        LL_SVD_EnableSVDDigitalFiltering(SVDx);
    }
    else
    {
        LL_SVD_DisableSVDDigitalFiltering(SVDx);
    }
    /* MOD=1 时必须置 1 */
    if(SVD_InitStruct->Mode == LL_SVD_WORK_MODE_INTERMITTENT)
    {
        if(!LL_SVD_IsEnabledSVDDigitalFiltering(SVDx))
        {
            LL_SVD_EnableSVDDigitalFiltering(SVDx);
        }
    }
    status = PASS;
    return status;
}


/**
  * @brief	SVD_InitStruct 为默认配置
  * @param 	SVD_InitStruct 指向需要将值设置为默认配置的结构体 @ref SVD_InitTypeDef structure 
  *         结构体
  * @retval	None
  */

void LL_SVD_StructInit(SVD_InitTypeDef *SVD_InitStruct)
{
    
    SVD_InitStruct->DigitalFilter   = ENABLE;
    SVD_InitStruct->VrefSelect      = LL_SVD_REFERENCE_VOLTAGE_1_0_VOLT;
    SVD_InitStruct->Mode            = LL_SVD_WORK_MODE_INTERMITTENT;
    SVD_InitStruct->Interval        = LL_SVD_INTERVEL_ENABLE_PERIOD_62MS;
    SVD_InitStruct->Threshold       = LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP0;

}
/** 
  *@} 
  */
/** 
  *@} 
  */
/*********************** (C) COPYRIGHT Fudan Microelectronics *****END OF FILE************************/

