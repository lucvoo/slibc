#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libc/stdio.h"

void abort(void)
{
	sigset_t set;

	// be sure to unblock SIGABRT
	sigemptyset(&set);
	sigaddset(&set, SIGABRT);

	// first try
	// FIXME:  __stdio_fcloseall()
	raise(SIGABRT);
	// a handler was installed for SIGABRT

	// removed it
	signal(SIGABRT, SIG_DFL);

	// and try again
	// FIXME:  __stdio_fcloseall()
	raise(SIGABRT);

	// or try this!
	exit(127);
}
