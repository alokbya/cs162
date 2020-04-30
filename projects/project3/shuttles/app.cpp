#include <iostream>
#include <cstring>




#include "spacehelpers.h"
#include "person.h"
#include "shuttle.h"


using namespace std;

int main(int argc, char* argv[]) 
{
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " <shuttles_file> <passengers_file> " << endl;
        return 0;
    }

    char* shuttlefile = argv[1];
    char* passengerfile = argv[2];


    // cout << "running in main!" << endl;
    // main algorithm
    /*
    Read in shuttle data and store into an array of shuttle objects

    Start putting people in shuttles, round robin style, as long as shuttles have room.
        If a shuttle doesn't have room, the sorting algorithm skips that shuttle and goes to the next.
        If all shuttles are full, then a "wave" is printed (a list of all passengers in each shuttle).
        
    Once the wave is printed, all shuttles are cleared and if there are still passengers to be placed, the algorithm repeats.

    Repeat until all passengers are evacuated.
    */
    // char f[5] = {'a', 'l', 'a', 'a', '\0'};
    // char l[5] = {'b', 'l', 'l', 'a', '\0'};

    person p1;
    shuttle s;
    shuttle l[MAX_STR];
    // First, get all passengers
    // Then, make a list of all the shuttles

    p1.person::getFirst();
    p1.person::getLast();

    s.shuttle::addPassenger(p1);
    // char fn[5] = {'a', 'l', 'a', 'a', '\0'};
    // char ln[7] = {'a', 'l', 'o', 'k', 'b', 'y', '\0'};

    person p2[MAX_PASSENGERS_TOTAL];

    readInAllPassengers(p2, passengerfile);
    readInShuttles(l, shuttlefile);
    
    for (int i = 0; i < 10; i++)
    {
        l[i].shuttle::getName();
        cout << endl;
        cout << l[i].shuttle::getCapacity() << endl;
    }
    // p1.person::test();
    // person::setFirst(p1.fname, f);
    // person::setLast(p1.lname, l);
    // p1.person::setFirst(fn);
    // p1.person::setLast(ln);

    // p1.person::getFirst();
    // cout << " ";
    // p1.person::getLast();
        
    return 0;
}