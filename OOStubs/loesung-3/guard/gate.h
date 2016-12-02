/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Klasse von Objekten, die in der Lage sind, Unterbrechungen zu behandeln.  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

#include "object/chain.h"

/* Hier muesst ihr selbst Code vervollstaendigen */ 
class Gate : public Chain {
private:
	Gate(const Gate &copy); // Verhindere Kopieren
	bool inqueue;
public:
	Gate(){}
	// Funktion zur Unterbrechungsbehandlung.
	virtual void trigger () = 0;
	virtual char* tostring() = 0;

	// Prolog der Unterbrechungsbehandlung. Ein Rückgabewert true zeigt an, 
	// dass der zugehörige Epilog ausgeführt werden soll.
	virtual bool prologue () = 0;

	// Epilogue der Unterbrechungsbehandlung.
	virtual void epilogue (){}

	// Methode zum Abfragen, ob sich das jeweilige Objekte gerade in einer 
	// Epilog-Warteschlange befindet.
	bool queued(){ return inqueue; }

	// Speichert, ob das jeweilige Objekt sich gerade in einer Epilog-Warteschlange befindet.
	void queued(bool b){ inqueue = b; }


};
#endif
