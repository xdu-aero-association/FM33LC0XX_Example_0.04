#ifndef __USB_BSP__H__
#define __USB_BSP__H__

// 相对于所用硬件平台的特定API

#include "usb_core.h"

extern USB_OTG_CORE_HANDLE USB_OTG_dev;

void USB_OTG_BSP_Init(USB_OTG_CORE_HANDLE *pdev);
void USB_OTG_BSP_DeInit(USB_OTG_CORE_HANDLE *pdev);
void USB_OTG_BSP_EnableInterrupt(USB_OTG_CORE_HANDLE *pdev);
void USB_OTG_BSP_DisableInterrupt(USB_OTG_CORE_HANDLE *pdev);

void USB_OTG_BSP_uDelay(const uint32_t usec);
void USB_OTG_BSP_mDelay(const uint32_t msec);

#endif
