#include "usergame/logic.h"
#include "device/cgastr.h"
#include "syscall/guarded_semaphore.h"

#include "usergame/game.h"
#include "syscall/guarded_organizer.h"

void Logic::action ()
 {	
 	buzzer.set(20);
 	buzzer.sleep();
 	while(1){
 		//semaphore.wait();
 		if(game.collision(game.bird_posx, game.bird_posy, game.width_bird, game.height_bird-2)){
 			//bird->sleep(200);
 			//scheduler.kill(*bird);
 			//scheduler.kill(*actor);
 			//scheduler.kill(*road);
 		}
 		//semaphore.signal();
	}
 }
