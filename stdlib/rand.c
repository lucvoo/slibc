#include <stdlib.h>

static
unsigned int rand_state = 1;

int rand(void)
{
	return rand_r(&rand_state);
}

void srand(unsigned int seed)
{
	rand_state = seed;
}

int random(void) __attribute__ ((alias("rand")));
void srandom(unsigned int i) __attribute__ ((alias("srand")));
