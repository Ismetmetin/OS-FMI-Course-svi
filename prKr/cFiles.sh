dir1=$1
dir2=$2

if [ $(expr $(ls $dir1 | grep -c ".out") + $(ls $dir2 | grep -c ".out")) -ge 5 ]
then
	touch sources.txt
	
	ls $dir1 $dir2 | grep ".out" > sources.txt
	
	chmod 444 sources.txt
else
	echo nishto
fi

