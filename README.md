# Embedded OS Assignment

## Day 1

- 2 Tier and 3 Tier Embedded Systems
- Hardware
  - CPU
    - PC/ IP
    - GPRs
    - Flags
    - Stack Pointer (SP)
  - Memory
    - Code
    - Data
  - Peripheral
- Bare Metal Systems
- SP, SF, Stack
  - SP - Register inside a CPU -> pointing to the top of stack
  - Stack - Chunk of memory
  - SF - Frame created on the Stack when you call a function. Deleted when you return from the function
- Frame Pointer - points to the base of the frame
- How are arguments passed to the function
  - Stack
  - Registers

## Day 2

- Booting procedure

  - ROM BL
  - PBL
  - SBL (Uboot)
  - Kernel (Linux)
  - RFS (Buildroot)

## Day 3 and 4

- Makefile
- Toolchain

  - Build System
  - Host System
  - Target System

- Program

  - Program Sections
    - Text
    - Data
    - BSS
    - Heap
    - Stack

- Address Space

- Program vs Process

  - Program
    - Executable// Binary
    - Compiled
    - Dormant
  - Process
    - Thread
    - Process / Program under execution
    - Active

- OS

  - Process Management
  - Memory Management
  - I/O Management
    - Device Drivers
    - File System
    - Networking
    - GUI

- Kernel Mode vs User Mode

  - Kernel Mode aka Supervisor Mode
    - Kernel Space
    - Kernel Heap
    - Kernel Stack
  - User Mode
    - User Space
    - User Heap
    - User Stack

- Process ID (PID)

  - getpid()

- Man

  - man -k pid
  - man 2 getpid

- Process Control Block (PCB)

  - PID
  - Base Address of the Process
  - Size of the Address space

- Library Calls
- System Calls

- strace

- Differentiated between library and system call

- Shell

  - Command Line
  - Parsing
  - Built-in Commands
  - Shell Scripts

- Users and Groups

  - Users
    - User ID
    - Group ID
    - User Name
    - Group Name
    - Home Directory
    - Shell
  - Groups
    - Group ID
    - Group Name
    - Group Members

- Superuser

## Day 4

- Library

  - Static Libraries
    - .a
  - Dynamic Libraries aka Shared Object Libraries

    - Windows => .dll
    - Linux => .so

  - Standard Library
    - GCC -> libc.a / libc.so
    - Bundled as part of the compiler /toolchain
    - ANSI
    - eg. printf, strcpy, strlen, scanf, fopen
  - User Library/ Third Party Library
    - App Developer
    - eg. Your own arith functionality, mp3 decoding library

- Archive command to create and extract libraries

  - ar crv
  - ar x

- Assignment (Both: Static and Shared Object):

  - Repeat the demo shown in the class
  - Enhance the library to add mul and div functions
  - Update the library and send it to your friend to use it

- Syscalls

  - open, write and close
  - File Descriptors (fd)
  - Assignment: 1
    - Create a file
    - Write to the file
    - Close the file
  - Assignment: 2
    - Create a file
    - Read from the file
    - Print it on screen
    - Close the file
  - Explore
    - Return values for read and write system calls

## Day 5

- CPU (Uniprocessor)

  - Physical Hardware => PC, SP, GPR, Flags

- One CPU -> One Process at any given instance
- One CPU => Multiple process

- Memory

  - Each process given a separate address space
  - Address space is divided into 2 parts:
    - Text
    - Data
    - BSS
    - Heap
    - Stack

- Context

  - Contents of the registers PC, SP, GPR, Flags
  - Context Saving
    - Physical registers to Logical Copy (in memory)
  - Context Restoring
    - Logical Copy to Physical registers
  - Context Switching
    - Save the current context
    - Scheduling
    - Restore0 the new context

- Process State Diagram
  - New
  - Ready
  - Running
  - Waiting/ Blocked
  - Terminated/ Exit

## Day 6

- Batch Systems
- Multiuser Systems
- Multiprogramming
- Multitasking Systems
- Multiprocessing Systems
- Multithreading Systems

- Process Scheduling

  - Round Robin
  - Priority
  - FIFO
  - Shortest Job First

- Priority Based Scheduling

  - Preemptive Scheduling
  - Non-Preemptive Scheduling

- Shortest Job First

  - Preemptive Scheduling
  - Non-Preemptive Scheduling

- Response Times
- Throughput
  -Fork
  - Zombie Processes
  - Orphan Processes
  - Child inherits file descriptors from the parent

  # day7

- Interprocess Communication
  - Pipes
    - Unidrectional
    - Related processes
    - Data is Sequential
    - pipe, read, write, close
  - FIFO aka Named Pipes
    - Unidirectional
    - Unrelated processes
    - Data is Sequential
    - open,/home/madhusudhan/Pictures/Screenshot from 2022-06-02 17-29-10.png read, wirte, close

