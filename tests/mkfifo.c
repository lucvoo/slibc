#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./test.h"

const char file[] = "/tmp/fifo674";

int main(void)
{
	char c;
	int fd;
	int pid, n;

	unlink(file);

	if (mkfifo(file, 0600) < 0)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid) {
		fd = open(file, O_RDONLY);
		if (fd < 0)
			die("parent: open() failed");
		n = read(fd, &c, 1);
		if (n != 1)
			die("parent: read() failed");
		if (c != 'x')
			die("parent: readed value is wrong");

		return 0;
	}
	fd = open(file, O_WRONLY);
	if (fd < 0)
		die("child: open() failed!");

	n = write(fd, "x", 1);
	if (n != 1)
		die("child: write() failed!");

//    unlink(file);
	return 0;
}
