dir1=$1
dir2=$2


if [ $(ls $dir1 | grep -c "out") -gt $(ls $dir2 | grep -c "out") ]
then
	mkdir murr
	echo murr
	for file in "$dir1/"*
	do
		if [ -f $file ] && [ -r $file ] && [ -w $file ]
		then
			base_name=$(expr substr "$file" $(expr length "$dir1" + 1) $(expr length "$file"))
			cp "$file" "./murr/$base_name"
		fi
	done
else
	echo "ne stana"
fi
