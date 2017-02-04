#ifndef __game_include__
#define __game_include__

#include "guard/secure.h"
#include "device/cgastr.h"

class Game {
private:
    Game (const Game &copy); // Verhindere Kopieren
    int rate;
    int width;
    int height;
   
    int frequency;
    int advance;
    
    bool jump;
    bool hit;

    int timer;
    
public:
	enum { color_black= 0x0,  color_cyan= 0x3,color_red=0x5};
	enum {width_actor=9, width_bird=15, width_cactus=12};
    enum {height_actor=6, height_bird=9, height_cactus=12};
   // enum {game_object_color=0x70, game_object_clear_color=0x77};

    char game_object_color;
    char game_object_clear_color;
    Game() : game_object_color(0x70), game_object_clear_color(0x77){}
	char color;
	int actor_posx;
    int actor_posy;

    void set_actor_posy(int y){
        Secure secure;
        actor_posy = y;
    }

    bool isclash(){ return hit; }
    void clash(bool c) { 
        //Secure secure;
        hit = c;
    }

    int bird_posx;
    int bird_posy;

    void speed(int s){ 
		Secure secure;
		timer = s;
	}
    int speed(){ 
        Secure secure;
        return timer;
     }

    bool collision(int x, int y, int width, int height);

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

    void day();

    void night();

    void clearscreen(char bgcolor){
    int row = 0;
    int col = 0;
    for ( row =0; row < 80 ; row ++) {
        for ( col =0; col < 24 ; col ++) {
        kout.show( row , col , ' ' , bgcolor );
        }
    }
    // Move the cursor back to the top left corner.
    kout. setpos(0 , 0);
}
 };


extern Game game;

#endif
