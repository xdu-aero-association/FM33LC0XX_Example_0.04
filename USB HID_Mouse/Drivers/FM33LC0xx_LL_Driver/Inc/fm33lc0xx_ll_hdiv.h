/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_hdiv.h
  * @author  FMSH Application Team
  * @brief   Head file of HDIV LL Module
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
#ifndef __FM33LC0XX_LL_HDIV_H
#define __FM33LC0XX_LL_HDIV_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_HDIV
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup HDIV_LL_ES_INIT HDIV Exported Init structures
  * @{
  */

/**
  * @brief LL HDIV Init Sturcture definition
  */
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup HDIV_LL_Exported_Constants HDIV Exported Constants
  * @{
  */
  
#define    LL_HDIV_SR_BUSY_TIMEOUT                                (0xFFFU)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup HDIV_LL_Exported_Functions HDIV Exported Functions
  * @{
  */

/**
  * @brief    Write 32bit Signed Dividend
  * @rmtoll   END        LL_HDIV_SetDivisorEnd
  * @param    HDIVx HDIV instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void LL_HDIV_SetDivisorEnd(HDIV_Type* HDIVx, int32_t number)
{
    MODIFY_REG(HDIVx->END, (0xFFFFFFFFU << 0U), (number << 0U));
}

/**
  * @brief    Read 32bit Signed Dividend
  * @rmtoll   END        LL_HDIV_GetDivisorEnd
  * @param    HDIVx HDIV instance
  * @retval   
  */
__STATIC_INLINE int32_t LL_HDIV_GetDivisorEnd(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->END, 0xFFFFFFFFU) >> 0U);
}

/**
  * @brief    Write 16bit Signed Dividend
  * @rmtoll   SOR        LL_HDIV_SetDivisor
  * @param    HDIVx HDIV instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void LL_HDIV_SetDivisor(HDIV_Type* HDIVx, int32_t number)
{
    MODIFY_REG(HDIVx->SOR, (0xFFFFU << 0U), (number << 0U));
}

/**
  * @brief    Read 16bit Signed Dividend
  * @rmtoll   SOR        LL_HDIV_GetDivisor
  * @param    HDIVx HDIV instance
  * @retval   
  */
__STATIC_INLINE int32_t LL_HDIV_GetDivisor(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->SOR, 0xFFFFU) >> 0U);
}

/**
  * @brief    Read 32bit Signed QUTO 
  * @rmtoll   QUOT        LL_HDIV_GetQuotient
  * @param    HDIVx HDIV instance
  * @retval   
  */
__STATIC_INLINE int32_t LL_HDIV_GetQuotient(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->QUOT, 0xFFFFFFFFU) >> 0U);
}

/**
  * @brief    Read 16bit Signed Reminder 
  * @rmtoll   REMD        LL_HDIV_GetResidue
  * @param    HDIVx HDIV instance
  * @retval   
  */
__STATIC_INLINE int32_t LL_HDIV_GetResidue(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->REMD, 0xFFFFU) >> 0U);
}

/**
  * @brief    Get divided by 0 flag
  * @rmtoll   SR    DIV_BY_0    LL_HDIV_IsActiveDividedZero
  * @param    HDIVx HDIV instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_HDIV_IsActiveDividedZero(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->SR, HDIV_SR_DIV_BY_0_Msk) == (HDIV_SR_DIV_BY_0_Msk));
}

/**
  * @brief    Get Busy flag
  * @rmtoll   SR    BUSY    LL_HDIV_IsActiveBusy
  * @param    HDIVx HDIV instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_HDIV_IsActiveBusy(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->SR, HDIV_SR_BUSY_Msk) == (HDIV_SR_BUSY_Msk));
}

/**
  * @}
  */

/** @defgroup HDIV_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_HDIV_DeInit(HDIV_Type *HDIVx);
ErrorStatus LL_HDIV_Init(HDIV_Type *HDIVx);
uint32_t LL_HDIV_Calculation(HDIV_Type *HDIVx,int32_t DivisorEnd,int16_t Divisor,int32_t* Quotient, int16_t* Residue);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_HDIV_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-12-02**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
