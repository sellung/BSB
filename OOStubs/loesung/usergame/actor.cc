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
	kout.print("@\\/\\)  ", width, color); kout.setpos(x,y+6);	     
	kout.print("  \" \"  ", width, color);	  
 }

void Actor::clear_move_1(int x, int y){
	move_1(x, y, color_black);
 } 
      
void Actor::move_2(int x, int y, char color){      
	kout.setpos(x,y);
	kout.print("  //     ", width, color); kout.setpos(x,y+1);	  	  
	kout.print("  \\\\_    ", width, color); kout.setpos(x,y+2);	  
	kout.print("  ( o_>  ", width, color); kout.setpos(x,y+3);	  
	kout.print("  /:\\__ ", width, color); kout.setpos(x,y+4);	  
	kout.print(" /:_/`\"`", width, color); kout.setpos(x,y+5);	             
	kout.print("@\\)     ", width, color); kout.setpos(x,y+6);	  
	kout.print(" \"      ", width, color);	                 
}

void Actor::clear_move_2(int x, int y){      
	move_2(x, y, color_black);
}
      

void Actor::jump(int x, int y, char color){      
	kout.setpos(x,y);      
	kout.print(" \\\\    ", width, color); kout.setpos(x,y+1);
	kout.print("  \\\\_  ", width, color); kout.setpos(x,y+2);
	kout.print("  ( o_>  ", width, color); kout.setpos(x,y+3);
	kout.print("  /:\\__ ", width, color); kout.setpos(x,y+4);
	kout.print(" /:_/`\"`", width, color); kout.setpos(x,y+5);
	kout.print("@\\/\\)  ", width, color); kout.setpos(x,y+6);	     
	kout.print("  \" \"  ", width, color);	     
}

void Actor::clear_jump(int x, int y){      
	 jump(x, y, color_black);
}

void Actor::action ()
 {
 	buzzer.set(1);
 	buzzer.sleep();

	int x = 5; int y = 16;
	int oldx = x; int newy=y;
	//advance = 2;
 	while(1){
 		
 		if(game.getjump()){
 			semaphore.wait();
 			clear_move_2(oldx, y);
 			clear_move_1(oldx, y);
 			newy = 5;
 			jump(x, newy, 0x3);
 			semaphore.signal();

 			buzzer.set(25);
 			buzzer.sleep();
 			game.setjump(false);
 		}

 		buzzer.set(rate);
 		buzzer.sleep();

 		semaphore.wait();
 		clear_jump(x, newy);
 		clear_move_2(oldx, y);
		move_1(x, y, 0x3);
		//oldx =x;
		//x = x + advance;
		semaphore.signal();
		

		buzzer.set(rate);
 		buzzer.sleep();

 		semaphore.wait();
		clear_move_1(oldx, y);
		move_2(x, y, 0x3);
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