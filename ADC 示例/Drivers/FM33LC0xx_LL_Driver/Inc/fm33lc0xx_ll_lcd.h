/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_lcd.h
  * @author  FMSH Application Team
  * @brief   Head file of LCD LL Module
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
#ifndef __FM33LC0XX_LL_LCD_H
#define __FM33LC0XX_LL_LCD_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "FM33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_LCD
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup LCD_LL_ES_INIT LCD Exported Init structures
  * @{
  */

/**
  * @brief LL LCD Init Sturcture definition
  */
typedef struct
{
    /*! 电流源大小控制 */
    uint32_t ICCtrl;         
    /*! 驱动模式 */
    uint32_t EnableMode;
    /*! 偏执电平 */
    uint32_t BiasVoltage;
    /*! 偏执类型 */
    uint32_t BiasMode;    
    /*! 驱动波形 */    
    uint32_t Waveform;
	/*! COM数目 */    
    uint32_t COMxNum;
    /*! 显示频率 */    
    uint32_t FreqPsc;
    /*! 显示闪烁点亮时间(ms) */
    uint32_t FlickOnTime;
    /*! 显示闪烁熄灭时间(ms) */
    uint32_t FlickOffTime;
}LL_LCD_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup LCD_LL_Exported_Constants LCD Exported Constants
  * @{
  */
#define    LL_LCD_DATA_REG_0                                      (0x0U << 0U)
#define    LL_LCD_DATA_REG_1                                      (0x1U << 0U)
#define    LL_LCD_DATA_REG_2                                      (0x2U << 0U)
#define    LL_LCD_DATA_REG_3                                      (0x3U << 0U)
#define    LL_LCD_DATA_REG_4                                      (0x4U << 0U)
#define    LL_LCD_DATA_REG_5                                      (0x5U << 0U)
#define    LL_LCD_DATA_REG_6                                      (0x6U << 0U)
#define    LL_LCD_DATA_REG_7                                      (0x7U << 0U)
#define    LL_LCD_DATA_REG_8                                      (0x8U << 0U)
#define    LL_LCD_COM_EN_COM0                                     (0x1U << 0U)
#define    LL_LCD_COM_EN_COM1                                     (0x1U << 1U)
#define    LL_LCD_COM_EN_COM2                                     (0x1U << 2U)
#define    LL_LCD_COM_EN_COM3                                     (0x1U << 3U)
#define    LL_LCD_COM_EN_COM4                                     (0x1U << 28U)
#define    LL_LCD_COM_EN_COM5                                     (0x1U << 29U)
#define    LL_LCD_COM_EN_COM6                                     (0x1U << 30U)
#define    LL_LCD_COM_EN_COM7                                     (0x1U << 31U)
#define    LL_LCD_SEG_EN0_SEG0                                    (0x1U << 0U)
#define    LL_LCD_SEG_EN0_SEG1                                    (0x1U << 1U)
#define    LL_LCD_SEG_EN0_SEG2                                    (0x1U << 2U)
#define    LL_LCD_SEG_EN0_SEG3                                    (0x3U << 3U)
#define    LL_LCD_SEG_EN0_SEG4                                    (0x1U << 4U)
#define    LL_LCD_SEG_EN0_SEG5                                    (0x1U << 5U)
#define    LL_LCD_SEG_EN0_SEG6                                    (0x1U << 6U)
#define    LL_LCD_SEG_EN0_SEG7                                    (0x1U << 7U)
#define    LL_LCD_SEG_EN0_SEG8                                    (0x1U << 8U)
#define    LL_LCD_SEG_EN0_SEG9                                    (0x1U << 9U)
#define    LL_LCD_SEG_EN0_SEG10                                   (0x1U << 10U)
#define    LL_LCD_SEG_EN0_SEG11                                   (0x1U << 11U)
#define    LL_LCD_SEG_EN0_SEG12                                   (0x1U << 12U)
#define    LL_LCD_SEG_EN0_SEG13                                   (0x1U << 13U)
#define    LL_LCD_SEG_EN0_SEG14                                   (0x1U << 14U)
#define    LL_LCD_SEG_EN0_SEG15                                   (0x1U << 15U)
#define    LL_LCD_SEG_EN0_SEG16                                   (0x1U << 16U)
#define    LL_LCD_SEG_EN0_SEG17                                   (0x1U << 17U)
#define    LL_LCD_SEG_EN0_SEG18                                   (0x1U << 18U)
#define    LL_LCD_SEG_EN0_SEG19                                   (0x1U << 19U)
#define    LL_LCD_SEG_EN0_SEG20                                   (0x1U << 20U)
#define    LL_LCD_SEG_EN0_SEG21                                   (0x1U << 21U)
#define    LL_LCD_SEG_EN0_SEG22                                   (0x1U << 22U)
#define    LL_LCD_SEG_EN0_SEG23                                   (0x1U << 23U)
#define    LL_LCD_SEG_EN0_SEG24                                   (0x1U << 24U)
#define    LL_LCD_SEG_EN0_SEG25                                   (0x1U << 25U)
#define    LL_LCD_SEG_EN0_SEG26                                   (0x1U << 26U)
#define    LL_LCD_SEG_EN0_SEG27                                   (0x1U << 27U)
#define    LL_LCD_SEG_EN0_SEG28                                   (0x1U << 28U)
#define    LL_LCD_SEG_EN0_SEG29                                   (0x1U << 29U)
#define    LL_LCD_SEG_EN0_SEG30                                   (0x1U << 30U)
#define    LL_LCD_SEG_EN0_SEG31                                   (0x1U << 31U)



#define    LCD_CR_IC_CTRL_Pos                                     (16U)
#define    LCD_CR_IC_CTRL_Msk                                     (0x3U << LCD_CR_IC_CTRL_Pos)
#define    LCD_CR_IC_CTRL                                         LCD_CR_IC_CTRL_Msk
#define    LL_LCD_DRV_IC_CTRL_LARGETS                             (0x0U << LCD_CR_IC_CTRL_Pos)
#define    LL_LCD_DRV_IC_CTRL_LARGE                               (0x1U << LCD_CR_IC_CTRL_Pos)
#define    LL_LCD_DRV_IC_CTRL_SMALL                               (0x2U << LCD_CR_IC_CTRL_Pos)
#define    LL_LCD_DRV_IC_CTRL_MININUM                             (0x3U << LCD_CR_IC_CTRL_Pos)


#define    LCD_CR_ENMODE_Pos                                      (15U)
#define    LCD_CR_ENMODE_Msk                                      (0x1U << LCD_CR_ENMODE_Pos)
#define    LCD_CR_ENMODE                                          LCD_CR_ENMODE_Msk
#define    LL_LCD_DRV_ENMODE_INNERRESISTER                        (0x1U << LCD_CR_ENMODE_Pos)


#define    LCD_CR_FLICK_Pos                                       (14U)
#define    LCD_CR_FLICK_Msk                                       (0x1U << LCD_CR_FLICK_Pos)
#define    LCD_CR_FLICK                                           LCD_CR_FLICK_Msk
#define    LL_LCD_DISPCTRL_FLICK_DISABLE                          (0x0U << LCD_CR_FLICK_Pos)
#define    LL_LCD_DISPCTRL_FLICK_ENABLE                           (0x1U << LCD_CR_FLICK_Pos)


#define    LCD_CR_BIAS_Pos                                        (8U)
#define    LCD_CR_BIAS_Msk                                        (0xfU << LCD_CR_BIAS_Pos)
#define    LCD_CR_BIAS                                            LCD_CR_BIAS_Msk
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_0                         (0x0U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_1                         (0x1U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_2                         (0x2U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_3                         (0x3U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_4                         (0x4U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_5                         (0x5U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_6                         (0x6U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_7                         (0x7U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_8                         (0x8U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_9                         (0x9U << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_10                        (0xaU << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_11                        (0xbU << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_12                        (0xcU << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_13                        (0xdU << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_14                        (0xeU << LCD_CR_BIAS_Pos)
#define    LL_LCD_GRAY_SCALE_CTRL_LEVEL_15                        (0xfU << LCD_CR_BIAS_Pos)


#define    LCD_CR_BIASMD_Pos                                      (5U)
#define    LCD_CR_BIASMD_Msk                                      (0x1U << LCD_CR_BIASMD_Pos)
#define    LCD_CR_BIASMD                                          LCD_CR_BIASMD_Msk
#define    LL_LCD_SET_BIASMD_DIV4BIAS                             (0x0U << LCD_CR_BIASMD_Pos)
#define    LL_LCD_SET_BIASMD_DIV3BIAS                             (0x1U << LCD_CR_BIASMD_Pos)


#define    LCD_CR_ANTIPOLAR_Pos                                   (4U)
#define    LCD_CR_ANTIPOLAR_Msk                                   (0x1U << LCD_CR_ANTIPOLAR_Pos)
#define    LCD_CR_ANTIPOLAR                                       LCD_CR_ANTIPOLAR_Msk
#define    LL_LCD_DISPCTRL_ANTIPOLAR_FLOATING                     (0x0U << LCD_CR_ANTIPOLAR_Pos)
#define    LL_LCD_DISPCTRL_ANTIPOLAR_GND                          (0x1U << LCD_CR_ANTIPOLAR_Pos)


#define    LCD_CR_WFT_Pos                                         (3U)
#define    LCD_CR_WFT_Msk                                         (0x1U << LCD_CR_WFT_Pos)
#define    LCD_CR_WFT                                             LCD_CR_WFT_Msk
#define    LL_LCD_WAVEFORM_FORMAT_TYPE_A                          (0x0U << LCD_CR_WFT_Pos)
#define    LL_LCD_WAVEFORM_FORMAT_TYPE_B                          (0x1U << LCD_CR_WFT_Pos)


#define    LCD_CR_LMUX_Pos                                        (1U)
#define    LCD_CR_LMUX_Msk                                        (0x3U << LCD_CR_LMUX_Pos)
#define    LCD_CR_LMUX                                            LCD_CR_LMUX_Msk
#define    LL_LCD_SEG_LINE_SELECT_COM_4                           (0x0U << LCD_CR_LMUX_Pos)
#define    LL_LCD_SEG_LINE_SELECT_COM_6                           (0x1U << LCD_CR_LMUX_Pos)
#define    LL_LCD_SEG_LINE_SELECT_COM_8                           (0x2U << LCD_CR_LMUX_Pos)


#define    LCD_CR_EN_Pos                                          (0U)
#define    LCD_CR_EN_Msk                                          (0x1U << LCD_CR_EN_Pos)
#define    LCD_CR_EN                                              LCD_CR_EN_Msk



#define    LCD_TEST_LCCTRL_Pos                                    (7U)
#define    LCD_TEST_LCCTRL_Msk                                    (0x1U << LCD_TEST_LCCTRL_Pos)
#define    LCD_TEST_LCCTRL                                        LCD_TEST_LCCTRL_Msk
#define    LL_LCD_TEST_MODE_LCCTRL_0                              (0x0U << LCD_TEST_LCCTRL_Pos)
#define    LL_LCD_TEST_MODE_LCCTRL_1                              (0x1U << LCD_TEST_LCCTRL_Pos)


#define    LCD_TEST_TESTEN_Pos                                    (0U)
#define    LCD_TEST_TESTEN_Msk                                    (0x1U << LCD_TEST_TESTEN_Pos)
#define    LCD_TEST_TESTEN                                        LCD_TEST_TESTEN_Msk



#define    LCD_FCR_DF_Pos                                         (0U)
#define    LCD_FCR_DF_Msk                                         (0xffU << LCD_FCR_DF_Pos)
#define    LCD_FCR_DF                                             LCD_FCR_DF_Msk


#define    LCD_FLKT_TOFF_Pos                                      (8U)
#define    LCD_FLKT_TOFF_Msk                                      (0xffU << LCD_FLKT_TOFF_Pos)
#define    LCD_FLKT_TOFF                                          LCD_FLKT_TOFF_Msk


#define    LCD_FLKT_TON_Pos                                       (0U)
#define    LCD_FLKT_TON_Msk                                       (0xffU << LCD_FLKT_TON_Pos)
#define    LCD_FLKT_TON                                           LCD_FLKT_TON_Msk


#define    LCD_IER_DONIE_Pos                                      (1U)
#define    LCD_IER_DONIE_Msk                                      (0x1U << LCD_IER_DONIE_Pos)
#define    LCD_IER_DONIE                                          LCD_IER_DONIE_Msk



#define    LCD_IER_DOFFIE_Pos                                     (0U)
#define    LCD_IER_DOFFIE_Msk                                     (0x1U << LCD_IER_DOFFIE_Pos)
#define    LCD_IER_DOFFIE                                         LCD_IER_DOFFIE_Msk



#define    LCD_ISR_DONIF_Pos                                      (1U)
#define    LCD_ISR_DONIF_Msk                                      (0x1U << LCD_ISR_DONIF_Pos)
#define    LCD_ISR_DONIF                                          LCD_ISR_DONIF_Msk


#define    LCD_ISR_DOFFIF_Pos                                     (0U)
#define    LCD_ISR_DOFFIF_Msk                                     (0x1U << LCD_ISR_DOFFIF_Pos)
#define    LCD_ISR_DOFFIF                                         LCD_ISR_DOFFIF_Msk


#define    LCD_DATA0_DSDA_Pos                                     (0U)
#define    LCD_DATA0_DSDA_Msk                                     (0xffffffffU << LCD_DATA0_DSDA_Pos)
#define    LCD_DATA0_DSDA                                         LCD_DATA0_DSDA_Msk


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup LCD_LL_Exported_Functions LCD Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CR    IC_CTRL    LL_LCD_SetICCtrl
  * @param    LCDx LCD instance
  * @param    ICCtrl This parameter can be one of the following values:
  *           @arg @ref LL_LCD_DRV_IC_CTRL_LARGETS
  *           @arg @ref LL_LCD_DRV_IC_CTRL_LARGE
  *           @arg @ref LL_LCD_DRV_IC_CTRL_SMALL
  *           @arg @ref LL_LCD_DRV_IC_CTRL_MININUM
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetICCtrl(LCD_Type* LCDx, uint32_t ICCtrl)
{
    MODIFY_REG(LCDx->CR, LCD_CR_IC_CTRL_Msk, ICCtrl);
}

/**
  * @brief    
  * @rmtoll   CR    IC_CTRL    LL_LCD_GetICCtrl
  * @param    LCDx LCD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LCD_DRV_IC_CTRL_LARGETS
  *           @arg @ref LL_LCD_DRV_IC_CTRL_LARGE
  *           @arg @ref LL_LCD_DRV_IC_CTRL_SMALL
  *           @arg @ref LL_LCD_DRV_IC_CTRL_MININUM
  */
__STATIC_INLINE uint32_t LL_LCD_GetICCtrl(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_IC_CTRL_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    ENMODE    LL_LCD_SetEnableMode
  * @param    LCDx LCD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_LCD_DRV_ENMODE_INNERRESISTER
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetEnableMode(LCD_Type* LCDx, uint32_t mode)
{
    MODIFY_REG(LCDx->CR, LCD_CR_ENMODE_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR    ENMODE    LL_LCD_GetEnableMode
  * @param    LCDx LCD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LCD_DRV_ENMODE_INNERRESISTER
  */
__STATIC_INLINE uint32_t LL_LCD_GetEnableMode(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_ENMODE_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    FLICK    LL_LCD_SetDisplayFlick
  * @param    LCDx LCD instance
  * @param    state This parameter can be one of the following values:
  *           @arg @ref LL_LCD_DISPCTRL_FLICK_DISABLE
  *           @arg @ref LL_LCD_DISPCTRL_FLICK_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetDisplayFlick(LCD_Type* LCDx, uint32_t state)
{
    MODIFY_REG(LCDx->CR, LCD_CR_FLICK_Msk, state);
}

/**
  * @brief    
  * @rmtoll   CR    FLICK    LL_LCD_GetDisplayFlick
  * @param    LCDx LCD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LCD_DISPCTRL_FLICK_DISABLE
  *           @arg @ref LL_LCD_DISPCTRL_FLICK_ENABLE
  */
__STATIC_INLINE uint32_t LL_LCD_GetDisplayFlick(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_FLICK_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    BIAS    LL_LCD_SetBiasVoltage
  * @param    LCDx LCD instance
  * @param    voltage This parameter can be one of the following values:
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_0
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_1
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_2
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_3
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_4
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_5
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_6
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_7
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_8
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_9
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_10
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_11
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_12
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_13
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_14
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_15
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetBiasVoltage(LCD_Type* LCDx, uint32_t voltage)
{
    MODIFY_REG(LCDx->CR, LCD_CR_BIAS_Msk, voltage);
}

/**
  * @brief    
  * @rmtoll   CR    BIAS    LL_LCD_GetBiasVoltage
  * @param    LCDx LCD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_0
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_1
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_2
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_3
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_4
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_5
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_6
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_7
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_8
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_9
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_10
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_11
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_12
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_13
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_14
  *           @arg @ref LL_LCD_GRAY_SCALE_CTRL_LEVEL_15
  */
__STATIC_INLINE uint32_t LL_LCD_GetBiasVoltage(LCD_Type* LCDx)
{
    return (READ_BIT(LCDx->CR, LCD_CR_BIAS_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    BIASMD    LL_LCD_SetBiasMode
  * @param    LCDx LCD instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref LL_LCD_SET_BIASMD_1_DIV4BIAS
  *           @arg @ref LL_LCD_SET_BIASMD_1_DIV3BIAS
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetBiasMode(LCD_Type* LCDx, uint32_t mode)
{
    MODIFY_REG(LCDx->CR, LCD_CR_BIASMD_Msk, mode);
}

/**
  * @brief    
  * @rmtoll   CR    BIASMD    LL_LCD_GetBiasMode
  * @param    LCDx LCD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LCD_SET_BIASMD_1_DIV4BIAS
  *           @arg @ref LL_LCD_SET_BIASMD_1_DIV3BIAS
  */
__STATIC_INLINE uint32_t LL_LCD_GetBiasMode(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_BIASMD_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    ANTIPOLAR    LL_LCD_SetAntiPolar
  * @param    LCDx LCD instance
  * @param    state This parameter can be one of the following values:
  *           @arg @ref LL_LCD_DISPCTRL_ANTIPOLAR_FLOATING
  *           @arg @ref LL_LCD_DISPCTRL_ANTIPOLAR_GND
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetAntiPolar(LCD_Type* LCDx, uint32_t state)
{
    MODIFY_REG(LCDx->CR, LCD_CR_ANTIPOLAR_Msk, state);
}

/**
  * @brief    
  * @rmtoll   CR    ANTIPOLAR    LL_LCD_GetAntiPolar
  * @param    LCDx LCD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LCD_DISPCTRL_ANTIPOLAR_FLOATING
  *           @arg @ref LL_LCD_DISPCTRL_ANTIPOLAR_GND
  */
__STATIC_INLINE uint32_t LL_LCD_GetAntiPolar(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_ANTIPOLAR_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    WFT    LL_LCD_SetWaveform
  * @param    LCDx LCD instance
  * @param    state This parameter can be one of the following values:
  *           @arg @ref LL_LCD_WAVEFORM_FORMAT_TYPE_A
  *           @arg @ref LL_LCD_WAVEFORM_FORMAT_TYPE_B
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetWaveform(LCD_Type* LCDx, uint32_t state)
{
    MODIFY_REG(LCDx->CR, LCD_CR_WFT_Msk, state);
}

/**
  * @brief    
  * @rmtoll   CR    WFT    LL_LCD_GetWaveform
  * @param    LCDx LCD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LCD_WAVEFORM_FORMAT_TYPE_A
  *           @arg @ref LL_LCD_WAVEFORM_FORMAT_TYPE_B
  */
__STATIC_INLINE uint32_t LL_LCD_GetWaveform(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_WFT_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    LMUX    LL_LCD_SetCOMxNum
  * @param    LCDx LCD instance
  * @param    number This parameter can be one of the following values:
  *           @arg @ref LL_LCD_SEG_LINE_SELECT_COM_4
  *           @arg @ref LL_LCD_SEG_LINE_SELECT_C0M_6
  *           @arg @ref LL_LCD_SEG_LINE_SELECT_C0M_8
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetCOMxNum(LCD_Type* LCDx, uint32_t number)
{
    MODIFY_REG(LCDx->CR, LCD_CR_LMUX_Msk, number);
}

/**
  * @brief    
  * @rmtoll   CR    LMUX    LL_LCD_GetCOMxNum
  * @param    LCDx LCD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LCD_SEG_LINE_SELECT_COM_4
  *           @arg @ref LL_LCD_SEG_LINE_SELECT_C0M_6
  *           @arg @ref LL_LCD_SEG_LINE_SELECT_C0M_8
  */
__STATIC_INLINE uint32_t LL_LCD_GetCOMxNum(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_LMUX_Msk));
}

/**
  * @brief    
  * @rmtoll   CR    EN    LL_LCD_Enable
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_Enable(LCD_Type* LCDx)
{
    SET_BIT(LCDx->CR, LCD_CR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    EN    LL_LCD_IsEnable
  * @param    LCDx LCD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnable(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->CR, LCD_CR_EN_Msk) == LCD_CR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    EN    LL_LCD_Disable
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_Disable(LCD_Type* LCDx)
{
    CLEAR_BIT(LCDx->CR, LCD_CR_EN_Msk);
}

/**
  * @brief    
  * @rmtoll   TEST    LCCTRL    LL_LCD_SetTestCtrl
  * @param    LCDx LCD instance
  * @param    ctrl This parameter can be one of the following values:
  *           @arg @ref LL_LCD_TEST_MODE_LCCTRL_0
  *           @arg @ref LL_LCD_TEST_MODE_LCCTRL_1
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetTestCtrl(LCD_Type* LCDx, uint32_t ctrl)
{
    MODIFY_REG(LCDx->TEST, LCD_TEST_LCCTRL_Msk, ctrl);
}

/**
  * @brief    
  * @rmtoll   TEST    LCCTRL    LL_LCD_GetTestCtrl
  * @param    LCDx LCD instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_LCD_TEST_MODE_LCCTRL_0
  *           @arg @ref LL_LCD_TEST_MODE_LCCTRL_1
  */
__STATIC_INLINE uint32_t LL_LCD_GetTestCtrl(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->TEST, LCD_TEST_LCCTRL_Msk));
}

/**
  * @brief    
  * @rmtoll   TEST    TESTEN    LL_LCD_Enable_Test
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_Enable_Test(LCD_Type* LCDx)
{
    SET_BIT(LCDx->TEST, LCD_TEST_TESTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   TEST    TESTEN    LL_LCD_tIsEnable_Test
  * @param    LCDx LCD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_tIsEnable_Test(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->TEST, LCD_TEST_TESTEN_Msk) == LCD_TEST_TESTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   TEST    TESTEN    LL_LCD_Disable_Test
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_Disable_Test(LCD_Type* LCDx)
{
    CLEAR_BIT(LCDx->TEST, LCD_TEST_TESTEN_Msk);
}

/**
  * @brief    
  * @rmtoll   FCR    DF    LL_LCD_SetDisplayFrequencyPsc
  * @param    LCDx LCD instance
  * @param    Psc 
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetDisplayFrequencyPsc(LCD_Type* LCDx, uint32_t Psc)
{
    MODIFY_REG(LCDx->FCR, (0xffU << 0U), (Psc << 0U));
}

/**
  * @brief    
  * @rmtoll   FCR    DF    LL_LCD_GetDisplayFrequencyPsc
  * @param    LCDx LCD instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_LCD_GetDisplayFrequencyPsc(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->FCR, 0xffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   FLKT    TOFF    LL_LCD_SetDisplayOffTime
  * @param    LCDx LCD instance
  * @param    time 
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetDisplayOffTime(LCD_Type* LCDx, uint32_t time)
{
    MODIFY_REG(LCDx->FLKT, (0xffU << 8U), (time << 8U));
}

/**
  * @brief    
  * @rmtoll   FLKT    TOFF    LL_LCD_GetDisplayOffTime
  * @param    LCDx LCD instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_LCD_GetDisplayOffTime(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->FLKT, 0xffU) >> 8U);
}

/**
  * @brief    
  * @rmtoll   FLKT    TON    LL_LCD_SetDispalyOnTime
  * @param    LCDx LCD instance
  * @param    time 
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetDispalyOnTime(LCD_Type* LCDx, uint32_t time)
{
    MODIFY_REG(LCDx->FLKT, (0xffU << 0U), (time << 0U));
}

/**
  * @brief    
  * @rmtoll   FLKT    TON    LL_LCD_GetDisplayOnTime
  * @param    LCDx LCD instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_LCD_GetDisplayOnTime(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->FLKT, 0xffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   IER    DONIE    LL_LCD_EnableIT_DisplayOff
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_EnableIT_DisplayOff(LCD_Type* LCDx)
{
    SET_BIT(LCDx->IER, LCD_IER_DONIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    DONIE    LL_LCD_DisableIT_DisplayOff
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_DisableIT_DisplayOff(LCD_Type* LCDx)
{
    CLEAR_BIT(LCDx->IER, LCD_IER_DONIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    DONIE    LL_LCD_IsEnableIT_DisplayOff
  * @param    LCDx LCD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnableIT_DisplayOff(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->IER, LCD_IER_DONIE_Msk) == LCD_IER_DONIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    DOFFIE    LL_LCD_EnableIT_DisplayOn
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_EnableIT_DisplayOn(LCD_Type* LCDx)
{
    SET_BIT(LCDx->IER, LCD_IER_DOFFIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    DOFFIE    LL_LCD_DisableIT_DisplayOn
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_DisableIT_DisplayOn(LCD_Type* LCDx)
{
    CLEAR_BIT(LCDx->IER, LCD_IER_DOFFIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    DOFFIE    LL_LCD_IsEnableIT_DisplayOn
  * @param    LCDx LCD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnableIT_DisplayOn(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->IER, LCD_IER_DOFFIE_Msk) == LCD_IER_DOFFIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    DONIF    LL_LCD_IsActiveFlag_DisplayOff
  * @param    LCDx LCD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsActiveFlag_DisplayOff(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->ISR, LCD_ISR_DONIF_Msk) == (LCD_ISR_DONIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    DONIF    LL_LCD_ClearFlag_DisplayOff
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_ClearFlag_DisplayOff(LCD_Type* LCDx)
{
    WRITE_REG(LCDx->ISR, LCD_ISR_DONIF_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    DOFFIF    LL_LCD_IsActiveFlag_DisplayOn
  * @param    LCDx LCD instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsActiveFlag_DisplayOn(LCD_Type* LCDx)
{
    return (uint32_t)(READ_BIT(LCDx->ISR, LCD_ISR_DOFFIF_Msk) == (LCD_ISR_DOFFIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    DOFFIF    LL_LCD_ClearFlag_DisplayOn
  * @param    LCDx LCD instance
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_ClearFlag_DisplayOn(LCD_Type* LCDx)
{
    WRITE_REG(LCDx->ISR, LCD_ISR_DOFFIF_Msk);
}

/**
  * @brief    
  * @rmtoll   DATA0    DSDA    LL_LCD_SetDisplayData
  * @param    LCDx LCD instance
  * @param    data This parameter can be one of the following values:
  * @param    DataRegister This parameter can be one of the following values:
  *           @arg @ref LL_LCD_DATA_REG_0
  *           @arg @ref LL_LCD_DATA_REG_1
  *           @arg @ref LL_LCD_DATA_REG_2
  *           @arg @ref LL_LCD_DATA_REG_3
  *           @arg @ref LL_LCD_DATA_REG_4
  *           @arg @ref LL_LCD_DATA_REG_5
  *           @arg @ref LL_LCD_DATA_REG_6
  *           @arg @ref LL_LCD_DATA_REG_7
  *           @arg @ref LL_LCD_DATA_REG_8
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_SetDisplayData(LCD_Type* LCDx, uint32_t data, uint32_t DataRegister)
{
    volatile uint32_t *Temp_data = &(LCDx->DATA0);
    MODIFY_REG(Temp_data[DataRegister], LCD_DATA0_DSDA_Msk, data);
}

/**
  * @brief    
  * @rmtoll   DATA0    DSDA    LL_LCD_GetDisplayData
  * @param    LCDx LCD instance
  * @param    DataRegister This parameter can be one of the following values:
  *           @arg @ref LL_LCD_DATA_REG_0
  *           @arg @ref LL_LCD_DATA_REG_1
  *           @arg @ref LL_LCD_DATA_REG_2
  *           @arg @ref LL_LCD_DATA_REG_3
  *           @arg @ref LL_LCD_DATA_REG_4
  *           @arg @ref LL_LCD_DATA_REG_5
  *           @arg @ref LL_LCD_DATA_REG_6
  *           @arg @ref LL_LCD_DATA_REG_7
  *           @arg @ref LL_LCD_DATA_REG_8
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t LL_LCD_GetDisplayData(LCD_Type* LCDx, uint32_t DataRegister)
{
    volatile uint32_t *Temp_data = &(LCDx->DATA0);
    return (uint32_t)(READ_BIT(Temp_data[DataRegister], LCD_DATA0_DSDA_Msk));
}

/**
  * @brief    
  * @rmtoll   COMEN        LL_LCD_IsEnabledComPin
  * @param    LCDx LCD instance
  * @param    ComNum This parameter can be one of the following values:
  *           @arg @ref LL_LCD_COM_EN_COM0
  *           @arg @ref LL_LCD_COM_EN_COM1
  *           @arg @ref LL_LCD_COM_EN_COM2
  *           @arg @ref LL_LCD_COM_EN_COM3
  *           @arg @ref LL_LCD_COM_EN_COM4
  *           @arg @ref LL_LCD_COM_EN_COM5
  *           @arg @ref LL_LCD_COM_EN_COM6
  *           @arg @ref LL_LCD_COM_EN_COM7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnabledComPin(LCD_Type* LCDx, uint32_t ComNum)
{
    if(ComNum <= LL_LCD_COM_EN_COM3)
    {
        return (uint32_t)(READ_BIT(LCDx->COMEN, ((ComNum & 0xffffffff) << 0x0U)) == ((ComNum & 0xffffffff) << 0x0U));
    }
    else
    {
        return (uint32_t)(READ_BIT(LCDx->SEGEN0, ((ComNum & 0xffffffff) << 0x0U)) == ((ComNum & 0xffffffff) << 0x0U));
    }
}

/**
  * @brief    
  * @rmtoll   COMEN        LL_LCD_EnableComPin
  * @param    LCDx LCD instance
  * @param    ComNum This parameter can be one of the following values:
  *           @arg @ref LL_LCD_COM_EN_COM0
  *           @arg @ref LL_LCD_COM_EN_COM1
  *           @arg @ref LL_LCD_COM_EN_COM2
  *           @arg @ref LL_LCD_COM_EN_COM3
  *           @arg @ref LL_LCD_COM_EN_COM4
  *           @arg @ref LL_LCD_COM_EN_COM5
  *           @arg @ref LL_LCD_COM_EN_COM6
  *           @arg @ref LL_LCD_COM_EN_COM7
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_EnableComPin(LCD_Type* LCDx, uint32_t ComNum)
{
    if(ComNum <= LL_LCD_COM_EN_COM3)
    {
        SET_BIT(LCDx->COMEN, ((ComNum & 0xffffffff) << 0x0U));
    }
    else
    {
        SET_BIT(LCDx->SEGEN0, ((ComNum & 0xffffffff) << 0x0U));
    }
}

/**
  * @brief    
  * @rmtoll   COMEN        LL_LCD_DisableComPin
  * @param    LCDx LCD instance
  * @param    ComNum This parameter can be one of the following values:
  *           @arg @ref LL_LCD_COM_EN_COM0
  *           @arg @ref LL_LCD_COM_EN_COM1
  *           @arg @ref LL_LCD_COM_EN_COM2
  *           @arg @ref LL_LCD_COM_EN_COM3
  *           @arg @ref LL_LCD_COM_EN_COM4
  *           @arg @ref LL_LCD_COM_EN_COM5
  *           @arg @ref LL_LCD_COM_EN_COM6
  *           @arg @ref LL_LCD_COM_EN_COM7
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_DisableComPin(LCD_Type* LCDx, uint32_t ComNum)
{
    if(ComNum <= LL_LCD_COM_EN_COM3)
    {
        CLEAR_BIT(LCDx->COMEN, ((ComNum & 0xffffffff) << 0x0U));
    }
    else
    {
        CLEAR_BIT(LCDx->SEGEN0, ((ComNum & 0xffffffff) << 0x0U));
    }
}

/**
  * @brief    
  * @rmtoll   SEGEN0        LL_LCD_IsEnabledSegPin
  * @param    LCDx LCD instance
  * @param    ComNum This parameter can be one of the following values:
  *           @arg @ref LL_LCD_SEG_EN0_SEG0
  *           @arg @ref LL_LCD_SEG_EN0_SEG1
  *           @arg @ref LL_LCD_SEG_EN0_SEG2
  *           @arg @ref LL_LCD_SEG_EN0_SEG3
  *           @arg @ref LL_LCD_SEG_EN0_SEG4
  *           @arg @ref LL_LCD_SEG_EN0_SEG5
  *           @arg @ref LL_LCD_SEG_EN0_SEG6
  *           @arg @ref LL_LCD_SEG_EN0_SEG7
  *           @arg @ref LL_LCD_SEG_EN0_SEG8
  *           @arg @ref LL_LCD_SEG_EN0_SEG9
  *           @arg @ref LL_LCD_SEG_EN0_SEG10
  *           @arg @ref LL_LCD_SEG_EN0_SEG11
  *           @arg @ref LL_LCD_SEG_EN0_SEG12
  *           @arg @ref LL_LCD_SEG_EN0_SEG13
  *           @arg @ref LL_LCD_SEG_EN0_SEG14
  *           @arg @ref LL_LCD_SEG_EN0_SEG15
  *           @arg @ref LL_LCD_SEG_EN0_SEG16
  *           @arg @ref LL_LCD_SEG_EN0_SEG17
  *           @arg @ref LL_LCD_SEG_EN0_SEG18
  *           @arg @ref LL_LCD_SEG_EN0_SEG19
  *           @arg @ref LL_LCD_SEG_EN0_SEG20
  *           @arg @ref LL_LCD_SEG_EN0_SEG21
  *           @arg @ref LL_LCD_SEG_EN0_SEG22
  *           @arg @ref LL_LCD_SEG_EN0_SEG23
  *           @arg @ref LL_LCD_SEG_EN0_SEG24
  *           @arg @ref LL_LCD_SEG_EN0_SEG25
  *           @arg @ref LL_LCD_SEG_EN0_SEG26
  *           @arg @ref LL_LCD_SEG_EN0_SEG27
  *           @arg @ref LL_LCD_SEG_EN0_SEG28
  *           @arg @ref LL_LCD_SEG_EN0_SEG29
  *           @arg @ref LL_LCD_SEG_EN0_SEG30
  *           @arg @ref LL_LCD_SEG_EN0_SEG31
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_LCD_IsEnabledSegPin(LCD_Type* LCDx, uint32_t ComNum)
{
    return (uint32_t)(READ_BIT(LCDx->SEGEN0, ((ComNum & 0xffffffff) << 0x0U)) == ((ComNum & 0xffffffff) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   SEGEN0        LL_LCD_EnableSegPin
  * @param    LCDx LCD instance
  * @param    ComNum This parameter can be one of the following values:
  *           @arg @ref LL_LCD_SEG_EN0_SEG0
  *           @arg @ref LL_LCD_SEG_EN0_SEG1
  *           @arg @ref LL_LCD_SEG_EN0_SEG2
  *           @arg @ref LL_LCD_SEG_EN0_SEG3
  *           @arg @ref LL_LCD_SEG_EN0_SEG4
  *           @arg @ref LL_LCD_SEG_EN0_SEG5
  *           @arg @ref LL_LCD_SEG_EN0_SEG6
  *           @arg @ref LL_LCD_SEG_EN0_SEG7
  *           @arg @ref LL_LCD_SEG_EN0_SEG8
  *           @arg @ref LL_LCD_SEG_EN0_SEG9
  *           @arg @ref LL_LCD_SEG_EN0_SEG10
  *           @arg @ref LL_LCD_SEG_EN0_SEG11
  *           @arg @ref LL_LCD_SEG_EN0_SEG12
  *           @arg @ref LL_LCD_SEG_EN0_SEG13
  *           @arg @ref LL_LCD_SEG_EN0_SEG14
  *           @arg @ref LL_LCD_SEG_EN0_SEG15
  *           @arg @ref LL_LCD_SEG_EN0_SEG16
  *           @arg @ref LL_LCD_SEG_EN0_SEG17
  *           @arg @ref LL_LCD_SEG_EN0_SEG18
  *           @arg @ref LL_LCD_SEG_EN0_SEG19
  *           @arg @ref LL_LCD_SEG_EN0_SEG20
  *           @arg @ref LL_LCD_SEG_EN0_SEG21
  *           @arg @ref LL_LCD_SEG_EN0_SEG22
  *           @arg @ref LL_LCD_SEG_EN0_SEG23
  *           @arg @ref LL_LCD_SEG_EN0_SEG24
  *           @arg @ref LL_LCD_SEG_EN0_SEG25
  *           @arg @ref LL_LCD_SEG_EN0_SEG26
  *           @arg @ref LL_LCD_SEG_EN0_SEG27
  *           @arg @ref LL_LCD_SEG_EN0_SEG28
  *           @arg @ref LL_LCD_SEG_EN0_SEG29
  *           @arg @ref LL_LCD_SEG_EN0_SEG30
  *           @arg @ref LL_LCD_SEG_EN0_SEG31
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_EnableSegPin(LCD_Type* LCDx, uint32_t ComNum)
{
    SET_BIT(LCDx->SEGEN0, ((ComNum & 0xffffffff) << 0x0U));
}

/**
  * @brief    
  * @rmtoll   SEGEN0        LL_LCD_DisableSegPin
  * @param    LCDx LCD instance
  * @param    ComNum This parameter can be one of the following values:
  *           @arg @ref LL_LCD_SEG_EN0_SEG0
  *           @arg @ref LL_LCD_SEG_EN0_SEG1
  *           @arg @ref LL_LCD_SEG_EN0_SEG2
  *           @arg @ref LL_LCD_SEG_EN0_SEG3
  *           @arg @ref LL_LCD_SEG_EN0_SEG4
  *           @arg @ref LL_LCD_SEG_EN0_SEG5
  *           @arg @ref LL_LCD_SEG_EN0_SEG6
  *           @arg @ref LL_LCD_SEG_EN0_SEG7
  *           @arg @ref LL_LCD_SEG_EN0_SEG8
  *           @arg @ref LL_LCD_SEG_EN0_SEG9
  *           @arg @ref LL_LCD_SEG_EN0_SEG10
  *           @arg @ref LL_LCD_SEG_EN0_SEG11
  *           @arg @ref LL_LCD_SEG_EN0_SEG12
  *           @arg @ref LL_LCD_SEG_EN0_SEG13
  *           @arg @ref LL_LCD_SEG_EN0_SEG14
  *           @arg @ref LL_LCD_SEG_EN0_SEG15
  *           @arg @ref LL_LCD_SEG_EN0_SEG16
  *           @arg @ref LL_LCD_SEG_EN0_SEG17
  *           @arg @ref LL_LCD_SEG_EN0_SEG18
  *           @arg @ref LL_LCD_SEG_EN0_SEG19
  *           @arg @ref LL_LCD_SEG_EN0_SEG20
  *           @arg @ref LL_LCD_SEG_EN0_SEG21
  *           @arg @ref LL_LCD_SEG_EN0_SEG22
  *           @arg @ref LL_LCD_SEG_EN0_SEG23
  *           @arg @ref LL_LCD_SEG_EN0_SEG24
  *           @arg @ref LL_LCD_SEG_EN0_SEG25
  *           @arg @ref LL_LCD_SEG_EN0_SEG26
  *           @arg @ref LL_LCD_SEG_EN0_SEG27
  *           @arg @ref LL_LCD_SEG_EN0_SEG28
  *           @arg @ref LL_LCD_SEG_EN0_SEG29
  *           @arg @ref LL_LCD_SEG_EN0_SEG30
  *           @arg @ref LL_LCD_SEG_EN0_SEG31
  * @retval   None
  */
__STATIC_INLINE void LL_LCD_DisableSegPin(LCD_Type* LCDx, uint32_t ComNum)
{
    CLEAR_BIT(LCDx->SEGEN0, ((ComNum & 0xffffffff) << 0x0U));
}

/**
  * @}
  */

/** @defgroup LCD_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_LCD_DeInit(LCD_Type *LCDx);
void LL_LCD_StructInit(LL_LCD_InitTypeDef *LCD_InitStruct);
ErrorStatus LL_LCD_Init(LCD_Type *LCDx, LL_LCD_InitTypeDef *LCD_InitStruct);
/**
  * @}
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

#endif /* __FM33LC0XX_LL_LCD_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-11-21**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
