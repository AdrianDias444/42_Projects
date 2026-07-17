    1. Introduction to Concurrent Programming
    
***
    Essential Concepts
****
**Thread in Operating Systems**:
- https://www.geeksforgeeks.org/operating-systems/thread-in-operating-system/
****

**Threads x Process**:
- https://www.geeksforgeeks.org/operating-systems/difference-between-process-and-thread/
****

**State of a Process in Operating Systems**:
- https://www.geeksforgeeks.org/operating-systems/states-of-a-process-in-operating-systems/
****

**Program Counter**:
- https://www.geeksforgeeks.org/operating-systems/what-is-program-counter/
****

**Data Races**:
- https://www.geeksforgeeks.org/operating-systems/race-condition-in-operating-systems/
****
**Registers**:
- https://www.geeksforgeeks.org/computer-organization-architecture/different-classes-of-cpu-registers/
****

**Clocks**:
- https://www.geeksforgeeks.org/distributed-systems/clock-synchronization-in-distributed-system/   
****

    Mechanism to Avoid Data Races:
**Atomic Operations in Operative System**:
- https://www.geeksforgeeks.org/operating-systems/atomic-operations-in-os/
****

**What is Spinlock in Operating System?**:
- https://www.geeksforgeeks.org/operating-systems/what-is-spinlock-in-operating-system/
****

**Mutex lock for Linux Thread Synchronization**:
- https://www.geeksforgeeks.org/linux-unix/mutex-lock-for-linux-thread-synchronization/
****

**Reader-Writer Locks**:
- https://medium.com/@humbertofilho_30158/reader-writer-locks-aaa64e154c4e
****

**Read-Copy Update (RCU)**:
- https://www.geeksforgeeks.org/operating-systems/read-copy-update-rcu/
****

**Compare-and-Swap Algorithm(CAS)**:
- https://algomaster.io/learn/concurrency-interview/compare-and-swap
****

**Lock types and their rules**:
- https://docs.kernel.org/locking/locktypes.html
****

    More general concepts
**Introduction of Deadlock in Operating System**:
- https://www.geeksforgeeks.org/operating-systems/introduction-of-deadlock-in-operating-system/
****

**Memory Management in Operating System**:
- https://www.geeksforgeeks.org/operating-systems/memory-management-in-operating-system/
****

**Process Control Block in Operating Systems**:
- https://www.geeksforgeeks.org/operating-systems/process-control-block-in-os/
****


**CPU Sheduling in Operating Systems**:
- https://www.geeksforgeeks.org/operating-systems/cpu-scheduling-in-operating-systems/
****

**FIFO (First-In-First-Out) approach in Programming**
- https://www.geeksforgeeks.org/dsa/fifo-first-in-first-out-approach-in-programming/
****

**Earliest Deadline First (EDF) CPU scheduling algorithm**
- https://www.geeksforgeeks.org/operating-systems/earliest-deadline-first-edf-cpu-scheduling-algorithm/
****



**Threadings**:
- https://www.geeksforgeeks.org/c/multithreading-in-c/
- https://www.reddit.com/r/C_Programming/comments/qtc2slmultithreading_in_c_writing_more_difficult/
- https://www.geeksforgeeks.org/c/thread-functions-in-c-c/
****

**Scheduler(FIFO and EDF)**:
- https://www.geeksforgeeks.org/operating-systems/process-schedulers-in-operating-system/
****
    2. Only for this Project (Codexion)
****
**Codexion**:
- https://dev.to/yel-bakk/thread-in-c-codexion-42-1ao
****

    3. More Material
****
**Data Races in the Linux Kernel**:
- https://www.youtube.com/watch?v=ylXuwNOVr0A (Video)
****

**Foundations of Multithreaded, Parallel, and Distributed Programming, Gregory R. Andrews, 1999**:
- https://github.com/mincongzhang/MultithreadingLearning (Repository with books)
****

**Introduction of Shared Memory Segment**:
- https://www.geeksforgeeks.org/dbms/introduction-of-shared-memory-segment/
****

**Understanding Atomics and Memory Ordering**:
- https://dev.to/kprotty/understanding-atomics-and-memory-ordering-2mom
****

**Memory Barriers in CPP**:
- https://medium.com/@harshadaggarwal1999/memory-barriers-in-c-171bf4f03ff4
****

PTHREAD_CREATE:

    int pthread_create(thread, attr, routine, arg);

    thread - pointer to pthread_t variable where the system can store the ID ot the new thread

    attr - Pointer to a thread attributes object that defines thread properties. Use NULL for default attributes.
    
    routine - Pointer to the function that the thread will execute. It must return void* and accept a void* argument.
    
    arg - A single argument passed to the thread function. Use NULL if no argument is needed. We can pass a struct or pointer to pass multiple values.


