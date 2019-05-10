u0H					.set	0x7FFF		; Initial Value
u0L					.set 	0xFFFF		; Initial Value
v0H					.set 	0x0000 		; Initial Value
v0L					.set 	0x0000		; Initial Value
k1H					.set    0x0000		; Initial Value
k1L					.set 	0xa4b6		; Initial Value
k2H					.set    0x0001		; Initial Value
k2L					.set 	0x496b		; Initial Value
resetZero			.set	0x0000

k1:		.usect ".vars", 2,2,2
k2:		.usect ".vars", 2,2,2
un:		.usect ".vars", 2,2,2
vn:		.usect ".vars", 2,2,2
out:	.usect ".vars", 2,2,2


	.def  oscillator_inc32,  _oscillator_reset32, un, vn
	.text

_oscillator_reset32:
	MOV #u0H, *(#un)							; Setting HI(Un) = 0.999999
	MOV #u0L, *(#un+1)							; Setting LO(Un) = 999999
	MOV #v0H, *(#vn)							; Setting HI(vn) = 0
	MOV #v0L, *(#vn+1)							; Setting LO(Vn) = 0
	MOV #k1H, *(#k1)							; *Redundant
	MOV #k1L, *(#k1+1)							; *Redundant
	MOV #k2H, *(#k2)							; *Redundant
	MOV #k2L, *(#k2+1)							; *Redundant
	MOV #resetZero, *(#out)						; *Redundant
	MOV #resetZero, *(#out+1)					; *Redundant
	RET



oscillator_inc32:
	BSET FRCT
	BSET SATD
*Setup to calculate wn
	AMOV #vn, 		XAR0					; *Vn is Q31
	AMOV #k1,		XAR1					; *K1 is Q31
	AMOV #un,		XAR2					; *Un is Q31

*Calculate Wn = Un - K1 *Vn
	AMAR *AR1+								; Point to LO(K1)
	MPYM *AR0+, uns(*AR1-), AC1				; AC1 = HI(Vn)*LO(K1) 										(SAVE)
	MACM uns(*AR0-), *AR1, AC1 				; AC1 = HI(Vn)*LO(K1) + LO(Vn)*Hi(K1) 						(ACCUMULATE)
	MACM *AR0, *AR1, AC1 >> #16, AC1		; AC1 = HI(Vn)*LO(K1) + LO(Vn)*Hi(K1) + HI(Vn)*HI(K1)		(ACCUMULATE)
	SUB AC1, dbl(*AR2), AC1					; AC1 = Un - AC1											(SUBSTRACT)
	MOV AC1, dbl(*AR2)						; AR2 = Wn (We no longer need Un)

*Setup to calculate Vn+1
	; AR0 = HI(Vn)
	AMOV #k2,		XAR1					; *K2 is Q31
	; AR2 = HI(Wn)

*Calculate Vn+1 = Vn + K2 * Wn
	AMAR *AR1+								; Point to LO(K2)
	MPYM *AR2+, uns(*AR1-), AC1				; AC1 = HI(Wn)*LO(K2) 										(SAVE)
	MACM uns(*AR2-), *AR1, AC1 				; AC1 = HI(Wn)*LO(K2) + LO(Wn)*Hi(K2) 						(ACCUMULATE)
	MACM *AR2, *AR1, AC1 >> #16, AC1		; AC1 = HI(Wn)*LO(K2) + LO(Wn)*Hi(K2) + HI(Wn)*HI(K2)		(ACCUMULATE)
	ADD dbl(*AR0), AC1						; AC1 = Vn + AC1											(SUBSTRACT)
	MOV AC1, dbl(*AR0)						; AR0 = Vn+1

*Setup to calculate Un+1
	; AR0 = HI(Vn)
	AMOV #k1,		XAR1					; *K1 is Q31
	; AR2 = HI(Wn)

*Calculate Un+1 = Wn - K1 * Vn+1
	AMAR *AR1+								; Point to LO(K1)
	MPYM *AR0+, uns(*AR1-), AC1				; AC1 = HI(Vn+1)*LO(K2) 									(SAVE)
	MACM uns(*AR0-), *AR1, AC1 				; AC1 = HI(Vn+1)*LO(K2) + LO(Vn+1)*Hi(K2) 					(ACCUMULATE)
	MACM *AR0, *AR1, AC1 >> #16, AC1		; AC1 = HI(Vn+1)*LO(K2) + LO(Vn+1)*Hi(K2) + HI(Vn+1)*HI(K2)	(ACCUMULATE)
	SUB AC1, dbl(*AR2), AC1					; AC1 = Wn - AC1											(SUBSTRACT)
	MOV AC1, dbl(*AR2)						; AR2 = Un

	;MOV HI(AC1), T0
	BCLR FRCT
	BCLR SATD
	RET
