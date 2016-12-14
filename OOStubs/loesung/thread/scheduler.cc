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

void Scheduler::ready(Entrant& that) {
	*entrant = that;
	readylist.enqueue(entrant);
}

void Scheduler::schedule() {
	Entrant* entrant  = (Entrant*)readylist.dequeue();

	//entrant->action();
	go(*entrant);
}

void Scheduler::exit() {
	//readylist.remove(entrant);
	schedule();
}
void Scheduler::kill(Entrant& that) {
	readylist.remove(&that);
	//schedule();
}
void Scheduler::resume(){
	//readylist.remove(entrant);
	Entrant* entrant  = (Entrant*) active();
	readylist.enqueue(entrant);
	schedule();
}