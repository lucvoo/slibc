#ifndef _SYS_STATFS_H
#define _SYS_STATFS_H

#include "types/_kfsid_t.h"
#include <stdint.h>			// FIXME: should use __u32, ...

struct statfs {
	uint32_t		f_type;
	uint32_t		f_bsize;
	uint32_t		f_blocks;
	uint32_t		f_bfree;
	uint32_t		f_bavail;
	uint32_t		f_files;
	uint32_t		f_ffree;
	__kernel_fsid_t		f_fsid;
	uint32_t		f_namelen;
	uint32_t		f_frsize;
	uint32_t		f_spare[5];
};

struct statfs64 {
	uint32_t		f_type;
	uint32_t		f_bsize;
	uint64_t		f_blocks;
	uint64_t		f_bfree;
	uint64_t		f_bavail;
	uint64_t		f_files;
	uint64_t		f_ffree;
	__kernel_fsid_t		f_fsid;
	uint32_t		f_namelen;
	uint32_t		f_frsize;
	uint32_t		f_spare[5];
};

#endif
