
if [ -d $1 ]
then 
	for file in $1/*
	do	
		if [ -f $file -a $2 -lt $(wc -c < "$file") ]
		then
			echo "$file"
		fi
	done
else
	echo "no such directory"
fi
