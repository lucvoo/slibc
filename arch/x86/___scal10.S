#include "libc/asm.h"

// long double ___scal10(long double a, long b);
//	=> a * 10 ^ b

ENTRY(___scal10)

___scal10:
        fldl2t
	fimul    16(%esp)
        fld      %st(0)
        frndint
        fxch
        fsub     %st(1),%st(0)
        f2xm1
        fld1
        faddp    %st(0),%st(1)
        fscale
        fstp     %st(1)
	fldt	 4(%esp)
	fmulp
        ret

END(___scal10);
