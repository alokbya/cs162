#include <iostream>
#include "shuttle.h"
using namespace std;

int main(int argc, char* argv[]) 
{
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " <shuttles_file> <passengers_file> " << endl;
        return 0;
    }

    cout << "running in main!" << endl;
    // main algorithm
    /*
    Read in shuttle data and store into an array of shuttle objects

    Start putting people in shuttles, round robin style, as long as shuttles have room.
        If a shuttle doesn't have room, the sorting algorithm skips that shuttle and goes to the next.
        If all shuttles are full, then a "wave" is printed (a list of all passengers in each shuttle).
        
    Once the wave is printed, all shuttles are cleared and if there are still passengers to be placed, the algorithm repeats.

    Repeat until all passengers are evacuated.
    */
        
    return 0;
}