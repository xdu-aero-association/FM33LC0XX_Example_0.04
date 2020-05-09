#include "main.h"
#include "user_init.h"
#include "lpuart.h"

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
    
    LPUART_Init(LPUART0);
    
    LPUART_Test(LPUART0);
    
    while(1)
    {     
      
    }
}


