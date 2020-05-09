/**
  *******************************************************************************************************
  * @file    fm33lc0xx_ll_I2C.c
  * @author  FMSH Application Team
  * @brief   Src file of I2C LL Module
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
#include "fm33lc0xx_ll_i2c.h"
#include "fm33_assert.h"

/** @addtogroup FM33LC0xx_LL_Driver_I2C
  * @{
  */
   
/** @addtogroup Private_Macros
  * @{
  */
#define         IS_LL_I2C_INSTANCE(INTANCE)                     ((INTANCE) == I2C)

#define         IS_LL_I2C_BAUDRATE(__VALUE__)                   (((__VALUE__) > 0 )&&((__VALUE__) <= 1000000))

#define         IS_LL_I2C_CLOCKSRC(__VALUE__)                   (((__VALUE__) == LL_RCC_I2C_OPERATION_CLOCK_SOURCE_APBCLK1)||\
                                                                 ((__VALUE__) == LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RCHF)||\
                                                                 ((__VALUE__) == LL_RCC_I2C_OPERATION_CLOCK_SOURCE_SYSCLK)||\
                                                                 ((__VALUE__) == LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RC4M_PSC))

#define         IS_LL_I2C_MSATER_TIMEOUT(__VALUE__)             (((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_125MS)||\
                                                                 ((__VALUE__) == LL_IWDT_IWDT_OVERFLOW_PERIOD_16000MS))
                                                                 
                                                                 
#define         IS_LL_I2C_SLAVE__ACK(__VALUE__)                 (((__VALUE__) == ENABLE)||\
                                                                 ((__VALUE__) == DISABLE))
                                                                 
                                                                 
                                                                 
#define         IS_LL_I2C_ANGLOGFILTER(__VALUE__)               (((__VALUE__) == ENABLE)||\
                                                                 ((__VALUE__) == DISABLE)) 

#define         IS_LL_I2C_ADDRSIZE10BIT(__VALUE__)              (((__VALUE__) == ENABLE)||\
                                                                 ((__VALUE__) == DISABLE))
                                                                 
/**
  * @}
  */
  
/** @addtogroup I2C_LL_EF_Init
  * @{
  */ 
  
/**
  * @brief  复位对应I2C寄存器.
  * @param  I2Cx 
  * @retval ErrorStatus枚举值:
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_I2C_DeInit(I2C_Type *I2Cx)
{
    assert_param(IS_LL_I2C_INSTANCE(I2Cx));
    
    /* 使能外设复位 */
    LL_RCC_EnablePeripheralReset();
    /* 复位I2C外设寄存器 */
    LL_RCC_EnableResetAPB1Peripheral(LL_RCC_APB1_PERIPHERAL_RST_I2C);
    LL_RCC_DisableResetAPB1Peripheral(LL_RCC_APB1_PERIPHERAL_RST_I2C);
    /* 关闭外设总线始时钟和工作时钟 */
    LL_RCC_Group3_DisableBusClock(LL_RCC_BUS3_CLOCK_I2C);
    LL_RCC_Group1_DisableOperationClock(LL_RCC_OPERATION1_CLOCK_I2C);
    /* 锁定外设复位 */
    LL_RCC_DisablePeripheralReset();
    return PASS;
}

/**
  * @brief  根据 I2C_InitStruct 的配置信息初始化对应外设入口地址的寄存器值.
  * @param  I2cx I2cx 
  * @param  I2C_InitStruct 指向一个 @ref LL_I2C_MasterMode_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功  
  */
