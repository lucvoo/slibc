#ifndef _SIGNAL_H
#define _SIGNAL_H

#include <time.h>
#include "types/size_t.h"
#include "arch/signal.h"

typedef void (*__sighandler_t) (int);
typedef void (*__sig_t) (int);

#define SIG_DFL		((__sighandler_t) 0)
#define SIG_IGN		((__sighandler_t) 1)
#define SIG_ERR		((__sighandler_t)-1)
#define SIG_HOLD	((__sighandler_t) 2)

typedef int sig_atomic_t;

union sigval {
	int sival_int;
	void *sival_ptr;
};

#define SS_ONSTACK	1
#define SS_DISABLE	2

#ifdef __STRICT_POSIX
struct sigstack {			// Never used but defined by the standard
	void *ss_sp;
	int ss_onstack;
};
#endif

struct sigevent;

#include "types/pid_t.h"
#include "types/size_t.h"
#include "types/stack_t.h"
#include "types/mcontext_t.h"
#include "types/ucontext_t.h"

__sig_t bsd_signal(int signum, __sig_t handler);
int kill(pid_t pid, int sig);
int killpg(pid_t pgrp, int sig);
int raise(int sig);
int sigaction(int, const struct sigaction *restrict, struct sigaction *restrict);
int sigaddset(sigset_t * set, int signum);
int sigaltstack(const stack_t * restrict, stack_t * restrict);
int sigdelset(sigset_t * set, int signum);
int sigemptyset(sigset_t * set);
int sigfillset(sigset_t * set);
int sighold(int sig);
int sigignore(int sig);
int siginterrupt(int sig, int flag);
int sigismember(const sigset_t * set, int sig);
__sig_t signal(int signum, __sig_t handler);
int sigpause(int sig);
int sigpending(sigset_t * set);
int sigprocmask(int, const sigset_t * restrict, sigset_t * restrict);
int sigqueue(pid_t pid, int sig, const union sigval val);
int sigrelse(int sig);
__sig_t sigset(int sig, __sig_t handler);
int sigsuspend(const sigset_t * mask);
int sigtimedwait(const sigset_t * restrict, siginfo_t * restrict, const struct timespec *restrict);
int sigwaitinfo(const sigset_t * restrict, siginfo_t * restrict);
int sigwait(const sigset_t * restrict, int *restrict);

#ifndef __STRICT_POSIX
// Non Sus
extern const char *_sys_siglist[];
int __sys_rt_sigqueueinfo(pid_t, int, siginfo_t *);

int __sys_tkill(pid_t pid, int sig);
void psignal(int sig, const char *message);
#endif

#endif
