#include <config.h>

#if defined(__HAIKU__)

#include <mono/utils/mono-threads.h>
#include <pthread.h>
#include <kernel/OS.h>

void
mono_threads_core_get_stack_bounds (guint8 **staddr, size_t *stsize)
{
	thread_info info;
	get_thread_info(get_pthread_thread_id(pthread_self()), &info);
	
	*staddr = info.stack_base;
	*stsize = (size_t) (info.stack_end - info.stack_base);
}

#endif
