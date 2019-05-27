#!/bin/sh

nb_passed=0
nb_failed=0

print_status_test()
{
    ./asm champions/src/$1.s
    hexdump -C $1.cor > out
    hexdump -C champions/$1.cor > out_real ; diff out out_real
    if [ $? -eq 1 ] ; then
        echo "$1: \e[31mFailed\e[39m"
        nb_failed=$(($nb_failed + 1))
    else
        echo "$1: \e[92mPassed\e[39m"
        nb_passed=$(($nb_passed + 1))
    fi
}

make

print_status_test "abel"
print_status_test "bill"
print_status_test "pdd"
print_status_test "tyron"
print_status_test "zork"
print_status_test "42"
print_status_test "Car"
print_status_test "demo"
print_status_test "Octobre_Rouge_V4.2"

echo "\nTESTS: Failed: \e[31m$nb_failed\e[39m :: Passed: \e[92m$nb_passed\e[39m"

rm out out_real *.cor