#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

// defined two macros
#define LEDON( n ) PORTB &= ~( 1 << n )
#define LEDOFF( n ) PORTB |= ( 1 << n )

void setup() {
	DDRB = 0xFF; // now port B is an output
	PORTB = 0xFE; // turns off all the LEDs
	DDRD = 0x00; // port D is an input
	PORTD = 0xFF; // turns on the pull-up resitors on port D
}

void delay_ms(uint16_t milliseconds) { // for specifying the total delay time f-n
	for (uint16_t i = 0; i < milliseconds; i++) {
		_delay_ms(1);
	}
}

int main(void) {
	setup();
	while (1) {
		for (uint8_t i = 0; i < 7; i++) { // sequentially turn on and turn off the LEDs
			LEDON(i); // is connected to port B
			delay_ms(100);
			LEDOFF(i);
			
			if ((PIND & (1 << PD4)) == 0) { // checks if the fourth button (SW4) is pressed
				_delay_ms(5000);
			}
		}
		
		for (uint8_t i = 7; i > 0; i--) {
			LEDON(i);
			delay_ms(100);
			LEDOFF(i);
			
			if ((PIND & (1 << PD4)) == 0) { // checks if the fourth button (SW4) is pressed
				_delay_ms(5000);
			}
		}
	}
	return 0;
}
