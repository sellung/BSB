/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* Mit Hilfe des PICs koennen Hardware-Unterbrechungen einzeln zugelassen    */
/* oder unterdrueckt werden. Auf diese Weise wird also bestimmt, ob die      */
/* Unterbrechung eines Geraetes ueberhaupt an den Prozessor weitergegeben    */
/* wird. Selbst dann erfolgt eine Aktivierung der Unterbrechungsroutine nur, */
/* wenn der Prozessor bereit ist, auf Unterbrechungen zu reagieren. Dies     */
/* kann mit Hilfe der Klasse CPU festgelegt werden.                          */
/*****************************************************************************/

#ifndef __pic_include__
#define __pic_include__

#include "cpu.h"
#include "machine/io_port.h"
#include "device/cgastr.h" // only for test

class PIC
{
	private:
    	PIC(const PIC &copy); // Verhindere Kopieren

    private:
    	const IO_Port ocw1; // OCW1
    	const IO_Port ocw2; // OCW2
    	CGA_Stream kout; 
	public:
		
    	//PIC(CPU c){}
    	PIC();
		/* Hier muesst ihr selbst Code vervollstaendigen */

		/**
		* Nummern der Geräte, die an den PIC angeschlossen sind.
		*/
    	enum {timer = 0, keyboard = 1};
		/**
		* Lässt zu, dass de PIC Unterbrechungen des Geräts Nummer interrupt_device
		* an den Prozessor weiterleitet.
		*/   
		void allow(int interrupt_device);
		
		/**
		* Verhindert, dass der PIC Unterbrechung des Geräts Nummer interrupt_device
		* an der Prozessor weiterleitet.
		*/
		void forbid(int interrupt_device);
 };

extern PIC pic;

#endif
