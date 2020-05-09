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

#include "hid_core.h"
#include "usbd_desc.h"
#include "usbd_req.h"


uint8_t  USBD_HID_Init (void  *pdev, uint8_t cfgidx);
uint8_t  USBD_HID_DeInit (void  *pdev, uint8_t cfgidx);
uint8_t  USBD_HID_Setup (void  *pdev, USB_SETUP_REQ *req);
static uint8_t  *USBD_HID_GetCfgDesc (uint8_t speed, uint16_t *length);
uint8_t  USBD_HID_DataIn (void  *pdev, uint8_t epnum);

USBD_Class_cb_TypeDef  USBD_HID_cb = 
{
    USBD_HID_Init,
    USBD_HID_DeInit,
    USBD_HID_Setup,
    NULL, /*EP0_TxSent*/  
    NULL, /*EP0_RxReady*/
    USBD_HID_DataIn, /*DataIn*/
    NULL, /*DataOut*/
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
    0x09, /* bLength: Configuration Descriptor size */
    USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType: Configuration */
    USB_HID_CONFIG_DESC_SIZ,
    /* wTotalLength: Bytes returned */
    0x00,
    0x01,         /*bNumInterfaces: 1 interface*/
    0x01,         /*bConfigurationValue: Configuration value*/
    0x00,         /*iConfiguration: Index of string descriptor describing
    the configuration*/
    0xE0,         /*bmAttributes: bus powered and Support Remote Wake-up */
    0x32,         /*MaxPower 100 mA: this current is used for detecting Vbus*/
    
    /************** Descriptor of Joystick Mouse interface ****************/
    /* 09 */
    0x09,         /*bLength: Interface Descriptor size*/
    USB_INTERFACE_DESCRIPTOR_TYPE,/*bDescriptorType: Interface descriptor type*/
    0x00,         /*bInterfaceNumber: Number of Interface*/
    0x00,         /*bAlternateSetting: Alternate setting*/
    0x01,         /*bNumEndpoints*/
    0x03,         /*bInterfaceClass: HID*/
    0x01,         /*bInterfaceSubClass : 1=BOOT, 0=no boot*/
    0x02,         /*nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse*/
    0,            /*iInterface: Index of string descriptor*/
    /******************** Descriptor of Joystick Mouse HID ********************/
    /* 18 */
    0x09,         /*bLength: HID Descriptor size*/
    HID_DESCRIPTOR_TYPE, /*bDescriptorType: HID*/
    0x11,         /*bcdHID: HID Class Spec release number*/
    0x01,
    0x00,         /*bCountryCode: Hardware target country*/
    0x01,         /*bNumDescriptors: Number of HID class descriptors to follow*/
    0x22,         /*bDescriptorType*/
    HID_MOUSE_REPORT_DESC_SIZE,/*wItemLength: Total length of Report descriptor*/
    0x00,
    /******************** Descriptor of Mouse endpoint ********************/
    /* 27 */
    0x07,          /*bLength: Endpoint Descriptor size*/
    USB_ENDPOINT_DESCRIPTOR_TYPE, /*bDescriptorType:*/
    
    HID_IN_EP,     /*bEndpointAddress: Endpoint Address (IN)*/
    0x03,          /*bmAttributes: Interrupt endpoint*/
    HID_IN_PACKET, /*wMaxPacketSize: 4 Byte max */
    0x00,
    HID_FS_BINTERVAL,          /*bInterval: Polling Interval (10 ms)*/
    /* 34 */
} ;

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif
__ALIGN_BEGIN static uint8_t HID_MOUSE_ReportDesc[HID_MOUSE_REPORT_DESC_SIZE] __ALIGN_END =
{
    0x05,   0x01,   // Usage Page(Generic Desktop)
    0x09,   0x02,   // Usage(Mouse)
    0xA1,   0x01,   //  Collection(Application)
    0x09,   0x01,   //      Usage(Pointer)
    0xA1,   0x00,   //      Collection(Physical)
    0x05,   0x09,   //          Usage Page(Buttons)
    0x19,   0x01,   //          Usage Minimum(01)
    0x29,   0x03,   //          Usage Maximum(03)
    0x15,   0x00,   //          Logical Minimum(0)
    0x25,   0x01,   //          Logical Maximum(1)
    
    0x95,   0x03,   //          Report Count(3)
    0x75,   0x01,   //          Report Size(1)
    0x81,   0x02,   //          Input(Data, Variable, Absolute) ;3 button bits
    
    0x95,   0x01,   //          Report Count(1)
    0x75,   0x05,   //          Report Size(5)
    0x81,   0x01,   //          Input(Constant) ; 5 bit padding
    
    0x05,   0x01,   //          Usage Page(Generic Desktop)
    0x09,   0x30,   //          Usage(X)
    0x09,   0x31,   //          Usage(Y)
    0x09,   0x38,   //          Usage(Wheel)
    0x15,   0x81,   //          Logical Minimum(-127)
    0x25,   0x7F,   //          Logical Maximum(127)
    
    0x75,   0x08,   //          Report Size(8)
    0x95,   0x03,   //          Report Count(3)
    0x81,   0x06,   //          Input(Data, Variable, Relative) ;2 position byte(X & Y) 
    
    0xC0,           //      End Collection   
    0x09,   0x3c,   //      Usage(Motion WakeUp)
    0x05,   0xff,   //      Usage Page(Reserved)
    0x09,   0x01,   //      Usage(Pointer)
    0x15,   0x00,   //      Logical Minimum(0)
    0x25,   0x01,   //      Logical Maximum(1)
    0x75,   0x01,   //      Report Size(1)
    0x95,   0x02,   //      Report Count(2)
    0xb1,   0x22,   //      Feature()
    0x75,   0x06,   //      Report Size(6)
    0x95,   0x01,   //      Report Count(1)
    0xb1,   0x01,   //      Feature()
    0xc0,           //  End Collection
}; 

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
uint8_t  USBD_HID_DataIn (void  *pdev, uint8_t epnum)
{
    /* Ensure that the FIFO is empty before a new transfer, this condition could 
    be caused by  a new transfer before the end of the previous transfer */
    DCD_EP_Flush(pdev, HID_IN_EP);
    return USBD_OK;
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

