#include "usb_core.h"
#include "usb_bsp.h"

/**
* @brief  USB_OTG_EnableCommonInt
*         Initializes the commmon interrupts, used in both device and modes
* @param  pdev : Selected device
* @retval None
*/
static void USB_OTG_EnableCommonInt(USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_GINTMSK_TypeDef  int_mask;
    int_mask.d32 = 0;
    
    /* Clear any pending interrupts */
    USB_OTG_WRITE_REG32( &pdev->regs.GREGS->GINTSTS, 0xBFFFFFFF);
    
    /* Enable the interrupts in the INTMSK */
    int_mask.b.wkupintr = 1;
    int_mask.b.usbsuspend = 1;

    USB_OTG_WRITE_REG32( &pdev->regs.GREGS->GINTMSK, int_mask.d32);
}

/**
* @brief  USB_OTG_CoreReset : Soft reset of the core
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
static USB_OTG_STS USB_OTG_CoreReset(USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_STS status = USB_OTG_OK;
    __IO USB_OTG_GRSTCTL_TypeDef  greset;
    uint32_t count = 0;

    greset.d32 = 0;
    /* Wait for AHB master IDLE state. */
    do
    {
        USB_OTG_BSP_uDelay(3);
        greset.d32 = USB_OTG_READ_REG32(&pdev->regs.GREGS->GRSTCTL);
        if (++count > 200000)
        {
            return USB_OTG_OK;
        }
    }
    while (greset.b.ahbidle == 0);
    /* Core Soft Reset */
    count = 0;
    greset.b.csftrst = 1;
    USB_OTG_WRITE_REG32(&pdev->regs.GREGS->GRSTCTL, greset.d32 );
    do
    {
        greset.d32 = USB_OTG_READ_REG32(&pdev->regs.GREGS->GRSTCTL);
        if (++count > 200000)
        {
            break;
        }
    }
    while (greset.b.csftrst == 1);
    /* Wait for 3 PHY Clocks*/
    USB_OTG_BSP_uDelay(3);
    return status;
}

/**
* @brief  USB_OTG_WritePacket : Writes a packet into the Tx FIFO associated
*         with the EP
* @param  pdev : Selected device
* @param  src : source pointer
* @param  ch_ep_num : end point number
* @param  bytes : No. of bytes
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_WritePacket(USB_OTG_CORE_HANDLE *pdev,
                                uint8_t *src,
                                uint8_t ch_ep_num,
                                uint16_t len)
{
    USB_OTG_STS status = USB_OTG_OK;
    uint32_t count32b= 0 , i= 0;
    __IO uint32_t *fifo;

    if (pdev->cfg.dma_enable == 0)
    {
        count32b =  (len + 3) / 4;
        fifo = pdev->regs.DFIFO[ch_ep_num];
        for (i = 0; i < count32b; i++)
        {
            USB_OTG_WRITE_REG32( fifo, *((__packed uint32_t *)src) );
            src+=4;
        }
    }
    return status;
}


/**
* @brief  USB_OTG_ReadPacket : Reads a packet from the Rx FIFO
* @param  pdev : Selected device
* @param  dest : Destination Pointer
* @param  bytes : No. of bytes
* @retval None
*/
void *USB_OTG_ReadPacket(USB_OTG_CORE_HANDLE *pdev,
                         uint8_t *dest,
                         uint16_t len)
{
    uint32_t i=0;
    uint32_t count32b = (len + 3) / 4;

    __IO uint32_t *fifo = pdev->regs.DFIFO[0];

    for( i = 0; i < count32b; i++)
    {
        *(__packed uint32_t *)dest = USB_OTG_READ_REG32(fifo);
        dest += 4 ;
    }
    return ((void *)dest);
}


/**
* @brief  USB_OTG_SelectCore
*         Initialize core registers address.
* @param  pdev : Selected device
* @param  coreID : USB OTG Core ID
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_SelectCore(USB_OTG_CORE_HANDLE *pdev, USB_OTG_CORE_ID_TypeDef coreID)
{
    uint32_t i , baseAddress = 0;
    USB_OTG_STS status = USB_OTG_OK;

    pdev->cfg.dma_enable       = 0;

    /* at startup the core is in FS mode */
    pdev->cfg.speed            = USB_OTG_SPEED_FULL;
    pdev->cfg.mps              = USB_OTG_FS_MAX_PACKET_SIZE ;

    /* initialize device cfg following its address */
    baseAddress                = USB_OTG_FS_BASE_ADDR;
    pdev->cfg.coreID           = USB_OTG_FS_CORE_ID;
    pdev->cfg.host_channels    = 8 ;
    pdev->cfg.dev_endpoints    = 4 ;
    pdev->cfg.TotalFifoSize    = 320; /* in 32-bits */
    pdev->cfg.phy_itface       = USB_OTG_EMBEDDED_PHY;

#ifdef USB_OTG_FS_SOF_OUTPUT_ENABLED
    pdev->cfg.Sof_output       = 1;
#endif

#ifdef USB_OTG_FS_LOW_PWR_MGMT_SUPPORT
    pdev->cfg.low_power        = 0;
