#include <strings.h>
#include <string.h>

void bcopy(const void *src, void *dest, size_t count)
{
	memcpy(dest, src, count);
}

#include "libc/link_warning.h"
warn_legacy(bcopy, "memcpy() or memmove");
