#include <signal.h>
#include <string.h>

const char *strsignal(int sig)
{
	if (sig > 0 && sig < _NSIG)
		return _sys_siglist[sig];

	return "Unknown signal";
}
