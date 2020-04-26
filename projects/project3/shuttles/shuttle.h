#ifndef SHUTTLE_H
#define SHUTTLE_H

#define MAX_STR 100
#define MAX_PASSENGERS 350

#include "person.h"

// I guess this struct has to be included ABOVE class members who
// reference this type

class shuttle
{
    private:
        
        char name[MAX_STR];
        int capacity;
        int currentCount;
        person passengerList[MAX_PASSENGERS][2];  // store first name, last name

    public:
        shuttle();        // Default constructor
        ~shuttle();       // Destructor

        void setName(char n[]);
        void setCapacity(int cap);
        bool hasRoom();
        void addPassenger(person p);
        void printPassengerList();
        void clearPassengerList();


};



/*
    Helper functions
*/

void cStringInit_1D(char s[], int size);
void cStringInit_2D(char s[], int size1, int size2);


#endif