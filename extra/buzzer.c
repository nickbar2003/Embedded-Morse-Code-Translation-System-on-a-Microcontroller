#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>



// Controlling an LED with a button A
//
// Remember the LED circuit is actually seperate from the button circuit.
//
// The button circut will be used to determine whether we want to close the LED circuit.
//


void short_tone(void);
void long_tone(void);

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


    for(int i = 0; i < 100; i++)
    {
    // ●
    PORTB |= (1 << PORTB1);
    _delay_us(400);
    PORTB &= ~(1 << PORTB1);
    _delay_us(200);

    }
    for(int i = 0; i < 100; i++)
    {
    // ▬
    PORTB |= (1 << PORTB1);
    _delay_us(1200);
    PORTB &= ~(1 << PORTB1);
    _delay_us(300);

    }
    for(int i = 0; i < 100; i++)
    {
    // ●
    PORTB |= (1 << PORTB1);
    _delay_us(400);
    PORTB &= ~(1 << PORTB1);
    _delay_us(800);

    }







        // if(PIND & (1 << PD4))
        // {
        //     long_tone();
        // }
        // else if(PIND & (1 << PD2))
        // {
        //     short_tone();
        // }


    }



    return 0;
}

void short_tone(void)
{
    PORTB = PORTB | (1 << PORTB1);
    _delay_us(1432);
    PORTB = PORTB & ~(1 << PORTB1);
    _delay_us(1432);
}

void long_tone(void)
{
    PORTB = PORTB | (1 << PORTB1);
    _delay_us(716);
    PORTB = PORTB & ~(1 << PORTB1);
    _delay_us(716);
}
