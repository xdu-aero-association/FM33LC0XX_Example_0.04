#ifndef __USB_DESC_H
#define __USB_DESC_H

#include "usbd_req.h"


#define USB_DEVICE_DESCRIPTOR_TYPE              0x01	//设备描述符
#define USB_CONFIGURATION_DESCRIPTOR_TYPE       0x02	//配置描述符
#define USB_STRING_DESCRIPTOR_TYPE              0x03	//字符串描述符
#define USB_INTERFACE_DESCRIPTOR_TYPE           0x04	//接口描述符
#define USB_ENDPOINT_DESCRIPTOR_TYPE            0x05	//端点描述符
#define USB_SIZ_DEVICE_DESC                     18		//设备描述符长度
#define USB_SIZ_STRING_LANGID                   4		//字符串LANGID描述符长度

//设备ID定义，芯片UID存储位置
#define DEVICE_UID1          (*(uint32_t *)(0x1ffffe80))
#define DEVICE_UID2          (*(uint32_t *)(0x1ffffe84))
#define DEVICE_UID3          (*(uint32_t *)(0x1ffffe88))
#define DEVICE_UID4          (*(uint32_t *)(0x1ffffe8c))

#define  USB_SIZ_STRING_SERIAL       0x42	//字符串序列号长度


extern  uint8_t USBD_DeviceDesc  [USB_SIZ_DEVICE_DESC];                 //设备描述符18字节
extern  uint8_t USBD_StrDesc[USB_MAX_STR_DESC_SIZ];						//字符串描述符，最大长度156字节
extern  uint8_t USBD_OtherSpeedCfgDesc[USB_LEN_CFG_DESC]; 				//其他速度配置描述符
extern  uint8_t USBD_DeviceQualifierDesc[USB_LEN_DEV_QUALIFIER_DESC];	//设备解释描述符
extern  uint8_t USBD_LangIDDesc[USB_SIZ_STRING_LANGID];					//LANGID描述符，4字节
extern  USBD_DEVICE USR_desc; 										    //描述符回调结构体


uint8_t *USBD_USR_DeviceDescriptor( uint8_t speed , uint16_t *length);				//返回设备描述符
uint8_t *USBD_USR_LangIDStrDescriptor( uint8_t speed , uint16_t *length);			//返回LANGID字符串描述符
uint8_t *USBD_USR_ManufacturerStrDescriptor ( uint8_t speed , uint16_t *length);	//返回生产商字符串描述符
uint8_t *USBD_USR_ProductStrDescriptor ( uint8_t speed , uint16_t *length);		//返回产品字符串描述符
uint8_t *USBD_USR_SerialStrDescriptor( uint8_t speed , uint16_t *length);			//返回序列号字符串描述符
uint8_t *USBD_USR_ConfigStrDescriptor( uint8_t speed , uint16_t *length);			//返回配置字符串描述符
uint8_t *USBD_USR_InterfaceStrDescriptor( uint8_t speed , uint16_t *length);		//返回接口字符串描述符

#ifdef USB_SUPPORT_USER_STRING_DESC
uint8_t *     USBD_USR_USRStringDesc (uint8_t speed, uint8_t idx , uint16_t *length);	//用户字符串描述符
#endif

#endif
