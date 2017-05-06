#!/bin/sh

echo "-------------------------------------------"
echo "OK"
./lem-in < maps/1_m.txt
echo "-------------------------------------------"

echo "WRONG\n no ants" 
./lem-in < maps/2_m.txt
echo "-------------------------------------------"

echo "WRONG\n no ##start"
./lem-in < maps/3_m.txt
echo "-------------------------------------------"

echo "WRONG\n no ##end"
./lem-in < maps/4_m.txt
echo "-------------------------------------------"

echo "WRONG\n no ##start ##end ##bullshit instead" 
./lem-in < maps/5_m.txt
echo "-------------------------------------------"

echo "WRONG\n room instead of N of ants" 
./lem-in < maps/6_m.txt
echo "-------------------------------------------"

echo "WRONG\n zero ants"
./lem-in < maps/7_m.txt
echo "-------------------------------------------"

echo "WRONG\n comment after ##start"
./lem-in < maps/8_m.txt
echo "-------------------------------------------"

echo "WRONG\n comment after ##end"
./lem-in < maps/9_m.txt
echo "-------------------------------------------"

echo "OK\n #comment at the beginning"
./lem-in < maps/10_m.txt
echo "-------------------------------------------"

echo "WRONG\n ##start before ants"
./lem-in < maps/11_m.txt
echo "-------------------------------------------"

echo "WRONG\n ##end before ants"
./lem-in < maps/12_m.txt
echo "-------------------------------------------"

echo "WRONG\n 2 ##start" 
./lem-in < maps/13_m.txt
echo "-------------------------------------------"

echo "WRONG\n 2 ##end"
./lem-in < maps/14_m.txt
echo "-------------------------------------------"

echo "OK\n ##bullshit before ants"
./lem-in < maps/15_m.txt
echo "-------------------------------------------"

echo "WRONG\n empty line after ants"
./lem-in < maps/16_m.txt
echo "-------------------------------------------"

echo "WRONG\n empty line after rooms"
./lem-in < maps/17_m.txt
echo "-------------------------------------------"

echo "WRONG\n empty line first"
./lem-in < maps/18_m.txt
echo "-------------------------------------------"

echo "WRONG\n ##end right after ##start" 
./lem-in < maps/19_m.txt
echo "-------------------------------------------"

echo "WRONG\n no rooms"
./lem-in < maps/20_m.txt
echo "-------------------------------------------"

echo "WRONG\n no connections"
./lem-in < maps/21_m.txt
echo "-------------------------------------------"

echo "WRONG\n no room that in connection"
./lem-in < maps/22_m.txt
echo "-------------------------------------------"

echo "WRONG\n connection with non-existing room"
./lem-in < maps/23_m.txt
echo "-------------------------------------------"

echo "WRONG\n room start with L"
./lem-in < maps/24_m.txt
echo "-------------------------------------------"

echo "WRONG\n bullshit without #"
./lem-in < maps/25_m.txt
echo "-------------------------------------------"

echo "OK\n qwerty name of the room"
./lem-in < maps/26_m.txt
echo "-------------------------------------------"

echo "WRONG\n room without coordinates"
./lem-in < maps/27_m.txt
echo "-------------------------------------------"

echo "WRONG\n connections with spaces"
./lem-in < maps/28_m.txt
echo "-------------------------------------------"

echo "WRONG\n room doesn't connected to end"
./lem-in < maps/29_m.txt
echo "-------------------------------------------"

echo "WRONG\n room doesn't connected to start"
./lem-in < maps/30_m.txt
echo "-------------------------------------------"

echo "WRONG\n dublicats room names"
./lem-in < maps/31_m.txt
echo "-------------------------------------------"

echo "OK\n dublicates room coordinates"
./lem-in < maps/32_m.txt
echo "-------------------------------------------"