/**
  ****************************************************************************************************
  * @file    fm33lc0xx_ll_adc.c
  * @author  FMSH Application Team
  * @brief   Src file of ADC LL Module
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
#include "fm33lc0xx_ll_adc.h"
#include "fm33lc0xx_ll_rcc.h"
#include "fm33lc0xx_ll_rmu.h"
#include "fm33lc0xx_ll_vref.h"
#include "fm33_assert.h"

/** @addtogroup fm33lc0xx_LL_Driver
  * @{
  */
  
/**
  *@}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup LPUART_LL_Private_Macros
  * @{
  */

#define         IS_LL_ADC_INSTANCE(INSTANCE)                            ((INSTANCE) == ADC)

#define         IS_LL_ADC_COMMON_CLOCKSOURCE(__VALUE__)                 (((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_PLL)||\
        ((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_XTHF)||\
        ((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RCHF)||\
        ((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RC4M_PSC))


#define         IS_LL_ADC_COMMON_PRESCALER(__VALUE__)                   (((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV1)||\
        ((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV2)||\
        ((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV4)||\
        ((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV8)||\
        ((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV16)||\
        ((__VALUE__) == LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV32))

#define         IS_LL_ADC_CLOCK_SRC(__VALUE__)                          (((__VALUE__) == LL_ADC_CLOCK_ADCCLK)||\
        ((__VALUE__) == LL_ADC_CLOCK_APBCLK)||\
        ((__VALUE__) == LL_ADC_CLOCK_APBCLK_DIV2)||\
        ((__VALUE__) == LL_ADC_CLOCK_APBCLK_DIV4))

#define         IS_LL_ADC_CONTINUOUSCONVMODE(__VALUE__)                 (((__VALUE__) == LL_ADC_CONV_SINGLE)||\
        ((__VALUE__) == LL_ADC_CONV_CONTINUOUS))

#define         IS_LL_ADC_AUTO_MODE(__VALUE__)                          (((__VALUE__) == LL_ADC_SINGLE_CONV_MODE_SEMIAUTO)||\
        ((__VALUE__) == LL_ADC_SINGLE_CONV_MODE_AUTO))

#define         IS_LL_ADC_SCANDIRECTION(__VALUE__)                      (((__VALUE__) == LL_ADC_SEQ_SCAN_DIR_FORWARD)||\
        ((__VALUE__) == LL_ADC_SEQ_SCAN_DIR_BACKWARD))

#define         IS_LL_ADC_EXTERNALTRIGCONV(__VALUE__)                   (((__VALUE__) == LL_ADC_EXT_TRIGGER_NONE)||\
        ((__VALUE__) == LL_ADC_EXT_TRIGGER_RISING)||\
        ((__VALUE__) == LL_ADC_EXT_TRIGGER_FALLING)||\
        ((__VALUE__) == LL_ADC_EXT_TRIGGER_BOTHEDGE))

#define         IS_LL_ADC_CHANNEL_SWAP_WIAT(__VALUE__)                  (((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_1_CYCLE)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_2_CYCLES)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_3_CYCLES)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_4_CYCLES)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_5_CYCLES)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_6_CYCLES)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_7_CYCLES)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_8_CYCLES)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_9_CYCLES)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_10_CYCLES)||\
        ((__VALUE__) == LL_ADC_SAMPLEING_INTERVAL_11_CYCLES))

#define         IS_LL_ADC_CHANNEL_FAST_TIME(__VALUE__)                  (((__VALUE__) == LL_ADC_FAST_CH_SAMPLING_TIME_3_CYCLES_5)||\
        ((__VALUE__) == LL_ADC_FAST_CH_SAMPLING_TIME_4_CYCLES_5)||\
        ((__VALUE__) == LL_ADC_FAST_CH_SAMPLING_TIME_6_CYCLES_5)||\
        ((__VALUE__) == LL_ADC_FAST_CH_SAMPLING_TIME_10_CYCLES_5))

#define         IS_LL_ADC_CHANNEL_SLOW_TIME(__VALUE__)                  (((__VALUE__) == LL_ADC_SLOW_CH_SAMPLING_TIME_3_CYCLES_5)||\
        ((__VALUE__) == LL_ADC_SLOW_CH_SAMPLING_TIME_4_CYCLES_5)||\
        ((__VALUE__) == LL_ADC_SLOW_CH_SAMPLING_TIME_6_CYCLES_5)||\
        ((__VALUE__) == LL_ADC_SLOW_CH_SAMPLING_TIME_10_CYCLES_5))

