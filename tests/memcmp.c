#include <string.h>
#include <stdlib.h>

int main(void)
{

	// Some versions of memcmp are not 8-bit clean. 
	char c0 = 0x40, c1 = 0x80, c2 = 0x81;
	if (memcmp(&c0, &c2, 1) >= 0 || memcmp(&c1, &c2, 1) >= 0)
		exit(1);

	/* The Next x86 OpenStep bug shows up only when comparing 16 bytes
	   or more and with at least one buffer not starting on a 4-byte boundary.
	   William Lewis provided this test program.   */
	{
		char foo[21];
		char bar[21];
		int i;
		for (i = 0; i < 4; i++) {
			char *a = foo + i;
			char *b = bar + i;
			strcpy(a, "--------01111111");
			strcpy(b, "--------10000000");
			if (memcmp(a, b, 16) >= 0)
				exit(1);
		}
		exit(0);
	}

	;
	return 0;
}