# Assignment

1. Write your own utility using system calls (open, read, write, close) to copy data from one file to another file. Essentially you are implementing a copy utility. Fullfledged utility should support the following options:

- Handling all the errors
- cp srcfile destfile

2. Write your own utility using library calls (fopen, fread, fwrite, fclose) to copy data from one file to another file. Essentially you are implementing a copy utility. Fullfledged utility should support the following options:

- Handling all the errors
- cp srcfile destfile

3. Research

- Which of the following programs took more time to copy file
  1. Small
  2. Medium
  3. Large
- Justify your results => Why does system call / library call take time to copy file.
![Screenshot from 2022-06-04 11-30-56](https://user-images.githubusercontent.com/105910992/171986760-e86ce737-da0c-4f15-ac18-1089bc4d6209.png)

 using copy utility "cps" and " cpl " performing 1GB file operations
|     buf size  |      cps      | cpl   |
| ------------- |:-------------:| -----:|
| 1000bytes     | 2m14s.997s    |3m07.9s|
| 1000000       |  7.8850s      | 41.6  |
| 1000000000    |   0.766s      |0.4733 |

 using copy utility "cps" and " cpl " performing 400mb file operations
|     buf size  |      cps      | cpl   |
| ------------- |:-------------:| -----:|
| 1000bytes     | 5.833s        |19.647s|
| 1000000       |  0.743s       |8.953s |
| 1000000000    |   0.431s      |0.2533s|

 using copy utility "cps" and " cpl " performing 1mb file operations
|     buf size  |      cps      | cpl   |
| ------------- |:-------------:| -----:|
| 1000bytes     | 0.4699s       | 0.745 |
| 1000000       |  0.003        | 0.177 |
| 1000000000    |   0.455       | 0.427 |

 - posix threads
 - pthread_create

# Day 8

- POSIX Threads

  - pthread_create
  - pthread_join

- Threads

  - Joinable and Detachable

- Thread Attributes

  - pthread_attr_init
  - pthread_attr_setdetachstate
  - pthread_attr_destroy
  - Scope
  - Inherit Scheduling
  - Scheduling Parameters
  - Stack and Stack Size

- Threads

  - are light weight processes
  - TCB
  - Threads share the following sections with Process
    - Text
    - Data
    - BSS
    - Heap
  - Threads do not share the following sections with Process
    - Stack
    - means that each threads has its own stack

- Resource
  - Anything that is used by a thread or a process is called a resource
  - Shared Resource
    - Resource that is shared between multiple threads/ processes
    - Race Condition => Data corruption

 # day9
  - mutual Exclusion
    - mutex
      - futex
      - recursive mutex
      - error checking mutex
      - adaptive mutex
    - semaphores
    - Read write locks;

- mutex lock
 - lock
 - try lock
 - timed lock

- critical section
   - small as possible
 /usr/include/pthread.h



# day10 

- semaphores
  - binary semaphores
  - mutual exclusoin  => init =1
  - signaling
  - couting semaphores

  - **semaphore**
  - sem_t
  - sem_destroy
  - sem_wait => decrement => blocking => sem<=0
  - sem_post => Increment 1
  Counting Semaphore
   # day 11
  - signanling semaphore
  - Resource Management
  - sem_init => Maximum number of resources available => Same type

- Assignment: Use signalling semaphore for bilateral rendezvous (Task 1 and Task 2 => input and processing task respectively), when the initial value of both the semaphores is 1.
- Assignment: Memory Block Manager - Using the counting semaphore to manage the memory blocks.\
- ![Screenshot from 2022-06-08 23-11-33](https://user-images.githubusercontent.com/105910992/172779377-09ed3b79-f836-464a-97cf-e271b5603525.png)


- Read Write Locks

- Exec

  - Used to load a new program in the current address space of process
  - After exec no statments in the current process are executed

- Barriers

  - pthread_barrier_init
  - pthread_barrier_destroy
  - pthread_barrier_wait

- Conditional Variables (Condvars)

- Shared Memory

  - shm_open
  - ftruncate
  - mmap (attach the shared memory to the address space of the process)
  - Allocated in the User space
  - Fastest IPC
  - Race condition => Mutual Exclusion => Semaphores
  - Fixed size of data
  - Assignment:
    1. P1: Declare your own struct => {pid, ppid}
    2. P1: Tranfer struct to another process P2
    3. P2: Recv this struct and print it out

- Message Queues
  - mq_open
  - mq_send, mq_recv
  - Attributes => # number of messages, Max size of the message
  - In-built synchronization
  - Allows to communicate multiple messages and messages can be of different sizes
  - Assignment:
    1. P1: Declare your own struct => {pid, ppid}
    2. P1: Tranfer struct to another process P2
    3. P2: Recv this struct and print it out
- Sockets
