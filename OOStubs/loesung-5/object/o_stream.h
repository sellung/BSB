/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ iO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#ifndef __o_stream_include__
#define __o_stream_include__

#include "object/strbuf.h"
#include "machine/cgascr.h"

#define MAX_PRECISION = 1000000000;

class O_Stream
/* Hier muesst ihr selbst Code vervollstaendigen */         
	:public Stringbuffer
 {
	private:
      O_Stream(const O_Stream &copy); // Verhindere Kopieren
      
/* Hier muesst ihr selbst Code vervollstaendigen */  
	public:
		enum {dec=10, bin=2, oct=8, hex=16};
		int zahlensystem;
		char digits[16] ;//= {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
		char color;
		O_Stream() : Stringbuffer() , zahlensystem(10), color(0x0f){
			for (int i = 0; i < 10; ++i)
			{
				digits[i] = '0'+i;
			}
			digits[10] = 'a';
			digits[11] = 'b';
			digits[12] = 'c';
			digits[13] = 'd';
			digits[14] = 'e';
			digits[15] = 'f';
		};

		
		void flush();
		
		O_Stream& operator<< (unsigned char c);
		O_Stream& operator<< (char c);
		O_Stream& operator<< (unsigned short number);
		O_Stream& operator<< (short number);
		O_Stream& operator<< (unsigned int number);
		O_Stream& operator<< (int number);
		O_Stream& operator<< (unsigned long number);
		O_Stream& operator<< (long number);
		O_Stream& operator<< (void* pointer);
		O_Stream& operator<< (char* text);
		
		O_Stream& operator<< (O_Stream& (*fkt) (O_Stream&));

		void numbertostring(unsigned long number, int base);
		void numbertostring2(long number, int base);

		O_Stream& operator>> (unsigned char c);
		O_Stream& operator>> (O_Stream& (*fkt) (O_Stream&));

		void resetcolor(){ color = 0x0f;}

		void setcolor(char c){ color = c;}
 };

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          M A N I P U L A T O R E N                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die folgenden Funktionen erhalten und liefern jeweils eine Referenz auf   */
/* ein O_Stream Objekt. Da die Klasse O_Stream einen Operator << fuer        */
/* derartige Funktionen definiert, koennen sie mit Hilfe dieses Operators    */
/* aufgerufen und sogar in weitere Eingaben eingebettet werden.              */
/* Aufgabe der Manipulatoren ist, die Darstellung der nachfolgenden Ausgaben */
/* zu beeinflussen, z.B durch die Wahl des Zahlensystems.                    */
/*---------------------------------------------------------------------------*/

// ENDL: fuegt einen Zeilenumbruch in die Ausgabe ein.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
O_Stream& endl (O_Stream& os);
// BIN: waehlt das binaere Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
O_Stream& bin (O_Stream& os);
// OCT: waehlt das oktale Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
O_Stream& oct (O_Stream& os);
// DEC: waehlt das dezimale Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 O_Stream& dec (O_Stream& os);
// HEX: waehlt das hexadezimale Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 O_Stream& hex (O_Stream& os);

 O_Stream& myout (O_Stream& os);


#endif

