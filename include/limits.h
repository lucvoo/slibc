#ifndef _LIMITS_H
#define _LIMITS_H

// FIXME: partly extracted from kernel's linux/limits.h

// invariants values
#define ARG_MAX       131072		// # bytes of args + environ for exec()
#define ATEXIT_MAX        32		// FIXME: CONFIG_ATEXIT_MAX
#define CHILD_MAX        999		// no limit :-)
// FIXME: #define HOST_NAME_MAX ?
// FIXME: #define IOV_MAX               ?
// FIXME: #define LOGIN_NAME_MAX        ?
#define OPEN_MAX         256		// # open files a process may have
#define RTSIG_MAX	  32
// FIXME: #define STREAM_MAX    ?
// FIXME: #define SYMLOOP_MAX   ?
// FIXME: #define TTY_NAME_MAX  ?
// FIXME: #define TZNAME_MAX    ?

// pathname variants values
// FIXME: #define FILESIZEBITS  ?
#define LINK_MAX         127		// # links a file may have
#define MAX_CANON        255		// size of the canonical input queue
#define MAX_INPUT        255		// size of the type-ahead buffer
#define NAME_MAX         255		// # chars in a file name
#define PATH_MAX        4096		// # chars in a path name including nul
#define PIPE_BUF        4096		// # bytes in atomic write to a pipe
// FIXME: #define SYMLINK_MAX   ?

// runtime increasable values
#define LINE_MAX	2048
#define NGROUPS_MAX     65536

// FIXME: #define NR_OPEN               1024    // non SuS

// Numerical limits
#define CHAR_BIT	8

#define UCHAR_MAX	255
#define SCHAR_MIN	(-128)
#define SCHAR_MAX	127

#ifdef __CHAR_UNSIGNED__
#define CHAR_MIN	0
#define CHAR_MAX	UCHAR_MAX
#else
#define CHAR_MIN	SCHAR_MIN
#define CHAR_MAX	SCHAR_MAX
#endif

#define USHRT_MAX	65535
#define SHRT_MAX	32767
#define SHRT_MIN	(-32768)

#include "arch/limits.h"

#define SSIZE_MAX	LONG_MAX

#endif
