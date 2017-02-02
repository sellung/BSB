#include "usergame/actor.h"
#include "device/cgastr.h"
#include "syscall/guarded_semaphore.h"

#include "usergame/game.h"

void Actor::move_1(int x, int y){
	kout.setpos(x,y);
	kout.print("  //     ", width, game.color); kout.setpos(x,y+1);	  
	kout.print("  \\\\_  ", width, game.color); kout.setpos(x,y+2);	  
	kout.print("  ( o_>  ", width, game.color); kout.setpos(x,y+3);	  
	kout.print("  /:\\__ ", width, game.color); kout.setpos(x,y+4);	  
	kout.print(" /:_/`\"`", width, game.color); kout.setpos(x,y+5); 	             
	kout.print("@\\/\\)  ", width, game.color); kout.setpos(x,y+6);	     
	kout.print("  \" \"  ", width, game.color);	  
 }

void Actor::clear_move_1(int x, int y){
	move_1(x, y);
 } 
      
void Actor::move_2(int x, int y){      
	kout.setpos(x,y);
	kout.print("  //     ", width, game.color); kout.setpos(x,y+1);	  	  
	kout.print("  \\\\_    ", width, game.color); kout.setpos(x,y+2);	  
	kout.print("  ( o_>  ", width, game.color); kout.setpos(x,y+3);	  
	kout.print("  /:\\__ ", width, game.color); kout.setpos(x,y+4);	  
	kout.print(" /:_/`\"`", width, game.color); kout.setpos(x,y+5);	             
	kout.print("@\\)     ", width, game.color); kout.setpos(x,y+6);	  
	kout.print(" \"      ", width, game.color);	                 
}

void Actor::clear_move_2(int x, int y){      
	move_2(x, y);
}
      

void Actor::jump(int x, int y){      
	kout.setpos(x,y);      
	kout.print(" \\\\    ", width, game.color); kout.setpos(x,y+1);
	kout.print("  \\\\_  ", width, game.color); kout.setpos(x,y+2);
	kout.print("  ( o_>  ", width, game.color); kout.setpos(x,y+3);
	kout.print("  /:\\__ ", width, game.color); kout.setpos(x,y+4);
	kout.print(" /:_/`\"`", width, game.color); kout.setpos(x,y+5);
	kout.print("@\\/\\)  ", width, game.color); kout.setpos(x,y+6);	     
	kout.print("  \" \"  ", width, game.color);	     
}

void Actor::clear_jump(int x, int y){      
	 jump(x, y);
}

void Actor::action ()
 {
 	buzzer.set(1);
 	buzzer.sleep();

	game.actor_posx = 5; 
	game.actor_posy = 16;
	
	int oldx = game.actor_posx; int newy=game.actor_posy;
	//advance = 2;
 	while(1){
 		
 		if(game.getjump()){
 			semaphore.wait();
 			if(!game.color == game.color_red)
 			game.color = game.color_black;
 			clear_move_2(oldx, game.actor_posy);
 			clear_move_1(oldx, game.actor_posy);
 			newy = 5;
 			if(!game.color == game.color_red)
 			game.color = game.color_cyan;
 			jump(game.actor_posx, newy);
 			semaphore.signal();
 			buzzer.set(25);
 			buzzer.sleep();
 			game.setjump(false);
 		}

 		buzzer.set(rate);
 		buzzer.sleep();

 		semaphore.wait();
 		if(!game.color == game.color_red)
 		game.color = game.color_black;
 		clear_jump(game.actor_posx, newy);
 		clear_move_2(oldx, game.actor_posy);
 		if(!game.color == game.color_red)
		game.color = game.color_cyan;
		move_1(game.actor_posx, game.actor_posy);
		//oldx =x;
		//x = x + advance;
		semaphore.signal();
		

		buzzer.set(rate);
 		buzzer.sleep();

 		semaphore.wait();
 		if(!game.color == game.color_red)
 		game.color = game.color_black;
		clear_move_1(oldx, game.actor_posy);
		if(!game.color == game.color_red)
		game.color = game.color_cyan;
		move_2(game.actor_posx, game.actor_posy);
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
