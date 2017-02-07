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
	int x = 26; int y = 8;
 	while(1){
		 if(game.isjump() && game.game_status== START){
			 game.day();

			 while(y <= 16){
				
			 }
			 while()
			 game.game_status= ON;
			 game.setjump(false);
			 game.start_game();
		 }
		switch(game.game_status){
			case ON: 
				//semaphore.wait();
				unsigned long int val;
				val = count_interrupt/(watch.interval()*20);
				show_digit(val, col, row);
				//semaphore.signal();

				//count_interrupt ++;

				//scheduler.Scheduler::resume();
				//semaphore.signal();
				break;
			case START:
				//instruction(26, 5, game.game_object_clear_color);
				break;     

		}
		scheduler.resume();
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



void Start::game_logo1(int x, int y, char color){      
		int offset = 10;
		int width = 9;
		kout.setpos(x,y);
		kout.print("  //     ", width, color); kout.setpos(x,y+1);	  
		kout.print("  \\\\_  ", width, color); kout.setpos(x,y+2);	  
		kout.print("  ( o_>  ", width, color); kout.setpos(x,y+3);	  
		kout.print("  /:\\__ ", width, color); kout.setpos(x,y+4);	  
		kout.print(" /:_/`\"`", width, color); kout.setpos(x,y+5); 	             
		kout.print("@\\/\\)  ", width, color); kout.setpos(x,y+6);	     
		kout.print("  \" \"    ", width, color);
}

void Start::game_logo2(int x, int y, char color){      
	kout.setpos(x,y);
	int width = 9;
	kout.print("  //     ", width, color); kout.setpos(x,y+1);	  	  
	kout.print("  \\\\_    ", width, color); kout.setpos(x,y+2);	  
	kout.print("  ( o_>  ", width, color); kout.setpos(x,y+3);	  
	kout.print("  /:\\__ ", width, color); kout.setpos(x,y+4);	  
	kout.print(" /:_/`\"`", width, color); kout.setpos(x,y+5);	             
	kout.print("@\\)     ", width, color); kout.setpos(x,y+6);	  
	kout.print(" \"      ", width, color);	                 
}

void Start::instruction(int x, int y, char color){
		kout.setpos(x,y);
		kout.setcolor(color);	  
		kout << "WELCOME TO THE GAME " ;
		kout.flush(); kout.setpos(x,y+1);
		kout << "------------------- " ;
		kout.flush(); kout.setpos(x,y+2);  
		kout << "    Intruction      "    ;
		kout.flush(); kout.setpos(x,y+3);
		kout << "------------------- " ;
		kout.flush(); kout.setpos(x,y+4); 
		kout << "PRESS SPACE to START ";
		kout.flush(); kout.setpos(x,y+5);
		kout << "Press SPACE to JUMP " ;
		kout.flush(); kout.setpos(x,y+6);
		kout << "Press ENTER to PAUSE " ;
		kout.flush(); kout.setpos(x,y+7);
		kout << "------------------- "  ;//kout.setpos(x+10,y+8;
		kout.flush();  
		kout.resetcolor();            
	}

void Start::clear_game_logo1(int x, int y, char color){
	game_logo1(x,y,game.game_object_clear_color);
}
void Start::clear_game_logo2(int x, int y, char color){
	game_logo2(x,y,game.game_object_clear_color);
}
void Start::clear_instruction(int x, int y, char color){
	instruction(x,y,game.game_object_clear_color);
}

 void Start::action ()
 {
	//Secure secure;
 	buzzer.set(1);
	buzzer.sleep();
	int blink = 5;	

	int x = 0;
	int y = 8;
	//instruction(24, 8, game.game_object_color);
 	while(1){
		//Secure secure;
		semaphore.wait();
		kout.clearscreen();
		kout.startMsg();
		semaphore.signal();

		buzzer.set(100);
		buzzer.sleep();	
		
		while(blink > 0){
			blink--;
			semaphore.wait();
			kout.startMsg();
			semaphore.signal();

			buzzer.set(20);
			buzzer.sleep();	
			semaphore.wait();
			kout.clearscreen();
			//game.day();
			semaphore.signal();

			buzzer.set(20);
			buzzer.sleep();
		}

		semaphore.wait();
		game.day();
		semaphore.signal();

		int oldx = x;
		while(x <= 25){
			semaphore.wait();

			if(x % 2 == 0){
				clear_game_logo2(oldx, y, game.game_object_clear_color);
				game_logo2(x,y, game.game_object_color);
			}else{
				clear_game_logo1(oldx, y, game.game_object_clear_color);
				game_logo1(x,y, game.game_object_color);
			}
			
			instruction(60-x, y, game.game_object_color);
			semaphore.signal();
			oldx = x;
			x += 1;

			buzzer.set(5);
			buzzer.sleep();
		}

		game.game_status = game.START;
		game.setjump(false);
		scheduler.exit();
	}
 }
 
