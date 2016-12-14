; $Id: toc.asm 956 2008-10-19 22:24:23Z hsc $

;******************************************************************************
;* Betriebssysteme                                                            *
;*----------------------------------------------------------------------------*
;*                                                                            *
;*                               T O C . A S M                                *
;*                                                                            *
;*----------------------------------------------------------------------------*
;*
;******************************************************************************

%include "machine/toc.inc"

; EXPORTIERTE FUNKTIONEN

[GLOBAL toc_switch]
[GLOBAL toc_go]

; IMPLEMENTIERUNG DER FUNKTIONEN

[SECTION .text]

; TOC_GO : Startet den ersten Prozess ueberhaupt.
;
; C Prototyp: void toc_go (struct toc* regs);

toc_go:
	mov ebx, [esp + 4 + ebx_offset] 
    mov esi, [esp + 4 + esi_offset]
    mov edi, [esp + 4 + edi_offset]
    mov ebp, [esp + 4 + ebp_offset]  
    mov esp, [ebp + 4 + esp_offset]

    iret

; Hier muesst ihr selbst Code vervollstaendigen         

; TOC_SWITCH : Prozessumschaltung. Der aktuelle Registersatz wird     
;              gesichert und der Registersatz des neuen "thread of control"
;              wird in den Prozessor eingelesen.  
;
; C Prototyp: void toc_switch (struct toc* regs_now,
;                              struct toc* reg_then);

toc_switch:
; Hier muesst ihr selbst Code vervollstaendigen 
	; we backup firstly regs_now. regs_now is a pointer of struct toc, then
	; we can write direct to the address who regs_now pointing
	; [esp + 4] give us the first parameter
	mov eax, [esp + 4]
	mov [eax + ebx_offset], ebx
    mov [eax + 4 + esi_offset], esi
    mov [eax + 4 + edi_offset], edi
    mov [eax + 4 + ebp_offset], ebp 
    mov [eax + 4 + esp_offset], esp,
	; now we set the processor register with the content of reg_then
	; [esp + 8] give us the second parameter
	mov eax, [esp + 8]
	mov ebx, [eax + 8 + ebx_offset] 
    mov esi, [eax + 8 + esi_offset]
    mov edi, [eax + 8 + edi_offset]
    mov ebp, [eax + 8 + ebp_offset]  
    mov esp, [eax + 8 + esp_offset]

    iret
