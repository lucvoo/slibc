#include <signal.h>

int sigfillset(sigset_t * set)
{
	size_t n;

	n = sizeof(sigset_t) / sizeof(long);
	for (; n--;)
		((long *)set)[n] = ~0L;

	return 0;
}
