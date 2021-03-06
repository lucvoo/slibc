// Stolen from dietlibc

.text
	.align	2
	.global	strlen
	.type    strlen,function

strlen:
	ands	a3, a1, #3
	ldr	ip, =0x01010101
	rsb	a2, a1, #0
	ldr	a4, [a1, -a3]!

	// ensure junk bytes aren't nulls

	rsbne	a3, a3, #4
	movne	a3, a3, lsl #3
	orrne	a4, a4, ip, lsr a3

.Lloop:
	sub	a3, a4, ip
	bic	a3, a3, a4
	ands	a3, a3, ip, lsl #7
	ldreq	a4, [a1, #4]!
	beq	.Lloop

	// a3 & 0x80808080 == a3

	sub	a3, a3, #1
	tst	a3, #0x10000
	movne	a3, a3, lsr #16
	addne	a1, a1, #2
	movs	a3, a3, lsr #9
	adc	a1, a1, a2

	mov	pc, lr

	.size strlen,.-strlen
