/**
  ****************************************************************************************************
  * @file    fm33lC0xx_ll_flash.c
  * @author  FMSH Application Team
  * @brief   Src file of FLASH LL Module
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
#include "fm33lc0xx_ll_flash.h"
#include "fm33lc0xx_ll_rcc.h"
#include "fm33_assert.h"

/** @addtogroup FM33LC0XX_LL_Driver_FLASH
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup GPIO_LL_Private_Macros
  * @{
  */
  
#define         IS_FLASH_ALL_INSTANCE(INTENCE)              (((INTENCE) == FLASH))
                                                            
#define         IS_LL_FLASH_PAGE_NUM(__VALUE__)              ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (LL_FLASH_MAX_PAGE_NUM)))

#define         IS_LL_FLASH_SECTOR_NUM(__VALUE__)              ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (LL_FLASH_MAX_SECTOR_NUM)))
                                                             
#define         IS_LL_FLASH_MAX_ADDR(__VALUE__)              ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (LL_FLASH_ADDR_MAXPROGRAM)))

#define         IS_LL_FLASH_MAX_PAGE(__VALUE__)              ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (LL_FLASH_MAX_PAGE_NUM)))
                                                             
#define         IS_LL_FLASH_MAX_SECTOR(__VALUE__)           ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (LL_FLASH_MAX_SECTOR_NUM)))                                                             
/**
  * @}
  */
  
/** @addtogroup HDIV_LL_OPERATE_API
  * @{
  */
  
/**
  * @brief  Flash 页擦除函数，一个页为512byte.
  * @param  FLASHx FLASH Port
  * @param  Address 为需要擦除的页内任意地址，推荐使用页开始的首地址（字对齐）
  *         .
  * @retval ErrorStatus枚举值
  *         -FAIL 擦写发生错误        
  *         -PASS 擦写成功  
  */  
ErrorStatus LL_FLASH_PageErase(FLASH_Type* FLASHx, uint32_t Address)
{
    uint32_t        Timeout = 0;
    uint32_t        Primask;
    ErrorStatus     ret = PASS;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_LL_FLASH_MAX_ADDR((uint32_t)Address));

    /*时钟使能*/
    LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_FLASH);
    if(Address & (LL_FLASH_ADDRS_ALIGN-1))
    {
        /*地址未对齐*/
        return FAIL;
    }
    if(LL_FLASH_GetFlashLockStatus(FLASHx) == LL_FLASH_FLASH_KEY_STATUS_ERROR)
    {
        /*Flash 已经锁定，复位前无法操作*/
        return FAIL;
    }
    LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    /*配置擦写类型*/
    LL_FLASH_SetFlashEraseType(FLASHx,LL_FLASH_FLASH_ERTYPE_PAGE);
    /* 开始擦除页*/
    LL_FLASH_StartErase(FLASHx);

    if(LL_FLASH_GetFlashLockStatus(FLASHx) != LL_FLASH_FLASH_KEY_STATUS_SECTOR_ERASE)
    {/* Key 序列*/
        Primask = __get_PRIMASK();
        __disable_irq();
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_ERASE_KEY);
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_PGAE_ERASE_KEY);
        __set_PRIMASK(Primask);
    }
    LL_FLASH_ClearFlag_EraseFinish(FLASHx);
    /* 擦请求 */
    *((uint32_t*)Address) =  LL_FLASH_ERASE_REQUEST;
    while(1)
    {
        Timeout++;
        if((Timeout > LL_FLASH_ERASE_TIMEOUT)\
           ||(LL_FLASH_IsActiveFlag_ClockError(FLASHx))\
           ||(LL_FLASH_IsActiveFlag_KEYError(FLASHx))\
           ||(LL_FLASH_IsActiveFlag_AuthenticationError(FLASHx)))
        {
            /* 超时或出现错误 */
            ret = FAIL;
            break;
        }
        else if(LL_FLASH_IsActiveFlag_EraseFinish(FLASHx))
        {
            /*编程成功*/
            LL_FLASH_ClearFlag_EraseFinish(FLASHx);
            ret =  PASS;
            break;
        }
    }
    LL_FLASH_LockFlash(FLASHx);
    LL_RCC_Group2_DisableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    return ret;
}

/**
  * @brief  Flash 扇区擦除函数，一个扇区为2k byte.
  * @param  FLASHx FLASH Port
  * @param  Address 为需要擦除的扇区内任意地址，推荐使用扇区开始的首地址（字对齐）
  *         .
  * @retval ErrorStatus枚举值
  *         -FAIL 擦写发生错误        
  *         -PASS 擦写成功  
  */   
