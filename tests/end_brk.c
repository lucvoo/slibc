#include <unistd.h>
#include <stdio.h>

void *__sys_brk(void *end_data_segment);
extern void *__cur_brk;
extern char _end;

int main(void)
{
	void *brk;

	printf("     end => %p\n", &_end);

	brk = __sys_brk(0);
	printf("     brk => %p\n", brk);

	printf("_cur_brk => %p\n", __cur_brk);

	return 0;
}
