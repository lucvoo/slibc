#include <time.h>
#include <math.h>

static inline int ___isleap(int year)
{
	if ((year % 400) == 0)
		return 1;
	if (((year % 4) == 0) && ((year % 100) != 0))
		return 1;

	return 0;
}

static
time_t my_mktime(struct tm *tm)
{
	time_t t;
	int year = tm->tm_year;
	int leap;
	int days;

	if (year < 70)
		return -1;

	// adjust wday & yday;
	days = tm->tm_yday;

	leap = (year - 69) / 4;
	leap -= (year - 1) / 100;
	leap += (year + 299) / 400;

	t = (year - 70);
	t *= 365;
	t += leap;
	t += days;
	t *= 24;
	t += (tm->tm_hour);
	t *= 60;
	t += (tm->tm_min);
	t *= 60;
	t += (tm->tm_sec);

	return t;
}

static
const short __spm[12] = { 0,
	(31),
	(31 + 28),
	(31 + 28 + 31),
	(31 + 28 + 31 + 30),
	(31 + 28 + 31 + 30 + 31),
	(31 + 28 + 31 + 30 + 31 + 30),
	(31 + 28 + 31 + 30 + 31 + 30 + 31),
	(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31),
	(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30),
	(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31),
	(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30),
};

static
time_t diet_mktime(struct tm *t)
{
	time_t day;
	time_t i;

	if (t->tm_year < 70)
		return (time_t) - 1;

	day = t->tm_yday = __spm[t->tm_mon] + t->tm_mday - 1 +
		(___isleap(t->tm_year + 1900) & (t->tm_mon > 2));

	for (i = 70; i < t->tm_year; i++)
		day += 365 + ___isleap(i + 1900);

	// day is now the number of days since 'Jan 1 1970'
	i = 7;
	t->tm_wday = (day + 4) % i;

	i = 24;
	day *= i;
	i = 60;
	return ((day + t->tm_hour) * i + t->tm_min) * i + t->tm_sec;
}

#include <stdio.h>
static
const char *dayname[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

static void print_tm(time_t t, const struct tm *tm)
{
	printf("%s %02d/%02d/%04d %02d:%02d:%02d %3d => %10lu\n",
	       dayname[tm->tm_wday],
	       tm->tm_mday,
	       tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec, tm->tm_yday, t);
}

int main(void)
{
	int i, j, k;

	for (i = 70; i < 138; i++)
		for (j = 0; j < 12; j++)
			for (k = 1; k <= 31; k++) {
				struct tm t;
				time_t x, y, z;

				t.tm_year = i;
				t.tm_mon = j;
				t.tm_mday = k;
				t.tm_hour = 3;
				t.tm_min = 2;
				t.tm_sec = 1;
				t.tm_isdst = 0;

				z = diet_mktime(&t);
				print_tm(z, &t);

				y = my_mktime(&t);
				print_tm(y, &t);

				x = mktime(&t);
				print_tm(x, &t);

				if (y != z || y != x) {
					printf("! %10lu %10lu %10lu\n", x, y, z);
					printf("       %10ld %10ld\n", (x - y), (y - z));
				}
				putchar('\n');
			}

	return 0;
}
