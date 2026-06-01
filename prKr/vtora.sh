str=$1

if [ ! -d "/home/$USER/$str" ]
then 
	touch "/home/$USER/$str"
fi

count=0
for file in *
do
	if [ -r $file ] && [ -w $file ]
	then
		mv "$file" "/home/$USER/$str/$file"
	else
		count=$(expr $count + 1)
	fi

	echo $count
done

