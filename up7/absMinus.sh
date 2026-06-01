
if [ $1 -lt $2 ]
then
	expr $2 - $1
	
else
	expr $1 - $2
fi

