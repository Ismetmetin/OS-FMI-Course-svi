userss=$*


for user in $userss; do

	terminals=`who | grep $user | tr -s " \t" " " | cut -d" " -f 2`
	
	echo "$user"
	for terminal in $terminals; do
		echo "$terminal"
		ps -e | grep $terminal
	done 
done

