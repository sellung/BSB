/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C G A _ S T R E A M                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse CGA_Stream ermoeglicht die Ausgabe verschiedener Datentypen    */
/* als Zeichenketten auf dem CGA Bildschirm eines PCs.                       */
/* Fuer weitergehende Formatierung oder spezielle Effekte stehen die         */
/* Methoden der Klasse CGA_Screen zur Verfuegung.                            */
/*****************************************************************************/

#ifndef __cgastr_include__
#define __cgastr_include__

#include "object/o_stream.h"
#include "machine/cgascr.h"

class CGA_Stream 
/* Hier muesst ihr selbst Code vervollstaendigen */  
	: public O_Stream, public CGA_Screen       
 {	
 	private:
      CGA_Stream(CGA_Stream &copy); // Verhindere Kopieren
	/* Hier muesst ihr selbst Code vervollstaendigen */ 

	public:
		//CGA_Screen screen;
		//O_Stream kout;
		CGA_Stream() : O_Stream(), CGA_Screen() {
			//CGA_Screen screen;
			//screen.print("PERNES", 5, 0x07);
			//kout << "PERNES" << endl;
		};
		void flush(); 

 };

extern CGA_Stream kout;

#endif
