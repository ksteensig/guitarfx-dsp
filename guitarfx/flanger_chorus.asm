b0					.set	0x03e8				; signed Q16,0
a0					.set	0x07d0				; unsigned Q15,1
resetZero			.set	0x0000
direct_path			.set	0x4000
feedback_path		.set	0x6000
ADCR				.set	0x002A2D

G:					.usect ".vars", 1       ;Forward Gain: Q15
F:					.usect ".vars", 1		;Feedback Gain: Q15
bd:					.usect ".vars", 1		;Base delay is signed: Q16,0
amp:				.usect ".vars", 1		;Amplitude is unsigned: Q15,1
delay_output:		.usect ".vars", 2,2,2
interpol:			.usect ".vars", 1		;Needed so we are able to do a unsigned multiplication
noise_shaping:		.usect ".vars", 1


	.ref oscillator_inc32, un, vn, xn
	.def _flanger_chorus_reset, _flanger_effect
	.text

_flanger_chorus_reset:
	MOV #a0, *(#amp)
	MOV #b0, *(#bd)
	MOV #direct_path, *(#G)
	MOV #feedback_path, *(#F)
	MOV #resetZero, *(#delay_output)
	MOV #resetZero, *(#delay_output+1)
	MOV #resetZero, *(#noise_shaping)

* Caluclate M(n) = (amplitude * sin(omeg*n)) + base_delay
delay_calculate:
*Setup to calculate M(n)
	AMOV #un, 			 	XAR0				;Un is Q31
	AMOV #delay_output,		XAR1				;Out is Q15,32
	AMOV #amp,				XAR2
*Calculate product
	AMAR *AR0+									; AR1 = LO(out)
	MPYM uns(*AR0-), uns(*AR2), AC1				; AC1 = Amp * LO(Un)
	MACM *AR0, uns(*AR2), AC1 >> #16, AC1 		; AC1 = Amp * LO(Un) + Amp * HI(Un) *Product: Q16,16
*Calculate sum (basedelay)
	ADD *(#bd) << #16, AC1						; Upper bits is now Base delay, lower is used for interpolation
	MOV AC1, dbl(*AR1)							; Save to memeory
*Post increment Oscillator
	CALL oscillator_inc32
	RET

* y[n] = D * (x[n] + G * y[n-M(n)])
_flanger_effect:
*The flanger effect relys on a sin delay
	CALL delay_calculate

*Setup to find a
	; y[n] = *AR6
	MOV *(#delay_output), T0							;FLOOR(M(n))
*Calculate a = y[n-FLOOR(M(n))] - y[n-FLOOR(M(n))-1]
	MOV *AR6(T0), AC0  						    		;AC0 = y[n-FLOOR(M(n))]
	ADD #1, T0											;Modify AR6 offset
	SUB *AR6(T0), AC0									;AC0 = y[n-FLOOR(M(n))] - y[n-FLOOR(M(n))-1]
	MOV AC0, *(#interpol)

*Setup to interpolate
	AMOV #delay_output+1, 	XAR0
	AMOV #interpol, 		XAR1
*Interpolate a*LO(delayOutput)+y[n-FLOOR(M(n))]
	MPYM uns(*AR0), *AR1, AC0							;AC0 = a*LO(delayOutput), LO(delayOutput) = fractional part
	SUB #1, T0											;Reset T0 to point at y[n-FLOOR(M(n))]
	ADD *AR6(T0) << #16, AC0							;AC0 = a*LO(delayOutput)+y[n-FLOOR(M(n))]

*Setup for flanger effect
	; AC0 = y[n-M(n)]
	AMOV #xn, XAR1
* Calculate flanger effect: y[n] = G * (x[n] + F * y[n-M(n)])
	BSET FRCT
	MPYM *(#F), AC0
	ADD *AR1 << #16, AC0
 	MPYM *(#G), AC0
	;ADD *(#noise_shaping), AC0							; ADD noise shaping
	MOV HI(AC0), *AR1
	;MOV AC0, *(#noise_shaping)							; Save noise for next repetition
	BCLR FRCT
	RET
