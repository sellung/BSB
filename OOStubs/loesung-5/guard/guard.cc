/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse koennen Aktivitaeten, die einen kritischen        */
/* Abschnitt betreffen, der mit einem Guard-Objekt geschuetzt ist, mit       */
/* Unterbrechungsbehandlungsroutinen synchronisiert werden, die ebenfalls    */
/* auf den kritischen Abschnitt zugreifen.                                   */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "guard/guard.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

Guard guard;

void Guard::leave(){
	cpu.disable_int();
	Gate *g = (Gate *)queue.dequeue();
	while(g){ 				// if there are something in the queue
		g->queued(false); 	// validate dequeue operation for the refence 
		cpu.enable_int();
		g->epilogue();		// run epilogue. Here we don't need to block the epilogue operation, because 
		cpu.disable_int();
		g = (Gate *)queue.dequeue();						// we are already in a critic section
	}
	retne();				//  leave critic section. 
	cpu.enable_int();
} 

void Guard::relay (Gate* item){
	if(item->prologue()){			// if the prologue tell us that an epilogue will be run then,
		if(avail()){				// we check if critic section is available
			enter();
			cpu.enable_int();				// when critic section is available enter in critic section
			item->epilogue();
					// and run the epilogue
			leave();				// leave critic section when all is finish
		}else{						// critic section is not available
			if(!item->queued()){	// queue the action for the late run
		 		queue.enqueue(item);
		 		item->queued(true);
			}
		}
	}
}