#endif

    // Init USB Core Register
    pdev->regs.GREGS = (USB_OTG_GREGS *)(baseAddress + USB_OTG_CORE_GLOBAL_REGS_OFFSET);
    pdev->regs.DREGS = (USB_OTG_DREGS *)(baseAddress + USB_OTG_DEV_GLOBAL_REG_OFFSET);

    for (i = 0; i < pdev->cfg.dev_endpoints; i++)
    {
        pdev->regs.INEP_REGS[i] = (USB_OTG_INEPREGS *)
            (baseAddress + USB_OTG_DEV_IN_EP_REG_OFFSET + (i * USB_OTG_EP_REG_OFFSET));
        pdev->regs.OUTEP_REGS[i] = (USB_OTG_OUTEPREGS *)
            (baseAddress + USB_OTG_DEV_OUT_EP_REG_OFFSET + (i * USB_OTG_EP_REG_OFFSET));
    }
    
    for (i = 0; i < pdev->cfg.host_channels; i++)
    {
        pdev->regs.DFIFO[i] = (uint32_t *)
            (baseAddress + USB_OTG_DATA_FIFO_OFFSET + (i * USB_OTG_DATA_FIFO_SIZE));
    }
    
    pdev->regs.PCGCCTL = (uint32_t *)(baseAddress + USB_OTG_PCGCCTL_OFFSET);

    return status;
}


/**
* @brief  USB_OTG_CoreInit
*         Initializes the USB_OTG controller registers and prepares the core
*         device mode or host mode operation.
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_CoreInit(USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_STS status = USB_OTG_OK;
    
    /* Reset after a PHY select and set Host mode */
    USB_OTG_CoreReset(pdev);
    USB_OTG_BSP_mDelay(20);

    return status;
}

/**
* @brief  USB_OTG_EnableGlobalInt
*         Enables the controller's Global Int in the AHB Config reg
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_EnableGlobalInt(USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_STS status = USB_OTG_OK;
    USB_OTG_GAHBCFG_TypeDef  ahbcfg;

    ahbcfg.d32 = 0;
    ahbcfg.b.glblintrmsk = 1; /* Enable interrupts */
    USB_OTG_MODIFY_REG32(&pdev->regs.GREGS->GAHBCFG, 0x0, ahbcfg.d32);
    return status;
}


/**
* @brief  USB_OTG_DisableGlobalInt
*         Enables the controller's Global Int in the AHB Config reg
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_DisableGlobalInt(USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_STS status = USB_OTG_OK;
    USB_OTG_GAHBCFG_TypeDef  ahbcfg;

    ahbcfg.d32 = 0;
    ahbcfg.b.glblintrmsk = 0; /* Disable interrupts */
    USB_OTG_MODIFY_REG32(&pdev->regs.GREGS->GAHBCFG, 0x0, ahbcfg.d32);
    return status;
}


/**
* @brief  USB_OTG_FlushTxFifo : Flush a Tx FIFO
* @param  pdev : Selected device
* @param  num : FO num
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_FlushTxFifo (USB_OTG_CORE_HANDLE *pdev , uint32_t num )
{
    USB_OTG_STS status = USB_OTG_OK;
    __IO USB_OTG_GRSTCTL_TypeDef  greset;

    uint32_t count = 0;
    greset.d32 = 0;
    greset.b.txfflsh = 1;
    greset.b.txfnum  = num;
    USB_OTG_WRITE_REG32( &pdev->regs.GREGS->GRSTCTL, greset.d32 );
    do
    {
        greset.d32 = USB_OTG_READ_REG32( &pdev->regs.GREGS->GRSTCTL);
        if (++count > 200000)
        {
            break;
        }
    }
    while (greset.b.txfflsh == 1);
    /* Wait for 3 PHY Clocks*/
    USB_OTG_BSP_uDelay(3);

    return status;
}


/**
* @brief  USB_OTG_FlushRxFifo : Flush a Rx FIFO
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_FlushRxFifo( USB_OTG_CORE_HANDLE *pdev )
{
    USB_OTG_STS status = USB_OTG_OK;
    __IO USB_OTG_GRSTCTL_TypeDef  greset;
    uint32_t count = 0;

    greset.d32 = 0;
    greset.b.rxfflsh = 1;
    USB_OTG_WRITE_REG32( &pdev->regs.GREGS->GRSTCTL, greset.d32 );
    do
    {
        greset.d32 = USB_OTG_READ_REG32( &pdev->regs.GREGS->GRSTCTL);
        if (++count > 200000)
        {
            break;
        }
    }
    while (greset.b.rxfflsh == 1);
    /* Wait for 3 PHY Clocks*/
    USB_OTG_BSP_uDelay(3);

    return status;
}


/**
* @brief  USB_OTG_SetCurrentMode : Set ID line
* @param  pdev : Selected device
* @param  mode :  (Only Device Mode)
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_SetCurrentMode(USB_OTG_CORE_HANDLE *pdev , uint8_t mode)
{
    USB_OTG_STS status = USB_OTG_OK;

    USB_OTG_BSP_mDelay(50);

    return status;
}


/**
* @brief  USB_OTG_GetMode : Get current mode
* @param  pdev : Selected device
* @retval current mode
*/
uint32_t USB_OTG_GetMode(USB_OTG_CORE_HANDLE *pdev)
{
    return (USB_OTG_READ_REG32(&pdev->regs.GREGS->GINTSTS ) & 0x1);
}


/**
* @brief  USB_OTG_IsDeviceMode : Check if it is device mode
* @param  pdev : Selected device
* @retval num_in_ep
*/
uint8_t USB_OTG_IsDeviceMode(USB_OTG_CORE_HANDLE *pdev)
{
    return (USB_OTG_GetMode(pdev) != HOST_MODE);
}