#define         IS_LL_ADC_OVERSAMPCOFIG(__VALUE__)                      (((__VALUE__) == DISABLE)||\
        ((__VALUE__) == ENABLE))

#define         IS_LL_ADC_OVERSAMPINGRATIO(__VALUE__)                   (((__VALUE__) == LL_ADC_OVERSAMPLING_2X)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_4X)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_8X)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_16X)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_32X)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_64X)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_128X)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_256X))

#define         IS_LL_ADC_OVERSAMPINGSHIFT(__VALUE__)                   (((__VALUE__) == LL_ADC_OVERSAMPLING_RESULT_ORIGINAL)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_RESULT_DIV2)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_RESULT_DIV4)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_RESULT_DIV8)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_RESULT_DIV16)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_RESULT_DIV32)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_RESULT_DIV64)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_RESULT_DIV128)||\
        ((__VALUE__) == LL_ADC_OVERSAMPLING_RESULT_DIV256))

#define         ADC_CALIBRATIN_TIME_OUT                                 (500000)
/**
  * @}
  */

/**
  * @brief	ADC外设寄存器值为复位值
  * @param	外设入口地址
  * @retval	返回错误状态，可能值：
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_ADC_CommonDeInit(void)
{ 
    /* 关闭总线时钟 */
    LL_RCC_Group2_DisableBusClock(LL_RCC_BUS2_CLOCK_ADC);
    /* 关闭操作时钟 */
    LL_RCC_Group2_DisableOperationClock(LL_RCC_OPERATION2_CLOCK_ADC);

    return PASS;
}
/**
  * @brief	ADC共用寄存器设置以配置外设工作时钟
  *
  * @note 	其中LL_LPTIM_OPERATION_MODE_EXTERNAL_ASYN_PAUSE_CNT 模式需要外部脉冲提供给LPTIM模块作为工作时钟，此时
  *      	LPTIM完全工作在异步模式下。
  * @param	LPTIM  外设入口地址
  * @param 	LPTIM_InitStruct指向LL_LPTIM_TimeInitTypeDef类的结构体，它包含指定LPTIM外设的配置信息
  *
  * @retval	ErrorStatus枚举值
  *			-FAIL 配置过程发生错误
  *			-PASS LPUART配置成功
  */
ErrorStatus LL_ADC_CommonInit(LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    ErrorStatus status = PASS;

    /* 入口参数检查 */
    assert_param(IS_LL_ADC_COMMON_CLOCKSOURCE(ADC_CommonInitStruct->AdcClockSource));
    assert_param(IS_LL_ADC_COMMON_PRESCALER(ADC_CommonInitStruct->AdcClockPrescaler));
    /* 开启总线时钟 */
    LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_ADC);
    /* 开启操作时钟 */
    LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_ADC);
    /* 配置ADC时钟预分频 */
    LL_RCC_SetADCPrescaler(ADC_CommonInitStruct->AdcClockPrescaler);
    /* 配置ADC时钟模块时钟源 */
    LL_RCC_SetADCClockSource(ADC_CommonInitStruct->AdcClockSource);

    return status;
}
/**
  * @brief	设置 ADC_CommonInitStruct 为默认配置
  * @param 	ADC_CommonInitStruct 指向需要将值设置为默认配置的结构体 @ref LL_ADC_CommonInitTypeDef 结构体
  *
  * @retval	None
  */
void LL_ADC_CommonStructInit(LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    /*默认使用RCHF作为ADC时钟模块时钟源，预分频系数16*/
    ADC_CommonInitStruct->AdcClockSource    = LL_RCC_ADC_OPERATION_CLOCK_PRESCALLER_RCHF;
    ADC_CommonInitStruct->AdcClockPrescaler = LL_RCC_ADC_OPERATION_CLOCK_PRESCALER_DIV16;
}
/**
  * @brief	恢复对应的ADC入口地址寄存器为默认值
  *
  * @param	ADCx  外设入口地址
  *
  * @retval	ErrorStatus枚举值
  *			-FAIL 配置过程发生错误
  *			-PASS LPUART配置成功
  */
