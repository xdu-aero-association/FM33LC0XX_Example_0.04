#include "flash.h"

// Flash DMA通道读最大长度为8192字节(2048 word)，只支持WORD传输
void FlashReadDma(uint32_t addr, uint8_t *buffer, uint32_t length)
{
    LL_DMA_InitTypeDef DMA_InitStruct;
    
    DMA_InitStruct.CircMode = DISABLE;
    DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_BYTE;
    DMA_InitStruct.Direction = LL_DMA_DIR_FLASH_TO_RAM;
    DMA_InitStruct.MemoryAddressIncMode = LL_DMA_CH7_RAM_ADDR_INCREASE;
    DMA_InitStruct.FlashAddressIncMode = LL_DMA_CH7_FLASH_ADDR_INCREASE;
    DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;
    DMA_InitStruct.PeriphAddress = addr >> 2;
    DMA_InitStruct.MemoryAddress = (uint32_t)buffer >> 2;
    DMA_InitStruct.NbData = length - 1;
    LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_7);
    
    LL_DMA_Enable_DMA(DMA);
    
    LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_7);
    LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_7);
    while (!LL_DMA_IsActiveFlag_Finished(DMA, LL_DMA_CHANNEL_7));
    LL_DMA_Disable_DMA(DMA);
}

// Flash DMA通道编程长度固定为256字节，只支持WORD传输
void FlashWriteDma(uint32_t addr, uint8_t *buffer)
{
#define FLS_PROG_KEY0   0xA5A5A5A5
#define FLS_PROG_KEY1   0xF1F1F1F1
    
    LL_DMA_InitTypeDef DMA_InitStruct;
    
    LL_RCC_Group2_EnableBusClock(LL_RCC_BUS2_CLOCK_FLASH);
    if ((uint32_t)addr & (LL_FLASH_ADDRS_ALIGN-1))
    {
        return;
    }
    if (LL_FLASH_GetFlashLockStatus(FLASH) == LL_FLASH_FLASH_KEY_STATUS_ERROR)
    {
        return;
    }
    
    LL_RCC_Group2_EnableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    
    LL_FLASH_StartProgram(FLASH);
    LL_FLASH_UnlockFlash(FLASH, LL_FLASH_PROGRAM_KEY1);
    LL_FLASH_UnlockFlash(FLASH, LL_FLASH_PROGRAM_KEY2);
    LL_FLASH_ClearFlag_ProgramFinish(FLASH);
    
    DMA_InitStruct.CircMode = DISABLE;
    DMA_InitStruct.DataSize = LL_DMA_BAND_WIDTH_BYTE;
    DMA_InitStruct.Direction = LL_DMA_DIR_RAM_TO_FLASH;
    DMA_InitStruct.MemoryAddressIncMode = LL_DMA_CH7_RAM_ADDR_INCREASE;
    DMA_InitStruct.FlashAddressIncMode = LL_DMA_CH7_FLASH_ADDR_INCREASE;
    DMA_InitStruct.Priority = LL_DMA_CHANNEL_PRIORITY_HIGH;
    DMA_InitStruct.PeriphAddress = addr >> 2;
    DMA_InitStruct.MemoryAddress = (uint32_t)buffer >> 2;
    DMA_InitStruct.NbData = 64 - 1;
    LL_DMA_Init(DMA, &DMA_InitStruct, LL_DMA_CHANNEL_7);
    
    LL_DMA_Enable_DMA(DMA);
    
    LL_DMA_ClearFlag_Finished(DMA, LL_DMA_CHANNEL_7);
    LL_DMA_Enable_Channel(DMA, LL_DMA_CHANNEL_7);
    while (!LL_DMA_IsActiveFlag_Finished(DMA, LL_DMA_CHANNEL_7));
    LL_DMA_Disable_DMA(DMA);
    
    while (!LL_FLASH_IsActiveFlag_ProgramFinish(FLASH));
    LL_FLASH_LockFlash(FLASH);
    
    LL_RCC_Group2_DisableOperationClock(LL_RCC_OPERATION2_CLOCK_FLASH_ERASN_PROGRAM);
    
#undef FLS_PROG_KEY0
#undef FLS_PROG_KEY1
}
