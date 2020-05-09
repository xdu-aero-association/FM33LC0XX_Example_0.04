#include "main.h"
#include "user_init.h"
#include "lcd.h"

uint8_t number = 0;

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
    
    LcdInit();
    LcdDisplayAll(true);
    DelayMs(3000);
    LcdDisplayAll(false);
    DelayMs(3000);
    
    while(1)
    {     
        LED0_TOG();
        
        LcdDisplayBIT(1, 3, true);
        LcdDisplayNumber(number++);
        DelayMs(100);
    }
}


