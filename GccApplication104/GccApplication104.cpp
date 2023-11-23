#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define UBRR_VAL F_CPU/16/BAUD-1

void usart_init(unsigned int speed)  
{
	UBRRH=(unsigned char)(speed>>8);
	UBRRL=(unsigned char)speed;
	UCSRA=0x00;
	UCSRB|=(1<<RXEN);
	UCSRB|=(1<<RXCIE);
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

ISR(USART_RXC_vect)
{
	PORTB=UDR;
}
int main(void)
{
	DDRB=0xFF;
	PORTB=0x00;
	usart_init(UBRR_VAL);
	sei();
    while(1)
    {
         
    }
}