#ifndef USART_H
#define USART_H

#include <stdint.h>

#define FOSC        1000000
#define BAUD        9600
#define UBRR_VAL    (FOSC / 8 / BAUD - 1)    /*asynchronous double speed mode*/

void initUSART(const uint16_t);
void sendDataUSART(const char*);

#endif
