/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "thread/scheduler.h"
#include "device/cgastr.h"


void Scheduler::ready(Entrant& that) {
	kout << "ready: " << that.getName() << endl;
	readylist.enqueue(&that);
}

void Scheduler::schedule() {
	Entrant* entrant  = (Entrant*)readylist.dequeue();
	Dispatcher::go(*entrant);	
}

void Scheduler::exit() {
	//readylist.remove(entrant);
	resume();
}
void Scheduler::kill(Entrant& that) {
	readylist.remove(&that);
	//schedule();
}
void Scheduler::resume(){
	Entrant* entrant  = (Entrant*) active();
	readylist.enqueue(entrant);
	entrant  = (Entrant*)readylist.dequeue();
	
	dispatch(*entrant);
}
