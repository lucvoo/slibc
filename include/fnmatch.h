#ifndef _FNMATCH_H_
#define _FNMATCH_H_

#define FNM_PATHNAME	1
#define FNM_NOESCAPE	2
#define FNM_PERIOD	4

#ifndef __STRICT_POSIX
#define FNM_FILE_NAME	FNM_PATHNAME
#define FNM_LEADING_DIR	8
#define FNM_CASEFOLD	16
#endif

#define FNM_NOMATCH	1
#define FNM_NOSYS	(-1)

int fnmatch(const char *pattern, const char *string, int flags);

#endif
