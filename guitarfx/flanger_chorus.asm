 .copy "oscillator_32bit.asm"
;b0     .set 0x03e8    ; signed Q16,0
;a0     .set 0x07d0    ; unsigned Q15,1
;resetZero   	.set 0x0000
direct_path   	.set 0x6666
feedback_path  	.set 0x9000
ADCR    		.set 0x002A2D
voices    		.set 0x0002

		.sect  ".ivars"      ;Feedback Gain: Q15
 		.align 2
K1:		.word 0x0000      ;HI(K1) for voice 0
 		.word 0x1B73      ;LO(K1) for voice 0      0x00001B73 = (0,05) 0,1 Hz
		.word 0x0000      ;-- Voice 1
		.word 0x1B73      ;-- Voice 1     0x000036E7 = (0,1) 0,2 Hz
		.word 0x0000      ;-- Voice 2
		.word 0x1B73      ;-- Voice 2     0x00006DCE = (0,2) 0,4 Hz
		.word 0x0000      ;-- Voice 3
		.word 0xA4B6      ;-- Voice 3      0x00011284 = (0,5) 1 Hz
		.word 0x0000      ;-- Voice 4
		.word 0xA4B6      ;-- Voice 4

		.align 2
K2: 	.word 0x0000      ;HI(K2) for voice 0
		.word 0x36E7      ;LO(K2) for voice 0   0x000036E7 = (0,05) 0,1 Hz
		.word 0x0000      ;-- Voice 1
		.word 0x36E7      ;-- Voice 1     0x00006DCE = (0,1) 0,2 Hz
		.word 0x0000      ;-- Voice 2
		.word 0x36E7      ;-- Voice 2     0x0000DB9D = (0,2) 0,4 Hz
		.word 0x0001      ;-- Voice 3
		.word 0x496B      ;-- Voice 3     0x00022508 = (0,5) 1 Hz
		.word 0x0001      ;-- Voice 4
		.word 0x496B      ;-- Voice 4

 		.align 2
un: 	.word 	0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
		.word 	0xFFFF      ;LO(un) Start value for sin(n*w) = 1
		.word	0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
		.word 	0xFFFF      ;LO(un) Start value for sin(n*w) = 1
		.word 	0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
		.word 	0xFFFF      ;LO(un) Start value for sin(n*w) = 1
		.word 	0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
		.word 	0xFFFF      ;LO(un) Start value for sin(n*w) = 1
		.word 	0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
		.word 	0xFFFF      ;LO(un) Start value for sin(n*w) = 1

		.align 2
vn: 	.word 	0x0000      ;HI(vn) Start value for cos(n*w)? = 0
		.word 	0x0000      ;LO(vn) Start value for cos(n*w) = 0
		.word 	0x0000      ;HI(vn) Start value for cos(n*w)? = 0
		.word 	0x0000      ;LO(vn) Start value for cos(n*w) = 0
		.word 	0x0000      ;HI(vn) Start value for cos(n*w)? = 0
		.word 	0x0000      ;LO(vn) Start value for cos(n*w) = 0
		.word 	0x0000      ;HI(vn) Start value for cos(n*w)? = 0
		.word 	0x0000      ;LO(vn) Start value for cos(n*w) = 0
		.word 	0x0000      ;HI(vn) Start value for cos(n*w)? = 0
		.word 	0x0000      ;LO(vn) Start value for cos(n*w) = 0

 		.align 2
F: 		.word 	0x2333
		.word 	0x2333
		.word 	0x2333
		.word 	0x0000
		.word 	0x0000

 		.align 2
bd:	 	.word	0x0FFF 		; Base delay is signed: Q16,0
		.word 	0x0000 		; It is necessary to have long word alignment for delay calculate to work, therefore zero padding is used.
		.word 	0x0FFF
		.word 	0x0000
		.word 	0x0FFF
		.word 	0x0000
		.word 	0x0FFF
		.word 	0x0000
		.word 	0x7FFF

		.align 2
amp:	.word 	0x0FFF		; Amplitude is unsigned: Q15,1
		.word 	0x0000 		; It is necessary to have long word alignment for delay calculate to work, therefore zero padding is used.
		.word 	0x0FFF
		.word 	0x0000
		.word 	0x0FFF
		.word 	0x0000
		.word 	0x0FFF
		.word 	0x0000

G:     					.usect ".vars", 1       	;Forward Gain: Q15
delay_output:  			.usect ".vars", 2,2,2
interpol:   			.usect ".vars", 1  			;Needed so we are able to do a unsigned multiplication
noise_shaping:  		.usect ".vars", 1
aditional_voices: 		.usect ".vars", 1
		;.ref oscillator_inc32,
		;.ref un, vn
		.ref xn
		.def _flanger_chorus_reset, _flanger_effect, _chorus_effect, _oscillator_reset32
		.text

_flanger_chorus_reset:
	;MOV #a0, *(#amp)
	;MOV #b0, *(#bd)
	MOV #direct_path, *(#G)
	;MOV #feedback_path, *(#F)
	MOV #resetZero, *(#delay_output)
	MOV #resetZero, *(#delay_output+1)
	MOV #resetZero, *(#noise_shaping)
	MOV #voices, *(#aditional_voices)

