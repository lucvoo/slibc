#include <string.h>
#include "libc/errno.h"
#include "libc/string.h"

char *strerror(int errnum)
{
	return (char *)__strerror(errnum);
}
