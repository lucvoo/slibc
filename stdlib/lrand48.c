#include <stdlib.h>
#include "libc/rand48.h"

long lrand48(void)
{
	return nrand48(__libc_rand48_state.x);
}
