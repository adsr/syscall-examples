#define SYSCALL "epoll_create1"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
EPOLL_CREATE(2)            Linux Programmer's Manual           EPOLL_CREATE(2)

NAME
       epoll_create, epoll_create1 - open an epoll file descriptor

SYNOPSIS
       #include <sys/epoll.h>

       int epoll_create(int size);
       int epoll_create1(int flags);

DESCRIPTION
       epoll_create()  creates  an  epoll(7) instance.  Since Linux 2.6.8, the
       size argument is ignored, but must be  greater  than  zero;  see  NOTES
       below.

       epoll_create()  returns  a  file  descriptor referring to the new epoll
       instance.  This file descriptor is used for all the subsequent calls to
       the  epoll  interface.   When  no  longer required, the file descriptor
       returned by epoll_create() should be closed by  using  close(2).   When
       all  file  descriptors referring to an epoll instance have been closed,
       the kernel destroys the instance and releases the associated  resources
       for reuse.

   epoll_create1()
       If  flags  is 0, then, other than the fact that the obsolete size argu‐
       ment is dropped, epoll_create1() is the same  as  epoll_create().   The
       following value can be included in flags to obtain different behavior:

       EPOLL_CLOEXEC
              Set the close-on-exec (FD_CLOEXEC) flag on the new file descrip‐
              tor.  See the description of the O_CLOEXEC flag in  open(2)  for
              reasons why this may be useful.

RETURN VALUE
       On  success,  these  system calls return a nonnegative file descriptor.
       On error, -1 is returned, and errno is set to indicate the error.

ERRORS
       EINVAL size is not positive.

       EINVAL (epoll_create1()) Invalid value specified in flags.

       EMFILE The per-user limit on the number of epoll instances  imposed  by
              /proc/sys/fs/epoll/max_user_instances   was   encountered.   See
              epoll(7) for further details.

       EMFILE The per-process limit on the number of open file descriptors has
              been reached.

       ENFILE The system-wide limit on the total number of open files has been
              reached.

       ENOMEM There was insufficient memory to create the kernel object.

VERSIONS
       epoll_create() was added to the kernel in version 2.6.  Library support
       is provided in glibc starting with version 2.3.2.

       epoll_create1()  was  added  to  the kernel in version 2.6.27.  Library
       support is provided in glibc starting with version 2.9.

CONFORMING TO
       epoll_create() is Linux-specific.

NOTES
       In  the  initial  epoll_create()  implementation,  the  size   argument
       informed  the  kernel of the number of file descriptors that the caller
       expected to add to the epoll instance.  The kernel used  this  informa‐
       tion  as a hint for the amount of space to initially allocate in inter‐
       nal data structures describing events.  (If necessary, the kernel would
       allocate  more  space  if the caller's usage exceeded the hint given in
       size.)  Nowadays, this hint is no longer required (the  kernel  dynami‐
       cally sizes the required data structures without needing the hint), but
       size must still be greater than zero, in order to ensure backward  com‐
       patibility when new epoll applications are run on older kernels.

SEE ALSO
       close(2), epoll_ctl(2), epoll_wait(2), epoll(7)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-12-28                   EPOLL_CREATE(2)
*/
