//
//  TWI_master.h
//  
//
//  Created by Isaac Patka on 3/29/14.
//
//
#include <avr/io.h>

void TWIInit(void);

void TWIStart(void);

void TWIStop(void);

void TWIStop(void);

void TWIWrite(uint8_t u8data);

uint8_t TWIReadACK(void);

uint8_t TWIReadNACK(void);

uint8_t TWIGetStatus(void);