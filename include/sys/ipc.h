#ifndef _SYS_IPC_H
#define _SYS_IPC_H

#include <types/key_t.h>
#include <types/uid_t.h>
#include <types/gid_t.h>
#include <types/mode_t.h>

#define IPC_CREAT  00001000		// create if key is nonexistent
#define IPC_EXCL   00002000		// fail if key exists
#define IPC_NOWAIT 00004000		// return error on wait

#define IPC_PRIVATE ((key_t) 0)

#define IPC_RMID	0		// remove resource
#define IPC_SET		1		// set ipc_perm options
#define IPC_STAT	2		// get ipc_perm options
#define IPC_INFO	3		// see ipcs

struct ipc_perm {
	key_t		__key;
	uid_t		uid;
	gid_t		gid;
	uid_t		cuid;
	gid_t		cgid;
	mode_t		mode;
	unsigned short	__seq;
};

key_t ftok(const char *path, int id);

#endif
