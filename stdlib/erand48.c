#include <stdlib.h>
#include "libc/rand48.h"

double erand48(unsigned short buf[3])
{
	double val;

	__libc_rand48_iter(buf);

	val = buf[1] << 16 | buf[0];
	val += buf[2] * 4294967296.0;
	val = val / (65536 * 4294967296LL);

	return val;
}
