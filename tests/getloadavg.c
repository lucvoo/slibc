#include <stdio.h>
#include <stdlib.h>

int min[3] = { 1, 5, 15 };

int main(void)
{
	double load[3];
	int i;

	getloadavg(load, 3);

	for (i = 0; i < 3; i++) {
		int val;

		val = load[i] * 1000;
		printf("load[%02d] = %d.%03d\n", min[i], val / 1000, val % 1000);
	}

	return 0;
}
