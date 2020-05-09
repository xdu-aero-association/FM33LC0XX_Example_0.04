#ifndef __CDC_CORE_H_
#define __CDC_CORE_H_

#include "usbd_ioreq.h"
#include "stream.h"

#define USB_CDC_CONFIG_DESC_SIZ                (60)			//配置描述符大小
	
#define DEVICE_CLASS_CDC                        0x02		//CDC类
#define DEVICE_SUBCLASS_CDC                     0x00		//CDC子类

#define USB_DEVICE_DESCRIPTOR_TYPE              0x01		//设备描述符
#define USB_CONFIGURATION_DESCRIPTOR_TYPE       0x02		//配置描述符
#define USB_STRING_DESCRIPTOR_TYPE              0x03		//字符串描述符
#define USB_INTERFACE_DESCRIPTOR_TYPE           0x04		//接口描述符
#define USB_ENDPOINT_DESCRIPTOR_TYPE            0x05		//端点描述符

#define STANDARD_ENDPOINT_DESC_SIZE             0x09		//标注端点描述符长度

// CDC Requests
#define SEND_ENCAPSULATED_COMMAND               0x00		//发送封包命令
#define GET_ENCAPSULATED_RESPONSE               0x01		//获取封包回应
#define SET_COMM_FEATURE                        0x02		//设置通用特性
#define GET_COMM_FEATURE                        0x03		//获取通用特性
#define CLEAR_COMM_FEATURE                      0x04		//清除通用特性
#define SET_LINE_CODING                         0x20		//设置波特率等串口参数
#define GET_LINE_CODING                         0x21		//获取波特率等
#define SET_CONTROL_LINE_STATE                  0x22		//设置控制总线状态
#define SEND_BREAK                              0x23		//发送BREAK
#define NO_CMD                                  0xFF		//没有命令

// CDC Endpoints parameters: you can fine tune these values depending on the needed baudrates and performance
#define CDC_DATA_MAX_SIZE               CDC_EP_MAX_SIZE      /* Total size of data buffer */ 
#define CDC_CMD_MAX_SIZE                8                    /* Control Endpoint Packet size */

// (CDC_DATA_MAX_SIZE * 8) / (MAX_BAUDARATE * 1000) should be > CDC_IN_FRAME_INTERVAL
#define CDC_IN_FRAME_INTERVAL           5                    /* Number of frames between IN transfers */

#define APP_FOPS                        VCP_fops	//底层接口结构体指针

typedef struct _CDC_IF_PROP
{
    uint16_t (*pIf_Init)     (void);   
    uint16_t (*pIf_DeInit)   (void);   
    uint16_t (*pIf_Ctrl)     (uint32_t Cmd, uint8_t* Buf, uint32_t Len);
    uint16_t (*pIf_DataTx)   (uint8_t *Buf, uint16_t Len);
    uint16_t (*pIf_DataRx)   (uint8_t *Buf, uint16_t Len);
}
CDC_IF_Prop_TypeDef;

extern USBD_Class_cb_TypeDef  USBD_CDC_cb;

#endif
