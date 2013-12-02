#include <avr/io.h>
#include <util/delay.h>

void usart_init(unsigned int baud) {
	/* set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;

	/* enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	
	/* set frame format: 8data, 2stop bit */
	UCSRC = (1<<USBS)|(3<<UCSZ0);
}

void usart_transmit(unsigned char data) {
	/* wait for empty transmit buffer */
	while (!(UCSRA & (1<<UDRE)))
		;
	
	/* put data into buffer, sends the data */
	UDR = data;
}

void send_hello() {
	usart_transmit('H');
	usart_transmit('e');
	usart_transmit('l');
	usart_transmit('l');
	usart_transmit('o');
	usart_transmit(',');
	usart_transmit(' ');
	usart_transmit('W');
	usart_transmit('o');
	usart_transmit('r');
	usart_transmit('l');
	usart_transmit('d');
	usart_transmit('\n');
}

int main(void) {
	unsigned char baud = 8000000/16/9600-2;
	unsigned char x = 0b00000001;
	DDRB = 0b00000001;

	
	usart_init(25);

	while (1) {
		x = ~(x&0b00000001);
		PORTB = x;
		send_hello();
		_delay_ms(1000);
	}
}
