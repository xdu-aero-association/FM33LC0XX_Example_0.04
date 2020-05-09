/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_svd.h
  * @author  FMSH Application Team
  * @brief   Head file of SVD LL Module
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
#ifndef __FM33LC0XX_LL_SVD_H
#define __FM33LC0XX_LL_SVD_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_SVD
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup SVD_LL_ES_INIT SVD Exported Init structures
  * @{
  */

/**
  * @brief LL SVD Init Sturcture definition
  */
typedef struct{
    
    /*! SVD 工作模式 */
    uint32_t  Mode;
    /*! 间歇工作模式下的使能周期 */
    uint32_t  Interval;
    /*! SVD 报警阈值设置 */
    uint32_t  Threshold;
    /*! SVD 参考电压选择 */
    uint32_t  VrefSelect;
    /*! SVD 数字滤波使能与否 */
    FunState  DigitalFilter;
    
}SVD_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup SVD_LL_Exported_Constants SVD Exported Constants
  * @{
  */
#define    LL_SVD_REFERENCE_VOLTAGE_1_2_VOLT                      (0x1U << 2U)
#define    LL_SVD_REFERENCE_VOLTAGE_1_1_VOLT                      (0x1U << 1U)
#define    LL_SVD_REFERENCE_VOLTAGE_1_0_VOLT                      (0x1U << 0U)

#define    LL_SVD_ADC_SVD_GEAR_3_300VOLT                          (0x0U << SVD_CFGR_ADSVD_SEL_Pos)
#define    LL_SVD_ADC_SVD_GEAR_3_514VOLT                          (0x1U << SVD_CFGR_ADSVD_SEL_Pos)
#define    LL_SVD_ADC_SVD_GEAR_3_729VOLT                          (0x2U << SVD_CFGR_ADSVD_SEL_Pos)
#define    LL_SVD_ADC_SVD_GEAR_3_943VOLT                          (0x3U << SVD_CFGR_ADSVD_SEL_Pos)
#define    LL_SVD_ADC_SVD_GEAR_4_157VOLT                          (0x4U << SVD_CFGR_ADSVD_SEL_Pos)
#define    LL_SVD_ADC_SVD_GEAR_4_371VOLT                          (0x5U << SVD_CFGR_ADSVD_SEL_Pos)
#define    LL_SVD_ADC_SVD_GEAR_4_586VOLT                          (0x6U << SVD_CFGR_ADSVD_SEL_Pos)
#define    LL_SVD_ADC_SVD_GEAR_4_800VOLT                          (0x7U << SVD_CFGR_ADSVD_SEL_Pos)

#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP0         (0x0U << SVD_CFGR_LVL_Pos)

#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP1         (0x1U << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP2         (0x2U << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP3         (0x3U << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP4         (0x4U << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP5         (0x5U << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP6         (0x6U << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP7         (0x7U << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP8         (0x8U << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP9         (0x9U << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP10        (0xaU << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP11        (0xbU << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP12        (0xcU << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP13        (0xdU << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP14        (0xeU << SVD_CFGR_LVL_Pos)
#define    LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_SVSBASE        (0xfU << SVD_CFGR_LVL_Pos)

#define    LL_SVD_WORK_MODE_ALWAYS                                (0x0U << SVD_CFGR_MOD_Pos)
#define    LL_SVD_WORK_MODE_INTERMITTENT                          (0x1U << SVD_CFGR_MOD_Pos)

#define    LL_SVD_INTERVEL_ENABLE_PERIOD_62MS                     (0x0U << SVD_CFGR_ITVL_Pos)
#define    LL_SVD_INTERVEL_ENABLE_PERIOD_256MS                    (0x1U << SVD_CFGR_ITVL_Pos)
#define    LL_SVD_INTERVEL_ENABLE_PERIOD_1000MS                   (0x2U << SVD_CFGR_ITVL_Pos)
#define    LL_SVD_INTERVEL_ENABLE_PERIOD_4000MS                   (0x3U << SVD_CFGR_ITVL_Pos)

#define    LL_SVD_POWER_VOLTAGE_STATUS_LESS_THRESHOLD             (0x0U << SVD_ISR_SVDO_Pos)
#define    LL_SVD_POWER_VOLTAGE_STATUS_GREATER_THRESHOLD          (0x1U << SVD_ISR_SVDO_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup SVD_LL_Exported_Functions SVD Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CFGR    ADSVD_SEL    LL_SVD_SetADCSVD_Gear
  * @param    SVDx SVD instance
  * @param    gear This parameter can be one of the following values:
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_3_300VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_3_514VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_3_729VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_3_943VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_4_157VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_4_371VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_4_586VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_4_800VOLT
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_SetADCSVD_Gear(SVD_Type* SVDx, uint32_t gear)
{
    MODIFY_REG(SVDx->CFGR, SVD_CFGR_ADSVD_SEL_Msk, gear);
}

/**
  * @brief    
  * @rmtoll   CFGR    ADSVD_SEL    LL_SVD_GetADCSVD_Gear
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_3_300VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_3_514VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_3_729VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_3_943VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_4_157VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_4_371VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_4_586VOLT
  *           @arg @ref LL_SVD_ADC_SVD_GEAR_4_800VOLT
  */
__STATIC_INLINE uint32_t LL_SVD_GetADCSVD_Gear(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CFGR, SVD_CFGR_ADSVD_SEL_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    LVL    LL_SVD_SetSVDThresholdLevel
  * @param    SVDx SVD instance
  * @param    level This parameter can be one of the following values:
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP0
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP1
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP2
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP3
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP4
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP5
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP6
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP7
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP8
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP9
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP10
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP11
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP12
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP13
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP14
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_SetSVDThresholdLevel(SVD_Type* SVDx, uint32_t level)
{
    MODIFY_REG(SVDx->CFGR, SVD_CFGR_LVL_Msk, level);
}

/**
  * @brief    
  * @rmtoll   CFGR    LVL    LL_SVD_GetSVDThresholdLevel
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP0
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP1
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP2
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP3
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP4
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP5
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP6
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP7
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP8
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP9
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP10
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP11
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP12
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP13
  *           @arg @ref LL_SVD_WARNING_THRESHOLD_LEVEL_STANDARD_GTOUP14
  */
__STATIC_INLINE uint32_t LL_SVD_GetSVDThresholdLevel(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CFGR, SVD_CFGR_LVL_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    DFEN    LL_SVD_EnableSVDDigitalFiltering
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_EnableSVDDigitalFiltering(SVD_Type* SVDx)
{
    SET_BIT(SVDx->CFGR, SVD_CFGR_DFEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    DFEN    LL_SVD_IsEnabledSVDDigitalFiltering
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsEnabledSVDDigitalFiltering(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CFGR, SVD_CFGR_DFEN_Msk) == SVD_CFGR_DFEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    DFEN    LL_SVD_DisableSVDDigitalFiltering
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_DisableSVDDigitalFiltering(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->CFGR, SVD_CFGR_DFEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CFGR    MOD    LL_SVD_SetSVDWorkMode
  * @param    SVDx SVD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_SVD_WORK_MODE_ALWAYS
  *           @arg @ref LL_SVD_WORK_MODE_INTERMITTENT
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_SetSVDWorkMode(SVD_Type* SVDx, uint32_t mode)
{
    MODIFY_REG(SVDx->CFGR, SVD_CFGR_MOD_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CFGR    MOD    LL_SVD_GetSVDWorkMode
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SVD_WORK_MODE_ALWAYS
  *           @arg @ref LL_SVD_WORK_MODE_INTERMITTENT
  */
__STATIC_INLINE uint32_t LL_SVD_GetSVDWorkMode(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CFGR, SVD_CFGR_MOD_Msk));
}

/**
  * @brief    
  * @rmtoll   CFGR    ITVL    LL_SVD_SetSVDInterValEnablePeriod
  * @param    SVDx SVD instance
  * @param    period This parameter can be one of the following values:
  *           @arg @ref LL_SVD_INTERVEL_ENABLE_PERIOD_62MS
  *           @arg @ref LL_SVD_INTERVEL_ENABLE_PERIOD_256MS
  *           @arg @ref LL_SVD_INTERVEL_ENABLE_PERIOD_1000MS
  *           @arg @ref LL_SVD_INTERVEL_ENABLE_PERIOD_4000MS
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_SetSVDInterValEnablePeriod(SVD_Type* SVDx, uint32_t period)
{
    MODIFY_REG(SVDx->CFGR, SVD_CFGR_ITVL_Msk, period);
}

/**
  * @brief    
  * @rmtoll   CFGR    ITVL    LL_SVD_GetSVDInterValEnablePeriod
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SVD_INTERVEL_ENABLE_PERIOD_62MS
  *           @arg @ref LL_SVD_INTERVEL_ENABLE_PERIOD_256MS
  *           @arg @ref LL_SVD_INTERVEL_ENABLE_PERIOD_1000MS
  *           @arg @ref LL_SVD_INTERVEL_ENABLE_PERIOD_4000MS
  */
__STATIC_INLINE uint32_t LL_SVD_GetSVDInterValEnablePeriod(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CFGR, SVD_CFGR_ITVL_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    SVSEN    LL_SVD_EnableSVDSVSChannel
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_EnableSVDSVSChannel(SVD_Type* SVDx)
{
    SET_BIT(SVDx->CR, SVD_CR_SVSEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    SVSEN    LL_SVD_IsEnabledSVDSVSChannel
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsEnabledSVDSVSChannel(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CR, SVD_CR_SVSEN_Msk) == SVD_CR_SVSEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    SVSEN    LL_SVD_DisableSVDSVSChannel
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_DisableSVDSVSChannel(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->CR, SVD_CR_SVSEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    EN    LL_SVD_EnableSVD
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_EnableSVD(SVD_Type* SVDx)
{
    SET_BIT(SVDx->CR, SVD_CR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    EN    LL_SVD_IsEnabledSVD
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsEnabledSVD(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->CR, SVD_CR_EN_Msk) == SVD_CR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    EN    LL_SVD_DisableSVD
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_DisableSVD(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->CR, SVD_CR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    PFIE    LL_SVD_EnableITPowerFall
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_EnableITPowerFall(SVD_Type* SVDx)
{
    SET_BIT(SVDx->IER, SVD_IER_PFIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    PFIE    LL_SVD_IsEnabledITPowerFall
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsEnabledITPowerFall(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->IER, SVD_IER_PFIE_Msk) == SVD_IER_PFIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    PFIE    LL_SVD_DisableITPowerFall
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_DisableITPowerFall(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->IER, SVD_IER_PFIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    PRIE    LL_SVD_EnableITPowerRise
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_EnableITPowerRise(SVD_Type* SVDx)
{
    SET_BIT(SVDx->IER, SVD_IER_PRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    PRIE    LL_SVD_IsEnabledITPowerRise
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsEnabledITPowerRise(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->IER, SVD_IER_PRIE_Msk) == SVD_IER_PRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    PRIE    LL_SVD_DisableITPowerRise
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_DisableITPowerRise(SVD_Type* SVDx)
{
    CLEAR_BIT(SVDx->IER, SVD_IER_PRIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    ADLVDO    LL_SVD_IsActiveFlag_ADACSVD
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsActiveFlag_ADACSVD(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->ISR, SVD_ISR_ADLVDO_Msk) == (SVD_ISR_ADLVDO_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    SVDO    LL_SVD_GetPowerOutputStatus
  * @param    SVDx SVD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_SVD_POWER_VOLTAGE_STATUS_LESS_THRESHOLD
  *           @arg @ref LL_SVD_POWER_VOLTAGE_STATUS_GREATER_THRESHOLD
  */
__STATIC_INLINE uint32_t LL_SVD_GetPowerOutputStatus(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->ISR, SVD_ISR_SVDO_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    SVDR    LL_SVD_IsActiveFlag_SVDOutPut
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsActiveFlag_SVDOutPut(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->ISR, SVD_ISR_SVDR_Msk) == (SVD_ISR_SVDR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    PFF    LL_SVD_IsActiveFlag_PowerFallFlag
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsActiveFlag_PowerFallFlag(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->ISR, SVD_ISR_PFF_Msk) == (SVD_ISR_PFF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    PFF    LL_PMU_ClearFlag_PowerFallFlag
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_PMU_ClearFlag_PowerFallFlag(SVD_Type* SVDx)
{
    WRITE_REG(SVDx->ISR, SVD_ISR_PFF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    PRF    LL_SVD_IsActiveFlag_PowerRiseFlag
  * @param    SVDx SVD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsActiveFlag_PowerRiseFlag(SVD_Type* SVDx)
{
    return (uint32_t)(READ_BIT(SVDx->ISR, SVD_ISR_PRF_Msk) == (SVD_ISR_PRF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    PRF    LL_PMU_ClearFlag_PowerRiseFlag
  * @param    SVDx SVD instance
  * @retval   None
  */
__STATIC_INLINE void LL_PMU_ClearFlag_PowerRiseFlag(SVD_Type* SVDx)
{
    WRITE_REG(SVDx->ISR, SVD_ISR_PRF_Msk);
}

/**
  * @brief    
  * @rmtoll   VSR    EN    LL_SVD_EnableReference
  * @param    SVDx SVD instance
  * @param    ReferenceSrc This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_EnableReference(SVD_Type* SVDx, uint32_t ReferenceSrc)
{
    MODIFY_REG(SVDx->VSR, SVD_VSR_EN_Msk, ReferenceSrc);
}

/**
  * @brief    
  * @rmtoll   VSR    EN    LL_SVD_IsEnabledReference
  * @param    SVDx SVD instance
  * @param    ReferenceSrc This parameter can be one of the following values:
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SVD_IsEnabledReference(SVD_Type* SVDx, uint32_t ReferenceSrc)
{
    return (uint32_t)(READ_BIT(SVDx->VSR, SVD_VSR_EN_Msk) == ReferenceSrc);
}

/**
  * @brief    
  * @rmtoll   VSR    EN    LL_SVD_DisableReference
  * @param    SVDx SVD instance
  * @param    ReferenceSrc This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void LL_SVD_DisableReference(SVD_Type* SVDx, uint32_t ReferenceSrc)
{
    MODIFY_REG(SVDx->VSR, SVD_VSR_EN_Msk, ~ReferenceSrc);
}

/**
  * @}
  */

/** @defgroup SVD_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_SVD_DeInit(SVD_Type* SVDx);
void LL_SVD_StructInit(SVD_InitTypeDef *SVD_InitStruct);
ErrorStatus LL_SVD_Init(SVD_Type* SVDx, SVD_InitTypeDef *SVD_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_SVD_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-09-24**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
