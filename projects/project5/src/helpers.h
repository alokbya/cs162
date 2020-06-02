#ifndef HELPERS_H
#define HELPERS_H
#include "LinkedList.h"

void readData(char* f);
char* getCommand(const char s[]);   // returns the command usedsdf
void processCommand(LinkedList& ll, char* line);
char* parseReceivedData(char *line, int& id);
// int getIdIndexRec(line, )
int getDelData(char* line);

#endif 