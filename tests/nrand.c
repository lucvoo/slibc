#include <stdlib.h>
#include <stdio.h>

unsigned int nrand(void);

int main(void)
{
	unsigned int v;
	int n;

	for (n = 1; n < 2000; n++) {
		v = nrand();
		printf("N[%4d] = %08x\n", n, v);
	}

	return 0;
}
