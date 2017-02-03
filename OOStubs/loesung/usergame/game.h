#ifndef __game_include__
#define __game_include__

#include "guard/secure.h"
class Game {
private:
    Game (const Game &copy); // Verhindere Kopieren
    int rate;
    int width;
    int height;
   
    int frequency;
    int advance;
    
    bool jump;
    
    int timer;
    
public:
	enum { color_black= 0x0,  color_cyan= 0x3,color_red=0x5};
	enum {width_actor=9, width_bird=15, width_cactus=12};
    enum {height_actor=6, height_bird=9, height_cactus=12};

    Game() {}
	char color;
	int actor_posx;
    int actor_posy;

    int bird_posx;
    int bird_posy;

    void speed(int s){ 
		Secure secure;
		timer = s;
	}

    bool collision(int x, int y, int width, int height);


    int speed(){ 
		Secure secure;
    	return timer;
     }

    int step() { return advance; }
    void step(int s) { advance =s; }

    void setjump(bool j) { 
    	Secure secure;
    	jump = j;
    }
    bool getjump() {
     	Secure secure;
     	return jump; 
    }
 };


extern Game game;

#endif
