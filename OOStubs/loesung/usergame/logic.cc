#include "usergame/logic.h"
#include "device/cgastr.h"
#include "syscall/guarded_semaphore.h"

#include "usergame/game.h"
#include "syscall/guarded_organizer.h"

#include "device/watch.h"

void Logic::show_digit(int to_show, int col, int row){
	int high_col = 1;
	if(to_show < 10){
		high_col = 1;
	}else if(to_show < 100){
		high_col = 2;
	}else if(to_show < 1000){
		high_col = 3;
	}else if(to_show < 10000){
		high_col = 4;
	}

	for (int i = high_col; i > 0; i--)
	{
		char c = '0' + (to_show % 10);
		kout.show((col-1) + i, row, c, 0x0f);
		if(c == '9'){kout.show(col + i, row, ' ', 0x0f);}

		to_show = to_show /10;
	}
}


void Logic::action ()
 {	
 	int counter = 0; 
 	buzzer.set(20);
 	buzzer.sleep();
 	while(1){

 		

 		semaphore.wait();
 		unsigned long int val;
 		val = counter/watch.interval();
		//show_digit(watch.interval(), 60, 2);

		kout.setpos(60, 2);
		kout << watch.interval() ;
		kout.flush();
		semaphore.signal();

		counter++;

	}
 }
