#include <unistd.h>
#include <stdlib.h>
#include "libc/cdefs.h"
#include "libc/string.h"

//FIXME: is $LOGNAME good enough ???

int getlogin_r(char *name, size_t len)
{
	char *foo;

	foo = getenv("LOGNAME");	// thread-safe ???
	if (__unlikely(!foo))
		return -1;

	__safe_strcpy(name, foo, len);

	return 0;
}
