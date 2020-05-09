/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_rtc.h
  * @author  FMSH Application Team
  * @brief   Head file of RTC LL Module
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
#ifndef __FM33LC0XX_LL_RTC_H
#define __FM33LC0XX_LL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_RTC
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup RTC_LL_ES_INIT RTC Exported Init structures
  * @{
  */
  
/**
  * @brief Configuration with temporary structure variable users will not be used directly
  */
typedef struct
{     
   __IO uint32_t Backup[7];
}Backup_ADDR;
/**
  * @brief LL RTC Init Sturcture definition
  */
typedef struct
{
    /*! 年 */    
    uint32_t Year;
    /*! 月 */       
    uint32_t Month;        
    /*! 日 */   
    uint32_t Day; 
    /*! 周 */   
    uint32_t Week;    
    /*! 时 */   
    uint32_t Hour;
    /*! 分 */   
    uint32_t Minute;    
    /*! 秒 */   
    uint32_t Second;   
                                                         
} LL_RTC_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup RTC_LL_Exported_Constants RTC Exported Constants
  * @{
  */

#define    LL_RTC_BACKUP_0                                        (0x0U << 0U)
#define    LL_RTC_BACKUP_1                                        (0x1U << 0U)
#define    LL_RTC_BACKUP_2                                        (0x2U << 0U)
#define    LL_RTC_BACKUP_3                                        (0x3U << 0U)
#define    LL_RTC_BACKUP_4                                        (0x4U << 0U)
#define    LL_RTC_BACKUP_5                                        (0x5U << 0U)
#define    LL_RTC_BACKUP_6                                        (0x6U << 0U)
#define    LL_RTC_BACKUP_7                                        (0x7U << 0U)

#define    LL_RTC_TIME_MARK_SECOND                                (0x2U << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_MINUTE                                (0x3U << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_HOUR                                  (0x4U << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_DAY                                   (0x5U << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_ALARM                                 (0x6U << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_32_SEC                                (0x7U << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_SECOND_REVERSE                        (0x9U << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_MINUTE_REVERSE                        (0xaU << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_HOUR_REVERSE                          (0xbU << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_DAY_REVERSE                           (0xcU << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_ALARM_REVERSE                         (0xdU << RTC_TMSEL_TMSEL_Pos)
#define    LL_RTC_TIME_MARK_SEC                                   (0xfU << RTC_TMSEL_TMSEL_Pos)

#define    LL_RTC_ADJUST_DIR_INCREASE                             (0x0U << RTC_ADSIGN_ADSIGN_Pos)
#define    LL_RTC_ADJUST_DIR_REDUCE                               (0x1U << RTC_ADSIGN_ADSIGN_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup RTC_LL_Exported_Functions RTC Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   WER        LL_RTC_EnableConfigTime
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableConfigTime(RTC_Type* RTCx)
{
     RTCx->WER = 0xACACACAC;
}

/**
  * @brief    
  * @rmtoll   WER        LL_RTC_DisableConfigTime
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableConfigTime(RTC_Type* RTCx)
{
    RTCx->WER = 0x5A5A5A5A; 
}

/**
  * @brief    
  * @rmtoll   IER    ADJ_IE    LL_RTC_EnableIT_Adjust
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_Adjust(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_ADJ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    ADJ_IE    LL_RTC_IsEnabledIT_Adjust
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_Adjust(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_ADJ_IE_Msk) == RTC_IER_ADJ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    ADJ_IE    LL_RTC_DisableIT_Adjust
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_Adjust(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_ADJ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    ALARM_IE    LL_RTC_EnableIT_Alarm
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_Alarm(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_ALARM_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    ALARM_IE    LL_RTC_IsEnabledIT_Alarm
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_Alarm(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_ALARM_IE_Msk) == RTC_IER_ALARM_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    ALARM_IE    LL_RTC_DisableIT_Alarm
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_Alarm(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_ALARM_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    1KHZ_IE    LL_RTC_EnableIT_1Khz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_1Khz(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_1KHZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    1KHZ_IE    LL_RTC_IsEnabledIT_1Khz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_1Khz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_1KHZ_IE_Msk) == RTC_IER_1KHZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    1KHZ_IE    LL_RTC_DisableIT_1Khz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_1Khz(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_1KHZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    256HZ_IE    LL_RTC_EnableIT_256hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_256hz(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_256HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    256HZ_IE    LL_RTC_IsEnabledIT_256hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_256hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_256HZ_IE_Msk) == RTC_IER_256HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    256HZ_IE    LL_RTC_DisableIT_256hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_256hz(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_256HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    64HZ_IE    LL_RTC_EnableIT_64hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_64hz(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_64HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    64HZ_IE    LL_RTC_IsEnabledIT_64hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_64hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_64HZ_IE_Msk) == RTC_IER_64HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    64HZ_IE    LL_RTC_DisableIT_64hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_64hz(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_64HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    16HZ_IE    LL_RTC_EnableIT_16hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_16hz(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_16HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    16HZ_IE    LL_RTC_IsEnabledIT_16hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_16hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_16HZ_IE_Msk) == RTC_IER_16HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    16HZ_IE    LL_RTC_DisableIT_16hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_16hz(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_16HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    8HZ_IE    LL_RTC_EnableIT_8hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_8hz(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_8HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    8HZ_IE    LL_RTC_IsEnabledIT_8hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_8hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_8HZ_IE_Msk) == RTC_IER_8HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    8HZ_IE    LL_RTC_DisableIT_8hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_8hz(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_8HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    4HZ_IE    LL_RTC_EnableIT_4hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_4hz(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_4HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    4HZ_IE    LL_RTC_IsEnabledIT_4hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_4hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_4HZ_IE_Msk) == RTC_IER_4HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    4HZ_IE    LL_RTC_DisableIT_4hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_4hz(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_4HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    2HZ_IE    LL_RTC_EnableIT_2hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_2hz(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_2HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    2HZ_IE    LL_RTC_IsEnabledIT_2hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_2hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_2HZ_IE_Msk) == RTC_IER_2HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    2HZ_IE    LL_RTC_DisableIT_2hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_2hz(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_2HZ_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    SEC_IE    LL_RTC_EnableIT_Second
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_Second(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_SEC_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    SEC_IE    LL_RTC_IsEnabledIT_Second
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_Second(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_SEC_IE_Msk) == RTC_IER_SEC_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    SEC_IE    LL_RTC_DisableIT_Second
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_Second(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_SEC_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    MIN_IE    LL_RTC_EnableIT_Minute
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_Minute(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_MIN_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    MIN_IE    LL_RTC_IsEnabledIT_Minute
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_Minute(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_MIN_IE_Msk) == RTC_IER_MIN_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    MIN_IE    LL_RTC_DisableIT_Minute
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_Minute(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_MIN_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    HOUR_IE    LL_RTC_EnableIT_Hour
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_Hour(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_HOUR_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    HOUR_IE    LL_RTC_IsEnabledIT_Hour
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_Hour(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_HOUR_IE_Msk) == RTC_IER_HOUR_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    HOUR_IE    LL_RTC_DisableIT_Hour
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_Hour(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_HOUR_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    DAY_IE    LL_RTC_EnableIT_Day
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_Day(RTC_Type* RTCx)
{
    SET_BIT(RTCx->IER, RTC_IER_DAY_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    DAY_IE    LL_RTC_IsEnabledIT_Day
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_Day(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->IER, RTC_IER_DAY_IE_Msk) == RTC_IER_DAY_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    DAY_IE    LL_RTC_DisableIT_Day
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_DisableIT_Day(RTC_Type* RTCx)
{
    CLEAR_BIT(RTCx->IER, RTC_IER_DAY_IE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    ADJ_IF    LL_RTC_ClearFlag_Adjust
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_Adjust(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_ADJ_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    ADJ_IF    LL_RTC_IsActiveFlag_Adjust
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_Adjust(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_ADJ_IF_Msk) == (RTC_ISR_ADJ_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    ALARM_IF    LL_RTC_ClearFlag_Alarm
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_Alarm(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_ALARM_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    ALARM_IF    LL_RTC_IsActiveFlag_Alarm
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_Alarm(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_ALARM_IF_Msk) == (RTC_ISR_ALARM_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    1KHZ_IF    LL_RTC_ClearFlag_1Khz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_1Khz(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_1KHZ_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    1KHZ_IF    LL_RTC_IsActiveFlag_1Khz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_1Khz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_1KHZ_IF_Msk) == (RTC_ISR_1KHZ_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    256HZ_IF    LL_RTC_ClearFlag_256hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_256hz(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_256HZ_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    256HZ_IF    LL_RTC_IsActiveFlag_256hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_256hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_256HZ_IF_Msk) == (RTC_ISR_256HZ_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    64HZ_IF    LL_RTC_ClearFlag_64hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_64hz(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_64HZ_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    64HZ_IF    LL_RTC_IsActiveFlag_64hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_64hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_64HZ_IF_Msk) == (RTC_ISR_64HZ_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    16HZ_IF    LL_RTC_ClearFlag_16hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_16hz(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_16HZ_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    16HZ_IF    LL_RTC_IsActiveFlag_16hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_16hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_16HZ_IF_Msk) == (RTC_ISR_16HZ_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    8HZ_IF    LL_RTC_EnableIT_RTC_8hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_EnableIT_RTC_8hz(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_8HZ_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    8HZ_IF    LL_RTC_IsActiveFlag_8hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_8hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_8HZ_IF_Msk) == (RTC_ISR_8HZ_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    4HZ_IF    LL_RTC_ClearFlag_4hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_4hz(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_4HZ_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    4HZ_IF    LL_RTC_IsActiveFlag_4hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_4hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_4HZ_IF_Msk) == (RTC_ISR_4HZ_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    2HZ_IF    LL_RTC_ClearFlag_2hz
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_2hz(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_2HZ_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    2HZ_IF    LL_RTC_IsActiveFlag_2hz
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_2hz(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_2HZ_IF_Msk) == (RTC_ISR_2HZ_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    SEC_IF    LL_RTC_ClearFlag_Second
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_Second(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_SEC_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    SEC_IF    LL_RTC_IsActiveFlag_Second
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_Second(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_SEC_IF_Msk) == (RTC_ISR_SEC_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    MIN_IF    LL_RTC_ClearFlag_Minute
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_Minute(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_MIN_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    MIN_IF    LL_RTC_IsActiveFlag_Minute
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_Minute(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_MIN_IF_Msk) == (RTC_ISR_MIN_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    HOUR_IF    LL_RTC_ClearFlag_Hour
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_Hour(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_HOUR_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    HOUR_IF    LL_RTC_IsActiveFlag_Hour
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_Hour(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_HOUR_IF_Msk) == (RTC_ISR_HOUR_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    DAY_IF    LL_RTC_ClearFlag_Day
  * @param    RTCx RTC instance
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_Day(RTC_Type* RTCx)
{
    WRITE_REG(RTCx->ISR, RTC_ISR_DAY_IF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    DAY_IF    LL_RTC_IsActiveFlag_Day
  * @param    RTCx RTC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_Day(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ISR, RTC_ISR_DAY_IF_Msk) == (RTC_ISR_DAY_IF_Msk));
}

/**
  * @brief    
  * @rmtoll   BCDSEC        LL_RTC_GetSecondReg
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetSecondReg(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->BCDSEC, 0x7fU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   BCDSEC        LL_RTC_SetSecondReg
  * @param    RTCx RTC instance
  * @param    SecVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetSecondReg(RTC_Type* RTCx, uint32_t SecVel)
{
    MODIFY_REG(RTCx->BCDSEC, (0x7fU << 0U), (SecVel << 0U));
}

/**
  * @brief    
  * @rmtoll   BCDMIN        LL_RTC_GetMinutesReg
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetMinutesReg(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->BCDMIN, 0x7fU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   BCDMIN        LL_RTC_SetMinutesReg
  * @param    RTCx RTC instance
  * @param    MinVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetMinutesReg(RTC_Type* RTCx, uint32_t MinVel)
{
    MODIFY_REG(RTCx->BCDMIN, (0x7fU << 0U), (MinVel << 0U));
}

/**
  * @brief    
  * @rmtoll   BCDHOUR        LL_RTC_GetHoursReg
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetHoursReg(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->BCDHOUR, 0x3fU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   BCDHOUR        LL_RTC_SetHoursReg
  * @param    RTCx RTC instance
  * @param    HourVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetHoursReg(RTC_Type* RTCx, uint32_t HourVel)
{
    MODIFY_REG(RTCx->BCDHOUR, (0x3fU << 0U), (HourVel << 0U));
}

/**
  * @brief    
  * @rmtoll   BCDDAY        LL_RTC_GetDaysReg
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetDaysReg(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->BCDDAY, 0x3fU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   BCDDAY        LL_RTC_SetDaysReg
  * @param    RTCx RTC instance
  * @param    DayVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetDaysReg(RTC_Type* RTCx, uint32_t DayVel)
{
    MODIFY_REG(RTCx->BCDDAY, (0x3fU << 0U), (DayVel << 0U));
}

/**
  * @brief    
  * @rmtoll   BCDWEEK        LL_RTC_GetWeeksReg
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetWeeksReg(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->BCDWEEK, 0x7U) >> 0U);
}

/**
  * @brief    
  * @rmtoll   BCDWEEK        LL_RTC_SetWeeksReg
  * @param    RTCx RTC instance
  * @param    WeekVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetWeeksReg(RTC_Type* RTCx, uint32_t WeekVel)
{
    MODIFY_REG(RTCx->BCDWEEK, (0x7U << 0U), (WeekVel << 0U));
}

/**
  * @brief    
  * @rmtoll   BCDMONTH        LL_RTC_GetMonthReg
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetMonthReg(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->BCDMONTH, 0x1fU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   BCDMONTH        LL_RTC_SetMonthReg
  * @param    RTCx RTC instance
  * @param    MonVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetMonthReg(RTC_Type* RTCx, uint32_t MonVel)
{
    MODIFY_REG(RTCx->BCDMONTH, (0x1fU << 0U), (MonVel << 0U));
}

/**
  * @brief    
  * @rmtoll   BCDYEAR        LL_RTC_GetYearsReg
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetYearsReg(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->BCDYEAR, 0xffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   BCDYEAR        LL_RTC_SetYearsReg
  * @param    RTCx RTC instance
  * @param    YearVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetYearsReg(RTC_Type* RTCx, uint32_t YearVel)
{
    MODIFY_REG(RTCx->BCDYEAR, (0xffU << 0U), (YearVel << 0U));
}

/**
  * @brief    
  * @rmtoll   ALARM        LL_RTC_GetHours_Alarm
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetHours_Alarm(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ALARM, 0x3fU) >> 16U);
}

/**
  * @brief    
  * @rmtoll   ALARM        LL_RTC_SetHours_Alarm
  * @param    RTCx RTC instance
  * @param    HourVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetHours_Alarm(RTC_Type* RTCx, uint32_t HourVel)
{
    MODIFY_REG(RTCx->ALARM, (0x3fU << 16U), (HourVel << 16U));
}

/**
  * @brief    
  * @rmtoll   ALARM        LL_RTC_GetMinutes_Alarm
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetMinutes_Alarm(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ALARM, 0x7fU) >> 8U);
}

/**
  * @brief    
  * @rmtoll   ALARM        LL_RTC_SetMinutes_Alarm
  * @param    RTCx RTC instance
  * @param    MinVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetMinutes_Alarm(RTC_Type* RTCx, uint32_t MinVel)
{
    MODIFY_REG(RTCx->ALARM, (0x7fU << 8U), (MinVel << 8U));
}

/**
  * @brief    
  * @rmtoll   ALARM        LL_RTC_GetSecond_Alarm
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetSecond_Alarm(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ALARM, 0x7fU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   ALARM        LL_RTC_SetSecond_Alarm
  * @param    RTCx RTC instance
  * @param    SecVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetSecond_Alarm(RTC_Type* RTCx, uint32_t SecVel)
{
    MODIFY_REG(RTCx->ALARM, (0x7fU << 0U), (SecVel << 0U));
}

/**
  * @brief    
  * @rmtoll   TMSEL    TMSEL    LL_RTC_SetTimeMark
  * @param    RTCx RTC instance
  * @param    MarkSelect This parameter can be one of the following values:
  *           @arg @ref LL_RTC_TIME_MARK_SECOND
  *           @arg @ref LL_RTC_TIME_MARK_MINUTE
  *           @arg @ref LL_RTC_TIME_MARK_HOUR
  *           @arg @ref LL_RTC_TIME_MARK_DAY
  *           @arg @ref LL_RTC_TIME_MARK_ALARM
  *           @arg @ref LL_RTC_TIME_MARK_32_SEC
  *           @arg @ref LL_RTC_TIME_MARK_SECOND_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_MINUTE_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_HOUR_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_DAY_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_ALARM_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_SEC
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetTimeMark(RTC_Type* RTCx, uint32_t MarkSelect)
{
    MODIFY_REG(RTCx->TMSEL, RTC_TMSEL_TMSEL_Msk, MarkSelect);
}

/**
  * @brief    
  * @rmtoll   TMSEL    TMSEL    LL_RTC_GetTimeMark
  * @param    RTCx RTC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RTC_TIME_MARK_SECOND
  *           @arg @ref LL_RTC_TIME_MARK_MINUTE
  *           @arg @ref LL_RTC_TIME_MARK_HOUR
  *           @arg @ref LL_RTC_TIME_MARK_DAY
  *           @arg @ref LL_RTC_TIME_MARK_ALARM
  *           @arg @ref LL_RTC_TIME_MARK_32_SEC
  *           @arg @ref LL_RTC_TIME_MARK_SECOND_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_MINUTE_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_HOUR_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_DAY_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_ALARM_REVERSE
  *           @arg @ref LL_RTC_TIME_MARK_SEC
  */
__STATIC_INLINE uint32_t LL_RTC_GetTimeMark(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->TMSEL, RTC_TMSEL_TMSEL_Msk));
}

