#ifndef _SYS_SYSINFO_H
#define _SYS_SYSINFO_H

#define SI_LOAD_SHIFT	16		// fixed point shift for loadavg

struct sysinfo {
	long		uptime;		// Seconds since boot
	unsigned long	loads[3];	// 1, 5, and 15 minute loads
	unsigned long	totalram;	// Total usable main memory
	unsigned long	freeram;	// Available memory size
	unsigned long	sharedram;	// Amount of shared memory
	unsigned long	bufferram;	// Memory used by buffers
	unsigned long	totalswap;	// Total swap space size
	unsigned long	freeswap;	// swap space still available
	unsigned short	procs;		// Number of current processes
	unsigned short	__pad;
	unsigned long	totalhigh;	// Total high memory size
	unsigned long	freehigh;	// Available high memory size
	unsigned int	mem_unit;	// Memory unit size in bytes
	char _f[20 - 2 * sizeof(long) - sizeof(int)];	// Padding
};

int sysinfo(struct sysinfo *info);

#endif
