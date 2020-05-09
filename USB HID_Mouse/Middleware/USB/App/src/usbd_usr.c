#include "usbd_usr.h"

// 用户回调函数
USBD_Usr_cb_TypeDef USR_cb = {
    USBD_USR_Init,
    USBD_USR_DeviceReset,
    USBD_USR_DeviceConfigured,
    USBD_USR_DeviceSuspended,
    USBD_USR_DeviceResumed,

    USBD_USR_DeviceConnected,
    USBD_USR_DeviceDisconnected,
};


#define USER_INFORMATION1      (uint8_t*)"[Key]:RemoteWakeup"
#define USER_INFORMATION2      (uint8_t*)"[Joystick]:Mouse emulation"

/**
* @brief  USBD_USR_Init 
*         Displays the message by Debug for USB initialization
* @param  None
* @retval None
*/
void USBD_USR_Init(void)
{
    
}

/**
* @brief  USBD_USR_DeviceReset 
*         Displays the message by Debug on device Reset Event 
* @param  speed : device speed
* @retval None
*/
void USBD_USR_DeviceReset(uint8_t speed)
{
    
}


/**
* @brief  USBD_USR_DeviceConfigured
*         Displays the message by Debug on device configuration Event
* @param  None
* @retval Status
*/
void USBD_USR_DeviceConfigured(void)
{
    
}

/**
* @brief  USBD_USR_DeviceSuspended 
*         Displays the message by Debug on device suspend Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceSuspended(void)
{

}


/**
* @brief  USBD_USR_DeviceResumed 
*         Displays the message by Debug on device resume Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceResumed(void)
{

}


/**
* @brief  USBD_USR_DeviceConnected
*         Displays the message by Debug on device connection Event
* @param  None
* @retval Status
*/
void USBD_USR_DeviceConnected(void)
{

}


/**
* @brief  USBD_USR_DeviceDisonnected
*         Displays the message by Debug on device disconnection Event
* @param  None
* @retval Status
*/
void USBD_USR_DeviceDisconnected(void)
{

}
