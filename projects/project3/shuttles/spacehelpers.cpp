#include <iostream>
#include <cstring>
#include <fstream>

// helper files
#include "person.h"
#include "shuttle.h"
#include "spacehelpers.h"

using namespace std;

/*
    LoadShuttles
    This function accepts four parameters: 1) A shuttle array, filled with shuttle objects that contain
    shuttle name, capacity, and current fill (should be zero at time of calling this function), 2) A person
    array which should be populated with the names of passengers at this point, 3) Shuttle count, which is 
    the size of the shuttle array, and 4) Person count, which is teh size of the person array.
    The purpose of this function is to load the the passengers into each shuttle in the shuttle array, 
    in a round-robin style.
*/
void loadShuttles(shuttle s[], person p[], int shuttleCount, int personCount)
{
    int waveCounter = 0;
    int shuttleCounter = 0;
    // iterate through each person in person list
    for (int i = 0; i < personCount; i++)
    {
        bool lastPassenger = (i == (personCount - 1));
        
        if(readyToSendWave(s, shuttleCount) || lastPassenger)
        {
            cout << "======================================================================" << endl;
            cout << "==============================";
            cout << " Wave  " << waveCounter + 1;
            cout << " ===============================" << endl;
            cout << "======================================================================" << endl;
            
            // print passenger list for each shuttle in s (shuttle list)
            for (int j = 0; j < shuttleCount; j++)
            {
                char shuttleName[MAX_STR];
                s[j].shuttle::getName(shuttleName);
                cout << shuttleName << " (" << s[j].shuttle::getCurrentCount() << "/"<< s[j].shuttle::getCapacity() << ") " << endl;
                cout << "Passengers:" << endl;
                s[j].shuttle::printPassengerList();
                s[j].shuttle::reset();
            }
            shuttleCounter = 0;
            waveCounter++;
            if(!lastPassenger)
                i = i - 1;
        }
        else
        {
            bool sent = false;
            while(!sent)
            {
                if(!s[shuttleCounter].shuttle::hasRoom())
                    incrementCounter(shuttleCounter, shuttleCount); // we know A shuttle has room, so increment to find it
                else if(s[shuttleCounter].shuttle::hasRoom())
                {
                    s[shuttleCounter].shuttle::addPassenger(p[i]);
                    sent = true;
                }
            }
            incrementCounter(shuttleCounter, shuttleCount);
        }
    }
}

void incrementCounter(int& counter, int max)
{
    counter = (counter <= max) ? counter + 1 : 0;
}

bool readyToSendWave(shuttle listOfShuttles[], int totalShuttles)
{   // Increment through each of the shuttles,
    // if none of them have room (are at capacity)
    // return true, otherwise return false
    int numberOfFullShuttles = 0;
    for (int i = 0; i < totalShuttles; i++)
    {
        if (!listOfShuttles[i].shuttle::hasRoom())
            numberOfFullShuttles++;
    }
    return numberOfFullShuttles == totalShuttles;
}

/*
    ReadInAllPassengers
    This function accepts two arguments: 1) An array of person types, and 2) a character pointer that, 
    in all cases for this program is the file path that is defined by the user as a command-line argument.
    The function will read in the passenger list at said file path.
    The purpose of this function is to load the person data into the program
    for further calculations.
*/
void readInAllPassengers(person p[], char* filepath, int& personCount)
{
    ifstream file;
    file.open(filepath);
    if(!file.is_open())
    {
        cerr << "Cannot open file at specified path: " << filepath << endl;
        cerr << "Exiting program" << endl;
        exit(0);
    }
    else
    {
        int personCounter = 0;
        while(file.peek() != EOF)
        {
            char line[MAX_STR] = {'\0'};
            file.getline(line, MAX_STR);
            // cout << line << endl;
            parsePerson(p, line, personCounter);
            personCounter++;
        }
        personCount = personCounter;
        
    }
}
/*
    ParsePerson
    This function accepts three arguments: 1) A person array to add the person object into, 
    2) A character array that contains all of the unorganized data to be parsed into the person
    object, and 4) A counter variable to mark the specific index that this person object 
    will reside within the person array. The purpose of this function is to organize 
    the person data into the person object.
*/
void parsePerson(person plist[], char line[], int personCounter)
{
    person p;
    char firstName[MAX_STR];
    char lastName[MAX_STR];
    cleanString(firstName, MAX_STR);
    cleanString(lastName, MAX_STR);

     // loop variables
    int counter = 0;        // keep track of loop number
    int token = 0;          // index where capacity begins
    char sentinel = '!';
    bool isFirstName = true;

    // parse out name, capacity
    while(sentinel != '\0')
    {
        sentinel = line[counter];
        if (sentinel == ' ')
        {
            isFirstName = false;
            token = counter + 1;
            counter++;
        }
        if (isFirstName)
            firstName[counter] = line[counter];
        if (!isFirstName)
            lastName[counter-token] = line[counter];

        counter++;
    }

    // get data into person object (fname, lname)
    p.person::setFirst(firstName);
    p.person::setLast(lastName);
    plist[personCounter] = p;
}

