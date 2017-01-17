/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S E M A P H O R E                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Semaphor.                                   */
/*****************************************************************************/

#ifndef __Guarded_Semaphore_include__
#define __Guarded_Semaphore_include__

#include "thread/organizer.h"
#include "thread/thread.h"
        
class Guarded_Semaphore 
	: Organizer
 {
private:
    Guarded_Semaphore (const Guarded_Semaphore &copy); // Verhindere Kopieren
public:
	Guarded_Semaphore () : Organizer() {}
	
	void ready (Thread& that);
	void exit ();
	void kill (Thread& that);
	void resume ();
 };

#endif
