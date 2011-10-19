#!/bin/zsh
val=$(echo $1 | sed "s/0*\(.*\)/\1/")
num=$((val/100))
dir=\[Volume$num\]
if [ -d $dir/$1 ]
then
	mv $dir/$1 .
elif [ -d $dir/\!$1 ]
then
	mv $dir/\!$1 .
else
	mkdir \!$1
	cd \!$1
	template aoj.cpp
fi
