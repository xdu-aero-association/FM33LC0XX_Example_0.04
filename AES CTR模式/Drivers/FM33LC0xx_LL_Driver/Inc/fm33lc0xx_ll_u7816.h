/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_u7816.h
  * @author  FMSH Application Team
  * @brief   Head file of U7816 LL Module
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
#ifndef __FM33LC0XX_LL_U7816_H
#define __FM33LC0XX_LL_U7816_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
/** @addtogroup FM33LC0XX_LL_Driver_U7816
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup U7816_LL_ES_INIT U7816 Exported Init structures
  * @{
  */

/**
  * @brief LL U7816 Init Sturcture definition
  */
typedef struct
{
    /*! 通讯速率 */  
    uint32_t Baud; 
    /*! 帧格式奇偶校验模式 */    
    uint32_t Parity;
    /*! 接口发送失败后自动重试使能 */    
    uint32_t TxAutoRetry;
    /*! 自动重试次数 */
    uint32_t RetryCnt;  
    /*! 块保护使能 */    
    uint32_t BlockGuard;
    /*! 强上拉使能 */   
    uint32_t StrongPullUp;
    /*! 帧格式 接收Guard时间 */    
    uint32_t RxGuardTime;
    /*!帧格式  发送Guard时间 */    
    uint32_t TxGuardTime;  
    /*! 帧格式 错误Guard时间 */   
    uint32_t ErrorGuardTime;  
    /*! 额外  发送Guard时间 */    
    uint32_t ExtraGuardTime;
    /*! 帧错误信号长度 */    
    uint32_t ErrorSignalTime;
    /*! 接收校验错自动回发error signal使能 */
    uint32_t RxAutoErrorSignal;
    /*! 传输BIT顺序 */    
    uint32_t TransferOrder;
    /*! 卡时钟频率 */    
    uint32_t OutputClockFreqence;         
                          
} LL_U7816_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup U7816_LL_Exported_Constants U7816 Exported Constants
  * @{
  */
#define    LL_U7816_GUARD_TIME_TX_X2_ETU                          (0x0U << U7816_FFR_SFREN_Pos)
#define    LL_U7816_GUARD_TIME_TX_X3_ETU                          (0x1U << U7816_FFR_SFREN_Pos)

#define    LL_U7816_ERROR_SIGNAL_WIDTH_X2_ETU                     (0x1U << U7816_FFR_ERSW_Pos)
#define    LL_U7816_ERROR_SIGNAL_WIDTH_X1_5ETU                    (0x2U << U7816_FFR_ERSW_Pos)
#define    LL_U7816_ERROR_SIGNAL_WIDTH_X1_ETU                     (0x3U << U7816_FFR_ERSW_Pos)

#define    LL_U7816_ERROR_GUARD_TIME_X2_ETU                       (0x0U << U7816_FFR_ERSGD_Pos)
#define    LL_U7816_ERROR_GUARD_TIME_X1_ETU                       (0x1U << U7816_FFR_ERSGD_Pos)

#define    LL_U7816_RETRY_CNT_X1                                  (0x0U << U7816_FFR_REP_T_Pos)
#define    LL_U7816_RETRY_CNT_X3                                  (0x1U << U7816_FFR_REP_T_Pos)

#define    LL_U7816_PARITY_EVEN                                   (0x0U << U7816_FFR_PAR_Pos)
#define    LL_U7816_PARITY_ODD                                    (0x1U << U7816_FFR_PAR_Pos)
#define    LL_U7816_PARITY_ALWAYS_1                               (0x2U << U7816_FFR_PAR_Pos)
#define    LL_U7816_PARITY_NONE                                   (0x3U << U7816_FFR_PAR_Pos)

#define    LL_U7816_GUARD_TIME_RX_X2_ETU                          (0x0U << U7816_FFR_RFREN_Pos)
#define    LL_U7816_GUARD_TIME_RX_X1_ETU                          (0x1U << U7816_FFR_RFREN_Pos)

#define    LL_U7816_AUTO_RETRY_DISABLE                            (0x0U << U7816_FFR_TREPEN_Pos)
#define    LL_U7816_AUTO_RETRY_ENABLE                             (0x1U << U7816_FFR_TREPEN_Pos)

#define    LL_U7816_AUTO_RESPOND_ERR_SIG_DISABLE                  (0x0U << U7816_FFR_RREPEN_Pos)
#define    LL_U7816_AUTO_RESPOND_ERR_SIG_ENABLE                   (0x1U << U7816_FFR_RREPEN_Pos)

#define    LL_U7816_BIT_ORDER_FIRST_LSB                           (0x0U << U7816_FFR_DICONV_Pos)
#define    LL_U7816_BIT_ORDER_FIRST_MSB                           (0x1U << U7816_FFR_DICONV_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup U7816_LL_Exported_Functions U7816 Exported Functions
  * @{
  */

/**
  * @brief    
  * @rmtoll   CR    TXEN    LL_U7816_EnableTx
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_EnableTx(U7816_Type* U7816x)
{
    SET_BIT(U7816x->CR, U7816_CR_TXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TXEN    LL_U7816_IsEnabledTx
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsEnabledTx(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->CR, U7816_CR_TXEN_Msk) == U7816_CR_TXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    TXEN    LL_U7816_DisableTx
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_DisableTx(U7816_Type* U7816x)
{
    CLEAR_BIT(U7816x->CR, U7816_CR_TXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    RXEN    LL_U7816_EnableRx
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_EnableRx(U7816_Type* U7816x)
{
    SET_BIT(U7816x->CR, U7816_CR_RXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    RXEN    LL_U7816_IsEnabledRx
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsEnabledRx(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->CR, U7816_CR_RXEN_Msk) == U7816_CR_RXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    RXEN    LL_U7816_DisableRx
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_DisableRx(U7816_Type* U7816x)
{
    CLEAR_BIT(U7816x->CR, U7816_CR_RXEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    CKOEN    LL_U7816_EnableClkOutPut
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_EnableClkOutPut(U7816_Type* U7816x)
{
    SET_BIT(U7816x->CR, U7816_CR_CKOEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    CKOEN    LL_U7816_IsEnabledClkOutPut
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsEnabledClkOutPut(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->CR, U7816_CR_CKOEN_Msk) == U7816_CR_CKOEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    CKOEN    LL_U7816_DisableClkOutPut
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_DisableClkOutPut(U7816_Type* U7816x)
{
    CLEAR_BIT(U7816x->CR, U7816_CR_CKOEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    HPUAT    LL_U7816_EnableTxAutoPullUp
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_EnableTxAutoPullUp(U7816_Type* U7816x)
{
    SET_BIT(U7816x->CR, U7816_CR_HPUAT_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    HPUAT    LL_U7816_IsEnabledTxAutoPullUp
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsEnabledTxAutoPullUp(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->CR, U7816_CR_HPUAT_Msk) == U7816_CR_HPUAT_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    HPUAT    LL_U7816_DisableTxAutoPullUp
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_DisableTxAutoPullUp(U7816_Type* U7816x)
{
    CLEAR_BIT(U7816x->CR, U7816_CR_HPUAT_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    HPUEN    LL_U7816_SetPullUpEnable
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetPullUpEnable(U7816_Type* U7816x)
{
    SET_BIT(U7816x->CR, U7816_CR_HPUEN_Msk);
}

/**
  * @brief    
  * @rmtoll   CR    HPUEN    LL_U7816_SetPullUpDisable
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetPullUpDisable(U7816_Type* U7816x)
{
    CLEAR_BIT(U7816x->CR, U7816_CR_HPUEN_Msk);
}

/**
  * @brief    
  * @rmtoll   FFR    SFREN    LL_U7816_SetTxGuardTime
  * @param    U7816x U7816 instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref LL_U7816_GUARD_TIME_TX_X2_ETU
  *           @arg @ref LL_U7816_GUARD_TIME_TX_X3_ETU
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetTxGuardTime(U7816_Type* U7816x, uint32_t config)
{
    MODIFY_REG(U7816x->FFR, U7816_FFR_SFREN_Msk, config);
}

/**
  * @brief    
  * @rmtoll   FFR    SFREN    LL_U7816_GetTxGuardTime
  * @param    U7816x U7816 instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_U7816_GUARD_TIME_TX_X2_ETU
  *           @arg @ref LL_U7816_GUARD_TIME_TX_X3_ETU
  */
__STATIC_INLINE uint32_t LL_U7816_GetTxGuardTime(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_FFR_SFREN_Msk));
}

