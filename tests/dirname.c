#include <libgen.h>
#include <string.h>
#include <assert.h>

#define test(input, expect)	\
	assert(strcmp(dirname(input), expect) == 0)

#define test_cpy(input, expect)	\
	strncpy(tmp, input, sizeof(tmp)); \
	test(tmp, expect)

int main(void)
{
	char tmp[80];

	test(0, ".");

	test_cpy("/a/b/", "/a");
	test_cpy("/a/b", "/a");
	test_cpy("/a/", "/");
	test_cpy("/a", "/");
	test_cpy("/", "/");

	test_cpy("a", ".");
	test_cpy("a/", ".");
	test_cpy("a/b", "a");
	test_cpy("a/b/", "a");
	test_cpy("a/b/c", "a/b");
	test_cpy("a/b/c/", "a/b");

	test_cpy(".", ".");
	test_cpy("..", ".");

	test_cpy("//", "/");
	test_cpy("////", "/");

	test_cpy("", ".");

	return 0;
}
