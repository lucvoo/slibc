#include <stdlib.h>
#include "libc/rand48.h"

long nrand48(unsigned short buf[3])
{
	return jrand48(buf) >> 1;
}
