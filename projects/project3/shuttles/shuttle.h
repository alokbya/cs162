#ifndef SHUTTLE_H
#define SHUTTLE_H

#include "person.h"
#include "spaceconstants.h"

class shuttle
{
    private:
        char name[MAX_STR];
        int capacity;
        int currentCount;
        person list[MAX_PASSENGERS_SHUTTLE];

    public:
        shuttle();        // Default constructor
        ~shuttle();       // Destructor
        void setName(char n[]);
        void getName(char n[]);
        void setCapacity(int cap);
        int getCapacity();
        int getCurrentCount();
        bool hasRoom();
        void addPassenger(person p);
        void printPassengerList();
        void clearPassengerList();
        void test();
        void reset();
};


#endif
