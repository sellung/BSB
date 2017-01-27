/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

/* INCLUDES */
/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "meeting/buzzer.h"
#include "meeting/bellringer.h"
#include "thread/customer.h"
#include "syscall/guarded_organizer.h"

#include "device/cgastr.h"

Buzzer::~Buzzer (){
	bellringer.cancel(this);
}

void Buzzer::ring (){
	Customer* customer = (Customer*)Waitingroom::dequeue();
	while(customer){
		//kout << "wakeup" << endl;
		scheduler.Organizer::wakeup(*(customer));
		customer = (Customer*) dequeue();
	}
}

void Buzzer::set (int ms){
	bellringer.job(this, ms);
}

void Buzzer::sleep (){
	bellringer.cancel(this);
	
}