/**
* @brief  USB_OTG_IsHostMode : Check if it is host mode
* @param  pdev : Selected device
* @retval num_in_ep
*/
uint8_t USB_OTG_IsHostMode(USB_OTG_CORE_HANDLE *pdev)
{
    return (USB_OTG_GetMode(pdev) == HOST_MODE);
}


/**
* @brief  USB_OTG_ReadCoreItr : returns the Core Interrupt register
* @param  pdev : Selected device
* @retval Status
*/
uint32_t USB_OTG_ReadCoreItr(USB_OTG_CORE_HANDLE *pdev)
{
    uint32_t v = 0;
    v = USB_OTG_READ_REG32(&pdev->regs.GREGS->GINTSTS);
    v &= USB_OTG_READ_REG32(&pdev->regs.GREGS->GINTMSK);
    return v;
}


/**
* @brief  USB_OTG_InitDevSpeed :Initializes the DevSpd field of DCFG register
*         depending the PHY type and the enumeration speed of the device.
* @param  pdev : Selected device
* @retval : None
*/
void USB_OTG_InitDevSpeed(USB_OTG_CORE_HANDLE *pdev , uint8_t speed)
{
    USB_OTG_DCFG_TypeDef   dcfg;

    dcfg.d32 = USB_OTG_READ_REG32(&pdev->regs.DREGS->DCFG);
    dcfg.b.devspd = speed;
    USB_OTG_WRITE_REG32(&pdev->regs.DREGS->DCFG, dcfg.d32);
}


/**
* @brief  USB_OTG_CoreInitDev : Initializes the USB_OTG controller registers
*         for device mode
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_CoreInitDev (USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_STS             status       = USB_OTG_OK;
    USB_OTG_DEPCTL_TypeDef  depctl;
    uint32_t i;
    USB_OTG_DCFG_TypeDef    dcfg;
    USB_OTG_FSIZ_TypeDef    nptxfifosize;
    USB_OTG_DIEPMSK_TypeDef msk;

    depctl.d32 = 0;
    dcfg.d32 = 0;
    nptxfifosize.d32 = 0;
    msk.d32 = 0;

    /* Restart the Phy Clock */
    USB_OTG_WRITE_REG32(pdev->regs.PCGCCTL, 0);
    /* Device configuration register */
    dcfg.d32 = USB_OTG_READ_REG32( &pdev->regs.DREGS->DCFG);
    dcfg.b.perfrint = DCFG_FRAME_INTERVAL_80;
    USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DCFG, dcfg.d32 );

    if(pdev->cfg.coreID == USB_OTG_FS_CORE_ID  )
    {
        /* Set Full speed phy */
        USB_OTG_InitDevSpeed (pdev , USB_OTG_SPEED_PARAM_FULL);

        /* set Rx FIFO size */
        USB_OTG_WRITE_REG32(&pdev->regs.GREGS->GRXFSIZ, RX_FIFO_FS_SIZE);

        /* EP0 TX*/
        nptxfifosize.b.depth     = TX0_FIFO_FS_SIZE;
        nptxfifosize.b.startaddr = RX_FIFO_FS_SIZE;
        USB_OTG_WRITE_REG32( &pdev->regs.GREGS->GNPTXFSIZ, nptxfifosize.d32);
    }

    /* Flush the FIFOs */
    USB_OTG_FlushTxFifo(pdev , 0x10); /* all Tx FIFOs */
    USB_OTG_FlushRxFifo(pdev);
    /* Clear all pending Device Interrupts */
    USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DIEPMSK, 0 );
    USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DOEPMSK, 0 );
    USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DAINT, 0xFFFFFFFF );
    USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DAINTMSK, 0 );

    for (i = 0; i < pdev->cfg.dev_endpoints; i++)
    {
        depctl.d32 = USB_OTG_READ_REG32(&pdev->regs.INEP_REGS[i]->DIEPCTL);
        if (depctl.b.epena)
        {
            depctl.d32 = 0;
            depctl.b.epdis = 1;
            depctl.b.snak = 1;
        }
        else
        {
            depctl.d32 = 0;
        }
        USB_OTG_WRITE_REG32( &pdev->regs.INEP_REGS[i]->DIEPCTL, depctl.d32);
        USB_OTG_WRITE_REG32( &pdev->regs.INEP_REGS[i]->DIEPTSIZ, 0);
        USB_OTG_WRITE_REG32( &pdev->regs.INEP_REGS[i]->DIEPINT, 0xFF);
    }
    for (i = 0; i <  pdev->cfg.dev_endpoints; i++)
    {
        USB_OTG_DEPCTL_TypeDef  depctl;
        depctl.d32 = USB_OTG_READ_REG32(&pdev->regs.OUTEP_REGS[i]->DOEPCTL);
        if (depctl.b.epena)
        {
            depctl.d32 = 0;
            depctl.b.epdis = 1;
            depctl.b.snak = 1;
        }
        else
        {
            depctl.d32 = 0;
        }
        USB_OTG_WRITE_REG32( &pdev->regs.OUTEP_REGS[i]->DOEPCTL, depctl.d32);
        USB_OTG_WRITE_REG32( &pdev->regs.OUTEP_REGS[i]->DOEPTSIZ, 0);
        USB_OTG_WRITE_REG32( &pdev->regs.OUTEP_REGS[i]->DOEPINT, 0xFF);
    }
    msk.d32 = 0;
    msk.b.txfifoundrn = 1;
    USB_OTG_MODIFY_REG32(&pdev->regs.DREGS->DIEPMSK, msk.d32, msk.d32);

    USB_OTG_EnableDevInt(pdev);
    return status;
}

