#include <stdlib.h>

int main(void)
{
	int i;

	for (i = 1000; i; i--) {
		unsigned long a, b;
		long val;
		int w;

		a = random();
		b = random();
		val = (a << 16) ^ b;
		w = random() % 10;

		printf("%*.*s%ld\n", w, w, "", val);
	}

	return 0;
}
