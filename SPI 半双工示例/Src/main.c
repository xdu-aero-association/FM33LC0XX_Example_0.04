#include "main.h"
#include "user_init.h"
#include "lcd.h"

uint8_t id[4];  // 85H 85H 52H xxH

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
    
    LcdReadID(&id[0]);
    while(1)
    {
        LED0_TOG();
        LcdClear(RED);
        LED0_TOG();
        LcdClear(GREEN);
        LED0_TOG();
        LcdClear(BLUE);
    }
}


