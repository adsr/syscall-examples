#define SYSCALL "bdflush"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
BDFLUSH(2)                 Linux Programmer's Manual                BDFLUSH(2)

NAME
       bdflush - start, flush, or tune buffer-dirty-flush daemon

SYNOPSIS
       #include <sys/kdaemon.h>

       int bdflush(int func, long *address);
       int bdflush(int func, long data);

DESCRIPTION
       Note: Since Linux 2.6, this system call is deprecated and does nothing.
       It is likely to disappear altogether in a future kernel release.  Nowa‐
       days,  the task performed by bdflush() is handled by the kernel pdflush
       thread.

       bdflush() starts, flushes,  or  tunes  the  buffer-dirty-flush  daemon.
       Only  a  privileged process (one with the CAP_SYS_ADMIN capability) may
       call bdflush().

       If func is negative  or  0,  and  no  daemon  has  been  started,  then
       bdflush() enters the daemon code and never returns.

       If func is 1, some dirty buffers are written to disk.

       If  func  is  2 or more and is even (low bit is 0), then address is the
       address of a long word, and the tuning parameter numbered (func-2)/2 is
       returned to the caller in that address.

       If  func  is  3  or more and is odd (low bit is 1), then data is a long
       word, and the kernel sets tuning parameter numbered (func-3)/2 to  that
       value.

       The set of parameters, their values, and their valid ranges are defined
       in the Linux kernel source file fs/buffer.c.

RETURN VALUE
       If func is negative or 0 and the daemon successfully starts,  bdflush()
       never  returns.   Otherwise, the return value is 0 on success and -1 on
       failure, with errno set to indicate the error.

ERRORS
       EBUSY  An attempt was made to  enter  the  daemon  code  after  another
              process has already entered.

       EFAULT address points outside your accessible address space.

       EINVAL An  attempt  was made to read or write an invalid parameter num‐
              ber, or to write an invalid value to a parameter.

       EPERM  Caller does not have the CAP_SYS_ADMIN capability.

CONFORMING TO
       bdflush() is Linux-specific and should not be used in programs intended
       to be portable.

SEE ALSO
       fsync(2), sync(2), sync(1)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2014-08-19                        BDFLUSH(2)
*/
