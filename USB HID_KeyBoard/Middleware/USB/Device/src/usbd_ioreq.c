#include "usbd_ioreq.h"

/**
* @brief  USBD_CtlSendData
*         send data on the ctl pipe
* @param  pdev: device instance
* @param  buff: pointer to data buffer
* @param  len: length of data to be sent
* @retval status
*/
USBD_Status USBD_CtlSendData(USB_OTG_CORE_HANDLE  *pdev, uint8_t *pbuf, uint16_t len)
{
    USBD_Status ret = USBD_OK;
    
    pdev->dev.in_ep[0].total_data_len = len;
    pdev->dev.in_ep[0].rem_data_len   = len;
    pdev->dev.device_state = USB_OTG_EP0_DATA_IN;

    DCD_EP_Tx (pdev, 0, pbuf, len);
  
    return ret;
}

/**
* @brief  USBD_CtlContinueSendData
*         continue sending data on the ctl pipe
* @param  pdev: device instance
* @param  buff: pointer to data buffer
* @param  len: length of data to be sent
* @retval status
*/
USBD_Status USBD_CtlContinueSendData(USB_OTG_CORE_HANDLE  *pdev, uint8_t *pbuf, uint16_t len)
{
    USBD_Status ret = USBD_OK;
    DCD_EP_Tx (pdev, 0, pbuf, len);
    
    return ret;
}

/**
* @brief  USBD_CtlPrepareRx
*         receive data on the ctl pipe
* @param  pdev: USB OTG device instance
* @param  buff: pointer to data buffer
* @param  len: length of data to be received
* @retval status
*/
USBD_Status USBD_CtlPrepareRx(USB_OTG_CORE_HANDLE  *pdev, uint8_t *pbuf, uint16_t len)
{
    USBD_Status ret = USBD_OK;
    
    pdev->dev.out_ep[0].total_data_len = len;
    pdev->dev.out_ep[0].rem_data_len   = len;
    pdev->dev.device_state = USB_OTG_EP0_DATA_OUT;
    DCD_EP_PrepareRx (pdev, 0, pbuf, len);

    return ret;
}

/**
* @brief  USBD_CtlContinueRx
*         continue receive data on the ctl pipe
* @param  pdev: USB OTG device instance
* @param  buff: pointer to data buffer
* @param  len: length of data to be received
* @retval status
*/
USBD_Status USBD_CtlContinueRx(USB_OTG_CORE_HANDLE  *pdev, uint8_t *pbuf, uint16_t len)
{
    USBD_Status ret = USBD_OK;
    
    DCD_EP_PrepareRx (pdev, 0, pbuf, len);
    
    return ret;
}

/**
* @brief  USBD_CtlSendStatus
*         send zero length packet on the ctl pipe
* @param  pdev: USB OTG device instance
* @retval status
*/
USBD_Status USBD_CtlSendStatus(USB_OTG_CORE_HANDLE  *pdev)
{
    USBD_Status ret = USBD_OK;

    pdev->dev.device_state = USB_OTG_EP0_STATUS_IN;
    DCD_EP_Tx (pdev, 0, NULL, 0); 
    USB_OTG_EP0_OutStart(pdev);  
    
    return ret;
}

/**
* @brief  USBD_CtlReceiveStatus
*         receive zero length packet on the ctl pipe
* @param  pdev: USB OTG device instance
* @retval status
*/
USBD_Status USBD_CtlReceiveStatus(USB_OTG_CORE_HANDLE  *pdev)
{
    USBD_Status ret = USBD_OK;
    
    pdev->dev.device_state = USB_OTG_EP0_STATUS_OUT;  
    DCD_EP_PrepareRx(pdev, 0, NULL, 0);  
    USB_OTG_EP0_OutStart(pdev);
    
    return ret;
}

/**
* @brief  USBD_GetRxCount
*         returns the received data length
* @param  pdev: USB OTG device instance
*         epnum: endpoint index
* @retval Rx Data blength
*/
uint16_t  USBD_GetRxCount (USB_OTG_CORE_HANDLE  *pdev , uint8_t epnum)
{
    return pdev->dev.out_ep[epnum].xfer_count;
}
