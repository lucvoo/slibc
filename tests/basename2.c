#include <libgen.h>
#include <stdio.h>
#include <string.h>

static
const char *names[] = { "file", ".", "..", "//", "/" };

#define nbr_names	(sizeof(names)/sizeof(names[0]))

static
void test_me(const char *entry)
{
	char buf[4096];
	char *res;

	strcpy(buf, entry);
	res = basename(buf);

	printf("%s -> %s\n", entry, res);
}

static
char buff[4096];

static
char *build_one(char *buf, const char *name)
{
	size_t len = strlen(name);

	memcpy(buf, name, len);

	return buf + len;
}

static
void build_level(char *buf, int l)
{
	if (l == 0) {
		buf[0] = '\0';
		test_me(buff);
	} else {
		size_t i;

		for (i = 0; i < nbr_names; i++) {
			char *ptr;

			ptr = build_one(buf, names[i]);
			build_level(ptr, l - 1);
		}
	}
}

int main(void)
{
	int i;

	for (i = 0; i < 8; i++)
		build_level(buff, i);

	//fflush(stdout);
	return 0;
}
