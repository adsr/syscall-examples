#define SYSCALL "ipc"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
IPC(2)                     Linux Programmer's Manual                    IPC(2)

NAME
       ipc - System V IPC system calls

SYNOPSIS
       int ipc(unsigned int call, int first, int second, int third,
               void *ptr, long fifth);

DESCRIPTION
       ipc()  is  a  common  kernel entry point for the System V IPC calls for
       messages, semaphores, and shared memory.   call  determines  which  IPC
       function  to  invoke;  the  other  arguments  are passed through to the
       appropriate call.

       User programs should call the  appropriate  functions  by  their  usual
       names.   Only  standard library implementors and kernel hackers need to
       know about ipc().

CONFORMING TO
       ipc() is Linux-specific, and should not be used in programs intended to
       be portable.

NOTES
       On some architectures—for example x86-64 and ARM—there is no ipc() sys‐
       tem call; instead msgctl(2), semctl(2), shmctl(2), and so on really are
       implemented as separate system calls.

SEE ALSO
       msgctl(2),   msgget(2),  msgrcv(2),  msgsnd(2),  semctl(2),  semget(2),
       semop(2), semtimedop(2), shmat(2), shmctl(2), shmdt(2), shmget(2)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2012-10-16                            IPC(2)
*/
