#ifndef SYSLOG_H
#define SYSLOG_H
#include "entries.h"

/*
 syslog class
 This class is designed to analyze and process data pertaining to user access 
 to a system. This class is used to store <entries> types to represent users
 who have accessed a specific system.

 char *systemType: a name for the instantiated system
 entries *entriesList: a list of entries objects who have accessed this system
 int listSize: an integer value representing the max possilbe number of employees in *entriesList
 int count: an integer value representing the actual number of employees in *entriesList
*/
class syslog
{   
    public:
        syslog();                                               // default constructor
        syslog(char* sys, const int num);                       // overloaded constructor
        syslog(const syslog& obj);                              // copy constructor
        ~syslog();                                              // destructor
        //// addEntry
        // add employee with name *who to *entriesList if sys matches *systemType
        void addEntry(const char* sys, const char* who);
        //// printAll
        // prints all employee, system data inline with requirements
        void printAll();
        //// entryIndex
        // returns the index of the name (who) within *entriesList
        int entryIndex(const char *who);
        //// topAccessors
        // populates e1[] with staff members (entries objects) whose count matches 
        // the "top" count within the system. populates e2[] with staff members
        // whose count is second to the top count staff members
        void topAccessors(entries e1[], entries e2[], int& totalFirst, int& totalSecond);
        //// getTopCounts
        // sets first to the value of the highest count of a member. sets second
        // to the value of the second highest count of a member
        void getTopCounts(int& first, int& second);            
        //// printNames
        // prints list of names for Top, Second employees (entries)
        void printNames(entries e[], int total);

    private:
        char *systemType;           // dynamically allocated character array to store system type?
        entries *entriesList;       // array of names of people accessing the system
        int listSize;               // size of employee array
        int count;                  // number of employees in array
};

#endif