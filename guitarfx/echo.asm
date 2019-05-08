D				.set	0x7FFF			  ; Delay
DG				.set	0010000000000000b ; in Q14 this is 0.5

	.def echo_effect
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
*Calculate Echo effect: y[n] = x[n] + DG * y[n-d]
	MOV *AR6(D), AC0				; move y[n-d] into accumulator
	SFTS AC0, #16					; Shift the delay input left in the AC0. Could probably be replaced by HI(AC0) as Casper mentioned.
	MPYK #DG, AC0					; multiply G and y[n-d]
	SFTS AC0, #-15					; Shift the output down so we can get it out. 15 = 16 right (to mov hi to low part) - 1 to remove extra sign bit.
	ADD *AR0, AC0					; add x[n] to get y[n]
	MOV AC0, *AR0					; move y[n] into x[n] = AR0 for next effect to use
	RET
