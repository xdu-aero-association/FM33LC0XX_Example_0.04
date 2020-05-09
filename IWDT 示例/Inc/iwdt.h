
#ifndef __IWDT_H
#define __IWDT_H
#ifdef __cplusplus
extern "C" {
#endif
	
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
	
ErrorStatus IWDT_Init(void);
ErrorStatus Test_IWDT(void);
void IWDT_Clr(void);
  
#ifdef __cplusplus
}
#endif

#endif /* __IWDT_H */

/************************ (C) COPYRIGHT FMSH *****END OF FILE****/
