#define SYSCALL "clock_settime"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
CLOCK_GETRES(2)            Linux Programmer's Manual           CLOCK_GETRES(2)

NAME
       clock_getres, clock_gettime, clock_settime - clock and time functions

SYNOPSIS
       #include <time.h>

       int clock_getres(clockid_t clk_id, struct timespec *res);

       int clock_gettime(clockid_t clk_id, struct timespec *tp);

       int clock_settime(clockid_t clk_id, const struct timespec *tp);

       Link with -lrt (only for glibc versions before 2.17).

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       clock_getres(), clock_gettime(), clock_settime():
              _POSIX_C_SOURCE >= 199309L

DESCRIPTION
       The  function  clock_getres()  finds  the resolution (precision) of the
       specified clock clk_id, and, if res  is  non-NULL,  stores  it  in  the
       struct timespec pointed to by res.  The resolution of clocks depends on
       the implementation and cannot be configured by  a  particular  process.
       If  the  time value pointed to by the argument tp of clock_settime() is
       not a multiple of res, then it is truncated to a multiple of res.

       The functions clock_gettime() and clock_settime() retrieve and set  the
       time of the specified clock clk_id.

       The  res  and  tp  arguments  are  timespec structures, as specified in
       <time.h>:

           struct timespec {
               time_t   tv_sec;        /* seconds *|
               long     tv_nsec;       /* nanoseconds *|
           };

       The clk_id argument is the identifier of the particular clock on  which
       to  act.   A  clock  may  be system-wide and hence visible for all pro‐
       cesses, or per-process  if  it  measures  time  only  within  a  single
       process.

       All  implementations  support the system-wide real-time clock, which is
       identified by CLOCK_REALTIME.  Its time represents seconds and nanosec‐
       onds  since the Epoch.  When its time is changed, timers for a relative
       interval are unaffected, but timers for an absolute point in  time  are
       affected.

       More  clocks may be implemented.  The interpretation of the correspond‐
       ing time values and the effect on timers is unspecified.

       Sufficiently recent versions of glibc and the Linux kernel support  the
       following clocks:

       CLOCK_REALTIME
              System-wide  clock  that  measures real (i.e., wall-clock) time.
              Setting this clock requires appropriate privileges.  This  clock
              is  affected by discontinuous jumps in the system time (e.g., if
              the system administrator manually changes the clock), and by the
              incremental adjustments performed by adjtime(3) and NTP.

       CLOCK_REALTIME_COARSE (since Linux 2.6.32; Linux-specific)
              A  faster  but less precise version of CLOCK_REALTIME.  Use when
              you need very fast, but not fine-grained timestamps.

       CLOCK_MONOTONIC
              Clock that cannot be set and  represents  monotonic  time  since
              some  unspecified starting point.  This clock is not affected by
              discontinuous jumps in the system  time  (e.g.,  if  the  system
              administrator  manually  changes  the clock), but is affected by
              the incremental adjustments performed by adjtime(3) and NTP.

       CLOCK_MONOTONIC_COARSE (since Linux 2.6.32; Linux-specific)
              A faster but less precise version of CLOCK_MONOTONIC.  Use  when
              you need very fast, but not fine-grained timestamps.

       CLOCK_MONOTONIC_RAW (since Linux 2.6.28; Linux-specific)
              Similar  to  CLOCK_MONOTONIC, but provides access to a raw hard‐
              ware-based time that is not subject to NTP  adjustments  or  the
              incremental adjustments performed by adjtime(3).

       CLOCK_BOOTTIME (since Linux 2.6.39; Linux-specific)
              Identical  to  CLOCK_MONOTONIC, except it also includes any time
              that the system is suspended.  This allows applications to get a
              suspend-aware  monotonic  clock  without having to deal with the
              complications of CLOCK_REALTIME, which may have  discontinuities
              if the time is changed using settimeofday(2).

       CLOCK_PROCESS_CPUTIME_ID (since Linux 2.6.12)
              Per-process  CPU-time  clock  (measures CPU time consumed by all
              threads in the process).

       CLOCK_THREAD_CPUTIME_ID (since Linux 2.6.12)
              Thread-specific CPU-time clock.

RETURN VALUE
       clock_gettime(), clock_settime() and clock_getres() return 0  for  suc‐
       cess, or -1 for failure (in which case errno is set appropriately).

ERRORS
       EFAULT tp points outside the accessible address space.

       EINVAL The clk_id specified is not supported on this system.

       EPERM  clock_settime()  does not have permission to set the clock indi‐
              cated.

VERSIONS
       These system calls first appeared in Linux 2.6.

ATTRIBUTES
       For  an  explanation  of  the  terms  used   in   this   section,   see
       attributes(7).

       ┌─────────────────────────────────┬───────────────┬─────────┐
       │Interface                        │ Attribute     │ Value   │
       ├─────────────────────────────────┼───────────────┼─────────┤
       │clock_getres(), clock_gettime(), │ Thread safety │ MT-Safe │
       │clock_settime()                  │               │         │
       └─────────────────────────────────┴───────────────┴─────────┘

CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, SUSv2.

AVAILABILITY
       On POSIX systems on which these functions  are  available,  the  symbol
       _POSIX_TIMERS  is defined in <unistd.h> to a value greater than 0.  The
       symbols _POSIX_MONOTONIC_CLOCK,  _POSIX_CPUTIME,  _POSIX_THREAD_CPUTIME
       indicate      that      CLOCK_MONOTONIC,      CLOCK_PROCESS_CPUTIME_ID,
       CLOCK_THREAD_CPUTIME_ID are available.  (See also sysconf(3).)

NOTES
   Historical note for SMP systems
       Before Linux added  kernel  support  for  CLOCK_PROCESS_CPUTIME_ID  and
       CLOCK_THREAD_CPUTIME_ID,  glibc  implemented these clocks on many plat‐
       forms using timer registers from the CPUs (TSC on i386, AR.ITC on  Ita‐
       nium).   These  registers  may differ between CPUs and as a consequence
       these clocks may return bogus results  if  a  process  is  migrated  to
       another CPU.

       If  the  CPUs in an SMP system have different clock sources, then there
       is no way to maintain a correlation between the timer  registers  since
       each  CPU  will  run at a slightly different frequency.  If that is the
       case, then clock_getcpuclockid(0) will return ENOENT  to  signify  this
       condition.   The  two  clocks  will  then  be  useful only if it can be
       ensured that a process stays on a certain CPU.

       The processors in an SMP system do not start all at  exactly  the  same
       time and therefore the timer registers are typically running at an off‐
       set.  Some architectures include code that attempts to limit these off‐
       sets  on bootup.  However, the code cannot guarantee to accurately tune
       the offsets.  Glibc contains no provisions to deal with  these  offsets
       (unlike  the  Linux  Kernel).   Typically  these  offsets are small and
       therefore the effects may be negligible in most cases.

       Since glibc 2.4, the wrapper functions for the system  calls  described
       in  this page avoid the abovementioned problems by employing the kernel
       implementation of CLOCK_PROCESS_CPUTIME_ID and CLOCK_THREAD_CPUTIME_ID,
       on  systems that provide such an implementation (i.e., Linux 2.6.12 and
       later).

BUGS
       According to POSIX.1-2001, a process with "appropriate privileges"  may
       set  the  CLOCK_PROCESS_CPUTIME_ID  and  CLOCK_THREAD_CPUTIME_ID clocks
       using clock_settime().  On Linux, these clocks are not settable  (i.e.,
       no process has "appropriate privileges").

SEE ALSO
       date(1),   gettimeofday(2),   settimeofday(2),   time(2),   adjtime(3),
       clock_getcpuclockid(3), ctime(3),  ftime(3),  pthread_getcpuclockid(3),
       sysconf(3), time(7), vdso(7)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

                                  2015-12-28                   CLOCK_GETRES(2)
*/