/**
* @brief  USB_OTG_EnableDevInt : Enables the Device mode interrupts
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_EnableDevInt(USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_STS status = USB_OTG_OK;
    USB_OTG_GINTMSK_TypeDef  intmsk;

    intmsk.d32 = 0;

    /* Disable all interrupts. */
    USB_OTG_WRITE_REG32( &pdev->regs.GREGS->GINTMSK, 0);
    /* Clear any pending interrupts */
    USB_OTG_WRITE_REG32( &pdev->regs.GREGS->GINTSTS, 0xBFFFFFFF);
    /* Enable the common interrupts */
    USB_OTG_EnableCommonInt(pdev);

    if (pdev->cfg.dma_enable == 0)
    {
        intmsk.b.rxstsqlvl = 1;
    }

    /* Enable interrupts matching to the Device mode ONLY */
    intmsk.b.usbsuspend = 1;
    intmsk.b.usbreset   = 1;
    intmsk.b.enumdone   = 1;
    intmsk.b.inepintr   = 1;
    intmsk.b.outepintr  = 1;
    intmsk.b.sofintr    = 1;

    intmsk.b.incomplisoin    = 1;
    intmsk.b.incomplisoout    = 1;
#ifdef VBUS_SENSING_ENABLED
    intmsk.b.sessreqintr    = 1;
    intmsk.b.otgintr    = 1;
#endif
    USB_OTG_MODIFY_REG32( &pdev->regs.GREGS->GINTMSK, intmsk.d32, intmsk.d32);
    return status;
}

/**
* @brief  USB_OTG_GetDeviceSpeed
*         Get the device speed from the device status register
* @param  None
* @retval status
*/
enum USB_OTG_SPEED USB_OTG_GetDeviceSpeed (USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_DSTS_TypeDef  dsts;
    enum USB_OTG_SPEED speed = USB_SPEED_UNKNOWN;

    dsts.d32 = USB_OTG_READ_REG32(&pdev->regs.DREGS->DSTS);

    switch (dsts.b.enumspd)
    {
    case DSTS_ENUMSPD_HS_PHY_30MHZ_OR_60MHZ:
        speed = USB_SPEED_HIGH;
        break;
    case DSTS_ENUMSPD_FS_PHY_30MHZ_OR_60MHZ:
    case DSTS_ENUMSPD_FS_PHY_48MHZ:
        speed = USB_SPEED_FULL;
        break;

    case DSTS_ENUMSPD_LS_PHY_6MHZ:
        speed = USB_SPEED_LOW;
        break;
    default:
        speed = USB_SPEED_FULL;
        break;
    }

    return speed;
}

/**
* @brief  enables EP0 OUT to receive SETUP packets and configures EP0
*   for transmitting packets
* @param  None
* @retval USB_OTG_STS : status
*/
USB_OTG_STS  USB_OTG_EP0Activate(USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_STS             status = USB_OTG_OK;
    USB_OTG_DSTS_TypeDef    dsts;
    USB_OTG_DEPCTL_TypeDef  diepctl;
    USB_OTG_DCTL_TypeDef    dctl;

    dctl.d32 = 0;
    /* Read the Device Status and Endpoint 0 Control registers */
    dsts.d32 = USB_OTG_READ_REG32(&pdev->regs.DREGS->DSTS);
    diepctl.d32 = USB_OTG_READ_REG32(&pdev->regs.INEP_REGS[0]->DIEPCTL);
    /* Set the MPS of the IN EP based on the enumeration speed */
    switch (dsts.b.enumspd)
    {
    case DSTS_ENUMSPD_HS_PHY_30MHZ_OR_60MHZ:
    case DSTS_ENUMSPD_FS_PHY_30MHZ_OR_60MHZ:
    case DSTS_ENUMSPD_FS_PHY_48MHZ:
        diepctl.b.mps = DEP0CTL_MPS_64;
        break;
    case DSTS_ENUMSPD_LS_PHY_6MHZ:
        diepctl.b.mps = DEP0CTL_MPS_8;
        break;
    default:
        diepctl.b.mps = DEP0CTL_MPS_64;
        break;
    }
    USB_OTG_WRITE_REG32(&pdev->regs.INEP_REGS[0]->DIEPCTL, diepctl.d32);
    dctl.b.cgnpinnak = 1;
    USB_OTG_MODIFY_REG32(&pdev->regs.DREGS->DCTL, dctl.d32, dctl.d32);

    return status;
}


/**
* @brief  USB_OTG_EPActivate : Activates an EP
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_EPActivate(USB_OTG_CORE_HANDLE *pdev , USB_OTG_EP *ep)
{
    USB_OTG_STS status = USB_OTG_OK;
    USB_OTG_DEPCTL_TypeDef  depctl;
    USB_OTG_DAINT_TypeDef  daintmsk;
    __IO uint32_t *addr;


    depctl.d32 = 0;
    daintmsk.d32 = 0;
    /* Read DEPCTLn register */
    if (ep->is_in == 1)
    {
        addr = &pdev->regs.INEP_REGS[ep->num]->DIEPCTL;
        daintmsk.ep.in = 1 << ep->num;
    }
    else
    {
        addr = &pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL;
        daintmsk.ep.out = 1 << ep->num;
    }
    /* If the EP is already active don't change the EP Control
    * register. */
    depctl.d32 = USB_OTG_READ_REG32(addr);
    if (!depctl.b.usbactep)
    {
        depctl.b.mps    = ep->maxpacket;
        depctl.b.eptype = ep->type;
        depctl.b.txfnum = ep->tx_fifo_num;
        depctl.b.setd0pid = 1;
        depctl.b.usbactep = 1;
        USB_OTG_WRITE_REG32(addr, depctl.d32);
    }
    /* Enable the Interrupt for this EP */
    USB_OTG_MODIFY_REG32(&pdev->regs.DREGS->DAINTMSK, 0, daintmsk.d32);

    return status;
}


