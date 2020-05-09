#include "usb_bsp.h"
#include "usbd_conf.h"
#include "hid_core.h"

// USB板级初始化文件
#include <string.h>
#include "user_init.h"

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN USB_OTG_CORE_HANDLE USB_OTG_dev __ALIGN_END;

// USB初始化
static void USB_Clock_Init(void)
{
    RCC->PCLKCR1 |= 0x1 << 1;   // 开启USB总线时钟
    
    RCC->PHYCR |= 0x1 << 2;     // VDD15标志已建立
    
    RCC->PHYCR |= 0x1 << 4;     // USB PHY模块复位释放
    RCC->PHYCR |= 0x1 << 0;     // USB BCK模块复位释放
    
    RCC->PHYCR &= ~(0x1 << 3);  // USB PHY工作
    RCC->PHYCR &= ~(0x1 << 1);  // USB BCK工作
    
    RCC->PHYBCKCR |= 0x1 << 8;  // PHY输出48M使能
    
    DelayMs(1000);
}

// USB去初始化
static void USB_Clock_DeInit(void)
{
    RCC->PHYBCKCR &= ~(0x1 << 8);   // PHY关闭48M输出
    
    RCC->PHYCR |= 0x1 << 1;     // 关闭USB BCK
    RCC->PHYCR |= 0x1 << 3;     // 关闭USB PHY
    RCC->PHYCR &= ~(0x1 << 0);  // USB BCK模块复位
    RCC->PHYCR &= ~(0x1 << 4);  // USB PHY模块复位
    
    RCC->PHYCR &= ~(0x1 << 2);  // VDD15建立标志清除
    
    RCC->PCLKCR1 &= ~(0x1 << 1);// 关闭USB总线时钟
}

// USB软件连接
static void USB_Soft_Connect(USB_OTG_CORE_HANDLE *pdev)
{
	USB_OTG_DCTL_TypeDef     dctl;
	
	dctl.d32 = USB_OTG_READ_REG32(&pdev->regs.DREGS->DCTL);
	dctl.b.sftdiscon = 0;
	USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DCTL, dctl.d32);
}

// USB软件断开
static void USB_Soft_Disconnect(USB_OTG_CORE_HANDLE *pdev)
{
	USB_OTG_DCTL_TypeDef     dctl;
	
	dctl.d32 = USB_OTG_READ_REG32(&pdev->regs.DREGS->DCTL);
	dctl.b.sftdiscon = 1;
	USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DCTL, dctl.d32);
}

// 初始化USB(GPIO及时钟)
void USB_OTG_BSP_Init(USB_OTG_CORE_HANDLE * pdev)
{
    USB_Clock_Init();
	
	// Init FIFO Debug Read/Write Region
    memset((uint32_t*)0x50020000, 0x400, 0x00);
}

// 初始化USB(GPIO及时钟)
void USB_OTG_BSP_DeInit(USB_OTG_CORE_HANDLE * pdev)
{
    USB_Clock_DeInit();
}

// 使能USB全局中断
void USB_OTG_BSP_EnableInterrupt(USB_OTG_CORE_HANDLE * pdev)
{
	NVIC_ClearPendingIRQ(USB_IRQn);
	NVIC_DisableIRQ(USB_IRQn);
	NVIC_SetPriority(USB_IRQn,2);
	NVIC_EnableIRQ(USB_IRQn);
	
	// 软件断连并重连
	USB_Soft_Disconnect(&USB_OTG_dev);
	USB_OTG_BSP_mDelay(1000);
	USB_Soft_Connect(&USB_OTG_dev);
}

void USB_OTG_BSP_DisableInterrupt(USB_OTG_CORE_HANDLE * pdev)
{
	// 软件断连
	USB_Soft_Disconnect(&USB_OTG_dev);
    
    NVIC_DisableIRQ(USB_IRQn);
}

#define count_us 6	//系统时钟为32MHZ

// USB驱动us级延时
void USB_OTG_BSP_uDelay(const uint32_t usec)
{
    DelayUs(usec);
}

// USB驱动ms级延时 
void USB_OTG_BSP_mDelay(const uint32_t msec)
{
    USB_OTG_BSP_uDelay(msec * 1000);
}
