#include "main.h"
/* HDIV初始化 */
ErrorStatus HDIV_Init(void)
{
	return LL_HDIV_Init(HDIV);
}

ErrorStatus Test_HDIV(void)
{
	int32_t DivisorEnd = 5;//被除数
	int16_t Divisor = 2;//除数
	int32_t Quotient;
	int16_t Residue;
	uint32_t result = 0;
	HDIV_Init();
	result = LL_HDIV_Calculation(HDIV,DivisorEnd,Divisor,&Quotient, &Residue);
	if(result == 0)
	{
		if((Quotient == (DivisorEnd/Divisor)) && (Residue == (DivisorEnd%Divisor)))
			return PASS;
	}
	return FAIL;
}

