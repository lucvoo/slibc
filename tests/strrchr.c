#include <string.h>
#include <assert.h>

int main(void)
{
	const char x[] = "foo bar baz";

	assert(strrchr(x, 'z') == x + 10);	// last
	assert(strrchr(x, ' ') == x + 7);	// 2 occurences
	assert(strrchr(x, 'f') == x + 0);	// first
	assert(strrchr(x, 'x') == 0);	// not present

	return 0;
}
