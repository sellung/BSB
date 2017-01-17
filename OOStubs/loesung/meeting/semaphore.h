/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#ifndef __Semaphore_include__
#define __Semaphore_include__

#include "meeting/waitingroom.h"

class Semaphore 
	: Waitingroom
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    Semaphore (const Semaphore &copy); // Verhindere Kopieren
	int counter;
	Customer* lifeCustomer;
public:
	Semaphore (int c): Waitingroom(), counter(c){}
	inline void p ();
	inline void v ();
	
	void wait (){ p(); }
	void signal() { v(); }
 };

#endif
