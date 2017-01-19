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
#include "syscall/guarded_scheduler.h"

void Semaphore::p() {
	if(counter > 0){
		counter--;
	}else{
		Coroutine* lifeptr = scheduler.active();
		//Customer* lifeCustomer = (Entrant*)lifeptr;
		
		//((Customer*)(Entrant*)lifeptr)->bloc();
	}
}

void Semaphore::v() {
	Customer* customer;//= dequeue();
	if(customer != 0){
		
	}else{
		counter ++;
	}
}

