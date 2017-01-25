/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Queue, die der Gloeckner verwaltet.        */
/*****************************************************************************/

#include "meeting/bellringer.h"
#include "syscall/guarded_organizer.h"
#include "object/chain.h"

Bellringer bellringer;

void Bellringer::check (){
	Chain* chain = first();
	while(chain){
		Bell* bell = (Bell*) chain;
		bell->tick();
		if(bell->run_down()){
			bell->ring();
			remove(chain);
		}
		chain = chain->next;
	}
}

void Bellringer::job (Bell *bell, int ticks){
	bell->wait(ticks);
	insert_first((Chain*)bell);
}

void Bellringer::cancel (Bell *bell){
	remove((Chain*)bell);
}
