#ifndef _LIBC_LIMITS_32_H
#define _LIBC_LIMITS_32_H

#define WORD_BIT        32
#define UINT_MAX        4294967295U
#define INT_MAX         2147483647
#define INT_MIN         (-INT_MAX -1)

#define LONG_BIT        32
#define ULONG_MAX       4294967295UL
#define LONG_MAX        2147483647L
#define LONG_MIN        (-LONG_MAX -1)

#define __LLONG_BIT	64
#define ULLONG_MAX      18446744073709551615ULL
#define LLONG_MAX       9223372036854775807LL
#define LLONG_MIN       (-LLONG_MAX -1)

#endif
