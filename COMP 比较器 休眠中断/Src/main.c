#include "main.h"
#include "user_init.h"
#include "compare.h"
#include "sleep.h"

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
    
//    COMP_IO_Init();//引脚配置
    
//    COMP1_Init();//初始化
//    LL_GPIO_SetFout0(GPIO_COMMON, LL_GPIO_FOUT0_SELECT_COMP1_OUTPUT);//COMP1_OUT(FOUT0)    //引脚输出
    COMP2_Init();//初始化
//    LL_GPIO_SetFout1(GPIO_COMMON, LL_GPIO_FOUT1_SELECT_COMP2_OUTPUT);//COMP2_OUT(FOUT1) //引脚输出  

    while(1)
    {     
//        Sleep();    
//        DeepSleep();    
    }
}


