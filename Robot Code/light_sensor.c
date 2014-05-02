//
//  light_sensor.c
//  
//
//  Created by Isaac Patka on 3/29/14.
//
//
#include "light_sensor.h"

/*                                                   *
 *                         ------                    *
 *   PC6                  |1   28| PC5 -  SCL        *
 *   PD0                  |2   27| PC4 -  SDA        *
 *   PD1                  |3   26| PC3               *
 *   PD2                  |4   25| PC2               *
 *   PD3                  |5   24| PC1               *
 *   PD4                  |6   23| PC0               *
 *   VCC                  |7   22| GND               *
 *   GND                  |8   21| AREF              *
 *   PB6                  |9   20| AVCC              * 
 *   PB7                  |10  19| PB5               *
 *   PD5 - LED            |11  18| PB4               *
 *   PD6                  |12  17| PB3               *
 *   PD7                  |13  16| PB2               *
 *   PB0                  |14  15| PB1               *
 *                         ------                    *
 *                                                   */



void TWIInit(void);

void TWIStart(void);

void TWIStop(void);

void TWIStop(void);

void TWIWrite(uint8_t u8data);

uint8_t TWIReadACK(void);

uint8_t TWIReadNACK(void);

uint8_t TWIGetStatus(void);

void Init_Ports(void);

void blink_led(void);

void set_bit_value(volatile uint8_t * byte, unsigned char bit, unsigned char value);

uint16_t MAX3(uint16_t VAR1, uint16_t VAR2, uint16_t VAR3);



void run_light_sensor(void)
{
    uint16_t ATIME_MS = 2.72;
    uint16_t GA = 1;             //  Nothing obstructing the light sensor
    uint16_t AGAINX = 1;         //  1x light gain
    uint16_t CPL = 0;
    uint16_t LUX1 = 0;
    uint16_t LUX2 = 0;
    uint16_t LUX = 0;



    //blink_led();
    //blink_led();

    TWIInit();

    
    while(1)
    {
    
    /*  TWIStart is the equivalent of [ symbol in Kyle's example
     *  It sends a start signal
     *
     *  TWIWrite sends the 8 bit number
     *
     *  Writing 0x72 tells the device you're about to write
     *  Writing 0x73 tells the device you're about to read
     *
     *  Both of these numbers are device specific and
     *      can be determined by studying the datasheet
     *
     *      It's basically the device address 0x39 combined with
     *      some other bits saying read or write
     *
     *  TWIReadNACK grabs whatever 8 bits are coming in
     *  The NACK refers to the fact that we don't need an acknowlegment signal
     *
     *  Check page 16 of the datasheet to see descriptions of the
     *      comm protocal
     *
     *  Write goes like this:
     *  [ Slave_Address W Command_Code Data_Byte ]
     *
     *  Read goes like this:
     *  [ Slave_Address W Command_Code [ Slave_Address R Data ]
     *  It's assymetrical so it looks annoying but it's correct
     *  Data is taked in by TWIRead
     *
     *  Key:    [ - start bit
     *          ] - stop bit
     *          Slave_Address is the device address (7 bits)
                W - Write (1 bit)
                    These two get combined into 0x72
                R - Read (1 bit)
                    Gets combined with Slave_Address into 0x73
                Command_Code is a combination of some complicated stuff 
                             and what register you want to manipulate
                Data_Byte is what you're writing to the register
                Data is the stuff you're reading in, get it with TWIRead
     */
        

    //  Disable Device
        
        TWIStart();
        TWIWrite( 0x72 );
        TWIWrite( 0xA0 );
        TWIWrite( 0x0);
        TWIStop();
        

    //  Set ATime to 2.72ms
        
        TWIStart();
        TWIWrite( 0x72 );
        TWIWrite( 0xA1 );
        TWIWrite( 0xff);
        TWIStop();
        
    //  Set Wtime to 2.72ms
        
        TWIStart();
        TWIWrite( 0x72 );
        TWIWrite( 0xA3 );
        TWIWrite( 0xff);
        TWIStop();
        
    //  Set gain
        
        TWIStart();
        TWIWrite( 0x72 );
        TWIWrite( 0xAF );
        TWIWrite( 0x0);
        TWIStop();
        
    //  Enable Device
        
        TWIStart();
        TWIWrite( 0x72 );
        TWIWrite( 0xA0 );
        TWIWrite( 0xB );
        TWIStop();
        

        uint16_t C0DATA = 0;
        uint16_t C0DATAH = 0;

        while(1)
        {
        //  Read

            /*  CPL = (ATIME_MS * AGAINX) / (GA * 53)
                LUX1 = (C0DATA - 2*C1DATA)/CPL
                LUX2 = (0.6 * C0DATA - C1DATA) / CPL
                LUX = MAX(LUX1,LUX2,0)
                */
            
           

            TWIStart();
            TWIWrite( 0x72);
            TWIWrite( 0xB4);
            TWIStart();
            TWIWrite( 0x73);
            C0DATA = TWIReadNACK();

            
            TWIStart();
            TWIWrite( 0x72);
            TWIWrite( 0xB5);
            TWIStart();
            TWIWrite( 0x73);
            C0DATAH = TWIReadNACK();

            //C0DATA |= (C0DATAH << 8);
            

            uint16_t C1DATA = 0;
            uint16_t C1DATAH = 0;

            TWIStart();
            TWIWrite( 0x72);
            TWIWrite( 0xB6);
            TWIStart();
            TWIWrite( 0x73);
            C1DATA = TWIReadNACK();

            
            TWIStart();
            TWIWrite( 0x72);
            TWIWrite( 0xB7);
            TWIStart();
            TWIWrite( 0x73);
            C1DATAH = TWIReadNACK();

            C1DATA |= (C1DATAH << 8);


            //  Calculate Lux
            CPL = (ATIME_MS * AGAINX) / (GA * 53);
            LUX1 = (C0DATA - 2*C1DATA)/CPL;
            LUX2 = (0.6 * C0DATA - C1DATA) / CPL;
            LUX = MAX3(LUX1,LUX2,0);

            //if (LUX > 1000)
              //  blink_led();

            if (C0DATA > 0x10)  // Lux isn't being used right now to set off the indicator, just this threshold which I found through trial and error
                //blink_led();
                //light detected;

        }

        


/*  //I2c Tester Code
    // Enable device
    
    TWIStart();
    TWIWrite( 0x72 );
    TWIWrite( 0xA0 );
    TWIWrite( 0xB );
    TWIStop();
    
    // See if device is enabled
    
    TWIStart();
    TWIWrite( 0x72);
    TWIWrite( 0xA0);
    TWIStart();
    TWIWrite( 0x73);
        char state = TWIReadNACK();
        
    if (state == 0xB)
    blink_led();
        
    //Disable device
        TWIStart();
        TWIWrite( 0x72 );
        TWIWrite( 0xA0 );
        TWIWrite( 0x0);
        TWIStop();
        */
    
        
    }//end while
    
    
    return 0;
}

