/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "machine/pit.h"

void PIT::interval(int us){
	frequency = us;
	int x = TACT / us;

	command.outb(0x34); // 0011 0100
	chanel0.outb(x & 0xff);
	chanel0.outb((x >> 8) & 0xff); 
}

bool  PIT::fire_interrupt(){
	// read low bits
	command.outb(0x12);
	int x1 = chanel0.inb();

	// read high bits
	command.outb(0x22);
	int x2 = chanel0.inb();

	int x =  x2 | (x1 << 8) ;

	if( x == 1){ return true;}

	return false;
}
