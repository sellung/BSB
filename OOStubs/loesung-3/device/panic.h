/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */

#include "guard/gate.h"
#include "device/cgastr.h" // only for test
#include "machine/cpu.h"

class Panic : public Gate
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    Panic (const Panic &copy); // Verhindere Kopieren
    CGA_Stream kout;
public:
    Panic (){}
/* Hier muesst ihr selbst Code vervollstaendigen */                  
	void trigger ();  
	char* tostring();

	bool prologue();
 };

extern Panic panic;

#endif

