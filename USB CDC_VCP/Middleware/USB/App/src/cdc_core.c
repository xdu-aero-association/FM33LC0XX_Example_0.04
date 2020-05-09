/**
  ******************************************************************************
  *          ===================================================================      
  *                                CDC Class Driver Description
  *          =================================================================== 
  *           This driver manages the "Universal Serial Bus Class Definitions for Communications Devices
  *           Revision 1.2 November 16, 2007" and the sub-protocol specification of "Universal Serial Bus 
  *           Communications Class Subclass Specification for PSTN Devices Revision 1.2 February 9, 2007"
  *           This driver implements the following aspects of the specification:
  *             - Device descriptor management
  *             - Configuration descriptor management
  *             - Enumeration as CDC device with 2 data endpoints (IN and OUT) and 1 command endpoint (IN)
  *             - Requests management (as described in section 6.2 in specification)
  *             - Abstract Control Model compliant
  *             - Union Functional collection (using 1 IN endpoint for control)
  *             - Data interface class
  ******************************************************************************
  */ 

#include "cdc_core.h"
#include "usbd_desc.h"
#include "usbd_req.h"

extern DataStream USBRxStream;
extern DataStream USBTxStream;

//CDC类状态定义
#define USB_CDC_IDLE         0      // USB空闲
#define USB_CDC_BUSY         1      // USB忙
#define USB_CDC_ZLP          2      // 发送0长度数据包

/*********************************************
   CDC Device library callbacks
 *********************************************/
uint8_t  usbd_cdc_Init        (void *pdev, uint8_t cfgidx);
uint8_t  usbd_cdc_DeInit      (void *pdev, uint8_t cfgidx);
uint8_t  usbd_cdc_Setup       (void *pdev, USB_SETUP_REQ *req);
uint8_t  usbd_cdc_EP0_RxReady (void *pdev);
uint8_t  usbd_cdc_DataIn      (void *pdev, uint8_t epnum);
uint8_t  usbd_cdc_DataOut     (void *pdev, uint8_t epnum);
uint8_t  usbd_cdc_SOF         (void *pdev);

/*********************************************
   CDC specific management functions
 *********************************************/
static void Handle_USBAsynchXfer(void *pdev);
static uint8_t  *USBD_cdc_GetCfgDesc(uint8_t speed, uint16_t *length); // 获取配置描述符


extern CDC_IF_Prop_TypeDef APP_FOPS;						// 接口服务程序
extern uint8_t USBD_DeviceDesc[USB_SIZ_DEVICE_DESC];		// 设备描述符18字节长度

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN uint8_t usbd_cdc_CfgDesc [USB_CDC_CONFIG_DESC_SIZ] __ALIGN_END;       // 配置描述符大小

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN uint8_t usbd_cdc_OtherCfgDesc [USB_CDC_CONFIG_DESC_SIZ] __ALIGN_END;	// 高速设备时才有的其他配置描述符

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN static __IO uint32_t  usbd_cdc_AltSet  __ALIGN_END = 0;	            // wValue数值

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN uint8_t USB_Rx_Buffer   [CDC_DATA_MAX_SIZE] __ALIGN_END;	    // USB接收缓冲区定义，最大包长度64字节

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN uint8_t USB_Tx_Buffer   [CDC_DATA_MAX_SIZE] __ALIGN_END;	    // USB发送缓冲区定义，最大包长度64字节


#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN uint8_t CmdBuff[CDC_CMD_MAX_SIZE] __ALIGN_END; 	                    // 命令缓冲区 8字节


uint8_t USB_Tx_State = USB_CDC_IDLE;    // USB发送状态

static uint32_t cdcCmd = NO_CMD;	    // cdc命令码
static uint32_t cdcLen = 0;			    // cdc长度

/* CDC interface class callbacks structure */
USBD_Class_cb_TypeDef  USBD_CDC_cb = 
{
    usbd_cdc_Init,
    usbd_cdc_DeInit,
    usbd_cdc_Setup,
    NULL,                 /* EP0_TxSent, */
    usbd_cdc_EP0_RxReady,
    usbd_cdc_DataIn,
    usbd_cdc_DataOut,
    usbd_cdc_SOF,
    NULL,
    NULL,     
    USBD_cdc_GetCfgDesc,
};

