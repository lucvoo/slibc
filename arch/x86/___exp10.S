#include "libc/asm.h"

ENTRY(___exp10)

___exp10:
        fldl2t
        fmull    4(%esp)
        fld      %st(0)
        frndint
        fxch
        fsub     %st(1),%st(0)
        f2xm1
        fld1
        faddp    %st(0),%st(1)
        fscale
        fstp     %st(1)
        ret

END(___exp10)
