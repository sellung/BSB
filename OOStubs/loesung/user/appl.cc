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
//#include "syscall/guarded_scheduler.h"
#include "syscall/guarded_organizer.h"

#include "guard/secure.h"
#include "device/watch.h"
//#include "guard/guard.h"

/* Hier muesst ihr selbst Code vervollstaendigen *         
#include "device/keyboard.h"
#include "machine/cpu.h"
#include "guard/secure.h"
/* GLOBALE VARIABLEN */

void Application::action ()
 {
 	
 	int i = 0;
 	while(1){
		Secure secure;
		kout.setcolor(color);
		kout.setpos(col, row);
		kout << getName() << ".i = " << i;
		kout.flush();
		kout.resetcolor();
		if(i==10000 && id ==1 ){
			scheduler.Scheduler::exit();
		};
		i++;
		//scheduler.resume();
	}
 }
 
 void EmptyApp::action ()
 {
 	
 	count_interrupt = 0;
 	int col = 1; int row = 23;
	kout.setpos(col, row);
	kout << "AUFGABE STARTET IN " ;
	kout.flush();
 	while(1){
		unsigned long int val;
		val = count_interrupt/watch.interval();
		watch.show_digit(val, col+19, row);
	}
 }
