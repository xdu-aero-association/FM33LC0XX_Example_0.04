/**
  ******************************************************************************
  * @verbatim
  *      
  *          ===================================================================      
  *                                HID Class  Description
  *          =================================================================== 
  *           This module manages the HID class V1.11 following the "Device Class Definition
  *           for Human Interface Devices (HID) Version 1.11 Jun 27, 2001".
  *           This driver implements the following aspects of the specification:
  *             - The Boot Interface Subclass
  *             - The Mouse protocol
  *             - Usage Page : Generic Desktop
  *             - Usage : Joystick)
  *             - Collection : Application 
  *
  ******************************************************************************
  */ 
  
#include <string.h>
#include "hid_core.h"
#include "usbd_desc.h"
#include "usbd_req.h"

static uint8_t  USBD_HID_Init (void  *pdev, uint8_t cfgidx);
static uint8_t  USBD_HID_DeInit (void  *pdev, uint8_t cfgidx);
static uint8_t  USBD_HID_Setup (void  *pdev, USB_SETUP_REQ *req);
static uint8_t  *USBD_HID_GetCfgDesc (uint8_t speed, uint16_t *length);
static uint8_t  USBD_HID_DataIn (void  *pdev, uint8_t epnum);
static uint8_t  USBD_HID_DataOut (void  *pdev, uint8_t epnum);

USBD_Class_cb_TypeDef  USBD_HID_cb = 
{
    USBD_HID_Init,
    USBD_HID_DeInit,
    USBD_HID_Setup,
    NULL, /*EP0_TxSent*/  
    NULL, /*EP0_RxReady*/
    USBD_HID_DataIn, /*DataIn*/
    USBD_HID_DataOut, /*DataOut*/
    NULL, /*SOF */
    NULL,
    NULL,      
    USBD_HID_GetCfgDesc,
};
   
#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN static uint32_t  USBD_HID_AltSet  __ALIGN_END = 0; 

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN static uint32_t  USBD_HID_Protocol  __ALIGN_END = 0;

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN static uint32_t  USBD_HID_IdleState __ALIGN_END = 0;

