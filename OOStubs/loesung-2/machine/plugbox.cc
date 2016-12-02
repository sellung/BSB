/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Behandlungs- */
/* routine fuer jeden Hardware-, Softwareinterrupt und jede Prozessor-       */
/* exception festlegen.                                                      */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "plugbox.h"

Plugbox plugbox;

//CGA_Stream kout;
// Mit dieser Methode kann das Objekt einer spezialisierten Unterbrechungsbehandlung 
// gate zu der Unterbrechung Nummer slot in die Plugbox eingetragen werden.
void Plugbox::assign (unsigned int slot, Gate& gate){
	//kout << gate.tostring() << endl;
	gates[slot] = &gate;
}

// Hiermit kann das Gate-Objekt abgefragt werden, das zu der Unterbrechung Nummer slot 
// in die Plugbox eingetragen wurde.
Gate& Plugbox::report (unsigned int slot){
	//kout << gates[slot]->tostring() << endl;
	return *gates[slot];
}