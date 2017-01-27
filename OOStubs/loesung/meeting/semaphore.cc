/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "meeting/semaphore.h"
#include "guard/guard.h"
#include "guard/secure.h"
#include "thread/entrant.h"
#include "thread/coroutine.h"
#include "syscall/guarded_organizer.h"
#include "thread/organizer.h"

//Semaphore keyboard_semaphore(1);

void Semaphore::p() {
	//kout << "p() counter=" << counter << endl;
	if(counter > 0){
		counter--;
		//kout << "p(--)" << endl;
	}else{
		//kout << "p(2)" << endl;
		Customer* lifeCustomer = scheduler.Organizer::active();
		scheduler.Organizer::block(*(lifeCustomer), *this);
	}
}

void Semaphore::v() {
	//kout << "v() counter=" <<  counter << endl;
	Entrant* entrant = (Entrant*)dequeue();
	if(entrant != 0){
		Customer* customer = (Customer*)entrant;
		scheduler.wakeup(*(customer));
	}else{
		counter ++;
	}
}

Semaphore::~Semaphore(){}

