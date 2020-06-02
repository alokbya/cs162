#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include "helpers.h"
// #include "messageList.h"
using namespace std;

#define BUFF 256

void readData(char* f)
{
    // open file
    ifstream input;
    input.open(f);
    if(!input.is_open())
    {
        cerr << "Cannot open file at specified path " << f << endl;
        cerr << "Exiting program " << endl;
        exit(0);
    }
    else
    {
        // MessageList mList = MessageList();
        cout << "reading data " << endl << endl;
        char line[BUFF];
        
        // int id = -1;
        // char* name;

        while(input.peek() != EOF)
        {
            input.getline(line, BUFF);
            // processCommand(mList, line);
        }

        // MessageList mList;
        // const char* n = "john";
        // Message m(1, n);
        
        // mList.addNewMessage(&m);

    
    }
    input.close();
    cout << "closed file " << endl;
}

char* getCommand(const char s[])
{
    // get first word in char array
    char *n = nullptr;
    char newString[BUFF] = {'\0'};
    int index = 0;
    char c = '!';
    while(c != ' ')
    {
        c = s[index];
        newString[index] = c;
        index++;
    }
    n = newString;
    return n;
}

void processCommand(LinkedList& ll, char* line)
{
    if(line[0] == 'R')
    {
        // ll.listAllMessages();
        // cout << "Receiving " << endl;
        // get receipt data
        // id, name
        int id = -1;
        char *name = parseReceivedData(line, id);
        // name = parseReceivedData(line, id);
        
        
        cout << line << endl;
    // create new message
        // Message m(id, name);
        Message m = Message(id, name);
        // ll.addNewMessage(m);
        // cout << name << endl;
        // mList.listMessages(name);
        // ll.listAllMessages();

        delete [] name;                    // need to delete name
        // add message to list
            // mList.add(&m);
    }
    else if(line[0] == 'L')
    {
        // cout << "List" << endl;
        // get list data
            // recipeint name
        // read recipients messages
            // listMessages(recipientsName)
    }
    else if(line[0] == 'D')
    {
        // cout << "Delete" << endl;
        // get line data
            // id
        // deleteMessage(id);
    }
    else if(line[0] == 'A')
    {
        // listAllMessages()
    }
    else 
    {
        cout << "Error, could not determine command " << endl;
    }
    
}

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
    // cout << data[2] << endl;
    mark++;
    fullName[mark] = ' ';
    mark++;
    // mark++;
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