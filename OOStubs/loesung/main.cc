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

void* stack_1[1024];
void* stack_2[1024];

void* stack_cactus[1024];
void* stack_keylistener[1024];

void* stack_5[1024];
void* stack_actor[1024];
void* stack_road[1024];

void* stack_logic[1024];

Watch watch(1);

int main()
{	
	Secure secure;

	kout.clearscreen();

	//kout.startMsg();

	keyboard.plugin();
	
	watch.windup();

	kout << "salut pantos2" << endl;
	
	EmptyApp app1(&stack_1[1024]);
	Application app2(&stack_2[1024]);
	
	Keylistener keylistener(&stack_keylistener[1024]);
	
	Bird bird(&stack_5[1024]);
	Actor actor(&stack_actor[1024]);
	Road road(&stack_road[1024]);
	Cactus cactus(&stack_cactus[1024]);

	//Logic(void* tos, Actor* a, Bird* b, Cactus* c,Road* r): 
	Logic logic(&stack_logic[1024], &actor, &bird, &cactus, &road);

	int col = 30;
	int row = 8;
	app1.setName("App1");
	app1.color = 0x03;
	app1.setCoord(col, row);
	app1.id = 1;
	
	app2.setName("App2");
	app2.color = 0x04;
	app2.setCoord(col, row + 2);
	app2.id = 2;

	scheduler.Organizer::ready(app1);
	scheduler.Scheduler::ready(keylistener);
	scheduler.Scheduler::ready(app2);		
	scheduler.Scheduler::ready(bird);		
	scheduler.Scheduler::ready(actor);
	//scheduler.Scheduler::ready(cactus);
	scheduler.Scheduler::ready(road);
	scheduler.Scheduler::ready(logic);

	scheduler.schedule();
}
