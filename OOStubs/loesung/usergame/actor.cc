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

void Actor::stop(){
	/*if(game.isclash()) { 
		semaphore.wait(); 
		sleep(100);
		semaphore.signal();	
	}else { 
		//game.clash(false);
	}*/
}

void Actor::score(){
	semaphore.wait();
	kout.setpos(70, 2);
	kout << game.score ;
	kout.flush();
	semaphore.signal();
}
void Actor::high_score(){
	semaphore.wait();
	semaphore.signal();
}
void Actor::live(){
	semaphore.wait();
	semaphore.signal();
}

void Actor::action ()
 {
 	/*semaphore.wait();
 	kout.setpos(60, 2);
	kout << "00000" ;
	kout.flush();
	semaphore.signal();*/
 	
 	sleep(1);
 	game.score = 0;
	game.actor_posx = 5; 
	game.actor_posy = 16;
	
	int oldx = game.actor_posx; int newy=game.actor_posy;
	//score();
 	while(1){
 		//score();
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
 				stop();
 			}
 			
 			
 			int oldy = newy;
 			//semaphore.wait();
 			sleep(45);

 			while(newy < 16){
 				stop();
 				newy++;
 				game.actor_posy = newy;

 				if(oldx > game.actor_posx) { oldx--; }
 				semaphore.wait();
 				clear_jump(oldx-1, newy-1);
 				jump(oldx, newy, game.game_object_color);

 				semaphore.signal();
 			
 				//sleep(0);
 			}
 			

 			game.setjump(false);
 			game.actor_posx = 5;
 			game.actor_posy = 16;
 		}

 		sleep(rate);

 		semaphore.wait();
 		clear_jump(game.actor_posx, newy);
 		clear_move_2(oldx, game.actor_posy);
 		
		move_1(game.actor_posx, game.actor_posy, game.game_object_color);
	
		semaphore.signal();
		
		sleep(rate);

 		semaphore.wait();
		clear_move_1(oldx, game.actor_posy);
		move_2(game.actor_posx, game.actor_posy, game.game_object_color);
		semaphore.signal();
	}
 }
