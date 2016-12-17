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
	
	kout << "size of stack_1: " << sizeof(stack_1) << endl;
	kout << "size of stack_2: " << sizeof(stack_2) << endl;
	kout << "size of stack_3: " << sizeof(stack_3) << endl;

	Application app1(&stack_1[1024]);
	Application app2(&stack_2[1024]);
	Application app3(&stack_3[1024]);
	
	int col = 30;
	int row = 8;
	app1.setName("App1");
	app1.color = 0x03;
	app1.setCoord(col, row);
	
	app2.setName("App2");
	app2.color = 0x04;
	app2.setCoord(col, row + 2);
	
	app3.setName("App3");
	app3.color = 0x05;
	app3.setCoord(col, row + 4);
	
	scheduler.ready(app1);
	scheduler.ready(app2);
	scheduler.ready(app3);
	
	scheduler.schedule();
}
