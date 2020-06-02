#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include "helpers.h"
using namespace std;

#define BUFF 256

// parse through raw string, change id by ref,
// return full name as char*
char* parseReceivedData(char* line, int& id)
{
    // ex. Receive 34 Alaa Alokby
    // This is only called if data is "RECEIVED"
    int count = 0;
    char ptr[strlen(line)] = {'\0'};
    char *token = nullptr;
    char data[4][BUFF];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < BUFF; j++)
            data[i][j] = {'\0'};
    }

    for(int i = 0; i < static_cast<int>(strlen(line)) + 1; i++)
        ptr[i] = line[i];
    
    token = strtok(ptr, " ");
    strcpy(data[count], token);
    count++;
    while (token)
    {
        token = strtok(NULL, " ");
        if(token)
            strcpy(data[count], token);
        count++;
    }

    id = atoi(data[1]);
    int mark = 0;
    int size = strlen(data[2]) + strlen(data[3]) + 1;
    char fullName[size + 1] = {'\0'};
    for(int i = 0; i < (static_cast<int>(strlen(data[2]))); i++)
    {
        fullName[i] = data[2][i];
        mark = i;
    }
    
    mark++;
    fullName[mark] = ' ';
    mark++;
    for (int j = 0; j < static_cast<int>(strlen(data[3])); j++)
    {
        fullName[mark] = data[3][j];
        mark++;
    }
    
    char* name = new char[strlen(fullName) + 1];            // don't forget to allocate for this guy
    strcpy(name, fullName);
    
    return name;
}

int getDelData(char* line)
{
    int count = 0;
    char ptr[strlen(line)] = {'\0'};
    char *token = nullptr;

    char data[2][BUFF];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < BUFF; j++)
            data[i][j] = {'\0'};
    }

    for(int i = 0; i < static_cast<int>(strlen(line)) + 1; i++)
        ptr[i] = line[i];
    
    token = strtok(ptr, " ");
    strcpy(data[count], token);
    count++;
    
    while (token)
    {
        token = strtok(NULL, " ");
        if(token)
            strcpy(data[count], token);
        count++;
    }

    return atoi(data[1]);
}

char* getNameToList(char * line)
{
    int count = 0;
    int mark = 0;
    char ptr[strlen(line)] = {'\0'};
    char *token = nullptr;

    char data[2][BUFF];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < BUFF; j++)
            data[i][j] = {'\0'};
    }

    for(int i = 0; i < static_cast<int>(strlen(line)) + 1; i++)
        ptr[i] = line[i];
    
    token = strtok(ptr, " ");
    strcpy(data[count], token);
    count++;
    
    while (token)
    {
        token = strtok(NULL, " ");
        if(token)
            strcpy(data[count], token);
        count++;
    }
    
    int size = strlen(data[1]) + strlen(data[2]) + 1;
    char fullName[size + 1] = {'\0'};
    for(int i = 0; i < (static_cast<int>(strlen(data[1]))); i++)
    {
        fullName[i] = data[1][i];
        mark = i;
    }
    mark++;
    fullName[mark] = ' ';
    mark++;
    for (int j = 0; j < static_cast<int>(strlen(data[2])); j++)
    {
        fullName[mark] = data[2][j];
        mark++;
    }
    
    char* name = new char[strlen(fullName) + 1];            // don't forget to allocate for this guy
    strcpy(name, fullName);


    return name;
}