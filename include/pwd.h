#ifndef _PWD_H
#define _PWD_H

#include "types/gid_t.h"
#include "types/uid_t.h"
#include "types/size_t.h"		// FIXME: not defined int SuS

struct passwd {
	char		*pw_name;
	uid_t		pw_uid;
	gid_t		pw_gid;
	char		*pw_dir;
	char		*pw_shell;
	char		*pw_gecos;
	char		*pw_passwd;
};

struct passwd *getpwnam(const char *name);
struct passwd *getpwuid(uid_t uid);
int getpwnam_r(const char *name, struct passwd *, char *, size_t, struct passwd **);
int getpwuid_r(uid_t uid, struct passwd *, char *, size_t, struct passwd **);
void endpwent(void);
struct passwd *getpwent(void);
void setpwent(void);

#ifndef __STRICT_POSIX
int getpwent_r(struct passwd *, char *, size_t, struct passwd **);
#endif

#endif
