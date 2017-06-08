#!/bin/bash

echo "#define SYSCALL \"$1\""
echo '#include "common.h"'
echo
echo 'int run() {'
echo '    // TODO'
echo '    return 0;'
echo '}'
echo
echo '/*'
MANWIDTH=80 man -P cat 2 $1 | sed 's@*/@*|@g'
echo '*/'
