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
#include "machine/keyctrl.h"

#include "machine/plugbox.h"
#include "device/cgastr.h"

Keyboard keyboard;

void Keyboard::trigger(){
	kout.setpos(40, 9);
	kout << "Keyboard trigger " << count;
	kout.flush();
	count ++;
	Key key = key_hit();
	if(key.valid()){
    	
    	kout.show(10, 10, key.ascii(), 0x03);

    	unsigned char a = key.scancode();
    	if(a == 0x53 && (key.ctrl_left() && key.alt_left())){
    		reboot();
    	}
    }
}

void Keyboard::plugin(){
	//Plugbox plugbox;
	//PIC pic;
	plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

char* Keyboard::tostring(){
	// kout << "Ich bin Keyboard" << endl;
	return "Ich bin Keyboard";
}

void Keyboard::hello(){
	kout.setpos(60, 9);
	kout << "Print keyboard" ;
	kout.flush();
}