ErrorStatus  LL_ADC_DeInit(ADC_Type *ADCx)
{
    ErrorStatus status = PASS;

    /* 入口合法性检查 */
    assert_param(IS_LL_ADC_INSTANCE(ADCx));

    /* 外设复位使能 */
    LL_RCC_EnablePeripheralReset();


    LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ADC);
    LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ADC);
	LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ADC_CR);
    LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ADC_CR);
    LL_RCC_DisablePeripheralReset();
    return status;
}
/**
  * @brief	初始化ADCx指定的入口地址的外设寄存器
  *
  * @note 	用户必须检查此函数的返回值，以确保自校准完成，否则转换结果精度无法保证，除此之外ADC使能过采样实际不会增加ADC的
  *      	转换精度只会提高转换结果的稳定性（同时配置移位寄存器的情况下），同时过采样会降低转换速度。
  * @param	ADCx  外设入口地址
  * @param 	ADC_InitStruct 向一LL_ADC_InitTypeDef结构体，它包含指定ADC外设的配置信息
  *
  * @retval	ErrorStatus枚举值
  *			-FAIL 配置过程发生错误
  *			-PASS LPUART配置成功
  */
ErrorStatus LL_ADC_Init(ADC_Type *ADCx, LL_ADC_InitTypeDef  *ADC_InitStruct)
{
    ErrorStatus status = PASS;
    /* 入口合法性检查 */
    assert_param(IS_LL_ADC_INSTANCE(ADCx));
    assert_param(IS_LL_ADC_CONTINUOUSCONVMODE(ADC_InitStruct->ADC_ContinuousConvMode));
    assert_param(IS_LL_ADC_AUTO_MODE(ADC_InitStruct->ADC_AutoMode));
    assert_param(IS_LL_ADC_SCANDIRECTION(ADC_InitStruct->ADC_ScanDirection));
    assert_param(IS_LL_ADC_EXTERNALTRIGCONV(ADC_InitStruct->ADC_ExternalTrigConv));
    assert_param(IS_LL_ADC_OVERSAMPCOFIG(ADC_InitStruct->ADC_Oversampling));
    assert_param(IS_LL_ADC_OVERSAMPINGRATIO(ADC_InitStruct->ADC_OverSampingRatio));
    assert_param(IS_LL_ADC_OVERSAMPINGSHIFT(ADC_InitStruct->ADC_OversamplingShift));

	
	LL_VREF_EnableVREF(VREF);//置位VREF_EN寄存器，使能VREF1p2模块
	LL_VREF_EnableTemperatureSensor(VREF);//置位PTAT_EN寄存器

    while (LL_VREF_IsActiveFlag_VREFReady(VREF) == 0); //等待VREF建立
		
    LL_RCC_EnablePeripheralReset();


    LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ADC);
    LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ADC);
	  LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ADC_CR);
    LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_ADC_CR);
    LL_RCC_DisablePeripheralReset();
    if (LL_ADC_IsEnabled(ADCx) == 0U)
    {
        /* 选择ADC时钟源 */
        //LL_ADC_SetClock(ADCx,ADC_InitStruct->ADC_Clock_Src);
        /* 连续转换模式 */
        LL_ADC_SetContinuousMode(ADCx, ADC_InitStruct->ADC_ContinuousConvMode);
        /* 自动转换模式 */
        LL_ADC_SetSingleConversionAutoMode(ADCx, ADC_InitStruct->ADC_AutoMode);

        /*采样时间控制模式*/
        LL_ADC_SetSamplingTimeControlMode(ADCx, ADC_InitStruct->ADC_SamplingTimeControl);
        
        /*采样启动控制模式*/
        LL_ADC_Set_SamplingStartControlMode(ADCx, ADC_InitStruct->ADC_SamplingStartControl);

        /* 多通道扫描方向 */
        LL_ADC_SetSequencerScanDirection(ADCx, ADC_InitStruct->ADC_ScanDirection);
        /* 触发模式 */
        LL_ADC_SetTriggerEdge(ADCx, ADC_InitStruct->ADC_ExternalTrigConv);
        /* 通道等待使能 */
        LL_ADC_SetWaitMode(ADCx, ADC_InitStruct->ADC_WaitMode);
        /*数据冲突模式设置*/
        LL_ADC_SetOverrun(ADCx, ADC_InitStruct->ADC_OverrunMode);
        /*通道采样时间设置*/
        LL_ADC_SetSamplingInterval(ADCx, ADC_InitStruct->ADC_Channel_Swap_Wiat);
        LL_ADC_SetSamplingTimeFastCH(ADCx, ADC_InitStruct->ADC_Channel_Fast_Time);
        LL_ADC_SetSamplingTimeSlowCH(ADCx, ADC_InitStruct->ADC_Channel_Slow_Time);
        if (ADC_InitStruct->ADC_Oversampling)
        {
            /*使能过采样倍数后，需要配置移位寄存器进行移位，这一过程是硬件自动完成的最终最大
            可输出16位的结果值（即256被采样得到的结果是20bit的，右移4bit结果就是16bit的）*/
            LL_ADC_SetOverSamplingRatio(ADCx, ADC_InitStruct->ADC_OverSampingRatio);
            LL_ADC_SetOverSamplingResult(ADCx, ADC_InitStruct->ADC_OversamplingShift);
            /* 过采样使能 */
            LL_ADC_EnableOverSampling(ADCx);
        }
        else
        {
            /* 关闭过采样 */
            LL_ADC_DisableOverSampling(ADCx);
        }
        /* 使能ADC */
        LL_ADC_Enable(ADCx);

        /* 关闭ADC，关闭后ADC自校准值依然保持，除非执行外设复位或芯片复位 */
        LL_ADC_Disable(ADCx);
    }
    else
    {
        status = FAIL;
    }

    return status;
}
/**
  * @brief	校准芯片实际工作的VDDA值，从而进行采样值到实际电压值的准确装换
  *
  * @note 	此函数必须将ADC工作时钟频率配置为1M以下(推荐500KHz)，才可以保证转换结果的准确性
  *
  * @param	ADCx  外设入口地址
  *
  * @retval	当前芯片工作实际的VDDA电压值(mV)
  *
  *
  */
