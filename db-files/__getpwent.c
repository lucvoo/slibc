#include "_pwd.h"
#include <ctype.h>			// for isdigit()

// Format: account:password:UID:GID:GECOS:directory:shell

// FIXME: Make the suppostion that db-files are correct
// FIXME: error handling

int __libc_getpwent(struct passwd *pwd, char *buf, size_t size, parse_state_t * ps)
{
	const char *pptr = ps->ptr;
	const char *pend = ps->end;
	char *bptr = buf;
	const char *bend = buf + size - 1;

	COPYstr(pwd->pw_name, ':');
	COPYstr(pwd->pw_passwd, ':');
	COPYul(pwd->pw_uid, ':');
	COPYul(pwd->pw_gid, ':');
	COPYstr(pwd->pw_gecos, ':');
	COPYstr(pwd->pw_dir, ':');
	COPYstr(pwd->pw_shell, ':');

	ps->ptr = pptr;
	return 0;

error:
	ps->ptr = pptr;
	return 1;
}
