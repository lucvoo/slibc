#include <fcntl.h>

int creat(const char *pathname, mode_t mode)
{
	// FIXME: open & creat syscalls really take an int for the mode
	return open(pathname, O_CREAT | O_WRONLY | O_TRUNC, mode);
}
