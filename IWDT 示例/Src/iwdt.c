#include "main.h"
/* IWDT初始化 */
ErrorStatus IWDT_Init(void)
{
	LL_IWDT_InitTypeDef IWDT_InitStruct;
	/* 默认不使用窗口 */
	IWDT_InitStruct.IwdtWindows    = 0;
	/*最长溢出时间*/
	IWDT_InitStruct.OverflowPeriod = LL_IWDT_IWDT_OVERFLOW_PERIOD_8000MS;
	return LL_IWDT_Init(IWDT, &IWDT_InitStruct);
}

ErrorStatus Test_IWDT(void)
{
	return IWDT_Init();
}

void IWDT_Clr(void)
{
  LL_IWDG_ReloadCounter(IWDT);
}
