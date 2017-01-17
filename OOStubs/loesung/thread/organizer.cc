/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Organizer ist ein spezieller Scheduler, der zusaetzlich das Warten    */
/* von Threads (Customer) auf Ereignisse erlaubt.                            */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "thread/organizer.h"
#include "thread/entrant"

void Organizer::block (Customer& customer, Waitingroom& waitingroom){
	//Customer* c = (Customer*)((Entrant*)active());
	//c->waitin_in(&waitingroom);
	customer.waiting_in(waitingroom);	
	resume();
}

void Organizer::wakeup (Customer& customer){
	customer.waiting_in(0);
	ready(customer)
}

void Organizer::kill (Customer& that){
	if(that.wainting){
		kill(that);
	}else{
		that.waiting_in(0);
	}
}
