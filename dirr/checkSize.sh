str=$1
num=$2

ls | grep -qw $str

if [ $? != 0 ]
then
	echo "checkSize.sh: No such directory found!!!:p"

else
	for var in ls $str
	do
		wc $var -c
	done
fi

