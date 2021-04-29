#!/usr/bin/env bash
filename=$1
if [ -x $filename ]
then
    bash $filename
elif [ -a $filename ]
then
    chmod +x $filename
    bash $filename
else
    echo "$filename 不存在"
fi