/* USB HID device Configuration Descriptor */
#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN static uint8_t USBD_HID_CfgDesc[USB_HID_CONFIG_DESC_SIZ] __ALIGN_END =
{
    0x09,         /* bLength: Configuration Descriptor size */
    USB_CONFIGURATION_DESCRIPTOR_TYPE,  /* bDescriptorType: Configuration */
    USB_HID_CONFIG_DESC_SIZ, 0x00,      /* wTotalLength: Bytes returned */
    0x01,         /*bNumInterfaces: 1 interface*/
    0x01,         /*bConfigurationValue: Configuration value*/
    0x00,         /*iConfiguration: Index of string descriptor describing the configuration*/
    0xE0,         /*bmAttributes: bus powered and Support Remote Wake-up */
    0x32,         /*MaxPower 100 mA: this current is used for detecting Vbus*/
    
    /************** Descriptor of Keyboard interface ****************/
    /* 09 */
    0x09,         /*bLength: Interface Descriptor size*/
    USB_INTERFACE_DESCRIPTOR_TYPE,/*bDescriptorType: Interface descriptor type*/
    0x00,         /*bInterfaceNumber: Number of Interface*/
    0x00,         /*bAlternateSetting: Alternate setting*/
    0x02,         /*bNumEndpoints*/
    0x03,         /*bInterfaceClass: HID*/
    0x01,         /*bInterfaceSubClass : 1=BOOT, 0=no boot*/
    0x01,         /*nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse*/
    0x00,         /*iInterface: Index of string descriptor*/
    
    /******************** Descriptor of Keyboard HID ********************/
    /* 18 */
    0x09,         /*bLength: HID Descriptor size*/
    HID_DESCRIPTOR_TYPE, /*bDescriptorType: HID*/
    0x11, 0x01,   /*bcdHID: HID Class Spec release number*/
    0x00,         /*bCountryCode: Hardware target country*/
    0x01,         /*bNumDescriptors: Number of HID class descriptors to follow*/
    0x22,         /*bDescriptorType*/
    HID_MOUSE_REPORT_DESC_SIZE,/*wItemLength: Total length of Report descriptor*/
    0x00,
    
    /******************** Descriptor of Keyboard endpoint ********************/
    /* 27 */
    0x07,          /*bLength: Endpoint Descriptor size*/
    USB_ENDPOINT_DESCRIPTOR_TYPE, /*bDescriptorType:*/
    
    HID_IN_EP,     /*bEndpointAddress: Endpoint Address (IN)*/
    0x03,          /*bmAttributes: Interrupt endpoint*/
    HID_IN_PACKET, /*wMaxPacketSize: 8 Byte max */
    0x00,
    HID_FS_BINTERVAL,          /*bInterval: Polling Interval (10 ms)*/
    /* 34 */
    0x07,          /*bLength: Endpoint Descriptor size*/
    USB_ENDPOINT_DESCRIPTOR_TYPE, /*bDescriptorType:*/
    
    HID_OUT_EP,     /*bEndpointAddress: Endpoint Address (IN)*/
    0x03,          /*bmAttributes: Interrupt endpoint*/
    HID_OUT_PACKET, /*wMaxPacketSize: 8 Byte max */
    0x00,
    HID_FS_BINTERVAL,          /*bInterval: Polling Interval (10 ms)*/
    /* 41 */
} ;

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN static uint8_t HID_MOUSE_ReportDesc[HID_MOUSE_REPORT_DESC_SIZE] __ALIGN_END =
{
    0x05,0x01,// Global Generic Desktop
    0x09,0x06,// Local KeyBoard 
    0xA1,0x01,// Main app collection
    0x05,0x07,// Global KeyBoard
    //////////////////////////////////第1字节
    0x19,0xe0,// Local Usage Min (KeyBoard LeftControl)
    0x29,0xe7,// Local Usage Max (KeyBoard Right GUI)
    0x15,0x00,// Global Logical Min
    0x25,0x01,// Global Logical Max 
    0x95,0x08,// Global ReportCount
    0x75,0x01,// Global ReportSize
    0x81,0x02,// Main Input(Data,Var,Abs)
    //////////////////////////////////第2字节
    0x95,0x01,// Global ReportCount
    0x75,0x08,// Global ReportSize
    0x81,0x03,// Main Input(Cnst,Var,Abs)
    //////////////////////////////////第3-8字节
    0x95,0x06,// Global ReportCount
    0x75,0x08,// Global ReportSize
    0x15,0x00,// Global Logical Min
    0x26,0xff,0x00,//Global Logical Max
    0x19,0x00,// Local Usage Min
    0x29,0x65,// Local Usage Max
    0x81,0x00,// Main Output(Data,Ary,Abs)
    ////////////////////////////////1字节输出报告
    0x15,0x00,// Global Logical Min
    0x25,0x01,// Global Logical Max
    0x95,0x05,// Global ReportCount
    0x75,0x01,// Global ReportSize
    0x05,0x08,// Global LED
    0x19,0x01,// Local Usage Min
    0x29,0x05,// Local Usage Max
    0x91,0x02,// Main Output(Data,Var,Abs)
    ////////////////////////////////补足上面变成1个字节
    0x95,0x01,// Global ReportCount
    0x75,0x03,// Global ReportSize
    0x91,0x03,// Main Output(Cnst,Var,Abs)
    0xc0      // Main End collection
}; 

static uint8_t buff[HID_OUT_PACKET];

static uint8_t rReportBuff[HID_OUT_PACKET];
static uint8_t rReportLen;

/**
  * @brief  USBD_HID_Init
  *         Initialize the HID interface
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
uint8_t  USBD_HID_Init (void  *pdev, uint8_t cfgidx)
{
    /* Open EP IN */
    DCD_EP_Open(pdev, HID_IN_EP, HID_IN_PACKET, USB_OTG_EP_INT);
    DCD_EP_Open(pdev, HID_OUT_EP, HID_OUT_PACKET, USB_OTG_EP_INT);
    
    DCD_EP_PrepareRx(pdev, HID_OUT_EP, buff, HID_OUT_PACKET);
    
    return USBD_OK;
}

/**
  * @brief  USBD_HID_Init
  *         DeInitialize the HID layer
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
uint8_t  USBD_HID_DeInit (void  *pdev, uint8_t cfgidx)
{
    /* Close HID EPs */
    DCD_EP_Close (pdev , HID_IN_EP);  
    DCD_EP_Close (pdev , HID_OUT_EP);  
    return USBD_OK;
}

/**
  * @brief  USBD_HID_Setup
  *         Handle the HID specific requests
  * @param  pdev: instance
  * @param  req: usb requests
  * @retval status
  */
