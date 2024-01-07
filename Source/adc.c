#include <avr/io.h>

#define VREF		5
#define RESOLUTION	1024

void initADC(void)
{
	ADCSRA |= _BV(ADEN);				/*ADC enable*/
	ADCSRA |= _BV(ADPS1) | _BV(ADPS0);		/*8 prescaler*/
	
	ADMUX |= _BV(REFS0);				/*AVcc voltage reference*/
	ADMUX |= _BV(MUX0);				/*ADC1 channel*/
}

void startADC(void)
{
	ADCSRA |= _BV(ADSC);
}

uint16_t readADC(void)
{
	loop_until_bit_is_set(ADCSRA, ADIF);
	
	return ADC;
}

float convertADCf(const uint16_t adc)
{
	return (float)adc * VREF / RESOLUTION;
}
