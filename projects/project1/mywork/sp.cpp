// Alaa Alokby
// Assumptions: This program assumes that the user only enters time in the correct format (mm ss).
// If the user does not need two digits to express minutes or seconds, then the program will not 
// account for an extra digit (e.g. user enters '2' instead of '02').
// Details: This program calculates the total laps, average lap time, fastest lap time, and 
// slowest lap time based on the number of entries the user inputs, as well as the values that 
// the user inputs for each entry.

#include <iostream>
#include <iomanip>  // for mm : ss output

using namespace std;

// Function Prototypes
void OutputTimeInCorrectFormat(int minutes, int seconds);
int GetAverageTimeInSeconds(int totalMinutes, int totalSeconds, int numberOfLaps);
void FormatAverageTimeOutput(int averageTimeInSeconds);

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
    int totalMinutes = 0;
    int totalSeconds = 0;
    
    do {
        cout << "Enter lap time (mm ss): ";
        cin >> minutes >> seconds;
        
        // Set fastest, slowest times accordingly on first lap
        if (numberOfLaps == 0) {
            fastestTimeMinutes = minutes;
            fastestTimeSeconds = seconds;
            slowestTimeMinutes = minutes;
            slowestTimeSeconds = seconds;
        }

        // Check fastest time in minutes and seconds
        if (minutes < fastestTimeMinutes){
            fastestTimeMinutes = minutes;
            fastestTimeSeconds = seconds;
        }
        // If seconds are faster, but minutes are the same
        else if (minutes == fastestTimeMinutes && seconds < fastestTimeSeconds) {
            fastestTimeSeconds = seconds;
        }
        else if (minutes > slowestTimeMinutes) {
            slowestTimeMinutes = minutes;
            slowestTimeSeconds = seconds;
        }
        else if (minutes == slowestTimeMinutes && seconds > slowestTimeSeconds) {
            slowestTimeSeconds = seconds;
        }
        
        // Calculations for average time
        totalMinutes += minutes;
        totalSeconds += seconds;
        numberOfLaps++;
        averageLapTimeMinutes = totalMinutes / numberOfLaps;
        averageLapTimeSeconds = totalSeconds / numberOfLaps;

        cout << "AVERAGE TIME: ";
        int averageTimeInSeconds = GetAverageTimeInSeconds(totalMinutes, totalSeconds, numberOfLaps);
        FormatAverageTimeOutput(averageTimeInSeconds);
        cout << endl;
        // Testing output
        //cout << "Fastest Time: ";
        //OutputTimeInCorrectFormat(fastestTimeMinutes, fastestTimeSeconds);
        //cout << endl;
        //OutputTimeInCorrectFormat(slowestTimeMinutes, slowestTimeSeconds);
        //cout << endl;
        //OutputTimeInCorrectFormat(averageLapTimeMinutes, averageLapTimeSeconds);
        //cout << endl;
        
        // Calculations
        //cout << "Total laps: " << numberOfLaps << endl;
        //cout << "END LAP" << endl;
        
    } while (minutes > 0 || seconds > 0);

    numberOfLaps -= 1;
    cout << numberOfLaps << endl;
    cout << "END RACE" << endl;

    return 0;
}

// Function Definitions

// OutputTimeInCorrectFormat
// Passed in values are output to console in correct lap time format.
void OutputTimeInCorrectFormat(int minutes, int seconds)
{
    cout << setfill('0') << setw(2) << minutes << ":" << setw(2) <<  seconds;
}

// GetAverageMinutes
int GetAverageTimeInSeconds(int totalMinutes, int totalSeconds, int numberOfLaps)
{
    int totalTimeInSeconds = totalSeconds + (totalMinutes * 60);
    int averageTotalTimeInSeconds = totalSeconds / numberOfLaps;

    cout << "TOTAL MINUTES: " << totalMinutes << endl;
    cout << "TOTAL SECONDS: " << totalSeconds << endl;
    cout << "TOTAL LAPS: " << numberOfLaps << endl;
    cout << "TOTAL TIME IN SECONDS: " << totalSeconds + totalMinutes * 60 << endl;
    cout << "AVG TOTAL IN SECONDS: " << (totalSeconds + totalMinutes * 60) / numberOfLaps << endl; 
    return (totalSeconds + totalMinutes * 60) / numberOfLaps;
}

void FormatAverageTimeOutput(int averageTimeInSeconds)
{
    int averageMinutes = 0;
    int averageSeconds = 0;
    // Math here
    averageMinutes = averageTimeInSeconds / 60;
    averageSeconds = averageTimeInSeconds % 60;
    OutputTimeInCorrectFormat(averageMinutes, averageSeconds);
}
