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
	Game() {}
	const char color_black = 0x0;
	const char color_cyan = 0x3;
	const char color_red = 0x5;
	
	char color;
	int actor_posx;
    int actor_posy;
    
    void speed(int s){ 
		Secure secure;
		timer = s;
	}
	
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
