#include <arpa/inet.h>
#include "arch/swab.h"
#include "arch/endian.h"
#include "libc/symbols.h"
#include "libc/config.h"

uint32_t htonl(uint32_t x)
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	return __swab32(x);
#elif	__BYTE_ORDER == __BIG_ENDIAN
	return x;
#else
#error "NUXI-endian unsupportted"
#endif
}

strong_alias(htonl, ntohl);
