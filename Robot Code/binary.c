/*

binary.c
low level bitwise manipulation

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/



#include "binary.h"


#define quad_bit_A 1
#define quad_bit_B 0


 void set_bit(volatile uint8_t *Byte, const unsigned char BitToSet)
{
    *Byte = *Byte | (1 << BitToSet);
}

 void clear_bit(volatile uint8_t *Byte, const unsigned char BitToClear)
{
    *Byte &= ~(1 << BitToClear);
    
}

 unsigned char read_bit(unsigned char Byte, const unsigned char BitToRead)
{
    unsigned char ValueOfBit;
    
    ValueOfBit = (Byte & (1 << BitToRead)) >> BitToRead;
    
    return ValueOfBit;
}

 void toggle_bit(volatile uint8_t *Byte, const unsigned char BitToToggle)
{
    *Byte = (*Byte ^= (1 << BitToToggle));
    
}



unsigned char get_quad_encoder_signal(volatile uint8_t *motor_port, const unsigned char BitA, const unsigned char BitB)
{
    unsigned char signal_A, signal_B;
    signal_A = read_bit(*motor_port, BitA);
    signal_B = read_bit(*motor_port, BitB);
    signal_A = signal_A << 1;
 
      return signal_A + signal_B;
    
}

