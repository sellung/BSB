/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "device/watch.h"
#include "device/cgastr.h"
//#include "syscall/guarded_scheduler.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "syscall/guarded_organizer.h"
#include "meeting/bellringer.h"

//Plugbox plugbox;
//PIC pic;

int count_interrupt = 0;
bool wait_guardiant_PIT = false;

void Watch::windup (){
	plugbox.assign(Plugbox::timer, *this);
	pic.allow(PIC::timer);
}

bool Watch::prologue (){
	return true;
}

void Watch::epilogue (){
	//kout << "epilogue" <<endl;
	scheduler.Scheduler::resume();
	
	if(count_interrupt % interval() == 0){
		bellringer.check();
		//kout << "epilogue" <<endl;
	}
	//count_interrupt++;
	//bellringer.check();
}

char* Watch::tostring(){
	return "Ich bin Timer";
}

void Watch::trigger (){
	
}

void Watch::sleep(int delay){
	wait_guardiant_PIT = true; 
	count_interrupt = 0;
	const unsigned long int TICK_SECOND = interval();
	const unsigned long int wait_tick = TICK_SECOND * delay;
	int col = 1; int row = 23;
	kout.setpos(col, row);
	kout << "AUFGABE STARTET IN " ;
	kout.flush();
	unsigned long int val;
	while(wait_tick - count_interrupt > 0){
		val = (wait_tick - count_interrupt)/interval();
		show_digit(val, col+19, row);
	}
	count_interrupt = 0;
	wait_guardiant_PIT = false;
}

void Watch::time(){
	count_interrupt = 0;
	int col = 1; int row = 23;
	kout.setpos(col, row);
	kout << "AUFGABE STARTET IN " ;
	kout.flush();
	unsigned long int val;
	while(1){
		val = count_interrupt/interval();
		show_digit(val, col+19, row);
	}
	count_interrupt = 0;
}

void Watch::show_digit(int to_show, int col, int row){
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
