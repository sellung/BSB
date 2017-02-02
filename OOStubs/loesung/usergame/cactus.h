#ifndef __cactus_include__
#define __cactus_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"

class Cactus : public Thread
 
 {
private:
    Cactus (const Cactus &copy); // Verhindere Kopieren
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

    Cactus(void* tos): Thread(tos),rate(20), width(12), frequency(200),advance(1){} 
    
    void speed(int s){ rate = s;}
    int speed(){ return rate; }

    int step() { return advance; }
    void step(int s) { advance =s; }

    void cactus1(int x, int y, char color);
    void cactus2(int x, int y, char color);
    void cactus3(int x, int y, char color);
    void cactus4(int x, int y, char color);

    void clear_cactus1(int x, int y);
    void clear_cactus2(int x, int y);
    void clear_cactus3(int x, int y);
    void clear_cactus4(int x, int y);

    void action ();
 };


#endif 

