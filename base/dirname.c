#include <libgen.h>
#include <string.h>

#include <stdio.h>
#include <assert.h>

char *dirname(char *path)
{
	char *c;

	if (!path)
		goto dot;

	if (path[0] == 0)
		goto dot;

	c = path + strlen(path) - 1;	// on last char of pathname

	while (*c == '/' && c != path)	// skip trailing '/'
		c--;
	while (*c != '/' && c != path)	// remove name part
		c--;

	if (*c != '/' && c == path)
		goto dot;

	while (*c == '/' && c != path)	// skip remaining '/'
		c--;

	c[1] = 0;
	return path;

dot:
	return (char *)".";		// FIXME: is this legal ??
}
