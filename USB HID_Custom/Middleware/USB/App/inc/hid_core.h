#ifndef __USB_HID_CORE_H_
#define __USB_HID_CORE_H_

#include  "usbd_ioreq.h"

#define USB_HID_CONFIG_DESC_SIZ       41
#define USB_HID_DESC_SIZ              9
#define HID_MOUSE_REPORT_DESC_SIZE    33

// Class Descriptor Class
#define HID_DESCRIPTOR_TYPE           0x21  // HID
#define HID_REPORT_DESC               0x22  // Report
#define HID_PHYSICAL_DESC             0x23  // Physical descriptor

#define HID_HS_BINTERVAL              0x07
#define HID_FS_BINTERVAL              0x0A

#define HID_REQ_SET_PROTOCOL          0x0B
#define HID_REQ_GET_PROTOCOL          0x03

#define HID_REQ_SET_IDLE              0x0A
#define HID_REQ_GET_IDLE              0x02

#define HID_REQ_SET_REPORT            0x09
#define HID_REQ_GET_REPORT            0x01

// USB设备类回调结构体
extern USBD_Class_cb_TypeDef  USBD_HID_cb;

uint8_t USBD_HID_SendReport (USB_OTG_CORE_HANDLE  *pdev, uint8_t *report, uint16_t len);
uint8_t USBD_HID_RecvReport (USB_OTG_CORE_HANDLE  *pdev, uint8_t *report, uint16_t *len);

uint32_t USBD_HID_GetPollingInterval (USB_OTG_CORE_HANDLE *pdev);

#endif 
