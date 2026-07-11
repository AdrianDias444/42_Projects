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
PTHREAD_MUTEX_LOCK:
PTHREAD_MUTEX_UNLOCK:
PTHREAD_MUTEX_DESTROY:
PTHREAD_COND_INIT:
PTHREAD_COND_WAIT:
PTHREAD_COND_TIMEDWAIT:
PTHREAD_COND_SIGNAL:
PTHREAD_COND_BROADCAST:
PTHREAD_COND_DESTROY:
GETTIMEOFDAY:
CLOCK_GETTIME:
USLEEP:
