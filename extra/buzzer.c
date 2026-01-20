#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>



// Controlling an LED with a button A
//
// Remember the LED circuit is actually seperate from the button circuit.
//
// The button circut will be used to determine whether we want to close the LED circuit.
//


int main(void)
{
    // Port Direction Register 0 = input; 1 = output


    // Set PORTB1 to output
    DDRB = DDRB | (1 << DDB1);

    // Set PORTB4 to output
    DDRB = DDRB | (1 << DDB4);

    // Set PORTB3 to output
    DDRB = DDRB | (1 << DDB3);

    // Set PORTD4 is input by default
    DDRD = DDRD & ~(1 << DDD4);

    // Set PORTD2 is input by default
    DDRD = DDRD & ~(1 << DDD2);

    while(1)
    {




        if(PIND & (1 << PD4))
        {
            // for(uint8_t i = 0; i < 500; i++)
            // {
                PORTB = PORTB | (1 << PORTB1);
                _delay_us(1432);
                PORTB = PORTB & ~(1 << PORTB1);
                _delay_us(1432);
            // }
        }
        else if(PIND & (1 << PD2))
        {
            // for(uint8_t i = 0; i < 100; i++)
            // {
                PORTB = PORTB | (1 << PORTB1);
                _delay_us(716);
                PORTB = PORTB & ~(1 << PORTB1);
                _delay_us(716);
            // }
        }


    }



    return 0;
}