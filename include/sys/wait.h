#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H

#include <sys/cdefs.h>

#include <signal.h>
#include <sys/resource.h>

#define WNOHANG		0x00000001	// Do not hang if no status is available
#define WUNTRACED	0x00000002	// Report status of stopped child process

// Linux specific stuff
#define __WNOTHREAD	0x20000000	// Don't wait on children of other threads in this group
#define __WALL		0x40000000	// Wait on all children, regardless of type
#define __WCLONE	0x80000000	// Wait only on non-SIGCHLD children

// macro definitons
#define WIFEXITED(STAT)		(((STAT) & 0x007f) == 0)
#define WEXITSTATUS(STAT)	(((STAT) & 0xff00) >> 8)
#define WIFSIGNALED(STAT)	({ int __stat = (STAT); !WIFSTOPPED(__stat) && !WIFEXITED(__stat); })
#define WTERMSIG(STAT)		(((STAT) & 0x007f))
#define WIFSTOPPED(STAT)	(((STAT) & 0x00ff) == 0x007f)
#define WSTOPSIG(STAT)		(((STAT) & 0xff00) >> 8)

#define WCOREDUMP(STAT)		((STAT) & 0x0080)

#include "types/pid_t.h"
#include "types/id_t.h"
#include <sys/resource.h>

pid_t wait(int *status);
//int   waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
pid_t waitpid(pid_t pid, int *status, int options);

#ifndef __STRICT_POSIX
pid_t wait3(int *status, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);
#endif

#endif
