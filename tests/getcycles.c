#include "arch/libc/config.h"
#include <stdio.h>
#include <stdint.h>

#ifdef HAVE_ARCH_GETCYCLES
#include "libc/getcycles.h"
#endif

int main(void)
{
#ifdef HAVE_ARCH_GETCYCLES
	uint64_t cycles;

	cycles = __getcycles();

	printf("=> %016llx\n", cycles);
#endif

	return 0;
}
