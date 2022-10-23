#!/bin/bash
files_dir=$1
search_str=$2

if [ -z $files_dir ] || [ -z $search_str ]
then
    echo "Some parameters were not specified"
    exit 1
fi

if [ ! -d $files_dir ]
then
    echo "$files_dir is not a directory";
    exit 1
fi

files_count=$(find $files_dir -type f | wc -l)
files=$(find $files_dir -type f)
lines_count=0
for file in $files
do
    count=$(cat $file | grep $search_str | wc -l)
    lines_count=$(($lines_count + $count))
done
echo "The number of files are $files_count and the number of matching lines are $lines_count"
