#!/usr/bin/env bash

set -e

PROBLEM_OUTPUT=/tmp/problem

COMMAND=$1
shift

args=$(getopt --long problem: -o "p:" -- "$@")

while [ $# -ge 1 ]; do

    case "$1" in
        --)
            # No more options left.
            shift
            break
           ;;
        -p|--problem)
            PROBLEM_ROOT_DIR="$2"
        ;;
    esac

    shift
done

if [[ $COMMAND == "debug" ]]; then
    m4 "$PROBLEM_ROOT_DIR/main.c" |
        gcc -DPROBLEM_ROOT_DIR="\"$PROBLEM_ROOT_DIR\"" -DDEBUG -Wall -lm -xc -o "$PROBLEM_OUTPUT"  -
    
    $PROBLEM_OUTPUT
elif [[ $COMMAND == "submit" ]]; then
    m4 "$PROBLEM_ROOT_DIR/main.c" | xclip -i -selection clipboard
elif [[ $COMMAND == "new" ]]; then
    mkdir -p "$PROBLEM_ROOT_DIR"/test
    touch "$PROBLEM_ROOT_DIR"/test/input.txt
    touch "$PROBLEM_ROOT_DIR"/test/output.txt
    touch "$PROBLEM_ROOT_DIR"/README.md
    tee "$PROBLEM_ROOT_DIR"/main.c <<MAIN.C > /dev/null
#include <stdio.h>

include(./incs/common.c)

int
main(void) {
#if DEBUG
    init_debug();
#endif


#if DEBUG
    print_expected();
#endif
    return 0;
}
MAIN.C
else
    echo Unknown command
    exit -1
fi