/**
* @brief  USB_OTG_EPDeactivate : Deactivates an EP
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_EPDeactivate(USB_OTG_CORE_HANDLE *pdev , USB_OTG_EP *ep)
{
    USB_OTG_STS status = USB_OTG_OK;
    USB_OTG_DEPCTL_TypeDef  depctl;

    /* Read DEPCTLn register and Disable the IN endpoint*/
    if (ep->is_in == 1)
    {
        depctl.d32 = USB_OTG_READ_REG32(&pdev->regs.INEP_REGS[ep->num]->DIEPCTL);
        if (depctl.b.epena)
        {
            depctl.d32 = 0;
            depctl.b.epdis = 1;
            depctl.b.snak = 1;
        }
        else
        {
            depctl.d32 = 0;
        }
        USB_OTG_WRITE_REG32( &pdev->regs.INEP_REGS[ep->num]->DIEPCTL, depctl.d32);
    }
    else  /* Disable the OUT endpoint */
    {
        USB_OTG_DEPCTL_TypeDef  depctl;
        depctl.d32 = USB_OTG_READ_REG32(&pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL);
        if (depctl.b.epena)
        {
            depctl.d32 = 0;
            depctl.b.epdis = 1;
            depctl.b.snak = 1;
        }
        else
        {
            depctl.d32 = 0;
        }
        USB_OTG_WRITE_REG32( &pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL, depctl.d32);
    }
    return status;
}


/**
* @brief  USB_OTG_EPStartXfer : Handle the setup for data xfer for an EP and
*         starts the xfer
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_EPStartXfer(USB_OTG_CORE_HANDLE *pdev , USB_OTG_EP *ep)
{
    USB_OTG_STS status = USB_OTG_OK;
    USB_OTG_DEPCTL_TypeDef     depctl;
    USB_OTG_DEPXFRSIZ_TypeDef  deptsiz;
    USB_OTG_DSTS_TypeDef       dsts;
    uint32_t fifoemptymsk = 0;

    depctl.d32 = 0;
    deptsiz.d32 = 0;
    /* IN endpoint */
    if (ep->is_in == 1)
    {
        depctl.d32  = USB_OTG_READ_REG32(&(pdev->regs.INEP_REGS[ep->num]->DIEPCTL));
        deptsiz.d32 = USB_OTG_READ_REG32(&(pdev->regs.INEP_REGS[ep->num]->DIEPTSIZ));
        /* Zero Length Packet? */
        if (ep->xfer_len == 0)
        {
            deptsiz.b.xfersize = 0;
            deptsiz.b.pktcnt = 1;
        }
        else
        {
            /* Program the transfer size and packet count
            * as follows: xfersize = N * maxpacket +
            * short_packet pktcnt = N + (short_packet
            * exist ? 1 : 0)
            */
            deptsiz.b.xfersize = ep->xfer_len;
            deptsiz.b.pktcnt = (ep->xfer_len - 1 + ep->maxpacket) / ep->maxpacket;

            if (ep->type == EP_TYPE_ISOC)
            {
                deptsiz.b.mc = 1;
            }
        }
        USB_OTG_WRITE_REG32(&pdev->regs.INEP_REGS[ep->num]->DIEPTSIZ, deptsiz.d32);

        if (ep->type != EP_TYPE_ISOC)
        {
            /* Enable the Tx FIFO Empty Interrupt for this EP */
            if (ep->xfer_len > 0)
            {
                fifoemptymsk = 1 << ep->num;
                USB_OTG_MODIFY_REG32(&pdev->regs.DREGS->DIEPEMPMSK, 0, fifoemptymsk);
            }
        }

        if (ep->type == EP_TYPE_ISOC)
        {
            dsts.d32 = USB_OTG_READ_REG32(&pdev->regs.DREGS->DSTS);

            if (((dsts.b.soffn)&0x1) == 0)
            {
                depctl.b.setd1pid = 1;
            }
            else
            {
                depctl.b.setd0pid = 1;
            }
        }

        /* EP enable, IN data in FIFO */
        depctl.b.cnak = 1;
        depctl.b.epena = 1;
        USB_OTG_WRITE_REG32(&pdev->regs.INEP_REGS[ep->num]->DIEPCTL, depctl.d32);

        if (ep->type == EP_TYPE_ISOC)
        {
            USB_OTG_WritePacket(pdev, ep->xfer_buff, ep->num, ep->xfer_len);
        }
    }
    else
    {
        /* OUT endpoint */
        depctl.d32  = USB_OTG_READ_REG32(&(pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL));
        deptsiz.d32 = USB_OTG_READ_REG32(&(pdev->regs.OUTEP_REGS[ep->num]->DOEPTSIZ));
        /* Program the transfer size and packet count as follows:
        * pktcnt = N
        * xfersize = N * maxpacket
        */
        if (ep->xfer_len == 0)
        {
            deptsiz.b.xfersize = ep->maxpacket;
            deptsiz.b.pktcnt = 1;
        }
        else
        {
            deptsiz.b.pktcnt = (ep->xfer_len + (ep->maxpacket - 1)) / ep->maxpacket;
            deptsiz.b.xfersize = deptsiz.b.pktcnt * ep->maxpacket;
            ep->xfer_len = deptsiz.b.xfersize ;
        }
        USB_OTG_WRITE_REG32(&pdev->regs.OUTEP_REGS[ep->num]->DOEPTSIZ, deptsiz.d32);

        if (ep->type == EP_TYPE_ISOC)
        {
            if (ep->even_odd_frame)
            {
                depctl.b.setd1pid = 1;
            }
            else
            {
                depctl.b.setd0pid = 1;
            }
        }
        /* EP enable */
        depctl.b.cnak = 1;
        depctl.b.epena = 1;
        USB_OTG_WRITE_REG32(&pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL, depctl.d32);
    }
    return status;
}


