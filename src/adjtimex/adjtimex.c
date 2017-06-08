#define SYSCALL "adjtimex"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
ADJTIMEX(2)                Linux Programmer's Manual               ADJTIMEX(2)

NAME
       adjtimex - tune kernel clock

SYNOPSIS
       #define _BSD_SOURCE      /* See feature_test_macros(7) *|
       #include <sys/timex.h>

       int adjtimex(struct timex *buf);

DESCRIPTION
       Linux  uses  David L. Mills' clock adjustment algorithm (see RFC 5905).
       The system call adjtimex() reads and optionally sets adjustment parame‐
       ters  for  this  algorithm.   It  takes a pointer to a timex structure,
       updates kernel parameters from  field  values,  and  returns  the  same
       structure  with  current  kernel values.  This structure is declared as
       follows:

           struct timex {
               int  modes;      /* Mode selector *|
               long offset;     /* Time offset; nanoseconds, if STA_NANO
                                   status flag is set, otherwise microseconds *|
               long freq;       /* Frequency offset, in units of 2^-16 ppm
                                   (parts per million, see NOTES below) *|
               long maxerror;   /* Maximum error (microseconds) *|
               long esterror;   /* Estimated error (microseconds) *|
               int  status;     /* Clock command/status *|
               long constant;   /* PLL (phase-locked loop) time constant *|
               long precision;  /* Clock precision (microseconds, read-only) *|
               long tolerance;  /* Clock frequency tolerance (ppm, read-only) *|
               struct timeval time;
                                /* Current time (read-only, except for
                                   ADJ_SETOFFSET); upon return, time.tv_usec
                                   contains nanoseconds, if STA_NANO status
                                   flag is set, otherwise microseconds *|
               long tick;       /* Microseconds between clock ticks *|
               long ppsfreq;    /* PPS (pulse per second) frequency (in units
                                   of 2^-16 ppm--see NOTES, read-only) *|
               long jitter;     /* PPS jitter (read-only); nanoseconds, if
                                   STA_NANO status flag is set, otherwise
                                   microseconds *|
               int  shift;      /* PPS interval duration (seconds, read-only) *|
               long stabil;     /* PPS stability (2^-16 ppm--see NOTES,
                                   read-only) *|
               long jitcnt;     /* PPS jitter limit exceeded (read-only) *|
               long calcnt;     /* PPS calibration intervals (read-only) *|
               long errcnt;     /* PPS calibration errors (read-only) *|
               long stbcnt;     /* PPS stability limit exceeded (read-only) *|
               int tai;         /* TAI offset, as set by previous ADJ_TAI
                                   operation (seconds, read-only,
                                   since Linux 2.6.26) *|
               /* Further padding bytes to allow for future expansion *|
           };

       The modes field determines which parameters, if any, to set.  It  is  a
       bit  mask  containing  a  bitwise-or combination of zero or more of the
       following bits:

       ADJ_OFFSET
              Set time offset from buf.offset.

       ADJ_FREQUENCY
              Set frequency offset from buf.freq.

       ADJ_MAXERROR
              Set maximum time error from buf.maxerror.

       ADJ_ESTERROR
              Set estimated time error from buf.esterror.

       ADJ_STATUS
              Set clock status from buf.status.

       ADJ_TIMECONST
              Set PLL time constant from buf.constant.  If the STA_NANO status
              flag (see below) is clear, the kernel adds 4 to this value.

       ADJ_SETOFFSET (since Linux 2.6.29)
              Add  buf.time  to  the current time.  If buf.status includes the
              ADJ_NANO  flag,  then  buf.time.tv_usec  is  interpreted  as   a
              nanosecond value; otherwise it is interpreted as microseconds.

       ADJ_MICRO (since Linux 2.6.36)
              Select microsecond resolution.

       ADJ_NANO (since Linux 2.6.36)
              Select   nanosecond  resolution.   Only  one  of  ADJ_MICRO  and
              ADJ_NANO should be specified.

       ADJ_TAI (since Linux 2.6.26)
              Set TAI (Atomic International Time) offset from buf->constant.

              ADJ_TAI should not be used in  conjunction  with  ADJ_TIMECONST,
              since the latter mode also employs the buf->constant field.

              For a complete explanation of TAI and the difference between TAI
              and UTC, see BIPM ⟨http://www.bipm.org/en/bipm/tai/tai.html⟩

       ADJ_TICK
              Set tick value from buf.tick.

       Alternatively, modes can  be  specified  as  either  of  the  following
       (multibit  mask)  values, in which case other bits should not be speci‐
       fied in modes:

       ADJ_OFFSET_SINGLESHOT
              Old-fashioned adjtime(): (gradually) adjust time by value speci‐
              fied  in  buf.offset, which specifies an adjustment in microsec‐
              onds.

       ADJ_OFFSET_SS_READ (functional since Linux 2.6.28)
              Return (in buf.offset)  the  remaining  amount  of  time  to  be
              adjusted after an earlier ADJ_OFFSET_SINGLESHOT operation.  This
              feature was added in Linux 2.6.24, but did  not  work  correctly
              until Linux 2.6.28.

       Ordinary  users  are  restricted  to  a  value  of either 0 or ADJ_OFF‐
       SET_SS_READ for modes.  Only the superuser may set any parameters.

       The buf.status field is a bit mask that is used to set and/or  retrieve
       status  bits  associated with the NTP implementation.  Some bits in the
       mask are both readable and settable, while others are read-only.

       STA_PLL
              Enable phase-locked loop (PLL) updates (read-write) via ADJ_OFF‐
              SET.

       STA_PPSFREQ
              Enable PPS freq discipline (read-write).

       STA_PPSTIME
              Enable PPS time discipline (read-write).

       STA_FLL
              Select frequency-locked loop (FLL) mode (read-write).

       STA_INS
              Insert leap second (read-write).

       STA_DEL
              Delete leap second (read-write).

       STA_UNSYNC
              Clock unsynchronized (read-write).

       STA_FREQHOLD
              Hold frequency (read-write).

       STA_PPSSIGNAL
              PPS signal present (read-only).

       STA_PPSJITTER
              PPS signal jitter exceeded (read-only).

       STA_PPSWANDER
              PPS signal wander exceeded (read-only).

       STA_PPSERROR
              PPS signal calibration error (read-only).

       STA_CLOCKERR
              Clock hardware fault (read-only).

       STA_NANO (since Linux 2.6.26)
              Resolution  (0  = microsecond, 1 = nanoseconds; read-only).  Set
              via ADJ_NANO, cleared via ADJ_MICRO.

       STA_MODE (since Linux 2.6.26)
              Mode (0 = Phase Locked Loop, 1 = Frequency  Locked  Loop;  read-
              only).

       STA_CLK (since Linux 2.6.26)
              Clock source (0 = A, 1 = B; read-only).

       Attempts to set read-only status bits are silently ignored.

RETURN VALUE
       On  success,  adjtimex()  returns  the clock state; that is, one of the
       following values:

       TIME_OK     Clock synchronized.

       TIME_INS    Insert leap second.

       TIME_DEL    Delete leap second.

       TIME_OOP    Leap second in progress.

       TIME_WAIT   Leap second has occurred.

       TIME_ERROR  Clock not synchronized.  The symbolic name  TIME_BAD  is  a
                   synonym  for  TIME_ERROR, provided for backward compatibil‐
                   ity.

       On failure, adjtimex() returns -1 and sets errno.

ERRORS
       EFAULT buf does not point to writable memory.

       EINVAL An attempt was made to set buf.offset to  a  value  outside  the
              range  -131071 to +131071, or to set buf.status to a value other
              than those listed above, or to set buf.tick to a  value  outside
              the  range 900000/HZ to 1100000/HZ, where HZ is the system timer
              interrupt frequency.

       EPERM  buf.modes is neither 0 nor ADJ_OFFSET_SS_READ,  and  the  caller
              does   not   have   sufficient   privilege.   Under  Linux,  the
              CAP_SYS_TIME capability is required.

NOTES
       In struct timex, freq, ppsfreq, and stabil are ppm (parts per  million)
       with  a 16-bit fractional part, which means that a value of 1 in one of
       those fields actually means 2^-16 ppm, and 2^16=65536 is 1  ppm.   This
       is the case for both input values (in the case of freq) and output val‐
       ues.

CONFORMING TO
       adjtimex() is  Linux-specific  and  should  not  be  used  in  programs
       intended  to be portable.  See adjtime(3) for a more portable, but less
       flexible, method of adjusting the system clock.

SEE ALSO
       settimeofday(2), adjtime(3), capabilities(7), time(7), adjtimex(8)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2014-12-31                       ADJTIMEX(2)
*/
