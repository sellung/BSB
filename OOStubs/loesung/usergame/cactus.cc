#include "usergame/cactus.h"
#include "device/cgastr.h"
#include "guard/secure.h"
#include "device/watch.h"
#include "syscall/guarded_semaphore.h"
#include "usergame/game.h"

void Cactus::ground(int x, int y){
	kout.setpos(x, 22);
	kout.print(".   -   `     .     '      -      ,", 34, game.game_object_color);
}

void Cactus::cactus1(int x, int y, char color){
	kout.setpos(x,y);	
	kout.print("  _  _    ", width, color); kout.setpos(x,y+1);	  
	kout.print(" || | | _ ", width, color); kout.setpos(x,y+2);	  
	kout.print("-||_| |||- ", width, color); kout.setpos(x,y+3);	  
	kout.print("  \\_  ||| ", width, color); kout.setpos(x,y+4);	  
	kout.print("   |  _/  ", width, color); kout.setpos(x,y+5);	  
	kout.print("---| |----", width, color); kout.setpos(x,y+6);	  
	kout.print("  `\"\"\"`-   ", width, color); 

	ground(x, y);
	collision_with_actor(x, y, cactus1_w, cactus1_h);
}

void Cactus::cactus2(int x, int y, char color){
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

	ground(x, y);     
	collision_with_actor(x, y, cactus2_w, cactus2_h);
}
void Cactus::cactus3(int x, int y, char color){
	int width = 9;
	kout.setpos(x,y);
	kout.print(" , /\\ , ", width, color); kout.setpos(x,y+1);	  
	kout.print("((_||_)) ", width, color); kout.setpos(x,y+2);	  
	kout.print("`--,,--` ", width, color); kout.setpos(x,y+3);	  
	kout.print("   ||    ", width, color); kout.setpos(x,y+4);	  
	kout.print("   ||    ", width, color); kout.setpos(x,y+5);	  
	kout.print("--`\"\"`-----", width, color); 

	ground(x, y);
	collision_with_actor(x, y, cactus3_w, cactus3_h);	  
}
void Cactus::cactus4(int x, int y, char color){
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

	ground(x, y);
	collision_with_actor(x, y, cactus4_w, cactus4_h);
}

