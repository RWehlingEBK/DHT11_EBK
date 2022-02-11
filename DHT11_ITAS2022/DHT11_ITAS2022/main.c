/*
 * DHT11_ITAS2022.c
 *
 * Created: 17.01.2022 08:18:37
 * Author : RalfW
 */ 

#include <avr/io.h>
#define F_CPU 11059280
#include <util/delay.h>

#define DHT11DDR	DDRA
#define DHT11PORT	PORTA
#define DHT11PIN	PINB
#define DHT11PWR	PINB5
#define DHT11DATA	PINB6

#define DHT11TX	1
#define DHT11RX	0

#define DHT11HIGH 1
#define DHT11LOW  0


void initDHT11()
{
//Datenrichtung setzen
DHT11DDR =(1<<DHT11PWR);
//Pin auf 5V schalten mit dem Port Register
DHT11PORT=(1<<DHT11PWR); 	
}

void setDataDirection(uint8_t output)
{
if (output) 
	//Datenrichtung f�r Data auf 1 setzen TX
	DHT11DDR |=(1<<DHT11DATA);				
	//DHT11DDR |= (1<<DHT11DATA);	gleichwertig 
	else
	//Datenrichtung f�r Data auf 0 setzen RX
	DHT11DDR &=~(1<<DHT11DATA);
}


void setDatapin(uint8_t high)
{
	if (high)
	//Output auf high setzen
	DHT11PORT |=(1<<DHT11DATA);
	//DHT11DDR |= (1<<DHT11DATA);	gleichwertig
	else
	//Output auf low setzen
	DHT11PORT &=~(1<<DHT11DATA);
}

void startDHT11()
{

setDataDirection(DHT11TX);
setDatapin(DHT11LOW);
_delay_us(18000);
setDatapin(DHT11HIGH);
setDataDirection(DHT11RX);
	
}


int main(void)
{
initDHT11();
    /* Zweiter Replace with your application code */
    while (1) 
    {
	startDHT11();
	_delay_ms(500);
    }
}

