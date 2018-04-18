#!/usr/bin/env bash

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
        gcc -DDEBUG_INPUT="\"$PROBLEM_ROOT_DIR/test/input.txt\"" -DDEBUG -Wall -xc -o "$PROBLEM_OUTPUT"  -
    
    $PROBLEM_OUTPUT
elif [[ $COMMAND == "submit" ]]; then
    m4 "$PROBLEM_ROOT_DIR/main.c" | xclip -i -selection clipboard
else
    echo Unknown command
    exit -1
fi
