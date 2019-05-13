u0H     	.set 0x7FFF  ; Initial Value
u0L     	.set  0xFFFF  ; Initial Value
v0H     	.set  0x0000   ; Initial Value
v0L     	.set  0x0000  ; Initial Value
K1H     	.set    0x0000  ; Initial Value
K1L     	.set  0x1B73  ; Initial Value
K2H     	.set    0x0000  ; Initial Value
K2L    		.set  0x36E7  ; Initial Value
resetZero   .set 0x0000
; .sect ".ivars"
; .align 2
;K1: .word 0x0000      ;HI(K1) for voice 0
; .word 0xA4B6      ;LO(K1) for voice 0      0x00001B73 = (0,05) 0,1 Hz
; .word 0x0000      ;-- Voice 1
; .word 0x36E7      ;-- Voice 1     0x000036E7 = (0,1) 0,2 Hz
; .word 0x0000      ;-- Voice 2
; .word 0x6DCE      ;-- Voice 2     0x00006DCE = (0,2) 0,4 Hz
; .word 0x0000      ;-- Voice 3
; .word 0xA4B6      ;-- Voice 3
; .word 0x0000      ;-- Voice 4
; .word 0xA4B6      ;-- Voice 4

;K2: .word 0x0000      ;HI(K2) for voice 0
; .word 0xDB9D      ;LO(K2) for voice 0   0x000036E7 = (0,05) 0,1 Hz
; .word 0x0000      ;-- Voice 1
; .word 0x6DCE      ;-- Voice 1     0x00006DCE = (0,1) 0,2 Hz
; .word 0x0000      ;-- Voice 2
; .word 0xDB9D      ;-- Voice 2     0x0000DB9D = (0,2) 0,4 Hz
; .word 0x0001      ;-- Voice 3
; .word 0x496B      ;-- Voice 3
; .word 0x0001      ;-- Voice 4
; .word 0x496B      ;-- Voice 4

;un: .word 0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
; .word 0x7FFF      ;LO(un) Start value for sin(n*w) = 1
; .word 0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
; .word 0x7FFF      ;LO(un) Start value for sin(n*w) = 1
; .word 0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
; .word 0x7FFF      ;LO(un) Start value for sin(n*w) = 1
; .word 0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
; .word 0x7FFF      ;LO(un) Start value for sin(n*w) = 1
; .word 0x7FFF      ;HI(un) Start value for sin(n*w)? = 1
; .word 0x7FFF      ;LO(un) Start value for sin(n*w) = 1

;vn: .word 0x0000      ;HI(vn) Start value for cos(n*w)? = 0
; .word 0x0000      ;LO(vn) Start value for cos(n*w) = 0
; .word 0x0000      ;HI(vn) Start value for cos(n*w)? = 0
; .word 0x0000      ;LO(vn) Start value for cos(n*w) = 0
; .word 0x0000      ;HI(vn) Start value for cos(n*w)? = 0
; .word 0x0000      ;LO(vn) Start value for cos(n*w) = 0
; .word 0x0000      ;HI(vn) Start value for cos(n*w)? = 0
; .word 0x0000      ;LO(vn) Start value for cos(n*w) = 0
; .word 0x0000      ;HI(vn) Start value for cos(n*w)? = 0
; .word 0x0000      ;LO(vn) Start value for cos(n*w) = 0


 ;.def  oscillator_inc32,
 ;.def un, vn,
 ;.def  _oscillator_reset32
 .text
_oscillator_reset32:
; MOV #u0H, *(#un)       ; Setting HI(Un) = 0.999999
; MOV #u0L, *(#un+1)       ; Setting LO(Un) = 999999
; MOV #v0H, *(#vn)       ; Setting HI(vn) = 0
; MOV #v0L, *(#vn+1)       ; Setting LO(Vn) = 0
; MOV #K1H, *(#K1)       ; *Redundant
; MOV #K1L, *(#K1+1)       ; *Redundant
; MOV #K2H, *(#K2)       ; *Redundant
; MOV #K2L, *(#K2+1)       ; *Redundant
 RET

