#include "binary.h"

void init_ADC(void);
void init_test_pins(void);
void init_analog_hardware();
int analog_read(unsigned char channel);
void run_ADC(void);
