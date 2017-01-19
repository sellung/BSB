/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Liste von Threads, die auf ein Ereignis warten.                           */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "meeting/waitingroom.h"
#include "syscall/guarded_organizer.h"
#include "thread/entrant.h"
#include "object/chain.h"

Waitingroom::~Waitingroom(){
	Chain* chain = dequeue();
	while(chain){
		Entrant* entrant = (Entrant*)chain;
		Customer* customer = (Customer*)entrant;
		scheduler.wakeup(*(customer));
		chain = dequeue();
	}
}

void Waitingroom::remove (Customer* customer) {
	Entrant* entrant = (Entrant*)customer;
	Chain* chain = (Chain*)entrant;
	Queue::remove(chain);
}


