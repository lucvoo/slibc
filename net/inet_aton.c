#include <arpa/inet.h>
#include <stdlib.h>			// for strtoul()
#include "libc/cdefs.h"

int inet_aton(const char *str, struct in_addr *dest)
{
	uint32_t addr = 0x00000000;
	uint32_t max = 0xffffffff;
	int i;

	for (i = 24; i >= 0; i -= 8, max >>= 8) {
		unsigned long val;
		char *ptr;

		val = strtoul(str, &ptr, 0);
		// check if value is acceptable at this position
		if (*ptr == '\0')	// end reached
		{
			if (val > max)
				return 0;
			addr |= val;
			dest->s_addr = htonl(addr);
			return 1;
		}

		if (*ptr != '.')
			return 0;	// illegal char

		if (val > 0xff)
			return 0;
		addr |= (val << i);
		str = ptr + 1;
	}
	// more than 4 fields
	return 0;
}
