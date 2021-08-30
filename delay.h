#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

uint32_t multipliter;

void init_delay(void){
	RCC_ClocksTypeDef RCC_Clocks;
  RCC_GetClocksFreq(&RCC_Clocks);    /* get system clock */
  /* while loop takes 4 cycles */
  /* for 1 us delay, we need to divide with 4M */
  multipliter = RCC_Clocks.HCLK_Frequency / 8000001; 
}

void delayUs(uint32_t micros){
  /* multiply micro with multipliter */
	micros = multipliter * micros - 10;
  /* 4 cycles for one loop */
  while(micros--);
}
 
 void delayMs(uint32_t mills){
   /* multiply mills with multipliter */
	 mills = multipliter * mills * 1000 - 10;
   /* 4 cycles for one loop */
   while(mills--);
}
 
 void delay(unsigned int nCount){
	unsigned int i, j;
	for (i = 0; i < nCount; i++)
		for (j = 0; j < 0x281F; j++);
}