ErrorStatus LL_FLASH_SectorErase(FLASH_Type* FLASHx, uint32_t Address)
{
    uint32_t    Timeout = 0;
    uint32_t    Primask;
    ErrorStatus    ret = PASS;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_LL_FLASH_MAX_ADDR((uint32_t)Address));
    /*时钟使能*/
    LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_FLASH);
    if(Address & (LL_FLASH_ADDRS_ALIGN-1))
    {
        /*地址未对齐*/
        return FAIL;
    }
    if(LL_FLASH_GetFlashLockStatus(FLASHx) == LL_FLASH_FLASH_KEY_STATUS_ERROR)
    {
        /*Flash 已经锁定，复位前无法操作*/
        return FAIL;
    }
    LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    /*配置擦写类型*/
    LL_FLASH_SetFlashEraseType(FLASHx,LL_FLASH_FLASH_ERTYPE_SECTOR);
    /* 开始擦除扇区*/
    LL_FLASH_StartErase(FLASHx);
    
    if(LL_FLASH_GetFlashLockStatus(FLASHx) != LL_FLASH_FLASH_KEY_STATUS_SECTOR_ERASE)
    {/* Key 序列*/
        Primask = __get_PRIMASK();
        __disable_irq();
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_ERASE_KEY);
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_SECTOR_ERASE_KEY);
        __set_PRIMASK(Primask);
    }
    LL_FLASH_ClearFlag_EraseFinish(FLASHx);
    /* 擦请求 */
    *((uint32_t*)Address) =  LL_FLASH_ERASE_REQUEST;
    while(1)
    {
        Timeout++;
        if((Timeout > LL_FLASH_ERASE_TIMEOUT)\
           ||(LL_FLASH_IsActiveFlag_ClockError(FLASHx))\
           ||(LL_FLASH_IsActiveFlag_KEYError(FLASHx))\
           ||(LL_FLASH_IsActiveFlag_AuthenticationError(FLASHx)))
        {
            /* 超时或出现错误 */
            ret = FAIL;
            break;
        }
        else if(LL_FLASH_IsActiveFlag_EraseFinish(FLASHx))
        {
            /*编程成功*/
            LL_FLASH_ClearFlag_EraseFinish(FLASHx);
            ret =  PASS;
            break;
        }
    }
    LL_FLASH_LockFlash(FLASHx);
    LL_RCC_Group2_DisableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    return ret;
}

/**
  * @brief  单次编程函数，编程地址必须对齐到字边界.
  * @param  FLASHx FLASH Port
  * @param  Address 为需要编程的已经擦除过的扇区内任意地址，非对齐地址编程将触发fault。
  *         
  * @retval ErrorStatus枚举值
  *         -FAIL 擦写发生错误        
  *         -PASS 擦写成功  
  */ 
ErrorStatus LL_FLASH_Program_Word(FLASH_Type* FLASHx, uint32_t Address, uint32_t data)
{
    uint32_t    Timeout = 0;
    uint32_t    Primask;
    ErrorStatus  ret = PASS;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_LL_FLASH_MAX_ADDR((uint32_t)Address));
    /*时钟使能*/
    LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_FLASH);
    if(Address & (LL_FLASH_ADDRS_ALIGN-1))
    {
        /*地址未对齐*/
        return FAIL;
    }
    if(LL_FLASH_GetFlashLockStatus(FLASHx) == LL_FLASH_FLASH_KEY_STATUS_ERROR)
    {
        /*Flash 已经锁定，复位前无法操作*/
        return FAIL;
    }
    LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    /* 开始编程*/
    LL_FLASH_StartProgram(FLASHx);
    if(LL_FLASH_GetFlashLockStatus(FLASHx) != LL_FLASH_FLASH_KEY_STATUS_PROGRAM)
    {/* Key 序列*/
        Primask = __get_PRIMASK();
        __disable_irq();
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_PROGRAM_KEY1);
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_PROGRAM_KEY2);
        __set_PRIMASK(Primask);
    }
    *((uint32_t*)Address) =  data;
    while(1)
    {
        Timeout++;
        if((Timeout > LL_FLASH_ERASE_TIMEOUT)\
           ||(LL_FLASH_IsActiveFlag_ClockError(FLASHx))\
           ||(LL_FLASH_IsActiveFlag_KEYError(FLASHx))\
           ||(LL_FLASH_IsActiveFlag_AuthenticationError(FLASHx)))
        {
            /* 超时或出现错误 */
            ret = FAIL;
            break;
        }
        else if(LL_FLASH_IsActiveFlag_ProgramFinish(FLASHx))
        {
            /*编程成功*/  
            LL_FLASH_ClearFlag_ProgramFinish(FLASHx);
            ret = PASS;
            break;
        }
    }
    LL_FLASH_LockFlash(FLASHx);
    LL_RCC_Group2_DisableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    return ret;
}

/**
  * @brief  页编程函数，编程地址必须对齐到字边界.
  * @param  FLASHx FLASH Port
  * @param  PageNum 为需要编程的已经擦除过的扇区号，FM33LC04最大为256，非对齐地址编程将触发fault。
  *         
  * @retval ErrorStatus枚举值
  *         -FAIL 擦写发生错误        
  *         -PASS 擦写成功  
  */ 
