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
#include "device/cgastr.h"

void PIT::interval(int us){
	frequency = us;
	int x = TACT / us;
	kout << "x=" << x << endl;
	command.outb(0x36); // 0011 0100
	chanel0.outb(x & 0xff);
	chanel0.outb((x >> 8) & 0xff); 
}

