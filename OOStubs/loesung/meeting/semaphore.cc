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
#include "meeting/Semaphore.h"
#include "guard/guard.h"
#include "guard/secure.h"

void Semaphore::p() {
	guard.enter();
	if(c > 0){
		c--;
	}else{
		enqueue(lifeCustomer);
	}
	guard.leave();
}

void Semaphore::v() {
	guard.enter();
	Customer* customer = dequeue();
	if(customer != 0){
		
	}else{
		counter ++;
	}
	guard.leave();
}
