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
#include "object/chain.h"

Buzzer::~Buzzer (){
	bellringer.cancel(this);
	Waittingroom::~Waittingroom();
}

void Buzzer::ring (){
	Chain* chain = dequeue();
	while(chain){
		Entrant* entrant = (Entrant*)chain;
		Customer* customer = (Customer*)entrant;
		scheduler.wakeup(*(customer));
		chain = dequeue();
	}
}

void Buzzer::set (int ms){
	bellringer.job(this, ms)
}

void Buzzer::sleep (){
	tick();
}
