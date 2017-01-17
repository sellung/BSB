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

void Semaphore::p() {
	if(c > 0){
		c--;
	}else{
		enqueue(lifeCustomer);
	}
}

void Semaphore::v() {
	Customer* customer = dequeue();
	if(customer != 0){
		
	}else{
		counter ++;
	}
}
