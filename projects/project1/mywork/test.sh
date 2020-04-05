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

# 0 45
# 1 15
# 1 45
# 0 0

echo "Test 2"

./${PROGRAM_NAME} <<EOF
0 45
0 15
1 45
0 0
EOF

echo "Test 3"

./${PROGRAM_NAME} <<EOF
1 45
1 15
0 45
0 0
EOF
