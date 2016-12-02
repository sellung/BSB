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

/* Hier muesst ihr selbst Code vervollstaendigen */ 
class Gate {
private:
	Gate(const Gate &copy); // Verhindere Kopieren

public:
	Gate(){}
	// Funktion zur Unterbrechungsbehandlung.
	virtual void trigger () = 0;
	virtual char* tostring() = 0;
};
#endif
