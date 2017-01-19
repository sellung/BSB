/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
#include "keyboard.h"
//#include "machine/keyctrl.h"

#include "machine/plugbox.h"
#include "device/cgastr.h"

Keyboard keyboard;

 Guarded_Semaphore semaphore(1);

void Keyboard::trigger(){
	kout.setpos(40, 9);
	kout << "Keyboard hit " << count;
	kout.flush();
	count ++;
	//Key key = key_hit();
	key = key_hit();
	if(key.valid()){
    	
    	kout.setpos(10, 10);
    	kout << key.ascii() ;
    	kout.flush();
    	//kout.show(10, 10, key.ascii(), 0x03);

    	unsigned char a = key.scancode();
    	if(a == 0x53 && (key.ctrl_left() && key.alt_left())){
    		reboot();
    	}
    }
}

void Keyboard::plugin(){
	plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

char* Keyboard::tostring(){
	return "Ich bin Keyboard";
}

void Keyboard::hello(){
	//kout.setpos(60, 9);
	//kout << "Print keyboard" ;
	kout.flush();
}

bool Keyboard::prologue(){
	//kout << "prologue keyboard" << endl;
	key = key_hit();

	unsigned char a = key.scancode();
	if(a == 0x53 && (key.ctrl_left() && key.alt_left())){
    	reboot();
    }	

	return key.valid();
}

void Keyboard::epilogue(){
	semaphore.wait();

	/*
	kout.setpos(40, 9);
	kout << "Keyboard hit " << count;
	kout.flush();
	count ++;

	kout.setcolor(0x03);
	kout.setpos(10, 10);
    kout << key.ascii() ;
    kout.flush();
    kout.resetcolor();

    unsigned char a = key.scancode();
    if(a == 0x53 && (key.ctrl_left() && key.alt_left())){
    	reboot();
    }	*/
}

Key Keyboard::getkey(){

return key;
}