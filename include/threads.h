#ifndef _THREADS_H_
#define _THREADS_H_

#include <time.h>

typedef struct cnd {
} cnd_t;

typedef struct thrd {
};

typedef struct tss {
};

typedef struct mtx {
} mtx_t;

typedef struct once_flag {
	volatile int flag;
} once_flag;

typedef void (*tss_dtor_t) (void *);
typedef int (*thrd_start_t) (void *);

enum {
	mtx_plain,
	mtx_try,
	mtx_timed,
	mtx_recursive,
};

enum {
	thrd_success,
	thrd_timeout,
	thrd_error,
	thrd_busy,
	thrd_nomem,
};

void call_once(once_flag * flag, void (*func) (void));
int cnd_broadcast(cnd_t * cond);
void cnd_destroy(cnd_t * cond);
int cnd_init(cnd_t * cond);
int cnd_signal(cnd_t * cond);
int cnd_timedwait(cnd_t * restrict cond, mtx_t * restrict mtx, const struct timespec *restrict ts);
int cnd_wait(cnd_t * cond, mtx_t * mtx);

void mtx_destroy(mtx_t * mtx);
int mtx_init(mtx_t * mtx, int type);
int mtx_lock(mtx_t * mtx);
int mtx_timedlock(mtx_t * restrict mtx, const struct timespec *restrict ts);
int mtx_trylock(mtx_t * mtx);
int mtx_unlock(mtx_t * mtx);

int thrd_create(thrd_t * thr, thrd_start_t func, void *arg);
thrd_t thrd_current(void);
int thrd_detach(thrd_t thr);
int thrd_equal(thrd_t thr0, thrd_t thr1);
__Noreturn void thrd_exit(int res);
int thrd_join(thrd_t thr, int *res);
void thrd_sleep(const struct timespec *duration, struct timespec *remaining);
void thrd_yield(void);

int tss_create(tss_t * key, tss_dtor_t dtor);
void tss_delete(tss_t key);
void *tss_get(tss_t key);
int tss_set(tss_t key, void *val);

#endif
