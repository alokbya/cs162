#ifndef HELPERS_H
#define HELPERS_H
#include "messagelist.h"

char* parseReceivedData(char *line, int& id);
// int getIdIndexRec(line, )
int getDelData(char* line);
char* getNameToList(char * line);

#endif 