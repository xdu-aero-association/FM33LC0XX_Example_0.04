#include "main.h"
#include "user_init.h"
#include "sleep.h"
#include "wkup.h"

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
    WKUP_init();// wkup÷–∂œ≥ı ºªØ
    while(1)
    {
//        LED0_TOG();    
//        Sleep();    
        DeepSleep();
    }
}


