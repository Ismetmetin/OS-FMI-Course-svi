
user_id=$1

while ! who | grep -q "$user_id"
do
	echo "vanka brat stiga"
	sleep 5
done

echo "$user_id startira sesiq"

