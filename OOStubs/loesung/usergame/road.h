#ifndef __road_include__
#define __road_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"

class Road : public Thread
 
 {
private:
    Road (const Road &copy); // Verhindere Kopieren
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

    Road(void* tos): Thread(tos),rate(5), width(15), frequency(500),advance(2){} 
    
    void speed(int s){ rate = s;}
    int speed(){ return rate; }

    int step() { return advance; }
    void step(int s) { advance =s; }


    void draw_road(int x, int y, char color);
    void clear_road(int x, int y);
    void action ();
 };


#endif 

