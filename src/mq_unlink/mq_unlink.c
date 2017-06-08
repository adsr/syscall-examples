#define SYSCALL "mq_unlink"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
MQ_UNLINK(3)               Linux Programmer's Manual              MQ_UNLINK(3)

NAME
       mq_unlink - remove a message queue

SYNOPSIS
       #include <mqueue.h>

       int mq_unlink(const char *name);

       Link with -lrt.

DESCRIPTION
       mq_unlink()  removes  the  specified  message  queue name.  The message
       queue name is removed immediately.  The queue itself is destroyed  once
       any  other  processes  that have the queue open close their descriptors
       referring to the queue.

RETURN VALUE
       On success mq_unlink() returns 0; on error, -1 is returned, with  errno
       set to indicate the error.

ERRORS
       EACCES The  caller  does  not  have  permission  to unlink this message
              queue.

       ENAMETOOLONG
              name was too long.

       ENOENT There is no message queue with the given name.

ATTRIBUTES
       For  an  explanation  of  the  terms  used   in   this   section,   see
       attributes(7).

       ┌────────────┬───────────────┬─────────┐
       │Interface   │ Attribute     │ Value   │
       ├────────────┼───────────────┼─────────┤
       │mq_unlink() │ Thread safety │ MT-Safe │
       └────────────┴───────────────┴─────────┘
CONFORMING TO
       POSIX.1-2001, POSIX.1-2008.

SEE ALSO
       mq_close(3),  mq_getattr(3),  mq_notify(3),  mq_open(3), mq_receive(3),
       mq_send(3), mq_overview(7)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-08-08                      MQ_UNLINK(3)
*/