/*
    ReadInShuttles
    This function accepts two arguments: 1) An array of shuttle types, and 2) a character pointer that,
    in all cases for this program is the file path that is defined by the user as a command-line argument.
    This function will load shuttle data from the specified file into the shuttle array for further processing.
    The purpose of this functino is to load the shuttle data into memory for easy access.
*/
void readInShuttles(shuttle shuttles[], char* filepath, int& shuttleCount)
{
    // open the file
    ifstream file;
    file.open(filepath);
    if(!file.is_open())
    {
        // handle errors with opening the file
        cerr << "Cannot open file at specified path: " << filepath << endl;
        cerr << "Exiting program" << endl;
        exit(0);
    }
    else
    {
        // initialize a counter to keep track of the number of shuttles
        int shuttleCounter = 0;
        while(file.peek() != EOF)
        {
            // read in the data
            shuttle s;
            char line[MAX_STR] = {'\0'};
            file.getline(line, MAX_STR);
            // cout << line << endl;
            // parse the shuttle data into the correct fields within the shuttle object (s).
            parseShuttles(s, shuttles, line, shuttleCounter);
            shuttleCounter++;
        }
        shuttleCount = shuttleCounter;
    }
}

/*
    ParseShuttles
    This function accepts four arguments: 1) A shuttle object to have data organized into,
    2) A shuttle array to add the shuttle object into, 3) A character array that contains
    all of the unorganized data to be parsed into the shuttle object, and 4) A counter variable
    to mark the specific index that this shuttle object will reside within the shuttle array.
    The purpose of this function is to organize the shuttle data into the shuttle.
*/
void parseShuttles(shuttle s, shuttle shuttles[], char line[], int shuttleCounter)
{
    // declare c strings to hold shuttle information, clean out
    char name[MAX_STR];
    char strCap[MAX_STR];
    cleanString(name, MAX_STR);
    cleanString(strCap, MAX_STR);

    // loop variables
    int counter = 0;        // keep track of loop number
    int token = 0;          // index where capacity begins
    char sentinel = '!';
    bool isName = true;

    // parse out name, capacity
    while(sentinel != '\0')
    {
        sentinel = line[counter];
        if (sentinel == ' ')
        {
            isName = false;
            token = counter;
        }
        if (isName)
            name[counter] = line[counter];
        if (!isName)
            strCap[counter-token] = line[counter];

        counter++;
    }

    // populate shuttle object with line data, assign to array at index shuttleCounter
    // cout << name << endl;
    s.shuttle::setName(name);
    // cout << atoi(strCap) << endl;
    s.shuttle::setCapacity(atoi(strCap));
    // cout << shuttleCounter << endl;
    shuttles[shuttleCounter] = s;
}

/*
    CleanString
    This function accepts two arguments: 1) A character array, and 2) The size of that array.
    This function iterates through the array and populates each index with the null terminator
    value to indicate and empty character array. This is done to avoid any errors with this 
    character array down the line.
*/
void cleanString(char s[], int size)
{
    for (int i = 0; i < size; i++)
        s[i] = '\0';
}
