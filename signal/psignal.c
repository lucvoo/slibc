#include <signal.h>
#include <string.h>			// for strsignal()
#include <stdio.h>

void psignal(int sig, const char *message)
{
	if (message && message[0])
		fprintf(stderr, "%s: ", message);

	fputs(strsignal(sig), stderr);
}
