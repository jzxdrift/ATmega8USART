#include <stdio.h>

#ifdef ANALOG_TO_DIGITAL
	#include "adc.h"
#endif
#include "led_grid.h"
#include "usart.h"
#include "menu.h"

int main(void)
{
#ifdef ANALOG_TO_DIGITAL
	initADC();
#endif
	initLedGrid();
	initUSART(UBRR_VAL);
	
	while(1)
	{
#ifdef ANALOG_TO_DIGITAL
		startADC();
		printf("%.2fV\r", convertADCf(readADC()));
#endif
		
		showMenuPrompt();
		selectMenuOption(getchar());
	}
}
