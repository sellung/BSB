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
Guarded_Semaphore semaphore(1);

void Guarded_Semaphore::p (){
	Secure secure;
	Semaphore::p();
}

void Guarded_Semaphore::v (){
	Secure secure;
	Semaphore::v();
}

void Guarded_Semaphore::wait (){
	Secure secure;
	Semaphore::wait();
}

void Guarded_Semaphore::signal (){
	Secure secure;
	Semaphore::signal();
}
