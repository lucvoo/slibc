#include <time.h>

static
const char days[7][4] = { "Sun ", "Mon ", "Tue ", "Wed ", "Thu ", "Fri ", "Sat " };

static
const char mons[12][4] = { "Jan ", "Feb ", "Mar ", "Apr ", "May ", "Jun ",
	"Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec ",
};

#define bufcpy(buf, src, size)			\
	__builtin_memcpy(buf, src, size);	\
	buf += size

#define bufchr(buf, C)		\
	*buf++ = C

#define bufnu_(buf, num)		\
	if (num < 10)			\
	    buf[0] = ' ';		\
	else				\
	    buf[0] = '0' + num/10;	\
	buf[1] = '0' + num%10;		\
	buf += 2

#define bufnu0(buf, num)	\
	buf[0] = '0' + num/10;	\
	buf[1] = '0' + num%10;	\
	buf += 2

char *asctime_r(const struct tm *tm, char *buf)
{
	int hi_y = tm->tm_year / 100 + 19;
	int lo_y = tm->tm_year % 100;
	char *start = buf;

	bufcpy(buf, days[tm->tm_wday], 4);
	bufcpy(buf, mons[tm->tm_mon], 4);
	bufnu_(buf, tm->tm_mday);
	bufchr(buf, ' ');
	bufnu0(buf, tm->tm_hour);
	bufchr(buf, ':');
	bufnu0(buf, tm->tm_min);
	bufchr(buf, ':');
	bufnu0(buf, tm->tm_sec);
	bufchr(buf, ' ');
	bufnu0(buf, hi_y);
	bufnu0(buf, lo_y);
	bufchr(buf, '\n');
	bufchr(buf, '\0');

	return start;
}
