#ifndef _SYS_MSG_H
#define _SYS_MSG_H

#include <sys/ipc.h>
#include "types/pid_t.h"
#include "types/size_t.h"
#include "types/ssize_t.h"
#include "types/time_t.h"

// ipcs ctl commands
#define MSG_STAT 11
#define MSG_INFO 12

// msgrcv options
#define MSG_NOERROR     010000		// no error if message is too big
#define MSG_EXCEPT      020000		// recv any msg except of specified type

typedef unsigned short msgqnum_t;
typedef unsigned short msglen_t;

struct msqid_ds {
	struct ipc_perm	msg_perm;
	struct msg	*msg_first;	// first message on queue,unused
	struct msg	*msg_last;	// last message in queue,unused
	time_t		msg_stime;	// last msgsnd time
	time_t		msg_rtime;	// last msgrcv time
	time_t		msg_ctime;	// last change time
	unsigned long	msg_lcbytes;	// Reuse junk fields for 32 bit
	unsigned long	msg_lqbytes;	// ditto
	unsigned short	msg_cbytes;	// current nbr of bytes on queue
	msgqnum_t	msg_qnum;	// number of messages in queue
	msglen_t	msg_qbytes;	// max number of bytes on queue
	pid_t		msg_lspid;	// pid of last msgsnd
	pid_t		msg_lrpid;	// last receive pid
};

int msgctl(int, int, struct msqid_ds *);
int msgget(key_t, int);
ssize_t msgrcv(int, void *, size_t, long, int);
int msgsnd(int, const void *, size_t, int);

#endif
