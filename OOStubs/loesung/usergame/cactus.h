#ifndef __cactus_include__
#define __cactus_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"

#include "usergame/game_object.h"

class Cactus : public Game_Object
 
 {
private:
    Cactus (const Cactus &copy); // Verhindere Kopieren

    int rate;
    int width;
    int height;
    //char color;
    int posx;
    int posy;
    int frequency;
    int advance;
    int distance;

    bool flyhigh;

    int cactus1_h; int cactus1_w;
    int cactus2_h; int cactus2_w; 
    int cactus3_h; int cactus3_w;
    int cactus4_h; int cactus4_w;

    int bird_h; int bird_w;

     Guarded_Semaphore jump_sem;

public:
	enum {back=0, front=1};

    Cactus(void* tos): Game_Object(tos),rate(4), width(11), frequency(200),advance(2), distance(40), flyhigh(false),
        cactus1_h(5), cactus1_w(11),
        cactus2_h(5), cactus2_w(14), 
        cactus3_h(5), cactus3_w(9), 
        cactus4_h(5), cactus4_w(14),
        bird_h(3), bird_w(16),
        jump_sem(1)
        {} 
    
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


    void flyup(int x, int y, char color);
    void flydown(int x, int y, char color);

    void clear_flyup(int x, int y);
    void clear_flydown(int x, int y);


    void sun(int x, int y, char color);

    void cloud1(int x, int y, char color);
    void cloud2(int x, int y, char color);

    void clear_cloud1(int x, int y);
    void clear_cloud2(int x, int y);

    void tooglefly(){ flyhigh = flyhigh? false: true;}

    //void collision(int x,int y, int width, int height);

    void action ();

    void draw(void (*fkt)(int x, int y, char color));
    
    void ground(int x, int y);

    //void wait_jump();
 };


#endif 

