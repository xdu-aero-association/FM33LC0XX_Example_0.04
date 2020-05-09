#ifndef __USBD_USR_H__
#define __USBD_USR_H__

#include "usbd_ioreq.h"

extern  USBD_Usr_cb_TypeDef USR_cb;

void USBD_USR_Init(void);
void USBD_USR_DeviceReset (uint8_t speed);
void USBD_USR_DeviceConfigured (void);
void USBD_USR_DeviceSuspended(void);
void USBD_USR_DeviceResumed(void);

void USBD_USR_DeviceConnected(void);
void USBD_USR_DeviceDisconnected(void); 

#endif 
