ADCR			.set	002A2Dh			  ; Input sample (x(n))
DACR			.set	002A0Dh			  ; Output sample (y(n))
D				.set	0x7FFF			  ; Delay
DG				.set	0010000000000000b ; in Q14 this is 0.5
ECHOBUFFSIZE	.set	0x8000
;	.bss BUFFER,(8000)

;	.sect "BUFFER"	  ; Ring buffer for echo effect

		.def BUFFER
BUFFER 	.usect "BUFFER", ECHOBUFFSIZE

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
	MOV #ECHOBUFFSIZE, mmap(BK47) 	; set buffer size
	AMOV #020000h, XAR6				; set page
	BSET AR6LC						; enable circular incrementation
	MOV #0000, BSA67   				; set start address
	MOV #0000, AR6					; set start address of AR6

	; Make sure that the buffer is zeroed
	RPT #ECHOBUFFSIZE
	MOV #0000, *AR6+

	;OR 1110000000000000b, port(#001C06h)
	;OR 1110000000000000b, port(#001C0Ah)
	;AND 0111111111111111b, port(#001C0Ah)
	RET

; y[n] = x[n] + G * y[n-d]
echo_effect:
	MOV *AR6(-D), AC0				; move y[n-d] into accumulator
	SFTS AC0, #16					; Shift the
	MPYK #DG, AC0					; multiply G and y[n-d]
	SFTS AC0, #-15					; Does this work?
	ADD AR0, AC0					; add x[n] to get y[n]
	MOV.CR AC0, *AR6+				; move y[n] into ringbuffer
	MOV AC0, AR0					; move y[n] into AR0
	RET

flanger_effect:
	RET

_isr_func:
	MOV port(#ADCR), AR0
	CALL echo_effect
	MOV AR0, port(#DACR)
	RETI
