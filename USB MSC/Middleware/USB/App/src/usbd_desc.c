#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_req.h"
#include "usbd_conf.h"
#include "usb_regs.h"

//字符串序列号长度
#define USB_SIZ_STRING_SERIAL       0x42	

//设备ID定义，芯片UID存储位置
#define DEVICE_UID1                 (*(uint32_t *)(0x1ffffe80))
#define DEVICE_UID2                 (*(uint32_t *)(0x1ffffe84))
#define DEVICE_UID3                 (*(uint32_t *)(0x1ffffe88))
#define DEVICE_UID4                 (*(uint32_t *)(0x1ffffe8c))

#define USBD_VID                        0x464D
#define USBD_PID                        0x0402

#define USBD_LANGID_STRING              0x409
#define USBD_MANUFACTURER_STRING        "FMSH"
#define USBD_PRODUCT_FS_STRING          "Mass Storage in FS Mode"
#define USBD_CONFIGURATION_FS_STRING    "MSC Config"
#define USBD_INTERFACE_FS_STRING        "MSC Interface"


USBD_DEVICE USR_desc = {
    USBD_USR_DeviceDescriptor,
    USBD_USR_LangIDStrDescriptor,
    USBD_USR_ManufacturerStrDescriptor,
    USBD_USR_ProductStrDescriptor,
    USBD_USR_SerialStrDescriptor,
    USBD_USR_ConfigStrDescriptor,
    USBD_USR_InterfaceStrDescriptor,
};//描述符回调结构体

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )      /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif                          /* USB_DATA_STRUCT_ALIGNED */
/* USB Standard Device Descriptor 标准设备描述符 */
__ALIGN_BEGIN uint8_t USBD_DeviceDesc[USB_SIZ_DEVICE_DESC] __ALIGN_END = {
    0x12,                         /* bLength */
    USB_DEVICE_DESCRIPTOR_TYPE,   /* bDescriptorType */
    0x00,                         /* bcdUSB */
    0x02,
    0x00,                         /* bDeviceClass */
    0x00,                         /* bDeviceSubClass */
    0x00,                         /* bDeviceProtocol */
    USB_OTG_MAX_EP0_SIZE,         /* bMaxPacketSize */
    LOBYTE(USBD_VID),             /* idVendor */
    HIBYTE(USBD_VID),             /* idVendor */
    LOBYTE(USBD_PID),             /* idVendor */
    HIBYTE(USBD_PID),             /* idVendor */
    0x00,                         /* bcdDevice rel. 2.00 */
    0x02,
    USBD_IDX_MFC_STR,             /* Index of manufacturer string */
    USBD_IDX_PRODUCT_STR,         /* Index of product string */
    USBD_IDX_SERIAL_STR,          /* Index of serial number string */
    USBD_CFG_MAX_NUM              /* bNumConfigurations */
};                              /* USB_DeviceDescriptor */


#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )      /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif                          /* USB_DATA_STRUCT_ALIGNED */
/* USB LangID Descriptor LANGID描述符 */
__ALIGN_BEGIN uint8_t USBD_LangIDDesc[USB_SIZ_STRING_LANGID] __ALIGN_END = {
    USB_SIZ_STRING_LANGID,
    USB_DESC_TYPE_STRING,
    LOBYTE(USBD_LANGID_STRING),
    HIBYTE(USBD_LANGID_STRING),
};

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )      /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif 
uint8_t USBD_StringSerial[USB_SIZ_STRING_SERIAL] = {
    USB_SIZ_STRING_SERIAL,
    USB_DESC_TYPE_STRING,
};//字符串序列

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )      /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif                          /* USB_DATA_STRUCT_ALIGNED */
__ALIGN_BEGIN uint8_t USBD_StrDesc[USB_MAX_STR_DESC_SIZ] __ALIGN_END; //字符串描述符

