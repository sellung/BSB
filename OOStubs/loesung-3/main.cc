/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
//#include "machine/cgascr.h"
#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"



int main()
{	
	//CGA_Stream kout;
	kout.clearscreen();
    
    Application appl;

    appl.action();
 }
