#ifndef HELPERS_H
#define HELPERS_H
#include "messagelist.h"

// Get data from the line item (line).
// Pass in id <int> by ref as a way to return 
// two values from this function. This function is used
// to parse relevent data to 'Recieve' a message.
// modify id (int), return recipient name (char*)
char* parseReceivedData(char *line, int& id);   
// Get data from the line item (line).
// Pass in line <char*> and return id <int> of
// message that is to be deleted. 
int getDelData(char* line);      
// Get data from line item (line).
// Pass in line <char*> and return name <char*>
// of the recipient whose messages are to be
// listed
char* getNameToList(char * line);

#endif 