.text
	.align	2
	.global	memcmp
	.type	 memcmp,function
memcmp:
	mov	ip, r0
	subs	r0, r2, #0
	moveq	pc, lr
.Loop:
	ldrb	r2, [ip], #1
	ldrb	r3, [r1], #1
	subs	r2, r2, r3
	bne	.Lend
	subs	r0, r0, #1
	bne	.Loop
.Lend:
	mov	r0, r2
	mov	pc, lr

	.size	 memcmp,.-memcmp
