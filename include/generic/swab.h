#ifndef _LIBC_GENERIC_SWAB_H
#define _LIBC_GENERIC_SWAB_H

#include <stdint.h>

static inline uint16_t __swab16(uint32_t x)
{
	return __builtin_bswap16(x);
}

static inline uint32_t __swab32(uint32_t x)
{
	return __builtin_bswap32(x);
}

static inline uint64_t __swab64(uint64_t x)
{
	return __builtin_bswap64(x);
}

#endif
