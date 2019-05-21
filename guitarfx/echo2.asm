
		.sect  ".ivars"
 			.align 2
dl:			.word 0x0FFF
G:			.word 0x3000		;Signed Q15
D:			.word 0x7FFF		;Signed Q15

	;.def echo_effect
	.ref xn
*********************************************************************
* echo_effect														*
*	Adds echo effect to input sample								*
*	Takes paramters:												*
*		D - Delay, DG - Delay Gain									*
*	Difference equation:											*
*		y[n] = x[n] + DG * y[n-d]									*
*********************************************************************

	.text
echo_effect:
*Setup for echo_effect
	AMOV #xn, XAR0
	MOV *(#dl), T0
*Calculate Echo effect: y[n] = D*(x[n] + DG * y[n-d])
	BSET FRCT
	MOV *AR6(T0) << #16, AC0		; move y[n-d] into accumulator
	MPYM *(#G), AC0					; multiply G and y[n-d]
	SFTS AC0, #-16					; Shift the output down so we can get it out. 15 = 16 right (to mov hi to low part) - 1 to remove extra sign bit.
	ADD *AR0, AC0					; add x[n] to get y[n]
	MPYM *(#D), AC0					; multiply D and x[n] + DG * y[n-d]
	MOV HI(AC0), *AR0				; move y[n] into x[n] = AR0 for next effect to use
	BCLR FRCT
	RET

