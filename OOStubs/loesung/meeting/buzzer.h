/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

#ifndef __Buzzer_include__
#define __Buzzer_include__

#include "meeting/bell.h"
#include "meeting/waitingroom.h"

class Buzzer
	: public Bell, public Waitingroom
{
private:
    Buzzer(const Buzzer &copy); // Verhindere Kopieren
public:
	Buzzer (): Bell(), Waitingroom() {}
	virtual ~Buzzer ();
	virtual void ring ();
	void set (int ms);
	void sleep ();
};

#endif
