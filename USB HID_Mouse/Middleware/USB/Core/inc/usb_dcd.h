#ifndef __DCD_H__
#define __DCD_H__

// USB设备驱动头文件，定义端点、设备状态，提供初始化、端点设置、设备中断处理接口

#include "usb_core.h"

// USB设备端点类型定义
#define USB_OTG_EP_CONTROL                       0  // 控制传输
#define USB_OTG_EP_ISOC                          1  // 同步输出
#define USB_OTG_EP_BULK                          2  // 块传输
#define USB_OTG_EP_INT                           3  // 中断传输
#define USB_OTG_EP_MASK                          3

// USB设备状态定义
#define USB_OTG_DEFAULT                          1
#define USB_OTG_ADDRESSED                        2
#define USB_OTG_CONFIGURED                       3
#define USB_OTG_SUSPENDED                        4

// 端点描述符定义
typedef struct
{
    uint8_t  bLength;
    uint8_t  bDescriptorType;
    uint8_t  bEndpointAddress;
    uint8_t  bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t  bInterval;
}
EP_DESCRIPTOR , *PEP_DESCRIPTOR;

// USB设备初始化、端点设置、设备中断处理接口
void DCD_Init(USB_OTG_CORE_HANDLE *pdev, USB_OTG_CORE_ID_TypeDef coreID);
void DCD_DevConnect(USB_OTG_CORE_HANDLE *pdev);
void DCD_DevDisconnect(USB_OTG_CORE_HANDLE *pdev);

void DCD_EP_SetAddress(USB_OTG_CORE_HANDLE *pdev, uint8_t address);
uint32_t DCD_EP_Open(USB_OTG_CORE_HANDLE *pdev, uint8_t ep_addr, uint16_t ep_mps, uint8_t ep_type);
uint32_t DCD_EP_Close(USB_OTG_CORE_HANDLE *pdev, uint8_t ep_addr);

uint32_t DCD_EP_PrepareRx(USB_OTG_CORE_HANDLE *pdev, uint8_t ep_addr, uint8_t *pbuf, uint16_t buf_len);
uint32_t DCD_EP_Tx(USB_OTG_CORE_HANDLE *pdev, uint8_t  ep_addr, uint8_t *pbuf, uint32_t buf_len);

uint32_t DCD_EP_Stall(USB_OTG_CORE_HANDLE *pdev, uint8_t epnum);
uint32_t DCD_EP_ClrStall(USB_OTG_CORE_HANDLE *pdev, uint8_t epnum);
uint32_t DCD_EP_Flush (USB_OTG_CORE_HANDLE *pdev, uint8_t epnum);

uint32_t DCD_Handle_ISR(USB_OTG_CORE_HANDLE *pdev);
uint32_t DCD_GetEPStatus(USB_OTG_CORE_HANDLE *pdev, uint8_t epnum);
void DCD_SetEPStatus (USB_OTG_CORE_HANDLE *pdev, uint8_t epnum,  uint32_t Status);
#endif