/**
  * @brief    
  * @rmtoll   FFR    ERSW    LL_U7816_SetErrorSignalWidth
  * @param    U7816x U7816 instance
  * @param    width This parameter can be one of the following values:
  *           @arg @ref LL_U7816_ERROR_SIGNAL_WIDTH_X2_ETU
  *           @arg @ref LL_U7816_ERROR_SIGNAL_WIDTH_X1_5ETU
  *           @arg @ref LL_U7816_ERROR_SIGNAL_WIDTH_X1_ETU
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetErrorSignalWidth(U7816_Type* U7816x, uint32_t width)
{
    MODIFY_REG(U7816x->FFR, U7816_FFR_ERSW_Msk, width);
}

/**
  * @brief    
  * @rmtoll   FFR    ERSW    LL_U7816_GetErrorSignalWidth
  * @param    U7816x U7816 instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_U7816_ERROR_SIGNAL_WIDTH_X2_ETU
  *           @arg @ref LL_U7816_ERROR_SIGNAL_WIDTH_X1_5ETU
  *           @arg @ref LL_U7816_ERROR_SIGNAL_WIDTH_X1_ETU
  */
__STATIC_INLINE uint32_t LL_U7816_GetErrorSignalWidth(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_FFR_ERSW_Msk));
}

