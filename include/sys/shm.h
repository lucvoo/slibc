#ifndef _SYS_SHM_H
#define _SYS_SHM_H

#include <sys/ipc.h>
#include "arch/sys/shm.h"
#include "types/pid_t.h"
#include "types/size_t.h"
#include "types/time_t.h"

// permission flag for shmget
#define SHM_R		0400
#define SHM_W		0200

// mode for attach
#define SHM_RDONLY	010000		// read-only access
#define SHM_RND		020000		// round attach addr to SHMLBA boundary
#define SHM_REMAP	040000		// take-over region on attach

// super user shmctl commands
#define SHM_LOCK	11
#define SHM_UNLOCK	12

// ipcs ctl commands
#define SHM_STAT	13
#define SHM_INFO	14

struct shmid_ds;			// FIXME: kernel use __kernel_ipc_pid_t
			//        which may be != user pid_t !!!

void *shmat(int, const void *, int);
int shmctl(int, int, struct shmid_ds *);
int shmdt(const void *);
int shmget(key_t, size_t, int);

#endif
