#ifndef __MSC_CORE_H__
#define __MSC_CORE_H__

#include  "usbd_ioreq.h"


#define BOT_GET_MAX_LUN              0xFE
#define BOT_RESET                    0xFF
#define USB_MSC_CONFIG_DESC_SIZ      32

#define MSC_EPIN_SIZE                MSC_MAX_PACKET 
#define MSC_EPOUT_SIZE               MSC_MAX_PACKET 

extern USBD_Class_cb_TypeDef  USBD_MSC_cb;

#endif
