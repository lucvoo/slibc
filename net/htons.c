#include <arpa/inet.h>
#include "arch/swab.h"
#include "arch/endian.h"
#include "libc/symbols.h"
#include "libc/config.h"

uint16_t htons(uint16_t x)
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	return __swab16(x);
#elif	__BYTE_ORDER == __BIG_ENDIAN
	return x;
#else
#error "NUXI-endian unsupportted"
#endif
}

strong_alias(htons, ntohs);
