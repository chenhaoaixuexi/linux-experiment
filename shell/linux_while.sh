#! /bin/sh
i=1
while [ $i -lt 10 ]
#while ture
do 
	echo "hello"
#	i=$((i+1))
	let "i++"
done

