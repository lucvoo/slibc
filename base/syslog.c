#include <syslog.h>
#include <stdarg.h>
#include <time.h>			// for time(), strftime()
#include <stdio.h>			// for (v)snprintf()
#include <unistd.h>			// for getpid()
#include <fcntl.h>			// for FD_CLOEXEC
#include <string.h>			// for strncpy()
#include <sys/socket.h>
#include <sys/un.h>
#include <paths.h>
#include "libc/cdefs.h"

#include "assert.h"			// FIXME: to be removed

#define _LOG_GETPRI(pf) ((pf) &  0x7)
#define _LOG_GETFAC(pf) ((pf) & ~0x7)

#define default_tag	"(unknown)"
#define default_fac	_LOG_GETFAC(LOG_USER)

static int log_fac = default_fac;	// default facility
static int log_mask = 0xff;		// mask of priorities
static char log_tag[32] = default_tag;	// default 'ident'
static int log_fd = -1;
static int log_opt;

static
int do_openlog(void)
{
	if (log_fd == -1) {
		int fd;

		fd = socket(AF_UNIX, SOCK_DGRAM, 0);
		// FIXME: if fail, Glibc try SOCK_STREAM ???
		if (fd == -1)
			return fd;

		fcntl(fd, F_SETFD, FD_CLOEXEC);
		log_fd = fd;
	}

	return 0;
}

static
void do_closelog(void)
{
	if (log_fd != -1) {
		close(log_fd);
		log_fd = -1;
	}
}

////////////////////////////////////////////////////////////////////////

void vsyslog(int pri_fac, const char *fmt, va_list ap)
{
	int pri = _LOG_GETPRI(pri_fac);
	int fac = _LOG_GETFAC(pri_fac);
	char buff[2048];
	char tbuf[20];
	char pid[20];
	time_t now;
	struct tm tm;
	size_t len;
	int try;

	// FIXME: check for invalid priority/facility bits ??

	if ((LOG_MASK(pri) & log_mask) == 0)
		return;

	if (!fac)			// tricky: 0 correspond to LOG_KERN
		fac = log_fac;

	time(&now);
	strftime(tbuf, sizeof(tbuf), "%h %e %H:%M:%S", localtime_r(&now, &tm));
	if (log_opt & LOG_PID)
		snprintf(pid, sizeof(pid), "[%d]", getpid());
	else
		pid[0] = '\0';

	// print the header
	pri |= fac;
	len = snprintf(buff, 80, "<%d>%s %s%s: ", pri, tbuf, log_tag, pid);

	// print the body, reserve place for final '\n'
	len += vsnprintf(buff + len, sizeof(buff) - len - 1, fmt, ap);

	// truncate if overflow
	if (len > (sizeof(buff) - 1)) {
		len = sizeof(buff) - 1;
		buff[len - 1] = '\n';
		buff[len] = '\0';
	}
	assert(len < sizeof(buff));

	// ensure a final '\n'
	if (buff[len - 1] != '\n') {
		len++;
		buff[len - 1] = '\n';
		buff[len] = '\0';
	}
	assert(len < sizeof(buff));

	// write to stderr also
	if (log_opt & LOG_PERROR) {
		write(STDERR_FILENO, buff, len);
	}
	// send this message to syslogd unix socket

	// FIXME: should ignore SIGPIPE
	// FIXME: can we use flag MSG_NOSIGNAL ??

	// try to send;
	for (try = 3; try; try--) {
		static struct sockaddr_un addr_un = { AF_UNIX, _PATH_LOG };
		struct sockaddr *addr = (struct sockaddr *)&addr_un;
		int rc;

		rc = do_openlog();
		if (rc)
			continue;

		rc = sendto(log_fd, buff, len, 0, addr, sizeof(addr_un));
		if (__unlikely(rc < 0)) {
			do_closelog();
			continue;
		}
		goto end;
	}
	if ((log_opt & (LOG_CONS | LOG_PERROR)) == LOG_CONS) {
		int fd;

		fd = open(_PATH_CONSOLE, O_WRONLY | O_NOCTTY, 0);
		if (fd != -1) {
			write(fd, buff, len);
			close(fd);
		}
	}

end:
	// FIXME: restore SIGPIPE handler
	// FIXME: release lock

	return;
}

void syslog(int pri_fac, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vsyslog(pri_fac, fmt, ap);
	va_end(ap);
}

void openlog(const char *ident, int option, int facility)
{
	strncpy(log_tag, ident, sizeof(log_tag));
	log_tag[sizeof(log_tag) - 1] = '\0';

	// FIXME: check option validity ?
	// FIXME: check facility validity ?
	log_opt = option;
	log_fac = facility;

	if (log_opt & LOG_NDELAY)
		do_openlog();
}

void closelog(void)
{
	do_closelog();
	log_fac = default_fac;
	__builtin_memcpy(log_tag, default_tag, sizeof(default_tag));
}

int setlogmask(int new_mask)
{
	int old_mask;

	old_mask = log_mask;
	log_mask = new_mask;

	return old_mask;
}
