#include <string.h>

// FIXME: is this correct ???

char *strtok_r(char *s, const char *seps, char **last)
{
	size_t n;

	if (!s)
		s = *last;
	else
		*last = s;

	// search the start of the token
	n = strspn(s, seps);
	s += n;
	if (*s == '\0')
		return NULL;

	// search the end of the token
	n = strcspn(s, seps);
	s[n] = '\0';

	// and keep this info for the next calls
	*last = s + n + 1;

	return s;
}
