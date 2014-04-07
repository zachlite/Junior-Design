#include <stdio.h>
#include "binary.h"


#define Data_Direction_Reg_D &DDRD
#define Data_Direction_Reg_B &DDRB




#define Left_Motor_Enable 6
#define Left_Motor_Direction 5
#define Right_Motor_Enable 3
#define Right_Motor_Direction 4

#define Left_Motor_Port &PORTD
#define Right_Motor_Port &PORTB

#define Left_Motor_Pin &PIND
#define Right_Motor_Pin &PINB




void initialize_io(void);

void set_up_left_motor(void);
void set_up_right_motor(void);

void init_timer_pin(void);
