/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
        
#include "object/queue.h"
#include "thread/entrant.h"

class Scheduler: public Dispatcher
{
	private:
    	Scheduler (const Scheduler &copy); // Verhindere Kopieren
    	Queue readylist;
		Queue applicationlist;
     	// Entrant* entrant;
	public:
		Scheduler():Dispatcher(){}

		void ready(Entrant& that);
		void schedule();
		void exit();
		void kill(Entrant& that);
		void resume();
		void application(Entrant& that);
};

//extern Scheduler scheduler;
 
#endif
