#include "main.h"
#include "user_init.h"
#include "atim.h"

void ATIM_IRQHandler(void)
{
    if (( LL_ATIM_IsEnabledIT_UPDATE(ATIM) == SET ) &&(LL_ATIM_IsActiveFlag_UPDATE(ATIM)==SET))
    {	 
        LL_ATIM_ClearFlag_UPDATE(ATIM);    
        LED0_TOG();      
    }			
}

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
    
    ATIM_Init();
    while(1)
    {     
      
    }
}


