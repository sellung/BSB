/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Scheduler.                                  */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "syscall/guarded_scheduler.h"
#include "guard/secure.h"

//Guarded_Scheduler scheduler;

void Guarded_Scheduler::ready(Thread& that){
	Secure secure;
	ready(that);
}

void Guarded_Scheduler::exit(){
	Secure secure;
	exit();
}

void Guarded_Scheduler::kill(Thread& that){
	Secure secure;
	kill(that);
}

void Guarded_Scheduler::resume(){
	Secure secure;
	resume();
}
