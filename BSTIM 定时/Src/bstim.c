#include "bstim.h"
#include "main.h"

void BSTIM_Init(void)
{
    LL_BSTIM_InitTypeDef   InitStructer;
    
    InitStructer.Prescaler         = 799;
    InitStructer.Autoreload        = 9999;    
    InitStructer.AutoreloadState   = ENABLE;
    InitStructer.ClockSource       = LL_RCC_BSTIM_OPERATION_CLK_SOURCE_APBCLK2;
  
    LL_BSTIM_Init(BSTIM,&InitStructer);
    
    
  
    NVIC_DisableIRQ(BSTIM_IRQn);
    NVIC_SetPriority(BSTIM_IRQn, 2);
    NVIC_EnableIRQ(BSTIM_IRQn);
    
    LL_BSTIM_ClearFlag_UpdataEvent(BSTIM);
    LL_BSTIM_EnabledIT_UpdataEvent(BSTIM);
  
    LL_BSTIM_EnableCounter(BSTIM);
}
