#include <stdlib.h>
#include "libc/rand48.h"

void lcong48(unsigned short par[7])
{
	__libc_rand48_state.x[0] = par[0];
	__libc_rand48_state.x[1] = par[1];
	__libc_rand48_state.x[2] = par[2];

	__libc_rand48_state.a = __libc_rand48_mk64(par[5], par[4], par[3]);
	__libc_rand48_state.c = par[6];
}
