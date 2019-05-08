b0				.set	0x5dc0				; signed Q16,0
a0				.set	0x2ee0				; unsigned Q15,1



bd:					.usect ".vars", 1		;
amp:				.usect ".vars", 1		;Amplitude is unsigned: Q15,1
delay_output:		.usect ".vars", 3,3,3

	.ref oscillator_inc32, un, vn
	;.def
	.text

_flanger_chorus_reset:
	MOV #a0, *(#amp)
	MOV #b0, *(#bd)

* Caluclate M(n) = (amplitude * sin(omeg*n)) + base_delay
delay_calculate: .macro
*Setup to calculate M(n)
	AMOV #un, 			 	XAR0				;Un is Q31
	AMOV #delay_output,		XAR1				;Out is Q15,32

*Calculate product
	AMAR AR0+									; AR1 = LO(out)
	MPYM uns(*AR0-), uns(*(#amp)),AC1			; AC1 = Amp * LO(Un)
	MACM *AR0, uns(*(#amp)), AC1 >> #16, AC1 	; AC1 = Amp * LO(Un) + Amp * HI(Un) *Product: Q16,16
*Calculate sum (basedelay)
	ADD *(#bd), HI(AC1)							; Upper bits is now Base delay, lower is used for interpolation
	MOV AC1, dbl(*AR1)							; Save to memeory
*Post increment Oscillator
	;CALL oscillator_inc32
	.endm


* y[n] = D * (x[n] + G * y[n-M(n)])
flanger_effect:

*First calculate delay M(n) =
