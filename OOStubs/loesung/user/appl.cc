/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
/* Hier muesst ihr selbst Code vervollstaendigen */         
#include "device/keyboard.h"
#include "machine/cpu.h"
#include "guard/secure.h"
/* GLOBALE VARIABLEN */

//extern CGA_Stream kout;
/* Hier muesst ihr selbst Code vervollstaendigen */ 

//CGA_Stream kout;

void Application::action ()
 {
 	/* Hier muesst ihr selbst Code vervollstaendigen */ 
 	keyboard.plugin();
 	 while(1){
 	 	Secure secure;
 	 	//cpu.disable_int();
 	 	kout.setpos(20, 20);
 		kout << "Hello world";
 		kout.flush();
 		//cpu.enable_int();	
 		//secure.~Secure();
 	 }
 }
