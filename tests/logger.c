/*
 * Copyright (c) 1983, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * 1999-02-22 Arkadiusz Mi¶kiewicz <misiek@pld.ORG.PL>
 * - added Native Language Support
 * Sun Mar 21 1999 - Arnaldo Carvalho de Melo <acme@conectiva.com.br>
 * - fixed strerr(errno) in gettext calls
 */

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SYSLOG_NAMES
#include <syslog.h>

#define LOG_PRIMASK     0x07
#define LOG_FACMASK     0x03f8
#define LOG_NFACILITIES 24
#define LOG_MAKEPRI(fac, pri)   (((fac) << 3) | (pri))

#define INTERNAL_NOPRI  0x10		// the "no priority" priority
				// mark "facility"
#define INTERNAL_MARK   LOG_MAKEPRI(LOG_NFACILITIES, 0)
typedef struct _code {
	const char *c_name;
	int c_val;
} CODE;

CODE prioritynames[] = {
	{"alert", LOG_ALERT},
	{"crit", LOG_CRIT},
	{"debug", LOG_DEBUG},
	{"emerg", LOG_EMERG},
	{"err", LOG_ERR},
	{"error", LOG_ERR},		// DEPRECATED
	{"info", LOG_INFO},
	{"none", INTERNAL_NOPRI},	// INTERNAL
	{"notice", LOG_NOTICE},
	{"panic", LOG_EMERG},		// DEPRECATED
	{"warn", LOG_WARNING},		// DEPRECATED
	{"warning", LOG_WARNING},
	{NULL, -1}
};

CODE facilitynames[] = {
	{"auth", LOG_AUTH},
	{"authpriv", LOG_AUTHPRIV},
	{"cron", LOG_CRON},
	{"daemon", LOG_DAEMON},
	{"ftp", LOG_FTP},
	{"kern", LOG_KERN},
	{"lpr", LOG_LPR},
	{"mail", LOG_MAIL},
	{"mark", INTERNAL_MARK},	// INTERNAL
	{"news", LOG_NEWS},
	{"security", LOG_AUTH},		// DEPRECATED
	{"syslog", LOG_SYSLOG},
	{"user", LOG_USER},
	{"uucp", LOG_UUCP},
	{"local0", LOG_LOCAL0},
	{"local1", LOG_LOCAL1},
	{"local2", LOG_LOCAL2},
	{"local3", LOG_LOCAL3},
	{"local4", LOG_LOCAL4},
	{"local5", LOG_LOCAL5},
	{"local6", LOG_LOCAL6},
	{"local7", LOG_LOCAL7},
	{NULL, -1}
};

int decode(char *, CODE *);
int pencode(char *);

static
void usage(void)
{
	fprintf(stderr, "usage: logger [-is] [-f file] [-p pri] [-t tag]"
		" [-u socket] [ message ... ]\n");
}

static int optd = 0;

