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
#include "thread/entrant.h"
#include "meeting/waitingroom.h"

void Organizer::block (Customer& customer, Waitingroom& waitingroom){
	customer.waiting_in(&waitingroom);
	exit();
}

void Organizer::wakeup (Customer& customer){
	customer.waiting_in(0);
	Entrant* entrant  = (Entrant*)&customer;
	ready(*(entrant));
}

void Organizer::kill (Customer& that){
	Waitingroom* w = that.waiting_in();
	if(w){
		w->remove(&that);
	}else{
		Entrant* entrant  = (Entrant*)&that;
		Scheduler::kill(*(entrant));
	}
}

Customer* Organizer::active(){
	Entrant* entrant  = (Entrant*)Scheduler::active();
	Customer* customer = (Customer*)entrant;
	return customer;
}
