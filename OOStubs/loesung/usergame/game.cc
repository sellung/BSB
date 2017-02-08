#include "usergame/game.h"
#include "syscall/guarded_semaphore.h"


Game game;

bool Game::collision(int x, int y, int width, int height){
	Secure secure;
	if(actor_posy + height_actor < height){
		return false;
	}else{
	if((x >= actor_posx && x <= actor_posx + 8)
			|| (x < game.actor_posx && x + width > game.actor_posx)
			)
		{
			return true;
		}
	}
	//return false;
}

void Game::day(){
	clearscreen(0x70);
}

void Game::night(){
	clearscreen(0x0);
}

void Game::day(int x, int y){
	clearscreen(x, y, 0x70);
}
	