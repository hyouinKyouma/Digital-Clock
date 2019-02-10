/*
 * DIGITAL_CLOCK.c
 *
 * Created: 1/31/2018 2:59:59 PM
 *  Author: ADITYA
 */ 



#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

const int delay=1000;

int main(void)
{
	unsigned char seg[10]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};
	DDRA=DDRB=DDRC=DDRD=0xff;
    while(1)
    {
label:	
		for(char i=0;i<3;i++)
		for(char j=0;j<10;j++)
		for(char k=0;k<6;k++)
		for (char l=0;l<10;l++)
		{
			PORTA=seg[i];
			PORTB=seg[j];
			PORTC=seg[k];
			PORTD=seg[l];	
			_delay_ms(delay);
			if(i==2 && j==4)
				goto label;
		}
	}
}