// USB CDC device Configuration Descriptor
#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN uint8_t usbd_cdc_CfgDesc[USB_CDC_CONFIG_DESC_SIZ]  __ALIGN_END =
{
    /*Configuration Descriptor */
    0x09,   /* bLength: Configuration Descriptor size */
    USB_CONFIGURATION_DESCRIPTOR_TYPE,      /* bDescriptorType: Configuration */
    USB_CDC_CONFIG_DESC_SIZ,                /* wTotalLength:no of returned bytes */
    0x00,
    0x02,   /* bNumInterfaces: 2 interface */
    0x01,   /* bConfigurationValue: Configuration value */
    0x00,   /* iConfiguration: Index of string descriptor describing the configuration */
    0xC0,   /* bmAttributes: self powered */
    0x32,   /* MaxPower 0 mA */

    /*---------------------------------------------------------------------------*/

    /*Interface Descriptor */
    0x09,   /* bLength: Interface Descriptor size */
    USB_INTERFACE_DESCRIPTOR_TYPE,  /* bDescriptorType: Interface */
    /* Interface descriptor type */
    0x00,   /* bInterfaceNumber: Number of Interface */
    0x00,   /* bAlternateSetting: Alternate setting */
    0x00,   /* bNumEndpoints: One endpoints used */
    0x02,   /* bInterfaceClass: Communication Interface Class */
    0x02,   /* bInterfaceSubClass: Abstract Control Model */
    0x01,   /* bInterfaceProtocol: Common AT commands */
    0x00,   /* iInterface: */

    /*Header Functional Descriptor */
    0x05,   /* bLength: Endpoint Descriptor size */
    0x24,   /* bDescriptorType: CS_INTERFACE */
    0x00,   /* bDescriptorSubtype: Header Func Desc */
    0x10,   /* bcdCDC: spec release number */
    0x01,

    /*Call Management Functional Descriptor */
    0x05,   /* bFunctionLength */
    0x24,   /* bDescriptorType: CS_INTERFACE */
    0x01,   /* bDescriptorSubtype: Call Management Func Desc */
    0x00,   /* bmCapabilities: D0+D1 */
    0x01,   /* bDataInterface: 1 */

    /*ACM Functional Descriptor */
    0x04,   /* bFunctionLength */
    0x24,   /* bDescriptorType: CS_INTERFACE */
    0x02,   /* bDescriptorSubtype: Abstract Control Management desc */
    0x02,   /* bmCapabilities */

    /*Union Functional Descriptor */
    0x05,   /* bFunctionLength */
    0x24,   /* bDescriptorType: CS_INTERFACE */
    0x06,   /* bDescriptorSubtype: Union func desc */
    0x00,   /* bMasterInterface: Communication class interface */
    0x01,   /* bSlaveInterface0: Data Class Interface */

    /*---------------------------------------------------------------------------*/

    /*Data class interface descriptor */
    0x09,   /* bLength: Endpoint Descriptor size */
    USB_INTERFACE_DESCRIPTOR_TYPE,  /* bDescriptorType: */
    0x01,   /* bInterfaceNumber: Number of Interface */
    0x00,   /* bAlternateSetting: Alternate setting */
    0x02,   /* bNumEndpoints: Two endpoints used */
    0x0A,   /* bInterfaceClass: CDC */
    0x00,   /* bInterfaceSubClass: */
    0x00,   /* bInterfaceProtocol: */
    0x00,   /* iInterface: */

    /*Endpoint OUT Descriptor */
    0x07,   /* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE,      /* bDescriptorType: Endpoint */
    CDC_OUT_EP,                        /* bEndpointAddress */
    0x02,                              /* bmAttributes: Bulk */
    LOBYTE(CDC_EP_MAX_SIZE),           /* wMaxPacketSize: */
    HIBYTE(CDC_EP_MAX_SIZE),
    0x00,                              /* bInterval: ignore for Bulk transfer */

    /*Endpoint IN Descriptor */
    0x07,   /* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE,      /* bDescriptorType: Endpoint */
    CDC_IN_EP,                         /* bEndpointAddress */
    0x02,                              /* bmAttributes: Bulk */
    LOBYTE(CDC_EP_MAX_SIZE),           /* wMaxPacketSize: */
    HIBYTE(CDC_EP_MAX_SIZE),
    0x00                               /* bInterval: ignore for Bulk transfer */
};


/**
  * @brief  usbd_cdc_Init
  *         Initialize the CDC interface
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
uint8_t usbd_cdc_Init(void  *pdev, uint8_t cfgidx)
{
    //uint8_t *pbuf;

    /* Open EP IN 打开输入端点*/
    DCD_EP_Open(pdev, CDC_IN_EP, CDC_EP_MAX_SIZE, USB_OTG_EP_BULK);

    /* Open EP OUT 打开输出端点*/
    DCD_EP_Open(pdev, CDC_OUT_EP, CDC_EP_MAX_SIZE, USB_OTG_EP_BULK);

    /* Initialize the Interface physical components */
    APP_FOPS.pIf_Init();

    USB_Tx_State = USB_CDC_IDLE;
    cdcCmd = 0xFF;
    cdcLen = 0;	
    
    /* Prepare Out endpoint to receive next packet */
    DCD_EP_PrepareRx(pdev, CDC_OUT_EP, (uint8_t*)(USB_Rx_Buffer), CDC_DATA_MAX_SIZE);

    return USBD_OK;
}

