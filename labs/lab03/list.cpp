#include "list.h"
#include <iostream>
using namespace std;

bool insert(int position, int val, int intList[], int& size)
{
	//insert your code here and modify the following line
	if (position < size && position >= 0) 
	{	// val requires elements to be shifted down
		for (int i = size; i >= position; i--) 
		{	// start from the last index + 1, and work down
			intList[i] = intList[i-1];
		}	
		
		intList[position] = val;
		size++;						 // increment size to reflect addition
		return true;
	}		
	else if (position == size) 
	{	// val fits at the end of array
		intList[position] = val;
		size++;
		return true;
	}
	return false;
}

bool remove(int position, int& val, int intList[], int& size)
{
	//insert your code here and modify the following line
	if (position < size && position >= 0)
	{
		val = intList[position];
		for (int i = position; i <= size; i++)
		{	// start at position and replace element with element to the right
			intList[i] = intList[i+1];
		}
		size--;						// decrement size to reflect removal
		return true;
	}
	return false;
}

void print(const int intList[], int size)
{
	cout << endl << "[ ";
	for(int i=0; i<size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}



