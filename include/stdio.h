#ifndef _STDIO_H
#define _STDIO_H

#define BUFSIZ		4096		// FIXME: CONFIG

#define _IONBF		0
#define _IOLBF		1
#define _IOFBF		2

#define L_ctermid	9
#define L_tmpnam	20

#include "values/SEEK_.h"

#define FILENAME_MAX 	4095
#define FOPEN_MAX	16
#define TMP_MAX 	238328		// FIXME: ???

#define EOF		(-1)

#include "values/NULL.h"

#define P_tmpdir	"/tmp"

typedef struct __stdio_file FILE;
#include "types/fpos_t.h"
#include "types/va_list.h"
#include "types/size_t.h"

#include "types/off_t.h"

// Global variables
extern FILE *stderr;
extern FILE *stdin;
extern FILE *stdout;

void clearerr(FILE * S);
char *ctermid(char *s);
int fclose(FILE * S);
FILE *fdopen(int fd, const char *mode);
int feof(FILE * S);
int ferror(FILE * S);
int fflush(FILE * S);
int fgetc(FILE * S);
//int   fgetpos(FILE* restrict S, fpos_t* restrict pos);
char *fgets(char *restrict s, int n, FILE * restrict S);
int fileno(FILE * S);
FILE *fopen(const char *restrict filename, const char *restrict modes);
int fprintf(FILE * restrict S, const char *restrict format, ...);
int fputc(int c, FILE * S);
int fputs(const char *restrict s, FILE * restrict S);
size_t fread(void *restrict ptr, size_t size, size_t n, FILE * restrict S);
FILE *freopen(const char *restrict path, const char *restrict mode, FILE * restrict S);
//int   fscanf(FILE* restrict S, const char* restrict format, ...);
int fseek(FILE * S, long int off, int whence);
//int   fseeko(FILE* S, off_t off, int whence);
//int   fsetpos(FILE* S, const fpos_t* pos);
//long  ftell(FILE* S);
//off_t ftello(FILE* S);
size_t fwrite(const void *restrict ptr, size_t size, size_t n, FILE * restrict S);
int getc(FILE * S);
int getchar(void);
//char* gets(char* s);
int pclose(FILE * S);
void perror(const char *s);
FILE *popen(const char *command, const char *modes);
int printf(const char *restrict format, ...);
int putc(int c, FILE * S);
int putchar(int c);
int puts(const char *s);
int remove(const char *pathname);
int rename(const char *oldpath, const char *newpath);
void rewind(FILE * S);
//int   scanf(const char* restrict format, ...);
void setbuf(FILE * restrict S, char *restrict buf);
int setvbuf(FILE * restrict S, char *restrict buf, int modes, size_t n);
int snprintf(char *restrict s, size_t maxlen, const char *restrict format, ...)
	__attribute__ ((format(printf, 3, 4)));
int sprintf(char *restrict s, const char *restrict format, ...);
//int   sscanf(const char* restrict s, const char* restrict format, ...);
//char* tempnam(const char* dir, const char* pfx) __MALLOC;
FILE *tmpfile(void);
//char* tmpnam(char* s);
//int   ungetc(int c, FILE* S);
int vfprintf(FILE * restrict S, const char *restrict format, va_list arg);
//int   vfscanf(FILE* restrict S, const char* restrict format, va_list arg) __attribute__((format(scanf, 2, 0)));
int vprintf(const char *restrict format, va_list arg);
//int   vscanf(const char* restrict format, va_list arg) __attribute__((format(scanf, 1, 0)));
int vsnprintf(char *restrict s, size_t maxlen, const char *restrict format, va_list arg)
	__attribute__ ((format(printf, 3, 0)));
int vsprintf(char *restrict s, const char *restrict format, va_list arg);
//int   vsscanf(const char* restrict s, const char* restrict format, va_list arg) __attribute__((format(scanf, 2, 0)));

// Macros
#define getchar()	getc(stdin)
#define putchar(c)	putc(c, stdout)

#ifndef __STRICT_POSIX

#include "types/ssize_t.h"

//int   fcloseall(void);
ssize_t getdelim(char **restrict linep, size_t * restrict np, int delim, FILE * restrict S);	// GNU
ssize_t getline(char **restrict linep, size_t * restrict np, FILE * restrict S);	// GNU
int getw(FILE * S);			// LEGACY
int putw(int w, FILE * S);		// LEGACY
//char* tmpnam_r(char* s);              // TSF

void setlinebuf(FILE * S);		// BSD
#endif

#endif
