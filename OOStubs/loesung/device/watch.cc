/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "device/watch.h"
#include "syscall/guarded_scheduler.h"

//Plugbox plugbox;
//PIC pic;

void Watch::windup (){
	plugbox.assign(Plugbox::timer, *this);
	pic.allow(PIC::timer);
}

bool Watch::prologue (){
	return fire_interrupt();
}

void Watch::epilogue (){
	scheduler.resume();
}
