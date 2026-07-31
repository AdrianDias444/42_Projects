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




Data Races example
My coder struct has a action field, so coder->action

    ➜  Codexion git:(main) ✗ valgrind --tool=helgrind ./a.out
    ==13542== Helgrind, a thread error detector
    ==13542== Copyright (C) 2007-2024, and GNU GPL'd, by OpenWorks LLP et al.
    ==13542== Using Valgrind-3.25.1 and LibVEX; rerun with -h for copyright info
    ==13542== Command: ./a.out
    ==13542== 
    49642 1 has taken a dongle
    Dongle: A | First Coder in heap is 1
    Dongle: A | Second Coder in heap is 1
    49672 1 has taken a dongle
    Dongle: C | First Coder in heap is 1
    Dongle: C | Second Coder in heap is 1
    ==13542== ---Thread-Announcement------------------------------------------
    ==13542== 
    ==13542== Thread #3 was created
    ==13542==    at 0x4A1C8D3: clone (in /usr/lib/libc.so.6)
    ==13542==    by 0x4A1C9E6: __clone_internal_fallback (clone-internal.c:64)
    ==13542==    by 0x4A1C9E6: __clone_internal (clone-internal.c:109)
    ==13542==    by 0x497B33B: create_thread (pthread_create.c:298)
    ==13542==    by 0x497BFE0: pthread_create@@GLIBC_2.34 (pthread_create.c:858)
    ==13542==    by 0x48AC061: ??? (in /usr/lib/valgrind/vgpreload_helgrind-amd64-linux.so)
    ==13542==    by 0x4001EDB: ft_create_coder_thread (create_coder_thread.c:144)
    ==13542==    by 0x400126B: run_single_coder (main.c:6)
    ==13542==    by 0x4001420: main (main.c:44)
    ==13542== 
    ==13542== ---Thread-Announcement------------------------------------------
    ==13542== 
    ==13542== Thread #2 was created
    ==13542==    at 0x4A1C8D3: clone (in /usr/lib/libc.so.6)
    ==13542==    by 0x4A1C9E6: __clone_internal_fallback (clone-internal.c:64)
    ==13542==    by 0x4A1C9E6: __clone_internal (clone-internal.c:109)
    ==13542==    by 0x497B33B: create_thread (pthread_create.c:298)
    ==13542==    by 0x497BFE0: pthread_create@@GLIBC_2.34 (pthread_create.c:858)
    ==13542==    by 0x48AC061: ??? (in /usr/lib/valgrind/vgpreload_helgrind-amd64-linux.so)
    ==13542==    by 0x400218F: ft_create_monitor_thread (create_monitor_thread.c:89)
    ==13542==    by 0x40013EE: main (main.c:40)
    ==13542== 
    ==13542== ---Thread-Announcement------------------------------------------
    ==13542== 
    ==13542== Thread #1 is the program's root thread
    ==13542== 
    ==13542== ----------------------------------------------------------------
    ==13542== 
    ==13542== Possible data race during write of size 8 at 0x4B29058 by thread #3
    ==13542== Locks held: none
    ==13542==    at 0x400194E: ft_compile (create_coder_thread.c:8)
    ==13542==    by 0x4001DDA: coder_rotine (create_coder_thread.c:121)
    ==13542==    by 0x48AC26B: ??? (in /usr/lib/valgrind/vgpreload_helgrind-amd64-linux.so)
    ==13542==    by 0x497B797: start_thread (pthread_create.c:454)
    ==13542==    by 0x4A1C8E3: clone (in /usr/lib/libc.so.6)
    ==13542== 
    ==13542== This conflicts with a previous read of size 8 by thread #2
    ==13542== Locks held: none
    ==13542==    at 0x400204B: ft_monitor_routine (create_monitor_thread.c:62)
    ==13542==    by 0x48AC26B: ??? (in /usr/lib/valgrind/vgpreload_helgrind-amd64-linux.so)
    ==13542==    by 0x497B797: start_thread (pthread_create.c:454)
    ==13542==    by 0x4A1C8E3: clone (in /usr/lib/libc.so.6)
    ==13542==  Address 0x4b29058 is 24 bytes inside a block of size 112 alloc'd
    ==13542==    at 0x489F9D8: malloc (in /usr/lib/valgrind/vgpreload_helgrind-amd64-linux.so)
    ==13542==    by 0x40024C4: ft_create_coder (create_coder.c:8)
    ==13542==    by 0x4001617: ft_handle_circle (handle_circle.c:23)
    ==13542==    by 0x40012EB: main (main.c:25)
    ==13542==  Block was alloc'd by thread #1
    ==13542== 
    66973 1 is compilling
    ==13542== ----------------------------------------------------------------
    

