/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_rng.c
  * @author  FMSH Application Team
  * @brief   Src file of RNG LL Module
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
#include "fm33lc0xx_ll_rng.h"
#include "fm33_assert.h"
/** @addtogroup FM33LC0xx_LL_Driver_RNG
  * @{
  */
  
/** @addtogroup Private_Macros
* @{
*/
#define         IS_LL_RNG_INSTANCE(INTANCE)                         ((INTANCE) == RNG)

#define         IS_LL_RNG_CLOCK_PRESCALER(__VALUE__)               (((__VALUE__) == LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV1)||\
                                                                     ((__VALUE__) == LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV2)||\
                                                                     ((__VALUE__) == LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV4)||\
                                                                     ((__VALUE__) == LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV8)||\
                                                                     ((__VALUE__) == LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV16)||\
                                                                     ((__VALUE__) == LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV32))
/** 
  *@} 
  */ 

/** @addtogroup RNG_LL_EF_Init
  * @{
  */   
/**
  * @brief  复位对应RNG寄存器.
  * @param  RNGx 
  * @retval ErrorStatus枚举值:
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_RNG_DeInit(RNG_Type *RNGx)
{
    
    assert_param(IS_LL_RNG_INSTANCE(RNGx));
    
    /* 使能外设复位 */
    LL_RCC_EnablePeripheralReset();
    /* 复位外设寄存器 */
    LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_RNG);
    LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_RNG);
    /* 关闭外设总线始时钟和工作时钟 */
    LL_RCC_Group2_DisableBusClock(LL_RCC_BUS2_CLOCK_RNG);
    /* 锁定外设复位 */
    LL_RCC_DisablePeripheralReset();
    return PASS;
}
/**
  * @brief  根据 InitStruct 的配置信息初始化对应外设入口地址的寄存器值.
  * @param  RNGx  
  * @param  InitStruct 指向一个 @ref LL_RNG_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @note   RNG使用RCHF默认的8M作为时钟输入，经2分频后4M提供给RNG
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS 配置成功  
  */
ErrorStatus LL_RNG_Init(RNG_Type* RNGx,LL_RNG_InitTypeDef *InitStruct)
{
    
    assert_param(IS_LL_RNG_INSTANCE(RNGx));
    assert_param(IS_LL_RNG_CLOCK_PRESCALER(InitStruct->Prescaler));
    /* RNG 使用RCHF作为工作时钟因此必须确认RCHF使能*/
    if(LL_RCC_IsEnabled_RCHF() != SET)
    {
        LL_RCC_Enable_RCHF();
    }
    /* 
    RNG 总线时钟使能，因为用到随机数需要打开模拟功能
    */
    LL_RCC_Group1_EnableBusClock(LL_RCC_BUS1_CLOCK_ANAC);
    LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_RNG);
    /* RNG 工作时钟预分频*/
    LL_RCC_SetRNGPrescaler(InitStruct->Prescaler);
    /* RNG 工作时钟使能*/
    LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_RNG);
    
    return PASS;
}
/**
  * @brief	设置 InitStruct 为默认配置
  * @param 	InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_RNG_InitTypeDef 结构体  
  *         
  * @retval	None
  */

void LL_RNG_StructInit(LL_RNG_InitTypeDef *InitStruct)
{
    InitStruct->Prescaler = LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV2;
}

/**
  * @brief  获取一次随机数
  *
  * @param  None
  *
  * @note   如果返回值为0xFFFFFFFF 则说明随机数生成失败，请用户检查此函数的返回值，失败时重新生成   
  *
  * @retval 成功返回随机数，失败返回0xFFFFFFFF
  *                
  */
uint32_t GetRandomNumber(void)
{
    uint32_t rn32;
    LL_RNG_ClearFlag_RandomFail(RNG);
    LL_RNG_Enable(RNGCTL);
    __NOP();
    __NOP();
    __NOP();
    LL_RNG_Disable(RNGCTL);
    rn32 = LL_RNG_Read(RNG);
    if(LL_RNG_IsActiveFlag_RandomFail(RNG))
    {
        LL_RNG_ClearFlag_RandomFail(RNG);
        return 0xFFFFFFFF;
    }
    return rn32;
   
}

/**
  * @brief  获取CRC32
  *
  * @param  dataIn：待计算的数据
  *
  * @note   None   
  *
  * @retval 成功返回CRC32，失败返回0xFFFFFFFF
  *                
  */
uint32_t GetCrc32(uint32_t dataIn)
{
    uint32_t i=0;
		uint32_t crc32=0;
    LL_RNG_CrcWriteData(RNG,dataIn);
    LL_RNG_ClearFlag_CRCCalculationFinish(RNG);
    LL_RNG_EnableCRC(RNG);
    while(0==LL_RNG_IsActiveFlag_CRCCalculationFinish(RNG))
    {
        i++;
        if(i>600)break;
    }
    if(i >= 600)
    {
        LL_RNG_ClearFlag_CRCCalculationFinish(RNG);
        LL_RNG_Disable(RNGCTL);
        return 0xFFFFFFFF;
    }
    LL_RNG_ClearFlag_CRCCalculationFinish(RNG);
    crc32 = LL_RNG_Read(RNG);
    LL_RNG_Disable(RNGCTL);
    return crc32;
}

/** 
  *@} 
  */

/** 
  *@} 
  */
/*************************************************************END OF FILE************************************************************/

