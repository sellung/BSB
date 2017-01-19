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

void Organizer::block (Customer& customer, Waitingroom& waitingroom){
	customer.waiting_in(&waitingroom);
	resume();
}

void Organizer::wakeup (Customer& customer){
	customer.waiting_in(0);
	Entrant* entrant  = (Entrant*)&customer;
	ready(*(entrant));
}

void Organizer::kill (Customer& that){
	if(that.waiting_in()){
		Entrant* entrant  = (Entrant*)&that;
		Scheduler::kill(*(entrant));
	}else{
		that.waiting_in(0);
	}
}

Customer* Organizer::active(){
	Entrant* entrant  = (Entrant*)Scheduler::active();
	Customer* customer = (Customer*)entrant;
	return customer;
}