ErrorStatus LL_I2C_MasterMode_Init(I2C_Type *I2Cx, LL_I2C_MasterMode_InitTypeDef *I2C_InitStruct)
{
    uint32_t I2C_Clk_Freq,BRG;
    
    assert_param(IS_LL_I2C_INSTANCE(I2Cx));
    assert_param(IS_LL_I2C_CLOCKSRC(I2C_InitStruct->ClockSource));
    assert_param(IS_LL_I2C_BAUDRATE(I2C_InitStruct->BaudRate));
    /* 外设总线时钟和工作时钟开启 */
    LL_RCC_Group3_EnableBusClock(LL_RCC_BUS3_CLOCK_I2C);
    LL_RCC_Group1_EnableOperationClock(LL_RCC_OPERATION1_CLOCK_I2C);
    /* 选择I2C工作时钟源 */
    LL_RCC_SetI2CClockSource(I2C_InitStruct->ClockSource);
    /* 获取时钟源速度 */
    switch(I2C_InitStruct->ClockSource)
    {
          
        case LL_RCC_I2C_OPERATION_CLOCK_SOURCE_APBCLK1:
            I2C_Clk_Freq = LL_RCC_GetAPB1ClockFreq(LL_RCC_GetAHBClockFreq(LL_RCC_GetSystemClockFreq()));
            break;
        case LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RCHF:
            I2C_Clk_Freq = LL_RCC_GetRCHFClockFreq();
            break;
        case LL_RCC_I2C_OPERATION_CLOCK_SOURCE_SYSCLK:
            I2C_Clk_Freq = LL_RCC_GetSystemClockFreq();
            break;
        case LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RC4M_PSC:
            I2C_Clk_Freq = LL_RCC_GetRC4MClockFreq();
            break;
        default:break;
    }
    /* 根据不同的时钟源速度计算出配置速率需要的寄存器值并配置相关寄存器 */
    BRG = (uint32_t)(I2C_Clk_Freq/(2*I2C_InitStruct->BaudRate)) -1;
    LL_I2C_MasterMode_Set_SCL_HighWidth(I2Cx,BRG);
    LL_I2C_MasterMode_Set_SCL_LowWidth(I2Cx,BRG);
		
	LL_I2C_MasterMode_Set_SDA_HoldTime(I2Cx,(uint32_t)(BRG/2.0+0.5));
    /* 使能外设 */
    LL_I2C_MasterMode_Enable(I2C);
    
    return PASS;
}



/**
  * @brief	设置 I2C_InitStruct 为默认配置
  * @param 	I2C_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_I2C_MasterMode_InitTypeDef 结构体  
  *         
  * @retval	None
  */

void LL_I2C_MasterMode_StructInit(LL_I2C_MasterMode_InitTypeDef *I2C_InitStruct)
{
    I2C_InitStruct->ClockSource = LL_RCC_I2C_OPERATION_CLOCK_SOURCE_RCHF;
    I2C_InitStruct->BaudRate = 40000;
}

/**
  * @brief  根据 I2C_InitStruct 的配置信息初始化对应外设入口地址的寄存器值.
  * @param  I2cx I2cx
  * @param  I2C_InitStruct 指向一个 @ref LL_I2C_SlaveMode_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @note   作为从机时的丛机地址应参考手册推荐具体设置。  
  *         
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功  
  */
ErrorStatus LL_I2C_SlaveMode_Init(I2C_Type *I2Cx, LL_I2C_SlaveMode_InitTypeDef *I2C_InitStruct)
{
    assert_param(IS_LL_I2C_INSTANCE(I2Cx));
    assert_param(IS_LL_I2C_SLAVE__ACK(I2C_InitStruct->ACK));
    assert_param(IS_LL_I2C_ADDRSIZE10BIT(I2C_InitStruct->OwnAddrSize10bit));
    /* 外设总线时钟开启 注：不需要工作时钟*/
    LL_RCC_Group3_EnableBusClock(LL_RCC_BUS3_CLOCK_I2C);
    /* 使能SDA输出延迟 注：推荐开启*/
    LL_I2C_SlaveMode_Enable_SDAStretching(I2Cx);
    /* 使能SCL模拟滤波使能 注：推荐开启*/
    LL_I2C_SlaveMode_Enable_SCLAnalogFilter(I2Cx);
    /* 从机ACK */
    if(I2C_InitStruct->ACK == ENABLE)
    {
        LL_I2C_SlaveMode_Enable_ACK_Respond(I2Cx);
    }
    else
    {
        LL_I2C_SlaveMode_Disable_ACK_Respond(I2Cx);
    }
    /* 从机地址宽度  和地址配置 */
    if(I2C_InitStruct->OwnAddrSize10bit == ENABLE)
    {
        LL_I2C_SlaveMode_Enable_ADDR10Bit(I2Cx);
        LL_I2C_SlaveMode_Set_SlaveAddr(I2Cx,I2C_InitStruct->OwnAddr);
    }
    else
    {
        LL_I2C_SlaveMode_Disable_ADDR10Bit(I2Cx);
        LL_I2C_SlaveMode_Set_SlaveAddr(I2Cx,I2C_InitStruct->OwnAddr&0x7F);
    } 
    /* 外设开启 */
    LL_I2C_SlaveMode_Enable(I2Cx); 
    return PASS;
}

/**
  * @brief	设置 I2C_InitStruct 为默认配置
  * @param 	I2C_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_I2C_SlaveMode_InitTypeDef 结构体  
  *         
  * @retval	None
  */

void LL_I2C_SlaveMode_StructInit(LL_I2C_SlaveMode_InitTypeDef *I2C_InitStruct)
{
    I2C_InitStruct->ACK                 = ENABLE;
    I2C_InitStruct->OwnAddr             = 0x55;
    I2C_InitStruct->OwnAddrSize10bit    = DISABLE;
}
/**
  * @}
  */
  
  /**
  * @}
  */
  
  