/**
  * @brief    
  * @rmtoll   FFR    ERSGD    LL_U7816_SetErrorGuardTime
  * @param    U7816x U7816 instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref LL_U7816_ERROR_GUARD_TIME_X2_ETU
  *           @arg @ref LL_U7816_ERROR_GUARD_TIME_X1_ETU
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetErrorGuardTime(U7816_Type* U7816x, uint32_t config)
{
    MODIFY_REG(U7816x->FFR, U7816_FFR_ERSGD_Msk, config);
}

/**
  * @brief    
  * @rmtoll   FFR    ERSGD    LL_U7816_GetErrorGuardTime
  * @param    U7816x U7816 instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_U7816_ERROR_GUARD_TIME_X2_ETU
  *           @arg @ref LL_U7816_ERROR_GUARD_TIME_X1_ETU
  */
__STATIC_INLINE uint32_t LL_U7816_GetErrorGuardTime(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_FFR_ERSGD_Msk));
}

/**
  * @brief    
  * @rmtoll   FFR    BGT    LL_U7816_EnableBlockGuardTime
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_EnableBlockGuardTime(U7816_Type* U7816x)
{
    SET_BIT(U7816x->FFR, U7816_CR_BGT_Msk);
}

/**
  * @brief    
  * @rmtoll   FFR    BGT    LL_U7816_IsEnabledBlockGuardTime
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsEnabledBlockGuardTime(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_CR_BGT_Msk) == U7816_CR_BGT_Msk);
}

/**
  * @brief    
  * @rmtoll   FFR    BGT    LL_U7816_DisableBlockGuardTime
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_DisableBlockGuardTime(U7816_Type* U7816x)
{
    CLEAR_BIT(U7816x->FFR, U7816_CR_BGT_Msk);
}

/**
  * @brief    
  * @rmtoll   FFR    REP_T    LL_U7816_SetRetryCnt
  * @param    U7816x U7816 instance
  * @param    cnt This parameter can be one of the following values:
  *           @arg @ref LL_U7816_RETRY_CNT_X1
  *           @arg @ref LL_U7816_RETRY_CNT_X3
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetRetryCnt(U7816_Type* U7816x, uint32_t cnt)
{
    MODIFY_REG(U7816x->FFR, U7816_FFR_REP_T_Msk, cnt);
}

/**
  * @brief    
  * @rmtoll   FFR    REP_T    LL_U7816_GetRetryCnt
  * @param    U7816x U7816 instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_U7816_RETRY_CNT_X1
  *           @arg @ref LL_U7816_RETRY_CNT_X3
  */
