#include "main.h"
#include "user_init.h"
#include "u7816.h"

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
    
    U7816_Init(); //7816≥ı ºªØ
    ColdReset();  //¿‰∏¥Œª
    
    while(1)
    {     
      
    }
}


