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

void EmptyApp::show_digit(int to_show, int col, int row, int size){
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
	int j = 0;
	for(int j = col+high_col; j < col + size; j++){
		kout.show(j , row, '0', game.game_object_color);
	}
	int i = j;
	do{
		char c = '0' + (to_show % 10);
		kout.show(i , row, c, game.game_object_color);
		i--;
		to_show = to_show / 10;
	}while(to_show  != 0);
}

void EmptyApp::gameover(int x, int y, char color){
	
	kout.setpos(x,y);
	kout.setcolor(color);
	/*kout <<"  _____"; kout.flush(); kout.setpos(x,y+1);                                 
	kout <<" / ___/__ ___ _  ___   ___ _  _____ ____ "; kout.flush(); kout.setpos(x,y+2);                                 
	kout <<"/ (_ / _ `/  ' \/ -_) / _ \ |/ / -_) __/ "; kout.flush(); kout.setpos(x,y+3);                                 
	kout <<"\___/\_,_/_/_/_/\__/  \___/___/\__/_/    "; kout.flush(); kout.setpos(x,y+4);*/
	/*
	kout <<"  _____"; kout.flush(); kout.setpos(x,y+1);                                 
	kout <<" / ___/__ ___ _  ___   ___ _  _____ ____ "; kout.flush(); kout.setpos(x,y+2);                                 
	kout <<"/ (_ / _ `/  ' \/ -_) / _ \ |/ / -_) __/ "; kout.flush(); kout.setpos(x,y+3);                                 
	kout <<"\\___/\\_,_/_/_/_/\\__/  \\___/___/\\__/_/    "; kout.flush(); kout.setpos(x,y+4);*/
	
	kout <<"  _____                                                  "; kout.flush(); kout.setpos(x,y+1);                                 
	kout <<" / ____|                                                 "; kout.flush(); kout.setpos(x,y+2);                                 
	kout <<"| |  __  __ _ _ __ ___   ___    _____   _____ _ __       "; kout.flush(); kout.setpos(x,y+3);                                 
	kout <<"| | |_ |/ _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__| "; kout.flush(); kout.setpos(x,y+4);                                 
	kout <<"| |__| | (_| | | | | | |  __/ | (_) \\ \\V /  __/ |       "; kout.flush(); kout.setpos(x,y+5);                                 
	kout <<" \\_____|\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|    "; kout.flush(); kout.setpos(x,y+7);                                 
	kout <<"                            PRESS SPACE TO RESTART "; kout.flush(); kout.setpos(x,y+8);                                 
                                                
	kout.resetcolor();
}

 void EmptyApp::action ()
 {
 	
 	count_interrupt = 0;
 	int col = 70; int row = 2;
	int x = 26; int y = 8;

	int count = 0;
 	while(1){
		
		if(game.live <= 0){
			//game.day();
			game.game_status= OVER;
			game.end_game();
			gameover(10, 7, 0x70);
			game.live = game.maxlive;
			count_interrupt = 0;
			
			kout.setcolor(game.game_object_color);
			kout.setpos(60, row);
			kout << "HI 00000";
			kout.flush();
			show_digit(game.high_score, 62, row);
			kout.resetcolor();
		}
		if(game.isjump() && (game.game_status== START || game.game_status== OVER )){
			// game.day();
			if(game.game_status== OVER){
				game.game_status= game.RESTART;
				gameover(10, 7, 0x77);
				//game.day();
			}else{
				game.game_status= ON;
			}
			
			game.setjump(false);
			game.start_game();
			for(int i = 0; i <5 ; i++){
 				kout.show(col+i , row, '0', game.game_object_color);
 			}
			kout.setcolor(game.game_object_color);
			kout.setpos(5, row);
			kout << "LIVE: ";
			kout.flush();
			kout.resetcolor();

			watch.show_digit(game.live, 12, row);

			//show_digit(game.live, 16, row, 2);
		 }
		switch(game.game_status){
			case RESTART:
			case ON: 
				//semaphore.wait();
				//unsigned long int val;
				game.score = count_interrupt/(watch.interval()*17);
				//game.score
				game.high_score = game.score > game.high_score ? game.score : game.high_score;
				show_digit(game.score, col, row);

				//watch.show_digit(game.speed(), 12, row);

				//if(game.score >0 && game.score == 100) { 
					//int s = game.speed();
					//game.speed(--s);
				 count =  count_interrupt/(watch.interval()*1700);
				 //game.start_rate - count;
				 game.speed(game.start_rate - count);
				 
				 watch.show_digit(game.live, 12, row);
				//}
				//count++; 
			
				//show_digit(game.live, 16, row, 2);
				
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
		kout << "    Instructions      "    ;
		kout.flush(); kout.setpos(x,y+3);
		kout << "------------------- " ;
		kout.flush(); kout.setpos(x,y+4); 
		kout << "PRESS SPACE to START ";
		kout.flush(); kout.setpos(x,y+5);
		kout << "PRESS SPACE to JUMP " ;
		kout.flush(); kout.setpos(x,y+6);
		kout.resetcolor(); 
		kout.setcolor(0x78);     
		kout << "PRESS ENTER to PAUSE " ;
		kout.flush(); kout.setpos(x,y+7);
		kout << "------------------- "  ;//kout.setpos(x+10,y+8;
		kout.flush();  
		kout.resetcolor();            
	}

void Start::clear_game_logo1(int x, int y){
	game_logo1(x,y,game.game_object_clear_color);
}
void Start::clear_game_logo2(int x, int y){
	game_logo2(x,y,game.game_object_clear_color);
}
void Start::clear_instruction(int x, int y){
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
				clear_game_logo2(oldx, y);
				game_logo2(x,y, game.game_object_color);
			}else{
				clear_game_logo1(oldx, y);
				game_logo1(x,y, game.game_object_color);
			}
			
			
			instruction(60-x, y, game.game_object_color);
			semaphore.signal();
			oldx = x;
			x += 1;

			buzzer.set(5);
			buzzer.sleep();
		}
		game.game_start_sem.wait();
		game.day();
		 x = 25; y = 8;
		 oldx = x;
	      int pos = 7;
		  while(y <= 16){
				semaphore.wait();
				game_logo1(x, y, game.game_object_color);
				semaphore.signal();
				
				buzzer.set(10);
				buzzer.sleep();

				if(x>5){
					oldx = x;
					x -=3;
				}else{
					oldx = x;
					x = 5;
				}
				y += 1;

				semaphore.wait();
				clear_game_logo1(oldx, y-1);
				clear_game_logo1(x, y-1);
				semaphore.signal();

		}
	   	semaphore.wait();
		game_logo1(5, 16, game.game_object_color);
		semaphore.signal();
		
		buzzer.set(40);
		buzzer.sleep();

		game.game_status = game.START;
		scheduler.exit();
	}
 }
 