__STATIC_INLINE uint32_t LL_U7816_GetRetryCnt(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_FFR_REP_T_Msk));
}

/**
  * @brief    
  * @rmtoll   FFR    PAR    LL_U7816_SetParity
  * @param    U7816x U7816 instance
  * @param    cnt This parameter can be one of the following values:
  *           @arg @ref LL_U7816_PARITY_EVEN
  *           @arg @ref LL_U7816_PARITY_ODD
  *           @arg @ref LL_U7816_PARITY_ALWAYS_1
  *           @arg @ref LL_U7816_PARITY_NONE
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetParity(U7816_Type* U7816x, uint32_t cnt)
{
    MODIFY_REG(U7816x->FFR, U7816_FFR_PAR_Msk, cnt);
}

/**
  * @brief    
  * @rmtoll   FFR    PAR    LL_U7816_GetParity
  * @param    U7816x U7816 instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_U7816_PARITY_EVEN
  *           @arg @ref LL_U7816_PARITY_ODD
  *           @arg @ref LL_U7816_PARITY_ALWAYS_1
  *           @arg @ref LL_U7816_PARITY_NONE
  */
__STATIC_INLINE uint32_t LL_U7816_GetParity(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_FFR_PAR_Msk));
}

/**
  * @brief    
  * @rmtoll   FFR    RFREN    LL_U7816_SetRxGuardTime
  * @param    U7816x U7816 instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref LL_U7816_GUARD_TIME_RX_X2_ETU
  *           @arg @ref LL_U7816_GUARD_TIME_RX_X1_ETU
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetRxGuardTime(U7816_Type* U7816x, uint32_t config)
{
    MODIFY_REG(U7816x->FFR, U7816_FFR_RFREN_Msk, config);
}

/**
  * @brief    
  * @rmtoll   FFR    RFREN    LL_U7816_GetRxGuardTime
  * @param    U7816x U7816 instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_U7816_GUARD_TIME_RX_X2_ETU
  *           @arg @ref LL_U7816_GUARD_TIME_RX_X1_ETU
  */
__STATIC_INLINE uint32_t LL_U7816_GetRxGuardTime(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_FFR_RFREN_Msk));
}

/**
  * @brief    
  * @rmtoll   FFR    TREPEN    LL_U7816_SetTxParityErrorAutoRetry
  * @param    U7816x U7816 instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref LL_U7816_AUTO_RETRY_DISABLE
  *           @arg @ref LL_U7816_AUTO_RETRY_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetTxParityErrorAutoRetry(U7816_Type* U7816x, uint32_t config)
{
    MODIFY_REG(U7816x->FFR, U7816_FFR_TREPEN_Msk, config);
}

/**
  * @brief    
  * @rmtoll   FFR    TREPEN    LL_U7816_GetTxParityErrorAutoRetry
  * @param    U7816x U7816 instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_U7816_AUTO_RETRY_DISABLE
  *           @arg @ref LL_U7816_AUTO_RETRY_ENABLE
  */
__STATIC_INLINE uint32_t LL_U7816_GetTxParityErrorAutoRetry(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_FFR_TREPEN_Msk));
}

/**
  * @brief    
  * @rmtoll   FFR    RREPEN    LL_U7816_SetRxParityErrorAutoRespons
  * @param    U7816x U7816 instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref LL_U7816_AUTO_RESPOND_ERR_SIG_DISABLE
  *           @arg @ref LL_U7816_AUTO_RESPOND_ERR_SIG_ENABLE
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetRxParityErrorAutoRespons(U7816_Type* U7816x, uint32_t config)
{
    MODIFY_REG(U7816x->FFR, U7816_FFR_RREPEN_Msk, config);
}

/**
  * @brief    
  * @rmtoll   FFR    RREPEN    LL_U7816_GetRxParityErrorAutoRetry
  * @param    U7816x U7816 instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_U7816_AUTO_RESPOND_ERR_SIG_DISABLE
  *           @arg @ref LL_U7816_AUTO_RESPOND_ERR_SIG_ENABLE
  */
__STATIC_INLINE uint32_t LL_U7816_GetRxParityErrorAutoRetry(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_FFR_RREPEN_Msk));
}

