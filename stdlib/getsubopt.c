#include <stdlib.h>			// SuS non-sense: should be with getop()
#include <string.h>			// for strchr, strchr & strlen()

int getsubopt(char **optionp, char *const *tokens, char **valuep)
{
	char *opt;
	char *end;
	char *val;
	int idx;

	opt = optionp[0];
	if (!opt)
		return -1;

	end = strchr(opt, ',');
	if (!end)			// no ',' found; point to end of option
		end = opt + strlen(opt);
	else				// ',' found
	{
		*end = '\0';
		end++;
	}

	*optionp = end;

	val = strchr(opt, '=');
	if (val)			// '=' found
	{
		val++;			// now point to start of value
		val[-1] = '\0';		// temporary terminate the key
	}
	// update the value pointer
	*valuep = val;

	// check if key match a token
	for (idx = 0; tokens[idx]; idx++) {
		if (strcmp(opt, tokens[idx]) == 0)	// match!
			goto match;
	}
	// not found;
	idx = -1;

match:
	// restore the '=' if necessary
	if (val)
		val[-1] = '=';

	return idx;
}
