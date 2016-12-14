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

void Scheduler::ready(Entrant& that) {
	entrant = that;
	readylist.enqueue(that);
}

void Scheduler::schedule() {
	entrant = readylist.dequeue();
	entrant->action();
}

void Scheduler::exit() {
	//readylist.remove(entrant);
	schedule();
}
void Scheduler::kill(Entrant& that) {
	readylist.remove(that);
	//schedule();
}
void Scheduler::resume(){
	//readylist.remove(entrant);
	readylist.enqueue(entrant);
	schedule();
}