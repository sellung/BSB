/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ O R G A N I Z E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Organizer.                                  */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "syscall/guarded_organizer.h"
#include "guard/secure.h"


void Guarded_Semaphore::ready (Thread& that){
	Secure secure;
	ready(that);
}

void Guarded_Semaphore::exit (){
	Secure secure;
	exit();
}

void Guarded_Semaphore::kill (Thread& that){
	Secure secure;
	kill(that);
}

void Guarded_Semaphore::resume (){
	Secure secure;
	resume();
}
