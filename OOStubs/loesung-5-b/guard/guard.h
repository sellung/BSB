/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse koennen Aktivitaeten, die einen kritischen        */
/* Abschnitt betreffen, der mit einem Guard-Objekt geschuetzt ist, mit       */
/* Unterbrechungsbehandlungsroutinen synchronisiert werden, die ebenfalls    */
/* auf den kritischen Abschnitt zugreifen.                                   */
/*****************************************************************************/

#ifndef __Guard_include__
#define __Guard_include__

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "guard/locker.h"
#include "object/queue.h"
#include "guard/gate.h"

class Guard : public Locker
 {
private:
    Guard (const Guard &copy); // Verhindere Kopieren
    int count;
public:
    Guard (): count(0) {}
/* Hier muesst ihr selbst Code vervollstaendigen */ 
	Queue queue;  

	//Mit dieser Methode wird der kritische Abschnitt verlassen und die 
	//angestauten Epiloge werden abgearbeitet.
	void leave();   

	void relay (Gate* item);    
 };

 extern Guard guard;

#endif
