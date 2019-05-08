*********************************************************************************
* This file contains all assembly code used for setting up communications.      *
* The file does:																*
*	- Initialize section - "COM_CONFIG_DMA_SEC", for use in DMA input routine   *
*	- Return the address of COM_CONFIG_DMA_SEC, call get_config_dma_address		*
*********************************************************************************
					.global _get_config_dma_address, _coms_isr
					.def COM_CONFIG_DMA_SEC
COM_CONFIG_DMA_SEC  .usect "COM_CONFIG_DMA_SEC", 0x1000

	.text

_get_config_dma_address:
	MOV #COM_CONFIG_DMA_SEC, AC0 		; Moves address of section into AC0.
	RET


_coms_isr:
	OR #0000100000000000b, mmap(ST1)	; DISABLE INTERRUPTS GLOBALLY!

	;AND 0111111111111111b, port(#001C0Ah) ; Something with LEDS
	;OR 1110000000000000b, port(#001C0Ah)  ; Also something with LEDS


	MOV #COM_CONFIG_DMA_SEC, AC0 		; Moves address of section into AC0
	MOV AC0, XAR0						; XAR0 now contains first entry from DMA
	ADD #200h, AC0						; Add 512 word offset.
	MOV AC0, XAR1						; XAR1 now contains desired destination of first two DMA entries
	; Sorting follows:
	; 	AR0 is temporary pointer
	; 	AR1 is destination pointer
	; 	AR0 should increment with 1 before loop, this is to get lower part of doubleword. (16-bit)
	; 	T0 = *AR0 						; (T0 now contains 8-empty-MSB and 8-LSB)
	;		Shift T0 8 left				; To get the first byte into MSB
	; 	AR0 = AR0 + 2					; To point to the next byte (THESE COULD BE SPLIT UP BETWEEN INSTRUCTIONS
	MOV #127, BRC0						; Initiate loop counter
	ADD #1, AR0							; Make sure we offset the pointer to actually point to 16-LSB of DMA D-Words.
	; LOOP
	RPTBLOCAL sorter-1
	MOV *AR0+, AC0						; Save first value in AC0, AR0 now points to 16-MSB of next DMA D-Word.
	SFTS AC0, #8						; Shift the 8-LSB into the 8-MSB (can only be done in Accumulator)
	MOV AC0, T0							; Move to remp register
	ADD #1, AR0							; Point to second byte
	MOV *AR0+, T1						; First increment AR0 to point to 16-LSB of next DMA D-word. Then save to T1
	ADD #1, AR0							; Point to second byte
	OR T1, T0							; Merge first and second byte
	MOV T0, *AR1+
sorter
	; ENDLOOP


	AND #1111011111111111b, mmap(ST1)	; ENABLE INTERRUPTS GLOBALLY!
	RETI



	;MOV #COM_CONFIG_DMA_SEC, AC0 	; Moves address of section into AC0
	;ADD #8000h, AC0					; Add 10000h to offset DARAM
	;SFTS AC0, #1					; Shift left to make word address -> byte address
	;MOV AC0, XAR0					; Move to auxillary register for pointer usage.
