term=$1

pids=$(ps -e | grep "$term" | cut -d" " -f3)

for pid in $pids
do
	kill -9 "$pid"
done