/**
* @brief  USB_OTG_EP0StartXfer : Handle the setup for a data xfer for EP0 and
*         starts the xfer
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_EP0StartXfer(USB_OTG_CORE_HANDLE *pdev , USB_OTG_EP *ep)
{
    USB_OTG_STS                 status = USB_OTG_OK;
    USB_OTG_DEPCTL_TypeDef      depctl;
    USB_OTG_DEP0XFRSIZ_TypeDef  deptsiz;
    USB_OTG_INEPREGS          *in_regs;
    uint32_t fifoemptymsk = 0;

    depctl.d32   = 0;
    deptsiz.d32  = 0;
    /* IN endpoint */
    if (ep->is_in == 1)
    {
        in_regs = pdev->regs.INEP_REGS[0];
        depctl.d32  = USB_OTG_READ_REG32(&in_regs->DIEPCTL);
        deptsiz.d32 = USB_OTG_READ_REG32(&in_regs->DIEPTSIZ);
        /* Zero Length Packet? */
        if (ep->xfer_len == 0)
        {
            deptsiz.b.xfersize = 0;
            deptsiz.b.pktcnt = 1;
        }
        else
        {
            if (ep->xfer_len > ep->maxpacket)
            {
                ep->xfer_len = ep->maxpacket;
                deptsiz.b.xfersize = ep->maxpacket;
            }
            else
            {
                deptsiz.b.xfersize = ep->xfer_len;
            }
            deptsiz.b.pktcnt = 1;
        }
        USB_OTG_WRITE_REG32(&in_regs->DIEPTSIZ, deptsiz.d32);

        /* EP enable, IN data in FIFO */
        depctl.b.cnak = 1;
        depctl.b.epena = 1;
        USB_OTG_WRITE_REG32(&in_regs->DIEPCTL, depctl.d32);

        if (pdev->cfg.dma_enable == 0)
        {
            /* Enable the Tx FIFO Empty Interrupt for this EP */
            if (ep->xfer_len > 0)
            {
                fifoemptymsk |= 1 << ep->num;
                USB_OTG_MODIFY_REG32(&pdev->regs.DREGS->DIEPEMPMSK, 0, fifoemptymsk);
            }
        }
    }
    else
    {
        /* OUT endpoint */
        depctl.d32  = USB_OTG_READ_REG32(&pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL);
        deptsiz.d32 = USB_OTG_READ_REG32(&pdev->regs.OUTEP_REGS[ep->num]->DOEPTSIZ);
        /* Program the transfer size and packet count as follows:
        * xfersize = N * (maxpacket + 4 - (maxpacket % 4))
        * pktcnt = N           */
        if (ep->xfer_len == 0)
        {
            deptsiz.b.xfersize = ep->maxpacket;
            deptsiz.b.pktcnt = 1;
        }
        else
        {
            ep->xfer_len = ep->maxpacket;
            deptsiz.b.xfersize = ep->maxpacket;
            deptsiz.b.pktcnt = 1;
        }
        USB_OTG_WRITE_REG32(&pdev->regs.OUTEP_REGS[ep->num]->DOEPTSIZ, deptsiz.d32);
        
        /* EP enable */
        depctl.b.cnak = 1;
        depctl.b.epena = 1;
        USB_OTG_WRITE_REG32 (&(pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL), depctl.d32);
    }

    return status;
}


/**
* @brief  USB_OTG_EPSetStall : Set the EP STALL
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_EPSetStall(USB_OTG_CORE_HANDLE *pdev , USB_OTG_EP *ep)
{
    USB_OTG_STS status = USB_OTG_OK;
    USB_OTG_DEPCTL_TypeDef  depctl;
    __IO uint32_t *depctl_addr;

    depctl.d32 = 0;
    if (ep->is_in == 1)
    {
        depctl_addr = &(pdev->regs.INEP_REGS[ep->num]->DIEPCTL);
        depctl.d32 = USB_OTG_READ_REG32(depctl_addr);
        /* set the disable and stall bits */
        if (depctl.b.epena)
        {
            depctl.b.epdis = 1;
        }
        depctl.b.stall = 1;
        USB_OTG_WRITE_REG32(depctl_addr, depctl.d32);
    }
    else
    {
        depctl_addr = &(pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL);
        depctl.d32 = USB_OTG_READ_REG32(depctl_addr);
        /* set the stall bit */
        depctl.b.stall = 1;
        USB_OTG_WRITE_REG32(depctl_addr, depctl.d32);
    }

    return status;
}


