#ifndef PERSON_H
#define PERSON_H



#include "spaceconstants.h"

class person
{
    private:
        char fname[MAX_STR];
        char lname[MAX_STR];

    public: 
        person();
        ~person();
        void setFirst(char f[]);
        void setLast(char l[]);
        void getFirst(char f[]);
        void getLast(char l[]);
        void test();
};

/*
    Helper functions
*/




#endif