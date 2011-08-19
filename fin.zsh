#!/bin/zsh
val=$(echo $1 | sed "s/0*\(.*\)/\1/")
num=$((val/100))
if [ ! -d \[Volume$num\] ]
then
	mkdir \[Volume$num\]
fi
if [ $# -eq 2 ]
then
	mv *$1 \[Volume$num\]
else
	mv *$1 \[Volume$num\]/$1
fi
