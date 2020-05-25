#ifndef ENTRIES_H
#define ENTRIES_H

/*
 entries class
 This class is a definition of staff member names and associated counts for 
 an individual's access history to different systems. Instances of this class
 will be used in syslog objects to document a specific user's number of 
 accesses into a system.
 
 char *name:    entries name
 int count:     number of times the entries has accessed a system
*/
class entries
{
    public:
        entries();
        entries(char *n, int c);
        entries(const entries& obj);    // copy constructor
        ~entries();
        //// setName
        // copy *n to *name
        void setName(const char *n);
        //// setCount
        // copy c to count
        void setCount(int c);
        //// setData
        // copy *n to name and copy c to count
        void setData(const char *n, int c);
        //// getName
        // return char* copy of name
        char* getName();
        //// getCount
        // return int count
        int getCount();
        //// incrementCount
        // count++
        void incrementCount();
    private:
        char* name;
        int count;
};

#endif