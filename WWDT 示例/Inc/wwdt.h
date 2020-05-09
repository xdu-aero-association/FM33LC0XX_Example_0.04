#ifndef __WWDT_H
#define __WWDT_H
#ifdef __cplusplus
extern "C" {
#endif
	
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33xx.h"
	
ErrorStatus WWDT_Init(void);
ErrorStatus Test_WWDT(void);

#ifdef __cplusplus
}
#endif

#endif /* __WWDT_H */

/************************ (C) COPYRIGHT FMSH *****END OF FILE****/