uint8_t  USBD_HID_Setup (void  *pdev,  USB_SETUP_REQ *req)
{
    uint16_t len = 0;
    uint8_t  *pbuf = NULL;
    
    switch (req->bmRequest & USB_REQ_TYPE_MASK)
    {
    case USB_REQ_TYPE_CLASS :  
        switch (req->bRequest)
        {
        case HID_REQ_SET_PROTOCOL:
            USBD_HID_Protocol = (uint8_t)(req->wValue);
            break;
        
        case HID_REQ_GET_PROTOCOL:
            USBD_CtlSendData (pdev, (uint8_t *)&USBD_HID_Protocol, 1);    
            break;
        
        case HID_REQ_SET_IDLE:
            USBD_HID_IdleState = (uint8_t)(req->wValue >> 8);
            break;
        
        case HID_REQ_GET_IDLE:
            USBD_CtlSendData (pdev, (uint8_t *)&USBD_HID_IdleState, 1);        
            break;      
        
        default:
            USBD_CtlError (pdev, req);
            return USBD_FAIL; 
        }
        break;
        
    case USB_REQ_TYPE_STANDARD:
        switch (req->bRequest)
        {
        case USB_REQ_GET_DESCRIPTOR: 
            if( req->wValue >> 8 == HID_REPORT_DESC)
            {
                len = MIN(HID_MOUSE_REPORT_DESC_SIZE , req->wLength);
                pbuf = HID_MOUSE_ReportDesc;
            }
            else if( req->wValue >> 8 == HID_DESCRIPTOR_TYPE)
            {
                pbuf = USBD_HID_CfgDesc + 0x12;
            }
            else
            {
                /* Do Nothing */
            }
            USBD_CtlSendData (pdev, pbuf, len);
            break;
        
        case USB_REQ_GET_INTERFACE :
            USBD_CtlSendData (pdev, (uint8_t *)&USBD_HID_AltSet, 1);
            break;
        
        case USB_REQ_SET_INTERFACE :
            USBD_HID_AltSet = (uint8_t)(req->wValue);
            break;
        
        default:
            USBD_HID_AltSet = (uint8_t)(req->wValue);
            break; 
        }
        break;
        
    default:
        USBD_CtlSendData (pdev, (uint8_t *)&USBD_HID_AltSet, 1);
        break; 
    }

    return USBD_OK;
}

/**
  * @brief  USBD_HID_GetCfgDesc 
  *         return configuration descriptor
  * @param  speed : current device speed
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t  *USBD_HID_GetCfgDesc (uint8_t speed, uint16_t *length)
{
    *length = sizeof (USBD_HID_CfgDesc);
    return USBD_HID_CfgDesc;
}

/**
  * @brief  USBD_HID_DataIn
  *         handle data IN Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t  USBD_HID_DataIn (void  *pdev, uint8_t epnum)
{
    /* Ensure that the FIFO is empty before a new transfer, this condition could 
    be caused by  a new transfer before the end of the previous transfer */
    DCD_EP_Flush(pdev, HID_IN_EP);
    return USBD_OK;
}

/**
  * @brief  USBD_HID_DataOut
  *         handle data OUT Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t  USBD_HID_DataOut (void  *pdev, uint8_t epnum)
{
    memcpy(rReportBuff, buff, USBD_GetRxCount(pdev, HID_OUT_EP));
    rReportLen = USBD_GetRxCount(pdev, HID_OUT_EP);
    
    DCD_EP_PrepareRx(pdev, HID_OUT_EP, buff, 1);
    return USBD_OK;
}

/**
  * @brief  USBD_HID_SendReport 
  *         Send HID Report
  * @param  pdev: device instance
  * @param  buff: pointer to report
  * @retval status
  */
uint8_t USBD_HID_SendReport (USB_OTG_CORE_HANDLE  *pdev, uint8_t *report, uint16_t len)
{
    if (pdev->dev.device_status == USB_OTG_CONFIGURED )
    {
        DCD_EP_Tx (pdev, HID_IN_EP, report, len);
    }
    return USBD_OK;
}

/**
  * @brief  USBD_HID_RecvReport 
  *         Recv HID Report
  * @param  pdev: device instance
  * @param  buff: pointer to report
  * @retval status
  */
uint8_t USBD_HID_RecvReport (USB_OTG_CORE_HANDLE  *pdev, uint8_t *report, uint16_t *len)
{
    if (pdev->dev.device_status == USB_OTG_CONFIGURED )
    {
        if (rReportLen > 0)
        {
            memcpy(report, rReportBuff, rReportLen);
            *len = rReportLen;
            rReportLen = 0;
            
            return USBD_OK;
        }
    }
    return USBD_FAIL;
}

/**
  * @brief  USBD_HID_GetPollingInterval 
  *         return polling interval from endpoint descriptor
  * @param  pdev: device instance
  * @retval polling interval
  */
uint32_t USBD_HID_GetPollingInterval (USB_OTG_CORE_HANDLE *pdev)
{
    uint32_t polling_interval = 0;

    /* Sets the data transfer polling interval for low and full 
    speed transfers */
    polling_interval =  HID_FS_BINTERVAL;
    
    return ((uint32_t)(polling_interval));
}
