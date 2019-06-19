*********************************************************************
*Section for: .set, .ref and .def									*
*********************************************************************
ADCR			.set	002A29h			  ; Left channel ADC
DACR			.set	002A09h			  ; Left channel DAC
ECHOBUFFSIZE	.set	0x4000

	.ref echo_effect, _flanger_effect, _chorus_effect
	.def _isr_func, _ring_buffer, xn, yn



*********************************************************************
* _ringBuffer														*
*	Sets up a ringbuffer for use in AR6 and AR7.					*
*	Takes paramters:												*
*		Array consisting of [Buffer Size, Start Address(23)]		*
*********************************************************************
BUFFER 	.usect ".BUFFER", ECHOBUFFSIZE, 0x10000
BUFFER_ECHO .usect ".BUFFER_ECHO", ECHOBUFFSIZE, 0x10000

	.text
_ring_buffer:
	MOV #ECHOBUFFSIZE, mmap(BK47) 	; set buffer size
	AMOV #BUFFER, XAR6				; set page
	BSET AR6LC						; enable circular incrementation
	MOV AR6, mmap(BSA67)			; set start address

	AMOV #BUFFER_ECHO, XAR5			; set page
	BSET AR5LC						; enable circular incrementation
	MOV AR5, mmap(BSA45)			; set start address
*Makes sure that the buffer is zeroed
	MOV #ECHOBUFFSIZE, mmap(BRC0)
	RPTBLOCAL ring_buffer_end
	MOV #0000, *AR6+
ring_buffer_end: MOV #0000, *AR5+ || NOP
	RET


*********************************************************************
* _isr_func															*
*	Defines the order in which the program is excecuted				*
*	Takes paramters:												*
*		None														*
*********************************************************************
		.sect ".temp"
xn:		.word 0x0000
yn:		.word 0x0000

	.text

_isr_func_IIR:
	OR #0000100000000000b, mmap(ST1)		; DISABLE INTERRUPTS GLOBALLY!
	AMOV #xn, XCDP							; Needed for next operation
	MOV port(#ADCR), *CDP					; Moves input sample to AC3
	CALL echo_effect
	MOV.CR *CDP, *AR6-						; Move x[n] into y[n] ringbuffer
	MOV *CDP, port(#DACR)
	AND #1111011111111111b, mmap(ST1)		; ENABLE INTERRUPTS GLOBALLY!
	RETI

_isr_func:
	OR #0000100000000000b, mmap(ST1)		; DISABLE INTERRUPTS GLOBALLY!
	AMOV #yn, XAR7
	AMOV #xn, XCDP							; Needed for next operation
	MOV *AR5, *AR7
	MOV port(#ADCR), *CDP					; Moves input sample to AC3
	MOV *CDP, *AR6
	CALL _flanger_effect
	;CALL _chorus_effect
	;CALL echo_effect
	AMAR *AR6-
	MOV.CR *CDP, *AR5-
	MOV *CDP, port(#DACR)
	AND #1111011111111111b, mmap(ST1)		; ENABLE INTERRUPTS GLOBALLY!
	RETI

_isr_func_DEBUG:
	OR #0000100000000000b, mmap(ST1)		; DISABLE INTERRUPTS GLOBALLY!
	;NEG T0
	MOV port(#ADCR), AR6
	MOV AR6, port(#DACR)
	;MOV *CDP, port(#DACR)
	;AMAR *AR6-
	AND #1111011111111111b, mmap(ST1)		; ENABLE INTERRUPTS GLOBALLY!
	RETI

