who | grep -q $1

while [ "$?" != "0" ]
do
	sleep 3
	echo "chakame $1"

	who | grep -q $1
done

echo "vsichko tochno"
