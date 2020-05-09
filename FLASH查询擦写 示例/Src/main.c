#include "main.h"
#include "user_init.h"

ErrorStatus LL_FLASH_Program_String(FLASH_Type* FLASHx, uint32_t Address, uint32_t *data,uint32_t Length)
{
  uint32_t i;
	ErrorStatus ret;
	for(i=0; i<128; i++)
	{
		ret = LL_FLASH_Program_Word(FLASH, Address + i * 4, data[i]);
		if(ret == FAIL)
			return FAIL;
	}
  return PASS;
}


void FlashTest(void)
{
	uint32_t ProgAddr = 0x00004000;
	uint32_t DataToWrite[128];
	
	LL_FLASH_PageErase(FLASH, 0x00004000);
	memset(DataToWrite, 0x55, 512);
	LL_FLASH_Program_String(FLASH,ProgAddr,DataToWrite,128);
	
	LL_FLASH_PageErase(FLASH, 0x00004000);
	memset(DataToWrite, 0xAA, 512);
	LL_FLASH_Program_Page(FLASH, ProgAddr / LL_FLASH_MAX_PAGE_NUM, DataToWrite);
	
	LL_FLASH_PageErase(FLASH, 0x00004000);
	memset(DataToWrite, 0x00, 512);
	LL_FLASH_Program_Sector(FLASH, ProgAddr / LL_FLASH_SECTOR_SIZE_BYTE, DataToWrite);

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
		
		FlashTest();
  
    while(1)
    {     
        LED0_TOG();
        DelayMs(500);
    }
}