/**
  * @brief    
  * @rmtoll   ADJUST        LL_RTC_GetAdjustVel
  * @param    RTCx RTC instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetAdjustVel(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ADJUST, 0x1ffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   ADJUST        LL_RTC_SetAdjustVel
  * @param    RTCx RTC instance
  * @param    AdjustVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetAdjustVel(RTC_Type* RTCx, uint32_t AdjustVel)
{
    MODIFY_REG(RTCx->ADJUST, (0x1ffU << 0U), (AdjustVel << 0U));
}

/**
  * @brief    
  * @rmtoll   ADSIGN    ADSIGN    LL_RTC_SetAdjustDirect
  * @param    RTCx RTC instance
  * @param    AdjustDirect This parameter can be one of the following values:
  *           @arg @ref LL_RTC_ADJUST_DIR_INCREASE
  *           @arg @ref LL_RTC_ADJUST_DIR_REDUCE
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetAdjustDirect(RTC_Type* RTCx, uint32_t AdjustDirect)
{
    MODIFY_REG(RTCx->ADSIGN, RTC_ADSIGN_ADSIGN_Msk, AdjustDirect);
}

/**
  * @brief    
  * @rmtoll   ADSIGN    ADSIGN    LL_RTC_GetAdjustDirect
  * @param    RTCx RTC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_RTC_ADJUST_DIR_INCREASE
  *           @arg @ref LL_RTC_ADJUST_DIR_REDUCE
  */
