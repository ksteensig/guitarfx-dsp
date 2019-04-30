; Note that this whole ASM file is currently pseudo code

TWO_PI_Q4_11        .set 0011001001000100b
INV_TWO_PI_Q15		.set 0001010001100010b
PI_Q4_11            .set 0001100100100010b

WINDOW_SIZE         .set 1024
INV_WINDOW_SIZE_Q15 .set 0000000000100000b
HOP_SIZE		   	.set 256
INV_HOP_SIZE_Q15    .set 0000000010000000b
STEP_SIZE           .set 1
WINDOW_SCALE_FACTOR .set 0x59BA ; Q15 0.701    ; Constant that comes from sqrt(((WINDOW_SIZE/HOP_SIZE)/2))
DELTA_PHI_CONST     .set 0x00C9 ; Q15 0.00613  ; approx 2pi/WINDOW_SIZE

HANN_WINDOW_START       .set 0x0000 ; TBD but it shall be 1024 big
FFT_BUF_START           .set 0x0000 ; TBD but it shall be 2048 big
MAGNITUDE_FRAME_START   .set 0x0000 ; TBD but it shall be 1024 big
PHASE_FRAME_START       .set 0x0000 ; TBD but it shall be 1024 big
PREV_PHASE_FRAME_START  .set 0x0000 ; TBD but it shall be 1024 big
DELTA_PHI_START         .set 0x0000 ; TBD but it shall be 1024 big
TRUE_FREQ_START         .set 0x0000 ; TBD but it shall be 1024 big
CUMMULATIVE_PHASE_START .set 0x0000 ; TBD but it shall be 1024 big

HOP_OUT                 .set 0x0000 ; TBD but it shall be 1 big
ALPHA                   .set 0x0000 ; TBD but it shall be 1 big

ATAN2_R                 .set 0x0000 ; TBD but it shall be 1024 big
ATAN2_J                 .set 0x0000 ; TBD but it shall be 1024 big

INPUT_RING_BUF  .usect "PITCH_SHIFT_RING_BUF_IN",  1200 ; 5*HOP_SIZE
OUTPUT_RING_BUF .usect "PITCH_SHIFT_RING_BUF_OUT", 2300 ; 7*HOP_SIZE*2^(4/12) rounded up to nearest 100

_cifft_SCALE:
  RET

_cfft_SCALE:
  RET

_sqrt_16:
  RET

_atan16:
  RET

_cbrev32:
  RET

** AC0 = input (Q15.15)
** AC0 = output (Q9.6)					; Modulus has not been finished
_mod_2pi: .macro						; AC0 = AC0 - 2*pi * floor(AC0 * 1/(2*pi))
										; Calculate floor(AC0 * 1/(2*pi))
	MOV AC0, AC1
	MOV AC0, AC2
	AND 0xFFFF8000, AC0					; Zero out lower word
	AND 0x00007FFF, AC1					; Zero out higher word
	SFTS AC1, #16
	MPY #INV_TWO_PI_Q15, AC0
	MPY #INV_TWO_PI_Q15, AC1
	ADD AC1, AC0						; Add results together
	SFTS AC1, #1
	AND 0xFFFF8000, AC0					; Zero out all fractions, which is flooring
	MPY TWO_PI_Q4_11, AC0
	SFTS AC0, #-2
	SUB AC0, AC2
  	.endm

_time_stretch:
  MOV #HANN_WINDOW_START, AR0           ; Need a pointer to the hanning window
  MOV #1023, BRC0                       ; RTPBLOCAL will loop BRC0+1 times

  RPTBLOCAL ps_loop1_end                ; Loop with WINDOW_SIZE iterations to move new window into work buffer
  MOV *AR4, AC0                         ; Assume AR4 is the input FFT_BUF
  MOV *AR0+, AC1
										; Window the sample
  SFTS AC0, #16
  MPY AC1, AC0
  SFTS AC0, #1
  MPY #WINDOW_SCALE_FACTOR, AC0
  SFTS AC0, #-15

  MOV AC0, *AR4+						; Move windowed sample back into FFT buffer
ps_loop1_end: ADD #1, AR4				; Every other sample in the FFT buffer is imaginary, so this is skipped

                                        ; FFT the frame
  SUB #2048, AR4						; Go back to beginning of the FFT buffer
  MOV #1024, T0							; Use 1024-point FFT
  CALL _cfft_SCALE                      ; Best performance with twiddle in ROM and FFT_BUF in DARAM
  CALL _cbrev32							; bit reverse, there is enough computation for this

                                        ; Calculate magnitude frame, which is the abs() of each value in the FFT buffer
  MOV #MAGNITUDE_FRAME_START, AR0		; Create pointer to magnitude frame
  MOV #1023, BRC0						; Loop 1024 times over magnitude frame
  RPTBLOCAL mag_frame_loop_end
  MOV *AR4+, AC0						; Move real part of the FFT buffer into AC0
  MOV *AR4+, AC1						; Move imaginary part of the FFT buffer into AC1

  SQR AC0								; Square both the real and imaginary
  SQR AC1
  SFTS AC0, #-15
  SFTS AC1, #-15

  ADD AC1, AC0							; Add the squared real and squared imaginary
