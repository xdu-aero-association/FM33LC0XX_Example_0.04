#ifndef __USB_OTG_REGS_H__
#define __USB_OTG_REGS_H__

#include "usb_conf.h"
#include "fm33lc0xx.h"

// USB Register Define 
#define USB_OTG_FS_BASE_ADDR                0x50000000		

#define USB_OTG_CORE_GLOBAL_REGS_OFFSET     0x000
#define USB_OTG_DEV_GLOBAL_REG_OFFSET       0x800			
#define USB_OTG_DEV_IN_EP_REG_OFFSET        0x900						
#define USB_OTG_DEV_OUT_EP_REG_OFFSET       0xB00								
#define USB_OTG_PCGCCTL_OFFSET              0xE00			
#define USB_OTG_DATA_FIFO_OFFSET            0x1000
#define USB_OTG_DEBUG_FIFO_OFFSET           0x20000

#define USB_OTG_EP_REG_OFFSET               0x20
#define USB_OTG_DATA_FIFO_SIZE              0x1000			

#define USB_OTG_MAX_TX_FIFOS                15				

// SIZE£ºword or byte£¿		
#define USB_OTG_FS_MAX_PACKET_SIZE          64				
#define USB_OTG_MAX_EP0_SIZE                16				


// Core Global CSR Map(000h-3FFh)
typedef struct _USB_OTG_GREGS  /* 000h */
{
    __IO uint32_t Reserved00;               /* Reserved                           000h*/
    __IO uint32_t Reserved04;               /* Reserved                           004h*/
    __IO uint32_t GAHBCFG;                  /* Core AHB Configuration Register    008h*/
    __IO uint32_t GUSBCFG;                  /* Core USB Configuration Register    00Ch*/
    __IO uint32_t GRSTCTL;                  /* Core Reset Register                010h*/
    __IO uint32_t GINTSTS;                  /* Core Interrupt Register            014h*/
    __IO uint32_t GINTMSK;                  /* Core Interrupt Mask Register       018h*/
    __IO uint32_t GRXSTSR;                  /* Receive Sts Q Read Register        01Ch*/
    __IO uint32_t GRXSTSP;                  /* Receive Sts Q Read & POP Register  020h*/
    __IO uint32_t GRXFSIZ;                  /* Receive FIFO Size Register         024h*/
    __IO uint32_t GNPTXFSIZ;                /* Non Periodic Tx FIFO Size Register 028h*/
    __IO uint32_t Reserved2C[10];           /* Reserved                      02Ch-04Ch*/
    __IO uint32_t GLPMCFG;                  /* Low-Power-Mode config Register     054h*/       
}
USB_OTG_GREGS;

// Device Mode CSR Map(800h-8ffh)
typedef struct _USB_OTG_DREGS /* 800h */
{
    __IO uint32_t DCFG;                     /* dev Configuration Register   800h*/
    __IO uint32_t DCTL;                     /* dev Control Register         804h*/
    __IO uint32_t DSTS;                     /* dev Status Register (RO)     808h*/
    uint32_t Reserved0C;                    /* Reserved                     80Ch*/
    __IO uint32_t DIEPMSK;                  /* dev IN Endpoint Mask         810h*/
    __IO uint32_t DOEPMSK;                  /* dev OUT Endpoint Mask        814h*/
    __IO uint32_t DAINT;                    /* dev All Endpoints Itr Reg    818h*/
    __IO uint32_t DAINTMSK;                 /* dev All Endpoints Itr Mask   81Ch*/
    uint32_t Reserved20[5];                 /* Reserved                 820h-830*/
    __IO uint32_t DIEPEMPMSK;               /* dev empty msk                834h*/ 
}
USB_OTG_DREGS;

// Device IN Endpointx Register(900h-AFFh)
typedef struct _USB_OTG_INEPREGS
{
    __IO uint32_t DIEPCTL;      /* dev IN Endpoint Control Reg      900h + (ep_num * 20h) + 00h*/
    uint32_t Reserved04;        /* Reserved                         900h + (ep_num * 20h) + 04h*/
    __IO uint32_t DIEPINT;      /* dev IN Endpoint Itr Reg          900h + (ep_num * 20h) + 08h*/
    uint32_t Reserved0C;        /* ReINEP_REGSserved                         900h + (ep_num * 20h) + 0Ch*/
    __IO uint32_t DIEPTSIZ;     /* IN Endpoint Txfer Size           900h + (ep_num * 20h) + 10h*/
    uint32_t Reserved14;        /* Reserved                         900h + (ep_num * 20h) + 14h*/
    __IO uint32_t DTXFSTS;      /* IN Endpoint Tx FIFO Status Reg   900h + (ep_num * 20h) + 18h*/
    uint32_t Reserved1C;        /* Reserved                         900h + (ep_num * 20h) + 1Ch*/
}
USB_OTG_INEPREGS;