static int myopenlog(const char *sock)
{
	int fd;
	static struct sockaddr_un s_addr;	// AF_UNIX address of local logger

	if (strlen(sock) >= sizeof(s_addr.sun_path)) {
		printf("logger: openlog: pathname too long\n");
		exit(1);
	}

	s_addr.sun_family = AF_UNIX;
	(void)strcpy(s_addr.sun_path, sock);

	if ((fd = socket(AF_UNIX, optd ? SOCK_DGRAM : SOCK_STREAM, 0)) == -1) {
		printf("socket: %s.\n", strerror(errno));
		exit(1);
	}

	if (connect(fd, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1) {
		printf("connect: %s.\n", strerror(errno));
		exit(1);
	}
	return fd;
}

static void mysyslog(int fd, int logflags, int pri, char *tag, char *msg)
{
	char buf[1000], pid[30], *tp;
	const char *cp;
	time_t now;

	if (fd > -1) {
		if (logflags & LOG_PID)
			snprintf(pid, sizeof(pid), "[%d]", getpid());
		else
			pid[0] = 0;
		if (tag)
			cp = tag;
		else {
			cp = getlogin();
			if (!cp)
				cp = "<someone>";
		}
		(void)time(&now);
		tp = ctime(&now) + 4;

		snprintf(buf, sizeof(buf), "<%d>%.15s %.200s%s: %.400s", pri, tp, cp, pid, msg);

		if (write(fd, buf, strlen(buf) + 1) < 0)
			return;		// error
	}
}

/*
 * logger -- read and log utility
 *
 *      Reads from an input and arranges to write the result on the system
 *      log.
 */
int main(int argc, char **argv)
{
	int ch, logflags, pri;
	char *tag, buf[1024];
	char *usock = NULL;
	int LogSock = -1;

	tag = NULL;
	pri = LOG_NOTICE;
	logflags = 0;
	while ((ch = getopt(argc, argv, "f:ip:st:u:d")) != -1)
		switch ((char)ch) {
		case 'f':		// file to log
			if (freopen(optarg, "r", stdin) == NULL) {
				int errsv = errno;

				(void)fprintf(stderr, "logger: %s: %s.\n", optarg, strerror(errsv));
				exit(1);
			}
			break;
		case 'i':		// log process id also
			logflags |= LOG_PID;
			break;
		case 'p':		// priority
			pri = pencode(optarg);
			break;
		case 's':		// log to standard error
			logflags |= LOG_PERROR;
			break;
		case 't':		// tag
			tag = optarg;
			break;
		case 'u':		// unix socket
			usock = optarg;
			break;
		case 'd':
			optd = 1;	// use datagrams
			break;
		case '?':
		default:
			usage();
			exit(1);
		}
	argc -= optind;
	argv += optind;

	// setup for logging
	if (!usock)
		openlog(tag ? tag : getlogin(), logflags, 0);
	else
		LogSock = myopenlog(usock);

	(void)fclose(stdout);

	// log input line if appropriate
	if (argc > 0) {
		char *p, *endp;
		size_t len;

		for (p = buf, endp = buf + sizeof(buf) - 2; *argv;) {
			len = strlen(*argv);
			if (p + len > endp && p > buf) {
				if (!usock)
					syslog(pri, "%s", buf);
				else
					mysyslog(LogSock, logflags, pri, tag, buf);
				p = buf;
			}
			if (len > sizeof(buf) - 1) {
				if (!usock)
					syslog(pri, "%s", *argv++);
				else
					mysyslog(LogSock, logflags, pri, tag, *argv++);
			} else {
				if (p != buf)
					*p++ = ' ';
				memcpy(p, *argv++, len);
				*(p += len) = '\0';
			}
		}
		if (p != buf) {
			if (!usock)
				syslog(pri, "%s", buf);
			else
				mysyslog(LogSock, logflags, pri, tag, buf);
		}
	} else
		while (fgets(buf, sizeof(buf), stdin) != NULL) {
			/* glibc is buggy and adds an additional newline, so we have to
			 * remove it here until glibc is fixed */
			int len = strlen(buf);

			if (len > 0 && buf[len - 1] == '\n')
				buf[len - 1] = '\0';

			if (!usock)
				syslog(pri, "%s", buf);
			else
				mysyslog(LogSock, logflags, pri, tag, buf);
		}
	if (!usock)
		closelog();
	else
		close(LogSock);
	return 0;
}

/*
 *  Decode a symbolic name to a numeric value
 */
int pencode(char *s)
{
	char *save;
	int fac, lev;

	for (save = s; *s && *s != '.'; ++s) ;
	if (*s) {
		*s = '\0';
		fac = decode(save, facilitynames);
		if (fac < 0) {
			(void)fprintf(stderr, "logger: unknown facility name: %s.\n", save);
			exit(1);
		}
		*s++ = '.';
	} else {
		fac = LOG_USER;
		s = save;
	}
	lev = decode(s, prioritynames);
	if (lev < 0) {
		(void)fprintf(stderr, "logger: unknown priority name: %s.\n", save);
		exit(1);
	}
	return (lev & LOG_PRIMASK) | (fac & LOG_FACMASK);
}

int decode(char *name, CODE * codetab)
{
	CODE *c;

	if (isdigit(*name))
		return atoi(name);

	for (c = codetab; c->c_name; c++)
		if (!strcasecmp(name, c->c_name))
			return c->c_val;

	return -1;
}
