#include <signal.h>

int sigemptyset(sigset_t * set)
{
	size_t n;

	n = sizeof(sigset_t) / sizeof(long);
	for (; n--;)
		((long *)set)[n] = 0;

	return 0;
}
