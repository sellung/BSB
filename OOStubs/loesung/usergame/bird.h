#ifndef __bird_include__
#define __bird_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"

class Bird : public Thread
 
 {
private:
    Bird (const Bird &copy); // Verhindere Kopieren
    Guarded_Buzzer buzzer;
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

    Bird(void* tos): Thread(tos),rate(5), width(15), frequency(200),advance(5){} 
    
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

