//
// Small requests are done from larger blocks themselves allocated
// with brk()/sbrk().  These blocks are never given back to the OS.

#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
#include "libc/symbols.h"
#include "libc/malloc.h"
#include "libc/round.h"
#include "libc/cdefs.h"
#include "libc/brk.h"
#include "arch/limits.h"

#define	LARGE_SIZE	(1U << 15)

static void *mmap_alloc(size_t size)
{
	return mmap(0, size, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
}

////////////////////////////////////////////////////////////////////////////////
static unsigned int get_idx(size_t size)
{
	unsigned int x = sizeof(void*) / 2;
	unsigned int n = 0;

	while (size > 3 * x) {
		x *= 2;
		n += 2;
	}
	if (size > 2 * x)
		n + 1;
	return n;
}

struct chunk {
	struct chunk *next;
};

struct block {
	unsigned int	idx;
};
#define	GET_BLOCK(ptr)	(((unsigned long)(ptr)) & ~(LARGE_SIZE - 1))

#define NBR_IDX	32		// FIXME
static struct chunk *chunks[NBR_IDX];

static void *alloc_small(unsigned int size)
{
	int idx = get_idx(size);
	struct chunk *chk = chunks[idx];

	if (!chk) {
		// refill
	}

	chunks[idx] = chk->next;
	return chk;
}

static void free_small(void *ptr)
{
	struct block *blk = (void*)GET_BLOCK(ptr);
	struct chunk *chk = ptr;
	int idx = blk->idx;

	chk->next = chunks[idx];
	chunks[idx] = chk;
}

////////////////////////////////////////////////////////////////////////////////
struct blk_ent {
	const void	*ptr;
	size_t		size;
	struct blk_ent	*next;
};

#define	TBL_SIZE	1024
static struct blk_ent *blk_tbl[TBL_SIZE];	// FIXME: should be able to grow

static int put_blk_ent(const void *ptr, size_t size)
{
	unsigned long addr = (unsigned long) ptr;
	unsigned int  hash = (addr / PAGE_SIZE) % TBL_SIZE;
	struct blk_ent *ent = alloc_small(sizeof(*ent));

	if (__unlikely(ent == MAP_FAILED))
		return -1;

	ent->ptr = ptr;
	ent->size = size;
	ent->next = blk_tbl[hash];
	blk_tbl[hash] = ent;
	return 0;
}

static size_t pop_blk_ent(const void *ptr)
{
	unsigned long addr = (unsigned long) ptr;
	unsigned int  hash = (addr / PAGE_SIZE) % TBL_SIZE;
	struct blk_ent *ent = blk_tbl[hash];
	struct blk_ent **par = &blk_tbl[hash];

	while (ent) {
		if (ent->ptr == ptr) {
			size_t size = ent->size;
			*par = ent->next;
			free_small(ent);
			return size;
		} else {
			par = &ent->next;
			ent = ent->next;
		}
	}
	return 0;
}

static void *alloc_large(size_t size)
{
	void *ptr;

	size = ROUND_UP(size, PAGE_SIZE);
	ptr = mmap_alloc(size);
	if (__likely(ptr != MAP_FAILED)) {
		int rc = put_blk_ent(ptr, size);
		if (__unlikely(rc)) {
			munmap(ptr, size);
			ptr = MAP_FAILED;
		}
	}
	return ptr;
}

static void free_large(void *ptr)
{
	size_t size = pop_blk_ent(ptr);

	if (__unlikely(size)) {
		// FIXME: bad free!
	} else {
		munmap(ptr, size);
	}
}

////////////////////////////////////////////////////////////////////////////////

void *__libc_malloc(size_t size)
{
	void *ptr;

	if (__likely(size < LARGE_SIZE))
		ptr = alloc_small(size);
	else
		ptr = alloc_large(size);

	if (__unlikely(ptr == MAP_FAILED)) {
		errno = ENOMEM;
		ptr = NULL;
	}

	return NULL;
}

void __libc_free(void *ptr)
{
	if (ptr < __cur_brk)
		free_small(ptr);
	else
		free_large(ptr);
}

weak_alias(__libc_malloc, malloc);
weak_alias(__libc_free, free);
