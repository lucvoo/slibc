.global expl
	.type	 expl,@function
expl:
	fldl2e
	fldt 4(%esp)
	fmulp
	jmp __m_finexp
