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
#include "device/cgastr.h"
#include "syscall/guarded_scheduler.h"
#include "machine/plugbox.h"
#include "machine/pic.h"

//Plugbox plugbox;
//PIC pic;

void Watch::windup (){
	plugbox.assign(Plugbox::timer, *this);
	pic.allow(PIC::timer);
}

bool Watch::prologue (){
	return true;
}

void Watch::epilogue (){
	//kout << "epilogue" <<endl;
	scheduler.Scheduler::resume();
}

char* Watch::tostring(){
	return "Ich bin Timer";
}

void Watch::trigger (){
	
}
