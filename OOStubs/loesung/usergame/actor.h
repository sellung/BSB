#ifndef __actor_include__
#define __actor_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"
#include "usergame/game_object.h"

class Actor : public Game_Object
 
 {
private:
    Actor (const Actor &copy); // Verhindere Kopieren
    int rate;
    int width;
    int height;
    //char color;
    int frequency;
    int advance;
    char color_black;
public:
	enum {back=0, front=1};

    Actor(void* tos): Game_Object(tos),rate(10), width(9), frequency(100),advance(1), color_black(0x0){} 
    
    void speed(int s){ rate = s;}
    int speed(){ return rate; }

    int step() { return advance; }
    void step(int s) { advance =s; }

    void move_1(int x, int y, char color);
    void move_2(int x, int y, char color);
    void jump(int x, int y, char color);

    void clear_move_1(int x, int y);
    void clear_move_2(int x, int y);
    void clear_jump(int x, int y);

    void stop();
    
    void score();
    void high_score();
    void live();

    void action ();
 };


#endif 