// Device OUT Endpointx Register(B00h-CFFh)
typedef struct _USB_OTG_OUTEPREGS
{
    __IO uint32_t DOEPCTL;      /* dev OUT Endpoint Control Reg     B00h + (ep_num * 20h) + 00h*/
    uint32_t Reserved04;        /* Reserved                         B00h + (ep_num * 20h) + 04h*/
    __IO uint32_t DOEPINT;      /* dev OUT Endpoint Itr Reg         B00h + (ep_num * 20h) + 08h*/
    uint32_t Reserved0C;        /* Reserved                         B00h + (ep_num * 20h) + 0Ch*/
    __IO uint32_t DOEPTSIZ;     /* dev OUT Endpoint Txfer Size      B00h + (ep_num * 20h) + 10h*/
    uint32_t Reserved14;        /* Reserved                         B00h + (ep_num * 20h) + 14h*/
    uint32_t Reserved18;        /* Reserved                         B00h + (ep_num * 20h) + 18h*/
    uint32_t Reserved1C;        /* Reserved                         B00h + (ep_num * 20h) + 1Ch*/
}
USB_OTG_OUTEPREGS;


// USB OTG CSR Struct
typedef struct USB_OTG_core_regs /* 000h */
{
    USB_OTG_GREGS         *GREGS;
    USB_OTG_DREGS         *DREGS;
    USB_OTG_INEPREGS      *INEP_REGS[USB_OTG_MAX_TX_FIFOS];
    USB_OTG_OUTEPREGS     *OUTEP_REGS[USB_OTG_MAX_TX_FIFOS];
    __IO uint32_t         *DFIFO[USB_OTG_MAX_TX_FIFOS];
    __IO uint32_t         *PCGCCTL;
}
USB_OTG_CORE_REGS , *PUSB_OTG_CORE_REGS;


// Global Register Bit Define 

typedef union _USB_OTG_GAHBCFG_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t glblintrmsk :
        1;
    uint32_t Reserved1_6 :
        6;
    uint32_t nptxfemplvl :
        1;
    uint32_t Reserved8_31 :
        24;
    }
    b;
} USB_OTG_GAHBCFG_TypeDef ;

typedef union _USB_OTG_GUSBCFG_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t toutcal :
        3;
    uint32_t Reserved3_9 :
        7;
    uint32_t usbtrdtim :
        4;
    uint32_t Reserved14_31 :
        18;
    }
    b;
} USB_OTG_GUSBCFG_TypeDef ;

typedef union _USB_OTG_GRSTCTL_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t csftrst :
        1;
    uint32_t hsftrst :
        1;
    uint32_t Reserved2_3 :
        2;
    uint32_t rxfflsh :
        1;
    uint32_t txfflsh :
        1;
    uint32_t txfnum :
        5;
    uint32_t Reserved11_30 :
        20;
    uint32_t ahbidle :
        1;
    }
    b;
} USB_OTG_GRSTCTL_TypeDef ;

typedef union _USB_OTG_GINTSTS_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t curmode :
        1;
    uint32_t modemismatch :
        1;
    uint32_t Reserved2 :
        1;
    uint32_t sofintr :
        1;
    uint32_t rxstsqlvl :
        1;
    uint32_t Reserved5 :
        1;
    uint32_t ginnakeff :
        1;
    uint32_t goutnakeff :
        1;
    uint32_t Reserved8_9 :
        2;
    uint32_t erlysuspend :
        1;
    uint32_t usbsuspend :
        1;
    uint32_t usbreset :
        1;
    uint32_t enumdone :
        1;
    uint32_t isooutdrop :
        1;
    uint32_t eopframe :
        1;
    uint32_t Reserved16_17 :
        2;
    uint32_t inepint:
        1;
    uint32_t outepintr :
        1;
    uint32_t incomplisoin :
        1;
    uint32_t incomplisoout :
        1;
    uint32_t Reserved22 :
        1;
    uint32_t resetdet :
        1;
    uint32_t Reserved24_26 :
        3;
    uint32_t lpmint:
        1;
    uint32_t Reserved28_30 :
        3;
    uint32_t wkupintr :
        1;
    }
    b;
} USB_OTG_GINTSTS_TypeDef ;