/**
  * @brief    
  * @rmtoll   FFR    DICONV    LL_U7816_SetBitOrder
  * @param    U7816x U7816 instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref LL_U7816_BIT_ORDER_FIRST_LSB
  *           @arg @ref LL_U7816_BIT_ORDER_FIRST_MSB
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetBitOrder(U7816_Type* U7816x, uint32_t config)
{
    MODIFY_REG(U7816x->FFR, U7816_FFR_DICONV_Msk, config);
}

/**
  * @brief    
  * @rmtoll   FFR    DICONV    LL_U7816_GetBitOrder
  * @param    U7816x U7816 instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref LL_U7816_BIT_ORDER_FIRST_LSB
  *           @arg @ref LL_U7816_BIT_ORDER_FIRST_MSB
  */
__STATIC_INLINE uint32_t LL_U7816_GetBitOrder(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->FFR, U7816_FFR_DICONV_Msk));
}

/**
  * @brief    
  * @rmtoll   EGTR        LL_U7816_SetExtraGuardTime
  * @param    U7816x U7816 instance
  * @param    time 
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetExtraGuardTime(U7816_Type* U7816x, uint32_t time)
{
    MODIFY_REG(U7816x->EGTR, (0xffU << 0U), (time << 0U));
}

/**
  * @brief    
  * @rmtoll   EGTR        LL_U7816_GetExtraGuardTime
  * @param    U7816x U7816 instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_U7816_GetExtraGuardTime(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->EGTR, 0xffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   PSC        LL_U7816_SetClockDivide
  * @param    U7816x U7816 instance
  * @param    div 
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetClockDivide(U7816_Type* U7816x, uint32_t div)
{
    MODIFY_REG(U7816x->PSC, (0x1fU << 0U), (div << 0U));
}

/**
  * @brief    
  * @rmtoll   PSC        LL_U7816_GetClockDivide
  * @param    U7816x U7816 instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_U7816_GetClockDivide(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->PSC, 0x1fU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   BGR        LL_U7816_SetBaudRate
  * @param    U7816x U7816 instance
  * @param    baud 
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_SetBaudRate(U7816_Type* U7816x, uint32_t baud)
{
    MODIFY_REG(U7816x->BGR, (0xfffU << 0U), (baud << 0U));
}

/**
  * @brief    
  * @rmtoll   BGR        LL_U7816_GetBaudRate
  * @param    U7816x U7816 instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_U7816_GetBaudRate(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->BGR, 0xfffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   TXBUF        LL_U7816_WriteBuff
  * @param    U7816x U7816 instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_WriteBuff(U7816_Type* U7816x, uint32_t data)
{
    MODIFY_REG(U7816x->TXBUF, (0xffU << 0U), (data << 0U));
}

/**
  * @brief    
  * @rmtoll   RXBUF        LL_U7816_ReadBuff
  * @param    U7816x U7816 instance
  * @retval   
  */
__STATIC_INLINE uint32_t LL_U7816_ReadBuff(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->RXBUF, 0xffU) >> 0U);
}

