#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include "db-files.h"

int __libc_parse_start(const char *filename, parse_state_t * s)
{
	int fd;
	off_t len;
	char *ptr;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return -1;

	len = lseek(fd, 0, SEEK_END);
	if (len == -1)
		return -1;

	ptr = mmap(NULL, len, PROT_READ, MAP_SHARED, fd, 0);
	close(fd);
	if (ptr == MAP_FAILED) {
		close(fd);
		return -1;
	}

	s->buf = s->ptr = ptr;
	s->end = ptr + len;

	return 0;
}
