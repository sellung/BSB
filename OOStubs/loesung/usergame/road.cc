#include "usergame/road.h"
#include "device/cgastr.h"
#include "syscall/guarded_semaphore.h"

void Road::draw_road(int x, int y, char color){
	kout.setpos(x, y);
	//kout.print("________________________________________________________________________________", width, color);
	//kout.print("______________0_________________1______________________2________________________", 79, color);
	//kout.print("______________-_______________________~~,_________________/\\ __________________", 79, color); kout.setpos(x, y+2); 
	kout.setpos(x, y+4); 
	kout.print(".   -     '   .      -        _             .          -   '   .   -   '       '", 79, color);
	 //kout.setpos(x, y+3); 
	//kout.print("--------------------------------------------------------------------------------", 79, color); kout.setpos(x, y+4); 
	//kout.print("                                                                               ", 79, color); //kout.setpos(x, y+2); 
}
void Road::clear_road(int x, int y){
	draw_road(x, y, 0x0);
}

 void Road::action ()
 {
 	sleep(1);

	int x = 0; int y = 19;
	int x2 = 7;
	int oldx = x;
	//advance = 2;
 	while(1){

 		sleep(rate);

 		semaphore.wait();
 		//clear_road(oldx, y);
		draw_road(x, y, 0x3);
		oldx =x;
		x = x-advance;
		if(x % 70 == 0) {
			x = 0;
		}
		semaphore.signal();
		
		//buzzer.set(rate);
 		//buzzer.sleep();

 		//semaphore.wait();
		//draw_road(x2, y, 0x3);
		//oldx =x;
		//x2 = x2-advance;
		//semaphore.signal();
		
		
		
	}
 }