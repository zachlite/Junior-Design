/*

binary.h
low level bitwise manipulation

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/

#include <avr/io.h>
#include <stdio.h>


 void set_bit(volatile uint8_t *Byte, const unsigned char BitToSet);
 void clear_bit(volatile uint8_t *Byte, const unsigned char BitToClear);
 unsigned char read_bit(unsigned char Byte, const unsigned char BitToRead);
 void toggle_bit(volatile uint8_t *Byte, const unsigned char BitToToggle);

//removed second motor port assuming the left and right motors both have their own unique ports
unsigned char get_quad_encoder_signal(volatile uint8_t *motor_port, const unsigned char BitA, const unsigned char BitB);



