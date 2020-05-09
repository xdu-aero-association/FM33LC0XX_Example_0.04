/**
  ****************************************************************************************************
  * @file    fm33lC0xx_ll_comp.c
  * @author  FMSH Application Team
  * @brief   Src file of COMP LL Module
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
#include "fm33lc0xx_ll_comp.h"
#include "fm33lc0xx_ll_rcc.h"
#include "fm33_assert.h"


/** @addtogroup FM33LC0xx_LL_Driver_COMP
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup COMP_LL_Private_Macros
  * @{
  */  
#define         IS_COMP_ALL_INSTANCE(INTENCE)              (((INTENCE) == COMP1)||\
                                                            ((INTENCE) == COMP2))
                                                            
#define         IS_LL_COMP_POSITIVEINPUT(__VALUE__)        (((__VALUE__) == LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP1)||\
                                                             ((__VALUE__) == LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP2))
    
#define         IS_LL_COMP_NEGATIVEINPUT(__VALUE__)        (((__VALUE__) == LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_COMP_INN1)||\
                                                             ((__VALUE__) == LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_COMP_INN2)||\
                                                             ((__VALUE__) == LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF)||\
                                                             ((__VALUE__) == LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF_DIV_2))
                                                             
#define         IS_LL_COMP_POLARITY(__VALUE__)             (((__VALUE__) == LL_COMP_COMPARAROT_OUTPUT_POLARITY_NORMAL)||\
                                                             ((__VALUE__) == LL_COMP_COMPARAROT_OUTPUT_POLARITY_REVERSE))
                                                      
#define         IS_LL_COMP_EDGE(__VALUE__)                 (((__VALUE__) == LL_COMP_COMPARATOR_INTERRUPT_EDGE_BOTH)||\
                                                            ((__VALUE__) == LL_COMP_COMPARATOR_INTERRUPT_EDGE_RISING )||\
                                                            ((__VALUE__) == LL_COMP_COMPARATOR_INTERRUPT_EDGE_FALLING))
                                                             
#define         IS_LL_COMP_DIGITAL_FILTER(__VALUE__)       (((__VALUE__) == DISABLE)||\
                                                            ((__VALUE__) == ENABLE))
/**
  * @}
  */

/** @addtogroup COMP_LL_EF_Init
  * @{
  */ 
  
/**
  * @brief  复位对应COMP控制寄存器.
  * @param  COMPx COMP Port
  * @retval ErrorStatus枚举值:
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_COMP_DeInit(COMP_Type *COMPx)
{
    /* 入口参数检查 */
    assert_param(IS_COMP_ALL_INSTANCE(COMPx));
    /* 恢复寄存器值为默认值 */
    COMPx->CR = 0x00000000U;
    return PASS;
}

/**
  * @brief  根据 COMP_InitStruct的配置信息初始化对应外设.
  * @param  COMPx COMP Port
  * @param  COMP_InitStruct 指向一个 @ref LL_COMP_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @param  Serial 比较器序号可取值：
  *         1 配置比较器1
  *         2 配置比较器2
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功  
  */
ErrorStatus LL_COMP_Init(COMP_Type *COMPx, LL_COMP_InitTypeDef *COMP_InitStruct)
{
  
    /* 入口参数检查 */
    assert_param(IS_COMP_ALL_INSTANCE(COMPx));
    assert_param(IS_LL_COMP_EDGE(COMP_InitStruct->Edge));
    assert_param(IS_LL_COMP_POLARITY(COMP_InitStruct->Polarity));
    assert_param(IS_LL_COMP_POSITIVEINPUT(COMP_InitStruct->PositiveInput));
    assert_param(IS_LL_COMP_NEGATIVEINPUT(COMP_InitStruct->NegativeInput));
    assert_param(IS_LL_COMP_DIGITAL_FILTER(COMP_InitStruct->DigitalFilter));
    /* 使能时钟总线 */
    /* 比较器输出极性选择 */
    LL_COMP_SetComparatorPolarity(COMPx,COMP_InitStruct->Polarity);
    /* 比较器正向输入选择 */
    LL_COMP_SetComparatorPositiveInput(COMPx,COMP_InitStruct->PositiveInput);
    /* 比较器反向输入选择 */
    LL_COMP_SetComparatorNegativeInput(COMPx,COMP_InitStruct->NegativeInput);
    /* 比较器数字滤波 */
    if(COMPx == COMP1)
    {
        /* 比较器中断边沿选择 */
        LL_COMP_SetComper1InterruptEdge(COMP_COMMON,COMP_InitStruct->Edge);
        if(COMP_InitStruct->DigitalFilter)
        {
            LL_COMP_EnableDigitalFilter1(COMP_COMMON);
        }
        else
        {
            LL_COMP_DisableDigitalFilter1(COMP_COMMON);
        }
    }
    else
    {
        /* 比较器中断边沿选择 */
        LL_COMP_SetComper2InterruptEdge(COMP_COMMON,COMP_InitStruct->Edge);
        if(COMP_InitStruct->DigitalFilter)
        {
            LL_COMP_EnableDigitalFilter2(COMP_COMMON);
        }
        else
        {
            LL_COMP_DisableDigitalFilter2(COMP_COMMON);
        }
    }
    
    return PASS;
}
/**
  * @brief	设置 COMP_InitStruct 为默认配置
  * @param 	COMP_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_COMP_InitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_COMP_StructInit(LL_COMP_InitTypeDef *COMP_InitStruct)
{
  /* 复位配置信息 */
  COMP_InitStruct->Edge             = LL_COMP_COMPARATOR_INTERRUPT_EDGE_BOTH;
  COMP_InitStruct->Polarity         = LL_COMP_COMPARAROT_OUTPUT_POLARITY_NORMAL;
  COMP_InitStruct->NegativeInput    = LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_COMP_INN1;
  COMP_InitStruct->PositiveInput    = LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP1;
  COMP_InitStruct->DigitalFilter    = ENABLE;
}


/**
  * @}
  */

/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/
