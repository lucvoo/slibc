#ifndef _ASSERT_H
#define _ASSERT_H

#ifdef NDEBUG
#define assert(ignore)	((void) 0)
#else

#include <sys/cdefs.h>

void __libc_assert(const char *expr, const char *file, unsigned int line, const char *func) __NORETURN;

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#define __ASSERT_FUNC	__func__
#else
#define __ASSERT_FUNC	__FUNCTION__
#endif

#define assert(expr)	((expr) ? (void) 0 : \
	__libc_assert(#expr, __FILE__, __LINE__, __ASSERT_FUNC))
#endif

#endif
