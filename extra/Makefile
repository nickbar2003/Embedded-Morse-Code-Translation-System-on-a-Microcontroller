default:

	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c buzzer.c -o buzzer.o
	avr-gcc -mmcu=atmega328p buzzer.o -o buzzer.bin
	avr-objcopy -O ihex -R .eeprom buzzer.bin buzzer.hex
	sudo avrdude -F -V -c arduino -p ATmega328P -P /dev/ttyACM0 -b 115200 -U flash:w:buzzer.hex
