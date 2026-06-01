read strr

for file in $*
do
	grep $strr "$file" | wc -l
done
