#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000 // System oscillator clock frequency in MHz
#define BAUD 9600 // Bits per second for Tx and Rx

// My microcontroller board has an ATmega328P microcontroller //
// For all w/r operations I am referencing the ATmega328P data sheet // 

// Documentation //
// ATmega328P datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
// Arduion UNO R3 pinout diagram: https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf



enum morse_translation
{
    EMPTY = 0b00000000,

    // 1 data bits
    E = 0b00100000,
    T = 0b00100001,
                 
    // 2 data bit,s
    A = 0b01000010,
    I = 0b01000000,
    M = 0b01000011,
    N = 0b01000001,
                 
    // 3 data bit,s
    D = 0b01100001,
    G = 0b01100011,
    K = 0b01100101,
    O = 0b01100111,
    R = 0b01100010,
    S = 0b01100000,
    U = 0b01100100,
    W = 0b01100110,
                 
    // 4 data bit,s
    B = 0b10000001,
    C = 0b10000101,
    F = 0b10000100,
    H = 0b10000000,
    J = 0b10001110,
    L = 0b10000010,
    P = 0b10000110,
    Q = 0b10001011,
    V = 0b10001000,
    X = 0b10001001,
    Y = 0b10001101,
    Z = 0b10000011,
    SPACE = 0b10001010

    // 5 data bits


};




