#ifndef _STDLIB_H
#define _STDLIB_H

#include <sys/cdefs.h>

#include <stddef.h>
#include <limits.h>
#include <math.h>
#include <sys/wait.h>

#include <malloc.h>

#define EXIT_FAILURE	1
#define EXIT_SUCCESS	0

#define NULL		((void*) 0)

#define RAND_MAX	INT_MAX

typedef struct {
	int		quot;
	int		rem;
} div_t;

typedef struct {
	long		quot;
	long		rem;
} ldiv_t;

typedef struct {
	long long	quot;
	long long	rem;
} lldiv_t;

typedef int (*__compar_fn_t) (const void *, const void *);

void _Exit(int status) __NORETURN;
long a64l(const char *s) __PURE;
void abort(void) __NORETURN;
int abs(int i) __CONST;
int atexit(void (*function) (void));
double atof(const char *str) __PURE;
int atoi(const char *str) __PURE;
long atol(const char *str) __PURE;
long long atoll(const char *str) __PURE;
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size,
	       __compar_fn_t compar);
div_t div(int numer, int denom) __CONST;
double drand48(void);
double erand48(unsigned short buf[3]);
void exit(int status) __NORETURN;
char *getenv(const char *name) __PURE;
int getsubopt(char **optionp, char *const *tokens, char **valuep);
int grantpt(int fd);
//char* initstate(unsigned, char*, size_t);
long jrand48(unsigned short buf[3]);
char *l64a(long value) __PURE;
long labs(long i) __CONST;
void lcong48(unsigned short param[7]);
long long llabs(long long i) __CONST;
ldiv_t ldiv(long numer, long denom) __CONST;
lldiv_t lldiv(long long numer, long long denom) __CONST;
long lrand48(void);
int mkstemp(char *template);
char *mktemp(char *template);
long mrand48(void);
long nrand48(unsigned short buf[3]);
int posix_memalign(void **, size_t, size_t);
int posix_openpt(int);
char *ptsname(int fd);
int putenv(char *string);
void qsort(void *base, size_t nmemb, size_t size, __compar_fn_t);
int rand(void);
int rand_r(unsigned *);
//int   random(void);
char *realpath(const char *restrict path, char *restrict real);
unsigned short *seed48(unsigned short buf[3]);
int setenv(const char *name, const char *value, int overwrite);
//void  setkey(const char* key);
//char* setstate(const char* state);
void srand(unsigned int seed);
void srand48(long seed);
//void  srandom(unsigned int seed);
float strtof(const char *restrict str, char **restrict endptr);
double strtod(const char *restrict str, char **restrict endptr);
long double strtold(const char *restrict str, char **restrict endptr);
long strtol(const char *restrict str, char **restrict endptr, int base);
long long strtoll(const char *restrict str, char **restrict endptr, int base);
unsigned long strtoul(const char *restrict str, char **restrict endptr, int base);
unsigned long long strtoull(const char *restrict str, char **restrict endptr, int base);
int system(const char *string);
int unlockpt(int fd);
int unsetenv(const char *name);

#ifndef __STRICT_POSIX
int getloadavg(double loadavg[], int nelem);
int getpt(void);
void *memalign(size_t, size_t);
int ptsname_r(int fd, char *buf, size_t size);
#endif

#endif