typedef union _USB_OTG_GINTMSK_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t Reserved0 :
        1;
    uint32_t modemismatch :
        1;
    uint32_t Reserved2 :
        1;
    uint32_t sofintr :
        1;
    uint32_t rxstsqlvl :
        1;
    uint32_t nptxfempty :
        1;
    uint32_t ginnakeff :
        1;
    uint32_t goutnakeff :
        1;
    uint32_t Reserved8_9 :
        2;
    uint32_t erlysuspend :
        1;
    uint32_t usbsuspend :
        1;
    uint32_t usbreset :
        1;
    uint32_t enumdone :
        1;
    uint32_t isooutdrop :
        1;
    uint32_t eopframe :
        1;
    uint32_t Reserved16_17 :
        2;
    uint32_t inepintr :
        1;
    uint32_t outepintr :
        1;
    uint32_t incomplisoin :
        1;
    uint32_t incomplisoout :
        1;
    uint32_t Reserved22 :
        1;
    uint32_t resetdet :
        1;
    uint32_t Reserved24_26 :
        3;
    uint32_t lpmint :
        1;
    uint32_t Reserved28_30 :
        3;
    uint32_t wkupintr :
        1;
    }
    b;
} USB_OTG_GINTMSK_TypeDef ;


// USB_GRXSTSR/USB_GRXSTSP
typedef union _USB_OTG_DRXSTS_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t epnum :
        4;
    uint32_t bcnt :
        11;
    uint32_t dpid :
        2;
    uint32_t pktsts :
        4;
    uint32_t fn :
        4;
    uint32_t Reserved25_31 :
        7;
    }
    b;
} USB_OTG_DRXSTS_TypeDef ;

// USB_GNPTXFSLZ
typedef union _USB_OTG_FSIZ_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t startaddr :
        16;
    uint32_t depth :
        16;
    }
    b;
} USB_OTG_FSIZ_TypeDef ;

typedef union _USB_OTG_DTXFSTSn_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t txfspcavail :
        16;
    uint32_t Reserved :
        16;
    }
    b;
} USB_OTG_DTXFSTSn_TypeDef ;

typedef union _USB_OTG_GLPMCFG_Typedef
{
    uint32_t d32;
    struct
    {
    uint32_t lpmcap :
        1;
    uint32_t appl1res :
        1;
    uint32_t hird :
        4;
    uint32_t enblslpm :
        1;
    uint32_t Reserved7 :
        1;
    uint32_t hird_thres :
        5;
    uint32_t corel1resp :
        2;
    uint32_t slpsts :
        1;
    uint32_t l1resumeok :
        1;
    uint32_t Reserved17_31:
        15;
    }
    b;
} USB_OTG_GLPMCFG_TypeDef;


// Device Register Bit Define

typedef union _USB_OTG_DCFG_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t devspd :
        2;
    uint32_t nzstsouthshk :
        1;
    uint32_t ena32khzs :
        1;
    uint32_t devaddr :
        7;
    uint32_t perfrint :
        2;
    uint32_t Reserved13_17 :
        5;
    uint32_t epmiscnt :
        5;
    uint32_t Reserved23_31 :
        3;
    uint32_t resvalid :
        6;
    }
    b;
} USB_OTG_DCFG_TypeDef ;

typedef union _USB_OTG_DCTL_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t rmtwkupsig :
        1;
    uint32_t sftdiscon :
        1;
    uint32_t gnpinnaksts :
        1;
    uint32_t goutnaksts :
        1;
    uint32_t tstctl :
        3;
    uint32_t sgnpinnak :
        1;
    uint32_t cgnpinnak :
        1;
    uint32_t sgoutnak :
        1;
    uint32_t cgoutnak :
        1;
    uint32_t poprg_done :
        1;    
    uint32_t Reserved12_15 :
        4;
    uint32_t nakonbble :
        1;
    uint32_t Reserved17_31 :
        15;
    }
    b;
} USB_OTG_DCTL_TypeDef ;

