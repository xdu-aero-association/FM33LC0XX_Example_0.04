/**
  ****************************************************************************************************
  * @file    fm33lc0xx_ll_aes.c
  * @author  FMSH Application Team
  * @brief   Src file of AES LL Module
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
#include "fm33lc0xx_ll_rcc.h"
#include "fm33lc0xx_ll_aes.h"
#include "fm33_assert.h"
/** @addtogroup FM33LC0xx_LL_Driver_AES
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup HDIV_LL_Private_Macros
  * @{
  */ 
#define         IS_LL_AES_INSTANCE(INSTANCE)                (((INSTANCE) == AES))
                                                             
#define         IS_LL_AES_KEYLENTH(__VALUE__)               (((__VALUE__) == LL_AES_KEY_LENTH_IS_128BITS)||\
                                                             ((__VALUE__) == LL_AES_KEY_LENTH_IS_192BITS)||\
                                                             ((__VALUE__) == LL_AES_KEY_LENTH_IS_256BITS))
                                                             
#define         IS_LL_AES_CIPHERMODE(__VALUE__)             (((__VALUE__) == LL_AES_CIPHER_ECB_MODE)||\
                                                             ((__VALUE__) == LL_AES_CIPHER_CBC_MODE)||\
                                                             ((__VALUE__) == LL_AES_CIPHER_CTR_MODE)||\
                                                             ((__VALUE__) == LL_AES_CIPHER_MULT_MODE))
                                                      
#define         IS_LL_AES_OPERATIONMODE(__VALUE__)          (((__VALUE__) == LL_AES_OPERATION_MODE_ENCRYPTION)||\
                                                             ((__VALUE__) == LL_AES_OPERATION_MODE_KEY_EXTENSION)||\
                                                             ((__VALUE__) == LL_AES_OPERATION_MODE_DECRYPT)||\
                                                             ((__VALUE__) == LL_AES_OPERATION_MODE_KEY_EXTENSION_AND_DECRYPT))
      
#define         IS_LL_AES_DATATYPE(__VALUE__)               (((__VALUE__) == LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED)||\
                                                             ((__VALUE__) == LL_AES_DATA_SWAP_RULE_HAIFWORD_EXCHANGE)||\
                                                             ((__VALUE__) == LL_AES_DATA_SWAP_RULE_BYTE_EXCHANGED)||\
                                                             ((__VALUE__) == LL_AES_DATA_SWAP_RULE_BIT_EXCHANGED))
/** 
  *@} 
  */

/** @addtogroup AES_LL_EF_Init
  * @{
  */
  
/**
  * @brief	复位AES 外设寄存器值为复位值
  * @param	外设入口地址
  * @retval	返回错误状态，可能值：
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_AES_DeInit(void)
{
    /* 外设复位使能 */
	LL_RCC_EnablePeripheralReset();
    
    /* 复位AES */
    LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_AES);
    LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_AES);
    /* 关闭总线时钟 */
    LL_RCC_Group2_DisableBusClock(LL_RCC_BUS2_CLOCK_AES);
    /* 锁定外设复位功能 */
    LL_RCC_DisablePeripheralReset();
    return PASS;
}
/**
  * @brief	根据 AES_InitStructer初始化对应外设入口地址的寄存器值.
  * @param	外设入口地址
  * @retval	返回错误状态，可能值：
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_AES_Init(AES_Type* AESx,LL_AES_InitTypeDef* AES_InitStructer)
{
    /* 入口合法性检查 */
    assert_param(IS_LL_AES_INSTANCE(AESx));
    assert_param(IS_LL_AES_KEYLENTH(AES_InitStructer->KeyLenth));         
    assert_param(IS_LL_AES_CIPHERMODE(AES_InitStructer->CipherMode));
    assert_param(IS_LL_AES_OPERATIONMODE(AES_InitStructer->OperationMode));         
    assert_param(IS_LL_AES_DATATYPE(AES_InitStructer->DataType));
    if(LL_AES_IsEnabled(AESx) == 0)
    {
        
        /* 开启总线时钟 */
        LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_AES);
        /* key长度 */
        LL_AES_SetBitLenthofKeys(AESx,AES_InitStructer->KeyLenth);
        /* 数据流处理模式 */
        LL_AES_SetCipherMode(AESx,AES_InitStructer->CipherMode);
        /* 操作模式 */
        LL_AES_SetOpertionMode(AESx,AES_InitStructer->OperationMode);
        /* 数据类型 */
        LL_AES_SetDataType(AESx,AES_InitStructer->DataType);
    }
    else
    {
        return FAIL;
    }
    
    
    return PASS;
}
/**
  * @brief	设置 AES_InitStruct 为默认配置
  * @param 	AES_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_AES_InitTypeDef 结构体  
  *         
  * @retval	None
  */
void LL_AES_StructInit(LL_AES_InitTypeDef* AES_InitStructer)
{
    AES_InitStructer->KeyLenth      = LL_AES_KEY_LENTH_IS_128BITS;

    AES_InitStructer->CipherMode    = LL_AES_CIPHER_ECB_MODE;

    AES_InitStructer->OperationMode = LL_AES_OPERATION_MODE_ENCRYPTION;

    AES_InitStructer->DataType      = LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED; 

}
/** 
  *@} 
  */
/** 
  *@} 
  */
/*********************** (C) COPYRIGHT Fudan Microelectronics *****END OF FILE************************/
