#!/bin/bash

FILENAME=$1
DIRARRAY=("$@")
len=${#DIRARRAY[@]}

# for dir in ${DIRARRAY[@]}; do
for ((i=1; i<$len; i++)); do
    # echo ${DIRARRAY[$i]} #test line
    find ${DIRARRAY[$i]} -maxdepth 1 -name $FILENAME | xargs realpath
    echo $(stat -c '%U' $FILENAME)
    echo $(stat -c '%a' $FILENAME)
done