PTHREAD_JOIN:

    int pthread_join(thread, retval);

    thread - The ID of the thread you want to wait for. This is the thread that will be joined.

    retval - A pointer to a location where the exit status of the thread will be stored. This is optional and can be set to NULL if you do not need the return value of the thread.

PTHREAD_MUTEX_INIT:

    int pthread_mutex_init(mutex, attr);

    mutex - Pointer to a pthread_mutex_t variable that will be initialized. This mutex must be initialized before it can be used.

    attr - Pointer to a pthread_mutexattr_t object that specifies mutex attributes. Use NULL for default attributes (normal, non-recursive mutex).

PTHREAD_MUTEX_LOCK:

    int pthread_mutex_lock(mutex);

    mutex - Pointer to a pthread_mutex_t variable that has been previously initialized. If the mutex is already locked by another thread, the calling thread will block until the mutex becomes available.

PTHREAD_MUTEX_UNLOCK:

    int pthread_mutex_unlock(mutex);

    mutex - Pointer to a pthread_mutex_t variable that the calling thread currently holds locked. The mutex is released and becomes available for other threads to lock.

PTHREAD_MUTEX_DESTROY:

    int pthread_mutex_destroy(mutex);

    mutex - Pointer to a pthread_mutex_t variable to be destroyed. The mutex must be unlocked before calling this function. After destruction, the mutex cannot be used unless re-initialized.

PTHREAD_COND_INIT:

    int pthread_cond_init(cond, attr);

    cond - Pointer to a pthread_cond_t variable that will be initialized. This condition variable must be initialized before it can be used.

    attr - Pointer to a pthread_condattr_t object that specifies condition variable attributes. Use NULL for default attributes.

PTHREAD_COND_WAIT:

    int pthread_cond_wait(cond, mutex);

    cond - Pointer to a pthread_cond_t variable on which the thread will wait. The thread blocks until the condition is signaled or a spurious wakeup occurs.

    mutex - Pointer to a pthread_mutex_t that must be locked by the calling thread. The mutex is atomically released when the thread starts waiting and re-acquired before the function returns.

PTHREAD_COND_TIMEDWAIT:

    int pthread_cond_timedwait(cond, mutex, abstime);

    cond - Pointer to a pthread_cond_t variable on which the thread will wait. The thread blocks until the condition is signaled, a spurious wakeup occurs, or the timeout expires.

    mutex - Pointer to a pthread_mutex_t that must be locked by the calling thread. It is atomically released when waiting and re-acquired before returning.

    abstime - Pointer to a struct timespec specifying the absolute time (since Epoch) at which the wait should timeout if not signaled. This is an absolute time, not a relative duration.

PTHREAD_COND_SIGNAL:

    int pthread_cond_signal(cond);

    cond - Pointer to a pthread_cond_t variable to signal. This unblocks at least one thread that is currently waiting on this condition variable. If no threads are waiting, the signal has no effect.

PTHREAD_COND_BROADCAST:

    int pthread_cond_broadcast(cond);

    cond - Pointer to a pthread_cond_t variable to broadcast. This unblocks all threads that are currently waiting on this condition variable. If no threads are waiting, the broadcast has no effect.

PTHREAD_COND_DESTROY:

    int pthread_cond_destroy(cond);

    cond - Pointer to a pthread_cond_t variable to be destroyed. No threads should be waiting on the condition variable when it is destroyed. After destruction, the condition variable cannot be used unless re-initialized.

GETTIMEOFDAY:

    int gettimeofday(tv, tz);

    tv - Pointer to a struct timeval where the current time will be stored. The struct contains seconds (tv_sec) and microseconds (tv_usec) since the Epoch (January 1, 1970).

    tz - Pointer to a struct timezone for timezone information. This argument is obsolete and should always be set to NULL.

CLOCK_GETTIME:

    int clock_gettime(clk_id, tp);

    clk_id - Clock identifier specifying which clock to query. Common values: CLOCK_REALTIME (system-wide real-time clock), CLOCK_MONOTONIC (monotonic time since some unspecified starting point, not affected by system time changes).

    tp - Pointer to a struct timespec where the current time will be stored. The struct contains seconds (tv_sec) and nanoseconds (tv_nsec) since the clock's reference point.

USLEEP:

    int usleep(usec);

    usec - Number of microseconds to suspend the calling thread's execution. The thread is blocked for at least this duration, though actual sleep time may be slightly longer due to system scheduling granularity. Use 0 to yield the processor.


Mutex evita:
- Que dois coders leem actual_coder == NULL ao mesmo tempo e ambos escrevem o seu nome: