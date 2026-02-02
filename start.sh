#!/bin/bash
# This commands for compiling and flashing were copied from a youtuber called "low level" here is the excellent video: https://www.youtube.com/watch?v=j4xw8QomkXs&t=313s
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o avr.o avr.c
avr-gcc -mmcu=atmega328p avr.o -o avr.bin
avr-objcopy -O ihex -R .eeprom avr.bin avr.hex
sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:avr.hex