void Init_Ports(void)
{
    
    DDRD |= (1 << PD4);
    /*
     *PD5 is LED_SWITCH
     */
}

void blink_led(void)
{
    set_bit_value(&SWITCH_PORT,LED_SWITCH,1);
    _delay_ms(125);
    set_bit_value(&SWITCH_PORT,LED_SWITCH,0);
    _delay_ms(125);
}

void set_bit_value(volatile uint8_t * byte, unsigned char bit, unsigned char value)
{
    
    if (value == 1)
        *byte |= 1 << bit;
    
    else if (value == 0)
        *byte &= ~(1 << bit);
    
}

void TWIInit(void)
{
    //set SCL to 400kHz
    TWSR = 0x00;
    TWBR = 0x0C;
    //enable TWI
    TWCR = (1<<TWEN);
}

void TWIStart(void)
{
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);
}
//send stop signal
void TWIStop(void)
{
    TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void TWIWrite(uint8_t u8data)
{
    TWDR = u8data;
    TWCR = (1<<TWINT)|(1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);
}

uint8_t TWIReadACK(void)
{
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    while ((TWCR & (1<<TWINT)) == 0);
    return TWDR;
}
//read byte with NACK
uint8_t TWIReadNACK(void)
{
    TWCR = (1<<TWINT)|(1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);
    return TWDR;
}

uint8_t TWIGetStatus(void)
{
    uint8_t status;
    //mask status
    status = TWSR & 0xF8;
    return status;
}

uint16_t MAX3(uint16_t VAR1, uint16_t VAR2, uint16_t VAR3)
{
    uint16_t maximum = 0;

    if (VAR1 > VAR2)
        maximum = VAR1;
    else if (VAR1 < VAR2)
        maximum = VAR2;

    if (maximum > VAR3);

    else if (maximum < VAR3)
        maximum = VAR3;

    return maximum;
}