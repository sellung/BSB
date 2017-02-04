#include "usergame/cactus.h"
#include "device/cgastr.h"
#include "guard/secure.h"
#include "device/watch.h"
#include "syscall/guarded_semaphore.h"
#include "usergame/game.h"

void Cactus::cactus1(int x, int y, char color){
	kout.setpos(x,y);	
	kout.print("  _  _    ", width, color); kout.setpos(x,y+1);	  
	kout.print(" || | | _ ", width, color); kout.setpos(x,y+2);	  
	kout.print("-||_| |||- ", width, color); kout.setpos(x,y+3);	  
	kout.print("  \\_  ||| ", width, color); kout.setpos(x,y+4);	  
	kout.print("   |  _/  ", width, color); kout.setpos(x,y+5);	  
	kout.print("---| |----", width, color); kout.setpos(x,y+6);	  
	kout.print("  `\"\"\"`-   ", width, color); 
}
void Cactus::cactus2(int x, int y, char color){
	//int yy = y;
	//x = x - 20;
	int width = 18;
	kout.setpos(x,y);
	kout.print("       ,/\\ ,        ", width, color); kout.setpos(x,y+1);	              
	kout.print("  ,/\\(,_||_)/\\     ", width, color); kout.setpos(x,y+2);	          
	kout.print("((_||_)),,, || ,     ", width, color); kout.setpos(x,y+3);	          
	kout.print("`--,,--`|((_||_))    ", width, color); kout.setpos(x,y+4);	          
	kout.print("   ||   |`--,,--`    ", width, color); kout.setpos(x,y+5);	          
	kout.print("---||--`\"\"`-||-----", width, color); kout.setpos(x,y+6);	          
	kout.print("..`\"\"`.`. ` ||     ", width, color); kout.setpos(x,y+7);	          
	kout.print("''.   -  . `\"\"`    ", width, color);     
}
void Cactus::cactus3(int x, int y, char color){
	//x = x - 30;
	//y = y-1;
	int width = 9;
	kout.setpos(x,y);
	kout.print(" , /\\ , ", width, color); kout.setpos(x,y+1);	  
	kout.print("((_||_)) ", width, color); kout.setpos(x,y+2);	  
	kout.print("`--,,--` ", width, color); kout.setpos(x,y+3);	  
	kout.print("   ||    ", width, color); kout.setpos(x,y+4);	  
	kout.print("   ||    ", width, color); kout.setpos(x,y+5);	  
	kout.print("--`\"\"`-----", width, color); 	  
}
void Cactus::cactus4(int x, int y, char color){
	//x = x - 40;
	int width = 16;
	kout.setpos(x,y);
	kout.print("        _   _  ", width, color); kout.setpos(x,y+1);	  
	kout.print("      -| |  || ", width, color); kout.setpos(x,y+2);	  
	kout.print("   _-  | ||/ | ", width, color); kout.setpos(x,y+3);	  
	kout.print(" -||   | |__/  ", width, color); kout.setpos(x,y+4);	  
	kout.print("  |\\__|| |     ", width, color); kout.setpos(x,y+5);	  
	kout.print("--\\____  |-----", width, color); kout.setpos(x,y+6);	  
	kout.print("   |   | |-    ", width, color); kout.setpos(x,y+7);	  
	kout.print("      -\"\"\"     ", width, color);
}

void Cactus::flyup(int x, int y, char color){
	//if(x < 0 || x > 79){ x = 0; }
	//if(y < 0 || y > 24){ y = 0;}
	int width = 16;
	kout.setpos(x, y-2);
	kout.print("   /''\\ /'''') ", width, color); kout.setpos(x, y-1);     
	kout.print("   \\   /    /  ", width, color); kout.setpos(x, y);           
	kout.print("  _/       /_  ", width, color); kout.setpos(x, y+1);                                                                               
	kout.print("<o _...,,.../  ", width, color);
	kout.setpos(x,21);
	//kout.print(".    -    `  , ", width, color);kout.setpos(x,y+5);
	kout.print("----------------", width, game.game_object_color);
	kout.setpos(70,21);

}
void Cactus::flydown(int x, int y, char color){
	//if(x < 0 || x > 79){ x = 0; }
	//if(y < 0 || y > 24){ y = 0;}
	int width = 16;
	kout.setpos(x, y);
	kout.print("  _         _  ", width, color); kout.setpos(x, y+1);
	kout.print("<o_````````./  ", width, color); kout.setpos(x, y+2);           
	kout.print("   \\,  \\   )   ", width, color); kout.setpos(x, y+3);                               
	kout.print("    \\,,/\\ ,_)  ", width, color); kout.setpos(x, y+4);                      
	kout.print("          \\,,/  ", width, color); 
	//kout.setpos(x,y+4);
	//kout.print(".    -    `  , ", width, color);
	//kout.setpos(x,y+5);
	kout.setpos(x,21);
	kout.print("-----------------", width, game.game_object_color);
	kout.setpos(70,21);
}

void Cactus::sun(int x, int y, char color){
	int width =11 ;
	kout.setpos(x,y);
	kout.print("     .     ", width, color); kout.setpos(x,y+1);
	kout.print("   \\ | /  ", width, color); kout.setpos(x,y+2);
	kout.print(" '-.;;;.-' ", width, color); kout.setpos(x,y+3);
	kout.print("-==;;;;;==-", width, color); kout.setpos(x,y+4);
	kout.print(" .-';;;'-. ", width, color); kout.setpos(x,y+5);
	kout.print("   / | \\  ", width, color); kout.setpos(x,y+6);
	kout.print("     '     ", width, color); kout.setpos(x,y+7);
}

