#ifndef _GENERIC_STDARG_H
#define _GENERIC_STDARG_H

#include <sys/cdefs.h>
#include "types/va_list.h"

#define va_start(ap,n)	__builtin_va_start(ap,n)
#define va_copy(d,s)	__builtin_va_copy(d,s)
#define va_arg(ap,type)	__builtin_va_arg(ap,type)
#define va_end(ap)	__builtin_va_end(ap)

#endif
