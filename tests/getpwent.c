#include <pwd.h>
#include <stdio.h>

int main(void)
{
	struct passwd *pwd;

	while ((pwd = getpwent())) {
		printf("%s:%s:%u:%u:%s:%s:%s\n",
		       pwd->pw_name, pwd->pw_passwd,
		       pwd->pw_uid, pwd->pw_gid, pwd->pw_gecos, pwd->pw_dir, pwd->pw_shell);
	}

	return 0;
}
