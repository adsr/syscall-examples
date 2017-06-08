#define SYSCALL "keyctl"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
KEYCTL(2)                 Linux Key Management Calls                 KEYCTL(2)

NAME
       keyctl - manipulate the kernel's key management facility

SYNOPSIS
       #include <keyutils.h>

       long keyctl(int cmd, ...);

DESCRIPTION
       keyctl() has a number of functions available:

       KEYCTL_GET_KEYRING_ID
              Ask for a keyring's ID.

       KEYCTL_JOIN_SESSION_KEYRING
              Join or start named session keyring.

       KEYCTL_UPDATE
              Update a key.

       KEYCTL_REVOKE
              Revoke a key.

       KEYCTL_CHOWN
              Set ownership of a key.

       KEYCTL_SETPERM
              Set perms on a key.

       KEYCTL_DESCRIBE
              Describe a key.

       KEYCTL_CLEAR
              Clear contents of a keyring.

       KEYCTL_LINK
              Link a key into a keyring.

       KEYCTL_UNLINK
              Unlink a key from a keyring.

       KEYCTL_SEARCH
              Search for a key in a keyring.

       KEYCTL_READ
              Read a key or keyring's contents.

       KEYCTL_INSTANTIATE
              Instantiate a partially constructed key.

       KEYCTL_NEGATE
              Negate a partially constructed key.

       KEYCTL_SET_REQKEY_KEYRING
              Set default request-key keyring.

       KEYCTL_SET_TIMEOUT
              Set timeout on a key.

       KEYCTL_ASSUME_AUTHORITY
              Assume authority to instantiate key.

       These  are  wrapped  by libkeyutils into individual functions to permit
       compiler the compiler to check types.  See the See Also section at  the
       bottom.

RETURN VALUE
       On  success keyctl() returns the serial number of the key it found.  On
       error, the value -1 will be returned and errno will have been set to an
       appropriate error.

ERRORS
       EACCES A key operation wasn't permitted.

       EDQUOT The  key quota for the caller's user would be exceeded by creat‐
              ing a key or linking it to the keyring.

       EKEYEXPIRED
              An expired key was found or specified.

       EKEYREJECTED
              A rejected key was found or specified.

       EKEYREVOKED
              A revoked key was found or specified.

       ENOKEY No matching key was found or an invalid key was specified.

LINKING
       Although this is a Linux system call, it is not present in libc but can
       be  found  rather  in  libkeyutils.  When linking, -lkeyutils should be
       specified to the linker.

SEE ALSO
       keyctl(1), add_key(2), request_key(2), keyctl_set_timeout(3),
       keyctl_chown(3), keyctl_clear(3), keyctl_describe(3),
       keyctl_describe_alloc(3), keyctl_get_keyring_ID(3),
       keyctl_instantiate(3), keyctl_join_session_keyring(3), keyctl_link(3),
       keyctl_negate(3), keyctl_revoke(3), keyctl_search(3),
       keyctl_setperm(3), keyctl_set_reqkey_keyring(3), keyctl_set_timeout(3),
       keyctl_read(3), keyctl_read_alloc(3), keyctl_unlink(3),
       keyctl_update(3), keyrings(7), request-key(8)

       The kernel source file Documentation/security/keys.txt.

COLOPHON
       This page is part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs, and the
       latest version of this page, can be found at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-05-07                         KEYCTL(2)
*/