__STATIC_INLINE uint32_t LL_RTC_GetAdjustDirect(RTC_Type* RTCx)
{
    return (uint32_t)(READ_BIT(RTCx->ADSIGN, RTC_ADSIGN_ADSIGN_Msk));
}

/**
  * @brief    
  * @rmtoll   SBSCNT        LL_RTC_SetMilliSecondsReg
  * @param    RTCx RTC instance
  * @param    MilliSecVel 
  * @retval   None
  */
__STATIC_INLINE void LL_RTC_SetMilliSecondsReg(RTC_Type* RTCx, uint32_t MilliSecVel)
{
    MODIFY_REG(RTCx->SBSCNT, (0x1ffU << 0U), (MilliSecVel << 0U));
}

/**
  * @brief    
  * @rmtoll   BACKUP        LL_RTC_GetBackupReg
  * @param    RTCx RTC instance
  * @param    Backnum This parameter can be one of the following values:
  *           @arg @ref LL_RTC_BACKUP_0
  *           @arg @ref LL_RTC_BACKUP_1
  *           @arg @ref LL_RTC_BACKUP_2
  *           @arg @ref LL_RTC_BACKUP_3
  *           @arg @ref LL_RTC_BACKUP_4
  *           @arg @ref LL_RTC_BACKUP_5
  *           @arg @ref LL_RTC_BACKUP_6
  *           @arg @ref LL_RTC_BACKUP_7
  * @retval   
  */
