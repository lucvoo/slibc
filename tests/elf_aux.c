#include <stdio.h>

#define AT_NULL   0	// end of vector
#define AT_IGNORE 1	// entry should be ignored
#define AT_EXECFD 2	// file descriptor of program
#define AT_PHDR   3	// program headers for program
#define AT_PHENT  4	// size of program header entry
#define AT_PHNUM  5	// number of program headers
#define AT_PAGESZ 6	// system page size
#define AT_BASE   7	// base address of interpreter
#define AT_FLAGS  8	// flags
#define AT_ENTRY  9	// entry point of program
#define AT_NOTELF 10	// program is not ELF
#define AT_UID    11	// real uid
#define AT_EUID   12	// effective uid
#define AT_GID    13	// real gid
#define AT_EGID   14	// effective gid
#define AT_PLATFORM 15	// string identifying CPU for optimizations
#define AT_HWCAP  16	// arch dependent hints at CPU capabilities
#define AT_CLKTCK 17	// frequency at which times() increments
#define AT_SECURE 23	// secure mode boolean

const char *tbl[] = {
	[AT_NULL]	= "AT_NULL",
	[AT_IGNORE]	= "AT_IGNORE",
	[AT_EXECFD]	= "AT_EXECFD",
	[AT_PHDR]	= "AT_PHDR",
	[AT_PHENT]	= "AT_PHENT",
	[AT_PHNUM]	= "AT_PHNUM",
	[AT_PAGESZ]	= "AT_PAGESZ",
	[AT_BASE]	= "AT_BASE",
	[AT_FLAGS]	= "AT_FLAGS",
	[AT_ENTRY]	= "AT_ENTRY",
	[AT_NOTELF]	= "AT_NOTELF",
	[AT_UID]	= "AT_UID",
	[AT_EUID]	= "AT_EUID",
	[AT_GID]	= "AT_GID",
	[AT_EGID]	= "AT_EGID",
	[AT_PLATFORM]	= "AT_PLATFORM",
	[AT_HWCAP]	= "AT_HWCAP",
	[AT_CLKTCK]	= "AT_CLKTCK",
	[AT_SECURE]	= "AT_SECURE",
};

// FIXME: include ELF header
struct elf_aux {
	unsigned int type;
	unsigned int value;
};

int main(int argc, char *argv[], char *envp[])
{
	struct elf_aux *auxp;
	char **tmp;

	// make gcc happy
	(void)argc;
	(void)argv;

	// search for end of envp == start of auxp
	for (tmp = envp; *tmp; tmp++) ;
	tmp++;

	// loop over all AUX key-values pair
	for (auxp = (void *)tmp; auxp->type; auxp++) {
		if (auxp->type < (sizeof(tbl) / sizeof(tbl[0])) && tbl[auxp->type])
			printf("%s:\t%x\n", tbl[auxp->type], auxp->value);
		else
			printf("%u:\t%x\n", auxp->type, auxp->value);
		if (auxp->type == 15) {
			printf("PLATFORM='%s'\n", (char *)auxp->value);
		}
	}

	return 0;
}
