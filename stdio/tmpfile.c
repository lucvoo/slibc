#include <stdio.h>
#include <stdlib.h>			// for mkstemp()
#include <unistd.h>			// for unlink() & close()

FILE *tmpfile(void)
{
	char path[] = P_tmpdir "/tmp-XXXXXX";
	int fd;
	FILE *fp;

	fd = mkstemp(path);
	if (fd < 0)
		return NULL;

	unlink(path);

	fp = fdopen(fd, "w+");
	if (!fp)
		close(fd);

	return fp;
}
