/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Dispatcher.                                           */
/* Der Dispatcher verwaltet den life-Pointer, der die jeweils aktive         */
/* Koroutine angibt. mit go() wird der life Pointer initialisiert und die    */
/* erste Koroutine gestartet, alle weiteren Kontextwechsel werden mit        */
/* dispatch() ausgeloest. active() liefert den life Pointer zurueck.         */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "thread/dispatch.h"
#include "device/cgastr.h"


void Dispatcher::go (Coroutine& first){
	kout << "Dispatcher::go" << endl;
	if(lifeptr == 0){
		first.go();
	}
	*lifeptr = first;

}
void Dispatcher::dispatch (Coroutine& next){
	lifeptr->resume(next);
	*lifeptr = next;
}
Coroutine* Dispatcher::active(){
	return lifeptr;
}
