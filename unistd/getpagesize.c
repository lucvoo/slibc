#include <unistd.h>
#include <limits.h>

size_t getpagesize(void)
{
	return PAGESIZE;
}
