#include <libgen.h>

typedef struct {
	char path[64];
	const char *dir;
	const char *base;
} entry_t;

entry_t vector[] = {
//    { 0,              ".",            "." },
	{"", ".", "."},
	{".", ".", "."},
	{"..", "..", ".."},
	{"/", "/", "/"},
	{"//", "/", "/"},
	{"/usr", "/", "usr"},
	{"/usr/", "/", "usr"},
	{"/usr//", "/", "usr"},
	{"/usr/lib", "/usr", "lib"},
	{"/usr/lib/", "/usr", "lib"},
	{"/usr/lib//", "/usr", "lib"},
};

int main(void)
{
	int n;
	int i;
	int err = 0;

	n = sizeof(vector) / sizeof(vector[0]);
	for (i = 0; i < n; i++) {
		const char *base;
		char *res;

		res = basename(vector[i].path);
		base = vector[i].base;
		if (strcmp(res, base)) {
			err++;
			fprintf(stderr, "[%d]: \"%s\" != \"%s\"\n", i, res, base);
		}
	}

	return err;
}
