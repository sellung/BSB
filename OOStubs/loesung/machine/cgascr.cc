/* $Id: cgascr.cc 5834 2013-10-08 17:04:08Z os $ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse kann man auf den Bildschirm des PCs zugreifen.    */
/* Der Zugriff erfolgt direkt auf der Hardwareebene, d.h. ueber den Bild-    */
/* schirmspeicher bzw. die I/O-Ports der Grafikkarte.                        */
/*****************************************************************************/

#include "machine/cgascr.h"


void CGA_Screen::show(int x, int y, char c, unsigned char attrib)
{
		char *CGA_START = (char *)0xb8000;
		char *pos;
		pos = CGA_START + 2*(x + y*80);
		*pos = 'Q';
		*(pos + 1) = attrib; // weiss auf schwarz
		CGA_Screen::setpos(x, y);
}

void CGA_Screen::setpos(int x, int y)
{

	int position = (x+1 + y*80);
	
	indexPort.outb(15);
	// Um die Bits zu schieben 
	datenPort.outb(position&0xff);
	indexPort.outb(14);
	datenPort.outb((position>>8)&0xff);


			
}

/* Hier muesst ihr selbst Code vervollstaendigen */ 
