#include <avr/io.h>
#include <stdio.h>

#define BYTE 8

static uint8_t receiveUSART(void);
static void transmitUSART(const uint8_t);
static void setStreamUSART(void);
static int getCharUSART(FILE*);
static int putCharUSART(char, FILE*);

void initUSART(const uint16_t ubrr)
{
	/*set baud rate*/
	UBRRH = (uint8_t)(ubrr >> BYTE);
	UBRRL = (uint8_t)ubrr;
	
	UCSRA |= _BV(U2X);												/*double transmission speed*/
	UCSRB = _BV(RXEN) | _BV(TXEN);									/*receiver and transmitter enable*/
	UCSRC = _BV(URSEL) | _BV(USBS) | _BV(UCSZ1) | _BV(UCSZ0);		/*2 stop bits, 8-bit frame*/
	
	setStreamUSART();
}

void sendDataUSART(const char *data)
{
	while(*data != '\0')
		transmitUSART(*data++);
}

static uint8_t receiveUSART(void)
{
	loop_until_bit_is_set(UCSRA, RXC);
	return UDR;
}

static void transmitUSART(const uint8_t data)
{
	loop_until_bit_is_set(UCSRA, UDRE);
	UDR = data;
}

static void setStreamUSART(void)
{
	static FILE inOutStream = FDEV_SETUP_STREAM(putCharUSART, getCharUSART, _FDEV_SETUP_RW);
	stdin = stdout = &inOutStream;
}

static int getCharUSART(FILE *stream)
{
	int usartResult = receiveUSART();
	return usartResult;
}

static int putCharUSART(char ch, FILE *stream)
{
	transmitUSART(ch);
	return 1;
}