#ifndef _LIBC_CDEFS_H
#define _LIBC_CDEFS_H

#define __builtin_expect(x, expected_value)	(x)

#define __likely(x)	__builtin_expect((x),1)
#define __unlikely(x)	__builtin_expect((x),0)

#endif
