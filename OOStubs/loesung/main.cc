/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
//#include "machine/cgascr.h"
#include "thread/scheduler.h"
#include "user/appl.h"
#include "device/cgastr.h"
#include "thread/dispatch.h"
#include "guard/secure.h"
//#include "syscall/guarded_scheduler.h"
#include "syscall/guarded_organizer.h"
#include "device/watch.h"
#include "machine/cpu.h"
#include "guard/guard.h"

#include "syscall/guarded_buzzer.h"
#include "syscall/guarded_keyboard.h"
#include "meeting/bellringer.h"

#include "device/keyboard.h"

#include "usergame/bird.h"
#include "usergame/actor.h"
#include "usergame/road.h"
#include "usergame/keylistener.h"
#include "usergame/cactus.h"
#include "usergame/logic.h"

void* stack_empty_app[2048];
void* stack_start[1024];

void* stack_cactus[1024];
void* stack_keylistener[1024];

//void* stack_bird[1024];
void* stack_actor[1024];
//void* stack_road[1024];

//void* stack_logic[1024];

Watch watch(1);

int main()
{	
	Secure secure;

	kout.clearscreen();

	//kout.startMsg();
	//game.day();

	keyboard.plugin();
	
	watch.windup();

	//kout << "salut pantos2" << endl;
	
	EmptyApp empty_app(&stack_empty_app[1024]);
	Start start_app(&stack_start[1024]);
	
	Keylistener keylistener(&stack_keylistener[1024]);
	

	//Bird bird(&stack_bird[1024]);
	Actor actor(&stack_actor[1024]);
	//Road road(&stack_road[1024]);
	Cactus cactus(&stack_cactus[1024]);

	game.setgame(&actor, &cactus);
	
	scheduler.Scheduler::ready(start_app);
	scheduler.Organizer::ready(empty_app);
	scheduler.Scheduler::ready(keylistener);
	//scheduler.Scheduler::ready(app2);		
	//scheduler.Scheduler::ready(bird);		
	//scheduler.Scheduler::ready(actor);
	//scheduler.Scheduler::ready(cactus);
	//scheduler.Scheduler::ready(road);
	//scheduler.Scheduler::ready(logic);

	scheduler.schedule();
}
