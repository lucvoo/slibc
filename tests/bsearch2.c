#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int compint(const void *a, const void *b)
{
	const int *A = a;
	const int *B = b;

	return *B - *A;
}

static void die(const char *message) __attribute__ ((noreturn));
static void die(const char *message)
{
	fputs(message, stderr);
	exit(1);
}

#define SIZE 1000
int main(void)
{
	int array[SIZE], array2[SIZE];
	int i, j;
	int *k;

	for (j = 10; j < SIZE; ++j) {
		for (i = 0; i < j; ++i)
			array[i] = rand();
		memcpy(array2, array, sizeof(array));
		qsort(array, j, sizeof(int), compint);
		for (i = 0; i < j - 1; ++i)
			if (array[i] < array[i + 1])
				die("not sorted after qsort!\n");
		for (i = 0; i < j; ++i) {
			// printf("element %d: ",i);
			k = bsearch(array + i, array, j, sizeof(int), compint);
			if (!k) {
				k = bsearch(array + i, array, j, sizeof(int), compint);
				die("bsearch returned NULL\n");
			}
			if (k != array + i)
				die("bsearch found wrong element\n");
			// printf("%d\n",k-array);
		}
	}

	return 0;
}
