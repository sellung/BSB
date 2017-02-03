#include "usergame/bird.h"
#include "device/cgastr.h"
#include "guard/secure.h"
#include "device/watch.h"
#include "syscall/guarded_semaphore.h"

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
 	sleep(1);

	game.bird_posx = 62; game.bird_posy = 17;
	int oldx = game.bird_posx;
	//advance = 2;
 	while(1){
 		sleep(rate);

 		semaphore.wait();
 		clear_flydown(oldx, game.bird_posy);
		flyup(game.bird_posx, game.bird_posy, 0x3);
		oldx = game.bird_posx;
		game.bird_posx = game.bird_posx-advance;
		semaphore.signal();
		
		sleep(rate);
		
 		semaphore.wait();
		clear_flyup(oldx, game.bird_posy);
		flydown(game.bird_posx, game.bird_posy, 0x3);
		oldx = game.bird_posx;
		game.bird_posx -=  advance;
		semaphore.signal();

		if(game.bird_posx < -15) {
			game.bird_posx = 62;
			semaphore.wait();
			clear_flydown(oldx, game.bird_posy);
			semaphore.signal();

 			sleep(frequency);
		}
	}
 }