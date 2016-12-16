/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "thread/entrant.h"

class Application : public Entrant
 
 {
private:
    Application (const Application &copy); // Verhindere Kopieren

public:
	int row;
	int col;
/* Hier muesst ihr selbst Code vervollstaendigen */                  
    Application(void* tos): Entrant(tos){} 
    void action ();
    void setCoord(int c, int r){ col = c; row = r;}
 };

#endif