/**
  * @brief  usbd_cdc_Init
  *         DeInitialize the CDC layer
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
uint8_t usbd_cdc_DeInit(void *pdev, uint8_t cfgidx)
{
    /* Close EP IN */
    DCD_EP_Close(pdev, CDC_IN_EP);

    /* Close EP OUT */
    DCD_EP_Close(pdev, CDC_OUT_EP);

    /* Restore default state of the Interface physical components */
    APP_FOPS.pIf_DeInit();

    return USBD_OK;
}

/**
  * @brief  usbd_cdc_Setup
  *         Handle the CDC specific requests
  * @param  pdev: instance
  * @param  req: usb requests
  * @retval status
  */
uint8_t usbd_cdc_Setup(void  *pdev, USB_SETUP_REQ *req)
{
    switch (req->bmRequest & USB_REQ_TYPE_MASK)
    {
    /* CDC Class Requests -------------------------------*/
    case USB_REQ_TYPE_CLASS :
        /* Check if the request is a data setup packet */
        if (req->wLength)
        {
            /* Check if the request is Device-to-Host */
            if (req->bmRequest & 0x80)
            {
                /* Get the data to be sent to Host from interface layer */
                APP_FOPS.pIf_Ctrl(req->bRequest, CmdBuff, req->wLength);

                /* Send the data to the host */
                USBD_CtlSendData(pdev, CmdBuff, req->wLength);          
            }
            else /* Host-to-Device request */
            {
                /* Set the value of the current command to be processed */
                cdcCmd = req->bRequest;
                cdcLen = req->wLength;

                /* Prepare the reception of the buffer over EP0
                Next step: the received data will be managed in usbd_cdc_EP0_TxSent() 
                function. */
                USBD_CtlPrepareRx(pdev, CmdBuff, req->wLength);          
            }
        }
        else /* No Data request */
        {
            /* Transfer the command to the interface layer */
            APP_FOPS.pIf_Ctrl(req->bRequest, NULL, 0);
        }
        return USBD_OK;

    /* Standard Requests -------------------------------*/
    case USB_REQ_TYPE_STANDARD://标准请求处理
        switch (req->bRequest)
        {
        case USB_REQ_GET_DESCRIPTOR: 
            USBD_CtlError (pdev, req);
            return USBD_FAIL;
          
        case USB_REQ_GET_INTERFACE :
            USBD_CtlSendData(pdev, (uint8_t *)&usbd_cdc_AltSet, 1);
            break;
          
        case USB_REQ_SET_INTERFACE :
            if ((uint8_t)(req->wValue) < USBD_ITF_MAX_NUM)
            {
                usbd_cdc_AltSet = (uint8_t)(req->wValue);
            }
            else
            {
                /* Call the error management function (command will be nacked */
                USBD_CtlError (pdev, req);
            }
            break;
        }
        break;
    
    default:
        USBD_CtlError(pdev, req);
        return USBD_FAIL;
    }
    
    return USBD_OK;
}

/**
  * @brief  usbd_cdc_EP0_RxReady
  *         Data received on control endpoint
  * @param  pdev: device instance
  * @retval status
  */
uint8_t usbd_cdc_EP0_RxReady(void *pdev)
{ 
    if (cdcCmd != NO_CMD)
    {
        /* Process the data */
        APP_FOPS.pIf_Ctrl(cdcCmd, CmdBuff, cdcLen);
        
        /* Reset the command variable to default value */
        cdcCmd = NO_CMD;
    }

    return USBD_OK;
}


/**
  * @brief  usbd_cdc_DataIn
  *         Data sent on non-control IN endpoint
  * @param  pdev: device instance
  * @param  epnum: endpoint number
  * @retval status
  */
