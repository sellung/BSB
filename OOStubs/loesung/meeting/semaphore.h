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
#include "device/cgastr.h"

class Semaphore 
	: public Waitingroom
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    Semaphore (const Semaphore &copy); // Verhindere Kopieren
	int counter;
public:
	Semaphore (int c): Waitingroom(), counter(c){
		//kout << "counter=" << c << endl;
	}
	//inline void p ();
	//inline void v ();

	 void p ();
	 void v ();
	
	void wait (){ p(); }
	void signal() { v(); }

	virtual ~Semaphore ();
 };

//extern Semaphore keyboard_semaphore;

#endif
