/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 B E L L                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine "Glocke" ist eine abstrakte Basisklasse, die das Ausloesen einer     */
/* Aktivitaet nach einer bestimmten Wartezeit erlaubt.                       */
/* Dazu besitzt sie einen Zaehler, der vom "Gloeckner" (Bellringer) ver-     */
/* waltet wird.                                                              */
/*****************************************************************************/

#ifndef __Bell_include__
#define __Bell_include__

#include "object/chain.h" 

class Bell
	: Chain
 {
private:
    Bell(const Bell &copy); // Verhindere Kopieren
    int timetowait;
public:
    Bell() : Chain {}

    void wait (int value) { timetowait = value;}
    int wait () { return timetowait; };
    void tick () { timetowait--; };
    bool run_down () {return timetowait <= 0; };
    virtual void ring () = 0;
};

#endif
