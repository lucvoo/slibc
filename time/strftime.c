#include <time.h>
#include <string.h>			// for strlen()
#include "libc/cdefs.h"

#include <assert.h>			// FIXME: to be removed

// FIXME: locale specific !!!

static
const char *days[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

static
const char *months[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

static inline void print_num(char *buff, size_t n, int num, char pad)
{
	do {
		unsigned digit;

		digit = num % 10;
		num = num / 10;
		buff[--n] = digit + '0';
	} while (num && n);

	while (n) {
		buff[--n] = pad;
	}
}

#define PUTC(C)		c = C;		goto do_putc
#define PUTX(S, N)	s = S; n = N;	goto do_putx
#define PUTS(S)		s = S;		goto do_puts
#define PUTI0(I, N)	i=I; n=N; pad='0'; 	goto do_puti;
#define PUTI_(I, N)	i=I; n=N; pad=' ';	goto do_puti;
#define FMT(F)		s = F;		goto do_strf

size_t strftime(char *dest, size_t size, const char *fmt, const struct tm *tm)
{
	char *end = dest + size;
	char *ptr;
	char c;
	const char *s;
	size_t n;

	for (ptr = dest; (c = *fmt); fmt++) {
		char pad;
		int i;

		if (c != '%')
			goto do_putc;

		fmt++;			// skip the '%'
		switch (c = *fmt) {
		case '%':
			PUTC(c);

		case 'E':		// FIXME: ignored in C/POSIX locale
		case 'O':
			break;

		case 'a':
			PUTX(days[tm->tm_wday], 3);

		case 'A':
			PUTS(days[tm->tm_wday]);

		case 'h':
		case 'b':
			PUTX(months[tm->tm_mon], 3);

		case 'B':
			PUTS(months[tm->tm_mon]);

		case 'c':
			FMT("%a %b %e %T %Y");

		case 'C':
			PUTI0(tm->tm_year / 100, 2);

		case 'd':
			PUTI0(tm->tm_mday, 2);

		case 'x':
		case 'D':
			FMT("%m/%d/%y");

		case 'e':
			PUTI_(tm->tm_mday, 2);

		case 'F':
			FMT("%Y-%m-%d");

		case 'H':
			PUTI0(tm->tm_hour, 2);

		case 'I':
			PUTI0((tm->tm_hour - 1) % 12 + 1, 2);

		case 'j':
			PUTI0(tm->tm_yday, 3);

		case 'm':
			PUTI0(tm->tm_mon + 1, 2);

		case 'M':
			PUTI0(tm->tm_min, 2);

		case 'n':
			PUTC('\n');

		case 'p':
			if (tm->tm_hour <= 12) {
				PUTX("AM", 2);
			} else {
				PUTX("PM", 2);
			}

		case 'r':
			FMT("%I:%M:%S %p");

		case 'R':
			FMT("%H:%M");

		case 'S':
			PUTI0(tm->tm_sec, 2);

		case 't':
			PUTC('\t');

		case 'X':
		case 'T':
			FMT("%H:%M:%S");

		case 'u':
			i = tm->tm_wday;
			if (i == 0)
				i = 7;
			PUTC('0' + i);

		case 'U':
			i = tm->tm_wday;
			i = (tm->tm_yday - i + 7) / 7;
			// FIXME: to be verified
			PUTI0(i, 2);

		case 'w':
			PUTI0('0' + tm->tm_wday, 1);

		case 'W':
			i = (tm->tm_wday + 6) % 7;
			i = (tm->tm_yday - i + 7) / 7;
			// FIXME: to be verified
			PUTI0(i, 2);

		case 'y':
			PUTI0(tm->tm_year % 100, 2);

		case 'Y':
			PUTI_(tm->tm_year + 1900, 4);
			// FIXME: will be truncate after 9999
			//        I don't think I'll live so long

		case 'z':		// time-zone stuff
		case 'G':		// FIXME: week based year
		case 'g':
		case 'V':

		default:
			assert(!"unsupported conversion");
		}
		continue;

do_puti:
		if (__unlikely((ptr + n) >= end))
			return 0;
		print_num(ptr, n, i, pad);
		ptr += n;
		continue;

do_puts:
		n = strlen(s);
do_putx:
		if (__unlikely((ptr + n) >= end))
			return 0;

		__builtin_memcpy(ptr, s, n);
		ptr += n;
		continue;

do_putc:
		if (__unlikely((ptr + 1) >= end))
			return 0;

		*ptr = c;
		ptr += 1;
		continue;

do_strf:
		n = strftime(ptr, end - ptr, s, tm);
		if (n == 0)
			return 0;

		ptr += n;
		continue;
	}

	if (ptr >= end)
		return 0;		// no place for trailing null

	ptr[0] = '\0';

	return ptr - dest;
}
