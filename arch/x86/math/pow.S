/* pow(x,y) */
.global powf,pow,powl
	.type	powf,@function
	.type	pow,@function
	.type	powl,@function
powf:
	flds 4(%esp)	# x
	flds 8(%esp)	# y
	jmp __pow
powl:
	fldt 4(%esp)
	fldt 16(%esp)
	jmp __pow
pow:
	fldl 4(%esp)
	fldl 12(%esp)
/* x^y; st(0)=y, st(1)=x */
__pow:
	ftst		# y = 0 ?
	fstsw %ax
	fld1		# st(0)=1, st(1)=y, st(2)=x
	sahf
	jz 1f		# return 1
	fcomp %st(1)	# y = 1 ?
	fstsw %ax
	fxch		# st(0)=x, st(1)=y
	sahf
	jz 1f		# return x
	ftst		# x = 0 ?
	fstsw %ax
	sahf
	jz 1f
	jnc __m_finpow	# x > 0
	fxch		# st(0)=y, st(1)=x
	fld %st(0)	# st(0)=y, st(1)=y, st(2)=x
	frndint		# st(0)=int(y)
	fcomp %st(1)	# y = int(y)?
	fstsw %ax
	fxch
	sahf
	jnz __m_finpow	# fyl2x -> st(0) = NaN
/* y even or odd ? */
	fld1
	fadd %st(0)	# st(0) = 2
	fdivr %st(2),%st(0) # st(0)=st(2)/2
	frndint
	fadd %st(0),%st(0)
	fcomp %st(2)	# st(0) = x, st(1) = y
	fstsw %ax
	fchs		# st(0) = -x
	sahf
	jz __m_finpow	# y even
	call __m_finpow	# y odd
	fchs
1:	ret
