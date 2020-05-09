#ifndef __LPUART_H__
#define __LPUART_H__
#include "main.h"

typedef struct 
{
	uint8_t *TxBuf;	//发送数据指针
	uint8_t TxLen;	//待发送数据长度
	uint8_t TxOpc;	//已发送数据长度
	uint8_t *RxBuf;	//接收数据指针
	uint8_t RxLen;	//待接收数据长度
	uint8_t RxOpc;	//已接收数据长度
}LPUARTOpTypeDef;

void LPUART_Init(LPUART_Type* LPUARTx);
void LPUART_Test(LPUART_Type* LPUARTx);

#endif

