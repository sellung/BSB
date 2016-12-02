/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Adresse der  */
/* Behandlungsroutine fuer jeden Hardware-, Softwareinterrupt und jede       */
/* Prozessorexception festlegen.                                             */
/*****************************************************************************/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"
#include "device/panic.h"
#include "device/cgastr.h"

//extern CGA_Stream kout;

class Plugbox
 {
 	//Panic panic;
private:
    Plugbox(const Plugbox &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */ 
    Gate *gates[64];
public:
	enum { timer = 32,  keyboard = 33};

	// Im Konstruktor wird für alle Unterbrechungen und Ausnahmen das global bekannte 
	// Panic-Objekt panic eingetragen, das eine minimale Unterbrechungsbehandlung sicherstellt.
	Plugbox(){
		//kout << "init" << count << endl;
		for (int i = 0; i < 64; ++i){
			gates[i] = &panic;  	
		}  
	}

	// Mit dieser Methode kann das Objekt einer spezialisierten Unterbrechungsbehandlung 
	// gate zu der Unterbrechung Nummer slot in die Plugbox eingetragen werden.
	void assign (unsigned int slot, Gate& gate);

	// Hiermit kann das Gate-Objekt abgefragt werden, das zu der Unterbrechung Nummer slot 
	// in die Plugbox eingetragen wurde.
	Gate& report (unsigned int slot);

 };

extern Plugbox plugbox;

#endif
