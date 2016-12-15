/* $Id: toc.c 956 2008-10-19 22:24:23Z hsc $ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 T O C                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Struktur toc dient dazu, bei einem Koroutinenwechsel die Werte der    */
/* nicht-fluechtigen Register zu sichern.                                    */
/* Beim GNU C Compiler sind eax, ecx und edx fluechtige Register, die bei    */
/* Funktionsaufrufen und somit auch bei einem Koroutinenwechsel keine        */
/* spaeter noch benoetigten Werte haben duerfen. Daher muss in der Struktur  */
/* toc auch kein Platz fuer sie bereitgestellt werden.                       */
/*****************************************************************************/

#include "machine/toc.h"

//static void* stack_start[512];

// TOC_SETTLE: bereitet den Kontext der Koroutine fuer den ersten
//             Aufruf vor.
void toc_settle (struct toc* regs, void* tos, void (*kickoff)(void*), void* object)
{	
	// Initialize stack pointer with the Top of Stack (high memory)
	//regs->ebp = tos;
	void **sp = (void**)tos; 
	// decrement the Stack pointer of the size of the pointer in 32 bits architecture (32bits)
	sp--;

	*sp = object;
	sp--;

	*sp = 0;
	sp--;

	*sp = kickoff; 
	
	//sp -= 11; 
	
	regs->esp = sp;
	*sp--;
	*sp = regs->esp;
	sp -= 12;
/*	*sp--;
	*sp = regs->ebp;
	*sp--;
	*sp = regs->edi;
	*sp--;
	*sp = regs->esi;
	*sp--;
	*sp = regs->ebx;*/

	//
}
