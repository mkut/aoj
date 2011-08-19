#!/bin/zsh
declare -i all
declare -i wa
declare -i sumall
declare -i sumwa
sumall=0
sumwa=0
printf "            AC  WA\n"
for fn in $(for _fn in \[Volume*\]; do echo $_fn; done | sed "s/\[Volume\(.*\)\]/\1/" | sort -n | sed "s/\(.*\)/\[Volume\1\]/")
do
	all=$(ls $fn | wc -l)
	wa=$(ls $fn | grep "\!.*" | wc -l)
	sumall=$(($sumall + $all))
	sumwa=$(($sumwa + $wa))
	printf "%10s %3d %3d\n" $fn $(($all - $wa)) $wa
done
printf "       all %3d %3d\n" $(($sumall - $sumwa)) $sumwa
