#ifndef _MQUEUE_H
#define _MQUEUE_H

#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <fcntl.h>

typedef int mqd_t;

struct mq_attr {
	long		mq_flags;	// O_NONBLOCK or 0
	long		mq_maxmsg;	// Maximum number of messages in the queue
	long		mq_msgsize;	// Maximum size of one message in bytes
	long		mq_curmsgs;	// Current number of messages in the queue
	long		__pad[2];
};

#define MQ_PRIO_MAX	0x7FFFFFFE

int mq_close(mqd_t);
int mq_getattr(mqd_t, struct mq_attr *);
int mq_notify(mqd_t, const struct sigevent *);
mqd_t mq_open(const char *, int, ...);
ssize_t mq_receive(mqd_t, char *, size_t, unsigned int *);
int mq_send(mqd_t, const char *, size_t, unsigned int);
int mq_setattr(mqd_t, const struct mq_attr *restrict, struct mq_attr *restrict);
ssize_t mq_timedreceive(mqd_t, char *restrict, size_t, unsigned *restrict,
			const struct timespec *restrict);
int mq_timedsend(mqd_t, const char *, size_t, unsigned, const struct timespec *);
int mq_unlink(const char *);

#endif
