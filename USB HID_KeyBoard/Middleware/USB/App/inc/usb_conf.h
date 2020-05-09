#ifndef __USB_CONF__H__
#define __USB_CONF__H__

// USB底层驱动配置，包括内核配置和物理层配置

#include "usb_conf.h"
 
// USB全速设备FIFO配置（分配单位:word）
#define RX_FIFO_FS_SIZE             64
#define TX0_FIFO_FS_SIZE            16
#define TX1_FIFO_FS_SIZE            16
#define TX2_FIFO_FS_SIZE            16


// 系统AHB工作时钟
#define SYSTEM_AHB_CLOCK    64000000

// USB模式选择
#define USE_DEVICE_MODE


// 编译器关键字定义：
// 支持实现USB所有的变量和结构体均4字节对齐
//#define USB_DATA_STRUCT_ALIGNED

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined ( __ICCARM__ )          /* !< IAR Compiler */
        #pragma data_alignment=4
    #endif
#endif

#ifdef USB_DATA_STRUCT_ALIGNED
    #if defined   (__GNUC__)            /* GNU Compiler */
        #define __ALIGN_END    __attribute__ ((aligned (4)))
        #define __ALIGN_BEGIN         
    #else                           
        #define __ALIGN_END
        #if defined   (__CC_ARM)        /* ARM Compiler */
            #define __ALIGN_BEGIN    __align(4)  
        #elif defined (__ICCARM__)      /* IAR Compiler */
            #define __ALIGN_BEGIN
        #endif /* __CC_ARM */  
    #endif /* __GNUC__ */ 
#else
    #define __ALIGN_BEGIN
    #define __ALIGN_END   
#endif

// 使用__packed关键字，实现1字节对齐
#if defined (__CC_ARM)                  /* ARM Compiler */
//    #define __packed    __packed
#elif defined (__ICCARM__)              /* IAR Compiler */
//    #define __packed    __packed
#elif defined   ( __GNUC__ )            /* GNU Compiler */                        
    #define __packed    __attribute__ ((__packed__))
#endif /* __CC_ARM */

#endif
