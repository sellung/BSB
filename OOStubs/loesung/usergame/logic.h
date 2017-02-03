#ifndef __logic_include__
#define __logic_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"

#include "usergame/actor.h"
#include "usergame/bird.h"
#include "usergame/cactus.h"
#include "usergame/road.h"

class Logic : public Thread
 
 {
private:
    Logic (const Logic &copy); // Verhindere Kopieren
    Guarded_Buzzer buzzer;

    Actor* actor;
    Bird* bird;
    Cactus* cactus;
    Road* road;

public:
	enum {back=0, front=1};

    Logic(void* tos, Actor* a, Bird* b, Cactus* c,Road* r): 
        Thread(tos), actor(a), bird(b), cactus(c), road(r){} 
  
    void action ();
 };


#endif 

