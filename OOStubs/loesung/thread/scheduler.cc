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
#include "machine/cpu.h"

void Scheduler::ready(Entrant& that) {
	//kout << "ready: " << that.getName() << endl;
	//cpu.disable_int();
	readylist.enqueue(&that);
	//cpu.enable_int();
}

void Scheduler::schedule() {
	Entrant* entrant  = (Entrant*)readylist.dequeue();
	//kout << "Schedule()" << endl;
	Dispatcher::go(*entrant);	
}

void Scheduler::exit() {
	Entrant* entrant = (Entrant*)readylist.dequeue();
	dispatch(*entrant);
}
void Scheduler::kill(Entrant& that) {
	//cpu.disable_int();
	readylist.remove(&that);
	//kout << "kill" << endl;
	//cpu.enable_int();
	//schedule();
}
void Scheduler::resume(){
	//kout << "resume()" << endl;
	Entrant* entrant  = (Entrant*) active();
	//cpu.disable_int();
	readylist.enqueue(entrant);
	entrant  = (Entrant*)readylist.dequeue();
	//cpu.enable_int();
	
	dispatch(*entrant);
}

void Scheduler::application(Entrant& that) {
	applicationlist.enqueue(&that);
}
