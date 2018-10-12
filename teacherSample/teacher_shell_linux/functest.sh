#!/bin/sh

sum()
{
	temp=$(($1+$2))
	# arithmatic variable
	temp=$(($temp+1))
	return $temp
}

sum 10 20
echo "result is $?"
