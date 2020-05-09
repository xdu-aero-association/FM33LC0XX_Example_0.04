#include "lcd.h"

void LcdInit(void)
{
    LL_GPIO_InitTypeDef GPIO_InitStruction;
    LL_LCD_InitTypeDef LCD_InitStruction;
    
    // GPIO Init
    GPIO_InitStruction.Pin = LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | 
        LL_GPIO_PIN_3 | LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_8 | 
        LL_GPIO_PIN_9 | LL_GPIO_PIN_10;
    GPIO_InitStruction.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruction.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruction.Pull = DISABLE;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruction);
    
    GPIO_InitStruction.Pin = LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_6 |
        LL_GPIO_PIN_7 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 |
        LL_GPIO_PIN_11 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14;
    GPIO_InitStruction.Mode = LL_GPIO_MODE_ANALOG;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruction);
    
    GPIO_InitStruction.Pin = LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_6 |
        LL_GPIO_PIN_7 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 |
        LL_GPIO_PIN_11 | LL_GPIO_PIN_12;
    GPIO_InitStruction.Mode = LL_GPIO_MODE_ANALOG;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruction);
    
    GPIO_InitStruction.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruction.Mode = LL_GPIO_MODE_ANALOG;
    LL_GPIO_Init(GPIOD, &GPIO_InitStruction);
    
    // LCD Init
    LCD_InitStruction.BiasMode = LL_LCD_SET_BIASMD_DIV3BIAS;
    LCD_InitStruction.BiasVoltage = LL_LCD_GRAY_SCALE_CTRL_LEVEL_10;
    LCD_InitStruction.COMxNum = LL_LCD_SEG_LINE_SELECT_COM_6;
    LCD_InitStruction.EnableMode = LL_LCD_DRV_ENMODE_INNERRESISTER;
    LCD_InitStruction.FreqPsc = 64;
    LCD_InitStruction.ICCtrl = LL_LCD_DRV_IC_CTRL_LARGE;
    LCD_InitStruction.Waveform = LL_LCD_WAVEFORM_FORMAT_TYPE_A;
    LL_LCD_Init(LCD, &LCD_InitStruction);
    
    // COM and SEG Init
    LL_LCD_EnableComPin(LCD, LL_LCD_COM_EN_COM0);
    LL_LCD_EnableComPin(LCD, LL_LCD_COM_EN_COM1);
    LL_LCD_EnableComPin(LCD, LL_LCD_COM_EN_COM2);
    LL_LCD_EnableComPin(LCD, LL_LCD_COM_EN_COM3);
    LL_LCD_EnableComPin(LCD, LL_LCD_COM_EN_COM4);
    LL_LCD_EnableComPin(LCD, LL_LCD_COM_EN_COM5);

    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG0);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG1);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG2);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG3);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG4);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG5);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG6);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG7);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG8);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG9);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG10);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG11);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG12);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG13);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG14);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG15);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG16);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG17);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG18);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG19);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG20);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG21);
    LL_LCD_EnableSegPin(LCD, LL_LCD_SEG_EN0_SEG22);
    
    LL_LCD_Enable(LCD);
}

void LcdDisplayAll(bool state)
{
    if (state == true)
    {
        LL_LCD_SetDisplayData(LCD, 0x007fffff, LL_LCD_DATA_REG_0);
        LL_LCD_SetDisplayData(LCD, 0x007fffff, LL_LCD_DATA_REG_1);
        LL_LCD_SetDisplayData(LCD, 0x007fffff, LL_LCD_DATA_REG_2);
        LL_LCD_SetDisplayData(LCD, 0x007fffff, LL_LCD_DATA_REG_3);
        LL_LCD_SetDisplayData(LCD, 0x007fffff, LL_LCD_DATA_REG_4);
        LL_LCD_SetDisplayData(LCD, 0x007fffff, LL_LCD_DATA_REG_5);
    }
    else
    {
        LL_LCD_SetDisplayData(LCD, 0x00000000, LL_LCD_DATA_REG_0);
        LL_LCD_SetDisplayData(LCD, 0x00000000, LL_LCD_DATA_REG_1);
        LL_LCD_SetDisplayData(LCD, 0x00000000, LL_LCD_DATA_REG_2);
        LL_LCD_SetDisplayData(LCD, 0x00000000, LL_LCD_DATA_REG_3);
        LL_LCD_SetDisplayData(LCD, 0x00000000, LL_LCD_DATA_REG_4);
        LL_LCD_SetDisplayData(LCD, 0x00000000, LL_LCD_DATA_REG_5);
    }
}

