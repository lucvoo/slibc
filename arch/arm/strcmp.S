.text
	.align	2
	.global	strcmp
	.type	strcmp,function

strcmp:
.Loop:
	ldrb	r2, [r1], #1		@ r2 = *s1++
	ldrb	r3, [r0], #1		@ r3 = *s0++
	subs	r3, r3, r2		@ r3 = *s0++ - r2
	bne	.Lend			@ if r3 != 0
					@   goto end
	cmp	r2, #0			@ if r2 != 0
	bne	.Loop			@   goto loop
.Lend:
	mov	r0, r3
	mov	pc, lr

	.size	strcmp,.-strcmp
