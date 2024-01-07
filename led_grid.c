#include <avr/io.h>

void initLedGrid(void)
{
	DDRB = 0xFF;
}

void displayLedGrid(const uint8_t data)
{
	if(data == 0x00 || data == 0xFF)
		PORTB = data;
	else
		PORTB ^= data;
}