#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>



// Controlling an LED with a button A
//
// Remember the LED circuit is actually seperate from the button circuit.
//
// The button circut will be used to determine whether we want to close the LED circuit.



int main(void)
{
    // Port Direction Register 0 = input; 1 = output
    
    // uint16_t = 0;

    // Set PORTB4 to output
    DDRB = DDRB | (1 << DDB4);

    // Set PORTB3 to output
    DDRB = DDRB | (1 << DDB3);

    // Set PORTD4 is input by default
    DDRD = DDRD & ~(1 << DDD4);

    uint8_t fresh_click = 1; // 1 for fresh, 0 for stale

    while(1)
    {




        if(PIND & (1 << PD4) && fresh_click) // button depressed
        {
            fresh_click = 0;
            _delay_ms(300); // This delay controls how long short vs long intepretation
            

            if(~PIND & (1 << PD4)) // button no longer depressed
            {
                // Set PortB4
                PORTB = PORTB | (1 << PORTB4); // RED
                _delay_ms(150);
                // unset PORTB4
                PORTB = PORTB & ~(1 << PORTB4); // RED
            }

            if(PIND & (1 << PD4)) // button still pressed
            {
                // Set PortB3
                PORTB = PORTB | (1 << PORTB3); // BLUE
                _delay_ms(150);
                // unSet PortB3
                PORTB = PORTB & ~(1 << PORTB3); // BLUE
            }
        }




        if(~PIND & (1 << PD4)) // button no longer depressed
        {
            _delay_ms(50);
            fresh_click = 1;
        }




    }



    return 0;
}
