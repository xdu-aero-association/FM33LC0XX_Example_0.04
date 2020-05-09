/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_rmu.h
  * @author  FMSH Application Team
  * @brief   Head file of RMU LL Module
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
#ifndef __FM33LC0XX_LL_RMU_H
#define __FM33LC0XX_LL_RMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_RMU
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup RMU_LL_ES_INIT RMU Exported Init structures
  * @{
  */

/**
  * @brief LL RMU Init Sturcture definition
  */
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup RMU_LL_Exported_Constants RMU Exported Constants
  * @{
  */

#define    LL_RMU_PDRPOWER_DOWN_RESET_1_5_VOLT                    (0x0U << RMU_PDRCR_CFG_Pos)
#define    LL_RMU_PDRPOWER_DOWN_RESET_1_25_VOLT                   (0x1U << RMU_PDRCR_CFG_Pos)
#define    LL_RMU_PDRPOWER_DOWN_RESET_1_35_VOLT                   (0x2U << RMU_PDRCR_CFG_Pos)
#define    LL_RMU_PDRPOWER_DOWN_RESET_1_4_VOLT                    (0x3U << RMU_PDRCR_CFG_Pos)

#define    LL_RMU_BORPOWER_DOWN_RESET_1_7_VOLT                    (0x0U << RMU_BORCR_CFG_Pos)
#define    LL_RMU_BORPOWER_DOWN_RESET_1_6_VOLT                    (0x1U << RMU_BORCR_CFG_Pos)
#define    LL_RMU_BORPOWER_DOWN_RESET_1_65_VOLT                   (0x2U << RMU_BORCR_CFG_Pos)
#define    LL_RMU_BORPOWER_DOWN_RESET_1_75_VOLT                   (0x3U << RMU_BORCR_CFG_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup RMU_LL_Exported_Functions RMU Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   PDRCR    CFG    LL_RMU_SetPowerDownResetCofig
  * @param    RMUx RMU instance
  * @param    ResetConfig This parameter can be one of the following values:
  *           @arg @ref LL_RMU_PDRPOWER_DOWN_RESET_1_5_VOLT
  *           @arg @ref LL_RMU_PDRPOWER_DOWN_RESET_1_25_VOLT
  *           @arg @ref LL_RMU_PDRPOWER_DOWN_RESET_1_35_VOLT
  *           @arg @ref LL_RMU_PDRPOWER_DOWN_RESET_1_4_VOLT
  * @retval   None
  */
__STATIC_INLINE void LL_RMU_SetPowerDownResetCofig(RMU_Type* RMUx, uint32_t ResetConfig)
{
    MODIFY_REG(RMUx->PDRCR, RMU_PDRCR_CFG_Msk, ResetConfig);
}

/**
  * @brief    
  * @rmtoll   PDRCR    CFG    LL_RMU_GetPowerDownResetCofig
  * @param    RMUx RMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RMU_PDRPOWER_DOWN_RESET_1_5_VOLT
  *           @arg @ref LL_RMU_PDRPOWER_DOWN_RESET_1_25_VOLT
  *           @arg @ref LL_RMU_PDRPOWER_DOWN_RESET_1_35_VOLT
  *           @arg @ref LL_RMU_PDRPOWER_DOWN_RESET_1_4_VOLT
  */
__STATIC_INLINE uint32_t LL_RMU_GetPowerDownResetCofig(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->PDRCR, RMU_PDRCR_CFG_Msk));
}

/**
  * @brief    
  * @rmtoll   PDRCR    EN    LL_RMU_IsEnabledPowerDownReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RMU_IsEnabledPowerDownReset(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->PDRCR, RMU_PDRCR_EN_Msk) == RMU_PDRCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   PDRCR    EN    LL_RMU_DisablePowerDownReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void LL_RMU_DisablePowerDownReset(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->PDRCR, RMU_PDRCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   PDRCR    EN    LL_RMU_EnablePowerDownReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void LL_RMU_EnablePowerDownReset(RMU_Type* RMUx)
{
    SET_BIT(RMUx->PDRCR, RMU_PDRCR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   BORCR    OFF_BOR_1P2    LL_RMU_IsEnabledBORPowerDownReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RMU_IsEnabledBORPowerDownReset(RMU_Type* RMUx)
{
    return (uint32_t)(!(READ_BIT(RMUx->BORCR, RMU_BORCR_OFF_BOR_1P2_Msk) == RMU_BORCR_OFF_BOR_1P2_Msk));
}

/**
  * @brief    
  * @rmtoll   BORCR    OFF_BOR_1P2    LL_RMU_DisableBORPowerDownReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void LL_RMU_DisableBORPowerDownReset(RMU_Type* RMUx)
{
    SET_BIT(RMUx->BORCR, RMU_BORCR_OFF_BOR_1P2_Msk);
}

/**
  * @brief    
  * @rmtoll   BORCR    OFF_BOR_1P2    LL_RMU_EnableBORPowerDownReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void LL_RMU_EnableBORPowerDownReset(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->BORCR, RMU_BORCR_OFF_BOR_1P2_Msk);
}

/**
  * @brief    
  * @rmtoll   BORCR    OFF_BOR_1P0    LL_RMU_IsEnabledPowerOnReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RMU_IsEnabledPowerOnReset(RMU_Type* RMUx)
{
    return (uint32_t)(!(READ_BIT(RMUx->BORCR, RMU_BORCR_OFF_BOR_1P0_Msk) == RMU_BORCR_OFF_BOR_1P0_Msk));
}

/**
  * @brief    
  * @rmtoll   BORCR    OFF_BOR_1P0    LL_RMU_DisablePowerOnReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void LL_RMU_DisablePowerOnReset(RMU_Type* RMUx)
{
    SET_BIT(RMUx->BORCR, RMU_BORCR_OFF_BOR_1P0_Msk);
}

/**
  * @brief    
  * @rmtoll   BORCR    OFF_BOR_1P0    LL_RMU_EnablePowerOnReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void LL_RMU_EnablePowerOnReset(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->BORCR, RMU_BORCR_OFF_BOR_1P0_Msk);
}

/**
  * @}
  */

/** @defgroup RMU_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_RMU_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-09-18**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
