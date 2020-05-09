/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_comp.h
  * @author  FMSH Application Team
  * @brief   Head file of COMP LL Module
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


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33LC0XX_LL_COMP_H
#define __FM33LC0XX_LL_COMP_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_COMP
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup COMP_LL_ES_INIT COMP Exported Init structures
  * @{
  */

/**
  * @brief LL COMP Init Sturcture definition
  */
typedef struct
{
    /*! 比较器正向输入选择 */
    uint32_t PositiveInput;          
    /*! 比较器反向输入选择 */
    uint32_t NegativeInput;
    /*! 结果输出极性 */      
    uint32_t Polarity;
    /*! 中断触发边沿选择 */                                             
    uint32_t Edge;
    /*! 数字滤波器使能 */  
    uint32_t DigitalFilter;  
                                                      
} LL_COMP_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup COMP_LL_Exported_Constants COMP Exported Constants
  * @{
  */




#define    LL_COMP_COMPARAROT_OUTPUT_POLARITY_NORMAL              (0x0U << COMP_CR_POL_Pos)
#define    LL_COMP_COMPARAROT_OUTPUT_POLARITY_REVERSE             (0x1U << COMP_CR_POL_Pos)


#define    LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP1            (0x0U << COMP_CR_VPSEL_Pos)
#define    LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP2            (0x1U << COMP_CR_VPSEL_Pos)
#define    LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP3            (0x2U << COMP_CR_VPSEL_Pos)



#define    LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_COMP_INN1          (0x0U << COMP_CR_VNSEL_Pos)
#define    LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_COMP_INN2          (0x1U << COMP_CR_VNSEL_Pos)
#define    LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF               (0x2U << COMP_CR_VNSEL_Pos)
#define    LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF_DIV_2         (0x3U << COMP_CR_VNSEL_Pos)

#define    LL_COMP_COMPARATOR_INTERRUPT_EDGE_BOTH                 (0x0U)
#define    LL_COMP_COMPARATOR_INTERRUPT_EDGE_RISING               (0x1U)
#define    LL_COMP_COMPARATOR_INTERRUPT_EDGE_FALLING              (0x2U)





/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup COMP_LL_Exported_Functions COMP Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CR    CMPO    LL_COMP_GetComparatorOutput
  * @param    COMPx COMP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_GetComparatorOutput(COMP_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CR, COMP_CR_CMPO_Msk) == (COMP_CR_CMPO_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    POL    LL_COMP_SetComparatorPolarity
  * @param    COMPx COMP instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref LL_COMP_COMPARAROT_OUTPUT_POLARITY_NORMAL
  *           @arg @ref LL_COMP_COMPARAROT_OUTPUT_POLARITY_REVERSE
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_SetComparatorPolarity(COMP_Type* COMPx, uint32_t polarity)
{
    MODIFY_REG(COMPx->CR, COMP_CR_POL_Msk, polarity);
}

/**
  * @brief    
  * @rmtoll   CR    POL    LL_COMP_GetComparatorPolarity
  * @param    COMPx COMP instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_COMP_COMPARAROT_OUTPUT_POLARITY_NORMAL
  *           @arg @ref LL_COMP_COMPARAROT_OUTPUT_POLARITY_REVERSE
  */
__STATIC_INLINE uint32_t LL_COMP_GetComparatorPolarity(COMP_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CR, COMP_CR_POL_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    VPSEL    LL_COMP_SetComparatorPositiveInput
  * @param    COMPx COMP instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP1
  *           @arg @ref LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP2
  *           @arg @ref LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP3
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_SetComparatorPositiveInput(COMP_Type* COMPx, uint32_t Input)
{
    MODIFY_REG(COMPx->CR, COMP_CR_VPSEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   CR    VPSEL    LL_COMP_GetComparatorPositiveInput
  * @param    COMPx COMP instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP1
  *           @arg @ref LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP2
  *           @arg @ref LL_COMP_COMPARAROT_POSITIVE_INPUT_COMP_INP3
  */
__STATIC_INLINE uint32_t LL_COMP_GetComparatorPositiveInput(COMP_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CR, COMP_CR_VPSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    VNSEL    LL_COMP_SetComparatorNegativeInput
  * @param    COMPx COMP instance
  * @param    Input This parameter can be one of the following values:
  *           @arg @ref LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_COMP_INN1
  *           @arg @ref LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF
  *           @arg @ref LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF_DIV_2
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_SetComparatorNegativeInput(COMP_Type* COMPx, uint32_t Input)
{
    MODIFY_REG(COMPx->CR, COMP_CR_VNSEL_Msk, Input);
}

/**
  * @brief    
  * @rmtoll   CR    VNSEL    LL_COMP_GetComparatorNegativeInput
  * @param    COMPx COMP instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_COMP_INN1
  *           @arg @ref LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF
  *           @arg @ref LL_COMP_COMPARAROT_NEGATIVEVE_INPUT_VREF_DIV_2
  */
__STATIC_INLINE uint32_t LL_COMP_GetComparatorNegativeInput(COMP_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CR, COMP_CR_VNSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    CMPEN    LL_COMP_Enable
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_Enable(COMP_Type* COMPx)
{
    SET_BIT(COMPx->CR, COMP_CR_CMPEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    CMPEN    LL_COMP_IsEnabled
  * @param    COMPx COMP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsEnabled(COMP_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CR, COMP_CR_CMPEN_Msk) == COMP_CR_CMPEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    CMPEN    LL_COMP_Disable
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_Disable(COMP_Type* COMPx)
{
    CLEAR_BIT(COMPx->CR, COMP_CR_CMPEN_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP1DF    LL_COMP_EnableDigitalFilter1
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_EnableDigitalFilter1(COMP_COMMON_Type* COMPx)
{
    SET_BIT(COMPx->ICR, COMP_ICR_CMP1DF_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP1DF    LL_COMP_IsEnabledDigitalFilter1
  * @param    COMPx COMP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsEnabledDigitalFilter1(COMP_COMMON_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->ICR, COMP_ICR_CMP1DF_Msk) == COMP_ICR_CMP1DF_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP1DF    LL_COMP_DisableDigitalFilter1
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_DisableDigitalFilter1(COMP_COMMON_Type* COMPx)
{
    CLEAR_BIT(COMPx->ICR, COMP_ICR_CMP1DF_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP2DF    LL_COMP_EnableDigitalFilter2
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_EnableDigitalFilter2(COMP_COMMON_Type* COMPx)
{
    SET_BIT(COMPx->ICR, COMP_ICR_CMP2DF_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP2DF    LL_COMP_IsEnabledDigitalFilter2
  * @param    COMPx COMP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsEnabledDigitalFilter2(COMP_COMMON_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->ICR, COMP_ICR_CMP2DF_Msk) == COMP_ICR_CMP2DF_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP2DF    LL_COMP_DisableDigitalFilter2
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_DisableDigitalFilter2(COMP_COMMON_Type* COMPx)
{
    CLEAR_BIT(COMPx->ICR, COMP_ICR_CMP2DF_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP1IE    LL_COMP_EnableITComper1
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_EnableITComper1(COMP_COMMON_Type* COMPx)
{
    SET_BIT(COMPx->ICR, COMP_ICR_CMP1IE_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP1IE    LL_COMP_IsEnabledITComper1
  * @param    COMPx COMP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsEnabledITComper1(COMP_COMMON_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->ICR, COMP_ICR_CMP1IE_Msk) == COMP_ICR_CMP1IE_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP1IE    LL_COMP_DisableITComper1
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_DisableITComper1(COMP_COMMON_Type* COMPx)
{
    CLEAR_BIT(COMPx->ICR, COMP_ICR_CMP1IE_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP2IE    LL_COMP_EnableITComper2
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_EnableITComper2(COMP_COMMON_Type* COMPx)
{
    SET_BIT(COMPx->ICR, COMP_ICR_CMP2IE_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP2IE    LL_COMP_IsEnabledITComper2
  * @param    COMPx COMP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsEnabledITComper2(COMP_COMMON_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->ICR, COMP_ICR_CMP2IE_Msk) == COMP_ICR_CMP2IE_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP2IE    LL_COMP_DisableITComper2
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_DisableITComper2(COMP_COMMON_Type* COMPx)
{
    CLEAR_BIT(COMPx->ICR, COMP_ICR_CMP2IE_Msk);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP2SEL    LL_COMP_SetComper2InterruptEdge
  * @param    COMPx COMP instance
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref LL_COMP_COMPARATOR_INTERRUPT_EDGE_BOTH
  *           @arg @ref LL_COMP_COMPARATOR_INTERRUPT_EDGE_RISING
  *           @arg @ref LL_COMP_COMPARATOR_INTERRUPT_EDGE_FALLING
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_SetComper2InterruptEdge(COMP_COMMON_Type* COMPx, uint32_t edge)
{
    MODIFY_REG(COMPx->ICR, COMP_ICR_CMP2SEL_Msk, edge<COMP_ICR_CMP2SEL_Pos);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP2SEL    LL_COMP_GetComper2InterruptEdge
  * @param    COMPx COMP instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_COMP_COMPARATOR_INTERRUPT_EDGE_BOTH
  *           @arg @ref LL_COMP_COMPARATOR_INTERRUPT_EDGE_RISING
  *           @arg @ref LL_COMP_COMPARATOR_INTERRUPT_EDGE_FALLING
  */
__STATIC_INLINE uint32_t LL_COMP_GetComper2InterruptEdge(COMP_COMMON_Type* COMPx)
{
    return (uint32_t)((READ_BIT(COMPx->ICR, COMP_ICR_CMP2SEL_Msk))>>COMP_ICR_CMP2SEL_Pos);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP1SEL    LL_COMP_SetComper1InterruptEdge
  * @param    COMPx COMP instance
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref LL_COMP_COMPARATOR2_INTERRUPT_EDGE_BOTH
  *           @arg @ref LL_COMP_COMPARATOR2_INTERRUPT_EDGE_RISING
  *           @arg @ref LL_COMP_COMPARATOR2_INTERRUPT_EDGE_FALLING
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_SetComper1InterruptEdge(COMP_COMMON_Type* COMPx, uint32_t edge)
{
    MODIFY_REG(COMPx->ICR, COMP_ICR_CMP1SEL_Msk, edge<<COMP_ICR_CMP1SEL_Pos);
}

/**
  * @brief    
  * @rmtoll   ICR    CMP1SEL    LL_COMP_GetComper1InterruptEdge
  * @param    COMPx COMP instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_COMP_COMPARATOR1_INTERRUPT_EDGE_BOTH
  *           @arg @ref LL_COMP_COMPARATOR1_INTERRUPT_EDGE_RISING
  *           @arg @ref LL_COMP_COMPARATOR1_INTERRUPT_EDGE_FALLING
  */
__STATIC_INLINE uint32_t LL_COMP_GetComper1InterruptEdge(COMP_COMMON_Type* COMPx)
{
    return (uint32_t)((READ_BIT(COMPx->ICR, COMP_ICR_CMP1SEL_Msk))>>COMP_ICR_CMP2SEL_Pos);
}

/**
  * @brief    
  * @rmtoll   ISR    CMP2IF    LL_COMP_IsActiveComparator2
  * @param    COMPx COMP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsActiveComparator2(COMP_COMMON_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->ISR, COMP_ISR_CMP2IF_Msk) == (COMP_ISR_CMP2IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    CMP2IF    LL_COMP_ClearFlag_Comparator2
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_ClearFlag_Comparator2(COMP_COMMON_Type* COMPx)
{
    WRITE_REG(COMPx->ISR, COMP_ISR_CMP2IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    CMP1IF    LL_COMP_IsActiveComparator1
  * @param    COMPx COMP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsActiveComparator1(COMP_COMMON_Type* COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->ISR, COMP_ISR_CMP1IF_Msk) == (COMP_ISR_CMP1IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    CMP1IF    LL_COMP_ClearFlag_Comparator1
  * @param    COMPx COMP instance
  * @retval   None
  */
__STATIC_INLINE void LL_COMP_ClearFlag_Comparator1(COMP_COMMON_Type* COMPx)
{
    WRITE_REG(COMPx->ISR, COMP_ISR_CMP1IF_Msk);
}

/**
  * @}
  */

/** @defgroup COMP_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_COMP_DeInit(COMP_Type *COMPx);
void LL_COMP_StructInit(LL_COMP_InitTypeDef *COMP_InitStruct);
ErrorStatus LL_COMP_Init(COMP_Type *COMPx, LL_COMP_InitTypeDef *COMP_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_COMP_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2020-04-08**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
