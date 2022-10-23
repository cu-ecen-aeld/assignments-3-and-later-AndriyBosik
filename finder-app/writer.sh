#!/bin/bash
path=$1
str=$2
if [ -z $path ] || [ -z $str ]
then
    echo "Some parameters were not specified"
    exit 1
fi
mkdir -p $(dirname $path)
echo $str >> $path
