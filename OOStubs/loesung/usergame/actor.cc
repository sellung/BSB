#include "usergame/actor.h"
#include "device/cgastr.h"
#include "syscall/guarded_semaphore.h"

#include "usergame/game.h"

void Actor::move_1(int x, int y, char color){
	kout.setpos(x,y);
	kout.print("  //     ", width, color); kout.setpos(x,y+1);	  
	kout.print("  \\\\_  ", width, color); kout.setpos(x,y+2);	  
	kout.print("  ( o_>  ", width, color); kout.setpos(x,y+3);	  
	kout.print("  /:\\__ ", width, color); kout.setpos(x,y+4);	  
	kout.print(" /:_/`\"`", width, color); kout.setpos(x,y+5); 	             
	kout.print("@\\/\\) -", width, color); kout.setpos(x,y+6);	     
	kout.print("  \" \"  ", width, color);	  
 }

void Actor::clear_move_1(int x, int y){
	move_1(x, y,  game.game_object_clear_color);
 } 
      
void Actor::move_2(int x, int y, char color){      
	kout.setpos(x,y);
	kout.print("  //     ", width, color); kout.setpos(x,y+1);	  	  
	kout.print("  \\\\_    ", width, color); kout.setpos(x,y+2);	  
	kout.print("  ( o_>  ", width, color); kout.setpos(x,y+3);	  
	kout.print("  /:\\__ ", width, color); kout.setpos(x,y+4);	  
	kout.print(" /:_/`\"`", width, color); kout.setpos(x,y+5);	             
	kout.print("@\\)   --", width, color); kout.setpos(x,y+6);	  
	kout.print(" \"      ", width, color);	                 
}

void Actor::clear_move_2(int x, int y){      
	move_2(x, y,  game.game_object_clear_color);
}
      

void Actor::jump(int x, int y, char color){    
	//x = x +4;  
	kout.setpos(x,y);      
	kout.print(" \\\\      ", width, color); kout.setpos(x,y+1);
	kout.print("  \\\\_    ", width, color); kout.setpos(x,y+2);
	kout.print("  ( o_>  ", width, color); kout.setpos(x,y+3);
	kout.print("  /:\\__ ", width, color); kout.setpos(x,y+4);
	kout.print(" /:_/`\"`", width, color); kout.setpos(x,y+5);
	kout.print("@\\/\\)  ", width-4, color); kout.setpos(x,y+6);	     
	kout.print("  \" \"  ", width, color);
	kout.setpos(5,21);
	kout.print("---------", 9, color);	     
}

void Actor::clear_jump(int x, int y){      
	 jump(x, y, game.game_object_clear_color);
}

void Actor::action ()
 {
 	//buzzer.set(1);
 	//buzzer.sleep();

 	sleep(1);
	game.actor_posx = 5; 
	game.actor_posy = 16;
	
	int oldx = game.actor_posx; int newy=game.actor_posy;
	//advance = 2;

	//int dec_jump = 1;

 	while(1){
 		
 		if(game.getjump()){
 			semaphore.wait();
 			clear_move_2(oldx, game.actor_posy);
 			clear_move_1(oldx, game.actor_posy);
 			
 			semaphore.signal();

 			while(newy > 4){
 				newy--;
 				game.actor_posy = newy;
 				if(oldx < game.actor_posx+4){ oldx++; }
 				semaphore.wait();
 				clear_jump(oldx-1, newy+1);
 				jump(oldx, newy, game.game_object_color);
 				semaphore.signal();

 				//sleep(dec_jump);
 			}
 			//newy = 5;
 			//oldx = game.actor_posx + 4;
 			int oldy = newy;
 			//game.actor_posy = newy;
 			//jump(game.actor_posx, newy, game.game_object_color);

 			
 			
 			//sleep(95);
 			sleep(45);

 			while(newy < 16){
 				newy++;
 				game.actor_posy = newy;

 				if(oldx > game.actor_posx) { oldx--; }
 				semaphore.wait();
 				clear_jump(oldx-1, newy-1);
 				jump(oldx, newy, game.game_object_color);

 				semaphore.signal();
 				
 				//sleep(0);
 				if(game.isclash()){
 					//sleep(200);
 					//game.clash(false);
 				}
 			}

 			game.setjump(false);
 			game.actor_posx = 5;
 			game.actor_posy = 16;
 		}

 		//buzzer.set(rate);
 		//buzzer.sleep();
 		sleep(rate);

 		semaphore.wait();
 		//if(!game.color == game.color_red)
 		//game.color = game.color_black;
 		clear_jump(game.actor_posx, newy);
 		clear_move_2(oldx, game.actor_posy);
 		//if(!game.color == game.color_red)
		//game.color = game.color_cyan;
		move_1(game.actor_posx, game.actor_posy, game.game_object_color);
		//oldx =x;
		//x = x + advance;
		semaphore.signal();
		

		//buzzer.set(rate);
 		//buzzer.sleep();

		sleep(rate);

 		semaphore.wait();
 		//if(!game.color == game.color_red)
 		//game.color = game.color_black;
		clear_move_1(oldx, game.actor_posy);
		//if(!game.color == game.color_red)
		//game.color = game.color_cyan;
		move_2(game.actor_posx, game.actor_posy, game.game_object_color);
		//oldx =x;
		//x = x + advance;
		semaphore.signal();

		/*if(x < -15) {
			x = 62;
			semaphore.wait();
			clear_flydown(oldx, y);
			semaphore.signal();

			buzzer.set(frequency);
 			buzzer.sleep();
		}*/
		
	}
 }
