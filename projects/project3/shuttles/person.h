#ifndef SHUTTLE_H
#define SHUTTLE_H

#define MAX_STR 100
#define MAX_PASSENGERS 350

#include <cstring>
// I guess this struct has to be included ABOVE class members who
// reference this type
class person
{
    private:
        char fname[MAX_STR];
        char lname[MAX_STR];

    public: 
        
};


void cStringInit_1D(char s[], int size);
void cStringInit_2D(char s[], int size1, int size2);


#endif