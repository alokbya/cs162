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
int GetAverageTime(int totalSeconds, int numberOfLaps);
void FormatAverageTimeOutput(int averageTimeInSeconds);
void UpdateFastestTime(int &newMinutes, int &newSeconds, int &fastestMinutes, int &fastestSeconds);
void UpdateSlowestTime(int &newMinutes, int &newSeconds, int &slowestMinutes, int &slowestSeconds);
void UpdateData(int &newMinutes, int &newSeconds, int &fastestMinutes, int &fastestSeconds, int &slowestMinutes, int &slowestSeconds, int &totalSeconds, int &numberOfLaps, int &fastestLap, int &slowestLap);

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
    int totalTimeSeconds = 0;
    int fastestLap = 0;
    int slowestLap = 0;
    
    do {
        cout << "Enter lap time (mm ss): ";
        cin >> minutes >> seconds;
       

        UpdateData(minutes, seconds, fastestTimeMinutes, fastestTimeSeconds, slowestTimeMinutes, slowestTimeSeconds, totalTimeSeconds, numberOfLaps, fastestLap, slowestLap);
        // Set fastest, slowest times accordingly on first lap
        // Calculations for average time

        cout << "AVERAGE TIME: ";
        int averageTimeInSeconds = GetAverageTime(totalTimeSeconds, numberOfLaps);
        FormatAverageTimeOutput(averageTimeInSeconds);
        cout << endl;
        
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

int GetAverageTime(int totalSeconds, int numberOfLaps)
{
    int totalTimeInSeconds = totalSeconds;
    int averageTotalTimeInSeconds = totalSeconds / numberOfLaps;

    cout << "TOTAL MINUTES: " << totalSeconds / 60 << endl;
    cout << "TOTAL SECONDS: " << totalSeconds % 60 << endl;
    cout << "TOTAL LAPS: " << numberOfLaps << endl;
    cout << "TOTAL TIME IN SECONDS: " << totalSeconds << endl;
    cout << "AVG TOTAL IN SECONDS: " << totalSeconds / numberOfLaps << endl; 
    return totalSeconds / numberOfLaps;
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

void UpdateFastestTime(int &newMinutes, int &newSeconds, int &fastestMinutes, int &fastestSeconds, int &numberOfLaps, int &fastestLap)
{
    if (newMinutes < fastestMinutes) {
        fastestMinutes = newMinutes;
        fastestSeconds = newSeconds;
        fastestLap = numberOfLaps;
    }
    else if (newMinutes == fastestMinutes && newSeconds < fastestSeconds) {
        fastestSeconds = newSeconds;
        fastestLap = numberOfLaps;
    }
}
void UpdateSlowestTime(int &newMinutes, int &newSeconds, int &slowestMinutes, int &slowestSeconds, int &numberOfLaps, int &slowestLap)
{
    if (newMinutes > slowestMinutes) {
        slowestMinutes = newMinutes;
        slowestSeconds = newSeconds;
        slowestLap = numberOfLaps;
    }
    else if (newMinutes == slowestMinutes && newSeconds > slowestSeconds) {
        slowestSeconds = newSeconds;
        slowestLap = numberOfLaps;
    }
}

void UpdateData(int &newMinutes, int &newSeconds, int &fastestMinutes, int &fastestSeconds, int &slowestMinutes, int &slowestSeconds, int &totalSeconds, int &numberOfLaps, int &fastestLap, int &slowestLap)
{
    UpdateFastestTime(newMinutes, newSeconds, fastestMinutes, fastestSeconds, numberOfLaps, fastestLap);
    UpdateSlowestTime(newMinutes, newSeconds, slowestMinutes, slowestSeconds, numberOfLaps, slowestLap);
    totalSeconds += newMinutes * 60 + newSeconds;
    numberOfLaps++;
    if (numberOfLaps == 0) {
        //fastestMinutes = newMinutes;
        //fastestSeconds = newSeconds;
        //slowestMinutes = newMinutes;
        //slowestSeconds = newSeconds;
        fastestMinutes, slowestMinutes = newMinutes;
        fastestSeconds, slowestSeconds = newSeconds;
    }
}
