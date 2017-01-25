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

Guarded_Organizer scheduler;

void Guarded_Organizer::ready (Thread& that){
	Secure secure;
	ready(that);
}

void Guarded_Organizer::exit (){
	Secure secure;
	exit();
}

void Guarded_Organizer::kill (Thread& that){
	Secure secure;
	kill(that);
}

void Guarded_Organizer::resume (){
	Secure secure;
	resume();
}

void Guarded_Organizer::block (Customer& customer, Waitingroom& waitingroom){
	Secure secure;
	Organizer::block(customer, waitingroom);
}
void Guarded_Organizer::wakeup (Customer& customer){
	Secure secure;
	Organizer::wakeup(customer);
}
void Guarded_Organizer::kill (Customer& that){
	Secure secure;
	Organizer::kill(that);
}