oscillator_inc32: .macro
	 BSET FRCT
	 BSET SATD
*Setup to calculate wn
	 AMOV #vn,   XAR0     ; *Vn is Q31
	 AMOV #K1,  XAR1     ; *K1 is Q31
	 AMOV #un,  XAR2     ; *Un is Q31
	 MOV BRC0, T0       ; Load current voice iteration into T0 to use for offset
	 SFTS T0 , #1       ; Multiply by two because all constants are long word aligned
*Calculate Wn = Un - K1 *Vn
	 AMAR *AR1+        ; Point to LO(K1)
	 MPYM *AR0(T0), uns(*AR1(T0)), AC1    ; AC1 = HI(Vn)*LO(K1)           (SAVE)
	  || ADD #1, AR0
	 SUB #1, AR1
	 MACM uns(*AR0(T0)), *AR1(T0), AC1     ; AC1 = HI(Vn)*LO(K1) + LO(Vn)*Hi(K1)       (ACCUMULATE)
	  || SUB #1, AR0
	 MACM *AR0(T0), *AR1(T0), AC1 >> #16, AC1  ; AC1 = HI(Vn)*LO(K1) + LO(Vn)*Hi(K1) + HI(Vn)*HI(K1)  (ACCUMULATE)
	 SUB AC1, dbl(*AR2(T0)), AC1     ; AC1 = Un - AC1           (SUBSTRACT)
	 MOV AC1, dbl(*AR2(T0))      ; AR2 = Wn (We no longer need Un)
*Setup to calculate Vn+1
	 ; AR0 = HI(Vn)
	 AMOV #K2,  XAR1     ; *K2 is Q31
	 ; AR2 = HI(Wn)
*Calculate Vn+1 = Vn + K2 * Wn
	 AMAR *AR1+        ; Point to LO(K2)
	 MPYM *AR2(T0), uns(*AR1(T0)), AC1    ; AC1 = HI(Wn)*LO(K2)           (SAVE)
	  || ADD #1, AR2
	 SUB #1, AR1
	 MACM uns(*AR2(T0)), *AR1(T0), AC1     ; AC1 = HI(Wn)*LO(K2) + LO(Wn)*Hi(K2)       (ACCUMULATE)
	  || SUB #1, AR2
	 MACM *AR2(T0), *AR1(T0), AC1 >> #16, AC1  ; AC1 = HI(Wn)*LO(K2) + LO(Wn)*Hi(K2) + HI(Wn)*HI(K2)  (ACCUMULATE)
	 ADD dbl(*AR0(T0)), AC1      ; AC1 = Vn + AC1           (SUBSTRACT)
	 MOV AC1, dbl(*AR0(T0))      ; AR0 = Vn+1
*Setup to calculate Un+1
	 ; AR0 = HI(Vn)
	 AMOV #K1,  XAR1     ; *K1 is Q31
	 ; AR2 = HI(Wn)
*Calculate Un+1 = Wn - K1 * Vn+1
	 AMAR *AR1+        ; Point to LO(K1)
	 MPYM *AR0(T0), uns(*AR1(T0)), AC1    ; AC1 = HI(Vn+1)*LO(K2)          (SAVE)
	  || ADD #1, AR0
	 SUB #1, AR1
	 MACM uns(*AR0(T0)), *AR1(T0), AC1     ; AC1 = HI(Vn+1)*LO(K2) + LO(Vn+1)*Hi(K2)      (ACCUMULATE)
	  || SUB #1, AR0
	 MACM *AR0(T0), *AR1(T0), AC1 >> #16, AC1  ; AC1 = HI(Vn+1)*LO(K2) + LO(Vn+1)*Hi(K2) + HI(Vn+1)*HI(K2) (ACCUMULATE)
	 SUB AC1, dbl(*AR2(T0)), AC1     ; AC1 = Wn - AC1           (SUBSTRACT)
	 MOV AC1, dbl(*AR2(T0))      ; AR2 = Un
	 ;MOV HI(AC1), T0
	 BCLR FRCT
	 BCLR SATD
 .endm
