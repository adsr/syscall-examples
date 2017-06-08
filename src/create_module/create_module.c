#define SYSCALL "create_module"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
CREATE_MODULE(2)           Linux Programmer's Manual          CREATE_MODULE(2)

NAME
       create_module - create a loadable module entry

SYNOPSIS
       #include <linux/module.h>

       caddr_t create_module(const char *name, size_t size);

       Note: No declaration of this function is provided in glibc headers; see
       NOTES.

DESCRIPTION
       Note: This system call is present only in kernels before Linux 2.6.

       create_module() attempts to create a loadable module entry and  reserve
       the  kernel memory that will be needed to hold the module.  This system
       call requires privilege.

RETURN VALUE
       On success, returns the kernel address at which the module will reside.
       On error, -1 is returned and errno is set appropriately.

ERRORS
       EEXIST A module by that name already exists.

       EFAULT name is outside the program's accessible address space.

       EINVAL The  requested  size  is  too  small  even for the module header
              information.

       ENOMEM The kernel could not allocate a contiguous block of memory large
              enough for the module.

       ENOSYS create_module()  is  not supported in this version of the kernel
              (e.g., the kernel is version 2.6 or later).

       EPERM  The caller was not privileged (did not have  the  CAP_SYS_MODULE
              capability).

VERSIONS
       This  system  call is present on Linux only up until kernel 2.4; it was
       removed in Linux 2.6.

CONFORMING TO
       create_module() is Linux-specific.

NOTES
       The create_module() system call is not supported by glibc.  No declara‐
       tion  is  provided  in  glibc headers, but, through a quirk of history,
       glibc does export an ABI for this system call.  Therefore, in order  to
       employ  this  system  call,  it  is  sufficient to manually declare the
       interface in your code; alternatively, you can invoke the  system  call
       using syscall(2).

SEE ALSO
       delete_module(2), init_module(2), query_module(2)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2014-05-10                  CREATE_MODULE(2)
*/
