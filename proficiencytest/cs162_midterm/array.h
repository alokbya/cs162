#ifndef ARRAY_H
#define ARRY_H

//array.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/* These functions are already written and can be called to test out your code */
void build(int list[], int size);  //supplied
void display(int list[], int size);  //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

// Compute and return the sum of integers in list array
int sumOfArray(int list[], int size);

/*  Remove all the integers that equal target in the list, update the size of the list.
    Returns total number of elements removed from the list.
*/
int remove(int list[], int& size, int target);


#endif
