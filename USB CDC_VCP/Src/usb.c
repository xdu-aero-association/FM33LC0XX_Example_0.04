#include "usb.h"
#include "user_init.h"
#include "usb_bsp.h"
#include "usb_dcd_int.h"
#include "usbd_desc.h"
#include "usbd_usr.h"
#include "cdc_core.h"
#include "cdc_vcp.h"

extern DataStream USBRxStream;
extern DataStream USBTxStream;

uint8_t dataBuff[256];
uint8_t dataLen;

void USBInit(void)
{
    LL_BSTIM_InitTypeDef BSTIM_InitStruct;
    
    // 初始化时钟：启用PLL，以64M主频运行
    LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_RCHF, LL_RCC_PLLSOURCE_DIV8, 
        64, LL_RCC_PLL_DIGITAL_DOMAIN_OUTPUT_MUL_1);
    LL_RCC_PLL_Enable();
    while (!LL_RCC_PLL_IsReady());
    
    LL_FLASH_SetLatency(FLASH, LL_FLASH_LATENCY_2);
    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);
    LL_RCC_SetSystemClockSource(LL_RCC_SYSTEM_CLKSOURCE_PLL);
    systemClock = 64000000;
    
    // 初始化BTIM定时器(定时周期: (64000000 / 2 / 32 * 1000) = 1ms)
    BSTIM_InitStruct.ClockSource = LL_RCC_BSTIM_OPERATION_CLK_SOURCE_APBCLK2;
    BSTIM_InitStruct.Prescaler = 32 - 1;
    BSTIM_InitStruct.Autoreload = 1000 -1;
    BSTIM_InitStruct.AutoreloadState = ENABLE;
    LL_BSTIM_Init(BSTIM, &BSTIM_InitStruct);
    
    LL_BSTIM_ClearFlag_UpdataEvent(BSTIM);
    LL_BSTIM_EnabledIT_UpdataEvent(BSTIM);
    
    NVIC_DisableIRQ(BSTIM_IRQn);
    NVIC_SetPriority(BSTIM_IRQn, 2);
    NVIC_EnableIRQ(BSTIM_IRQn);
    
    // USB初始化
    USBD_Init(&USB_OTG_dev, USB_OTG_FS_CORE_ID, 
        &USR_desc, &USBD_CDC_cb, &USR_cb);

    // 启动定时器
    LL_BSTIM_EnableCounter(BSTIM);
}

void BSTIM_IRQHandler(void)
{
//    uint32_t count;
    
    LL_BSTIM_ClearFlag_UpdataEvent(BSTIM);
  
//    dataLen = StreamGetDataSize(&USBRxStream);
//    if (dataLen != 0)
//    {
//        StreamReadData(&USBRxStream, dataBuff, dataLen);
//        
//        PRINT_ARRAY_NAME("Data");
//        for (count = 0; count < dataLen; count++)
//        {
//            PRINT_ARRAY_DATA("%02x ", dataBuff[count]);
//            dataBuff[count] |= 0x80;
//        }
//        PRINT_ARRAY_END();
//        
//        StreamWriteData(&USBTxStream, dataBuff, dataLen);
//    }
}

void USB_IRQHandler(void)
{
    USBD_OTG_ISR_Handler(&USB_OTG_dev);
}