/**
* @brief  Clear the EP STALL
* @param  pdev : Selected device
* @retval USB_OTG_STS : status
*/
USB_OTG_STS USB_OTG_EPClearStall(USB_OTG_CORE_HANDLE *pdev , USB_OTG_EP *ep)
{
    USB_OTG_STS status = USB_OTG_OK;
    USB_OTG_DEPCTL_TypeDef  depctl;
    __IO uint32_t *depctl_addr;

    depctl.d32 = 0;

    if (ep->is_in == 1)
    {
        depctl_addr = &(pdev->regs.INEP_REGS[ep->num]->DIEPCTL);
    }
    else
    {
        depctl_addr = &(pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL);
    }
    depctl.d32 = USB_OTG_READ_REG32(depctl_addr);
    /* clear the stall bits */
    depctl.b.stall = 0;
    if (ep->type == EP_TYPE_INTR || ep->type == EP_TYPE_BULK)
    {
        depctl.b.setd0pid = 1; /* DATA0 */
    }
    USB_OTG_WRITE_REG32(depctl_addr, depctl.d32);
    return status;
}

/**
* @brief  USB_OTG_ReadDevAllOutEp_itr : returns OUT endpoint interrupt bits
* @param  pdev : Selected device
* @retval OUT endpoint interrupt bits
*/
uint32_t USB_OTG_ReadDevAllOutEp_itr(USB_OTG_CORE_HANDLE *pdev)
{
    uint32_t v;
    v  = USB_OTG_READ_REG32(&pdev->regs.DREGS->DAINT);
    v &= USB_OTG_READ_REG32(&pdev->regs.DREGS->DAINTMSK);
    return ((v & 0xffff0000) >> 16);
}


/**
* @brief  USB_OTG_ReadDevOutEP_itr : returns Device OUT EP Interrupt register
* @param  pdev : Selected device
* @param  ep : end point number
* @retval Device OUT EP Interrupt register
*/
uint32_t USB_OTG_ReadDevOutEP_itr(USB_OTG_CORE_HANDLE *pdev , uint8_t epnum)
{
    uint32_t v;
    v  = USB_OTG_READ_REG32(&pdev->regs.OUTEP_REGS[epnum]->DOEPINT);
    v &= USB_OTG_READ_REG32(&pdev->regs.DREGS->DOEPMSK);
    return v;
}


/**
* @brief  USB_OTG_ReadDevAllInEPItr : Get int status register
* @param  pdev : Selected device
* @retval int status register
*/
uint32_t USB_OTG_ReadDevAllInEPItr(USB_OTG_CORE_HANDLE *pdev)
{
    uint32_t v;
    v = USB_OTG_READ_REG32(&pdev->regs.DREGS->DAINT);
    v &= USB_OTG_READ_REG32(&pdev->regs.DREGS->DAINTMSK);
    return (v & 0xffff);
}

/**
* @brief  configures EPO to receive SETUP packets
* @param  None
* @retval : None
*/
void USB_OTG_EP0_OutStart(USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_DEP0XFRSIZ_TypeDef  doeptsize0;
    doeptsize0.d32 = 0;
    doeptsize0.b.supcnt = 3;
    doeptsize0.b.pktcnt = 1;
    doeptsize0.b.xfersize = 8 * 3;
    USB_OTG_WRITE_REG32( &pdev->regs.OUTEP_REGS[0]->DOEPTSIZ, doeptsize0.d32 );
}

/**
* @brief  USB_OTG_RemoteWakeup : active remote wakeup signalling
* @param  None
* @retval : None
*/
void USB_OTG_ActiveRemoteWakeup(USB_OTG_CORE_HANDLE *pdev)
{
    USB_OTG_DCTL_TypeDef     dctl;
    USB_OTG_DSTS_TypeDef     dsts;
    USB_OTG_PCGCCTL_TypeDef  power;

    if (pdev->dev.DevRemoteWakeup)
    {
        dsts.d32 = USB_OTG_READ_REG32(&pdev->regs.DREGS->DSTS);
        if(dsts.b.suspsts == 1)
        {
            if(pdev->cfg.low_power)
            {
                /* un-gate USB Core clock */
                power.d32 = USB_OTG_READ_REG32(pdev->regs.PCGCCTL);
                power.b.gatehclk = 0;
                power.b.stoppclk = 0;
                USB_OTG_WRITE_REG32(pdev->regs.PCGCCTL, power.d32);
            }
            /* active Remote wakeup signaling */
            dctl.d32 = 0;
            dctl.b.rmtwkupsig = 1;
            USB_OTG_MODIFY_REG32(&pdev->regs.DREGS->DCTL, 0, dctl.d32);
            USB_OTG_BSP_mDelay(5);
            USB_OTG_MODIFY_REG32(&pdev->regs.DREGS->DCTL, dctl.d32, 0 );
        }
    }
}


/**
* @brief  USB_OTG_UngateClock : active USB Core clock
* @param  None
* @retval : None
*/
void USB_OTG_UngateClock(USB_OTG_CORE_HANDLE *pdev)
{
    if(pdev->cfg.low_power)
    {
        USB_OTG_DSTS_TypeDef     dsts;
        USB_OTG_PCGCCTL_TypeDef  power;

        dsts.d32 = USB_OTG_READ_REG32(&pdev->regs.DREGS->DSTS);

        if(dsts.b.suspsts == 1)
        {
            /* un-gate USB Core clock */
            power.d32 = USB_OTG_READ_REG32(pdev->regs.PCGCCTL);
            power.b.gatehclk = 0;
            power.b.stoppclk = 0;
            USB_OTG_WRITE_REG32(pdev->regs.PCGCCTL, power.d32);
        }
    }
}

