#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// function to turn on a LED
void led_on(uint8_t led_pin) {
	PORTD &= ~(1 << led_pin);
}

// function to turn off a LED
void led_off(uint8_t led_pin) {
	PORTD |= (1 << led_pin);
}

// ISR for PCINT0 interrupt
ISR(PCINT0_vect) {
	// check if SW4 (PB0) or SW1 (PB1) is pressed
	if (!(PINB & (1 << PB0)) || !(PINB & (1 << PB1))) {
		// turn on LEDs one by one with a delay of 3 seconds
		for (int i = 7; i >= 0; i--) {
			led_on(i);
			_delay_ms(3000);
			//led_off(i);
		}
	}
}
// ISR for PCINT1 interrupt
ISR(PCINT1_vect) {
	
	if (!(PINC & (1 << PC0)) && !(PINC & (1 << PC1))) {
		// turn off LEDs one by one with a delay of 1.5 seconds
		for (int i = 7; i >= 0; i--) {
			led_off(i);
			_delay_ms(1500);
		}
	}
}

int main(void) {
	// set all port D pins as output for the LEDs
	DDRD = 0xFF;
	
	// set all port B pins as input for the buttons SW4 (PB0) and SW1 (PB1)
	DDRB = 0x00;
	
	// set all port C pins as input for the buttons SW5 (PC0) and SW2 (PC1)
	DDRC = 0x00;

	// set all LEDs to off initially
	PORTD = 0xFF;

	// enable pull-up resistors for SW4 (PB0) and SW1 (PB1)
	PORTB |= (1 << PB0) | (1 << PB1);
	
	// enable pull-up resistors for SW5 (PC0) and SW2 (PC1)
	PORTC |= (1 << PC0) | (1 << PC1);

	// enable pin change interrupts for PCINT0 and PCINT1
	PCMSK0 |= (1 << PCINT0) | (1 << PCINT1);
	PCICR |= (1 << PCIE0);
	
	// enable the PCINT1 interrupt for pins PC0 and PC1 on Port C
	PCMSK1 |= (1 << PCINT8) | (1 << PCINT9);
	PCICR |= (1 << PCIE1);

	// enable global interrupts
	sei();

	while (1) {
		// main program loop to keep the program running until power is removed
	}
}
