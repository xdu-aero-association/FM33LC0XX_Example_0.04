// BOT: Bulk-only Transport
// CBW: Command Block Wrapper
// CSW: Command Status Wrapper

#include "msc_bot.h"
#include "msc_scsi.h"
#include "msc_mem.h"
#include "usbd_ioreq.h"

uint16_t MSC_BOT_DataLen;
uint8_t MSC_BOT_State;
uint8_t MSC_BOT_Status;

#ifdef USB_DATA_STRUCT_ALIGNED
  #if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4   
  #endif
#endif /* USB_DATA_STRUCT_ALIGNED */
__ALIGN_BEGIN uint8_t MSC_BOT_Data[MSC_MEDIA_PACKET] __ALIGN_END ; 

#ifdef USB_DATA_STRUCT_ALIGNED
  #if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4   
  #endif
#endif /* USB_DATA_STRUCT_ALIGNED */
__ALIGN_BEGIN MSC_BOT_CBW_TypeDef MSC_BOT_cbw __ALIGN_END ;

#ifdef USB_DATA_STRUCT_ALIGNED
  #if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4   
  #endif
#endif /* USB_DATA_STRUCT_ALIGNED */
__ALIGN_BEGIN MSC_BOT_CSW_TypeDef MSC_BOT_csw __ALIGN_END ;

static void MSC_BOT_CBW_Decode(void *pdev);
static void MSC_BOT_SendData(void *pdev, uint8_t* pbuf, uint16_t len);
static void MSC_BOT_Abort(void *pdev);

/**
* @brief  MSC_BOT_Init
*         Initialize the BOT Process
* @param  pdev: device instance
* @retval None
*/
void MSC_BOT_Init(void *pdev)
{
    MSC_BOT_State = BOT_IDLE;
    MSC_BOT_Status = BOT_STATE_NORMAL;
    USBD_STORAGE_fops->Init(0);

    DCD_EP_Flush(pdev, MSC_OUT_EP);
    DCD_EP_Flush(pdev, MSC_IN_EP);

    /* Prapare EP to Receive First BOT Cmd */
    DCD_EP_PrepareRx(pdev, MSC_OUT_EP, (uint8_t *)&MSC_BOT_cbw, BOT_CBW_LENGTH);    
}

/**
* @brief  MSC_BOT_Reset
*         Reset the BOT Machine
* @param  pdev: device instance
* @retval  None
*/
void MSC_BOT_Reset(void *pdev)
{
    MSC_BOT_State = BOT_IDLE;
    MSC_BOT_Status = BOT_STATE_RECOVERY;
    /* Prapare EP to Receive First BOT Cmd */
    DCD_EP_PrepareRx (pdev, MSC_OUT_EP, (uint8_t *)&MSC_BOT_cbw, BOT_CBW_LENGTH);    
}

/**
* @brief  MSC_BOT_DeInit
*         Uninitialize the BOT Machine
* @param  pdev: device instance
* @retval None
*/
void MSC_BOT_DeInit(void  *pdev)
{
    MSC_BOT_State = BOT_IDLE;
}

/**
* @brief  MSC_BOT_DataIn
*         Handle BOT IN data stage
* @param  pdev: device instance
* @param  epnum: endpoint index
* @retval None
*/
void MSC_BOT_DataIn(void *pdev, uint8_t epnum)
{
    switch (MSC_BOT_State)
    {
    case BOT_DATA_IN:
        if(SCSI_ProcessCmd(pdev, MSC_BOT_cbw.bLUN, &MSC_BOT_cbw.CB[0]) < 0)
        {
            MSC_BOT_SendCSW(pdev, CSW_CMD_FAILED);
        }
        break;

    case BOT_SEND_DATA:
    case BOT_LAST_DATA_IN:
        MSC_BOT_SendCSW(pdev, CSW_CMD_PASSED);
        break;

    default:
        break;
    }
}

/**
* @brief  MSC_BOT_DataOut
*         Proccess MSC OUT data
* @param  pdev: device instance
* @param  epnum: endpoint index
* @retval None
*/
void MSC_BOT_DataOut(void *pdev, uint8_t epnum)
{
    switch (MSC_BOT_State)
    {
    case BOT_IDLE:
        MSC_BOT_CBW_Decode(pdev);
        break;

    case BOT_DATA_OUT:
        if(SCSI_ProcessCmd(pdev, MSC_BOT_cbw.bLUN, &MSC_BOT_cbw.CB[0]) < 0)
        {
            MSC_BOT_SendCSW(pdev, CSW_CMD_FAILED);
        }
        break;

    default:
        break;
    }
}