typedef union _USB_OTG_DSTS_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t suspsts :
        1;
    uint32_t enumspd :
        2;
    uint32_t errticerr :
        1;
    uint32_t Reserved4_7:
        4;
    uint32_t soffn :
        14;
    uint32_t Reserved22_31 :
        10;
    }
    b;
} USB_OTG_DSTS_TypeDef ;

typedef union _USB_OTG_DIEPINTn_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t xfercompl :
        1;
    uint32_t epdisabled :
        1;
    uint32_t Reserved2 :
        1;
    uint32_t timeout :
        1;
    uint32_t intktxfemp :
        1;
    uint32_t Reserved5 :
        1;
    uint32_t inepnakeff :
        1;
    uint32_t emptyintr :
        1;
    uint32_t txfifoundrn :
        1;
    uint32_t Reserved9_31 :
        23;
    }
    b;
} USB_OTG_DIEPINTn_TypeDef ;
typedef union _USB_OTG_DIEPINTn_TypeDef   USB_OTG_DIEPMSK_TypeDef ;

typedef union _USB_OTG_DOEPINTn_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t xfercompl :
        1;
    uint32_t epdisabled :
        1;
    uint32_t Reserved2 :
        1;
    uint32_t setup :
        1;
    uint32_t Reserved04_31 :
        28;
    }
    b;
} USB_OTG_DOEPINTn_TypeDef ;
typedef union _USB_OTG_DOEPINTn_TypeDef   USB_OTG_DOEPMSK_TypeDef ;

typedef union _USB_OTG_DAINT_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t in :
        16;
    uint32_t out :
        16;
    }
    ep;
} USB_OTG_DAINT_TypeDef ;

typedef union _USB_OTG_DTHRCTL_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t non_iso_thr_en :
        1;
    uint32_t iso_thr_en :
        1;
    uint32_t tx_thr_len :
        9;
    uint32_t Reserved11_15 :
        5;
    uint32_t rx_thr_en :
        1;
    uint32_t rx_thr_len :
        9;
    uint32_t Reserved26 : 
        1;
    uint32_t arp_en :  
        1;
    uint32_t Reserved28_31 :
        4;   
    }
    b;
} USB_OTG_DTHRCTL_TypeDef ;


// IN and OUT EP Register Bit Define

typedef union _USB_OTG_DEPCTL_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t mps :
        11;
    uint32_t nxtep:
        4;
    uint32_t usbactep :
        1;
    uint32_t dpid :
        1;
    uint32_t naksts :
        1;
    uint32_t eptype :
        2;
    uint32_t snp :
        1;
    uint32_t stall :
        1;
    uint32_t txfnum :
        4;
    uint32_t cnak :
        1;
    uint32_t snak :
        1;
    uint32_t setd0pid :
        1;
    uint32_t setd1pid :
        1;
    uint32_t epdis :
        1;
    uint32_t epena :
        1;
    }
    b;
} USB_OTG_DEPCTL_TypeDef ;

typedef union _USB_OTG_DEP0XFRSIZ_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t xfersize :
        7;
    uint32_t Reserved7_18 :
        12;
    uint32_t pktcnt :
        1;
    uint32_t Reserved20_28 :
        9;
    uint32_t supcnt :
        2;
    uint32_t Reserved31 :
        1;
    }
    b;
} USB_OTG_DEP0XFRSIZ_TypeDef ;

typedef union _USB_OTG_DEPXFRSIZ_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t xfersize :
        19;
    uint32_t pktcnt :
        10;
    uint32_t mc :
        2;
    uint32_t Reserved :
        1;
    }
    b;
} USB_OTG_DEPXFRSIZ_TypeDef ;

// Power and Clock Register Bit Define

typedef union _USB_OTG_PCGCCTL_TypeDef 
{
    uint32_t d32;
    struct
    {
    uint32_t stoppclk :
        1;
    uint32_t gatehclk :
        1;
    uint32_t Reserved2_4 :
        3;
    uint32_t enbl_l1fating :
        1;
    uint32_t physleep :
        1;
    uint32_t l1_suspended :
        1;
    uint32_t Reserved8_31 :
        24;
    }
    b;
} USB_OTG_PCGCCTL_TypeDef ;

#endif
