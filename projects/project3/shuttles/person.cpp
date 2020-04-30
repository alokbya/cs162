#include <iostream>
#include <cstring>

#include "person.h"
#include "shuttle.h"
#include "spacehelpers.h"

using namespace std;

person::person()
{
    // initialize, set names to empty cstrings
    cleanString(fname, MAX_STR);
    cleanString(lname, MAX_STR);
}

person::~person()
{

}

void person::setFirst(char f[])
{
    strcpy(fname, f);
}

void person::setLast(char l[])
{
    strcpy(lname, l);
}

void person::getFirst()
{   // just prints name out to console
    cout << fname;
}

void person::getLast()
{   // just prints name out to console
    cout << lname;
}

void person::test()
{
    cout << "person::test()!" << endl;
}

