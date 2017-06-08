#include <stdlib.h>
#include <stdio.h>

#define SYS_CONST SYS_ ## SYSCALL

int run();

int main(int argc, char **argv) {
    #ifdef SYS_CONST
        printf("%s is defined\n", SYSCALL);
        return run();
    #else
        printf("%s is not defined\n", SYSCALL);
        return EXIT_FAILURE;
    #endif
}
