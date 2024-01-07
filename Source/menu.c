#include <stdio.h>

#include "led_grid.h"

#define CHAR_TO_INT(x)	(x - 48)

void showMenuPrompt(void)
{
	printf("Select option from the menu (0-9)\r");
	printf("Menu:\r");
	
	printf("0 - PORTB Low\r");
	printf("1 - PB0 0/1\r");
	printf("2 - PB1 0/1\r");
	printf("3 - PB2 0/1\r");
	printf("4 - PB3 0/1\r");
	printf("5 - PB4 0/1\r");
	printf("6 - PB5 0/1\r");
	printf("7 - PB6 0/1\r");
	printf("8 - PB7 0/1\r");
	printf("9 - PORTB High\r\r");
}

void selectMenuOption(const char ch)
{
	printf("Option: %c\r\r", ch);
	
	if(CHAR_TO_INT(ch) == 0)
		displayLedGrid(0x00);
	else if(CHAR_TO_INT(ch) == 9)
		displayLedGrid(0xFF);
	else if(CHAR_TO_INT(ch) >= 1 && CHAR_TO_INT(ch) <= 8)
		displayLedGrid(1 << (CHAR_TO_INT(ch) - 1));
	else
		printf("Incorrect option, try again!\r\r");
}
