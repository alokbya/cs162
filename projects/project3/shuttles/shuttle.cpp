#include <iostream>
#include <cstring>

#include "person.h"
#include "shuttle.h"
#include "spacehelpers.h"

using namespace std;

shuttle::shuttle()
{
    // initialize class members
    cleanString(name, MAX_STR);
    capacity = 0;
    currentCount = 0;
}

shuttle::~shuttle()
{
    
}

void shuttle::setName(char n[])
{
    strcpy(n, name);
}

void shuttle::getName()
{
    cout << name;
}

void shuttle::setCapacity(int c)
{
    capacity = c;
}

int shuttle::getCapacity()
{
    return capacity;
}

bool shuttle::hasRoom()
{
    return (currentCount < capacity);
}

void shuttle::addPassenger(person p)
{
    // cout << "capacity: " << capacity << endl;
    // cout << "has room: " << hasRoom() << endl;
}

void shuttle::printPassengerList()
{
    // for (int i = 0; i < currentCount; i++)
    // {
    //     cout << passengerList[i][0] << " " << passengerList[i][1] << endl;
    // }
}

void shuttle::clearPassengerList()
{
    // for (int i = 0; i < currentCount; i++)
    // {
    //     for (int j = 0; j < MAX_STR; j++)
    //     {
    //         passengerList[i][j] = '\0';
    //     }
        
    // }
}


void shuttle::test()
{
    cout << "shuttle::test()!" << endl;
}
