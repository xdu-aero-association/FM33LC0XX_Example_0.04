#include "lcd.h"
#include "user_init.h"

// Device IC: ST7789VW
// Interface: 4 Line SPI
// Resolution: 240(H)RGB x 320(V)
// Pin Assignment
// 1: GND
// 2: LEDK
// 3: LEDA  (IO)
// 4: VDD
// 5: GND
// 6: GND
// 7: D/C   (SPI)
// 8: CS    (SPI)
// 9: SCL   (SPI)
// 10: SDA  (SPI)
// 11: RESET(IO)
// 12: GND

#define LCD_RESET_SET() LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9)
#define LCD_RESET_RST() LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_9)

#define LCD_BACKLIGHT_SET() LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_10)
#define LCD_BACKLIGHT_RST() LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_10)

void LcdInit(void)
{
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    SpiInit();
    
    LCD_RESET_SET();
    LCD_BACKLIGHT_SET();
    
    GPIO_InitStruct.Pin = LL_GPIO_PIN_9 | LL_GPIO_PIN_10;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DISABLE;
    GPIO_InitStruct.RemapPin = DISABLE;
    
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    
    // Reset
    LCD_RESET_SET();
    DelayMs(1);
    LCD_RESET_RST();
    DelayMs(2);
    LCD_RESET_SET();
    DelayMs(3);
    
    // Exit power sleep mode
    DelayMs(5);
    SpiWriteCmd(0x11);
    DelayMs(120);
    
    // Config
    SpiWriteCmd(0xb2);
    SpiWriteData(0x0c);
    SpiWriteData(0x0c);
    SpiWriteData(0x00);
    SpiWriteData(0x33);
    SpiWriteData(0x33);
    
    SpiWriteCmd(0xb7);
    SpiWriteData(0x35);
    
    SpiWriteCmd(0xbb);
    SpiWriteData(0x19);
    
    SpiWriteCmd(0xc0);
    SpiWriteData(0x2c);
    
    SpiWriteCmd(0xc2);
    SpiWriteData(0x01);
    
    SpiWriteCmd(0xc3);
    SpiWriteData(0x12);
    
    SpiWriteCmd(0xc4);
    SpiWriteData(0x20);
    
    SpiWriteCmd(0xc6);
    SpiWriteData(0x0f);
    
    SpiWriteCmd(0xd0);
    SpiWriteData(0xa4);
    SpiWriteData(0xa1);
    
    SpiWriteCmd(0x36);
    // C0-竖显模式，RGB模式
    // C8-竖显模式，BGR模式
    // A0-横显模式，RGB模式
    // A8-横显模式，BGR模式
    SpiWriteData(0xa0);
    
    SpiWriteCmd(0xe0);
    SpiWriteData(0xd0);
    SpiWriteData(0x04);
    SpiWriteData(0x0d);
    SpiWriteData(0x11);
    SpiWriteData(0x13);
    SpiWriteData(0x2b);
    SpiWriteData(0x3f);
    SpiWriteData(0x54);
    SpiWriteData(0x4c);
    SpiWriteData(0x18);
    SpiWriteData(0x0d);
    SpiWriteData(0x0b);
    SpiWriteData(0x1f);
    SpiWriteData(0x23);
    
    SpiWriteCmd(0xe1);
    SpiWriteData(0xd0);
    SpiWriteData(0x04);
    SpiWriteData(0x0c);
    SpiWriteData(0x11);
    SpiWriteData(0x13);
    SpiWriteData(0x2c);
    SpiWriteData(0x3f);
    SpiWriteData(0x44);
    SpiWriteData(0x51);
    SpiWriteData(0x2f);
    SpiWriteData(0x1f);
    SpiWriteData(0x1f);
    SpiWriteData(0x20);
    SpiWriteData(0x23);
    
    SpiWriteCmd(0x21);
    
    SpiWriteCmd(0x3a);
    SpiWriteData(0x05);
    
    SpiWriteCmd(0x29);
    
    LcdClear(WHITE);
}

/**
 * @brief   设置显示区域。
 * @param   x1: x轴显示起始位置。
 * @param   x2: x轴显示结束位置
 * @param   y1: y轴显示起始位置。
 * @param   y2: y轴显示结束位置。
 * @return  无。
 */
void LcdSetPosition(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2)
{
    SpiWriteCmd(0x2a);
    SpiData16Bit();
    SpiWriteData(x1);
    SpiWriteData(x2);
    SpiData8Bit();
    
    SpiWriteCmd(0x2b);
    SpiData16Bit();
    SpiWriteData(y1);
    SpiWriteData(y2);
    SpiData8Bit();
}

/**
 * @brief   向指定区域填充指定的颜色。
 * @param   x: 填充区域的x轴起始位置。
 * @param   y: 填充区域的y轴起始位置。
 * @param   length: 填充区域的长度。
 * @param   height: 填充区域的高度。
 * @param   color: 填充颜色。
 * @return  无。
 */
void LcdFill(uint16_t x, uint16_t y, uint16_t length, uint16_t height, uint16_t color)
{
    int i = 0, j = 0;
    
    LcdSetPosition(x, x + length, y, y + height);
    
    SpiWriteCmd(0x2c);   
    SpiData16Bit();
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < height; j++)
        {
            SpiWriteData(color);
        }
    }
    SpiData8Bit();
    SpiWriteCmd(0x29);
}

/**
 * @brief   使用指定颜色清屏
 * @param   color: 清屏所用颜色。
 * @return  无。
 */
void LcdClear(uint16_t color)
{
    LcdFill(0, 0, 320, 240, color);
}

/**
 * @brief   读取驱动信息ID信息
 * @param   *id, LCD驱动器ID信息。  
 * @return  无。
 */
void LcdReadID(uint8_t *id)
{
    SpiReadData(0x04, id, 4);
}


