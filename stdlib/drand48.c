#include <stdlib.h>
#include "libc/rand48.h"

double drand48(void)
{
	return erand48(__libc_rand48_state.x);
}
