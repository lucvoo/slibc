.global expf
	.type	 expf,@function
expf:
	fldl2e
	fmuls 4(%esp)
	jmp __m_finexp
