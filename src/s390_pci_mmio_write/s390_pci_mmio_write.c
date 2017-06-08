#define SYSCALL "s390_pci_mmio_write"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
S390_PCI_MMIO_WRITE(2)        System Calls Manual       S390_PCI_MMIO_WRITE(2)

NAME
       s390_pci_mmio_write,  s390_pci_mmio_read  -  transfer  data to/from PCI
       MMIO memory page

SYNOPSIS
       #include <asm/unistd.h>

       int s390_pci_mmio_write(unsigned long mmio_addr,
                               void *user_buffer, size_t length);
       int s390_pci_mmio_read(unsigned long mmio_addr,
                               void *user_buffer, size_t length);

DESCRIPTION
       The s390_pci_mmio_write() system call writes length bytes of data  from
       the user-space buffer user_buffer to the PCI MMIO memory location spec‐
       ified by mmio_addr.  The s390_pci_mmio_read() system call reads  length
       bytes  of data from the PCI MMIO memory location specified by mmio_addr
       to the user-space buffer user_buffer.

       These system calls must be used instead of  the  simple  assignment  or
       data-transfer  operations  that  are used to access the PCI MMIO memory
       areas mapped to user space on the Linux System z platform.  The address
       specified by mmio_addr must belong to a PCI MMIO memory page mapping in
       the caller's address space, and the data being written or read must not
       cross  a  page  boundary.   The length value cannot be greater than the
       system page size.

RETURN VALUE
       On success, s390_pci_mmio_write() and  s390_pci_mmio_read()  return  0.
       On  error,  -1  is  returned and errno is set to one of the error codes
       listed below.

ERRORS
       EFAULT The address in mmio_addr is invalid.

       EFAULT user_buffer does not point to a valid location in  the  caller's
              address space.

       EINVAL Invalid length argument.

       ENODEV PCI support is not enabled.

       ENOMEM Insufficient memory.

VERSIONS
       These system calls are available since Linux 3.19.

CONFORMING TO
       This Linux-specific system call is available only on the s390 architec‐
       ture.  The required PCI support is available beginning  with  System  z
       EC12.

NOTES
       Glibc  does  not provide a wrapper for this system call, use syscall(2)
       to call it.

SEE ALSO
       syscall(2)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux Programmer's Manual         2015-01-15            S390_PCI_MMIO_WRITE(2)
*/
