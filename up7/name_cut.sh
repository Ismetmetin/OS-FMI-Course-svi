dir=$1

for file in "$dir/"*.c
do
	new_name="$(expr substr "$file" 1 $(expr length "$file" - 2)).exe"

	cc "$file" -o "$new_name"
done
	
