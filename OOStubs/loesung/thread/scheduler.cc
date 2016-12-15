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

Dispatcher dispatcher;

void Scheduler::ready(Entrant& that) {
	kout << "ready: " << that.getName() << endl;
	//Entrant* entrant = that;
	readylist.enqueue(&that);
}

void Scheduler::schedule() {
	kout << "schedule" << endl;
	Entrant* entrant  = (Entrant*)readylist.dequeue();
	kout << "Scheduler::schedule " << entrant->getName() << endl;
	//entrant->action();
	//if(active() == 0){
		go(*entrant);
	//}
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