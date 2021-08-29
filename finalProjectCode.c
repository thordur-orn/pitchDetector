# include <avr/io.h>
# include <avr/interrupt.h>

volatile unsigned long ovfCount;

int main ()
{
	ovfCount = 0;
	TCCR0B |= (1 << CS00 ); // no prescale
	TCNT0 = 0; // set up timer / counter
	TIMSK0 |= (1 << TOIE0 );
	EICRA &= ~3;
	EICRA |= (1 << ISC00 ) | (1 << ISC01 ); // set INT0 to trigger on
	rising edge
	EIMSK |= (1 << INT0 ); // enable external interrupt 0
	DDRB = 0x20; // set PORTB pins as output
	DDRC = 0x20; // set PORTC pins as output
	sei () ; // enable external interrupts
	while (1);
	return 0;
}

ISR(INT0_vect)
{
	unsigned long l = (ovfCount << 8) + TCNT0;
	if ((l > 35720 && l < 37000)) // A 
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTB |= (1 << PB0);
	}
	else if ((l > 33368 && l < 35320)) // A#
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTB |= (1 << PB1);
	}
	else if ((l > 31496 && l < 33368)) // B
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTB |= (1 << PB2);
	}
	else if ((l > 29739 && l < 31496)) // C
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTB |= (1 << PB3);
	}
	else if ((l > 28068 && l < 29739)) // C#
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTB |= (1 << PB4);
	}
	else if ((l > 26490 && l < 28068)) // D
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTB |= (1 << PB5);
	}
	else if ((l > 25001 && l < 26490)) // D#
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTC |= (1 << PC5);
	}
	else if ((l > 23600 && l < 25001)) // E
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTC |= (1 << PC4);
	}
	else if ((l > 22271 && l < 23600)) // F
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTC |= (1 << PC3);
	}
	else if ((l > 21014 && l < 22071)) // F#
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTC |= (1 << PC2);
	}
	else if ((l > 19842 && l < 21014)) // G
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTC |= (1 << PC1);
	}
	else if ((l > 18650 && l < 19842)) // G#
	{
		PORTB = 0 x00;
		PORTC = 0 x00;
		PORTC |= (1 << PC0);
	}
	ovfCount = 0; // reset overflow counter
}
ISR(TIMER0_OVF_vect)
{
	ovfCount ++; // increment overflow counter
}