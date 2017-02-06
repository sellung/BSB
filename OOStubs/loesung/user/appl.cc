/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "thread/scheduler.h"
#include "syscall/guarded_organizer.h"

#include "guard/secure.h"
#include "device/watch.h"

#include "guard/gate.h"
#include "syscall/guarded_semaphore.h"

//#include "guard/guard.h"

/* Hier muesst ihr selbst Code vervollstaendigen *         

#include "machine/cpu.h"
#include "guard/secure.h"
/* GLOBALE VARIABLEN */

#include "syscall/guarded_keyboard.h"
#include "usergame/game.h"
void Application::action ()
 {
	//Secure secure;
 	buzzer.set(5);
	buzzer.sleep();
	
 	int i = 0;
 	
		
 	while(1){
		//Secure secure;
		semaphore.wait();
		kout.setcolor(color);
		kout.setpos(col, row);
		kout << getName() << ".i = " << i;
		kout.flush();
		kout.resetcolor();
		//if(i%10000==0 && id ==2 ){
		//	semaphore.signal();
			//scheduler.exit();
		//	buzzer.set(3);
		//	buzzer.sleep();
		//};
		i++;
		semaphore.signal();
	}
 }
 
 void EmptyApp::show_digit(int to_show, int col, int row){
 	
	int i = col + 5;
	do{
		char c = '0' + (to_show % 10);
		kout.show(i , row, c, game.game_object_color);
		i--;
		to_show = to_show / 10;
	}while(to_show  != 0);
}

 void EmptyApp::action ()
 {
 	
 	count_interrupt = 0;
 	int col = 70; int row = 2;
 	for(int i = 0; i <5 ; i++){
 		kout.show(col+i , row, '0', game.game_object_color);
 	}

 	while(1){
		
		//semaphore.wait();
		unsigned long int val;
		val = count_interrupt/(watch.interval()*12);
		show_digit(val, col, row);
		//semaphore.signal();

 		//count_interrupt ++;

		scheduler.resume();

		//scheduler.Scheduler::resume();
		//semaphore.signal();
	}
 }

 void Keyboard_App::action ()
 {
	// semaphore.wait();
 	while(1){
		key = keyboard.getkey();
		//semaphore.wait();
		if(key.ascii() == 32) { game.setjump(true);}
		//semaphore.signal();

		semaphore.wait();
		count ++;
		kout.setpos(40, 5);
		kout << "Keyboard hit " << count;
		kout.flush();
		//count ++;
		
		kout.setcolor(0x03);
		kout.setpos(10, 10);
	    kout << key.ascii() ;
	    kout.flush();
	    kout.resetcolor();
	    semaphore.signal();
 	}
 }
