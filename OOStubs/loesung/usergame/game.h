#ifndef __game_include__
#define __game_include__

#include "guard/secure.h"
class Game {
private:
    Game (const Game &copy); // Verhindere Kopieren
    int rate;
    int width;
    int height;
    int posx;
    int posy;
    int frequency;
    int advance;
    char color_black;
    bool jump;
public:
	Game() {}
	//enum {back=0, front=1};

    //Game(),rate(10), width(9), frequency(500),advance(1),color_black(0x0){} 
    
    void speed(int s){ rate = s;}
    int speed(){ 
    	
    	return rate;
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