#define LCD_SET_BIT(data, bit)  ((data) |= (0x1 << (bit)))
#define LCD_RST_BIT(data, bit)  ((data) &= ~(0x1 << (bit)))

//0~9, A,B, C, D, E, F, 空
const uint8_t FONT_CODE_TABLE[] = { 
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f,
    0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00}; 

uint32_t dispBuf[8] = {0};

void LcdDisplayRefresh(void)
{
    LL_LCD_SetDisplayData(LCD, dispBuf[0], LL_LCD_DATA_REG_0);
    LL_LCD_SetDisplayData(LCD, dispBuf[1], LL_LCD_DATA_REG_1);
    LL_LCD_SetDisplayData(LCD, dispBuf[2], LL_LCD_DATA_REG_2);
    LL_LCD_SetDisplayData(LCD, dispBuf[3], LL_LCD_DATA_REG_3);
    LL_LCD_SetDisplayData(LCD, dispBuf[4], LL_LCD_DATA_REG_4);
    LL_LCD_SetDisplayData(LCD, dispBuf[5], LL_LCD_DATA_REG_5);
    LL_LCD_SetDisplayData(LCD, dispBuf[6], LL_LCD_DATA_REG_6);
    LL_LCD_SetDisplayData(LCD, dispBuf[7], LL_LCD_DATA_REG_7);
}

// true: 点亮; false: 熄灭
void LcdDisplayBIT(uint32_t x, uint32_t y, bool value)
{    
    if (value == true)
    {
        LCD_SET_BIT(dispBuf[x - 1], y - 1);
    }
    else
    {
        LCD_RST_BIT(dispBuf[x - 1], y - 1);
    }
    LcdDisplayRefresh();
}