/**
* @brief  Stop the device and clean up fifo's
* @param  None
* @retval : None
*/
void USB_OTG_StopDevice(USB_OTG_CORE_HANDLE *pdev)
{
    uint32_t i;

    pdev->dev.device_status = 1;

    for (i = 0; i < pdev->cfg.dev_endpoints ; i++)
    {
        USB_OTG_WRITE_REG32( &pdev->regs.INEP_REGS[i]->DIEPINT, 0xFF);
        USB_OTG_WRITE_REG32( &pdev->regs.OUTEP_REGS[i]->DOEPINT, 0xFF);
    }

    USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DIEPMSK, 0 );
    USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DOEPMSK, 0 );
    USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DAINTMSK, 0 );
    USB_OTG_WRITE_REG32( &pdev->regs.DREGS->DAINT, 0xFFFFFFFF );

    /* Flush the FIFO */
    USB_OTG_FlushRxFifo(pdev);
    USB_OTG_FlushTxFifo(pdev ,  0x10 );
}

/**
* @brief  returns the EP Status
* @param  pdev : Selected device
*         ep : endpoint structure
* @retval : EP status
*/

uint32_t USB_OTG_GetEPStatus(USB_OTG_CORE_HANDLE *pdev ,USB_OTG_EP *ep)
{
    USB_OTG_DEPCTL_TypeDef  depctl;
    __IO uint32_t *depctl_addr;
    uint32_t Status = 0;

    depctl.d32 = 0;
    if (ep->is_in == 1)
    {
        depctl_addr = &(pdev->regs.INEP_REGS[ep->num]->DIEPCTL);
        depctl.d32 = USB_OTG_READ_REG32(depctl_addr);

        if (depctl.b.stall == 1)
        {
            Status = USB_OTG_EP_TX_STALL;
        }
        else if (depctl.b.naksts == 1)
        {
            Status = USB_OTG_EP_TX_NAK;
        }
        else
        {
            Status = USB_OTG_EP_TX_VALID;
        }
    }
    else
    {
        depctl_addr = &(pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL);
        depctl.d32 = USB_OTG_READ_REG32(depctl_addr);
        if (depctl.b.stall == 1)
        {
            Status = USB_OTG_EP_RX_STALL;
        }
        else if (depctl.b.naksts == 1)
        {
            Status = USB_OTG_EP_RX_NAK;
        }
        else
        {
            Status = USB_OTG_EP_RX_VALID;
        }
    }

    /* Return the current status */
    return Status;
}

/**
* @brief  Set the EP Status
* @param  pdev : Selected device
*         Status : new Status
*         ep : EP structure
* @retval : None
*/
void USB_OTG_SetEPStatus (USB_OTG_CORE_HANDLE *pdev , USB_OTG_EP *ep , uint32_t Status)
{
    USB_OTG_DEPCTL_TypeDef  depctl;
    __IO uint32_t *depctl_addr;

    depctl.d32 = 0;

    /* Process for IN endpoint */
    if (ep->is_in == 1)
    {
        depctl_addr = &(pdev->regs.INEP_REGS[ep->num]->DIEPCTL);
        depctl.d32 = USB_OTG_READ_REG32(depctl_addr);

        if (Status == USB_OTG_EP_TX_STALL)
        {
            USB_OTG_EPSetStall(pdev, ep); return;
        }
        else if (Status == USB_OTG_EP_TX_NAK)
        {
            depctl.b.snak = 1;
        }
        else if (Status == USB_OTG_EP_TX_VALID)
        {
            if (depctl.b.stall == 1)
            {
                ep->even_odd_frame = 0;
                USB_OTG_EPClearStall(pdev, ep);
                return;
            }
            depctl.b.cnak = 1;
            depctl.b.usbactep = 1;
            depctl.b.epena = 1;
        }
        else if (Status == USB_OTG_EP_TX_DIS)
        {
            depctl.b.usbactep = 0;
        }
        else
        {
            /* Do Nothing */
        }
    }
    else /* Process for OUT endpoint */
    {
        depctl_addr = &(pdev->regs.OUTEP_REGS[ep->num]->DOEPCTL);
        depctl.d32 = USB_OTG_READ_REG32(depctl_addr);

        if (Status == USB_OTG_EP_RX_STALL)
        {
            depctl.b.stall = 1;
        }
        else if (Status == USB_OTG_EP_RX_NAK)
        {
            depctl.b.snak = 1;
        }
        else if (Status == USB_OTG_EP_RX_VALID)
        {
            if (depctl.b.stall == 1)
            {
                ep->even_odd_frame = 0;
                USB_OTG_EPClearStall(pdev, ep);
                return;
            }
            depctl.b.cnak = 1;
            depctl.b.usbactep = 1;
            depctl.b.epena = 1;
        }
        else if (Status == USB_OTG_EP_RX_DIS)
        {
            depctl.b.usbactep = 0;
        }
        else
        {
            /* Do Nothing */
        }
    }

    USB_OTG_WRITE_REG32(depctl_addr, depctl.d32);
}
