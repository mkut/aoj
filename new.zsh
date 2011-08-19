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
	cp -r ${SP_PATH}/default \!$1
	echo "/* aoj header */\n" > \!$1/c++.cpp
fi
