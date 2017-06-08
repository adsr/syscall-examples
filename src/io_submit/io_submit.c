#define SYSCALL "io_submit"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
IO_SUBMIT(2)               Linux Programmer's Manual              IO_SUBMIT(2)

NAME
       io_submit - submit asynchronous I/O blocks for processing

SYNOPSIS
       #include <linux/aio_abi.h>          /* Defines needed types *|

       int io_submit(aio_context_t ctx_id, long nr, struct iocb **iocbpp);

       Note: There is no glibc wrapper for this system call; see NOTES.

DESCRIPTION
       The io_submit() system call queues nr I/O request blocks for processing
       in the AIO context ctx_id.  The iocbpp argument should be an  array  of
       nr AIO control blocks, which will be submitted to context ctx_id.

RETURN VALUE
       On  success,  io_submit()  returns the number of iocbs submitted (which
       may be 0 if nr is zero).  For the failure return, see NOTES.

ERRORS
       EAGAIN Insufficient resources are available to queue any iocbs.

       EBADF  The file descriptor specified in the first iocb is invalid.

       EFAULT One of the data structures points to invalid data.

       EINVAL The AIO context specified by ctx_id is invalid.  nr is less than
              0.   The  iocb at *iocbpp[0] is not properly initialized, or the
              operation specified is invalid for the file  descriptor  in  the
              iocb.

       ENOSYS io_submit() is not implemented on this architecture.

VERSIONS
       The asynchronous I/O system calls first appeared in Linux 2.5.

CONFORMING TO
       io_submit()  is  Linux-specific and should not be used in programs that
       are intended to be portable.

NOTES
       Glibc does not provide a wrapper function for this  system  call.   You
       could  invoke  it  using syscall(2).  But instead, you probably want to
       use the io_submit() wrapper function provided by libaio.

       Note that the libaio wrapper function uses a  different  type  (io_con‐
       text_t)  for  the  ctx_id  argument.  Note also that the libaio wrapper
       does not follow the usual C library conventions for indicating  errors:
       on  error it returns a negated error number (the negative of one of the
       values  listed  in  ERRORS).   If  the  system  call  is  invoked   via
       syscall(2),  then  the  return  value follows the usual conventions for
       indicating an error: -1, with errno set  to  a  (positive)  value  that
       indicates the error.

SEE ALSO
       io_cancel(2), io_destroy(2), io_getevents(2), io_setup(2), aio(7)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2012-07-13                      IO_SUBMIT(2)
*/
