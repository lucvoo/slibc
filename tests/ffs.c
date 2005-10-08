#include <strings.h>
#include <limits.h>
#include <assert.h>

int main(void)
{
	assert(ffs(0) == 0);
	assert(ffs(1) == 1);
	assert(ffs(2) == 2);
	assert(ffs(3) == 1);
	assert(ffs(4) == 3);
	assert(ffs(256) == 9);
	assert(ffs(511) == 1);
	assert(ffs(1 << (WORD_BIT - 1)) == WORD_BIT);

	return 0;
}
