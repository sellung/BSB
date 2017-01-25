/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Zentrale Unterbrechungsbehandlungsroutine des Systems.                    */
/* Der Parameter gibt die Nummer des aufgetretenen Interrupts an.            */
/*****************************************************************************/

/* INCLUDES */
#include "device/cgastr.h" // only for test
#include "device/keyboard.h"
#include "device/watch.h"
#include "guard/guard.h"
#include "machine/plugbox.h"
#include "meeting/bellringer.h"

/* FUNKTIONEN */
               
extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-Level Interrupt-Behandlung. Die Funktion wird spaeter noch */
/*           erweitert.                                                     */

//int count_interrupt = 0;
int delay = 0;

bool wait = true;


void guardian (unsigned int slot)
{
	/*if(slot == plugbox.timer){
		//(plugbox.report(slot)).prologue();
		//bellringe.check();
	}
	if(slot == plugbox.keyboard){

	}
	Gate *g = &(plugbox.report(slot));
	guard.relay(g);
		*/
	
	count_interrupt ++;
	//if(wait_guardiant_PIT && slot == plugbox.timer){
	//	return;
	//}
	
	//(plugbox.report(slot)).prologue();
	
	//kout << "interrupt" << endl;
	Gate *g = &(plugbox.report(slot));
	guard.relay(g);
}

