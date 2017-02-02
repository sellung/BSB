#include "usergame/bird.h"
#include "device/cgastr.h"
#include "guard/secure.h"
#include "device/watch.h"
#include "syscall/guarded_semaphore.h"

#include "usergame/game.h"

void fly(int direction, int x, int y){
	//flyup(x,y);

	//flydown(x+1,y);
}

void Bird::flyup(int x, int y, char color){
	//if(x < 0 || x > 79){ x = 0; }
	//if(y < 0 || y > 24){ y = 0;}
	kout.setpos(x, y-2);
	kout.print("   /''\\ /'''')", width, color); kout.setpos(x, y-1);     
	kout.print("   \\   /    / ", width, color); kout.setpos(x, y);           
	kout.print("  _/       /_  ", width, color); kout.setpos(x, y+1);                                                                               
	kout.print("<o _...,,.../  ", width, color);

}
void Bird::flydown(int x, int y, char color){
	//if(x < 0 || x > 79){ x = 0; }
	//if(y < 0 || y > 24){ y = 0;}
	kout.setpos(x, y);
	kout.print("  _         _  ", width, color); kout.setpos(x, y+1);
	kout.print("<o_````````./  ", width, color); kout.setpos(x, y+2);           
	kout.print("   \\,  \\   ) ", width, color); kout.setpos(x, y+3);                               
	kout.print("    \\,,/\\ ,_)", width, color); kout.setpos(x, y+4);                      
	kout.print("          \\,,/", width, color); 
}

void Bird::clear_flyup(int x, int y){
	flyup(x, y, 0x0);
}
void Bird::clear_flydown(int x, int y){
	flydown(x, y, 0x0);
}

 void Bird::action ()
 {
 	buzzer.set(1);
 	buzzer.sleep();

	int x = 79; int y = 17;
	int oldx = x;
	//advance = 2;
 	while(1){
		
		
		
 		buzzer.set(rate);
 		buzzer.sleep();

 		semaphore.wait();
 		clear_flydown(oldx, y);
		flyup(x, y, 0x3);
		semaphore.signal();
		
		if((x >= game.actor_posx && x <= game.actor_posx + 8)
			//|| (x < game.actor_posx && x + width+advance > game.actor_posx)
			)
		{
			semaphore.wait();
			kout.setpos(60, 24);
			kout << "x = "<< x << " game x = " << game.actor_posx +8 ;
			kout.flush();
			semaphore.signal();
			// Prüfe die Y Position
			game.color = game.color_red;
			buzzer.set(500);
			buzzer.sleep();
		}
		
		oldx =x;
		x = x-advance;
		

		buzzer.set(rate);
 		buzzer.sleep();

 		semaphore.wait();
		clear_flyup(oldx, y);
		flydown(x, y, 0x3);
		semaphore.signal();
		
		if((x >= game.actor_posx && x <= game.actor_posx + 8)
			//|| (x < game.actor_posx && x + width+advance > game.actor_posx)
			)
		{
			semaphore.wait();
			kout.setpos(60, 24);
			kout << "x = "<< x << " game x = " << game.actor_posx +8 ;
			kout.flush();
			semaphore.signal();
			// Prüfe die Y Position
			game.color = game.color_red;
			buzzer.set(500);
			buzzer.sleep();
		}
		oldx =x;
		x = x - advance;
		//semaphore.signal();

		if(x < -15) {
			x = 79;
			semaphore.wait();
			clear_flydown(oldx, y);
			semaphore.signal();

			buzzer.set(frequency);
 			buzzer.sleep();
		}
		
	}
 }
