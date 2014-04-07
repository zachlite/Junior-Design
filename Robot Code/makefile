#Junior Design Makefile
#Written by Zach Lite (and Jen) ((and Kyle)) 
#April 7, 2014



CC=avr-gcc
CFLAGS= -std=c99 -g -Wall -mmcu=atmega328 -O1 
#check /dev to find your buspirate's device signature.  cu.usbserial-A601EXKG is mine.
DEVICE=/dev/cu.usbserial-A601EXKG
AVR=atmega328
OUTPUT=main



#command "make" runs all:
all: main.elf hexfile run



#the syntax here is main.elf: declares a target, and all the .o files to the right are the target's dependencies
#in other words, what's to the right is what is required by what's to the left.


#	$() is a variable, as defined above.
#	$< means link dependencies, as defined to the right of the target
#   $@ is a shortcut, equal to the name of the target, instead of re-writing it.
  


main.elf: binary.o inputoutput.o motors.o carrier_wave.o ir_comm.o ADC.o main.o
	$(CC) $(CFLAGS) binary.o inputoutput.o motors.o carrier_wave.o ir_comm.o ADC.o main.o -o $@

binary.o: binary.c binary.h
	avr-gcc $(CFLAGS) -c $< -o $@

inputoutput.o: inputoutput.c inputoutput.h binary.h
	avr-gcc $(CFLAGS) -c  $< -o $@

motors.o: motors.c motors.h binary.h inputoutput.h
	$(CC) $(CFLAGS) -c $< -o $@

carrier_wave.o: carrier_wave.c carrier_wave.h inputoutput.h
	$(CC) $(CFLAGS) -c $< -o $@

ir_comm.o: ir_comm.c ir_comm.h carrier_wave.h binary.h
	$(CC) $(CFLAGS) -c $< -o $@

ADC.o: ADC.c ADC.h binary.h
	$(CC) $(CFLAGS) -c $< -o $@

#add new files here

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@


hexfile:
	avr-objcopy -j .text -j.data -O ihex $(OUTPUT).elf $(OUTPUT).hex		
run:
	avrdude -c buspirate -P $(DEVICE) -p $(AVR) -V -U flash:w:$(OUTPUT).hex




#"make clean"
clean:
	rm -f $(OUTPUT).elf
	rm -f $(OUTPUT).o
	rm -f $(OUTPUT).hex
	rm -f binary.o
	rm -f inputoutput.o
	rm -f motors.o
	rm -f carrier_wave.o
	rm -f ir_comm.o
	clear
	
#"make eightMHZ"
eightMHZ:

	avrdude -c buspirate -P $(DEVICE) -p $(AVR) -U lfuse:w:0xe2:m

#"make oneMHZ"
oneMHZ:
	avrdude -c buspirate -P $(DEVICE) -p $(AVR) -U lfuse:w:0x62:m	

#etc..
test:

	avrdude –c buspirate –P $(DEVICE) –p $(AVR)