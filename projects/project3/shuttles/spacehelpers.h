#ifndef SPACEHELPERS_H
#define SPACEHELPERS_H

#include "person.h"
#include "shuttle.h"
#include "spaceconstants.h"

/*  
    Helpers.h is to define constant variables and functions that are common to 
    person.h, shuttle.h, and app.cpp. This allows for a place to write functions
    that are not specific to a particular class, but are required for the entire
    main application to run. These functionse leverage both the shuttle class and 
    the person class.
*/

void readInAllPassengers(person p[], char* filepath, int& personCount);
void readInShuttles(shuttle s[], char* filepath, int& personCount);
void parseShuttles(shuttle s, shuttle shuttles[], char line[], int shuttleCounter);
void cleanString(char s[], int size);
void parsePerson(person plist[], char line[], int personCounter);
void loadShuttles(shuttle s[], person[], int shuttleCount, int personCount);
bool readyToSendWave(shuttle listOfShuttles[], int totalShuttles);
void incrementCounter(int& counter, int max);

#endif