int main(void)
{


    // // //  USART0 CONFIGURATION // // //
    

    /* 
    
    Desired Settings for USART0 :

    In USCR0C (register):
        - USART mode = Asynchronous
        - Parity mode = disabled
        - Stop bit select = 1 stop bit
        - Data bit size = 8 bits
        - Baud rate = 9600

    In USCR0B (Register):
        Tx Enable = 1

    */

    // USART mode = 00 = Async mode
    UCSR0C = UCSR0C & ~(1 << UMSEL00); // Set bit 6 = 0
    UCSR0C = UCSR0C & ~(1 << UMSEL01); // Set bit 7 = 0


    // Parity mode = 00 = disabled
    UCSR0C = UCSR0C & ~(1 << UPM00); // Set bit 4 = 0
    UCSR0C = UCSR0C & ~(1 << UPM01); // Set bit 5 = 0
    
    // Stop bit select = 0 = one stop bit
    UCSR0C = UCSR0C & ~(1 << USBS0); // Set bit 3 = 0

    // For data size setting 11 = 8 data bits
    UCSR0C = UCSR0C | (1 << UCSZ01); // Set bit 2 = 1
    UCSR0C = UCSR0C | (1 << UCSZ00); // Set bit 1 = 1

    // Set USART Baud Rate Register for desired baud rate of 9600 to 103
    // For equation info about this calculation see ATmega328P datasheet pg. 146
    UBRR0L = 103; // UBBR0n = 103 = (fosc) / (16 * BAUD)

    // Enable transmission 
    UCSR0B = UCSR0B | (1 << TXEN0);



    // // // PORT DIRECTION CONFIGURATION // // //

    
    // Port Direction Register 0 = input pin; 1 = output pin

    // Set PORTB4 to output
    DDRB = DDRB | (1 << DDB4);

    // Set PORTB3 to output
    DDRB = DDRB | (1 << DDB3);

    // Set PORTB3 to output
    DDRB = DDRB | (1 << DDB0);

    // Set PORTD2 is input by default
    DDRD = DDRD & ~(1 << DDD2);

    // Set PORTD4 is input by default
    DDRD = DDRD & ~(1 << DDD4);

    /*
    Port to hardware correspondance:
    (See Adrunio Uno R3 pinout diagram linked above)

    NAME   | PCB Pin NAME   | Hardware Function
    --------------------------------------------
    PORTB4 | Digital Pin 12 | Powering a Red LED
    ---------------------------------------------
    PORTB3 | Digital Pin 11 | Powering a Blue LED
    ---------------------------------------------
    PORTD4 | Digital Pin 4 | Recieving input from button
    
    */


    uint8_t fresh_click = 1; // 1 for fresh, 0 for stale

    enum morse_translation MCDB = 0b00000000;
    uint8_t data_size_mask = 0b00000000;
    char letter = ' ';

    while(1)
    {

        if(PIND & (1 << PD2)) 
        {
            _delay_ms(225); // Wait after inital click

            if(PIND & (1 << PD2)) 
            {
                while(!(UCSR0A & (1 << UDRE0))); // Wait for UDR empty
                UDR0 = ' '; 
            }

            PORTB = PORTB | (1 << PORTB0); 

            _delay_ms(200); // let LED shine

            PORTB = PORTB & ~(1 << PORTB0); 

            switch(MCDB)
            {
                
                case A:
                    letter = 'A';
                    break;
                case B:
                    letter = 'B';
                    break;
                case C:
                    letter = 'C';
                    break;
                case D:
                    letter = 'D';
                    break;
                case E:
                    letter = 'E';
                    break;
                case F:
                    letter = 'F';
                    break;
                case G:
                    letter = 'G';
                    break;
                case H:
                    letter = 'H';
                    break;
                case I:
                    letter = 'I';
                    break;
                case J:
                    letter = 'J';
                    break;
                case K:
                    letter = 'K';
                    break;
                case L:
                    letter = 'L';
                    break;
                case M:
                    letter = 'M';
                    break;
                case N:
                    letter = 'N';
                    break;
                case O:
                    letter = 'O';
                    break;
                case P:
                    letter = 'P';
                    break;
                case EMPTY:
                    letter = '#';
                    break;
            }
            switch(MCDB)
            {
                case Q:
                    letter = 'Q';
                    break;
                case R:
                    letter = 'R';
                    break;
                case S:
                    letter = 'S';
                    break;
                case T:
                    letter = 'T';
                    break;
                case U:
                    letter = 'U';
                    break;
                case V:
                    letter = 'V';
                    break;
                case W:
                    letter = 'W';
                    break;
                case X:
                    letter = 'X';
                    break;
                case Y:
                    letter = 'Y';
                    break;
                case Z:
                    letter = 'Z';
                    break;
                case SPACE:
                    letter = ' ';
                    break;
                case EMPTY:
                    letter = '#';
                    break;
            }



            while(!(UCSR0A & (1 << UDRE0))); // Wait for UDR empty
            UDR0 = letter; 

            MCDB = 0b00000000;
            data_size_mask = 0b00000000;




        }




        if(PIND & (1 << PD4) && fresh_click) // button is depressed 
        {
            fresh_click = 0; // no longer a new click

            _delay_ms(225); // Wait after inital click
            

            if(~PIND & (1 << PD4)) // button no longer depressed == Short button press
            { 

                PORTB = PORTB | (1 << PORTB4); // Turn on red LED

                data_size_mask = MCDB; 
                data_size_mask = data_size_mask >> 5; 

                MCDB = MCDB & ~(1 << data_size_mask); 
                MCDB += 0b00100000;

                while(!(UCSR0A & (1 << UDRE0))); // Wait for UDR empty
                UDR0 = '.'; // Transmit 'S'

                _delay_ms(200); // let LED shine 

                PORTB = PORTB & ~(1 << PORTB4); // turn LED off

            }
            else if(PIND & (1 << PD4)) // button still pressed == long button press
            {
                PORTB = PORTB | (1 << PORTB3); // Turn on blue LED

                data_size_mask = MCDB; 
                data_size_mask = data_size_mask >> 5; 

                MCDB = MCDB | (1 << data_size_mask); 
                MCDB += 0b00100000;


                while(!(UCSR0A & (1 << UDRE0))); // Wait for UDR empty
                UDR0 = '-'; // Transmit 'L'

                _delay_ms(200); // let LED shine

                PORTB = PORTB & ~(1 << PORTB3); // turn LED off
            }
        }


        // Button has either not pressed, 
        // or input has already been serviced

        if(~PIND & (1 << PD4)) // Button is unpressed
        {
            _delay_ms(50);
            fresh_click = 1; // Ready to service new click
        }
    }

    return 0;
    
}






