/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_u7816.c
  * @author  FMSH Application Team
  * @brief   Src file of U7816 LL Module
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
#include "fm33lc0xx_ll_rmu.h"
#include "fm33lc0xx_ll_u7816.h"
#include "fm33_assert.h"
/** @addtogroup FM33LC0xx_LL_Driver_U7816
  * @{
  */
/** @addtogroup Private_Macros
  * @{
  */
#define         IS_LL_U7816_INSTANCE(INTANCE)                       ((INTANCE) == U7816)

#define         IS_LL_U7816_CLOCK_FRQUENCE(__VALUE__)               (((__VALUE__) >=1000000)||\
                                                                     ((__VALUE__) <= 5000000))


#define         IS_LL_U7816_AUTO_RETRY(__VALUE__)                   (((__VALUE__) == LL_U7816_AUTO_RETRY_DISABLE)||\
                                                                     ((__VALUE__) == LL_U7816_AUTO_RETRY_ENABLE))

#define         IS_LL_U7816_RETRY_CNT(__VALUE__)                    (((__VALUE__) == LL_U7816_RETRY_CNT_X1)||\
                                                                     ((__VALUE__) == LL_U7816_RETRY_CNT_X3))
                                                                 
#define         IS_LL_U7816_BLOCKGUARD(__VALUE__)                   (((__VALUE__) == ENABLE)||\
                                                                     ((__VALUE__) == DISABLE))

#define         IS_LL_U7816_AUTO_PULL(__VALUE__)                   (((__VALUE__) == ENABLE)||\
                                                                    ((__VALUE__) == DISABLE))
                                                                    
#define         IS_LL_U7816_PARITH(__VALUE__)                       (((__VALUE__) == LL_U7816_PARITY_EVEN)||\
                                                                     ((__VALUE__) == LL_U7816_PARITY_ODD )||\
                                                                     ((__VALUE__) == LL_U7816_PARITY_ALWAYS_1)||\
                                                                     ((__VALUE__) == LL_U7816_PARITY_NONE))                                                                    
                                                                 
#define         IS_LL_U7816_TX_GUARD(__VALUE__)                     (((__VALUE__) == LL_U7816_GUARD_TIME_TX_X2_ETU)||\
                                                                     ((__VALUE__) == LL_U7816_GUARD_TIME_TX_X3_ETU))
                                                                 
#define         IS_LL_U7816_RX_GUARD(__VALUE__)                     (((__VALUE__) == LL_U7816_GUARD_TIME_TX_X2_ETU)||\
                                                                     ((__VALUE__) == LL_U7816_GUARD_TIME_RX_X1_ETU))                                                                 

#define         IS_LL_U7816_ERROR_GUARD(__VALUE__)                   (((__VALUE__) == LL_U7816_ERROR_GUARD_TIME_X2_ETU)||\
                                                                      ((__VALUE__) == LL_U7816_ERROR_GUARD_TIME_X1_ETU))

#define         IS_LL_U7816_ERROR_SIGNALTIME(__VALUE__)               (((__VALUE__) == LL_U7816_ERROR_SIGNAL_WIDTH_X2_ETU)||\
                                                                      ((__VALUE__) == LL_U7816_ERROR_SIGNAL_WIDTH_X1_5ETU)||\
                                                                      ((__VALUE__) == LL_U7816_ERROR_SIGNAL_WIDTH_X1_ETU))
                                                                 
                                                                 
#define         IS_LL_U7816_AUTO_ERROR_SIG(__VALUE__)                (((__VALUE__) == LL_U7816_AUTO_RESPOND_ERR_SIG_DISABLE)||\
                                                                      ((__VALUE__) == LL_U7816_AUTO_RESPOND_ERR_SIG_ENABLE))
                                                                 
