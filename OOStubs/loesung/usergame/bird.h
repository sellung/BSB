#ifndef __bird_include__
#define __bird_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "usergame/game_object.h"
#include "usergame/game.h"

class Bird : public Game_Object
 
 {
private:
    Bird (const Bird &copy); // Verhindere Kopieren
    //Guarded_Buzzer buzzer;
    int rate;
    int width;
    int height;
    //char color;
    int posx;
    int posy;
    int frequency;
    int advance;

public:
	enum {back=0, front=1};

    Bird(void* tos): Game_Object(tos),rate(5),  width(game.width_bird), frequency(200),advance(5){
        //width(game.width_bird);
    } 
    
    void speed(int s){ rate = s;}
    int speed(){ return rate; }

    int step() { return advance; }
    void step(int s) { advance =s; }

    void fly(int x, int y);

    void flyup(int x, int y, char color);
    void flydown(int x, int y, char color);

    void clear_flyup(int x, int y);
    void clear_flydown(int x, int y);

    void action ();
 };


#endif 

