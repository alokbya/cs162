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

    shuttle shuttleList[MAX_STR];
    person passengerList[MAX_PASSENGERS_TOTAL];

    int personCount = 0;
    int shuttleCount = 0;
    
    readInAllPassengers(passengerList, passengerfile, personCount);
    readInShuttles(shuttleList, shuttlefile, shuttleCount);
    loadShuttles(shuttleList, passengerList, shuttleCount, personCount);
      
    return 0;
}