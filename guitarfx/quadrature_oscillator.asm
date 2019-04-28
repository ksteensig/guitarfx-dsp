k1_address			.set	0x002A2D		;Constant k1
k2_address			.set	0x002A0D		;Constant k2
u0					.set	0x7fff			;
v0					.set 	0x0000


		.sect "temp"
k1		.word 0x1111
k2		.word 0x2222

uv:		.usect "vars", 2

	.global  _oscillator_reset
	.text

_oscillator_reset:
	MOV #u0, *(#uv)							; Setting u = 0.999999
	MOV #v0, *(#uv+1)						; Setting v = 0

_oscillator_inc:
*Store un and vn
	MOV *(#uv) << #16,		AC0				; un 					;Q15 value in upper 16 bits of ACx
	MOV *(#uv+1) << #16,	AC1				; vn					;Q15 value in upper 16 bits of ACx

*Calculate wn
	MPYM *(#k1), AC1, AC2					; k1*vn					;Q15*Q15 = Q30
	SUB	AC2, AC0							; wn = un - k1*vn		;Q15-Q15 = Q15

*Calculate	vn+1
	MPYM *(#k2), AC0, AC2					; k2*wn					;Q15*Q15 = Q30
	ADD	AC2, AC1							; vn+1 = vn + k2*wn		;Q15-Q15 = Q15

*Calculate un+1
	MPYM *(#k1), AC1, AC2					; k1*vn+1				;Q15*Q15=Q30
	SUB	AC2, AC0							; un+1 = wn-k1+vn+1		;Q15-15
*Move Un+1 and Vn+1 to memory
	MOV HI(AC0), *(#uv)
	MOV HI(AC1), *(#uv+1)