uint32_t GetActualVddaVoltage(ADC_Type *ADCx)
{
    uint16_t  adcvel;

		LL_VREF_EnableVREFBuffer(VREF);//使能VREF的输出BUFFER
    /* 使能内部校准通道 */
    LL_ADC_EnalbleSequencerChannel(ADCx, LL_ADC_INTERNAL_CH_VREF);
    /* 使能ADC */
    LL_ADC_Enable(ADCx);
    /* 启动转换 */
    LL_ADC_StartConversion(ADCx);
    /* 等待转换完成标志置起 */
    while (!LL_ADC_IsActiveFlag_EOC(ADCx));
    /* 清除转换完成标志置起 */
    LL_ADC_ClearFlag_EOC(ADCx);
	adcvel = LL_ADC_ReadConversionData12(ADCx);
	
	LL_ADC_Disable(ADCx);
	while (LL_ADC_IsActiveFlag_BUSY(ADCx));
  
    /* 关闭转换通道 */
    LL_ADC_DisableSequencerChannel(ADCx, LL_ADC_INTERNAL_CH_VREF);
    /* 读取转换结果 */
    LL_VREF_DisableVREFBuffer(VREF);

    return (uint32_t)((*((uint16_t *)0x1FFFFD08) * 3000) / (adcvel));

}


/**
  * @brief	设置 ADC_InitStruct 为默认配置
  * @param 	ADC_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_ADC_InitTypeDef 结构体
  *
  * @retval	None
  */
void LL_ADC_StructInit(LL_ADC_InitTypeDef *ADC_InitStruct)
{

    ADC_InitStruct->ADC_ContinuousConvMode  = LL_ADC_CONV_CONTINUOUS;

    ADC_InitStruct->ADC_AutoMode            = LL_ADC_SINGLE_CONV_MODE_AUTO;

    ADC_InitStruct->ADC_ScanDirection       = LL_ADC_SEQ_SCAN_DIR_BACKWARD;

    ADC_InitStruct->ADC_ExternalTrigConv    = LL_ADC_EXT_TRIGGER_NONE;

    ADC_InitStruct->ADC_OverrunMode         = LL_ADC_OVR_DATA_OVERWRITTEN;

    ADC_InitStruct->ADC_WaitMode            = LL_ADC_WAIT_MODE_NO_WAIT;

    ADC_InitStruct->ADC_SamplingStartControl = LL_ADC_SAMPLING_START_CONTROL_BY_REG;

    ADC_InitStruct->ADC_SamplingTimeControl = LL_ADC_SAMPLING_TIME_CONTROL_BY_REG;

    ADC_InitStruct->ADC_Channel_Swap_Wiat   = LL_ADC_SAMPLEING_INTERVAL_11_CYCLES;

    ADC_InitStruct->ADC_Channel_Fast_Time   = LL_ADC_FAST_CH_SAMPLING_TIME_384_ADCCLK;

    ADC_InitStruct->ADC_Channel_Slow_Time   = LL_ADC_SLOW_CH_SAMPLING_TIME_384_ADCCLK;

    ADC_InitStruct->ADC_Oversampling        = ENABLE;

    ADC_InitStruct->ADC_OverSampingRatio    = LL_ADC_OVERSAMPLING_256X;

    ADC_InitStruct->ADC_OversamplingShift   = LL_ADC_OVERSAMPLING_RESULT_ORIGINAL;
}
/*************************************************************END OF FILE************************************************************/



