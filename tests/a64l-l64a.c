#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct base64 {
	const char *base64;
	long int value;
};

static
const struct base64 tests[] = {
	{"./", 64},
	{"", 0},
	{"/", 1},
	{"FT", 2001},
	{"zzzzz1", 0xffffffff},
	{"zzzz1", 0x3ffffff},
	{"zzz1", 0xfffff},
	{"zz1", 0x3fff},
	{"z1", 0xff},
	{"1", 0x3},
	{NULL, 0}
};

int main(void)
{
	const struct base64 *tbl;
	long int l;
	const char *s;
	int error = 0;

	for (tbl = tests; tbl->base64; ++tbl) {
		l = a64l(tbl->base64);
		if (l != tbl->value) {
			printf("\tBAD\n  returns %ld, expected %ld\n", l, tbl->value);
			error++;
		}
		s = l64a(tbl->value);
		if (strcmp(s, tbl->base64) != 0) {
			printf("\tBAD\n  returns \"%s\", expected \"%s\"\n", s, tbl->base64);
			error = 1;
		}
	}

	if (error == 0) {
		puts("OK");
		return 0;
	} else {
		printf("test failed: %d errors\n", error);
		return 1;
	}
}
