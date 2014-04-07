#define F_CPU 8000000UL


#include <avr/io.h>

#include "carrier_wave.h"
#include "inputoutput.h"
#include <avr/interrupt.h>


static const unsigned long carrier_frequency = 38000UL;


void set_up_IR_carrier()
{

 // Set the 0C1A pin (PB1) into output mode.
  DDRB |= (1 << PB1);

  // Place Timer 1 into PWM generation mode; which
  // produces a waveform that's very close to 38kHz.
  //
  // This waveform is used as a carrier wave for IR
  // communciations.
  TCCR1B |= (0 << CS11 | 1 << CS10);    // Fcpu/1 - no prescaler


  /**
   * Specifies the frequency of the infrared carrier wave,
   * by specifying the amount of _half periods_ in timer cycles.
   *
   * This is equal to (F_CPU / desired_carrier_frequency) / 2:
   * the resultant period of the wave is equal to the ratio of
   * the faster to the slower clocks; which we here divide by two.
   */
  OCR1A = ((F_CPU / carrier_frequency) / 2UL); // Should equal 210 for 38kHz.


  // Place Timer 3 into Clear on Timer Compare mode,
  // which essentially configures it to use OCR1A as
  // upper bound on how high Timer 3 can count;
  // and set the upper bound to half of our
  // period.
  TCCR1B |= (1 << WGM12);

  // Configure the timer to automatically invert the OC1A
  // pin, which happens to be PB1, each time the timer reaches
  // its maximum value. This is what actually generates our
  // square-wave.
  TCCR1A |= (1 << COM1A0);

}