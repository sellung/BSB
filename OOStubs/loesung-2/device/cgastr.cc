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

#include "device/cgastr.h"

/* Hier muesst ihr selbst Code vervollstaendigen */ 

CGA_Stream kout;

void CGA_Stream::flush(){
	CGA_Screen::print(CGA_Stream::O_Stream::Stringbuffer::value, O_Stream::currentindex, 0x0f);
	currentindex = 0;
	for (int i = 0; i < MAX_SIZE_BUFFER; ++i)
	{
		O_Stream::value[i]=' ';
	}
} 