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

Panic panic;

 void Panic::trigger (){
 	kout << " Panic trigger" << endl;
 }

 char* Panic::tostring(){
 		// kout << "Ich bin Panic" << endl;
 	return "Ich bin Panic";
 }