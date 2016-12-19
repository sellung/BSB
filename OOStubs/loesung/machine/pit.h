/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

#include "machine/io_port.h"
#include "device/cgastr.h" // only for test

class PIT
{
	private:
    	PIT(const PIT &copy); // Verhindere Kopieren
	/* Hier muesst ihr selbst Code vervollstaendigen */ 
    	const int TACT = 1193182;
    	int frequency;
    	const IO_Port chanel0; 
    	const IO_Port command; 
	public:
    	PIT (int us) :
    	 chanel0(0x40), command(0x43){
      		interval (us);
    	}
    	int interval () {
			return frequency;
    	}
    	void interval (int us);

    	bool fire_interrupt();
};

#endif