* Caluclate M(n) = (amplitude * sin(omeg*n)) + base_delay
delay_calculate: .macro
*Setup to calculate M(n)
	MOV BRC0, T0
	SFTS T0, #1         							;Un is long word aligned, thus amp had to be long word aligned to make the addressing offset long word aligned
	AMOV #un,      XAR0    							;Un is Q31
	AMOV #delay_output,  XAR1    					;Out is Q15,32
	AMOV #amp,    XAR2
	AMOV #bd,    XAR3
*Calculate product
	AMAR *AR0+         								;AR1 = LO(out)
	MPYM uns(*AR0(T0)), uns(*AR2(T0)), AC1    		;AC1 = Amp * LO(Un)
	|| SUB #1, AR0
	MACM *AR0(T0), uns(*AR2(T0)), AC1 >> #16, AC1   ;AC1 = Amp * LO(Un) + Amp * HI(Un) *Product: Q16,16
*Calculate sum (basedelay)
	ADD *AR3(T0) << #16, AC1      					;Upper bits is now Base delay, lower is used for interpolation
	MOV AC1, dbl(*AR1)       						;Save to memeory
	.endm

* y[n] = D * (x[n] + G * y[n-M(n)])
_flanger_effect:
*Pre increment Oscillator
	;CALL oscillator_inc32
	MOV #0, BRC0          							;Needed to make the oscillator run on voice 0, probably redundant loops leave BRC0 = 0
	oscillator_inc32
*The flanger effect relys on a sin delay
	delay_calculate
*Setup to find a
	; y[n] = *AR6
	MOV *(#delay_output), T0      					;FLOOR(M(n))
*Calculate a = y[n-FLOOR(M(n))] - y[n-FLOOR(M(n))-1] ; HAR ÆNDRET INTERPOLATION, TROR VI REGNEDE Y1-Y2 FØR, NU SKULLE DET GERNE VÆRE Y2-Y1, MEN TJEK EFTER!
	SUB #1, T0
	MOV *AR6(T0), AC0 					            ;AC0 = y[n-FLOOR(M(n))]
	ADD #1, T0           							;Modify AR6 offset
	SUB *AR6(T0), AC0         						;AC0 = y[n-FLOOR(M(n))] - y[n-FLOOR(M(n))-1]
	MOV AC0, *(#interpol)
*Setup to interpolate
	AMOV #delay_output+1,  XAR0
	AMOV #interpol,   XAR1
*Interpolate a*LO(delayOutput)+y[n-FLOOR(M(n))]
	MPYM uns(*AR0), *AR1, AC0       				;AC0 = a*LO(delayOutput), LO(delayOutput) = fractional part
	SUB #1, T0           							;Reset T0 to point at y[n-FLOOR(M(n))]
	ADD *AR6(T0) << #16, AC0       					;AC0 = a*LO(delayOutput)+y[n-FLOOR(M(n))]
*Setup for flanger effect
	; AC0 = y[n-M(n)]
	AMOV #xn, XAR1
* Calculate flanger effect: y[n] = G * (x[n] + F * y[n-M(n)])
	BSET FRCT
	MPYM *(#F), AC0
	ADD *AR1 << #16, AC0
	MPYM *(#G), AC0
	ADD *(#noise_shaping), AC0       				;ADD noise shaping
	MOV HI(AC0), *AR1
	MOV AC0, *(#noise_shaping)       				;Save noise for next repetition
	BCLR FRCT
	RET


_chorus_effect:
*Post increment Oscillator
	MOV #0, AC3           							;Zero AC3 so initial sum is 0 + voice(BRC0)
	AMOV #F, XAR4          							;AR4 points to first feedback gain
	MOV *(#aditional_voices), BRC0      			;Loop *(#aditional_voices)+1
	RPTB END          								;Loop everything until lable END, TOO MANY BYTES FOR LOCAL
	oscillator_inc32        						;Calculate sine value for voice(BRC0)
*The chorus effect relys on a sin delay
	delay_calculate
*Setup to find a
	; y[n] = *AR6
	MOV *(#delay_output), T0       					;FLOOR(M(n))
*Calculate a = y[n-FLOOR(M(n))] - y[n-FLOOR(M(n))-1]
	MOV *AR6(T0), AC0     				         	;AC0 = y[n-FLOOR(M(n))]
	ADD #1, T0           							;Modify AR6 offset
	SUB *AR6(T0), AC0      							;AC0 = y[n-FLOOR(M(n))] - y[n-FLOOR(M(n))-1]
	MOV AC0, *(#interpol)
*Setup to interpolate
	AMOV #delay_output+1,  XAR0
	AMOV #interpol,   XAR1
*Interpolate a*LO(delayOutput)+y[n-FLOOR(M(n))]
	MPYM uns(*AR0), *AR1, AC0       				;AC0 = a*LO(delayOutput), LO(delayOutput) = fractional part
	SUB #1, T0           							;Reset T0 to point at y[n-FLOOR(M(n))]
	ADD *AR6(T0) << #16, AC0       					;AC0 = a*LO(delayOutput)+y[n-FLOOR(M(n))]
	MOV BRC0, T0
	MPYM *AR4(T0), AC0         						;Multiply with feedback gain for each voice
END ADD AC0 << #1, AC3         						;Sum output of all voices

	AMOV #xn, XAR1
	MOV *(#G), T1
	ADD *AR1 << #16, AC3
	MACM *AR1, T1, AC3
	SFTS AC3, #1
	ADD *(#noise_shaping), AC3       				;ADD noise shaping
	MOV HI(AC3), *AR1
	MOV AC3, *(#noise_shaping)       				;Save noise for next repetition
	RET
