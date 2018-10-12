#!/bin/sh

for i in `ls`
do
	mv $i "linux_"$i
done
