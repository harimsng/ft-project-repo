#!/bin/bash
BNS_FLAG=$1
BNS_STR="bonus"
if [[ $BNS_FLAG == $BNS_STR ]]
then
	BIN=./philo_bonus
	echo $BIN
else
	BIN=./philo
	echo $BIN
fi

test1() {
	ARG="1 100 200 200 10"
	echo "test: $BIN $ARG"
	$BIN $ARG
	echo "test ends"
	echo ""
}

test2() {
	ARG="1 400 200 200 10"
	echo "test: $BIN $ARG"
	$BIN $ARG
	echo "test ends"
	echo ""
}

test3() {
	ARG="10 100 200 200 10"
	echo "test: $BIN $ARG"
	$BIN $ARG
	echo "test ends"
	echo ""
}

test4() {
	ARG="10 410 200 200 10"
	echo "test: $BIN $ARG"
	$BIN $ARG
	echo "test ends"
	echo ""
}

test5() {
	ARG="9 100 200 200 10"
	echo "test: $BIN $ARG"
	$BIN $ARG
	echo "test ends"
	echo ""
}

test6() {
	ARG="9 610 200 200 10"
	echo "test: $BIN $ARG"
	$BIN $ARG
	echo "test ends"
	echo ""
}


test1
cat -
test2
cat -
test3
cat -
test4
cat -
test5
cat -
test6
