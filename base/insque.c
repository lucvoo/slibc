#include <search.h>

void insque(void *_elem, void *_pred)
{
	struct qelem *elem = _elem;
	struct qelem *pred = _pred;
	struct qelem *next;

	next = pred->q_forw;
	pred->q_forw = elem;
	if (next)
		next->q_back = elem;

	elem->q_forw = next;
	elem->q_back = pred;
}
