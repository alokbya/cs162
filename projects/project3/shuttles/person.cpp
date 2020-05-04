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

// This function will copy the value from the current objects first name,
// to the character array that is passed into this function. This will allow 
// the f[] character array to be accessed, as it is not a member variable
// but holds the same content as the member variables first name.
void person::getFirst(char f[])
{   
    strcpy(f, fname);
}

// This function will copy the value from the current objects last name,
// to the character array that is passed into this function. This will allow 
// the l[] character array to be accessed, as it is not a member variable
// but holds the same content as the member variables last name.
void person::getLast(char l[])
{   
    strcpy(l, lname);
}

void person::test()
{
    cout << "person::test()!" << endl;
}

