#include <stdlib.h>
#include <string.h>
#include "libc/setenv.h"

int putenv(char *string)
{
	size_t len;
	char *ptr;

	ptr = strchr(string, '=');
	if (!ptr)			// FIXME: non SuS
	{
		unsetenv(string);
		return 0;
	}

	len = ptr + 1 - string;		// include '=';

	return __libc_setenv(string, len, 1);
}
