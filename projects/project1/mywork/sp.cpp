/*  Name:           Alaa Alokby
    Assumptions:    Most importantly, this application assumes that the user will enter numbers into the 
                    console in exactly the right format. That format is <int> <space> <int>. That is, if the
                    user is trying to enter one minute and seven seconds as a lap time, their input will 
                    be 1 7, and not 01 07. Leading zeros will be output to the user, but this application
                    is not expecting the user to enter leading zeros for single digit numbers. This program
                    was not tested against other types of input, as the instructions explicitly stated that
                    "Your program does not need to worry about invalid values."
                    Another important assumtion that is made is that the granularity of lap time does not
                    exceed seconds. Any time that is entered will round down to the nearest second. Because of 
                    downward rounding, the lap time will dispaly a value of seconds that has been achieved by 
                    the user. For instance, if the user enters 0 14, 0 15, 0 15, an accurate average calculation
                    to three significant digits will yield a value of 14.667. This program rounds down and will 
                    yield a value of 14 seconds, as the average of those time entries. This is because the user did
                    not achieve an average of 15 but they did achieve a value of 14 seconds.
    Details:        This program calculates the total laps, average lap time, fastest lap time, fastest lap number,
                    slowest lap time, and slowest lap number based on the number of entries the user inputs, 
                    as well as the values that the user inputs for each entry.
    Sources:        http://www.cplusplus.com/reference/iomanip/
                    https://www.learncpp.com/cpp-tutorial/73-passing-arguments-by-reference/
*/

#include <iostream>
#include <iomanip>  // for mm : ss output

using namespace std;

// Function Prototypes
void OutputTimeInCorrectFormat(int seconds);
void UpdateFastestTime(int &newMinutes, int &newSeconds, int &fastestSeconds);
void UpdateSlowestTime(int &newMinutes, int &newSeconds, int &slowestSeconds);
void UpdateData(int &newSeconds, int &fastestSeconds, int &slowestSeconds, int &totalSeconds, int &numberOfLaps, int &fastestLap, int &slowestLap);
void ReadInTimes(int &inputMinutes, int &inputSeconds, int &totalTimeSeconds, int &lapTimeSeconds);
void OutputData(int totalSeconds, int fastestTime, int slowestTime, int totalLaps, int fastLap, int slowLap);

int main()
{
    // Declare, Initialize Local Variables
    int inputMinutes = 0;
    int inputSeconds = 0;
    int lapTimeSeconds = 0;
    int fastestTimeSeconds = 0;
    int slowestTimeSeconds = 0;
    int numberOfLaps = 0;
    int totalTimeSeconds = 0;
    int fastestLapNumber = 0;
    int slowestLapNumber = 0;
    
    // Get Data
    do {
        
        ReadInTimes(inputMinutes, inputSeconds, totalTimeSeconds, lapTimeSeconds);
        UpdateData(lapTimeSeconds, fastestTimeSeconds, slowestTimeSeconds, totalTimeSeconds, numberOfLaps, fastestLapNumber, slowestLapNumber);
    
    } while (inputMinutes > 0 || inputSeconds > 0);
    
    // Output Data
    OutputData(totalTimeSeconds, fastestTimeSeconds, slowestTimeSeconds, numberOfLaps, fastestLapNumber, slowestLapNumber); 
    return 0;
}

//  ********** Function Definitions **********  

/*  *** OutputTimeInCorrectFormat ***
    This function accepts an integer that is in units of seconds. The function will then 
    breakdown the sum of seconds into units of minutes and seconds, and then properly 
    format them into output to the console. 
*/
void OutputTimeInCorrectFormat(int totalSeconds)
{   
    cout << setfill('0') << setw(2) << totalSeconds / 60 << ":" << setw(2) << totalSeconds % 60;
}

