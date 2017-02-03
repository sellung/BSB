#include "usergame/cactus.h"
#include "device/cgastr.h"
#include "guard/secure.h"
#include "device/watch.h"
#include "syscall/guarded_semaphore.h"

void Cactus::cactus1(int x, int y, char color){
	int yy = y;
	kout.setpos(x,y);	
	kout.print("  _  _    ", width, 0x3); kout.setpos(x,y);	  
	kout.print(" || | | _ ", width, 0x3); kout.setpos(x,y+1);	  
	kout.print("-||_| |||-", width, 0x3); kout.setpos(x,y+2);	  
	kout.print("  \\_  ||| ", width, 0x3); kout.setpos(x,y+3);	  
	kout.print("    |  _/ ", width, 0x3); kout.setpos(x,y+4);	  
	kout.print("   -| |   ", width, 0x3); kout.setpos(x,y+5);	  
	kout.print("    \"\"\"-  ", width, 0x3); 
}
void Cactus::cactus2(int x, int y, char color){

}
void Cactus::cactus3(int x, int y, char color){

}
void Cactus::cactus4(int x, int y, char color){

}

void Cactus::clear_cactus1(int x, int y){
	cactus1(x, y, 0x0);
}
void Cactus::clear_cactus2(int x, int y){
	cactus2(x, y, 0x0);
}
void Cactus::clear_cactus3(int x, int y){
	cactus3(x, y, 0x0);
}
void Cactus::clear_cactus4(int x, int y){
	cactus4(x, y, 0x0);
}

void Cactus::action ()
 {
 	sleep(1);

	int x = 62; int y = 17;
	int oldx = x;
	//advance = 2;
 	while(1){
 		
 		sleep(rate);

 		semaphore.wait();
 		//clear_cactus1(oldx, y);
		cactus1(x, y, 0x3);
		oldx =x;
		x = x-advance;
		semaphore.signal();
		
		sleep(rate);

 		semaphore.wait();
		clear_cactus1(oldx, y);
		semaphore.signal();
		/*
		if(x < -15) {
			x = 62;
			semaphore.wait();
			clear_flydown(oldx, y);
			semaphore.signal();

			buzzer.set(frequency);
 			buzzer.sleep();
		}*/
		
	}
 }