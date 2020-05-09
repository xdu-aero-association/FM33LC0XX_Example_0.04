/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_crc.h
  * @author  FMSH Application Team
  * @brief   Head file of CRC LL Module
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
#ifndef __FM33LC0XX_LL_CRC_H
#define __FM33LC0XX_LL_CRC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_CRC
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup CRC_LL_ES_INIT CRC Exported Init structures
  * @{
  */

/**
  * @brief LL CRC Init Sturcture definition
  */
typedef struct
{
    /*! CRC初值 */
    uint32_t InitVel;         
    /*! 计算数据宽度 */
    uint32_t DataWidth;
    /*! 输入数据翻转 */
    uint32_t ReflectIn;
    /*! 输出数据翻转 */
    uint32_t ReflectOut;    
    /*! 输出结果异或寄存器 */    
    uint32_t XorReg;
    /*! 输出结果异或使能 */    
    uint32_t XorRegState;
    /*! CRC多项式宽 */    
    uint32_t PolynomialWidth;
    /*! CRC多项式 */    
    uint32_t Polynomial;
    /*! 计算模式 串行或并行 */    
    uint32_t CalculatMode;

}LL_CRC_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup CRC_LL_Exported_Constants CRC Exported Constants
  * @{
  */

#define    LL_CRC_CRC_DR_WIDTH_BYTE                               (0x0U << CRC_CR_OPWD_Pos)
#define    LL_CRC_CRC_DR_WIDTH_WORD                               (0x1U << CRC_CR_OPWD_Pos)

#define    LL_CRC_CALCULA_MODE_SERIAL                             (0x0U << CRC_CR_PARA_Pos)
#define    LL_CRC_CALCULA_MODE_PARALLEL                           (0x1U << CRC_CR_PARA_Pos)

#define    LL_CRC_INPUT_REFLECTE_MODE_NOMAL                       (0x0U << CRC_CR_RFLTIN_Pos)
#define    LL_CRC_INPUT_REFLECTE_MODE_BYTE                        (0x1U << CRC_CR_RFLTIN_Pos)
#define    LL_CRC_INPUT_REFLECTE_MODE_HALF_WORD                   (0x2U << CRC_CR_RFLTIN_Pos)
#define    LL_CRC_INPUT_REFLECTE_MODE_WORD                        (0x3U << CRC_CR_RFLTIN_Pos)

#define    LL_CRC_OUPUT_REFLECTE_MODE_NOMAL                       (0x0U << CRC_CR_RFLTO_Pos)
#define    LL_CRC_OUPUT_REFLECTE_MODE_REVERSE                     (0x1U << CRC_CR_RFLTO_Pos)

#define    LL_CRC_POLYNOMIAL_WIDTH_32BIT                          (0x0U << CRC_CR_SEL_Pos)
#define    LL_CRC_POLYNOMIAL_WIDTH_16BIT                          (0x1U << CRC_CR_SEL_Pos)
#define    LL_CRC_POLYNOMIAL_WIDTH_8BIT                           (0x2U << CRC_CR_SEL_Pos)
#define    LL_CRC_POLYNOMIAL_WIDTH_7BIT                           (0x3U << CRC_CR_SEL_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup CRC_LL_Exported_Functions CRC Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   DR        LL_CRC_SetDataReg
  * @param    CRCx CRC instance
  * @param    Data 
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_SetDataReg(CRC_Type* CRCx, uint32_t Data)
{
    MODIFY_REG(CRCx->DR, (0xffffffffU << 0U), (Data << 0U));
}

/**
  * @brief    
  * @rmtoll   DR        LL_CRC_GetDataReg
  * @param    CRCx CRC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_CRC_GetDataReg(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->DR, 0xffffffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   CR    OPWD    LL_CRC_SetDataRegWidth
  * @param    CRCx CRC instance
  * @param    DataWidth This parameter can be one of the following values:
  *           @arg @ref LL_CRC_CRC_DR_WIDTH_BYTE
  *           @arg @ref LL_CRC_CRC_DR_WIDTH_WORD
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_SetDataRegWidth(CRC_Type* CRCx, uint32_t DataWidth)
{
    MODIFY_REG(CRCx->CR, CRC_CR_OPWD_Msk, DataWidth);
}

/**
  * @brief    
  * @rmtoll   CR    OPWD    LL_CRC_GetDataRegWidth
  * @param    CRCx CRC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_CRC_CRC_DR_WIDTH_BYTE
  *           @arg @ref LL_CRC_CRC_DR_WIDTH_WORD
  */
__STATIC_INLINE uint32_t LL_CRC_GetDataRegWidth(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_OPWD_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    PARA    LL_CRC_SetCalcuaMode
  * @param    CRCx CRC instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref LL_CRC_CALCULA_MODE_SERIAL
  *           @arg @ref LL_CRC_CALCULA_MODE_PARALLEL
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_SetCalcuaMode(CRC_Type* CRCx, uint32_t Mode)
{
    MODIFY_REG(CRCx->CR, CRC_CR_PARA_Msk, Mode);
}

/**
  * @brief    
  * @rmtoll   CR    PARA    LL_CRC_GetCalcuaMode
  * @param    CRCx CRC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_CRC_CALCULA_MODE_SERIAL
  *           @arg @ref LL_CRC_CALCULA_MODE_PARALLEL
  */
__STATIC_INLINE uint32_t LL_CRC_GetCalcuaMode(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_PARA_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    RFLTIN    LL_CRC_SetInputReflection
  * @param    CRCx CRC instance
  * @param    ReflectMode This parameter can be one of the following values:
  *           @arg @ref LL_CRC_INPUT_REFLECTE_MODE_NOMAL
  *           @arg @ref LL_CRC_INPUT_REFLECTE_MODE_BYTE
  *           @arg @ref LL_CRC_INPUT_REFLECTE_MODE_HALF_WORD
  *           @arg @ref LL_CRC_INPUT_REFLECTE_MODE_WORD
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_SetInputReflection(CRC_Type* CRCx, uint32_t ReflectMode)
{
    MODIFY_REG(CRCx->CR, CRC_CR_RFLTIN_Msk, ReflectMode);
}

/**
  * @brief    
  * @rmtoll   CR    RFLTIN    LL_CRC_GetInputReflection
  * @param    CRCx CRC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_CRC_INPUT_REFLECTE_MODE_NOMAL
  *           @arg @ref LL_CRC_INPUT_REFLECTE_MODE_BYTE
  *           @arg @ref LL_CRC_INPUT_REFLECTE_MODE_HALF_WORD
  *           @arg @ref LL_CRC_INPUT_REFLECTE_MODE_WORD
  */
__STATIC_INLINE uint32_t LL_CRC_GetInputReflection(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_RFLTIN_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    RFLTO    LL_CRC_SetOutPutReflection
  * @param    CRCx CRC instance
  * @param    ReflectMode This parameter can be one of the following values:
  *           @arg @ref LL_CRC_OUPUT_REFLECTE_MODE_NOMAL
  *           @arg @ref LL_CRC_OUPUT_REFLECTE_MODE_REVERSE
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_SetOutPutReflection(CRC_Type* CRCx, uint32_t ReflectMode)
{
    MODIFY_REG(CRCx->CR, CRC_CR_RFLTO_Msk, ReflectMode);
}

/**
  * @brief    
  * @rmtoll   CR    RFLTO    LL_CRC_GetOutPutReflection
  * @param    CRCx CRC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_CRC_OUPUT_REFLECTE_MODE_NOMAL
  *           @arg @ref LL_CRC_OUPUT_REFLECTE_MODE_REVERSE
  */
__STATIC_INLINE uint32_t LL_CRC_GetOutPutReflection(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_RFLTO_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    RES    LL_CRC_IsActiveFlag_ResultTrue
  * @param    CRCx CRC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CRC_IsActiveFlag_ResultTrue(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_RES_Msk) == (CRC_CR_RES_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    BUSY    LL_CRC_IsActiveFlag_Busy
  * @param    CRCx CRC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CRC_IsActiveFlag_Busy(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_BUSY_Msk) == (CRC_CR_BUSY_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    XOR    LL_CRC_Enable_OutPutXOR
  * @param    CRCx CRC instance
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_Enable_OutPutXOR(CRC_Type* CRCx)
{
    SET_BIT(CRCx->CR, CRC_CR_XOR_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    XOR    LL_CRC_IsEnabled_OutPutXOR
  * @param    CRCx CRC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_CRC_IsEnabled_OutPutXOR(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_XOR_Msk) == CRC_CR_XOR_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    XOR    LL_CRC_Disable_OutPutXOR
  * @param    CRCx CRC instance
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_Disable_OutPutXOR(CRC_Type* CRCx)
{
    CLEAR_BIT(CRCx->CR, CRC_CR_XOR_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    SEL    LL_CRC_SetPolynomialWidth
  * @param    CRCx CRC instance
  * @param    Width This parameter can be one of the following values:
  *           @arg @ref LL_CRC_POLYNOMIAL_WIDTH_32BIT
  *           @arg @ref LL_CRC_POLYNOMIAL_WIDTH_16BIT
  *           @arg @ref LL_CRC_POLYNOMIAL_WIDTH_8BIT
  *           @arg @ref LL_CRC_POLYNOMIAL_WIDTH_7BIT
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_SetPolynomialWidth(CRC_Type* CRCx, uint32_t Width)
{
    MODIFY_REG(CRCx->CR, CRC_CR_SEL_Msk, Width);
}

/**
  * @brief    
  * @rmtoll   CR    SEL    LL_CRC_GetPolynomialWidth
  * @param    CRCx CRC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_CRC_POLYNOMIAL_WIDTH_32BIT
  *           @arg @ref LL_CRC_POLYNOMIAL_WIDTH_16BIT
  *           @arg @ref LL_CRC_POLYNOMIAL_WIDTH_8BIT
  *           @arg @ref LL_CRC_POLYNOMIAL_WIDTH_7BIT
  */
__STATIC_INLINE uint32_t LL_CRC_GetPolynomialWidth(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   LFSR        LL_CRC_SetLinearShiftReg
  * @param    CRCx CRC instance
  * @param    Data 
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_SetLinearShiftReg(CRC_Type* CRCx, uint32_t Data)
{
    MODIFY_REG(CRCx->LFSR, (0xffffffffU << 0U), (Data << 0U));
}

/**
  * @brief    
  * @rmtoll   LFSR        LL_CRC_GetLinearShiftReg
  * @param    CRCx CRC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_CRC_GetLinearShiftReg(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->LFSR, 0xffffffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   XOR        LL_CRC_SetOutPutXORReg
  * @param    CRCx CRC instance
  * @param    Data 
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_SetOutPutXORReg(CRC_Type* CRCx, uint32_t Data)
{
    MODIFY_REG(CRCx->XOR, (0xffffffffU << 0U), (Data << 0U));
}

/**
  * @brief    
  * @rmtoll   XOR        LL_CRC_GetOutPutXORReg
  * @param    CRCx CRC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_CRC_GetOutPutXORReg(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->XOR, 0xffffffffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   POLY        LL_CRC_SetPolynominalsReg
  * @param    CRCx CRC instance
  * @param    Data 
  * @retval   None
  */
__STATIC_INLINE void LL_CRC_SetPolynominalsReg(CRC_Type* CRCx, uint32_t Data)
{
    MODIFY_REG(CRCx->POLY, (0xffffffffU << 0U), (Data << 0U));
}

/**
  * @brief    
  * @rmtoll   POLY        LL_CRC_GetPolynominalsReg
  * @param    CRCx CRC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_CRC_GetPolynominalsReg(CRC_Type* CRCx)
{
    return (uint32_t)(READ_BIT(CRCx->POLY, 0xffffffffU) >> 0U);
}

/**
  * @}
  */

/** @defgroup CRC_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_CRC_DeInit(CRC_Type *CRCx);
void LL_CRC_StructInit(LL_CRC_InitTypeDef *CRC_InitStruct);
ErrorStatus LL_CRC_Init(CRC_Type *CRCx,LL_CRC_InitTypeDef *CRC_InitStruct);
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_CRC_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-25**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
