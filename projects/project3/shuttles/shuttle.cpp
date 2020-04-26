#include <iostream>
#include <cstring>
#include "shuttle.h"

using namespace std;

shuttle::shuttle()
{
    // initialize class members
    cStringInit_1D(name, MAX_STR);
    capacity = 0;
    currentCount = 0;
    cStringInit_2D(passengerList, MAX_PASSENGERS, 2);

    cout << "constructor!" << endl;
}

shuttle::~shuttle()
{
    cout << "destructor!" << endl;
}

void shuttle::setName(char n[])
{
    strcpy(n, name);
}

void shuttle::setCapacity(int c)
{
    capacity = c;
}

bool shuttle::hasRoom()
{
    return (currentCount < capacity);
}

void shuttle::addPassenger(person p)
{
    if (hasRoom())
    {
        strcpy(passengerList[currentCount][0], p.fname);
        strcpy(passengerList[currentCount][1], p.lname);
    }
    currentCount++;
}

void shuttle::printPassengerList()
{
    for (int i = 0; i < currentCount; i++)
    {
        cout << passengerList[i][0] << " " << passengerList[i][1] << endl;
    }
}

void shuttle::clearPassengerList()
{
    for (int i = 0; i < currentCount; i++)
    {
        for (int j = 0; j < MAX_STR; j++)
        {
            passengerList[i][j] = '\0';
        }
        
    }
}

/*
    Helper functions
*/
void cStringInit_1D(char s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        s[i] = '\0';
    }
}

void cStringInit_2D(char s[], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            s[i][j] = '\0';
        }
        
    }
}