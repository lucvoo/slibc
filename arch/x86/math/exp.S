.global exp2f
	.type	 exp2f,@function
exp2f:
	flds 4(%esp)
	jmp __m_finexp

.global exp2
	.type	 exp2,@function
exp2:
	fldl 4(%esp)
	jmp __m_finexp

.global exp2l
	.type	 exp2l,@function
exp2l:
	fldt 4(%esp)
	jmp __m_finexp

.global expl
	.type	 expl,@function
expl:
	fldl2e
	fldt 4(%esp)
	fmulp
	jmp __m_finexp

.global expf
	.type	 expf,@function
expf:
	fldl2e
	fmuls 4(%esp)
	jmp __m_finexp

.global exp
	.type	 exp,@function
exp:
	fldl2e
	fmull 4(%esp)
__m_finexp:
	fst	%st(1)
	frndint
	fst	%st(2)
	fsubrp
	f2xm1
	fld1
	faddp
	fscale
	ret

/* x^y; st(0)=x, st(1)=y (x > 0) */
.global __m_finpow
	.type	__m_finpow,@function	#FIXME ??
__m_finpow:
	fyl2x
	jmp __m_finexp
