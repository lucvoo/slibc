#include <time.h>
#include <math.h>
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
				time_t x;

				t.tm_year = i;
				t.tm_mon = j;
				t.tm_mday = k;
				t.tm_hour = 3;
				t.tm_min = 2;
				t.tm_sec = 1;
				t.tm_isdst = 0;

				x = mktime(&t);
				print_tm(x, &t);

				putchar('\n');
			}

	return 0;
}
