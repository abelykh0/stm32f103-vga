.syntax unified

@ Arguments:
@  r0  uint8_t*  pix
@  r1  uint32_t* attr_base - address of attribute definitions
@  r2  uint8_t*  attr - attributes
@  r3  uint8_t*  odr
.section .text.vga_draw_impl,"ax",%progbits
.balign 4
.global vga_draw_impl
.thumb_func
vga_draw_impl:
	@ parameters
	pix         .req r0
	attr_base   .req r1
	attr        .req r2
	odr         .req r3

	@ variables
	pixels      .req r4
	attr_addr   .req r5
	attr_offset .req r6
	tmp1        .req r7
	tmp2        .req r8

	push {r4, r5, r6}          @ 4


	@ prepare
	ldr pixels, [pix], #4
	ror pixels, #30
	and attr_offset, pixels, #60
	ldrb attr_addr, [attr], #1
	and attr_addr, attr_base, attr_addr, LSR #6

	.rept 8
		@ character 0

		ldr tmp1, [attr_addr, attr_offset]          @ 2*
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
		ror pixels, #28                             @ 1
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
		and attr_offset, pixels, #60                @ 1
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
 		ldr tmp2, [attr_addr, attr_offset]          @ 1*
		strb tmp1, [odr]                            @ 2

		ror pixels, #28                             @ 1
		ldrb attr_addr, [attr], #1                  @ 1*
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		and attr_addr, attr_base, attr_addr, LSR #6 @ 1
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		ror pixels, #28                             @ 1
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		and attr_offset, pixels, #60                @ 1
		strb tmp2, [odr]                            @ 2

		@ character 1

		ror pixels, #28                             @ 1
		and attr_offset, pixels, #60                @ 1
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
 		ldr tmp2, [attr_addr, attr_offset]          @ 1*
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
		ror pixels, #28                             @ 1
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
		ldr attr_addr, [attr], #1                   @ 1*
		strb tmp1, [odr]                            @ 2

		nop                                         @ 1
		nop                                         @ 1
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		and attr_addr, attr_base, attr_addr, LSR #6 @ 1
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		and attr_offset, pixels, #60                @ 1
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		ldr tmp1, [attr_addr, attr_offset]          @ 1*
		strb tmp2, [odr]                            @ 2

		@ character 2

		ror pixels, #28                             @ 1
		and attr_offset, pixels, #60                @ 1
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
 		ldr tmp2, [attr_addr, attr_offset]          @ 1*
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
		ror pixels, #28                             @ 1
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
		ldr attr_addr, [attr], #1                   @ 1*
		strb tmp1, [odr]                            @ 2

		nop                                         @ 1
		nop                                         @ 1
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		and attr_addr, attr_base, attr_addr, LSR #6 @ 1
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		and attr_offset, pixels, #60                @ 1
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		ldr tmp1, [attr_addr, attr_offset]          @ 1*
		strb tmp2, [odr]                            @ 2

		@ character 3

		ror pixels, #28                             @ 1
		and attr_offset, pixels, #60                @ 1
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
 		ldr tmp2, [attr_addr, attr_offset]          @ 1*
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
		ror pixels, #28                             @ 1
		strb tmp1, [odr]                            @ 2

		ror tmp1, #8                                @ 1
		ldr attr_addr, [attr], #1                   @ 1*
		strb tmp1, [odr]                            @ 2

		and attr_addr, attr_base, attr_addr, LSR #6 @ 1
		nop                                         @ 1
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		ldr pixels, [pix], #4                       @ 1* load next 4 bytes
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		ror pixels, #30                             @ 1  first time << 2
		strb tmp2, [odr]                            @ 2

		ror tmp2, #8                                @ 1
		and attr_offset, pixels, #60                @ 1
		strb tmp2, [odr]                            @ 2
	.endr

	@ character 34

	ldr tmp1, [attr_addr, attr_offset]          @ 2*
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ror pixels, #28                             @ 1
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	and attr_offset, pixels, #60                @ 1
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ldr tmp2, [attr_addr, attr_offset]          @ 1*
	strb tmp1, [odr]                            @ 2

	ror pixels, #28                             @ 1
	ldrb attr_addr, [attr], #1                  @ 1*
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	and attr_addr, attr_base, attr_addr, LSR #6 @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	ror pixels, #28                             @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	and attr_offset, pixels, #60                @ 1
	strb tmp2, [odr]                            @ 2

	@ character 35

	ror pixels, #28                             @ 1
	and attr_offset, pixels, #60                @ 1
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ldr tmp2, [attr_addr, attr_offset]          @ 1*
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ror pixels, #28                             @ 1
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ldr attr_addr, [attr], #1                   @ 1*
	strb tmp1, [odr]                            @ 2

	nop                                         @ 1
	nop                                         @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	and attr_addr, attr_base, attr_addr, LSR #6 @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	and attr_offset, pixels, #60                @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	ldr tmp1, [attr_addr, attr_offset]          @ 1*
	strb tmp2, [odr]                            @ 2

	@ character 36

	ror pixels, #28                             @ 1
	and attr_offset, pixels, #60                @ 1
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ldr tmp2, [attr_addr, attr_offset]          @ 1*
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ror pixels, #28                             @ 1
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ldr attr_addr, [attr], #1                   @ 1*
	strb tmp1, [odr]                            @ 2

	nop                                         @ 1
	nop                                         @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	and attr_addr, attr_base, attr_addr, LSR #6 @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	and attr_offset, pixels, #60                @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	ldr tmp1, [attr_addr, attr_offset]          @ 1*
	strb tmp2, [odr]                            @ 2

	@ character 37

	ror pixels, #28                             @ 1
	and attr_offset, pixels, #60                @ 1
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ldr tmp2, [attr_addr, attr_offset]          @ 1*
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	ror pixels, #28                             @ 1
	strb tmp1, [odr]                            @ 2

	ror tmp1, #8                                @ 1
	nop                                         @ 1
	strb tmp1, [odr]                            @ 2

	nop                                         @ 1
	nop                                         @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	nop                                         @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	nop                                         @ 1
	strb tmp2, [odr]                            @ 2

	ror tmp2, #8                                @ 1
	nop                                         @ 1
	strb tmp2, [odr]                            @ 2

	@ 0 at the end
	mov r4, #0                     @ 1
	nop                            @ 1
	strb r4, [odr]                 @ 2

	pop	{r4, r5, r6}               @ 4
	bx lr
