#include "main.h"
#include "user_init.h"
#include "crc.h"

#define DATA_LENGTH     8
uint8_t DATA[DATA_LENGTH] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

#define DATA1_LENGTH    2
uint32_t DATA1[DATA1_LENGTH] = {0x01020304, 0x05060708};

uint32_t result;

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

    result = CRC16_CCITT(DATA, DATA_LENGTH);           // 0xEEA7
    result = CRC16_CCITT_WORD(DATA1, DATA1_LENGTH);    // 0xEEA7
    
    while(1)
    {     
        LED0_TOG();
        DelayMs(1000);
    }
}


