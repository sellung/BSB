/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
//#include "machine/cgascr.h"
#include "thread/scheduler.h"
#include "user/appl.h"

void* stack_1[1024];
void* stack_2[1024];

Scheduler scheduler;

int main()
{	

	Application app1(stack_1);
	Application app2(stack_2);

	scheduler.ready(app1);
	scheduler.ready(app2);
	//while(3){
	scheduler.schedule();
	//}
}
