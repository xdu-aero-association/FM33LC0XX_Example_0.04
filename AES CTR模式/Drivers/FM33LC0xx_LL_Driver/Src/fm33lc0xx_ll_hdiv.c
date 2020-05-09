/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_hdiv.c
  * @author  FMSH Application Team
  * @brief   Src file of HDIV LL Module
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
#include "fm33lc0xx_ll_hdiv.h"
#include "fm33lc0xx_ll_rcc.h"
#include "fm33_assert.h"

/** @addtogroup FM33LC0xx_LL_Driver_HDIV
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup HDIV_LL_Private_Macros
  * @{
  */  
#define         IS_HDIV_ALL_INSTANCE(INTENCE)              ((INTENCE) == HDIV)
                                                            
#define         IS_LL_HDIV_DIVISOR(__VALUE__)              (((__VALUE__) != 0))
    
/**
  * @}
  */

/** @addtogroup HDIV_LL_EF_Init
  * @{
  */ 
  
/**
  * @brief  复位对应HDIV控制寄存器.
  * @param  HDIVx HDIV Port
  * @retval ErrorStatus枚举值:
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_HDIV_DeInit(HDIV_Type *HDIVx)
{
    /* 入口参数检查 */
    assert_param(IS_HDIV_ALL_INSTANCE(HDIVx));
    /* 外设复位使能 */
	LL_RCC_EnablePeripheralReset();
    /* 恢复寄存器值为默认值 */
    LL_RCC_EnableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_HDV);
    LL_RCC_DisableResetAPB2Peripheral(LL_RCC_APB2_PERIPHERAL_RST_HDV);
    
    /* 锁定外设复位功能 */
    LL_RCC_DisablePeripheralReset();
    
    return PASS;
}

/**
  * @brief  根据 初始化对应外设HDIV.
  *
  * @param  HDIVx HDIV Port
  *        
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功  
  */
ErrorStatus LL_HDIV_Init(HDIV_Type *HDIVx)
{
  
    /* 入口参数检查 */
    assert_param(IS_HDIV_ALL_INSTANCE(HDIVx));
    /* 使能时钟总线 */
    LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_HDIV);  
    return PASS;
}
/**
  * @brief 硬件触发器计算函数	
  *
  * @param 	HDIVx HDIV Port 
  *
  * @param 	32位有符号被除数
  *
  * @param 	32位有符号除数，注意不能为0
  *
  * @param 	保存商的地址
  *
  * @param 	保存余数的地址
  *         
  * @retval	返回非0 表示计算出错
  */
uint32_t LL_HDIV_Calculation(HDIV_Type *HDIVx,int32_t DivisorEnd,int16_t Divisor,int32_t* Quotient, int16_t* Residue)
{
    uint32_t  TimeOut ;
    
    LL_HDIV_SetDivisorEnd(HDIVx,DivisorEnd);
    LL_HDIV_SetDivisor(HDIVx,Divisor);
    
    if(LL_HDIV_IsActiveDividedZero(HDIVx))
    {
        /*除数为0 */
        *Quotient = 0;
        *Residue  = 0;
        return 1;
        
    }
    TimeOut = LL_HDIV_SR_BUSY_TIMEOUT;
    while(LL_HDIV_IsActiveBusy(HDIVx))
    {
        TimeOut --;
        if(TimeOut<=0)
        {
            /* 计算超时*/
            *Quotient = 0;
            *Residue  = 0;
            return 3;
        }
            
    }
    *Quotient = LL_HDIV_GetQuotient(HDIVx);
    *Residue  = LL_HDIV_GetResidue(HDIVx);
    return 0;
}

/**
  * @}
  */

/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/


