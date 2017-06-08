#define SYSCALL "inotify_rm_watch"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
INOTIFY_RM_WATCH(2)        Linux Programmer's Manual       INOTIFY_RM_WATCH(2)

NAME
       inotify_rm_watch - remove an existing watch from an inotify instance

SYNOPSIS
       #include <sys/inotify.h>

       int inotify_rm_watch(int fd, int wd);

DESCRIPTION
       inotify_rm_watch() removes the watch associated with the watch descrip‐
       tor wd from the inotify instance associated with  the  file  descriptor
       fd.

       Removing  a  watch  causes an IN_IGNORED event to be generated for this
       watch descriptor.  (See inotify(7).)

RETURN VALUE
       On success, inotify_rm_watch() returns zero.  On error, -1 is  returned
       and errno is set to indicate the cause of the error.

ERRORS
       EBADF  fd is not a valid file descriptor.

       EINVAL The  watch  descriptor  wd is not valid; or fd is not an inotify
              file descriptor.

VERSIONS
       Inotify was merged into the 2.6.13 Linux kernel.

CONFORMING TO
       This system call is Linux-specific.

SEE ALSO
       inotify_add_watch(2), inotify_init(2), inotify(7)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2010-10-15               INOTIFY_RM_WATCH(2)
*/
