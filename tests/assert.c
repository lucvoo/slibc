#include <assert.h>

int main(int argc, char *argv[])
{
	assert(argc != 0);
	assert(argv[0] != 0);
	assert(argv[1] == 0);

	return 0;
}
