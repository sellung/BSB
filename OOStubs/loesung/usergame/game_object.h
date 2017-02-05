#ifndef __game_object_include__
#define __game_object_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"
#include "device/cgastr.h"

#include "usergame/game.h"

class Game_Object : public Thread
 
 {
private:
    Game_Object (const Game_Object &copy); // Verhindere Kopieren
    Guarded_Buzzer buzzer;
public:
	
    Game_Object(void* tos): Thread(tos){} 
    //void action ();

    void sleep(int time){
        buzzer.set(time);
        buzzer.sleep();
    }

    void collision_with_actor(int x,int y, const int width, const int height){
        int time = 50;
        if((x >= 5 && x<= game.actor_posx + game.width_actor -2) || (x + width>= 5 && x + width<= game.actor_posx + game.width_actor)){
            
            if(y >= game.actor_posy && y <= game.actor_posy + game.height_actor){
                //if(height )
                //game.set_actor_posy(game.actor_posy - 8);
                //game.clash(true);
                kout.setpos(0,24);
                kout << "colision:" <<"x:" << x<< " y:" << y << " actor_posy:" << game.actor_posy << " actor_posy + height_actor=" << game.actor_posy + game.height_actor;
                kout.flush();
                
                kout.setpos(70,24);
                kout << "HIT: " << game.collision_count++;
                kout.flush();
               // sleep(time);
            }else{
                //game.clash(false);
                kout.setpos(0,24);
                kout << "NO colision:" << " y=" << y << " game.actor_posy + game.height_actor=" << game.actor_posy + game.height_actor;
                kout.flush();
                //sleep(time);
            }
        }else{
            kout.setpos(0,24);
            kout << "                                                                      ";
            kout.flush();
        }
    }
 };

#endif 

