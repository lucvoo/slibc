#ifndef _LIBC_IPCCALL_H
#define _LIBC_IPCCALL_H

int __sys_ipc(unsigned int, int, int, int, void *, long);

#define IPCCALL(version, op)	(((version) << 16) | (op))

#define SEMOP            1
#define SEMGET           2
#define SEMCTL           3
#define MSGSND          11
#define MSGRCV          IPCCALL(1,12)
#define MSGGET          13
#define MSGCTL          14
#define SHMAT           21
#define SHMDT           22
#define SHMGET          23
#define SHMCTL          24

#endif
