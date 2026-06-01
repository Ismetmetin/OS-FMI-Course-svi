str=$1

if [ ! -e "/home/$USER/$str" ] 
then
	mkdir -p "/home/$USER/$str"
fi

count=0

for file in *
do
	if [ -f $file ] && [ -r $file ]
	then
		cp "$file" "/home/$USER/$str"
	else
		count=$(expr $count + 1)
	fi
done

echo "$count"

