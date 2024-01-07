#ifndef ADC_H
#define ADC_H

#include <stdint.h>

void initADC(void);
void startADC(void);
uint16_t readADC(void);
float convertADCf(const uint16_t);

#endif
