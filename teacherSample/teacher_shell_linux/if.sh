#!/bin/sh

score=50

if [ $score -ge 60 ]
then
	echo 'PASS!'
else
	echo 'FAIL!'
fi

temp="hello"
if [ $temp = "hello" ]
then
	echo "YES"
else
	echo "NO"
fi
