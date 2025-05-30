#ifndef _STD_THREAD_H
#define _STD_THREAD_H

#ifdef __cplusplus
extern "C" {
#endif
#if 0 /* so editors won't auto-indent due to the extern "C" { */
};
#endif

typedef struct _std_thread *std_thread;
typedef struct _std_thread_lock *std_thread_lock;

typedef void (*std_thread_routine)(void *args);

/* All of these return positive ('true') on success, zero ('false') on failure */
int std_thread_create(std_thread_routine start, void *args, std_thread *thread);
int std_thread_join(std_thread thread);
int std_thread_destroy(std_thread thread);

int std_thread_lock_create(std_thread_lock *lock);
void std_thread_lock_acquire(std_thread_lock lock);
void std_thread_lock_release(std_thread_lock lock);
void std_thread_lock_destroy(std_thread_lock lock);

#if 0 /* so editors won't auto-indent due to the extern "C" { */
{
#endif
#ifdef __cplusplus
};
#endif

#endif
