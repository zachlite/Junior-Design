#include <stdio.h>




 void set_bit(volatile uint8_t *Byte, const unsigned char BitToSet);
 void clear_bit(volatile uint8_t *Byte, const unsigned char BitToClear);
 unsigned char read_bit(unsigned char Byte, const unsigned char BitToRead);
 void toggle_bit(volatile uint8_t *Byte, const unsigned char BitToToggle);

unsigned char get_quad_encoder_signal(volatile uint8_t *motor_port_1, volatile uint8_t *motor_port_2, const unsigned char BitA, const unsigned char BitB);



