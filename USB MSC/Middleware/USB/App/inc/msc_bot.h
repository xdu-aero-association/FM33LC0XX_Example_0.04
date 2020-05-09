#ifndef __MSC_BOT_H__
#define __MSC_BOT_H__

#include "usbd_core.h"

/* BOT State */
#define BOT_IDLE                      0       /* Idle state */
#define BOT_DATA_OUT                  1       /* Data Out state */
#define BOT_DATA_IN                   2       /* Data In state */
#define BOT_LAST_DATA_IN              3       /* Last Data In Last */
#define BOT_SEND_DATA                 4       /* Send Immediate data */

/* BOT Status */
#define BOT_STATE_NORMAL              0
#define BOT_STATE_RECOVERY            1
#define BOT_STATE_ERROR               2

#define DIR_IN                        0
#define DIR_OUT                       1
#define BOTH_DIR                      2

// CBW and CSW Const Define
#define BOT_CBW_SIGNATURE             0x43425355
#define BOT_CSW_SIGNATURE             0x53425355
#define BOT_CBW_LENGTH                31
#define BOT_CSW_LENGTH                13

// CSW Status Definitions
#define CSW_CMD_PASSED                0x00  // 成功
#define CSW_CMD_FAILED                0x01  // 失败
#define CSW_PHASE_ERROR               0x02  // 阶段错误

// Commmand Block Wrapper
typedef struct _MSC_BOT_CBW
{
    uint32_t dSignature;    // CBW标识,0x43425355("USBC")    
    uint32_t dTag;          // CBW标签，由主机分配
    uint32_t dDataLength;   // 数据阶段传输的数据长度
    uint8_t  bmFlags;       // CBW标志位
    uint8_t  bLUN;          // 目标逻辑单元编号
    uint8_t  bCBLength;     // CBWCB的长度
    uint8_t  CB[16];        // CBWCB，需要执行的命令
} MSC_BOT_CBW_TypeDef;

// Commmand Status Wrapper
typedef struct _MSC_BOT_CSW
{
    uint32_t dSignature;    // CSW标识,0x53425355("USBS")   
    uint32_t dTag;          // CSW标签，与CBW标签对应
    uint32_t dDataResidue;  // 命令完成时剩余的字节数
    uint8_t  bStatus;       // 命令执行状态
} MSC_BOT_CSW_TypeDef;


extern uint8_t              MSC_BOT_Data[];
extern uint16_t             MSC_BOT_DataLen;
extern uint8_t              MSC_BOT_State;
extern uint8_t              MSC_BOT_BurstMode;
extern MSC_BOT_CBW_TypeDef  MSC_BOT_cbw;
extern MSC_BOT_CSW_TypeDef  MSC_BOT_csw;


void MSC_BOT_Init(void *pdev);
void MSC_BOT_Reset(void *pdev);
void MSC_BOT_DeInit(void *pdev);

void MSC_BOT_DataIn(void *pdev, uint8_t epnum);
void MSC_BOT_DataOut(void *pdev, uint8_t epnum);

void MSC_BOT_SendCSW(void *pdev, uint8_t CSW_Status);
void  MSC_BOT_CplClrFeature(void *pdev, uint8_t epnum);

#endif

