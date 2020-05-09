#include "crc.h"

uint8_t CRC7_MMC(uint8_t *data, uint32_t length)
{
    LL_CRC_InitTypeDef CRC_InitStruct;
    
    CRC_InitStruct.CalculatMode = LL_CRC_CALCULA_MODE_SERIAL;
    CRC_InitStruct.DataWidth = LL_CRC_CRC_DR_WIDTH_BYTE;
    CRC_InitStruct.InitVel = 0x00;
    CRC_InitStruct.Polynomial = 0x09;
    CRC_InitStruct.PolynomialWidth = LL_CRC_POLYNOMIAL_WIDTH_7BIT;
    CRC_InitStruct.ReflectIn = LL_CRC_INPUT_REFLECTE_MODE_NOMAL;
    CRC_InitStruct.ReflectOut = LL_CRC_OUPUT_REFLECTE_MODE_NOMAL;
    CRC_InitStruct.XorReg = 0x0000;
    CRC_InitStruct.XorRegState = DISABLE;
    LL_CRC_Init(CRC, &CRC_InitStruct);

    while (length--)
    {
        LL_CRC_SetDataReg(CRC, *data++);
        while (LL_CRC_IsActiveFlag_Busy(CRC));
    }
    
    return LL_CRC_GetDataReg(CRC) & 0x7f;
}

uint8_t CRC8(uint8_t *data, uint32_t length)
{
    LL_CRC_InitTypeDef CRC_InitStruct;
    
    CRC_InitStruct.CalculatMode = LL_CRC_CALCULA_MODE_SERIAL;
    CRC_InitStruct.DataWidth = LL_CRC_CRC_DR_WIDTH_BYTE;
    CRC_InitStruct.InitVel = 0x00;
    CRC_InitStruct.Polynomial = 0x07;
    CRC_InitStruct.PolynomialWidth = LL_CRC_POLYNOMIAL_WIDTH_8BIT;
    CRC_InitStruct.ReflectIn = LL_CRC_INPUT_REFLECTE_MODE_NOMAL;
    CRC_InitStruct.ReflectOut = LL_CRC_OUPUT_REFLECTE_MODE_NOMAL;
    CRC_InitStruct.XorReg = 0x0000;
    CRC_InitStruct.XorRegState = DISABLE;
    LL_CRC_Init(CRC, &CRC_InitStruct);

    while (length--)
    {
        LL_CRC_SetDataReg(CRC, *data++);
        while (LL_CRC_IsActiveFlag_Busy(CRC));
    }
    
    return LL_CRC_GetDataReg(CRC) & 0xff;
}

uint16_t CRC16_CCITT(uint8_t *data, uint32_t length)
{
    LL_CRC_InitTypeDef CRC_InitStruct;
    
    CRC_InitStruct.CalculatMode = LL_CRC_CALCULA_MODE_SERIAL;
    CRC_InitStruct.DataWidth = LL_CRC_CRC_DR_WIDTH_BYTE;
    CRC_InitStruct.InitVel = 0x0000;
    CRC_InitStruct.Polynomial = 0x1021;
    CRC_InitStruct.PolynomialWidth = LL_CRC_POLYNOMIAL_WIDTH_16BIT;
    CRC_InitStruct.ReflectIn = LL_CRC_INPUT_REFLECTE_MODE_BYTE;
    CRC_InitStruct.ReflectOut = LL_CRC_OUPUT_REFLECTE_MODE_REVERSE;
    CRC_InitStruct.XorReg = 0x0000;
    CRC_InitStruct.XorRegState = DISABLE;
    LL_CRC_Init(CRC, &CRC_InitStruct);

    while (length--)
    {
        LL_CRC_SetDataReg(CRC, *data++);
        while (LL_CRC_IsActiveFlag_Busy(CRC));
    }
    
    return LL_CRC_GetDataReg(CRC) & 0xffff;
}

uint32_t CRC32(uint8_t *data, uint32_t length)
{
    LL_CRC_InitTypeDef CRC_InitStruct;
    
    CRC_InitStruct.CalculatMode = LL_CRC_CALCULA_MODE_SERIAL;
    CRC_InitStruct.DataWidth = LL_CRC_CRC_DR_WIDTH_BYTE;
    CRC_InitStruct.InitVel = 0xffffffff;
    CRC_InitStruct.Polynomial = 0x04c11db7;
    CRC_InitStruct.PolynomialWidth = LL_CRC_POLYNOMIAL_WIDTH_32BIT;
    CRC_InitStruct.ReflectIn = LL_CRC_INPUT_REFLECTE_MODE_BYTE;
    CRC_InitStruct.ReflectOut = LL_CRC_OUPUT_REFLECTE_MODE_REVERSE;
    CRC_InitStruct.XorReg = 0xffffffff;
    CRC_InitStruct.XorRegState = ENABLE;
    LL_CRC_Init(CRC, &CRC_InitStruct);

    while (length--)
    {
        LL_CRC_SetDataReg(CRC, *data++);
        while (LL_CRC_IsActiveFlag_Busy(CRC));
    }
    
    return LL_CRC_GetDataReg(CRC);
}

uint16_t CRC16_CCITT_WORD(uint32_t *data, uint32_t length)
{
    LL_CRC_InitTypeDef CRC_InitStruct;
    
    CRC_InitStruct.CalculatMode = LL_CRC_CALCULA_MODE_SERIAL;
    CRC_InitStruct.DataWidth = LL_CRC_CRC_DR_WIDTH_WORD;
    CRC_InitStruct.InitVel = 0x0000;
    CRC_InitStruct.Polynomial = 0x1021;
    CRC_InitStruct.PolynomialWidth = LL_CRC_POLYNOMIAL_WIDTH_16BIT;
    CRC_InitStruct.ReflectIn = LL_CRC_INPUT_REFLECTE_MODE_WORD;
    CRC_InitStruct.ReflectOut = LL_CRC_OUPUT_REFLECTE_MODE_REVERSE;
    CRC_InitStruct.XorReg = 0x0000;
    CRC_InitStruct.XorRegState = DISABLE;
    LL_CRC_Init(CRC, &CRC_InitStruct);

    while (length--)
    {
        LL_CRC_SetDataReg(CRC, *data++);
        while (LL_CRC_IsActiveFlag_Busy(CRC));
    }
    
    return LL_CRC_GetDataReg(CRC) & 0xffff;
}
