//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here
int sumOfArray(int list[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += list[i];
    return sum;
}

int remove(int list[], int& size, int target)
{
    int totalRemoved = 0;
    for(int i = 0; i < size; i++)
    {
        if(list[i] == target)
        {
            for (int j = i; j <= size; j++)         
                list[j] = list[j+1];        // shuffles elements down after finding target
            size--;                         // update size and total elements removed
            totalRemoved++;
        }
    }
    return totalRemoved;
}