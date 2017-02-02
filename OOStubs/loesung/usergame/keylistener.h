#ifndef __keylistener_include__
#define __keylistener_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"

 class Keylistener : public Thread
 
 {
private:
    Keylistener (const Keylistener &copy); // Verhindere Kopieren
    //Guarded_Keyboard guarded_keyboard;
    Key key;
public:
	int row;
	int col;
	int i;
	int id;
	int count;

    Keylistener(void* tos): Thread(tos), i(0), count(0){
		//buzzer.set(10);
	} 
    void action ();
    void setCoord(int c, int r){ col = c; row = r;}
 };

#endif
