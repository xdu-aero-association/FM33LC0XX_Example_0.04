/**
  ****************************************************************************************************
  * @file    fm33lc0xx_ll_pmu.c
  * @author  FMSH Application Team
  * @brief   Src file of PMU LL Module
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
#include "fm33lc0xx_ll_rmu.h"
#include "fm33lc0xx_ll_pmu.h"
#include "fm33_assert.h"
/** @addtogroup FM33LC0xx_LL_Driver_PMU
  * @{
  */
/* Private macros ------------------------------------------------------------*/
/** @addtogroup UART_LL_Private_Macros
  * @{
  */



#define         IS_LL_PMU_INSTANCE(INSTANCE)                (((INSTANCE) == PMU))
                                                             
#define         IS_LL_PMU_MODE(__VALUE__)                   (((__VALUE__) == LL_PMU_POWER_MODE_LPRUN_ONLY)||\
                                                             ((__VALUE__) == LL_PMU_POWER_MODE_ACTIVE_AND_LPACTIVE)||\
                                                             ((__VALUE__) == LL_PMU_POWER_MODE_SLEEP_AND_DEEPSLEEP))
                                                             
#define         IS_LL_PMU_COREVOLTAGESCALING(__VALUE__)     (((__VALUE__) == DISABLE)||\
                                                             ((__VALUE__) == ENABLE))
                                                      
#define         IS_LL_PMU_DEEPSLEEP(__VALUE__)              (((__VALUE__) == LL_PMU_SLEEP_MODE_NOMAL)||\
                                                             ((__VALUE__) == LL_PMU_SLEEP_MODE_DEEP))
                                                             
#define         IS_LL_PMU_WAKEUPFREQUENCY(__VALUE__)        (((__VALUE__) == LL_PMU_SLEEP_WAKEUP_FREQ_RCHF_8MHZ)||\
                                                             ((__VALUE__) == LL_PMU_SLEEP_WAKEUP_FREQ_RCHF_16MHZ)||\
                                                             ((__VALUE__) == LL_PMU_SLEEP_WAKEUP_FREQ_RCHF_24MHZ))
                                                                         
#define         IS_LL_PMU_LDOLOWMODE(__VALUE__)             (((__VALUE__) == LL_PMU_LDO_LPM_DISABLE)||\
                                                             ((__VALUE__) == LL_PMU_LDO_LPM_ENABLE)) 
                                                             
#define         IS_LL_PMU_WAKEUPDELAY(__VALUE__)            (((__VALUE__) == LL_PMU_WAKEUP_DELAY_TIME_0US)||\
                                                             ((__VALUE__) == LL_PMU_WAKEUP_DELAY_TIME_2US)||\
                                                             ((__VALUE__) == LL_PMU_WAKEUP_DELAY_TIME_4US)||\
                                                             ((__VALUE__) == LL_PMU_WAKEUP_DELAY_TIME_8US))
                                                             
                                                             
#define         IS_LL_PMU_WAKEUPDELAY_PDPOWER(__VALUE__)    (((__VALUE__) == LL_PMU_WAKEUP_PD_POWER_DELAY_TIME_125NS)||\
                                                             ((__VALUE__) == LL_PMU_WAKEUP_PD_POWER_DELAY_TIME_250NS)||\
                                                             ((__VALUE__) == LL_PMU_WAKEUP_PD_POWER_DELAY_TIME_500NS)||\
                                                             ((__VALUE__) == LL_PMU_WAKEUP_PD_POWER_DELAY_TIME_1000NS))
/** 
  *@} 
  */
/** @addtogroup PMU_LL_EF_Init
  * @{
  */   
/**
  * @brief	复位PMU外设
  *
  * @param	外设入口地址
  *
  * @retval	返回错误状态，可能值：
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_PMU_Sleep_DeInit(PMU_Type* PMUx)
{
    ErrorStatus status = FAIL;
	/* 参数合法性检查 */
    assert_param(IS_LL_PMU_INSTANCE(PMUx));
    PMUx->CR   = 0x00060000U;
    PMUx->WKTR = 0xC0000001U;
    PMUx->IER  = 0x00000000U;
    status = PASS;
    return status;
}


