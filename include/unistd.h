#ifndef _UNISTD_H
#define _UNISTD_H

#include <sys/cdefs.h>
#include <getopt.h>

#include "values/SEEK_.h"
#include "values/NULL.h"
#include "sys/posix_conf.h"

// mode for access()
#define F_OK 0				// Test for existence of file.
#define R_OK 4				// Test for read permission.
#define W_OK 2				// Test for write permission.
#define X_OK 1				// Test for execute permission.

#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

#include "types/gid_t.h"
#include "types/intptr_t.h"
#include "types/off_t.h"
#include "types/pid_t.h"
#include "types/ptrdiff_t.h"
#include "types/size_t.h"
#include "types/ssize_t.h"
#include "types/uid_t.h"
#include "types/useconds_t.h"

void _exit(int status) __NORETURN;
	 int access(const char *pathname, int mode);
	 unsigned int alarm(unsigned int seconds);
	 int chdir(const char *path);
	 int chown(const char *path, uid_t owner, gid_t group);
	 int close(int fd);
	 size_t confstr(int name, char *buf, size_t len);
	 char *ctermid(char *buf);
	 int dup(int oldfd);
	 int dup2(int oldfd, int newfd);
	 int execl(const char *path, const char *arg, ...);
	 int execle(const char *path, const char *arg, ...);
	 int execlp(const char *file, const char *arg, ...);
	 int execv(const char *path, char *const argv[]);
	 int execve(const char *path, char *const argv[], char *const env[]);
	 int execvp(const char *file, char *const argv[]);
	 int fchdir(int fd);
	 int fchown(int fd, uid_t owner, gid_t group);
	 int fdatasync(int fd);
	 pid_t fork(void);
	 int fsync(int fd);
	 int ftruncate(int fd, off_t length);
	 char *getcwd(char *buf, size_t size);
	 uid_t getegid(void);
	 uid_t geteuid(void);
	 gid_t getgid(void);
	 int getgroups(int size, gid_t list[]);
	 int gethostname(char *name, size_t len);
	 char *getlogin(void);
	 int getlogin_r(char *name, size_t len);
	 pid_t getpgid(pid_t pid);
	 pid_t getpgrp(void);
	 pid_t getpid(void);
	 pid_t getppid(void);
	 pid_t getsid(pid_t);
	 uid_t getuid(void);
	 char *getwd(char *buf);
	 int isatty(int fd);
	 int lchown(const char *path, uid_t owner, gid_t group);
	 int link(const char *oldpath, const char *newpath);
////int lockf(int fd, int cmd, off_t len);
	 off_t lseek(int fd, off_t offset, int whence);
	 int nice(int inc);
	 int pause(void);
	 int pipe(int filedes[2]);
	 ssize_t pread(int fd, void *buf, size_t count, off_t offset);
	 ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);
	 ssize_t read(int fd, void *buf, size_t n);
	 int readlink(const char *restrict path, char *restrict buf, size_t bufsiz);
	 int rmdir(const char *pathname);
	 int setegid(gid_t egid);
	 int seteuid(uid_t euid);
	 int setgid(gid_t gid);
	 int setpgid(pid_t pid, pid_t pgid);
	 int setpgrp(void);
	 int setregid(gid_t rgid, gid_t egid);
	 int setreuid(uid_t ruid, uid_t euid);
	 pid_t setsid(void);
	 int setuid(uid_t uid);
	 unsigned int sleep(unsigned int seconds);
	 void swab(const void *restrict from, void *restrict to, ssize_t n);
	 int symlink(const char *oldpath, const char *newpath);
	 void sync(void);
	 pid_t tcgetpgrp(int fd);
	 int tcsetpgrp(int fd, pid_t pgrpid);
	 int truncate(const char *path, off_t length);
	 int ttyname_r(int fd, char *name, size_t size);
	 char *ttyname(int fd);
	 useconds_t ualarm(useconds_t value, useconds_t interval);
	 int unlink(const char *pathname);
	 int usleep(useconds_t);
	 pid_t vfork(void);
	 ssize_t write(int fd, const void *buf, size_t n);

	 extern char **__environ;

#ifndef __STRICT_POSIX
	 int brk(void *end_data_segment);
	 int chown32(const char *path, uid32_t owner, gid32_t group);
	 int chroot(const char *path);
	 extern char **environ;
	 int fchown32(int fd, uid32_t owner, gid32_t group);
	 int getdomainname(char *name, size_t len);
	 size_t getpagesize(void);
	 int getresgid(gid_t * rgid, gid_t * egid, gid_t * sgid);
	 int getresuid(uid_t * ruid, uid_t * euid, uid_t * suid);
	 int lchown32(const char *path, uid32_t owner, gid32_t group);
	 int _llseek(unsigned int fd, unsigned long hi, unsigned long lo, loff_t * res,
		     unsigned int whence);
	 ssize_t pread64(int fd, void *buf, size_t count, loff_t offset);
	 ssize_t pwrite64(int fd, const void *buf, size_t count, loff_t offset);
	 void *sbrk(ptrdiff_t increment);
	 int setdomainname(const char *name, size_t len);
	 int sethostname(const char *name, size_t len);
	 int setresgid(gid_t rgid, gid_t egid, gid_t sgid);
	 int setresuid(uid_t ruid, uid_t euid, uid_t suid);
	 int vhangup(void);

	 char *getusershell(void);
	 void setusershell(void);
	 void endusershell(void);

	 pid_t __sys_gettid(void);	// FIXME: move this to ...
	 void __sys_exit_group(int) __NORETURN;
#endif

#endif
