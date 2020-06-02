/*
Name: Alaa Alokby
Project: Project 5 - Messages
Date Due: 5/31/2020
Assumptions: All recipients have two names (first, last)
Notes:
*/

#include <fstream>
#include <istream>
#include <iostream>
#include <cstring>
#include "helpers.h"
#include "LinkedList.h"

#define BUFF 256
using namespace std;

void runTest();

int main(int argc, char* argv[])
{
    if (argc != 2)
        cerr << "Usage: " << argv[0] << " <datafile> " << endl;
    else
    {
        cout << "running main" << endl;
        cout << argv[1] << endl;
        //  NEW CODE BELOW
        ifstream input;
        input.open(argv[1]);
        if(!input.is_open())
        {
            cerr << "Cannot open file at specified path " << argv[1] << endl;
            cerr << "Exiting program " << endl;
            exit(0);
        }
        else
        {
            LinkedList ll;
            char item[BUFF];
            cout << "reading data " << endl << endl;
            while(input.peek() != EOF)
            {
                input.getline(item, BUFF);
                if (item[0] == 'R')
                {
                    int id = -1;
                    char *name = parseReceivedData(item, id);
                    ll.add(id, name);
                    delete [] name;            // need to delete name
                }
                else if (item[0] == 'L')
                {
                    char * name = getNameToList(item);   // get unique id to print
                    ll.print(name);
                    delete [] name;
                }
                else if (item[0] == 'D')
                {   
                    int val = getDelData(item);
                    ll.remove(val);
                }
                else{
                    ll.print();
                }   
            }
            input.close();
            cout << "closed file " << endl;
            cout << "end main" << endl;
        }
    }
    return 0;

}

// void runTest()
// {
//     cout << "testing" << endl;  
//     MessageList mList;
//     int id1 = -1;
    
//     char one[] = "Receive 15 Danica Moten";
//     char *name1 = parseReceivedData(one, id1);
//     Message m1 = Message(id1, name1);
//     mList.addNewMessage(m1);
//     delete [] name1;
    
//     mList.listAllMessages();
    

//     char two[] = "Receive 9 Ella Barela";
//     char *name2 = parseReceivedData(two, id1);
//     int id2 = -1;
//     Message m2 = Message(id2, name2);
//     mList.addNewMessage(m2);
//     delete [] name2;
//     mList.listAllMessages();
    
    
    
//     // mList.listAllMessages();
// }