The functions `compile()`, `debug()`, and `refactor()` in the `<create_coder_thread.c>` file were modifying `coder->action` to indicate which phase the coder is currently in. This is a problem because I cannot ensure that the write process is atomic. In my `ft_monitor_routine` in the `<create_monitor_thread.c>` file, I check the current state of the action field several times. In a multithreading context, this can obviously cause data races. To fix this, I added a `mutex_coder` field to the coder struct, and in any of these three functions (`compile()`, `debug()`, and `refactor()`), I added `pthread_mutex_lock` and `pthread_mutex_unlock` calls before and after.

---

Another problem that Helgrind showed me is the lack of a mutex on some heap. Here is how this data race works: for some reasons that I don’t know, in a function in `<heap_function.c>`, when I lock a mutex on a given dongle heap, at the same time I am accessing another dongle who haven't protection (mutex). This happens because, technically, each coder can access the same dongle. I modified the state of the dongle heap with `ft_heap_push_back()` and read the same data without protection with `return_last_coder()`, so sad.

# Helgrind Output
    ==23282== Possible data race during write of size 8 at 0x4B290A8 by thread #3
    ==23282== Locks held: 2, at addresses 0x4B29358 0x4B29410
    ==23282==    at 0x40025F9: ft_remove_from_heap (heap_functions.c:107)
    ==23282==    by 0x4001EAE: coder_rotine (create_coder_thread.c:154)
    ==23282==    by 0x48AC26B: ??? (in /usr/lib/valgrind/vgpreload_helgrind-amd64-linux.so)
    ==23282==    by 0x497B797: start_thread (pthread_create.c:454)
    ==23282==    by 0x4A1C8E3: clone (in /usr/lib/libc.so.6)
    ==23282== 
    ==23282== This conflicts with a previous read of size 8 by thread #5
    ==23282== Locks held: 1, at address 0x4B29690
    ==23282==    at 0x4002386: return_last_coder (heap_functions.c:18)
    ==23282==    by 0x400250B: ft_heap_push_back (heap_functions.c:76)
    ==23282==    by 0x4001BB3: ft_wait_dongle_be_free (create_coder_thread.c:71)
    ==23282==    by 0x4001E19: coder_rotine (create_coder_thread.c:145)
    ==23282==    by 0x48AC26B: ??? (in /usr/lib/valgrind/vgpreload_helgrind-amd64-linux.so)
    ==23282==    by 0x497B797: start_thread (pthread_create.c:454)
    ==23282==    by 0x4A1C8E3: clone (in /usr/lib/libc.so.6)
    ==23282==  Address 0x4b290a8 is 104 bytes inside a block of size 152 alloc'd
    ==23282==    at 0x489F9D8: malloc (in /usr/lib/valgrind/vgpreload_helgrind-amd64-linux.so)
    ==23282==    by 0x4002778: ft_create_coder (create_coder.c:8)
    ==23282==    by 0x4001607: ft_handle_circle (handle_circle.c:23)
    ==23282==    by 0x40012DB: main (main.c:25)
    ==23282==  Block was alloc'd by thread #1

How I fixed this: honestly, at this point in the project I hadn’t made the EDF yet, so I will make the decision to choose which coder in the heap will be selected to get the dongle in the `ft_wait_dongle_be_free()` function, so after this function finishes we can safely remove the coder from the heap. And yes, we haven’t made the `compile()` yet.

OK, so after this I went from 24 data races to 20.
I was passing `coder->simulation->mutex` and
directly accessing and reading `coder->simulation`
before locking the mutex.


OK, now we have 20 data races to fix.
To end this, I finally noticed that:
    
- When in `<create_coder_thread.c>` I pass `coder->simulation->mutex` to `ft_print_current_dongle_heap`, I am not passing the real memory space allocated earlier in `<create_coder.c>`.
- When this function receives this parameter, it is in fact a duplicated one.
Yeah "mutex" variable is a copy.

        void ft_print_current_dongle_heap(pthread_mutex_t mutex, t_dongle* dongle)

To fix this, you can change the prototype of the function and pass not the mutex but the memory address of a mutex variable, like this:

        void ft_print_current_dongle_heap(pthread_mutex_t* mutex, t_dongle* dongle)

So when you call the function, instead of passing:

    coder->simulation->mutex

You will need to pass:

    &coder->simulation->mutex




Before:

    ft_print_current_dongle_heap(coder->simulation->mutex, first);
    ft_print_current_dongle_heap(coder->simulation->mutex, second);


After:

    ft_print_current_dongle_heap(&coder->simulation->mutex, first);
    ft_print_current_dongle_heap(&coder->simulation->mutex, second);


So now you can rest:

    Simulation done
    ==39296== 
    ==39296== Use --history-level=approx or =none to gain increased speed, at
    ==39296== the cost of reduced accuracy of conflicting-access information
    ==39296== For lists of detected and suppressed errors, rerun with: -s
    ==39296== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 124094700 from 150)

One tip maybe in this projects or better in resolution of data races
gdb can not be your best solution, the chance of Heisenbug is big.
Helgrind probably will save your ass.