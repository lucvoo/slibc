#ifndef _UTMPX_H
#define _UTMPX_H

#include <sys/time.h>

#define __UT_LINESIZE   32
#define __UT_NAMESIZE   32
#define __UT_HOSTSIZE   64		// FIXME: CONFIG

#define EMPTY		0		// No valid user accounting information
#define BOOT_TIME	2		// Time of system boot
#define OLD_TIME	4		// Time when system clock changed
#define NEW_TIME	3		// Time after system clock changed
#define USER_PROCESS	7		// Normal process
#define INIT_PROCESS	5		// Process spawned by the init process
#define LOGIN_PROCESS	6		// Session leader of a logged in user
#define DEAD_PROCESS	8		// Terminated process

#ifndef __STRICT_POSIX
#define RUN_LVL		1		// The system's runlevel
#define ACCOUNTING	9		// System accounting
#endif

#include "types/pid_t.h"

struct utmpx {
	char		ut_user[__UT_NAMESIZE];
	char		ut_id[4];
	char		ut_line[__UT_LINESIZE];
	pid_t		ut_pid;
	short		ut_type;
	struct timeval	ut_tv;

	char		ut_host[__UT_HOSTSIZE];
	long		it_session;
	unsigned char	ut_addr_v6[16];	// FIXME ...
//  exit_status		ut_exit
};

void endutxent(void);
struct utmpx *getutxent(void);
struct utmpx *getutxid(const struct utmpx *id);
struct utmpx *getutxline(const struct utmpx *line);
struct utmpx *pututxline(const struct utmpx *utmpx);
void setutxent(void);

#endif
