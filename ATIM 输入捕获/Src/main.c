#include "main.h"
#include "user_init.h"
#include "atim.h"

uint32_t  IC1Value=0;
uint32_t  IC2Value=0;
uint32_t  DutyCycle=0;
uint32_t  Frequency=0;
uint32_t  count=0;

void ATIM_IRQHandler(void)
{    
  if(count==1)
  {
    IC1Value =LL_ATIM_GetCompareCH1(ATIM);
    IC2Value =LL_ATIM_GetCompareCH2(ATIM);
    LL_ATIM_DisableCounter(ATIM); 
    DutyCycle=(100*IC2Value/IC1Value); //占空比
    Frequency= (8000000/8000/IC1Value);//频率 主时钟为8MHZ、8000分频的计算公式
  }
  LL_ATIM_ClearFlag_CC(ATIM,LL_ATIM_CHANNEL_1); 
  LL_ATIM_ClearFlag_CC(ATIM,LL_ATIM_CHANNEL_2);
  count++;
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
    
    ATIM_CAPTURE_Init();
    
    while(1)
    {     
      
    }
}


