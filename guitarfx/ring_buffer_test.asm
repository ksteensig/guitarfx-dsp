.text
.global DACR, ADCR, D, DG, BUFF, _ringBuffer, _echoUpdate

DACR	.set	002A09h				; DAC Write Register Extended Address
ADCR	.set	002A29h				; ADC Read Register Extended Address
D		.set	10000h				; Delay (Hardcoded for now)
DG		.set	0010000000000000b	; Delay Gain = 0.5 in Q14 format
BUFF	.usect	"BUFFER", 14063		; Create Buffer section (uninitialized) called BUFFER with symbol BUFF


**********************************************************************
* _ringBuffer
*	Sets up a ringbuffer for use in AR6 and AR7.
*	Takes paramters:
*		Array consisting of [Buffer Size, Start Address(23)]
**********************************************************************
_ringBuffer:

	MOV *AR0+, BK47					; Buffer Size Register
	BSET AR6LC						; enables circular adressing
	BSET AR7LC						; enables circular adressing
	AMOV *AR0, XAR6					; Insert Page pointer for AR6
	AMOV *AR0, XAR7					; Insert Page pointer for AR7
	MOV AR6, BSA67 					; Buffer Start Adress Register
	RET


_echoUpdate:
		MOV *AR6+, DACR ; Gem sample i ringbuffer
		MPYM DG, *AR6(-D), *AR6
		ADD ADCR, *AR6
