#include <stdlib.h>
#include <unistd.h>

// FIXME: is $LOGNAME good enough ???

char *getlogin(void)
{
	return getenv("LOGNAME");
}