void Cactus::cloud1(int x, int y, char color){
	int width = 12;
	kout.setpos(x,y);
	kout.print("   _   _   ", width, color); kout.setpos(x,y+1);
	kout.print(" _( )_( )_ ", width, color); kout.setpos(x,y+2);
	kout.print("(_________)", width, color); 
}
void Cactus::cloud2(int x, int y, char color){
	int width = 12;
	kout.setpos(x,y);
	kout.print("   ___     ", width, color); kout.setpos(x,y+1);
	kout.print(" _(   )___ ", width, color); kout.setpos(x,y+2);
	kout.print("(_________)", width, color); 
}

void Cactus::clear_cloud1(int x, int y){
	cloud1(x, y,  game.game_object_clear_color);
}
void Cactus::clear_cloud2(int x, int y){
	cloud2(x, y,  game.game_object_clear_color);
}

void Cactus::clear_flyup(int x, int y){
	flyup(x, y,  game.game_object_clear_color);
}
void Cactus::clear_flydown(int x, int y){
	flydown(x, y,  game.game_object_clear_color);
}

void Cactus::clear_cactus1(int x, int y){
	cactus1(x, y,  game.game_object_clear_color);
}
void Cactus::clear_cactus2(int x, int y){
	cactus2(x, y,  game.game_object_clear_color);
}
void Cactus::clear_cactus3(int x, int y){
	cactus3(x, y,  game.game_object_clear_color);
}
void Cactus::clear_cactus4(int x, int y){
	cactus4(x, y,  game.game_object_clear_color);
}

void Cactus::action ()
 {
 	sleep(1);

	int x = 69; int y = 16;
	int oldx = x;

	int birdx = 62; int birdy = 16;
	int birdoldx = birdx;
	//advance = 2;

	int cloudx = 67; int cloudy=12;
	int cloudoldx;

	int sunx = 67; int suny=6;
	semaphore.wait();
	sun(sunx, suny, 0x7e);
	semaphore.signal();
	
	int cloud_bird_distance = 10;
	int day = 1;

 	while(1){
 		
 		//sleep(rate);

		semaphore.wait();
		kout.setpos(0,y+5);
		kout.print("-----", 5, game.game_object_color);
		kout.setpos(11,y+5); 
		kout.print("--------------------------------------------------------------------", 68, game.game_object_color); 
		//kout.setpos(11,y+5);
		//kout.print("--------------------------------------------------------------------", 68, 0x3);

		cactus1(x, y, game.game_object_color);
		collision(x,y, cactus1_w, cactus1_h);

		if(x+20 + 12 < 80){
			cloud1(x+20,cloudy, 0x78);
		}
		if(x+40 + 16 < 80){
			cactus2(x+40, y, game.game_object_color);
			collision(x+40, y, cactus2_w, cactus2_h);
		}

		if(x+60 + 12 < 80){
			cloud2(x+60,cloudy, 0x78);
		}

		if(x+40+50 + 9 < 80){
			cactus3(x+40+50, y, game.game_object_color);
			collision(x+40+50, y,cactus3_w, cactus3_h);
		}

		if(x+40+50+20 + 12 < 80){
			cloud1(x+40+50+20,cloudy, 0x78);
		}
		if(x+40+50 + 50 + 16 < 80){
			//clear_cactus4(oldx+40+50 + 50, y);
			cactus4(x+40+50 + 50, y, game.game_object_color);
			//cloud2(x+40+50 + 50-25, cloudy, 0x8);
			collision(x+40+50+50, y, cactus4_w, cactus4_h);
		}

		oldx =x;
		x = x-advance;

		semaphore.signal();
		
		if(x <= -154){
			//birdy = flyhigh? 10 : birdy;
			if(flyhigh){
				birdy = 10;
				sun(sunx, suny, 0x7e);
			}else{
				birdy = 16;
			}
			semaphore.wait();
			clear_cloud1(cloudoldx-10, cloudy);
			cloud1(cloudx-10,cloudy, 0x7f);

			if(cloud_bird_distance <= 0){
				clear_flydown(birdoldx, birdy);
				flyup(birdx, birdy, game.game_object_color);
				collision(birdx, birdy, bird_w, bird_h);
				birdoldx = birdx;
				birdx = birdx-advance*4;
				//cloudoldx = birdoldx;
				//cloudx = birdx;
			} else{
				cloud_bird_distance--;
			}
		
			cloudoldx = cloudx;
			cloudx = cloudx-advance*3;

			semaphore.signal();

			sleep(rate*2);

			semaphore.wait();

			clear_cloud1(cloudoldx-10, cloudy);
			cloud1(cloudx-10,cloudy, 0x78);
			
			if(cloud_bird_distance <= 0){
				clear_flyup(birdoldx, birdy);
				flydown(birdx, birdy, game.game_object_color);
				collision(birdx, birdy, bird_w, bird_h);

				birdoldx = birdx;
				birdx = birdx-advance*4;
				//cloudoldx = birdoldx;
				//cloudx = birdx;
			}else{
				cloud_bird_distance--;
				//cloudoldx = cloudx;
				//cloudx = cloudx-advance*4;
			}
			cloudoldx = cloudx;
			cloudx = cloudx-advance*3;

			semaphore.signal();

			sleep(rate*2);
		}
		
		if(birdx <= -30){
			tooglefly();
			x = 69;
			birdx = 62;
			cloudx = 67;
			cloud_bird_distance = 10;
		}
		
		
		sleep(rate);
		
	}
 }