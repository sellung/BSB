/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
//#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "object/strbuf.h"
#include "machine/keyctrl.h"
#include "machine/cpu.h"
#include "machine/pic.h"

int main_backup()
{
    CGA_Stream kout;   
    Keyboard_Controller keyctrl;
    CPU cpu;
    PIC pic ;

    pic.allow(PIC::keyboard);
    //kout.clearscreen();
    kout.startMsg();
    
    int jahr = 2016;
    int a = -32;
    kout << "Welcome to OOSTUBS WISE " << jahr << ". TU Dortmund" << endl;                   
    kout << "Pernes, Abdou und Marcel" << endl;
    kout << "a = " << dec << a << " ist binaere " << bin << a << endl;
    kout << "a = " << dec << a << " ist oktale " << oct << a << endl;
    kout << "a = " << dec << a << " ist hexadezimal " << hex << a << endl;

    //kout.setpos(0, 23);
   // int x , y;
    while(1){
    	
    	Key key = keyctrl.key_hit();

    	if(key.valid()){
    		//kout.getpos(x, y);
    		//kout << "x=" << x << "y=" << y << " ";
    		 
    		kout << key.ascii();
    		kout.flush();

    	}
    }
  	return 0;
 }
