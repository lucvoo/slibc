.text
	.align	2
	.global	strchr
	.type	 strchr,function
strchr:
.L1:
	ldrb	r3, [r0], #1		@ r3 = *s++
	cmp	r3, r1			@ if (r3 != c)
	cmpne	r3, #0			@   and (r3 != 0)
	bne	.L1			@ goto L1
	cmp	r3, #0			@ if (r3 == 0)
	moveq	r0, r3			@   s = 0
	subne	r0, r0, #1		@ else
					@   s = s-1
	mov	pc, lr			@ return s

	.size	 strchr,.-strchr
