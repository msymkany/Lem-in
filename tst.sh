#!/bin/sh

echo "OK"
./lem-in < 1_m.txt

echo "WRONG\n no ants" 
./lem-in < 2_m.txt

echo "WRONG\n no ##start"
./lem-in < 3_m.txt

echo "WRONG\n no ##end"
./lem-in < 4_m.txt

echo "WRONG\n no ##start ##end ##bullshit instead" 
./lem-in < 5_m.txt

echo "WRONG\n room instead of N of ants" 
./lem-in < 6_m.txt

echo "WRONG\n zero ants"
./lem-in < 7_m.txt

echo "WRONG\n comment after ##start"
./lem-in < 8_m.txt

echo "WRONG\n comment after ##end"
./lem-in < 9_m.txt

echo "OK\n #comment at the beginning"
./lem-in < 10_m.txt

echo "WRONG\n ##start before ants"
./lem-in < 11_m.txt

echo "WRONG\n ##end before ants"
./lem-in < 12_m.txt

echo "WRONG\n 2 ##start" 
./lem-in < 13_m.txt

echo "WRONG\n 2 ##end"
./lem-in < 14_m.txt

echo "OK\n ##bullshit before ants"
./lem-in < 15_m.txt

echo "WRONG\n empty line after ants"
./lem-in < 16_m.txt

echo "WRONG\n empty line after rooms"
./lem-in < 17_m.txt

echo "WRONG\n empty line first"
./lem-in < 18_m.txt

echo "WRONG\n ##end right after ##start" 
./lem-in < 19_m.txt

echo "WRONG\n no rooms"
./lem-in < 20_m.txt

echo "WRONG\n no connections"
./lem-in < 21_m.txt

echo "WRONG\n no room that in connection"
./lem-in < 22_m.txt

echo "WRONG\n connection with non-existing room"
./lem-in < 23_m.txt

echo "WRONG\n room start with L"
./lem-in < 24_m.txt

echo "WRONG\n bullshit without #"
./lem-in < 25_m.txt

echo "OK\n qwerty name of the room"
./lem-in < 26_m.txt

echo "WRONG\n room without coordinates"
./lem-in < 27_m.txt

echo "WRONG\n connections with spaces"
./lem-in < 28_m.txt

echo "WRONG\n room doesn't connected to end"
./lem-in < 29_m.txt

echo "WRONG\n room doesn't connected to start"
./lem-in < 30_m.txt

echo "WRONG\n dublicats room names"
./lem-in < 31_m.txt

echo "OK\n dublicates room coordinates"
./lem-in < 32_m.txt
