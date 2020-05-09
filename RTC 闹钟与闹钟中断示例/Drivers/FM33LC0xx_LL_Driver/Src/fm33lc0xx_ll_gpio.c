/**
  ****************************************************************************************************
  * @file    fm33lC0xx_ll_gpio.c
  * @author  FMSH Application Team
  * @brief   Src file of GPIO LL Module
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
#include "fm33lc0xx_ll_gpio.h"
#include "fm33lc0xx_ll_rcc.h"
#include "fm33_assert.h"

/** @addtogroup FM33LC0XX_LL_Driver_GPIO
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup GPIO_LL_Private_Macros
  * @{
  */
  
#define         IS_GPIO_ALL_INSTANCE(INTENCE)              (((INTENCE) == GPIOA)||\
                                                            ((INTENCE) == GPIOB)||\
                                                            ((INTENCE) == GPIOC)||\
                                                            ((INTENCE) == GPIOD))
                                                            
#define         IS_LL_GPIO_PIN(__VALUE__)                  ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                            ((__VALUE__) <= (LL_GPIO_PIN_ALL)))                                                         
                                                             
#define         IS_LL_GPIO_MODE(__VALUE__)                  (((__VALUE__) == LL_GPIO_MODE_ANALOG)||\
                                                             ((__VALUE__) == LL_GPIO_MODE_INPUT)||\
                                                             ((__VALUE__) == LL_GPIO_MODE_OUTPUT)||\
                                                             ((__VALUE__) == LL_GPIO_MODE_DIGITAL))
                                                             
#define         IS_LL_GPIO_OPENDRAIN(__VALUE__)             (((__VALUE__) == LL_GPIO_OUTPUT_OPENDRAIN)||\
                                                             ((__VALUE__) == LL_GPIO_OUTPUT_PUSHPULL))
                                                      
#define         IS_LL_GPIO_PULL_UP(__VALUE__)               (((__VALUE__) == DISABLE)||\
                                                             ((__VALUE__) == ENABLE))
/**
  * @}
  */

/** @addtogroup GPIO_LL_EF_Init
  * @{
  */ 
  
/**
  * @brief  复位对应GPIO控制寄存器.
  * @param  GPIOx GPIO Port
  * @retval ErrorStatus枚举值:
  *       	-PASS 外设寄存器值恢复复位值
  *       	-FAIL 未成功执行
  */
ErrorStatus LL_GPIO_DeInit(GPIO_Type *GPIOx)
{
    /* 入口参数检查 */
    assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
    /* 恢复寄存器值为默认值 */
    GPIOx->INEN = 0x00000000U;
    GPIOx->PUEN = 0x00000000U;
    GPIOx->ODEN = 0x00000000U;
    GPIOx->FCR  = 0x00000000U;
    GPIOx->DRST = 0x00000000U;
    GPIOx->DSET = 0x00000000U;
    GPIOx->DFS  = 0x00000000U;
    GPIOx->ANEN = 0x00000000U;
    return PASS;
}

/**
  * @brief  根据 GPIO_InitStruct的配置信息初始化对应外设.
  * @param  GPIOx GPIO Port
  * @param  GPIO_InitStruct 指向一个 @ref LL_GPIO_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值	
  *			-FAIL 配置过程发生错误        
  *			-PASS LPUART配置成功  
  */
ErrorStatus LL_GPIO_Init(GPIO_Type *GPIOx, LL_GPIO_InitTypeDef *GPIO_InitStruct)
{
    uint32_t pinpos     = 0x00000000U;
    uint32_t currentpin = 0x00000000U;

    /* 入口参数检查 */
    assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
    assert_param(IS_LL_GPIO_PIN(GPIO_InitStruct->Pin));
    assert_param(IS_LL_GPIO_MODE(GPIO_InitStruct->Mode));
    assert_param(IS_LL_GPIO_OPENDRAIN(GPIO_InitStruct->OutputType));
    assert_param(IS_LL_GPIO_PULL_UP(GPIO_InitStruct->Pull));
    /* 使能时钟总线 */
    LL_RCC_Group1_EnableBusClock(LL_RCC_BUS1_CLOCK_GPIO);
    /* 这里考虑到PIN有可能不止一个因此需要遍历 */
    while (((GPIO_InitStruct->Pin) >> pinpos) != 0x00000000U)
    {
        /* 获取当前遍历到的Pin脚 */
        currentpin = (GPIO_InitStruct->Pin) & (0x00000001U << pinpos);

        if (currentpin)
        {
					  /* Pin脚输出模式设置 */
            if(GPIO_InitStruct->OutputType == LL_GPIO_OUTPUT_PUSHPULL)
            {
                LL_GPIO_DisablePinOpendrain(GPIOx,currentpin);
            }
            else
            {
                LL_GPIO_EnablePinOpendrain(GPIOx,currentpin);
            }
						
            /* Pin脚上拉模式设置 */
            if(GPIO_InitStruct->Pull)
            {
                LL_GPIO_EnablePinPullup(GPIOx, currentpin);
            }
            else
            {
                LL_GPIO_DisablePinPullup(GPIOx, currentpin);
            }

            /* Pin脚复用模式设置 */
            if (GPIO_InitStruct->Mode == LL_GPIO_MODE_ANALOG )
            {
                LL_GPIO_EnablePinAnalog(GPIOx,currentpin);
            }
            /*默认复用*/
            if (GPIO_InitStruct->Mode == LL_GPIO_MODE_DIGITAL)
            {
                /*重定向*/
                if(GPIO_InitStruct->RemapPin == ENABLE)
                {
                    LL_GPIO_EnablePinRemap(GPIOx,currentpin);
                }
            }
            /*输入*/
            if(GPIO_InitStruct->Mode == LL_GPIO_MODE_INPUT)
            {
                 LL_GPIO_EnablePinInput(GPIOx,currentpin);   
            }
			
			/* Pin脚工作模式设置 */
            LL_GPIO_SetPinMode(GPIOx, currentpin, GPIO_InitStruct->Mode);
        }
        pinpos++;
    }
    return PASS;
}
/**
  * @brief	设置 GPIO_InitStruct 为默认配置
  * @param 	GPIO_InitStruct 指向需要将值设置为默认配置的结构体 @ref LL_GPIO_InitTypeDef 结构体  
  *         
  * @retval	None
  */

void LL_GPIO_StructInit(LL_GPIO_InitTypeDef *GPIO_InitStruct)
{
  /* 复位配置信息 */
  GPIO_InitStruct->Pin        = LL_GPIO_PIN_ALL;
  GPIO_InitStruct->Mode       = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct->OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
  GPIO_InitStruct->Pull       = DISABLE;
  GPIO_InitStruct->RemapPin   = DISABLE;
}
/**
  * @brief  设置所有GPIO为开漏输出高，注意此函数默认在系统初始化开始处调用
  *         从而不影响后续配置管脚功能
  * @note   PD8和PD9为调试接口
  *
  * @param  None 
  *         
  * @retval	None
  */
void LL_GPIO_ALLPIN_LPM_MODE(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  LL_GPIO_StructInit(&GPIO_InitStruct);

  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;

  LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_ALL);
  LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_ALL);
  LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_ALL);
  LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_ALL_EXCEPTSWD);
	
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* SWD ON */
  GPIO_InitStruct.Pin  = LL_GPIO_PIN_7|LL_GPIO_PIN_8;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
  GPIO_InitStruct.Pull = ENABLE;
  LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}
/**
  * @}
  */

/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/
