#ifndef _SYS_SWAP_H
#define _SYS_SWAP_H

#define SWAP_FLAG_PREFER	0x8000
#define SWAP_FLAG_PRIO_MASK	0x7fff
#define SWAP_FLAG_PRIO_SHIFT	0

#define MAX_SWAPFILES 32

int swapon(const char *path, int swapflags);
int swapoff(const char *path);

#endif
