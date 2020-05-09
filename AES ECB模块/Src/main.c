#include "main.h"
#include "user_init.h"
#include "aes.h"
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
    
		/* AES的ECB模式测试程序 */
		Test_AES_ECB();
    while(1)
    {     
        LED0_TOG();
        DelayMs(1000);
    }
}


