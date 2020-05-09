#include "main.h"
#include "user_init.h"
#include "flash.h"

#define LENGTH  256
uint8_t fBuff[LENGTH];

int main(void)
{
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    /* SHOULD BE KEPT!!! */
    MF_Clock_Init();
    
    /* Configure the system clock */
    /* SHOULD BE KEPT!!! */
    MF_SystemClock_Config();
    
    /* Initialize all configured peripherals */
    /* SHOULD BE KEPT!!! */
    MF_Config_Init();
    
    UserInit();
    
    LL_FLASH_PageErase(FLASH, 0x10000);
    memset(fBuff, 0x00, LENGTH);
    FlashReadDma(0x10000, fBuff, LENGTH);
    memset(fBuff, 0x55, LENGTH);
    FlashWriteDma(0x10000, fBuff);
    memset(fBuff, 0x00, LENGTH);
    FlashReadDma(0x10000, fBuff, LENGTH);
    
    LL_FLASH_PageErase(FLASH, 0x10000);
    memset(fBuff, 0x00, LENGTH);
    FlashReadDma(0x10000, fBuff, LENGTH);
    memset(fBuff, 0xAA, LENGTH);
    FlashWriteDma(0x10000, fBuff);
    memset(fBuff, 0x00, LENGTH);
    FlashReadDma(0x10000, fBuff, LENGTH);
    
    LL_FLASH_PageErase(FLASH, 0x10000);
    
    while(1)
    {     
        LED0_TOG();
        DelayMs(1000);
    }
}


