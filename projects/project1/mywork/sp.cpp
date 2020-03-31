// Alaa Alokby
// Assumptions: This program assumes that the user only enters time in the correct format (mm ss).
// If the user does not need two digits to express minutes or seconds, then the program will not 
// account for an extra digit (e.g. user enters '2' instead of '02').
// Details: This program calculates the total laps, average lap time, fastest lap time, and 
// slowest lap time based on the number of entries the user inputs, as well as the values that 
// the user inputs for each entry.

#include <iostream>
using namespace std;

// Function Prototypes


int main()
{
    int minutes = 0;
    int seconds = 0;
    int fastestTimeMinutes = 0;
    int fastestTimeSeconds = 0;
    int slowestTimeMinutes = 0;
    int slowestTimeSeconds = 0;
    int numberOfLaps = 0;
    int averageLapTimeMinutes = 0;
    int averageLapTimeSeconds = 0;

    do {
        cout << "Enter lap time (mm ss): ";
        cin >> minutes >> seconds;
        
        if (minutes != 0 && seconds != 0) {
            // Check fastest time in minutes and seconds
            if (minutes > fastestTimeMinutes){
                fastestTimeMinutes = minutes;
                fastestTimeSeconds = seconds;
            }
            else if (minutes == fastestTimeMinutes && seconds > fastestTimeSeconds) {
                fastestTimeSeconds = seconds;
            }
            else if (minutes < slowestTimeMinutes) {
                slowestTimeMinutes = minutes;
                slowestTimeSeconds = seconds;
            }
            else if (minutes == slowestTimeMinutes && seconds < slowestTimeSeconds) {
                slowestTimeSeconds = seconds;
            }
            numberOfLaps++;
        }

        // Calculations
        cout << "Total laps: " << numberOfLaps << endl;
        if (averageLapTimeMinutes
        
    } while (userInputMinutes != 0 && userInputSeconds != 0)

    return 0;
}
