#define SYSCALL "exit_group"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
EXIT_GROUP(2)              Linux Programmer's Manual             EXIT_GROUP(2)

NAME
       exit_group - exit all threads in a process

SYNOPSIS
       #include <linux/unistd.h>

       void exit_group(int status);

DESCRIPTION
       This system call is equivalent to exit(2) except that it terminates not
       only the calling thread, but  all  threads  in  the  calling  process's
       thread group.

RETURN VALUE
       This system call does not return.

VERSIONS
       This call is present since Linux 2.5.35.

CONFORMING TO
       This call is Linux-specific.

NOTES
       Since glibc 2.3, this is the system call invoked when the exit(2) wrap‐
       per function is called.

SEE ALSO
       exit(2)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2008-11-27                     EXIT_GROUP(2)
*/
