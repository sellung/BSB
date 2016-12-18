/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "device/watch.h"

//Plugbox plugbox;
//PIC pic;

void windup (){
	plugbox.assign(Plugbox::timer, *this);
	pic.allow(PIC::timer);
}

bool prologue (){

}

void epilogue (){

}
