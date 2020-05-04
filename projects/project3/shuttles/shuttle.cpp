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
    strcpy(name, n);
}

void shuttle::getName(char n[])
{
    strcpy(n, name);
}

void shuttle::setCapacity(int c)
{
    capacity = c;
}

int shuttle::getCapacity()
{
    return capacity;
}

int shuttle::getCurrentCount()
{
    return currentCount;
}


bool shuttle::hasRoom()
{
    return (currentCount < capacity);
}


// returns 1 if added passenger, returns 0 if not added (no room)
void shuttle::addPassenger(person p)
{
    list[currentCount] = p;
    currentCount++;
}

void shuttle::printPassengerList()
{
    int count = 1;
    for (int i = 0; i < currentCount; i++)
    {   
        // cout << "passenger: " << currentCount << endl;
        char first[MAX_STR];
        char last[MAX_STR];
        cleanString(first, MAX_STR);
        cleanString(last, MAX_STR);

        list[i].person::getFirst(first);
        list[i].person::getLast(last);
        bool noLastName = strlen(last) == 0;                // handle diff b/t test and prod

        if(noLastName)                                      
        {
            switch (count)
            {
                case 1:
                    cout << "  " << first << ", ";
                    count++;
                    break;
                case 2:
                case 3:
                case 4: 
                    if (i == currentCount - 1)
                        cout << first;
                    else
                    {
                        cout << first << ", ";
                        count++;
                    }
                    break;
                case 5: 
                    cout << first << endl;
                    count = 1;
            }
        }
        else
        {
            switch (count)
            {
                case 1:
                    cout << "  " << first << ' ' << last << ", ";
                    count++;
                    break;
                case 2:
                case 3:
                case 4: 
                    if (i == currentCount - 1)
                        cout << first << ' ' << last;
                    else
                    {
                        cout << first << ' ' << last << ", ";
                        count++;
                    }
                    break;
                case 5: 
                    cout << first << ' ' << last << endl;
                    count = 1;
            }
        }
    }
    cout << endl << endl;
}

void shuttle::clearPassengerList()
{
    char cleanstr[MAX_STR] = {'\0'};
    for (int i = 0; i < MAX_PASSENGERS_SHUTTLE; i++)
    {
        list[i].person::setFirst(cleanstr);
        list[i].person::setLast(cleanstr);
    }
}

void shuttle::reset()
{
    currentCount = 0;
    clearPassengerList();
}

void shuttle::test()
{
    cout << "shuttle::test()!" << endl;
}
