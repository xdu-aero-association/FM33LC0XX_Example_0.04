#include "main.h"
#include "user_init.h"
#include "spi.h"

uint8_t wBuffer[8] = {0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff};
uint8_t rBuffer[8];

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
    SpiInit();
    
    SpiWriteDataDMA((uint32_t)wBuffer, 8);
    while (!(SpiWriteDataComplete()));
    SpiReadDataDMA((uint32_t)rBuffer, 8);
    while (!(SpiReadDataComplete()));
    
    while(1)
    {     
        LED0_TOG();
        DelayMs(1000);
    }
}