/**
  * @brief	根据LPM_InitStruct结构体包含的配置信息配置PMU寄存器 
  *         
  * @note 	为更好的睡眠功耗用户可能需要根据实际应用，调用 @ref fm33lc0xx_ll_pmu.h中的其他接口
  *      	来完成睡眠前的模式配置，包括睡眠行为和唤醒后的行为（注：此函数会关闭BOR）      
  * @param	PMUx  外设入口地址
  * @param 	LPM_InitStruct 指向一个 @ref LL_PMU_SleepInitTypeDef 类型的结构体，它包含指定LPUART外设的配置信息	  
  *         
  * @retval	ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功        
  */
ErrorStatus LL_PMU_Sleep_Init(PMU_Type* PMUx, LL_PMU_SleepInitTypeDef *LPM_InitStruct)
{
    ErrorStatus status = FAIL;
	/* 参数合法性检查 */
    assert_param(IS_LL_PMU_INSTANCE(PMUx));
    assert_param(IS_LL_PMU_MODE(LPM_InitStruct->PowerMode));
    assert_param(IS_LL_PMU_COREVOLTAGESCALING(LPM_InitStruct->CoreVoltageScaling));
    assert_param(IS_LL_PMU_DEEPSLEEP(LPM_InitStruct->DeepSleep));
    assert_param(IS_LL_PMU_WAKEUPFREQUENCY(LPM_InitStruct->WakeupFrequency));
    assert_param(IS_LL_PMU_LDOLOWMODE(LPM_InitStruct->LDOLowPowerMode));
    assert_param(IS_LL_PMU_WAKEUPDELAY(LPM_InitStruct->WakeupDelay));
    assert_param(IS_LL_PMU_WAKEUPDELAY_PDPOWER(LPM_InitStruct->WakeupDelayPDPower));
    /* 唤醒延时 */
    LL_PMU_SetWakeupTimeDelay(PMUx,LPM_InitStruct->WakeupDelay);
    /* 唤醒PD域电源上电延时 */
    LL_PMU_SetPDPowerOpenDelayInRTCWakeUpMode(PMUx,LPM_InitStruct->WakeupDelayPDPower);
    /* 睡眠模式LDO工作方式配置 */
    LL_PMU_SetLDOLowPowerMode(PMUx,LPM_InitStruct->LDOLowPowerMode);
    /* 唤醒后RCHF的频率 */
    LL_PMU_SetWakeupRCHFFrequency(PMUx,LPM_InitStruct->WakeupFrequency);
    /* 睡眠下内核电压配置 */
    if(LPM_InitStruct->CoreVoltageScaling == ENABLE)
    {
        LL_PMU_EnableCoreVoltageScaling(PMUx);
    }
    else
    {
        LL_PMU_DisableCoreVoltageScaling(PMUx);
    }
	/* M0系统控制器,一般配置为0即可*/
	SCB->SCR =0;								
    /* 睡眠模式 */
    LL_PMU_SetSleepMode(PMUx,LPM_InitStruct->DeepSleep);
    /* 睡眠电源模式 */
    LL_PMU_SetLowPowerMode(PMUx,LPM_InitStruct->PowerMode);	

    __WFI();      
	status = PASS;
    return status;
}

/**
  * @brief	LPM_InitStruct 为默认配置
  * @param 	LPM_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_PMU_SleepInitTypeDef structure 
  *         结构体
  * @retval	None
  */
void LL_PMU_StructInit(LL_PMU_SleepInitTypeDef *LPM_InitStruct)
{
    
    LPM_InitStruct->PowerMode           = LL_PMU_POWER_MODE_SLEEP_AND_DEEPSLEEP;
    LPM_InitStruct->DeepSleep           = LL_PMU_SLEEP_MODE_NOMAL;
    LPM_InitStruct->LDOLowPowerMode     = LL_PMU_LDO_LPM_DISABLE;
    LPM_InitStruct->WakeupFrequency     = LL_PMU_SLEEP_WAKEUP_FREQ_RCHF_8MHZ;
    LPM_InitStruct->WakeupDelay         = LL_PMU_WAKEUP_DELAY_TIME_2US;
    LPM_InitStruct->WakeupDelayPDPower  = LL_PMU_WAKEUP_PD_POWER_DELAY_TIME_1000NS;
    LPM_InitStruct->CoreVoltageScaling  = ENABLE;
}
/** 
  *@} 
  */
/** 
  *@} 
  */
/*********************** (C) COPYRIGHT Fudan Microelectronics *****END OF FILE************************/
