#include <search.h>

void remque(void *_elem)
{
	struct qelem *elem = _elem;
	struct qelem *next = elem->q_forw;
	struct qelem *prev = elem->q_back;

	if (next)
		next->q_back = prev;
	if (prev)
		prev->q_forw = next;
}
