Lab 03

======================================================================

Implement two functions specified in list.h. You need to fill in the
implementation in list.cpp:

  bool insert(int position, int val, int intList[], int& size)

    The above function will insert "val" at "position" of "intList" and
    increment "size".

    When you insert an element at a position, you need to shift things down to
    make space for it instead of simply overwriting it. For example,

    [ ] //empty list

    after insert 4 at position 0,
    [ 4 ] 

    after insert 6 at position 0, 
    [6, 4]

    after insert 10 at position 1,
    [6, 10, 4]


  bool remove(int position, int& val, int intList[], int& size)	

    The above function will remove the integer at "position" from "intList" and
    return the value through "val" and decrement "size". It returns false if
    "position" is invalid. 

In app.cpp, the function print is used to print the integers in the list. You
can use this information to check the accuracy of your code.

You can build the app using the make utility, which is supported by the file
named makefile provided in the directory. (Just type "make" in the directory
that contains your source code and it will compile your program.)

For lab03 submission use the turnin command to submit list.cpp
