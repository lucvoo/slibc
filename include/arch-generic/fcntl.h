struct flock {
	short		l_type;
	short		l_whence;
	off_t		l_start;
	off_t		l_len;
	pid_t		l_pid;
};

#ifndef __STRICT_POSIX
struct flock64 {
	short		l_type;
	short		l_whence;
	loff_t		l_start;
	loff_t		l_len;
	pid_t		l_pid;
};

int creat64(const char *pathname, mode_t mode);
int fcntl64(int fd, int cmd, ...);

#endif
