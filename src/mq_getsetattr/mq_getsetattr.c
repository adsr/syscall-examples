#define SYSCALL "mq_getsetattr"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
MQ_GETSETATTR(2)           Linux Programmer's Manual          MQ_GETSETATTR(2)

NAME
       mq_getsetattr - get/set message queue attributes

SYNOPSIS
       #include <sys/types.h>
       #include <mqueue.h>

       int mq_getsetattr(mqd_t mqdes, struct mq_attr *newattr,
                        struct mq_attr *oldattr);

       Note: There is no glibc wrapper for this system call; see NOTES.

DESCRIPTION
       Do not use this system call.

       This  is  the low-level system call used to implement mq_getattr(3) and
       mq_setattr(3).  For an explanation of how this  system  call  operates,
       see the description of mq_setattr(3).

CONFORMING TO
       This interface is nonstandard; avoid its use.

NOTES
       Glibc  does  not  provide a wrapper for this system call; call it using
       syscall(2).  (Actually, never call  it  unless  you  are  writing  a  C
       library!)

SEE ALSO
       mq_getattr(3), mq_overview(7)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2012-07-13                  MQ_GETSETATTR(2)
*/