/**
* @brief  MSC_BOT_CBW_Decode
*         Decode the CBW command and set the BOT state machine accordingtly  
* @param  pdev: device instance
* @retval None
*/
static void MSC_BOT_CBW_Decode(void *pdev)
{
    MSC_BOT_csw.dTag = MSC_BOT_cbw.dTag;
    MSC_BOT_csw.dDataResidue = MSC_BOT_cbw.dDataLength;

    if ((USBD_GetRxCount(pdev ,MSC_OUT_EP) != BOT_CBW_LENGTH) ||
        (MSC_BOT_cbw.dSignature != BOT_CBW_SIGNATURE)||
        (MSC_BOT_cbw.bLUN > 1) || 
        (MSC_BOT_cbw.bCBLength < 1) || 
        (MSC_BOT_cbw.bCBLength > 16))
    {
        SCSI_SenseCode(MSC_BOT_cbw.bLUN, ILLEGAL_REQUEST, INVALID_CDB);
        MSC_BOT_Status = BOT_STATE_ERROR;   
        MSC_BOT_Abort(pdev);
    }
    else
    {
        if(SCSI_ProcessCmd(pdev, MSC_BOT_cbw.bLUN, &MSC_BOT_cbw.CB[0]) < 0)
        {
            MSC_BOT_Abort(pdev);
        }
        /*Burst xfer handled internally*/
        else if ((MSC_BOT_State != BOT_DATA_IN) && 
                 (MSC_BOT_State != BOT_DATA_OUT) &&
                 (MSC_BOT_State != BOT_LAST_DATA_IN)) 
        {
            if (MSC_BOT_DataLen > 0)
            {
                MSC_BOT_SendData(pdev, MSC_BOT_Data, MSC_BOT_DataLen);
            }
            else if (MSC_BOT_DataLen == 0) 
            {
                MSC_BOT_SendCSW(pdev, CSW_CMD_PASSED);
            }
        }
    }
}

/**
* @brief  MSC_BOT_SendData
*         Send the requested data
* @param  pdev: device instance
* @param  buf: pointer to data buffer
* @param  len: Data Length
* @retval None
*/
static void MSC_BOT_SendData(void *pdev, uint8_t *buf, uint16_t len)
{
    len = MIN(MSC_BOT_cbw.dDataLength, len);
    MSC_BOT_csw.dDataResidue -= len;
    MSC_BOT_csw.bStatus = CSW_CMD_PASSED;
    MSC_BOT_State = BOT_SEND_DATA;

    DCD_EP_Tx(pdev, MSC_IN_EP, buf, len);  
}

/**
* @brief  MSC_BOT_SendCSW
*         Send the Command Status Wrapper
* @param  pdev: device instance
* @param  status : CSW status
* @retval None
*/
void  MSC_BOT_SendCSW(void *pdev, uint8_t CSW_Status)
{
    MSC_BOT_csw.dSignature = BOT_CSW_SIGNATURE;
    MSC_BOT_csw.bStatus = CSW_Status;
    MSC_BOT_State = BOT_IDLE;
  
    DCD_EP_Tx(pdev, MSC_IN_EP, (uint8_t *)&MSC_BOT_csw, BOT_CSW_LENGTH);

    /* Prepare EP to Receive next Cmd */
    DCD_EP_PrepareRx(pdev, MSC_OUT_EP, (uint8_t *)&MSC_BOT_cbw, BOT_CBW_LENGTH);  
}

/**
* @brief  MSC_BOT_Abort
*         Abort the current transfer
* @param  pdev: device instance
* @retval status
*/
static void MSC_BOT_Abort(void  *pdev)
{
    if ((MSC_BOT_cbw.bmFlags == 0) && 
        (MSC_BOT_cbw.dDataLength != 0) &&
        (MSC_BOT_Status == BOT_STATE_NORMAL) )
    {
        DCD_EP_Stall(pdev, MSC_OUT_EP );
    }
    DCD_EP_Stall(pdev, MSC_IN_EP);

    if (MSC_BOT_Status == BOT_STATE_ERROR)
    {
        DCD_EP_PrepareRx(pdev, MSC_OUT_EP, (uint8_t *)&MSC_BOT_cbw, BOT_CBW_LENGTH);    
    }
}

/**
* @brief  MSC_BOT_CplClrFeature
*         Complete the clear feature request
* @param  pdev: device instance
* @param  epnum: endpoint index
* @retval None
*/
void  MSC_BOT_CplClrFeature(void *pdev, uint8_t epnum)
{
    /* Bad CBW Signature */
    if (MSC_BOT_Status == BOT_STATE_ERROR )
    {
        DCD_EP_Stall(pdev, MSC_IN_EP);
        MSC_BOT_Status = BOT_STATE_NORMAL;    
    }
    else if(((epnum & 0x80) == 0x80) && 
            (MSC_BOT_Status != BOT_STATE_RECOVERY))
    {
        MSC_BOT_SendCSW(pdev, CSW_CMD_FAILED);
    }
}
