/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
//#include "machine/cgascr.h"
#include "thread/scheduler.h"
#include "user/appl.h"
#include "device/cgastr.h"
#include "thread/dispatch.h"

void* stack_1[1024];
void* stack_2[1024];
void* stack_3[1024];

Scheduler scheduler;

int main()
{	

	kout.clearscreen();
	
	kout << " size of stack_1: " << sizeof(stack_1) << endl;

	Application app1(&stack_1[1024]);
	Application app2(&stack_2[1024]);
	Application app3(&stack_3[1024]);
	
	app1.setName("my-app1");
	app1.color = 0x03;
	app1.setCoord(20, 20);
	
	app2.setName("my-app2");
	app2.color = 0x04;
	app2.setCoord(20, 12);
	
	app3.setName("my-app2");
	app3.color = 0x05;
	app3.setCoord(20, 13);
	
	scheduler.ready(app1);
	scheduler.ready(app2);
	scheduler.ready(app3);
	
	scheduler.schedule();
	
	//Application app2(stack_2);
	
	
	//dispatcher.go(app1);
	//app2.setName("app2");
	
	//scheduler.ready(app1);
	
	//scheduler.ready(app2);
	//while(3){
	//scheduler.schedule();
	//scheduler.exit();
	//scheduler.exit();
	//}
}
