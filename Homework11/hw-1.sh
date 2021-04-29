#!/usr/bin/env bash
who|cut -f1
echo "参数个数为" $#
for name in $@
do
    who|cut -f 1 -d" "|grep "$name"'$' >/dev/null
    echo $?
done