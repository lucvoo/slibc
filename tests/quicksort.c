#include <stdlib.h>
#include <stdio.h>

static
size_t isnotsorted(const void *A, size_t n, size_t size, __compar_fn_t fun)
{
	size_t i;

	for (i = 0; (i + 1) < n; i++) {
		const void *next;

		next = A + size;
		if (!(fun(A, next) <= 0))
			return i;

		A = next;
	}

	return 0;
}

static
void dump(const int *A, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("A[%u]\t= %d\n", i, A[i]);
}

#define MAXN	10000
unsigned int tbl[MAXN];

static
int compar_int(const void *a, const void *b)
{
	int A = *(int *)a;
	int B = *(int *)b;

	return A - B;
}

int main(void)
{
	int loop = 10;

	while (loop--) {
		size_t n = rand() % MAXN;
		size_t i;

		// fill the table
		for (i = 0; i < n; i++)
			tbl[i] = rand();

		qsort(tbl, n, sizeof(tbl[0]), compar_int);
		if ((i = isnotsorted(tbl, n, sizeof(tbl[0]), compar_int))) {
			fprintf(stderr, "sort failed @ %u\n", i);
			dump(tbl, n);
			exit(1);
		}
		//printf("OK\n");
	}

	return 0;
}
