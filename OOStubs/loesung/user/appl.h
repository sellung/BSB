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
#include "syscall/thread.h"

class Application : public Thread
 
 {
private:
    Application (const Application &copy); // Verhindere Kopieren

public:
	int row;
	int col;
	int i;

    Application(void* tos): Thread(tos), i(0){} 
    void action ();
    void setCoord(int c, int r){ col = c; row = r;}
 };

#endif