void Cactus::flyup(int x, int y, char color){
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

	ground(x, y);
	collision_with_actor(x, y, bird_w, bird_h);
}
void Cactus::flydown(int x, int y, char color){
	int width = 16;
	kout.setpos(x, y);
	kout.print("  _         _  ", width, color); kout.setpos(x, y+1);
	kout.print("<o_````````./  ", width, color); kout.setpos(x, y+2);           
	kout.print("   \\,  \\   )   ", width, color); kout.setpos(x, y+3);                               
	kout.print("    \\,,/\\ ,_)  ", width, color); kout.setpos(x, y+4);                      
	kout.print("          \\,,/  ", width, color); 
	
	kout.setpos(x,21);
	kout.print("-----------------", width, game.game_object_color);
	kout.setpos(70,21);

	ground(x, y);
	collision_with_actor(x, y, bird_w, bird_h);
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

	ground(x, y);
}
void Cactus::cloud2(int x, int y, char color){
	int width = 12;
	kout.setpos(x,y);
	kout.print("   ___     ", width, color); kout.setpos(x,y+1);
	kout.print(" _(   )___ ", width, color); kout.setpos(x,y+2);
	kout.print("(_________)", width, color); 

	ground(x, y);
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
	sun(sunx, suny, 0x7f);
	semaphore.signal();
	
	int cloud_bird_distance = 6;
	int day = 1;

	int d1 = 60;
	int d2 = 60;
	int d3 = 60;

	int cactus_time = x;
	int bird_time =x;

	int distance_to_godown = 1;
 	while(1){
		 if(game.is_actor_up() && distance_to_godown >= 27){
		//if(game.is_actor_up() ){
			// sleep(100);
			 game.godown();
			 distance_to_godown = 0;
		 }
 		//sleep(rate);
		semaphore.wait();
		kout.setpos(0,y+5);
		kout.print("-----", 5, game.game_object_color);
		kout.setpos(11,y+5); 
		kout.print("--------------------------------------------------------------------", 68, game.game_object_color); 
		kout.setpos(0,y+6);
		kout.print(".   '", 5, game.game_object_color);
		kout.setpos(11,y+6);
		kout.print("-   '   .     `     -     '      .     `     -     '      `      -  ", 68, game.game_object_color);

		//#### CACTUS 1 ####
		clear_cactus1(oldx,y);
		cactus1(x, y, game.game_object_color);
		//collision(x,y, cactus1_w, cactus1_h);

		//#### CLOUD 1 ####
		if(x + (d1/2) + 12 < 80){
			clear_cloud1(oldx + (d1/2),cloudy);
			cloud1(x + (d1/2),cloudy, 0x78);
		}

		//#### CACTUS 2 ####
		if(x + d1 + 16 < 80){
			clear_cactus2(oldx+d1,y);
			cactus2(x+d1, y, game.game_object_color);
			//collision(x+40, y, cactus2_w, cactus2_h);
		}

		//#### CLOUD 2 ####
		if(x + (d1/2) + d1 + 12 < 80){
			clear_cloud2(oldx + (d1/2) + d1,cloudy);
			cloud2(x + (d1/2) + d1,cloudy, 0x78);
		}

		//#### CACTUS 3 ####
		if(x + d1 + d2 + 9 < 80){
			clear_cactus3(oldx + d1+ d2,y);
			cactus3(x + d1+ d2, y, game.game_object_color);
			//collision(x+40+50, y,cactus3_w, cactus3_h);
		}
		
		//#### CLOUD 1 ####
		if(x + (d1/2) + d1 + d1 + 12 < 80){
			clear_cloud1(oldx + + (d1/2) + d1 + d1,cloudy);
			cloud1(x + (d1/2) + d1 + d1,cloudy, 0x78);
		}

		//#### CACTUS 4 ####
		if(x + d1 + d2 + d3 + 16 < 80){
			clear_cactus4(oldx + d1 + d2 + d3,y);
			cactus4(x + d1 + d2 + d3, y, game.game_object_color);
		}


		oldx =x;
		x = x-advance;
		cactus_time = cactus_time - advance;
		bird_time = bird_time -advance;
		if(game.is_actor_up()){
			distance_to_godown += advance;
		}

		semaphore.signal();
		if(cactus_time > -2*(d1 + d2 + d3 +15) && cactus_time <= -(d1 + d2 + d3 +16) 
			&&
					bird_time > -2*(d1 + d2 + d3 +15) && bird_time <= -(d1 + d2 + d3 +16) ){
			x = 69;
			//birdx = 62;
			cloudx = 67;
			cactus_time = x;
		} 
		else if(bird_time <= -2*(d1 + d2 + d3 +14)-74){
			//birdy = flyhigh? 10 : birdy;
			//sleep(400);
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
				//collision(birdx, birdy, bird_w, bird_h);
				birdoldx = birdx;
				birdx = birdx-advance*4;
				if(game.is_actor_up()){
					distance_to_godown += advance*2;
				}
				//cloudoldx = birdoldx;
				//cloudx = birdx;
			} else{
				cloud_bird_distance--;
			}
		
			cloudoldx = cloudx;
			cloudx = cloudx-advance*3;

			semaphore.signal();

			sleep(10);

			semaphore.wait();

			clear_cloud1(cloudoldx-10, cloudy);
			cloud1(cloudx-10,cloudy, 0x78);
			
			if(cloud_bird_distance <= 0){
				clear_flyup(birdoldx, birdy);
				flydown(birdx, birdy, game.game_object_color);
				//collision(birdx, birdy, bird_w, bird_h);

				birdoldx = birdx;
				birdx = birdx-advance*4;
				if(game.is_actor_up()){
					distance_to_godown += advance*2;
				}
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

			sleep(10);
		}
		
		if(birdx <= -30){
			tooglefly();
			x = 69;
			birdx = 62;
			cloudx = 67;
			cloud_bird_distance = 6;
			cactus_time = x;
			bird_time = x;
			//distance_to_godown = 0;
		}
		
		sleep(rate);

		//game.score++;
		
	}
 }