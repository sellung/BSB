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

//#include "guard/guard.h"

/* Hier muesst ihr selbst Code vervollstaendigen *         

#include "machine/cpu.h"
#include "guard/secure.h"
/* GLOBALE VARIABLEN */

#include "syscall/guarded_keyboard.h"

void Application::action ()
 {
	//Secure secure;
 	buzzer.set(5);
	buzzer.sleep();
	
 	int i = 0;
 	
		
 	while(1){
		//Secure secure;
		kout.setcolor(color);
		kout.setpos(col, row);
		kout << getName() << ".i = " << i;
		kout.flush();
		kout.resetcolor();
		if(i==10000 && id ==1 ){
			scheduler.exit();
		};
		i++;
	}
 }
 
 void EmptyApp::action ()
 {
 	
 	count_interrupt = 0;
 	int col = 1; int row = 24;
	kout.setpos(col, row);
	kout << "TIME: " ;
	kout.flush();
 	while(1){
		Secure secure;
		
		unsigned long int val;
		val = count_interrupt/watch.interval();
		watch.show_digit(val, col+6, row);
		//scheduler.Scheduler::resume();
	}
 }

 void Keyboard_App::action ()
 {
 	while(1){
		Secure secure;
		
			key = guarded_keyboard.Keyboard::getkey();
		
			//guarded_keyboard.Scheduler::resume();	
		
 		//kout << "keyboard app" << endl;
 		
		/*count ++;
		kout.setpos(40, 9);
		kout << "Keyboard hit " << count;
		kout.flush();
		count ++;*/

		kout.setcolor(0x03);
		kout.setpos(10, 10);
	    kout << key.ascii() ;
	    kout.flush();
	    kout.resetcolor();
	    
 	}
 }
