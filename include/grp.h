#ifndef _GRP_H
#define _GRP_H

#include "types/gid_t.h"
#include "types/size_t.h"		// FIXME: not defined int SuS

struct group {
	char		*gr_name;
	char		*gr_passwd;
	gid_t		gr_gid;
	char		**gr_mem;
};

struct group *getgrgid(gid_t gid);
struct group *getgrnam(const char *name);
int getgrgid_r(gid_t gid, struct group *, char *, size_t, struct group **);
int getgrnam_r(const char *name, struct group *, char *, size_t, struct group **);
struct group *getgrent(void);
void endgrent(void);
void setgrent(void);

#ifndef __STRICT_POSIX
int getgrent_r(struct group *, char *, size_t, struct group **);
int setgroups(size_t size, const gid_t * list);
int initgroups(const char *user, gid_t group);
#endif

#endif