/**
  * @brief    
  * @rmtoll   IER    RXIE    LL_U7816_DisableIT_RxComplete
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_DisableIT_RxComplete(U7816_Type* U7816x)
{
    CLEAR_BIT(U7816x->IER, U7816_IER_RXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXIE    LL_U7816_EnabledIT_RxComplete
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_EnabledIT_RxComplete(U7816_Type* U7816x)
{
    SET_BIT(U7816x->IER, U7816_IER_RXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    RXIE    LL_U7816_IsEnabledIT_RxComplete
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsEnabledIT_RxComplete(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->IER, U7816_IER_RXIE_Msk) == U7816_IER_RXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXIE    LL_U7816_DisableIT_TxComplete
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_DisableIT_TxComplete(U7816_Type* U7816x)
{
    CLEAR_BIT(U7816x->IER, U7816_IER_TXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    TXIE    LL_U7816_EnabledIT_TxComplete
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_EnabledIT_TxComplete(U7816_Type* U7816x)
{
    SET_BIT(U7816x->IER, U7816_IER_TXIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    LSIE    LL_U7816_DisableIT_Error
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_DisableIT_Error(U7816_Type* U7816x)
{
    CLEAR_BIT(U7816x->IER, U7816_IER_LSIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    LSIE    LL_U7816_EnabledIT_Error
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_EnabledIT_Error(U7816_Type* U7816x)
{
    SET_BIT(U7816x->IER, U7816_IER_LSIE_Msk);
}

/**
  * @brief    
  * @rmtoll   IER    LSIE    LL_U7816_IsEnabledIT_Error
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsEnabledIT_Error(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->IER, U7816_IER_LSIE_Msk) == U7816_IER_LSIE_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    WAIT_PRT    LL_U7816_IsActiveFlag_RxWaitRetry
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_RxWaitRetry(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_WAIT_PRT_Msk) == (U7816_ISR_WAIT_PRT_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    TXBUSY    LL_U7816_IsActiveFlag_TxBusy
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_TxBusy(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_TXBUSY_Msk) == (U7816_ISR_TXBUSY_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    RXBUSY    LL_U7816_IsActiveFlag_RxBusy
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_RxBusy(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_RXBUSY_Msk) == (U7816_ISR_RXBUSY_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    TPARERR    LL_U7816_IsActiveFlag_TxParityError
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_TxParityError(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_TPARERR_Msk) == (U7816_ISR_TPARERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    TPARERR    LL_U7816_ClearFlag_TxParityError
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_ClearFlag_TxParityError(U7816_Type* U7816x)
{
    WRITE_REG(U7816x->ISR, U7816_ISR_TPARERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    RPARERR    LL_U7816_IsActiveFlag_RxParityError
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_RxParityError(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_RPARERR_Msk) == (U7816_ISR_RPARERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    RPARERR    LL_U7816_ClearFlag_RxParityError
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_ClearFlag_RxParityError(U7816_Type* U7816x)
{
    WRITE_REG(U7816x->ISR, U7816_ISR_RPARERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    FRERR    LL_U7816_IsActiveFlag_RxFreamError
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_RxFreamError(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_FRERR_Msk) == (U7816_ISR_FRERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    FRERR    LL_U7816_ClearFlag_RxFreamError
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_ClearFlag_RxFreamError(U7816_Type* U7816x)
{
    WRITE_REG(U7816x->ISR, U7816_ISR_FRERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    OVERR    LL_U7816_IsActiveFlag_RxOverFlow
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_RxOverFlow(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_OVERR_Msk) == (U7816_ISR_OVERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    OVERR    LL_U7816_ClearFlag_RxOverFlow
  * @param    U7816x U7816 instance
  * @retval   None
  */
__STATIC_INLINE void LL_U7816_ClearFlag_RxOverFlow(U7816_Type* U7816x)
{
    WRITE_REG(U7816x->ISR, U7816_ISR_OVERR_Msk);
}

/**
  * @brief    
  * @rmtoll   ISR    OVERR    LL_U7816_IsActiveFlag_Rx
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_Rx(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_OVERR_Msk) == (U7816_ISR_OVERR_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    RXIF    LL_U7816_IsActiveFlag_RxComplete
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_RxComplete(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_RXIF_Msk) == (U7816_ISR_RXIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    TXIF    LL_U7816_IsActiveFlag_TxBuffEmpty
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_TxBuffEmpty(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_TXIF_Msk) == (U7816_ISR_TXIF_Msk));
}

/**
  * @brief    
  * @rmtoll   ISR    ERRIF    LL_U7816_IsActiveFlag_Error
  * @param    U7816x U7816 instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_U7816_IsActiveFlag_Error(U7816_Type* U7816x)
{
    return (uint32_t)(READ_BIT(U7816x->ISR, U7816_ISR_ERRIF_Msk) == (U7816_ISR_ERRIF_Msk));
}

/**
  * @}
  */

/** @defgroup U7816_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_U7816_DeInit(U7816_Type *U7816x);
ErrorStatus LL_U7816_Init(U7816_Type *U7816x,LL_U7816_InitTypeDef *U7816_InitStruct);
void LL_U7816_StructInit(LL_U7816_InitTypeDef *U7816_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LC0XX_LL_U7816_H*/

/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-17**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
