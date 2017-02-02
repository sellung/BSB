#ifndef __actor_include__
#define __actor_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"

class Actor : public Thread
 
 {
private:
    Actor (const Actor &copy); // Verhindere Kopieren
    Guarded_Buzzer buzzer;
    int rate;
    int width;
    int height;
    //char color;
    int frequency;
    int advance;
public:
	enum {back=0, front=1};

    Actor(void* tos): Thread(tos),rate(10), width(9), frequency(100),advance(1){} 
    
    void speed(int s){ rate = s;}
    int speed(){ return rate; }

    int step() { return advance; }
    void step(int s) { advance =s; }

    void fly(int x, int y);

    void move_1(int x, int y);
    void move_2(int x, int y);
    void jump(int x, int y);

    void clear_move_1(int x, int y);
    void clear_move_2(int x, int y);
    void clear_jump(int x, int y);

    void action ();
 };


#endif 

