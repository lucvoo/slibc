#include "libc/printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>			// FIXME: to be removed
#include "libc/cdefs.h"

// values for flags
#define f_plus	 1U
#define f_left	 2U
#define f_hash	 4U
#define f_zero	 8U
#define f_spac	16U
#define f_quot	32U
#define f_upper 64U

#define NUMBUFSIZE	65

#define Write(B, S)	obj->write(obj->dest, B, S)
#define Putch(C)	obj->putch(C, obj->dest)

static
void padd(printf_t * obj, int len, unsigned int flags)
{
	static const char spaces[16] = "                ";
	static const char zeroes[16] = "0000000000000000";
	const char *pad;

	if (flags & f_zero)
		pad = zeroes;
	else
		pad = spaces;

	while (len >= 16) {
		Write(pad, 16);
		len -= 16;
	}
	if (len)
		Write(pad, len);
}

static
char *print_num(char *past, unsigned long long num, int neg, unsigned base,
		unsigned int flags, int prec)
{
	char *ptr = past;
	char *end = ptr - prec;
	int letter;

	letter = (flags & f_upper) ? 'A' - 10 : 'a' - 10;

	while (num) {
		unsigned int digit;

		digit = num % base;
		num /= base;
		if (digit <= 9)
			digit += '0';
		else
			digit += letter;
		*--ptr = digit;
	}

	// pad if necessary
	while (ptr > end)
		*--ptr = '0';

	// put a sign if necessary
	if (neg)
		*--ptr = '-';
	else if (flags & f_plus)
		*--ptr = '+';
	else if (flags & f_spac)
		*--ptr = ' ';

	return ptr;
}

// length qualifier
enum qualifier {
	q_none,
	q_hh,
	q_ll,
	q_j,
	q_t,
	q_z,
	q_h,
	q_l,
	q_L
};

