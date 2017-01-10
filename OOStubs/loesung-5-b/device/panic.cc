/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/
/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
#include "panic.h"
#include "machine/cpu.h"

Panic panic;

 void Panic::trigger (){
 	kout << " Panic trigger" << endl;
 }

 char* Panic::tostring(){
 		// kout << "Ich bin Panic" << endl;
 	return "Ich bin Panic";
 }

 bool Panic::prologue(){
 	kout.setcolor(0x04);
 	kout << "[ x ] PANIC: ERROR CPU go down" << endl;
 	kout.resetcolor();
 	cpu.halt();
 	return false;
 }