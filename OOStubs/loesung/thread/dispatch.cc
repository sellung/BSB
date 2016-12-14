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
#include "thread/dispatcher.h"

void Dispatcher::go (Coroutine& first){
	lifeptr = first;
	first.go();
}
void Dispatcher::dispatch (Coroutine& next){
	lifeptr.resume(next);
	lifeptr = next;
}
Coroutine* Dispatcher::active(){
	return lifeptr;
}