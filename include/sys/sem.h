#ifndef _SYS_SEM_H
#define _SYS_SEM_H

#include <sys/ipc.h>
#include "types/pid_t.h"
#include "types/size_t.h"
#include "types/time_t.h"

// semop flags
#define SEM_UNDO        0x1000		// undo the operation on exit

// semctl cmds
#define GETPID		11		// get sempid
#define GETVAL		12		// get semval
#define GETALL		13		// get all semval's
#define GETNCNT		14		// get semncnt
#define GETZCNT		15		// get semzcnt
#define SETVAL		16		// set semval
#define SETALL		17		// set all semval's

// ipcs ctl cmds
#define SEM_STAT	18
#define SEM_INFO	19

struct sembuf {
	unsigned short	sem_num;	// semaphore index in array
	short		sem_op;		// semaphore operation
	short		sem_flg;	// operation flags
};

struct seminfo {
	int		semmap;
	int		semmni;
	int		semmns;
	int		semmnu;
	int		semmsl;
	int		semopm;
	int		semume;
	int		semusz;
	int		semvmx;
	int		semaem;
};

union __semun {
	int		_val;		// value for SETVAL
	struct semid_ds	*_buf;		// buffer for IPC_STAT & IPC_SET
	unsigned short	*_array;	// array for GETALL & SETALL
	struct seminfo	*__buf;		// buffer for IPC_INFO
	void		*__pad;
};

int semctl(int, int, int, ...);
int semget(key_t, int, int);
int semop(int, struct sembuf *, size_t);

#endif
