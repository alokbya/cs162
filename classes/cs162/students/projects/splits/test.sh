#! /bin/bash

PROGRAM_NAME=sp

echo "Test 1"

./${PROGRAM_NAME} <<EOF
0 45
1 15
1 45
0 0
EOF

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
