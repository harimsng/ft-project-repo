#!/bin/bash
if [ $# != 1 ]
then
	echo "input range [0, 1000]"
else
	./automated_test $1
INPUT="`cat testcase.txt`"
#	echo $INPUT
#cat testcase.txt | xargs ../push_swap > instruction_temp.txt
	../push_swap $INPUT > instruction_temp.txt
	echo "number of operations"
	cat instruction_temp.txt | wc -l
	./checker_Mac $INPUT < instruction_temp.txt
#	./checker_linux $INPUT < instruction_temp.txt
#	./checker $INPUT < instruction_temp.txt
fi
