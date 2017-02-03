#ifndef __game_object_include__
#define __game_object_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"

class Game_Object : public Thread
 
 {
private:
    Game_Object (const Game_Object &copy); // Verhindere Kopieren
    Guarded_Buzzer buzzer;
public:
	
    Game_Object(void* tos): Thread(tos){} 
    //void action ();

    void sleep(int time){
        buzzer.set(time);
        buzzer.sleep();
    }
 };

#endif 

