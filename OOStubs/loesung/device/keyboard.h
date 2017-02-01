/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
#include "device/cgastr.h" // only for test
#include "machine/cgascr.h"
#include "machine/pic.h"
#include "syscall/guarded_semaphore.h"

// #include "machine/keyctrl.h"
// #include "machine/pic.h"
// #include "machine/plugbox.h"

class Keyboard 
:public Gate , public Keyboard_Controller      
{        
private:
    Keyboard (const Keyboard &copy); // Verhindere Kopieren              
//CGA_Screen cgaScreen;
    int count;
    Key key;
    Guarded_Semaphore keyboard_sem;
public:
	
 	Keyboard() :Keyboard_Controller(), count(0),keyboard_sem(1){}
    // PLUGIN: 'Anstoepseln' der Tastatur. Ab sofort werden Tasten erkannt.
    void plugin ();

   	void trigger ();
   	char* tostring();
   	void hello();

   	bool prologue();
   	void epilogue();
   	
   	Key getkey();
 };

 //extern Keyboard keyboard;

#endif