void LcdDisplayNumber(uint32_t number)
{      
    uint8_t digit = 8;
    uint8_t font;
        
    while (digit)
    {
        font = FONT_CODE_TABLE[number % 10];
        number /= 10;
        
        switch (digit--)
        {
        case 0x08:
            //------------ 第1个"8"字符 ----------
            if ((font & 0x01))  LCD_SET_BIT(dispBuf[1], 10);	//A
            else                LCD_RST_BIT(dispBuf[1], 10);
            if ((font & 0x02))  LCD_SET_BIT(dispBuf[2], 10);	//B
            else                LCD_RST_BIT(dispBuf[2], 10);
            if ((font & 0x04))  LCD_SET_BIT(dispBuf[3], 10);	//C
            else                LCD_RST_BIT(dispBuf[3], 10);
            if ((font & 0x08))  LCD_SET_BIT(dispBuf[4], 9);	    //D
            else                LCD_RST_BIT(dispBuf[4], 9);
            if ((font & 0x10))  LCD_SET_BIT(dispBuf[3], 9);	    //E
            else                LCD_RST_BIT(dispBuf[3], 9);
            if ((font & 0x20))  LCD_SET_BIT(dispBuf[1], 9);	    //F
            else                LCD_RST_BIT(dispBuf[1], 9);
            if ((font & 0x40))  LCD_SET_BIT(dispBuf[2], 9);	    //G
            else                LCD_RST_BIT(dispBuf[2], 9);
            break;

        case 0x07:
            //------------ 第2个"8"字符 ----------
            if ((font & 0x01))  LCD_SET_BIT(dispBuf[1], 8);	    //A
            else                LCD_RST_BIT(dispBuf[1], 8);
            if ((font & 0x02))  LCD_SET_BIT(dispBuf[2], 8);	    //B
            else                LCD_RST_BIT(dispBuf[2], 8);
            if ((font & 0x04))  LCD_SET_BIT(dispBuf[3], 8);	    //C
            else                LCD_RST_BIT(dispBuf[3], 8);
            if ((font & 0x08))  LCD_SET_BIT(dispBuf[4], 7);	    //D
            else                LCD_RST_BIT(dispBuf[4], 7);
            if ((font & 0x10))  LCD_SET_BIT(dispBuf[3], 7);	    //E
            else                LCD_RST_BIT(dispBuf[3], 7);
            if ((font & 0x20))  LCD_SET_BIT(dispBuf[1], 7);	    //F
            else                LCD_RST_BIT(dispBuf[1], 7);
            if ((font & 0x40))  LCD_SET_BIT(dispBuf[2], 7);	    //G
            else                LCD_RST_BIT(dispBuf[2], 7);		  
            break;
    
        case 0x06:
            //------------ 第3个"8"字符 ----------
            if ((font & 0x01))  LCD_SET_BIT(dispBuf[1], 6);	    //A
            else                LCD_RST_BIT(dispBuf[1], 6);
            if ((font & 0x02))  LCD_SET_BIT(dispBuf[2], 6);	    //B
            else                LCD_RST_BIT(dispBuf[2], 6);
            if ((font & 0x04))  LCD_SET_BIT(dispBuf[3], 6);	    //C
            else                LCD_RST_BIT(dispBuf[3], 6);
            if ((font & 0x08))  LCD_SET_BIT(dispBuf[4], 5);	    //D
            else                LCD_RST_BIT(dispBuf[4], 5);
            if ((font & 0x10))  LCD_SET_BIT(dispBuf[3], 5);	    //E
            else                LCD_RST_BIT(dispBuf[3], 5);
            if ((font & 0x20))  LCD_SET_BIT(dispBuf[1], 5);	    //F
            else                LCD_RST_BIT(dispBuf[1], 5);
            if ((font & 0x40))  LCD_SET_BIT(dispBuf[2], 5);	    //G
            else                LCD_RST_BIT(dispBuf[2], 5);	
            break;	
        
        case 0x05:
            //------------ 第4个"8"字符 ----------
            if ((font & 0x01))  LCD_SET_BIT(dispBuf[1], 13);	//A
            else                LCD_RST_BIT(dispBuf[1], 13);
            if ((font & 0x02))  LCD_SET_BIT(dispBuf[2], 13);	//B
            else                LCD_RST_BIT(dispBuf[2], 13);
            if ((font & 0x04))  LCD_SET_BIT(dispBuf[3], 13);	//C
            else                LCD_RST_BIT(dispBuf[3], 13);
            if ((font & 0x08))  LCD_SET_BIT(dispBuf[4], 14);	//D
            else                LCD_RST_BIT(dispBuf[4], 14);
            if ((font & 0x10))  LCD_SET_BIT(dispBuf[3], 14);	//E
            else                LCD_RST_BIT(dispBuf[3], 14);
            if ((font & 0x20))  LCD_SET_BIT(dispBuf[1], 14);	//F
            else                LCD_RST_BIT(dispBuf[1], 14);
            if ((font & 0x40))  LCD_SET_BIT(dispBuf[2], 14);	//G
            else                LCD_RST_BIT(dispBuf[2], 14);
            break;	

        case 0x04:
            //------------ 第5个"8"字符 ----------
            if ((font & 0x01))  LCD_SET_BIT(dispBuf[1], 15);	//A
            else                LCD_RST_BIT(dispBuf[1], 15);
            if ((font & 0x02))  LCD_SET_BIT(dispBuf[2], 15);	//B
            else                LCD_RST_BIT(dispBuf[2], 15);
            if ((font & 0x04))  LCD_SET_BIT(dispBuf[3], 15);	//C
            else                LCD_RST_BIT(dispBuf[3], 15);
            if ((font & 0x08))  LCD_SET_BIT(dispBuf[4], 16);	//D
            else                LCD_RST_BIT(dispBuf[4], 16);
            if ((font & 0x10))  LCD_SET_BIT(dispBuf[3], 16);	//E
            else                LCD_RST_BIT(dispBuf[3], 16);
            if ((font & 0x20))  LCD_SET_BIT(dispBuf[1], 16);	//F
            else                LCD_RST_BIT(dispBuf[1], 16);
            if ((font & 0x40))  LCD_SET_BIT(dispBuf[2], 16);	//G
            else                LCD_RST_BIT(dispBuf[2], 16);	
            break;	
    
        case 0x03:
            //------------ 第6个"8"字符 ----------
            if ((font & 0x01))  LCD_SET_BIT(dispBuf[1], 17);	//A
            else                LCD_RST_BIT(dispBuf[1], 17);
            if ((font & 0x02))  LCD_SET_BIT(dispBuf[2], 17);	//B
            else                LCD_RST_BIT(dispBuf[2], 17);
            if ((font & 0x04))  LCD_SET_BIT(dispBuf[3], 17);	//C
            else                LCD_RST_BIT(dispBuf[3], 17);
            if ((font & 0x08))  LCD_SET_BIT(dispBuf[4], 18);	//D
            else                LCD_RST_BIT(dispBuf[4], 18);
            if ((font & 0x10))  LCD_SET_BIT(dispBuf[3], 18);	//E
            else                LCD_RST_BIT(dispBuf[3], 18);
            if ((font & 0x20))  LCD_SET_BIT(dispBuf[1], 18);	//F
            else                LCD_RST_BIT(dispBuf[1], 18);
            if ((font & 0x40))  LCD_SET_BIT(dispBuf[2], 18);	//G
            else                LCD_RST_BIT(dispBuf[2], 18);
            break;	
        
        case 0x02:
            //------------ 第7个"8"字符 ----------
            if ((font & 0x01))  LCD_SET_BIT(dispBuf[1], 19);	//A
            else                LCD_RST_BIT(dispBuf[1], 19);
            if ((font & 0x02))  LCD_SET_BIT(dispBuf[2], 19);	//B
            else                LCD_RST_BIT(dispBuf[2], 19);
            if ((font & 0x04))  LCD_SET_BIT(dispBuf[3], 19);	//C
            else                LCD_RST_BIT(dispBuf[3], 19);
            if ((font & 0x08))  LCD_SET_BIT(dispBuf[4], 20);	//D
            else                LCD_RST_BIT(dispBuf[4], 20);
            if ((font & 0x10))  LCD_SET_BIT(dispBuf[3], 20);	//E
            else                LCD_RST_BIT(dispBuf[3], 20);
            if ((font & 0x20))  LCD_SET_BIT(dispBuf[1], 20);	//F
            else                LCD_RST_BIT(dispBuf[1], 20);
            if ((font & 0x40))  LCD_SET_BIT(dispBuf[2], 20);	//G
            else                LCD_RST_BIT(dispBuf[2], 20);	
            break;	
    
        case 0x01:
            //------------ 第8个"8"字符 ----------
            if ((font & 0x01))  LCD_SET_BIT(dispBuf[1], 21);	//A
            else                LCD_RST_BIT(dispBuf[1], 21);
            if ((font & 0x02))  LCD_SET_BIT(dispBuf[2], 21);	//B
            else                LCD_RST_BIT(dispBuf[2], 21);
            if ((font & 0x04))  LCD_SET_BIT(dispBuf[3], 21);	//C
            else                LCD_RST_BIT(dispBuf[3], 21);
            if ((font & 0x08))  LCD_SET_BIT(dispBuf[4], 22);	//D
            else                LCD_RST_BIT(dispBuf[4], 22);
            if ((font & 0x10))  LCD_SET_BIT(dispBuf[3], 22);	//E
            else                LCD_RST_BIT(dispBuf[3], 22);
            if ((font & 0x20))  LCD_SET_BIT(dispBuf[1], 22);	//F
            else                LCD_RST_BIT(dispBuf[1], 22);
            if ((font & 0x40))  LCD_SET_BIT(dispBuf[2], 22);	//G
            else                LCD_RST_BIT(dispBuf[2], 22);	
            break;
        }
    }
    
    LcdDisplayRefresh();
}
