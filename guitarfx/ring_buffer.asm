ADCR	.set	002A2Dh			  ; Input sample (x(n))
DACR	.set	002A0Dh			  ; Output sample (y(n))
D		.set	4000			  ; Delay
DG		.set	0010000000000000b ; in Q14 this is 0.5

;	.bss BUFFER,(8000)

;	.sect "BUFFER"	  ; Ring buffer for echo effect


		.def BUFFER
BUFFER 	.usect "BUFFER", 0x1000

	;.global DACR, ADCR, D, DG, BUFF, _ringBuffer, _echoUpdate
	.global _isr_func, _ring_buffer
	.text
**********************************************************************
* _ringBuffer
*	Sets up a ringbuffer for use in AR6 and AR7.
*	Takes paramters:
*		Array consisting of [Buffer Size, Start Address(23)]
**********************************************************************
_ring_buffer:
	MOV 0x1000, mmap(BK47) 			; set buffer size
	AMOV #020000h, XAR6; set page
	BSET AR6LC
	MOV #0000, BSA67   			; set start address
	MOV #0000, AR6
	;OR 1110000000000000b, port(#001C06h)
	;OR 1110000000000000b, port(#001C0Ah)
	;AND 0111111111111111b, port(#001C0Ah)
	RET

echo_effect:
	MOV *AR6(-D), AC0
	MPYK #DG, AC0, AC0
	ADD AR0, AC0
	MOV.CR AC0, *AR6+
	MOV AC0, AR0
	RET

flanger_effect:
	RET

_isr_func:
	MOV port(#ADCR), AR0
	CALL echo_effect
	MOV AR0, port(#DACR)
	RETI