static void IntToUnicode(uint32_t value, uint8_t * pbuf, uint8_t len);	//Int转unicode
static void Get_SerialNum(void);	//获取序列号

/**
* @brief  USBD_USR_DeviceDescriptor 
*         return the device descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *USBD_USR_DeviceDescriptor(uint8_t speed, uint16_t * length)
{
    *length = sizeof(USBD_DeviceDesc);
    return (uint8_t *) USBD_DeviceDesc;
}

/**
* @brief  USBD_USR_LangIDStrDescriptor 
*         return the LangID string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *USBD_USR_LangIDStrDescriptor(uint8_t speed, uint16_t * length)
{
    *length = sizeof(USBD_LangIDDesc);
    return (uint8_t *) USBD_LangIDDesc;
}


/**
* @brief  USBD_USR_ProductStrDescriptor 
*         return the product string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *USBD_USR_ProductStrDescriptor(uint8_t speed, uint16_t * length)
{
    USBD_GetString((uint8_t *)USBD_PRODUCT_FS_STRING, USBD_StrDesc, length);
    return USBD_StrDesc;
}

/**
* @brief  USBD_USR_ManufacturerStrDescriptor 
*         return the manufacturer string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *USBD_USR_ManufacturerStrDescriptor(uint8_t speed, uint16_t * length)
{
    USBD_GetString((uint8_t *)USBD_MANUFACTURER_STRING, USBD_StrDesc, length);
    return USBD_StrDesc;
}

/**
* @brief  USBD_USR_SerialStrDescriptor 
*         return the serial number string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *USBD_USR_SerialStrDescriptor(uint8_t speed, uint16_t * length)
{
    *length = USB_SIZ_STRING_SERIAL;

    /* Update the serial number string descriptor with the data from the unique
    * ID */
    Get_SerialNum();

    return (uint8_t *) USBD_StringSerial;
}

/**
* @brief  USBD_USR_ConfigStrDescriptor 
*         return the configuration string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *USBD_USR_ConfigStrDescriptor(uint8_t speed, uint16_t * length)
{
    USBD_GetString((uint8_t *)USBD_CONFIGURATION_FS_STRING, USBD_StrDesc, length);
    return USBD_StrDesc;
}


/**
* @brief  USBD_USR_InterfaceStrDescriptor 
*         return the interface string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *USBD_USR_InterfaceStrDescriptor(uint8_t speed, uint16_t * length)
{
    USBD_GetString((uint8_t *)USBD_INTERFACE_FS_STRING, USBD_StrDesc, length);
    return USBD_StrDesc;
}

/**
  * @brief  Create the serial number string descriptor  返回序列号
  * @param  None 
  * @retval None
  */
static void Get_SerialNum(void)
{
    uint32_t LotID = DEVICE_UID1;
    uint32_t WaferID = DEVICE_UID2;
    uint32_t xAddr = DEVICE_UID3;
    uint32_t yAddr = DEVICE_UID4;

    IntToUnicode(LotID, &USBD_StringSerial[2], 8);
    IntToUnicode(WaferID, &USBD_StringSerial[18], 8);
    IntToUnicode(xAddr, &USBD_StringSerial[34], 8);
    IntToUnicode(yAddr, &USBD_StringSerial[50], 8);
}

/**
  * @brief  Convert Hex 32Bits value into char
  * @param  value: value to convert
  * @param  pbuf: pointer to the buffer 
  * @param  len: buffer length
  * @retval None
  */
static void IntToUnicode(uint32_t value, uint8_t * pbuf, uint8_t len)
{
    uint8_t idx = 0;

    for (idx = 0; idx < len; idx++)
    {
        if (((value >> 28)) < 0xA)
        {
            pbuf[2 * idx] = (value >> 28) + '0';
        }
        else
        {
            pbuf[2 * idx] = (value >> 28) + 'A' - 10;
        }
        value = value << 4;
        pbuf[2 * idx + 1] = 0;
    }
}
