#include <stdlib.h>
#include "libc/rand48.h"

long mrand48(void)
{
	return jrand48(__libc_rand48_state.x);
}
