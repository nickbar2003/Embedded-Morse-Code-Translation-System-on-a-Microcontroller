// This makefile was copied from a youtube creator named Low Level, here is his excellent video: https://www.youtube.com/watch?v=j4xw8QomkXs
default:
		avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o main.o main.c
		avr-gcc -o main.bin main.o
		avr-objcopy -O ihex -R .eeprom main.bin main.hex
		sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex

