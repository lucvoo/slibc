#ifndef _LIBC_SYSLOG_H
#define _LIBC_SYSLOG_H

#include <syslog.h>

#define _LOG_GETPRI(pf)	((pf) & 0x7)
#define _LOG_GETFAC(pf)	((pf) >> 3)

#define _LOG_LAST_FAC	_LOG_GETFAC(LOG_LOCAL7)

#endif
