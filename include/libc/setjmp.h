#ifndef _LIBC_SETJMP_H
#define _LIBC_SETJMP_H

#include <setjmp.h>

int __libc_sigjmp_save(sigjmp_buf env, int savemask);

#endif
