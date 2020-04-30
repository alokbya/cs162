#ifndef SPACEHELPERS_H
#define SPACEHELPERS_H

// #include "shuttle.h"
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
void readInAllPassengers(person p[], char* filepath);

void readInShuttles(shuttle s[], char* filepath);

void parseShuttles(shuttle s, shuttle shuttles[], char line[], int shuttleCounter);

void cleanString(char s[], int size);

// void parsePersons(char line[], person


#endif