__STATIC_INLINE uint32_t LL_RTC_GetBackupReg(RTC_Type* RTCx, uint32_t Backnum)
{
    Backup_ADDR  *addr = (Backup_ADDR*)RTCx->BKR0;
    
    return (uint32_t)(READ_BIT(addr->Backup[Backnum], 0xFFFFFFFFu)); 
}

/**
  * @brief    
  * @rmtoll   BACKUP        LL_RTC_SetBackupReg
  * @param    RTCx RTC instance
  * @param    BackupVel 
  * @param    Backnum This parameter can be one of the following values:
  *           @arg @ref LL_RTC_BACKUP_0
  *           @arg @ref LL_RTC_BACKUP_1
  *           @arg @ref LL_RTC_BACKUP_2
  *           @arg @ref LL_RTC_BACKUP_3
  *           @arg @ref LL_RTC_BACKUP_4
  *           @arg @ref LL_RTC_BACKUP_5
  *           @arg @ref LL_RTC_BACKUP_6
  *           @arg @ref LL_RTC_BACKUP_7
  * @retval   
  */ 
__STATIC_INLINE void LL_RTC_SetBackupReg(RTC_Type* RTCx, uint32_t BackupVel, uint32_t Backnum)
{   
    Backup_ADDR  *addr = (Backup_ADDR*)RTCx->BKR0;
    MODIFY_REG(addr->Backup[Backnum], (0xFFFFFFFFu),BackupVel );
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_RTC_DeInit(RTC_Type *RTCx);
void LL_RTC_StructInit(LL_RTC_InitTypeDef *InitStruct);
ErrorStatus LL_RTC_GetTime(RTC_Type *RTCx,LL_RTC_InitTypeDef *InitStruct);
ErrorStatus LL_RTC_Init(RTC_Type *RTCx, LL_RTC_InitTypeDef *TIM_InitStruct);
ErrorStatus LL_RTC_ConfigTime(RTC_Type *RTCx,LL_RTC_InitTypeDef *TIM_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_RTC_H*/

/***************************Py_Code_Generator Version: 0.1-0.5- @ 2019-11-07***************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
