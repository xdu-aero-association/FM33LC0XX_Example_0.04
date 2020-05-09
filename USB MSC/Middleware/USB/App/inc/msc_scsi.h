#ifndef __MSC_SCSI_H__
#define __MSC_SCSI_H__

#include <stdint.h>
#include "usb_core.h"
#include "usbd_def.h"


#define SENSE_LIST_DEEPTH                          4

/* SCSI Commands */
#define SCSI_FORMAT_UNIT                            0x04
#define SCSI_INQUIRY                                0x12    // 获取设备信息
#define SCSI_MODE_SELECT6                           0x15    // 允许host对外部设备设置参数
#define SCSI_MODE_SELECT10                          0x55    // 允许host对外部设备设置参数
#define SCSI_MODE_SENSE6                            0x1A    // 向host传输参数
#define SCSI_MODE_SENSE10                           0x5A    // 向host传输参数
#define SCSI_ALLOW_MEDIUM_REMOVAL                   0x1E    // 禁止/允许存储介质移动
#define SCSI_READ6                                  0x08
#define SCSI_READ10                                 0x28    // host从设备读取数据
#define SCSI_READ12                                 0xA8
#define SCSI_READ16                                 0x88

#define SCSI_READ_CAPACITY10                        0x25    // 读取设备容量
#define SCSI_READ_CAPACITY16                        0x9E    

#define SCSI_REQUEST_SENSE                          0x03    // 主机请求设备返回执行结果，及获取状态信息
#define SCSI_START_STOP_UNIT                        0x1B    // 启动停止存储单元电源（写保护）
#define SCSI_TEST_UNIT_READY                        0x00    // 查询设备是否Ready
#define SCSI_WRITE6                                 0x0A
#define SCSI_WRITE10                                0x2A    // host向存储设备写数据
#define SCSI_WRITE12                                0xAA
#define SCSI_WRITE16                                0x8A

#define SCSI_VERIFY10                               0x2F    // 在存储中验证数据
#define SCSI_VERIFY12                               0xAF
#define SCSI_VERIFY16                               0x8F

#define SCSI_SEND_DIAGNOSTIC                        0x1D
#define SCSI_READ_FORMAT_CAPACITIES                 0x23    // 查询当前容量及可用空间

#define SCSI_START_OR_STOP_UINT                     0x1B    // 启动或停止存储单元电源（写保护）

#define SCSI_REPORT_LUNS                            0xA0    // 索取设备的LUN数和LUN清单

#define NO_SENSE                                    0
#define RECOVERED_ERROR                             1
#define NOT_READY                                   2
#define MEDIUM_ERROR                                3
#define HARDWARE_ERROR                              4
#define ILLEGAL_REQUEST                             5
#define UNIT_ATTENTION                              6
#define DATA_PROTECT                                7
#define BLANK_CHECK                                 8
#define VENDOR_SPECIFIC                             9
#define COPY_ABORTED                               10
#define ABORTED_COMMAND                            11
#define VOLUME_OVERFLOW                            13
#define MISCOMPARE                                 14


#define INVALID_CDB                                 0x20
#define INVALID_FIELED_IN_COMMAND                   0x24
#define PARAMETER_LIST_LENGTH_ERROR                 0x1A
#define INVALID_FIELD_IN_PARAMETER_LIST             0x26
#define ADDRESS_OUT_OF_RANGE                        0x21
#define MEDIUM_NOT_PRESENT                          0x3A
#define MEDIUM_HAVE_CHANGED                         0x28
#define WRITE_PROTECTED                             0x27 
#define UNRECOVERED_READ_ERROR			            0x11
#define WRITE_FAULT				                    0x03 

#define READ_FORMAT_CAPACITY_DATA_LEN               0x0C
#define READ_CAPACITY10_DATA_LEN                    0x08
#define MODE_SENSE10_DATA_LEN                       0x08
#define MODE_SENSE6_DATA_LEN                        0x04
#define REQUEST_SENSE_DATA_LEN                      0x12
#define STANDARD_INQUIRY_DATA_LEN                   0x24
#define BLKVFY                                      0x04

extern uint8_t Page00_Inquiry_Data[];
extern uint8_t Standard_Inquiry_Data[];
extern uint8_t Standard_Inquiry_Data2[];
extern uint8_t Mode_Sense6_data[];
extern uint8_t Mode_Sense10_data[];
extern uint8_t Scsi_Sense_Data[];
extern uint8_t ReadCapacity10_Data[];
extern uint8_t ReadFormatCapacity_Data [];

typedef struct _SENSE_ITEM {                
    uint8_t Skey;
    union {
        struct _ASCs {
            uint8_t ASC;
            uint8_t ASCQ;
        }b;
        uint32_t ASC;
        uint8_t *pData;
    } w;
} SCSI_Sense_TypeDef; 

extern SCSI_Sense_TypeDef SCSI_Sense[SENSE_LIST_DEEPTH]; 
extern uint8_t SCSI_Sense_Head;
extern uint8_t SCSI_Sense_Tail;

int8_t SCSI_ProcessCmd(void *pdev, uint8_t lun, uint8_t *cmd);
void SCSI_SenseCode(uint8_t lun, uint8_t sKey, uint8_t ASC);

#endif