#define         IS_LL_U7816_BIT_DIRECTION(__VALUE__)                (((__VALUE__) == LL_U7816_BIT_ORDER_FIRST_LSB)||\
                                                                     ((__VALUE__) == LL_U7816_BIT_ORDER_FIRST_MSB))                                                                 


/**
  * @}
  */
  
/** @addtogroup U7816_LL_EF_Init
  * @{
  */
  
/**
  * @brief  复位对应U7816寄存器.
  * @param  U7816x 
  * @retval ErrorStatus枚举值:
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_U7816_DeInit(U7816_Type *U7816x)
{
    
    assert_param(IS_LL_U7816_INSTANCE(U7816x));
    
    /* 使能外设复位 */
    LL_RCC_EnablePeripheralReset();
    /* 复位IIC外设寄存器 */
    LL_RCC_EnableResetAPB1Peripheral(LL_RCC_APB1_PERIPHERAL_RST_U7816);
    LL_RCC_DisableResetAPB1Peripheral(LL_RCC_APB1_PERIPHERAL_RST_U7816);
    /* 关闭外设总线始时钟和工作时钟 */
    LL_RCC_Group3_DisableBusClock(LL_RCC_BUS3_CLOCK_U7816);
    /* 锁定外设复位 */
    LL_RCC_DisablePeripheralReset();
    return PASS;
}
/**
  * @brief  根据 U7816_InitStruct 的配置信息初始化对应外设入口地址的寄存器值.
  * @param  U7816x U7816x 
  * @param  U7816_InitStruct 指向一个 @ref LL_U7816_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功  
  */
ErrorStatus LL_U7816_Init(U7816_Type *U7816x,LL_U7816_InitTypeDef *U7816_InitStruct)
{
    uint32_t Fclk;
    uint32_t tempClkdiv;
    /* 参数检查 */
    assert_param(IS_LL_U7816_INSTANCE(U7816x)); 
    assert_param(IS_LL_U7816_PARITH(U7816_InitStruct->Parity));
    assert_param(IS_LL_U7816_RETRY_CNT(U7816_InitStruct->RetryCnt));
    assert_param(IS_LL_U7816_AUTO_RETRY(U7816_InitStruct->TxAutoRetry));
    assert_param(IS_LL_U7816_AUTO_PULL(U7816_InitStruct->StrongPullUp));
    assert_param(IS_LL_U7816_TX_GUARD(U7816_InitStruct->TxGuardTime));
    assert_param(IS_LL_U7816_RX_GUARD(U7816_InitStruct->RxGuardTime));  
    assert_param(IS_LL_U7816_BLOCKGUARD(U7816_InitStruct->BlockGuard));    
    assert_param(IS_LL_U7816_ERROR_GUARD(U7816_InitStruct->ErrorGuardTime));                                                                                                                                                    
    assert_param(IS_LL_U7816_AUTO_ERROR_SIG(U7816_InitStruct->RxAutoErrorSignal));
    assert_param(IS_LL_U7816_BIT_DIRECTION(U7816_InitStruct->TransferOrder)); 
    assert_param(IS_LL_U7816_ERROR_SIGNALTIME(U7816_InitStruct->ErrorSignalTime));
    assert_param(IS_LL_U7816_CLOCK_FRQUENCE(U7816_InitStruct->OutputClockFreqence));                                                                            
    /* 时钟使能 */                                                          
    LL_RCC_Group3_EnableBusClock(LL_RCC_BUS3_CLOCK_U7816);
    /* 校验位 */
    LL_U7816_SetParity(U7816x,U7816_InitStruct->Parity);
    /* 发送失败重试次数 */
    LL_U7816_SetRetryCnt(U7816x,U7816_InitStruct->RetryCnt);
    /* 发送收到error signal 后自动重发 */
    LL_U7816_SetTxParityErrorAutoRetry(U7816x,U7816_InitStruct->TxAutoRetry);
    /* 发送一次之间的保护时间单位etu */
    LL_U7816_SetTxGuardTime(U7816x,U7816_InitStruct->TxGuardTime);
    /* 接收一次之间的保护时间单位etu */
    LL_U7816_SetRxGuardTime(U7816x,U7816_InitStruct->RxGuardTime);
    /* 错误之后的保护时间单位etu */
    LL_U7816_SetErrorGuardTime(U7816x,U7816_InitStruct->ErrorGuardTime);
    /* 额外保护时间单位etu */
    LL_U7816_SetExtraGuardTime(U7816x,U7816_InitStruct->ExtraGuardTime);
    /* 接收校验错是否自动回发error signal */
    LL_U7816_SetRxParityErrorAutoRespons(U7816x,U7816_InitStruct->RxAutoErrorSignal);
    /* 错误信号时间 单位etu */
    LL_U7816_SetErrorSignalWidth(U7816x,U7816_InitStruct->ErrorSignalTime);
    /* 传输bit方向 */
    LL_U7816_SetBitOrder(U7816x,U7816_InitStruct->TransferOrder);
    /* 卡时钟 */
    Fclk = LL_RCC_GetAPB1ClockFreq(LL_RCC_GetAHBClockFreq(LL_RCC_GetSystemClockFreq()));
    tempClkdiv = Fclk/U7816_InitStruct->OutputClockFreqence-1;
    LL_U7816_SetClockDivide(U7816x,tempClkdiv);
    /* baud */
    LL_U7816_SetBaudRate(U7816x,U7816_InitStruct->Baud);
    /* 强上拉*/
    if(U7816_InitStruct->StrongPullUp == ENABLE)
    {
        LL_U7816_SetPullUpEnable(U7816x);
    }
    else
    {
        LL_U7816_SetPullUpDisable(U7816x);
    }
    /* 块保护 */
    if(U7816_InitStruct->BlockGuard == ENABLE)
    {
        LL_U7816_EnableBlockGuardTime(U7816x);
    }
    else
    {
        LL_U7816_DisableBlockGuardTime(U7816x);
    }
    
    return PASS;
}
/**
  * @brief	设置 U7816_InitStruct 为默认配置
  * @param 	U7816_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_U7816_InitTypeDef 结构体  
  *         
  * @retval	None
  */