int __stdio_vxprintf(printf_t * obj, const char *restrict fmt, va_list ap)
{
	int len = 0;
	int c;

	for (c = *fmt; c; c = *++fmt) {
		size_t prec, width;
		unsigned int flags;
		enum qualifier qual;
		int idx;

		// first process 'template'
		for (idx = 0; fmt[idx] && fmt[idx] != '%'; idx++) ;
		// POST= fmt[idx] == '\0' || fmt[idx] == '%'

		if (idx) {
			Write(fmt, idx);	// FIXME: error ?
			len += idx;
			fmt += idx;
		}
		if (*fmt == '\0')
			break;

		// set default value
		prec = 1;
		width = 0;		// FIXME: to check!
		flags = 0;

		if (fmt[1] == '%') {
			Putch('%');
			fmt++;
			len++;
			continue;
		}

flag:					// process the flags
		fmt++;
		switch (*fmt) {
		case '0':
			flags |= f_zero;
			goto flag;
		case '+':
			flags |= f_plus;
			goto flag;
		case '-':
			flags |= f_left;
			goto flag;
		case '#':
			flags |= f_hash;
			goto flag;
		case ' ':
			flags |= f_spac;
			goto flag;
		default:
			break;
		}
		if (flags & f_left)
			flags &= ~f_zero;
		if (flags & f_plus)
			flags &= ~f_spac;

		// process the width
		if ('1' <= *fmt && *fmt <= '9') {
			width = strtol(fmt, (char **)&fmt, 10);
			// FIXME: replace with ???
		} else if (*fmt == '*') {
			int w = va_arg(ap, int);
			if (w < 0) {
				width = -w;
				flags |= f_left;
			} else
				width = w;

			fmt++;
		}
		// process the precision
		if (*fmt == '.') {
			fmt++;

			if ('0' <= *fmt && *fmt <= '9') {
				prec = strtoul(fmt, (char **)&fmt, 10);
			} else if (*fmt == '*') {
				int p = va_arg(ap, int);
				prec = (p < 0) ? 0 : p;
				fmt++;
			} else
				prec = 0;
		}
		// process the qualifier
		// TODO: be more clever and only record the corresponding size
		switch (*fmt) {
		case 'h':
			if (fmt[1] == 'h') {
				qual = q_hh;
				fmt += 2;
			} else {
				qual = q_h;
				fmt++;
			}
			break;

		case 'l':
			if (fmt[1] == 'l') {
				qual = q_ll;
				fmt += 2;
			} else {
				qual = q_l;
				fmt++;
			}
			break;

		case 'j':
			qual = q_j;
			fmt++;
			break;
		case 't':
			qual = q_t;
			fmt++;
			break;
		case 'z':
			qual = q_z;
			fmt++;
			break;
		case 'L':
			qual = q_L;
			fmt++;
			break;

		default:
			qual = q_none;
		}

		// process the format itself
		switch (*fmt) {
			size_t n;
			int npad;
			int base;
			int neg;
			const char *s;
			unsigned long long u;
			long long i;

		case 'c':
			u = va_arg(ap, unsigned int);
			Putch(u);
			len += 1;
			break;

		case 's':
			s = va_arg(ap, const char *);
			if (!s)
				s = "<nil>";
			n = strlen(s);
print_it:
			npad = (width > n) ? (width - n) : 0;

			if (npad && !(flags & f_left)) {
				padd(obj, npad, flags);
				len += npad;
			}

			Write(s, n);
			len += n;

			if (npad && (flags & f_left)) {
				padd(obj, npad, flags);
				len += npad;
			}
			break;

// FIXME: take length qualifier in account !!!

		case 'd':
		case 'i':
			switch (qual) {
			case q_hh:
				i = va_arg(ap, int);
				break;
			case q_h:
				i = va_arg(ap, int);
				break;
			case q_none:
				i = va_arg(ap, int);
				break;
			case q_l:
				i = va_arg(ap, long);
				break;
			case q_z:
				i = va_arg(ap, ssize_t);
				break;
			case q_t:
				i = va_arg(ap, ptrdiff_t);
				break;
			case q_ll:
				i = va_arg(ap, long long);
				break;
			case q_j:
				i = va_arg(ap, intmax_t);
				break;
			default:
				goto error;
			}
			neg = (i < 0);
			if (neg)
				u = -i;
			else
				u = i;
			base = 10;
			goto number;

		case 'p':
			u = (ptrdiff_t) va_arg(ap, void *);
			neg = 0;
			base = 16;
			prec = sizeof(void *) * 2;
			goto number;

		case 'o':
			base = 8;
			goto unumber;

		case 'u':
			base = 10;
			goto unumber;

		case 'x':
			base = 16;
			goto unumber;

		case 'X':
			base = 16;
			flags |= f_upper;
			// Fall throught
unumber:
			neg = 0;
			switch (qual) {
			case q_hh:
				u = va_arg(ap, unsigned int);
				break;
			case q_h:
				u = va_arg(ap, unsigned int);
				break;
			case q_none:
				u = va_arg(ap, unsigned int);
				break;
			case q_l:
				u = va_arg(ap, unsigned long);
				break;
			case q_z:
				u = va_arg(ap, size_t);
				break;
// FIXME: need this?case q_t:   u=va_arg(ap, ptrdiff_t);        break;
			case q_ll:
				u = va_arg(ap, unsigned long long);
				break;
			case q_j:
				u = va_arg(ap, uintmax_t);
				break;
			default:
				goto error;
			}
			// Fall throught
number:
			{
				char numbuf[NUMBUFSIZE];
				char *endbuf = numbuf + NUMBUFSIZE;

				s = print_num(endbuf, u, neg, base, flags, prec);
				n = endbuf - s;

				goto print_it;
			}

#if 1
		case 'e':
		case 'E':
		case 'f':
		case 'F':
		case 'g':
		case 'G':
			{
				long double val;
#if 0
				int rc;
#endif

				if (qual == q_L)
					val = va_arg(ap, long double);
				else	// FIXME: ??
					val = va_arg(ap, double);

#if 0
				rc = print_fp(obj, val, flags, width, prec, *fmt);
				if (__unlikely(rc < 0))
					error ! ! !len += rc;
#else
				(void)val;
#endif
				break;
			}
#endif

		default:
error:
			fprintf(stderr, "ABORT: ignored printf format: '%c'\n", *fmt);
			exit(1);	// abort();
			// FIXME: ... ?
			;
		}
	}

	return len;
}
