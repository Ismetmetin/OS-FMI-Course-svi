dir1=$1
dir2=$2

#>20 c files izsipi v txt file koito e s 444 prava


if [ $(expr $(ls $dir1 | grep -c ".out") + $(ls $dir2 | grep -c ".out")) -ge 5 ]
then
	touch fileWithNames.txt
	ls "$dir1" "$dir2" | grep ".out" > fileWithNames.txt
	chmod 444 fileWithNames.txt	
else
	echo "not enough C files"
fi
