#include <string.h>
#include "cdc_vcp.h"
#include "usbd_desc.h"
#include "usbd_req.h"
#include "main.h"
#include "user_init.h"

DataStream USBRxStream;
DataStream USBTxStream;

#define BUFF_LEN        1024
static uint8_t rxBuff[BUFF_LEN];
static uint8_t txBuff[BUFF_LEN];

LINE_CODING linecoding = {
    115200, /* baud rate */
    0x00,   /* stop bits-1 */
    0x00,   /* parity - none */
    0x08    /* nb. of bits 8 */
}; // 串口参数设定

static uint16_t VCP_Init(void);	
static uint16_t VCP_DeInit(void);
static uint16_t VCP_Ctrl(uint32_t Cmd, uint8_t * Buf, uint32_t Len);
static uint16_t VCP_DataTx(uint8_t *Buf, uint16_t Len);
static uint16_t VCP_DataRx(uint8_t *Buf, uint16_t Len);
static uint16_t VCP_COMConfig(uint8_t Conf);

CDC_IF_Prop_TypeDef VCP_fops = {
    VCP_Init,
    VCP_DeInit,
    VCP_Ctrl,
    VCP_DataTx,
    VCP_DataRx
};//接口回调函数

void UART1_Init(void)
{
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_UART_InitTypeDef UART_InitStruct = {0};    
    
    UART_InitStruct.ClockSrc = LL_RCC_UART_OPERATION_CLOCK_SOURCE_APBCLK1;
    UART_InitStruct.BaudRate = 115200;
    UART_InitStruct.DataWidth = LL_UART_DATAWIDTH_8B;
    UART_InitStruct.StopBits = LL_UART_STOPBITS_1;
    UART_InitStruct.Parity = LL_UART_PARITY_NONE;
    UART_InitStruct.TransferDirection = LL_UART_DIRECTION_TX_RX;
    UART_InitStruct.InfraredModulation = DISABLE;
    LL_UART_Init(UART1, &UART_InitStruct);
    
    LL_UART_EnableIT_ReceiveBuffFull(UART1);
    LL_UART_EnableIT_TxBuffEmpty(UART1);
    
    NVIC_DisableIRQ(UART1_IRQn);
    NVIC_SetPriority(UART1_IRQn, 2);
	NVIC_EnableIRQ(UART1_IRQn);
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_3;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void UART1_DeInit(void)
{
    LL_UART_DisableDirectionTx(UART1);
    LL_UART_DisableDirectionRx(UART1);
}

void UART1_IRQHandler(void)
{
    uint8_t temp;
    
    // RX
    if (LL_UART_IsActiveFlag_RXBF(UART1))
    {
        temp = LL_UART_ReceiveData(UART1);
        StreamWriteData(&USBTxStream, &temp, 1);
    }
    
    // TX
    if (LL_UART_IsActiveFlag_TXBE(UART1))
    {
        if (StreamReadData(&USBRxStream, &temp, 1))
        {
            LL_UART_TransmitData(UART1, temp);
        }
        else
        {
            LL_UART_DisableIT_TxBuffEmpty(UART1);
        }
    }
}

/**
  * @brief  VCP_Init
  *         Initializes the Media on the FM33xx
  * @param  None
  * @retval Result of the operation (USBD_OK in all cases)
  */
static uint16_t VCP_Init(void)
{
    StreamInit(&USBRxStream, rxBuff, BUFF_LEN);
    StreamInit(&USBTxStream, txBuff, BUFF_LEN);
    
    UART1_Init();
    
    return USBD_OK;
}

/**
  * @brief  VCP_DeInit
  *         DeInitializes the Media on the FM33xx
  * @param  None
  * @retval Result of the operation (USBD_OK in all cases)
  */
static uint16_t VCP_DeInit(void)
{
    UART1_DeInit();
    
    return USBD_OK;
}


/**
  * @brief  VCP_Ctrl
  *         Manage the CDC class requests
  * @param  Cmd: Command code            
  * @param  Buf: Buffer containing command data (request parameters)
  * @param  Len: Number of data to be sent (in bytes)
  * @retval Result of the operation (USBD_OK in all cases)
  */
static uint16_t VCP_Ctrl(uint32_t Cmd, uint8_t * Buf, uint32_t Len)
{
    // TODO: Need judge "*Buf" is NULL? 
    
    switch (Cmd)
    {
    case SEND_ENCAPSULATED_COMMAND:
        /* Not needed for this driver */
        break;

    case GET_ENCAPSULATED_RESPONSE:
        /* Not needed for this driver */
        break;

    case SET_COMM_FEATURE:
        /* Not needed for this driver */
        break;

    case GET_COMM_FEATURE:
        /* Not needed for this driver */
        break;

    case CLEAR_COMM_FEATURE:
        /* Not needed for this driver */
        break;

    case SET_LINE_CODING://设置串口参数，波特率等
        linecoding.bitrate = (Buf[0] & 0xff) << 0;
        linecoding.bitrate |= (Buf[1] & 0xff) << 8;
        linecoding.bitrate |= (Buf[2] & 0xff) << 16;
        linecoding.bitrate |= (Buf[3] & 0xff) << 24;
        linecoding.format = Buf[4];
        linecoding.paritytype = Buf[5];
        linecoding.datatype = Buf[6];
        /* Set the new configuration */
        VCP_COMConfig(OTHER_CONFIG);
        break;

    case GET_LINE_CODING:
        Buf[0] = (uint8_t) (linecoding.bitrate);
        Buf[1] = (uint8_t) (linecoding.bitrate >> 8);
        Buf[2] = (uint8_t) (linecoding.bitrate >> 16);
        Buf[3] = (uint8_t) (linecoding.bitrate >> 24);
        Buf[4] = linecoding.format;
        Buf[5] = linecoding.paritytype;
        Buf[6] = linecoding.datatype;
        break;

    case SET_CONTROL_LINE_STATE:
        /* Not needed for this driver */
        break;

    case SEND_BREAK:
        /* Not needed for this driver */
        break;

    default:
        break;
    }

    return USBD_OK;
}

/**
  * @brief  VCP_COMConfig
  *         Configure the COM Port with default values or values received from host.
  * @param  Conf: can be DEFAULT_CONFIG to set the default configuration or OTHER_CONFIG
  *         to set a configuration received from the host.
  * @retval None.
  */
static uint16_t VCP_COMConfig(uint8_t Conf)
{
    uint16_t status = USBD_OK;
    
    LL_UART_InitTypeDef UART_InitStruct = {0};    
    
    UART_InitStruct.ClockSrc = LL_RCC_UART_OPERATION_CLOCK_SOURCE_APBCLK1;
    UART_InitStruct.BaudRate = 115200;
    UART_InitStruct.DataWidth = LL_UART_DATAWIDTH_8B;
    UART_InitStruct.Parity = LL_UART_PARITY_NONE;
    UART_InitStruct.StopBits = LL_UART_STOPBITS_1;
    UART_InitStruct.TransferDirection = LL_UART_DIRECTION_TX_RX;
    UART_InitStruct.InfraredModulation = DISABLE;
    
    if (Conf != DEFAULT_CONFIG)
    {
        switch (linecoding.bitrate)
        {
            case 9600: UART_InitStruct.BaudRate = 9600; break;
            case 57600: UART_InitStruct.BaudRate = 57600; break;
            case 115200: UART_InitStruct.BaudRate = 115200; break;
            default: status = USBD_FAIL; break; 
        }
        
        switch (linecoding.datatype)
        {
            case 7: UART_InitStruct.DataWidth = LL_UART_DATAWIDTH_7B; break;
            case 8: UART_InitStruct.DataWidth = LL_UART_DATAWIDTH_8B; break;
            case 9: UART_InitStruct.DataWidth = LL_UART_DATAWIDTH_9B; break;
            case 6: UART_InitStruct.DataWidth = LL_UART_DATAWIDTH_6B; break;
            default: status = USBD_FAIL; break; 
        }   
        
        switch (linecoding.paritytype)
        {
            case 0: UART_InitStruct.Parity = LL_UART_PARITY_NONE; break;
            case 1: UART_InitStruct.Parity = LL_UART_PARITY_EVEN; break;
            case 2: UART_InitStruct.Parity = LL_UART_PARITY_ODD; break;
            default: status = USBD_FAIL; break; 
        }
        
        switch (linecoding.format)
        {
            case 0: UART_InitStruct.StopBits = LL_UART_STOPBITS_1; break;
            case 2: UART_InitStruct.StopBits = LL_UART_STOPBITS_2; break;
            default: status = USBD_FAIL; break; 
        }
    }
    
    LL_UART_Init(UART1, &UART_InitStruct);
    
    return status;
}

/**
  * @brief  VCP_DataTx
  *         CDC received data to be send over USB IN endpoint are managed in 
  *         this function.
  * @param  Buf: Buffer of data to be sent
  * @param  Len: Number of data to be sent (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else VCP_FAIL
  */
static uint16_t VCP_DataTx(uint8_t *Buf, uint16_t Len)
{
    return Len;
}

/**
  * @brief  VCP_DataRx
  *         Data received over USB OUT endpoint are sent over CDC interface 
  *         through this function.
  *         @note
  *         This function will block any OUT packet reception on USB endpoint 
  *         until exiting this function. If you exit this function before transfer
  *         is complete on CDC interface (ie. using DMA controller) it will result 
  *         in receiving more data while previous ones are still not sent.    
  * @param  Buf: Buffer of data received
  * @param  Len: Number of data received (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else VCP_FAIL
  */
static uint16_t VCP_DataRx(uint8_t *Buf, uint16_t Len)
{
    LL_UART_EnableIT_TxBuffEmpty(UART1);
    return Len;
}
