#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define expect_long(n, v, x) \
    do if (v != x) \
    {	fprintf(stderr, "test %d failed: %08lx != %08lx\n", n, v, x); \
	err++;	\
    } while (0)

#define expect_double(n, v, x) \
    do if (v != x) \
    {	fprintf(stderr, "test %d failed: %a != %a\n", n, v, x); \
	err++;	\
    } while (0)

int main(void)
{
	unsigned long val;
	unsigned short xsubi[3] = { 0x0123, 0x4567, 0x89ab };
	int err = 0;

	// test basic functionalities
	srand48(0x1);
	val = mrand48();
	srand48(val);
	val = mrand48();
	expect_long(1, val, 0xc4862cf1L);

	// test "half"-reentrant versions
	val = jrand48(xsubi);
	expect_long(2, val, 0xd1e77e24L);

#if 0
	double dval;
	dval = drand48();
	expect_double(99, dval, 0x1 .0278f 8e4 c6ep - 1);
#endif

	return err;
}