mag_frame_loop_end: MOV AC0, *AR0+
  CALL _sqrt_16                         ; Call sqrt on all magnitude frame members, this finishes the abs()

                                        ; Calculate the phase frame, the angles for each sample
                                        ; This is done by doing atan2(j/r)
  MOV #ATAN2_R, AR0						; Make pointer to buffer where all real FFT values can be copied into
  MOV #ATAN2_J, AR1						; Make pointer to buffer where all imaginary FFT values can be copied into
  SUB #2048, AR4						; Go back to beginning of FFT buffer
  MOV #1023, BRC0                       ; Iterate 1024 times
  RPTBLOCAL ps_loop2_end
  MOV *AR4+, *AR0+						; Copy real sample into real buffer
ps_loop2_end: MOV *AR4+, *AR1+			; Copy imaginary sample into imaginary buffer
  MOV #ATAN2_R, AR0                     ; Set pointers back to beginning
  MOV #ATAN2_J, AR1
  MOV #PHASE_FRAME_START, AR2
  MOV #1024, T0
  CALL _atan16							; Calculate the phase by using atan

                                        ; Calculate delta phi
  MOV 1023, BRC0						; Loop 1024 times
  MOV #DELTA_PHI_START, AR0				; Make pointer to delta phi buffer
  MOV #PHASE_FRAME_START, AR1			; Make pointer to phase frame buffer
  MOV #PREV_PHASE_FRAME_START, AR2		; Make pointer to last iteration's phase frame buffer
  MOV #0, T1							; Start index counter

  RPTBLOCAL ps_loop3_end
  										  ; SFTS the following block at some point
  MOV T1, AC0							  ; AC0 = i
  										  ; Calculate delta phi itself
  SFTS AC0, #15
  ADD #1, T1
  MPY #DELTA_PHI_CONST, AC0
  SFTS AC0, #1
  MPY #HOP_SIZE, AC0
  SFTS AC0, #1
  NEG AC0
  MOV *AR1, AC1
  SFTS AC1, #10
  ADD AC1, AC0
  MOV *AR2, AC1
  SFTS AC1, #10
  SUB AC1, AC0

  										   ; Ensure -pi < delta phi < pi
  MOV #PI_Q4_11, AC1
  SFTS AC1, #5
  ADD AC1, AC0
  _mod_2pi								   ; ((delta phi + pi) mod 2pi) - pi
  MOV #PI_Q4_11, AC1
  SFTS AC1, #5
  SUB AC1, AC0
  SFTS AC0, #10
  MOV AC0, *AR0+
ps_loop3_end: MOV *AR1+, *AR2+
										; Calculate the true frequency
  MOV #1023, BRC0						; Loop 1024 times
  SUB 1024, AR0                         ; Go back to beginning of delta phi vector
  MOV #TRUE_FREQ_START, AR1				; Get pointer to true frequency
  MOV #0, T1	                        ; Go back to beginning of the index
  
  RPTBLOCAL ps_loop4_end
  MOV #DELTA_PHI_CONST, AC0
  SFTS AC0, #16
  MPY #INV_HOP_SIZE_Q15, AC0
  SFTS AC0, #1
  MOV *AR0+, AC1
  MPY #INV_HOP_SIZE_Q15, AC1
  ADD AC1, AC0
ps_loop4_end: MOV AC1, *AR1+

                                        ; Calculate the cumulative phase
  MOV #1023, BRC0
  MOV #CUMMULATIVE_PHASE_START, AR0
  SUB #1024, AR1                        ; Go back to beginning of true freq vector
  MOV #HOP_OUT, AR2
  RPTBLOCAL ps_loop5_end
  MOV *AR2, AC0
  MPY *AR1+, AC0
  MOV AC0, T0
  _mod_2pi
ps_loop5_end: MOV T1, *AR0+
                                        ; Phase shift the FFT'd buffer, assume AR7 points at sine wave
                                        ; This has not been implemented yet
  MOV #1023, BRC0
  SUB #1024, AR0                        ; Go back to beginning of cummulative phase
  SUB #2048, AR4                        ; Go back to beginning of the FFT buffer

  RPTBLOCAL ps_loop6_end
  ;MOV *AR0+, T0
  ;MOV *AR7(T0), 
ps_loop6_end: NOP
                                        ; IFFT
  MOV #FFT_BUF_START, AR0
  MOV #1024, T0
  CALL _cifft_SCALE
                                        ; Hann window the result
  MOV #1023, BRC0
  SUB #2048, AR4
  MOV #HANN_WINDOW_START, AR0

  RPTBLOCAL ps_loop7_end
  MOV *AR4+, AC0
  MPY *AR0+, AC0
  MPY #WINDOW_SCALE_FACTOR, AC0
  MPY #INV_WINDOW_SIZE_Q15, AC0
  ADD *AR7, AC0
ps_loop7_end: MOV AC0, *AR7+
                                        ; Zero old values so it won't keep accumulating
  MOV #HOP_OUT, BRC0
  RPTBLOCAL ps_loop8_end
ps_loop8_end: MOV #0, *AR7+

  SUB #WINDOW_SIZE, AR7                 ; Only subtract the window size, so it will have kipped hop out size
  RET

_resample:
  MOV #HOP_OUT, AC0
  MPY #4, AC0
  SUB AC0, AR7

  MOV #1023, BRC0
  ; Make AR0 point at the output buffer
  RPTBLOCAL ps_loop9_end
  MOV *AR7+, AC1
  MOV *AR7+, AC0
  SUB AC1, AC0
  MPY #ALPHA, AC1
  ADD AC1, AC0
  MOV AC0, *AR0+
ps_loop9_end: SUB #1, AR7               ; Go one back so it will only loop 1024 times over AR7

  MOV HOP_OUT, AC0
  MPY #4, AC0
  ADD AC0, AR7
  RET
