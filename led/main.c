#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	unsigned char x = 0b00000001;
	DDRB = 0b00000001;

	while (1) {
		x = ~(x&0b00000001);
		PORTB = x;
		_delay_ms(1000);
	}
}