void LL_U7816_StructInit(LL_U7816_InitTypeDef *U7816_InitStruct)
{
    U7816_InitStruct->Baud                  = 372-1;
    U7816_InitStruct->BlockGuard            = DISABLE;
    U7816_InitStruct->StrongPullUp          = DISABLE;
    U7816_InitStruct->ErrorGuardTime        = LL_U7816_ERROR_GUARD_TIME_X1_ETU; 
    U7816_InitStruct->ErrorSignalTime       = LL_U7816_ERROR_SIGNAL_WIDTH_X2_ETU;
    U7816_InitStruct->ExtraGuardTime        = 0;
    U7816_InitStruct->OutputClockFreqence   = 100000;
    U7816_InitStruct->RxAutoErrorSignal     = LL_U7816_AUTO_RESPOND_ERR_SIG_ENABLE;   
    U7816_InitStruct->Parity                = LL_U7816_PARITY_EVEN;
    U7816_InitStruct->TxAutoRetry           = LL_U7816_AUTO_RETRY_ENABLE;
    U7816_InitStruct->RetryCnt              = LL_U7816_RETRY_CNT_X1;
    U7816_InitStruct->RxGuardTime           = LL_U7816_GUARD_TIME_RX_X2_ETU;
    U7816_InitStruct->TxGuardTime           = LL_U7816_GUARD_TIME_TX_X2_ETU;
    U7816_InitStruct->TransferOrder         = LL_U7816_BIT_ORDER_FIRST_LSB;
    
}
/**
  * @}
  */  
/**
  * @}
  */  
/**************************Py_Code_Generator Version: 0.1-0.5-0.1 @ 2019-10-17**************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
