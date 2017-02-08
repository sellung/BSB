#ifndef __game_include__
#define __game_include__

#include "guard/secure.h"
#include "device/cgastr.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_organizer.h"
//#include "usergame/actor.h"
//#include "usergame/cactus.h"

class Actor;
class Cactus;

class Game {
private:
    Game (const Game &copy); // Verhindere Kopieren

    int rate;
    int width;
    int height;
   
    int frequency;
    
    bool jump;
    bool actor_up_or_down;
    bool hit;

    int timer;

    Guarded_Semaphore game_sem;

public:
    enum {OFF=0, START=1, ON=2, PAUSE=3, OVER=4, RESTART=5};
	enum { color_black= 0x0,  color_cyan= 0x3,color_red=0x5, maxlive=20, start_rate=5};
	enum {width_actor=9, width_bird=15, width_cactus=12};
    enum {height_actor=6, height_bird=9, height_cactus=12};
   
    char game_object_color;
    char game_object_clear_color;
    int collision_count;
     int advance;

    int score;
    int high_score;
    int live;

    int game_status;
    bool key_space_press_status;
    bool pause;

    Thread *actor;
    Thread *cactus;

    Guarded_Semaphore game_start_sem;

    Game() :rate(start_rate),jump(false), actor_up_or_down(false), game_sem(0),
        game_object_color(0x70), game_object_clear_color(0x77), collision_count(0), advance(2),live(maxlive),
        game_status(OFF),key_space_press_status(false),pause(false),
        game_start_sem(0){}
	char color;
	int actor_posx;
    int actor_posy;

   bool ispause(){
       Secure secure;
       return pause;
   }

   void setpause(bool b){
        Secure secure;
        pause = b;
   }

   void tooglepause(){
       Secure secure;
       pause = pause? false : true;
   }

    void wan_to_startgame(){
        if(game_status == OFF){
            game_start_sem.signal();
        }
    }
    bool iskeyspacepressed(){
        Secure secure;
        return key_space_press_status;
    }
    void presskeyspace(bool b){
        Secure secure;
        key_space_press_status = b;
    }
    void setgame(Actor *a, Cactus *c){
        actor = (Thread*)a; 
        cactus =(Thread*)c; 
    }
    void start_game(){
        scheduler.ready(*actor);
	    scheduler.ready(*cactus);
        //scheduler.resume();
    }
    void end_game(){
        scheduler.kill(*actor);
	    scheduler.kill(*cactus);
    }
    void set_actor_posy(int y){
       // Secure secure;
        actor_posy = y;
    }
    
    void wan_to_godown(){
        actor_up(true);
        game_sem.wait();
    }

    void godown(){
        actor_up(false);
        game_sem.signal();
    }

    bool is_actor_up(){
        Secure secure;
        return actor_up_or_down;
    }
    void actor_up(bool b){
        Secure secure;
        actor_up_or_down = b;
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
        if(s <= 3){ advance = 1;}
		rate = s;
	}
    int speed(){ 
        Secure secure;
        return rate;
     }

    bool collision(int x, int y, int width, int height);

    int step() { return advance; }
    void step(int s) { advance =s; }

    void setjump(bool j) { 
    	Secure secure;
    	jump = j;
    }
    bool isjump() {
     	Secure secure;
     	return jump; 
    }

    void day();

    void day(int x, int y);
    
    void night();

    void clearscreen(char bgcolor){
        int row = 0;
        int col = 0;
        for ( row =0; row < 80 ; row ++) {
            for ( col =1; col < 24 ; col ++) {
            kout.show( row , col , ' ' , bgcolor );
            }
        }
        // Move the cursor back to the top left corner.
        kout. setpos(0 , 0);
    }

     void clearscreen(int x, int y, char bgcolor){
        int row = 0;
        int col = 0;
        for ( row =x; row < 80 ; row ++) {
            for ( col =y; col < 24 ; col ++) {
            kout.show( row , col , ' ' , bgcolor );
            }
        }
        // Move the cursor back to the top left corner.
        kout. setpos(0 , 0);
    }
 
 };

extern Game game;

#endif
