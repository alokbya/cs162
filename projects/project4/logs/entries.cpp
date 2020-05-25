#include "entries.h"
#include <cstring>
using namespace std;

entries::entries()
{
    name = new char[5];
    strcpy(name, "");
    count = 0; 
}

entries::entries(char *n, int c)
{
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    count = c;
}

entries::entries(const entries& obj)        // copy constructor
{
    name = new char[strlen(obj.name) + 1];
    for(int i = 0; i < strlen(obj.name) + 1; i++)
        name[i] = obj.name[i];
    
    count = obj.count;
}

entries::~entries() 
{
    delete [] name;
}

void entries::setName(const char *n)
{
    delete [] name;                         // delete old name before setting new one
    name = new char[strlen(n) + 1];         // create name to be the same size as passed in char* n
    strcpy(name, n);
}

void entries::setCount(int c)
{
    count = c;
}

void entries::setData(const char *n, int c)
{
    setName(n);
    setCount(c);
}

char* entries::getName()
{
    return name;
}

int entries::getCount()
{
    return count;
}

void entries::incrementCount()
{
    count++;
}