ErrorStatus LL_FLASH_Program_Page(FLASH_Type* FLASHx, uint32_t PageNum, uint32_t *data)
{
    uint32_t     Cnt;
    uint32_t     Primask;
    uint32_t     Address;
    uint32_t     Timeout;
    ErrorStatus  ret; 
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_LL_FLASH_MAX_PAGE((uint32_t)PageNum));
    Address      = PageNum*LL_FLASH_PGAE_SIZE_BYTE;
    /* 页对齐*/
    if(Address & (LL_FLASH_PGAE_SIZE_BYTE-1))
    {
        /*地址未对齐*/
        return FAIL;
    }
    LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_FLASH);
    LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    LL_FLASH_StartProgram(FLASHx);
    if(LL_FLASH_GetFlashLockStatus(FLASHx) != LL_FLASH_FLASH_KEY_STATUS_PROGRAM)
    {/* Key 序列*/
        Primask = __get_PRIMASK();
        __disable_irq();
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_PROGRAM_KEY1);
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_PROGRAM_KEY2);
        __set_PRIMASK(Primask);
    }
    for(Cnt = 0;Cnt< LL_FLASH_PGAE_SIZE_BYTE;Cnt+=4)
    {
        Timeout = 0;
        LL_FLASH_StartProgram(FLASHx);
        *((uint32_t*)Address) =  *(data++);
        Address+=4;
        while(1)
        {
            Timeout++;
            if((Timeout > LL_FLASH_ERASE_TIMEOUT)\
               ||(LL_FLASH_IsActiveFlag_ClockError(FLASHx))\
               ||(LL_FLASH_IsActiveFlag_KEYError(FLASHx))\
               ||(LL_FLASH_IsActiveFlag_AuthenticationError(FLASHx)))
            {
                /* 超时或出现错误 */
                ret = FAIL;
                break;
            }
            if(LL_FLASH_IsActiveFlag_ProgramFinish(FLASHx))
            {
                /*编程成功*/  
                LL_FLASH_ClearFlag_ProgramFinish(FLASHx);
                ret = PASS;
                break;
            }
        }        
    }
    LL_FLASH_LockFlash(FLASHx);
    LL_RCC_Group2_DisableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    return ret;
}

/**
  * @brief  扇区编程函数，编程地址必须对齐到字边界.
  * @param  FLASHx FLASH Port
  * @param  SectorNum 为需要编程的已经擦除过的扇区号，FM33LC04最大为128，非对齐地址编程将触发fault。
  *         
  * @retval ErrorStatus枚举值
  *         -FAIL 擦写发生错误        
  *         -PASS 擦写成功  
  */ 
ErrorStatus LL_FLASH_Program_Sector(FLASH_Type* FLASHx, uint32_t SectorNum, uint32_t *data)
{
    uint32_t     Cnt;
    uint32_t     Primask;
    uint32_t     Address;
    uint32_t     Timeout;
    ErrorStatus  ret; 
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_LL_FLASH_MAX_SECTOR((uint32_t)SectorNum));
    Address      = SectorNum*LL_FLASH_SECTOR_SIZE_BYTE;
    /* 页对齐*/
    if(Address & (LL_FLASH_SECTOR_SIZE_BYTE-1))
    {
        /*地址未对齐*/
        return FAIL;
    }
    LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_FLASH);
    LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    LL_FLASH_StartProgram(FLASHx);
    if(LL_FLASH_GetFlashLockStatus(FLASHx) != LL_FLASH_FLASH_KEY_STATUS_PROGRAM)
    {/* Key 序列*/
        Primask = __get_PRIMASK();
        __disable_irq();
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_PROGRAM_KEY1);
        LL_FLASH_UnlockFlash(FLASHx,LL_FLASH_PROGRAM_KEY2);
        __set_PRIMASK(Primask);
    }
    for(Cnt = 0;Cnt< LL_FLASH_SECTOR_SIZE_BYTE;Cnt+=4)
    {
        Timeout = 0;
        LL_FLASH_StartProgram(FLASHx);
        *((uint32_t*)Address) =  *(data++);
        Address+=4;
        while(1)
        {
            Timeout++;
            if((Timeout > LL_FLASH_ERASE_TIMEOUT)\
               ||(LL_FLASH_IsActiveFlag_ClockError(FLASHx))\
               ||(LL_FLASH_IsActiveFlag_KEYError(FLASHx))\
               ||(LL_FLASH_IsActiveFlag_AuthenticationError(FLASHx)))
            {
                /* 超时或出现错误 */
                ret = FAIL;
                break;
            }
            if(LL_FLASH_IsActiveFlag_ProgramFinish(FLASHx))
            {
                /*编程成功*/  
                LL_FLASH_ClearFlag_ProgramFinish(FLASHx);
                ret = PASS;
                break;
            }
        }        
    }
    LL_FLASH_LockFlash(FLASHx);
    LL_RCC_Group2_DisableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    return ret;
}

/**
  * @}
  */
/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/









