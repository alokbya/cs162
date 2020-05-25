#include <iostream>
#include "syslog.h"
#include <cstring>
#include <cmath>
using namespace std;

syslog::syslog()
{
    // default constructor
}
syslog::syslog(char* sys, const int num)
{
    count = 0;
    listSize = num;
    systemType = new char[strlen(sys) + 1];
    strcpy(systemType, sys);
    entriesList = new entries[num + 1];                     // creates a list of employees of listSize num
}
syslog::syslog(const syslog& obj)                           // copy constructor
{
    systemType = new char[strlen(obj.systemType)];
    for (int i = 0; i < strlen(obj.systemType) + 1; i++)
        systemType[i] = obj.systemType[i];

    entriesList = new entries[obj.listSize + 1];
    for (int j = 0; j < listSize; j++)
        entriesList[j] = obj.entriesList[j];
    
    listSize = obj.listSize;
    count = obj.count;
}
syslog::~syslog()
{
    delete [] entriesList;                                  // delete the "parent" list of names (name containing names)
    delete [] systemType;
}

void syslog::addEntry(const char* sys, const char* who)
{
    if(strcmp(sys, systemType) == 0)                        // if system matches
    {
        int index = entryIndex(who);
        if (index == -1)                                    // if employee doesn't exist yet
        {
            entriesList[count].setName(who);                // add employee @ next index
            entriesList[count].incrementCount();            // increment their count to 1
        }
        else
            entriesList[index].incrementCount();
        count++;
    }
}

int syslog::entryIndex(const char *who)
{   
    int index = -1;
    for (int i = 0; i < listSize; i++)
    {
        if (strcmp(who, entriesList[i].getName()) == 0)     // if parameter matches current index of employee list
            index = i;
    }
    return index;
}

void syslog::printAll()
{
    entries first[count];
    entries second[count];
    int totalFirst;
    int totalSecond;
    topAccessors(first, second, totalFirst, totalSecond);    
    
    // output
    cout << "System: " << systemType << endl;
    cout << "  Top: ";
    printNames(first, totalFirst);

    cout << "  Second: ";
    printNames(second, totalSecond);

    cout << "  All:" << endl;
    for (int i = 0; i < count; i++)
    {   
        if(entriesList[i].getCount() > 0)
        {
            cout << "    " << entriesList[i].getName() << " " << entriesList[i].getCount();
            cout << " (" << static_cast<double>(entriesList[i].getCount() * 100 / count) << "%)" << endl;
        }
    }
}

void syslog::topAccessors(entries eFirst[], entries eSecond[], int& totalFirst, int& totalSecond)
{
    // get first and second count numbers
    totalFirst = 0;                                     // set totals to 0 to make sure we have the right num
    totalSecond = 0;
    int f = 0;
    int s = 0;
    getTopCounts(f, s);

    for(int i = 0; i < count; i++)
    {
        if(entriesList[i].getCount() == f)              // if in first list
        {
               eFirst[totalFirst].setName(entriesList[i].getName());
               eFirst[totalFirst].setCount(entriesList[i].getCount());
               totalFirst++;
        }
        else if(entriesList[i].getCount() == s)
        {
            eSecond[totalSecond].setName(entriesList[i].getName());
            eSecond[totalSecond].setCount(entriesList[i].getCount());
            totalSecond++;
        }
    }    
}

void syslog::printNames(entries e[], int total)
{
    for (int i = 0; i < total; i++)
    {   if (i == total - 1)
            cout << e[i].getName();
        else
            cout << e[i].getName() << ", ";
    }   
    cout << endl;
}

void syslog::getTopCounts(int& first, int& second)
{
    first = 0;
    second = 0;
    for(int i = 0; i < count; i++)
    {
        if(entriesList[i].getCount() > first)
        {
            second = first;
            first = entriesList[i].getCount();
        }
        else if(entriesList[i].getCount() < first && entriesList[i].getCount() > second)
        {
            second = entriesList[i].getCount();
        }
    }
}