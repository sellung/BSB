/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S E M A P H O R E                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Semaphor.                                   */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "syscall/guarded_semaphore.h"
#include "guard/secure.h"

//Guarded_Semaphore keyboard_sem(1);

void Guarded_Semaphore::p (){
	Secure secure;
	p();
}

void Guarded_Semaphore::v (){
	Secure secure;
	v();
}

void Guarded_Semaphore::wait (){
	Secure secure;
	wait();
}

void Guarded_Semaphore::signal (){
	Secure secure;
	signal();
}
