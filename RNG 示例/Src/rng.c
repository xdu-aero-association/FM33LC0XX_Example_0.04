#include "main.h"
#include "rng.h"

/* crc32实现函数 = CRC-32/MPEG-2       x32+x26+x23+x22+x16+x12+x11+x10+x8+x7+x5+x4+x2+x+1 */
//static uint32_t Calc_Crc32_MPEG2(const uint8_t *data, uint32_t len)
//{
//    uint32_t crc = 0XFFFFFFFF;
//    uint32_t i = 0, j = 0;
//    while((len--)!=0)
//    {
//        crc ^= (uint32_t)*(data + j) <<24;
//		j++;
//		for (i = 0; i < 8; i++)
//		{
//			if((crc&0x80000000) !=0)	
//			{
//				crc = (crc<<1)^0x4C11DB7;
//			}
//			else
//			{
//				crc<<=1;
//			}
//		}
//    }
//    return crc;
//}

/* RNG初始化 */
ErrorStatus RNG_Init(void)
{
	LL_RNG_InitTypeDef InitStruct;
	LL_RNG_StructInit(&InitStruct);
	/* RNG Clock 分频系数*/
	InitStruct.Prescaler = LL_RCC_RNG_OPERATION_CLOCK_PRESCALER_DIV2;
	return LL_RNG_Init(RNG,&InitStruct);
}

ErrorStatus Test_RNG(void)
{
	ErrorStatus status = PASS;
	uint32_t rn32,crc32;
	status = RNG_Init();
	if(status == FAIL)
	{
		return FAIL;
	}
  rn32 =  GetRandomNumber();
	if(rn32 == 0xFFFFFFFF)
	{
		return FAIL;
	}
	crc32 = GetCrc32(rn32);
	if(crc32 == 0xFFFFFFFF)
	{
		return FAIL;
	}
//	/* 比较软件算法和模块计算的结果，方便查看结果正确性，（后续若用模块计算的硬算法下面的代码可注释） */
//	{
//		uint8_t buffer[4];
//		uint32_t crc32_MPEG2;
//		buffer[0] = rn32 >> 24;
//		buffer[1] = rn32 >> 16;
//		buffer[2] = rn32 >> 8;
//		buffer[3] = rn32;
//		crc32_MPEG2 = Calc_Crc32_MPEG2(buffer,sizeof(buffer));
//		if(crc32_MPEG2 != crc32)
//		{
//			return FAIL;
//		}
//	}
	return PASS;
}
