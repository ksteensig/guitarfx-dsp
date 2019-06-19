			.sect  ".ivars"
 			.align 2

*** Offsets in COM_CONFIG_DMA_SEC
dl:			.set 0x200
G:			.set 0x202		;Signed Q15
D:			.set 0x204		;Signed Q15

	.def echo_effect
	.ref xn, yn, COM_CONFIG_DMA_SEC
*********************************************************************
* echo_effect														*
*	Adds echo effect to input sample								*
*	Takes paramters:												*
*		D - Delay, DG - Delay Gain									*
*	Difference equation:											*
*		y[n] = D*(x[n] + G * y[n-d])								*
*********************************************************************

	.text
echo_effect:
*Setup for echo_effect
	AMOV #xn, XAR0
	MOV *(#COM_CONFIG_DMA_SEC+dl), T0
*Calculate Echo effect: y[n] = x[n] + DG * y[n-d]
	MOV *AR5(T0), AC0				; move y[n-d] into accumulator
	SFTS AC0, #16					; Shift the delay input left in the AC0.
	MPYM *(#COM_CONFIG_DMA_SEC + G), AC0					; multiply G and y[n-d]
	SFTS AC0, #1					; Shift the output down so we can get it out. 15 = 16 right (to mov hi to low part) - 1 to remove extra sign bit.

	ADD *AR0 << #16, AC0				; add x[n] to get y[n]
	MPYM *(#COM_CONFIG_DMA_SEC + D), AC0					; multiply D and x[n] + DG * y[n-d]
	SFTS AC0, #1
	MOV HI(AC0), *AR0				; move y[n] into x[n] = AR0 for next effect to use
	RET
