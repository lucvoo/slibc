#include <stdlib.h>
#include "libc/rand48.h"

long jrand48(unsigned short buf[3])
{
	unsigned long val;

	__libc_rand48_iter(buf);
	val = buf[2] << 16 | buf[1];
	return val;
}
