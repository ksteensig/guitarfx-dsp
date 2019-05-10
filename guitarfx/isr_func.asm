*********************************************************************
*Section for: .set, .ref and .def									*
*********************************************************************
ADCR			.set	002A2Dh			  ; Input sample (x(n))
DACR			.set	002A0Dh			  ; Output sample (y(n))
ECHOBUFFSIZE	.set	0x8000

	.ref echo_effect, _flanger_effect
	.def _isr_func, _ring_buffer, xn



*********************************************************************
* _ringBuffer														*
*	Sets up a ringbuffer for use in AR6 and AR7.					*
*	Takes paramters:												*
*		Array consisting of [Buffer Size, Start Address(23)]		*
*********************************************************************
BUFFER 	.usect ".BUFFER", ECHOBUFFSIZE

	.text
_ring_buffer:
	MOV #ECHOBUFFSIZE, mmap(BK47) 	; set buffer size
	AMOV #BUFFER, XAR6				; set page
	BSET AR6LC						; enable circular incrementation
	MOV #0000, BSA67   				; set start address
	MOV #0000, AR6					; set start address of AR6

*Makes sure that the buffer is zeroed
	RPT #ECHOBUFFSIZE
	MOV #0000, *AR6+
	RET


*********************************************************************
* _isr_func															*
*	Defines the order in which the program is excecuted				*
*	Takes paramters:												*
*		None														*
*********************************************************************
		.sect ".temp"
xn:		.word 0x0000

	.text
_isr_func:
	OR #0000100000000000b, mmap(ST1)		; DISABLE INTERRUPTS GLOBALLY!
	AMOV #xn, XCDP							; Needed for next operation
	MOV port(#ADCR), *CDP					; Moves input sample to AC3
	;CALL echo_effect
	CALL _flanger_effect
	MOV.CR *CDP, *AR6-						; Move x[n] into y[n] ringbuffer
	MOV *CDP, port(#DACR)
	AND #1111011111111111b, mmap(ST1)		; ENABLE INTERRUPTS GLOBALLY!
	RETI

