#define SYSCALL "getrandom"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
GETRANDOM(2)               Linux Programmer's Manual              GETRANDOM(2)

NAME
       getrandom - obtain a series of random bytes

SYNOPSIS
       #include <linux/random.h>

       int getrandom(void *buf, size_t buflen, unsigned int flags);

DESCRIPTION
       The  getrandom() system call fills the buffer pointed to by buf with up
       to buflen random bytes.  These bytes can be  used  to  seed  user-space
       random number generators or for cryptographic purposes.

       getrandom()  relies  on  entropy gathered from device drivers and other
       sources of environmental noise.  Unnecessarily reading large quantities
       of  data  will have a negative impact on other users of the /dev/random
       and /dev/urandom devices.  Therefore, getrandom() should  not  be  used
       for  Monte  Carlo  simulations  or  other programs/algorithms which are
       doing probabilistic sampling.

       By default, getrandom() draws entropy from the /dev/urandom pool.  This
       behavior  can  be  changed via the flags argument.  If the /dev/urandom
       pool has been initialized, reads of up to 256 bytes will always  return
       as  many bytes as requested and will not be interrupted by signals.  No
       such guarantees apply for larger buffer sizes.   For  example,  if  the
       call  is  interrupted  by  a  signal handler, it may return a partially
       filled buffer, or fail with the error EINTR.  If the pool has  not  yet
       been  initialized, then the call blocks, unless GRND_NONBLOCK is speci‐
       fied in flags.

       The flags argument is a bit mask that can contain zero or more  of  the
       following values ORed together:

       GRND_RANDOM
              If  this  bit  is  set,  then  random  bytes  are drawn from the
              /dev/random  pool  instead  of  the  /dev/urandom   pool.    The
              /dev/random  pool  is  limited  based on the entropy that can be
              obtained from environmental noise.  If the number  of  available
              bytes  in /dev/random is less than requested in buflen, the call
              returns just the available random bytes.  If no random bytes are
              available, the behavior depends on the presence of GRND_NONBLOCK
              in the flags argument.

       GRND_NONBLOCK
              By default, when reading from /dev/random, getrandom() blocks if
              no  random bytes are available, and when reading from /dev/uran‐
              dom, it blocks if the entropy pool has not yet been initialized.
              If  the  GRND_NONBLOCK  flag  is  set, then getrandom() does not
              block in these cases, but instead immediately  returns  -1  with
              errno set to EAGAIN.

RETURN VALUE
       On success, getrandom() returns the number of bytes that were copied to
       the buffer buf.  This may be less than the number  of  bytes  requested
       via  buflen  if  GRND_RANDOM  was  specified  in flags and insufficient
       entropy was present in the /dev/random pool, or if the system call  was
       interrupted by a signal.

       On error, -1 is returned, and errno is set appropriately.

ERRORS
       EINVAL An invalid flag was specified in flags.

       EFAULT The address referred to by buf is outside the accessible address
              space.

       EAGAIN The requested entropy was not available, and  getrandom()  would
              have blocked if the GRND_NONBLOCK flag was not set.

       EINTR  The  call  was interrupted by a signal handler; see the descrip‐
              tion of how interrupted read(2) calls on "slow" devices are han‐
              dled  with  and without the SA_RESTART flag in the signal(7) man
              page.

VERSIONS
       getrandom() was introduced in version 3.17 of the Linux kernel.

CONFORMING TO
       This system call is Linux-specific.

NOTES
   Maximum number of bytes returned
       As of Linux 3.19 the following limits apply:

       *  When reading from /dev/urandom,  a  maximum  of  33554431  bytes  is
          returned by a single call to getrandom() on a system where int has a
          size of 32 bits.

       *  When reading from /dev/random, a maximum of 512 bytes is returned.

   Initialization of the entropy pool
       The kernel collects bits of entropy from environment.   When  a  suffi‐
       cient  number  of  random  bits  has  been  collected, the /dev/urandom
       entropy pool is considered to be initialized.  This state  is  normally
       reached early in the system bootstrap phase.

   Interruption by a signal handler
       When  reading  from  /dev/urandom (GRND_RANDOM is not set), getrandom()
       will block until the entropy pool  has  been  initialized  (unless  the
       GRND_NONBLOCK  flag  was  specified).   If  a request is made to read a
       large number (more than 256) of bytes,  getrandom()  will  block  until
       those  bytes  have been generated and transferred from kernel memory to
       buf.  When reading from /dev/random (GRND_RANDOM is  set),  getrandom()
       will  block  until  some  random  bytes  become  available  (unless the
       GRND_NONBLOCK flag was specified).

       The behavior when a call to getrandom() that is blocked  while  reading
       from  /dev/urandom  is  interrupted  by a signal handler depends on the
       initialization state of the entropy buffer and  on  the  request  size,
       buflen.  If the entropy is not yet initialized, then the call will fail
       with the EINTR error.  If the entropy pool has been initialized and the
       request size is large (buflen > 256), the call either succeeds, return‐
       ing a partially filled buffer, or fails with the error EINTR.   If  the
       entropy  pool  has  been  initialized  and  the  request  size is small
       (buflen <= 256), then getrandom() will not fail with  EINTR.   Instead,
       it will return all of the bytes that have been requested.

       When  reading  from  /dev/random,  blocking requests of any size can be
       interrupted by a signal (the call fails with the error EINTR).

       Calling getrandom() to read /dev/urandom for small values  (<= 256)  of
       buflen is the preferred mode of usage.

       The  special  treatment of small values of buflen was designed for com‐
       patibility with OpenBSD's getentropy() system call.

       The user of getrandom() must always check the return value,  to  deter‐
       mine  whether  either  an  error occurred or fewer bytes than requested
       were returned.  In the case where  GRND_RANDOM  is  not  specified  and
       buflen  is  less  than  or  equal  to 256, a return of fewer bytes than
       requested should never happen, but the careful  programmer  will  check
       for this anyway!

   Choice of random device
       Unless  you  are  doing  long-term key generation (and perhaps not even
       then), you probably shouldn't be using GRND_RANDOM.  The  cryptographic
       algorithms  used for /dev/urandom are quite conservative, and so should
       be sufficient for all purposes.  The  disadvantage  of  GRND_RANDOM  is
       that  it  can block.  Furthermore, dealing with the partially fulfilled
       getrandom() requests that can occur when  using  GRND_RANDOM  increases
       code complexity.

   Emulating OpenBSD's getentropy()
       The  getentropy() system call in OpenBSD can be emulated using the fol‐
       lowing function:

           int
           getentropy(void *buf, size_t buflen)
           {
               int ret;

               if (buflen > 256)
                   goto failure;
               ret = getrandom(buf, buflen, 0);
               if (ret < 0)
                   return ret;
               if (ret == buflen)
                   return 0;
           failure:
               errno = EIO;
               return -1;
           }

BUGS
       As of Linux 3.19, the following bug exists:

       *  Depending on CPU load, getrandom()  does  not  react  to  interrupts
          before reading all bytes requested.

SEE ALSO
       random(4), urandom(4), signal(7)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-01-22                      GETRANDOM(2)
*/
