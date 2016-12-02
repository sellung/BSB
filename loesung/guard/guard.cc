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
	
	Gate *g = (Gate *)queue.dequeue();

	if(g !=0){
		//kout << "leave" << endl;
		//cpu.disable_int();
		g->queued(false);
		g->epilogue();
		//cpu.enable_int();
	}
	retne();
} 

void Guard::relay (Gate* item){
	if(item->prologue()){
		if(avail()){
			//kout << "available" << item->queued() << count++ << endl;
			//enter();
			// if(item->queued()){
			// 	leave();
			// }else{
			enter();
			item->epilogue();
			
			leave();
			// }	
		}else{
			//kout << " nicht available" << count++ << endl;
			if(!item->queued()){
		 		//kout << " Item in queued" << endl;
		 		queue.enqueue(item);
		 		item->queued(true);
			}
		}
	}
}