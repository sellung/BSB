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
//#include "device/cgastr.h" // only for test
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "guard/guard.h"

/* FUNKTIONEN */
               
extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-Level Interrupt-Behandlung. Die Funktion wird spaeter noch */
/*           erweitert.                                                     */

void guardian (unsigned int slot)
{
	//(plugbox.report(slot)).trigger();
	
	Gate *g = &(plugbox.report(slot));
	guard.relay(g);
}
