#include "main.h"
#include "user_init.h"
#include "bstim.h"

void BSTIM_IRQHandler(void)
{
    if (( LL_BSTIM_IsEnabledIT_UpdataEvent(BSTIM) == SET ) &&(LL_BSTIM_IsActiveFlag_UpdataEvent(BSTIM)==SET))
    {	 
        LL_BSTIM_ClearFlag_UpdataEvent(BSTIM);    
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
    BSTIM_Init();
    while(1)
    {     
       
    }
}

