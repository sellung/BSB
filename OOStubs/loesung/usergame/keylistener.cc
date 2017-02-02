#include "usergame/keylistener.h"
#include "device/cgastr.h"
#include "thread/scheduler.h"
#include "syscall/guarded_organizer.h"

#include "guard/secure.h"
#include "device/watch.h"

#include "guard/gate.h"
#include "syscall/guarded_semaphore.h"


#include "syscall/guarded_keyboard.h"
#include "usergame/game.h"


 void Keylistener::action ()
 {
	// semaphore.wait();
 	while(1){
		key = keyboard.getkey();
		//semaphore.wait();
		if(key.ascii() == 32) { game.setjump(true);}
		//semaphore.signal();

		/*semaphore.wait();
		count ++;
		kout.setpos(40, 5);
		kout << "Keyboard hit " << count;
		kout.flush();
		//count ++;
		
		kout.setcolor(0x03);
		kout.setpos(10, 10);
	    kout << key.ascii() ;
	    kout.flush();
	    kout.resetcolor();
	    semaphore.signal();*/
 	}
 }
