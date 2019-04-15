DACR	.set	002A0Dh
ADCR	.set	002A2Dh
D		.set	10000h
DG		.set	0010000000000000b
BUFF	.usect	"BUFFER", 14063

	;.global DACR, ADCR, D, DG, BUFF, _ringBuffer, _echoUpdate
	.global _echoUpdate, _ringBuffer
	.text
**********************************************************************
* _ringBuffer
*	Sets up a ringbuffer for use in AR6 and AR7.
*	Takes paramters:
*		Array consisting of [Buffer Size, Start Address(23)]
**********************************************************************
_ringBuffer:
	MOV D, BK47 		; set buffer size
	MOV BUFF, BSA67		; set start address
	BSET AR6LC
	RET

_echoUpdate:
	MOV *AR6(-D), AC0
	MPYK DG, AC0, AC0
	ADD AR0, AC0
	MOV AC0, *AR6+
	MOV AC0, AR0
