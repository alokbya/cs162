#! /bin/bash

PROGRAM_NAME=sp

echo "Test 1"

./${PROGRAM_NAME} <<EOF


0 15
1 20
3 16
2 20
0 10
0 8
1 22
6 18
7 6
0 0



EOF

echo "Test 2"

./${PROGRAM_NAME} <<EOF

0 16
1 4
2 13
7 8
0 2
2 0
6 7
5 14
3 26
4 15
 
0 0
EOF

echo "Test 3"

./${PROGRAM_NAME} <<EOF
1 45
1 15
0 45
0 0
EOF

echo "Test 4"

./${PROGRAM_NAME} << EOF
0 0
EOF
