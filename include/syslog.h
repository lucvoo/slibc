#ifndef _SYS_SYSLOG_H
#define _SYS_SYSLOG_H

// values for logopt of openlog
#define LOG_PID		0x01		// log the pid with each message
#define LOG_CONS	0x02		// log to the console on error
#define LOG_ODELAY	0x04		// delay open until syslog() is called
#define LOG_NDELAY	0x08		// connect to syslogd immediately
#define LOG_NOWAIT	0x10		// do not wait for child process
#define LOG_PERROR	0x20		// log to stderr as well

// facility codes
#define LOG_KERN	(0<<3)		// kernel messages
#define LOG_USER	(1<<3)		// user-level messages
#define LOG_MAIL	(2<<3)		// mail system
#define LOG_DAEMON	(3<<3)		// system daemons
#define LOG_AUTH	(4<<3)		// authorization messages
#define LOG_SYSLOG	(5<<3)		// internal for syslogd
#define LOG_LPR		(6<<3)		// line printer subsystem
#define LOG_NEWS	(7<<3)		// network news subsystem
#define LOG_UUCP	(8<<3)		// UUCP subsystem
#define LOG_CRON	(9<<3)		// clock daemon
#define LOG_AUTHPRIV	(10<<3)		// authorization messages (private)
#define LOG_FTP		(11<<3)		// ftp daemon

// reserved for local use
#define LOG_LOCAL0	(16<<3)		// reserved for local use
#define LOG_LOCAL1	(17<<3)		// reserved for local use
#define LOG_LOCAL2	(18<<3)		// reserved for local use
#define LOG_LOCAL3	(19<<3)		// reserved for local use
#define LOG_LOCAL4	(20<<3)		// reserved for local use
#define LOG_LOCAL5	(21<<3)		// reserved for local use
#define LOG_LOCAL6	(22<<3)		// reserved for local use
#define LOG_LOCAL7	(23<<3)		// reserved for local use

// values for priority
#define LOG_EMERG	0		// system is unusable
#define LOG_ALERT	1		// action must be taken immediately
#define LOG_CRIT	2		// critical conditions
#define LOG_ERR		3		// error conditions
#define LOG_WARNING	4		// warning conditions
#define LOG_NOTICE	5		// normal but significant condition
#define LOG_INFO	6		// informational
#define LOG_DEBUG	7		// debug-level messages

#define LOG_MASK(pri)	(1 << (pri))

void closelog(void);
void openlog(const char *ident, int option, int facility);
int setlogmask(int mask);
void syslog(int pri, const char *fmt, ...) __attribute__ ((format(printf, 2, 3)));

#ifndef __STRICT_POSIX
#include <types/va_list.h>
void vsyslog(int pri, const char *fmt, va_list) __attribute__ ((format(printf, 2, 0)));
#endif

#endif
