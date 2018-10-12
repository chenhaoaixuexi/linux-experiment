#!/bin/sh

for i in `ls /mnt/d/mindMap_思维导图` 
do
	mv $i "linux_"$i
done
