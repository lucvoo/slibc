.global exp2f,exp2,exp2l
	.type	 exp2f,@function
	.type	 exp2,@function
	.type	 exp2l,@function
exp2f:
	flds 4(%esp)
	jmp __m_finexp
exp2:
	fldl 4(%esp)
	jmp __m_finexp
exp2l:
	fldt 4(%esp)
	jmp __m_finexp

// FIXME:
.long	exp
