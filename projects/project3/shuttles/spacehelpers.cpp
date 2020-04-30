#include <iostream>
#include <cstring>
#include <fstream>

#include "person.h"
#include "shuttle.h"
#include "spacehelpers.h"

using namespace std;

/*
    Read all passengers from text file into person array.
*/
void readInAllPassengers(person p[], char* filepath)
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
            p[personCounter].person::setFirst(line);
            
        }
    }
}

/*

*/
void readInShuttles(shuttle shuttles[], char* filepath)
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
        int shuttleCounter = 0;
        while(file.peek() != EOF)
        {
            shuttle s;
            char line[MAX_STR] = {'\0'};
            file.getline(line, MAX_STR);
            
            parseShuttles(s, shuttles, line, shuttleCounter);
        }
    }
}

/*
    // designed for particularly formatted line
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
    s.shuttle::setName(name);
    s.shuttle::setCapacity(atoi(strCap));
    shuttles[shuttleCounter] = s;
}

/*
    Clean out a character array with null terminators.
*/
void cleanString(char s[], int size)
{
    for (int i = 0; i < size; i++)
        s[i] = '\0';
}
