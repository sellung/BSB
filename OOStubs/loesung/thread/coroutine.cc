/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          C O R O U T I N E                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Koroutinenkonzepts.                                   */
/* Im Konstruktor wird der initiale Kontext der Koroutine eingerichtet.      */
/* Mit go() wird die erste Koroutine aktiviert. Alle weiteren Koroutinen-    */
/* wechsel sollten mit resume() erfolgen.                                    */
/* Um bei einem Koroutinenwechsel den Kontext sichern zu koennen, enthaelt   */
/* jedes Koroutinenobjekt eine Struktur toc, in dem die Werte der nicht-     */
/* fluechtigen Register gesichert werden koennen.                            */
/*****************************************************************************/

#include "thread/coroutine.h"
#include "device/cgastr.h"


// Funktionen, die auf der Assembler-Ebene implementiert werden, muessen als
// extern "C" deklariert werden, da sie nicht dem Name-Mangeling von C++ 
// entsprechen.
extern "C" void toc_settle (struct toc* regs, void* tos, void (*kickoff)(void*), void* object); 
extern "C" void toc_go(struct toc* regs);
extern "C" void toc_switch(struct toc* regs_now, struct toc* regs_then);  

Coroutine::Coroutine(void* tos){
	kout << "new coroutine : kickoff address : "  << (int)kickoff << endl;
	toc_settle(&toc, tos, kickoff, this);
	kout << "[toc.esp] " << toc.esp << " esp = " << *(int*)toc.esp <<endl;
}
void Coroutine::go(){
	kout << "Coroutine::go" << endl;
	kout << "[toc.esp] " << toc.esp << " esp = " << *(int*)toc.esp <<endl;
	toc_go(&toc);
}

void Coroutine::resume(Coroutine& next){
	toc_switch(&toc, &(next.toc));
}
