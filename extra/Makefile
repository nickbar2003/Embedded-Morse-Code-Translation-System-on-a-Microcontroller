default:
		avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o buzzer.o buzzer.c
		avr-gcc -o buzzer.bin buzzer.o
		avr-objcopy -O ihex -R .eeprom buzzer.bin buzzer.hex
		sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:buzzer.hex