uint8_t usbd_cdc_DataIn(void *pdev, uint8_t epnum)
{
    uint16_t USB_Tx_length;
    
    if (USB_Tx_State == USB_CDC_BUSY)
    {
        USB_Tx_length = StreamGetDataSize(&USBTxStream);
        if (USB_Tx_length == 0)
        {
            USB_Tx_State = USB_CDC_IDLE;
        }
        else if (USB_Tx_length > CDC_DATA_MAX_SIZE)
        {
            StreamReadData(&USBTxStream, USB_Tx_Buffer, CDC_DATA_MAX_SIZE);
            APP_FOPS.pIf_DataTx(USB_Tx_Buffer, CDC_DATA_MAX_SIZE);
            
            DCD_EP_Tx(pdev, CDC_IN_EP, USB_Tx_Buffer, CDC_DATA_MAX_SIZE);
        }
        else
        {
            StreamReadData(&USBTxStream, USB_Tx_Buffer, USB_Tx_length);
            APP_FOPS.pIf_DataTx(USB_Tx_Buffer, USB_Tx_length);
            
            if (USB_Tx_length == CDC_DATA_MAX_SIZE)
            {
                USB_Tx_State = USB_CDC_ZLP;
            }
            DCD_EP_Tx(pdev, CDC_IN_EP, USB_Tx_Buffer, USB_Tx_length);
        }
    }
    else if (USB_Tx_State == USB_CDC_ZLP)
    {
        USB_Tx_State = USB_CDC_IDLE;
        DCD_EP_Tx(pdev, CDC_IN_EP, NULL, 0);
    }
    
    return USBD_OK;
}

/**
  * @brief  usbd_cdc_DataOut
  *         Data received on non-control Out endpoint
  * @param  pdev: device instance
  * @param  epnum: endpoint number
  * @retval status
  */
uint8_t usbd_cdc_DataOut(void *pdev, uint8_t epnum)
{      
    uint16_t USB_Rx_length;
    
    if (epnum == CDC_OUT_EP)
    {
        /* Get the received data buffer and update the counter */
        USB_Rx_length = USBD_GetRxCount(pdev, epnum);
        
        /* USB data will be immediately processed, this allow next USB traffic being 
        NAKed till the end of the application Xfer */
        StreamWriteData(&USBRxStream, USB_Rx_Buffer, USB_Rx_length);
        APP_FOPS.pIf_DataRx(USB_Rx_Buffer, USB_Rx_length);
    
        /* Prepare Out endpoint to receive next packet */
        DCD_EP_PrepareRx(pdev, epnum, (uint8_t*)(USB_Rx_Buffer), CDC_DATA_MAX_SIZE);
    }
    
    return USBD_OK;
}

/**
  * @brief  usbd_audio_SOF
  *         Start Of Frame event management
  * @param  pdev: instance
  * @param  epnum: endpoint number
  * @retval status
  */
uint8_t usbd_cdc_SOF(void *pdev)
{      
    static uint32_t FrameCount = 0;

    if (FrameCount++ == CDC_IN_FRAME_INTERVAL)
    {
        /* Reset the frame counter */
        FrameCount = 0;

        /* Check the data to be sent through IN pipe */
        Handle_USBAsynchXfer(pdev);
    }

    return USBD_OK;
}

/**
  * @brief  Handle_USBAsynchXfer
  *         Send data to USB
  * @param  pdev: instance
  * @retval None
  */
static void Handle_USBAsynchXfer(void *pdev)
{
    uint16_t USB_Tx_length;

    if (USB_Tx_State == USB_CDC_IDLE)
    {
        USB_Tx_length = StreamGetDataSize(&USBTxStream);
        
        if (USB_Tx_length > 0)
        {
            if (USB_Tx_length > CDC_DATA_MAX_SIZE)
            {
                USB_Tx_State = USB_CDC_BUSY;
                
                StreamReadData(&USBTxStream, USB_Tx_Buffer, CDC_DATA_MAX_SIZE);
                APP_FOPS.pIf_DataTx(USB_Tx_Buffer, CDC_DATA_MAX_SIZE);
                
                DCD_EP_Tx(pdev, CDC_IN_EP, USB_Tx_Buffer, CDC_DATA_MAX_SIZE);
            }
            else
            {
                StreamReadData(&USBTxStream, USB_Tx_Buffer, USB_Tx_length);
                APP_FOPS.pIf_DataTx(USB_Tx_Buffer, USB_Tx_length);
                
                if (USB_Tx_length == CDC_DATA_MAX_SIZE)
                {
                    USB_Tx_State = USB_CDC_ZLP;
                }
                else
                {
                    USB_Tx_State = USB_CDC_BUSY;
                }
                
                DCD_EP_Tx(pdev, CDC_IN_EP, USB_Tx_Buffer, USB_Tx_length);
            }
        }
    }
}

/**
  * @brief  USBD_cdc_GetCfgDesc 
  *         Return configuration descriptor
  * @param  speed : current device speed
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t *USBD_cdc_GetCfgDesc(uint8_t speed, uint16_t *length)
{
    *length = sizeof(usbd_cdc_CfgDesc);
    return usbd_cdc_CfgDesc;
}