/*  *** UpdateFastestTime ***
    This function accepts the most recently input lap time in units of seconds, the variable
    holding the value of fastst lap in seconds, the variable holding the value of the total
    number of laps, and then the variable holding the value of the lap number for which the 
    fastest lap was entered. This function then checks to see if the newly input lap time value
    is faster than the previously held record for fastest time. If so, the fastest lap time 
    is updated with the most recent entry, and the fastest lap number is updated with the 
    most recent entry's respective lap number.
*/
void UpdateFastestTime(int &newSeconds, int &fastestSeconds, int &numberOfLaps, int &fastestLap)
{
    if (newSeconds < fastestSeconds) {
        fastestSeconds = newSeconds;
        fastestLap = numberOfLaps;
    }
}

/*  *** UpdateSlowestTime ***
    This function accepts the most recently input lap time value in units of seconds, the variable 
    for the slowest lap time recorded, in seconds, the total number of laps that have been entered,
    and the slowest lap number that is associated with the slowest lap time. The function determines
    if the most recent lap time input is slower than the previously recorded slowest lap time. If 
    this is the case, then the slowest lap time is updated with the most recent entry. The 
    slowest lap number is also updated to reflect the lap number with the slowest time. 
*/
void UpdateSlowestTime(int &newSeconds, int &slowestSeconds, int &numberOfLaps, int &slowestLap)
{   
    if (newSeconds > slowestSeconds) {
        slowestSeconds = newSeconds;
        slowestLap = numberOfLaps;
    }
}

/*  *** UpdateData ***
    This function accepts the most recently entered value for lap time in seconds, the value for the fastest 
    lap time, slowest lap time, total seconds elapsed while running laps, the number of laps, the fastest 
    lap number, and the slowest lap number. Firstly, this function evaluates whether or not only one lap time
    has been entered, and if so the function will assign this single value to the fastest and slowest lap times,
    as well as mark the first lap number as the fastest and slowest lap. This is an edge case. 
    In all other circumstances (if more than one lap is entered) the function increments the number of laps, 
    and then calls functions UpdateFastestTime() and UpdateSlowestTime() to update the fastest and slowest 
    lap times respectively, if necessary. Lastly, this function the most recently entered lap time to the total 
    time (the sum of all lap times).
*/
void UpdateData(int &newSeconds, int &fastestSeconds, int &slowestSeconds, int &totalSeconds, int &numberOfLaps, int &fastestLap, int &slowestLap)
{
    if (numberOfLaps == 0 ) {
        fastestSeconds = newSeconds;
        slowestSeconds = newSeconds;
        fastestLap = 1; 
        slowestLap = 1;
    }
    if (newSeconds > 0) {
        numberOfLaps++;
        UpdateFastestTime(newSeconds, fastestSeconds, numberOfLaps, fastestLap);
        UpdateSlowestTime(newSeconds, slowestSeconds, numberOfLaps, slowestLap);
    }
}

/*  *** ReadInTimes ***
    This function accepts the reference to the most recenly entered value for minutes and seconds, as well 
    as the reference to the value for the total amount of seconds entered as lap time. The function reads
    in user input for minutes and seconds, and then accordingly increments the total number of seconds.
    It is important to note that there is no validation performed on the user input. This entire program
    assumes that the user knows what they are doing and will only enter valid values.
*/
void ReadInTimes(int &inputMinutes, int &inputSeconds, int &totalSeconds, int &lapTimeSeconds)
{
    cout << "Enter lap time (MM SS): ";
    cin >> inputMinutes >> inputSeconds;
    totalSeconds += inputSeconds + inputMinutes * 60;
    lapTimeSeconds = inputSeconds + inputMinutes * 60;
}

/*  *** OutputData ***
    This function is used to output all relevant data to the console for the user to read. All parameters
    are passed by value because this is the last function to be called in main() and no variables require 
    modification. 
*/
void OutputData(int totalSeconds, int fastestTime, int slowestTime, int totalLaps, int fastLap, int slowLap)
{
    cout << "Total Laps: " << totalLaps << endl;
    cout << "Average lap time: ";
    OutputTimeInCorrectFormat((totalSeconds / (totalLaps)));
    cout << endl << "Fastest lap was #" << fastLap << endl << "Fastest Lap Time: ";
    OutputTimeInCorrectFormat(fastestTime);
    cout << endl << "Slowest lap was #" << slowLap << endl << "Slowest Lap Time: ";
    OutputTimeInCorrectFormat(slowestTime);
    cout << endl;
}
