#include "usb.h"
#include "user_init.h"
#include "usb_bsp.h"
#include "usb_dcd_int.h"
#include "usbd_desc.h"
#include "usbd_usr.h"
#include "hid_core.h"

static uint8_t rBuffer[256];
static uint16_t rLength;

void USBInit(void)
{
    LL_BSTIM_InitTypeDef BSTIM_InitStruct = {0};
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    
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
    
    // GPIO初始化
    GPIO_InitStruct.Pin = LL_GPIO_PIN_9 | LL_GPIO_PIN_10;   // LED1 LED2
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_10;       // KEY1
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = ENABLE;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_12;       // KEY2
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_11;       // KEY3
    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_6;        // KEY4
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    
    // USB初始化
    USBD_Init(&USB_OTG_dev, USB_OTG_FS_CORE_ID, 
        &USR_desc, &USBD_HID_cb, &USR_cb);

    // 启动定时器
    LL_BSTIM_EnableCounter(BSTIM);
}

static uint8_t HID_Buffer[8];

static void USBD_HID_GetPos(void)
{
    // JOY_A
    if (!(LL_GPIO_ReadInputPort(GPIOA) & LL_GPIO_PIN_10))
    {
        DelayUs(10);
        if (!(LL_GPIO_ReadInputPort(GPIOA) & LL_GPIO_PIN_10))
        {
            HID_Buffer[2] = 0x04;   // A
        }
    }
    // JOY_B
    else if (!(LL_GPIO_ReadInputPort(GPIOB) & LL_GPIO_PIN_12))
    {
        DelayUs(10);
        if (!(LL_GPIO_ReadInputPort(GPIOB) & LL_GPIO_PIN_12))
        {
            HID_Buffer[3] = 0x05;   // B
        }
    }
    // JOY_C
    else if (!(LL_GPIO_ReadInputPort(GPIOD) & LL_GPIO_PIN_11))
    {
        DelayUs(10);
        if (!(LL_GPIO_ReadInputPort(GPIOD) & LL_GPIO_PIN_11))
        {
            HID_Buffer[4] = 0x06;   // C
        }
    }
    // JOY_CAP
    else if (!(LL_GPIO_ReadInputPort(GPIOC) & LL_GPIO_PIN_6))
    {
        DelayUs(10);
        if (!(LL_GPIO_ReadInputPort(GPIOC) & LL_GPIO_PIN_6))
        {
            HID_Buffer[5] = 0x39;   // shift
        }
    }
    else
    {
        HID_Buffer[2] = 0x00;
        HID_Buffer[3] = 0x00;
        HID_Buffer[4] = 0x00;
        HID_Buffer[5] = 0x00;
    }
}

void BSTIM_IRQHandler(void)
{
    static uint32_t counter = 0;
    static bool isSend = false;
    
    LL_BSTIM_ClearFlag_UpdataEvent(BSTIM);
  
    counter++;
    //每10ms检测一次数据状态
    if ((counter % USBD_HID_GetPollingInterval(&USB_OTG_dev)) == 0)
    {
        USBD_HID_GetPos();
        if ((HID_Buffer[5] != 0) || (HID_Buffer[4] != 0) || 
            (HID_Buffer != 0) || (HID_Buffer != 0))
        {
            // 如果按键有变动，则通过输入端点发送数据
            USBD_HID_SendReport(&USB_OTG_dev, HID_Buffer, 8);
            isSend = true;
        }
        else if (isSend == true)
        {
            // 按键弹起时发送一次报告
            isSend = false;
            USBD_HID_SendReport(&USB_OTG_dev, HID_Buffer, 8);
        }
        
        // 检测输入报告
        if (USBD_HID_RecvReport(&USB_OTG_dev, rBuffer, &rLength) == USBD_OK)
        {
            // NumsLock
            if (rBuffer[0] & 0x1)
            {
                LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_9);
            }
            else
            {
                LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_9);
            }
            
            // CapsLock
            if (rBuffer[0] & 0x2)
            {
                LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_10);
            }
            else
            {
                LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_10);
            }
        }
    }
}

void USB_IRQHandler(void)
{
    USBD_OTG_ISR_Handler(&USB_OTG_dev);
}
