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

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "pic.h"

PIC pic;

CPU cpu;

PIC::PIC(): ocw1(0x21), ocw2(0x20) {}

/**
* Lässt zu, dass de PIC Unterbrechungen des Geräts Nummer interrupt_device
* an den Prozessor weiterleitet.
*/   
void PIC::allow(int interrupt_device){
	int c = ocw1.inb();
	c &= ~(1<<interrupt_device);
	ocw1.outb(c);
	kout <<"PIC STATUS: " << bin << c << endl;
	cpu.enable_int();
}
		
/**
* Verhindert, dass der PIC Unterbrechung des Geräts Nummer interrupt_device
* an der Prozessor weiterleitet.
*/
void PIC::forbid(int interrupt_device){
	kout << "forbid" << endl;
	int c = ocw1.inb();
	c |= (1<<interrupt_device);
	ocw1.outb(c);
	kout << c <<" " << bin << c << endl;
	cpu.disable_int();
}
