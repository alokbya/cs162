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

int main(int argc, char* argv[])
{
    if (argc != 2)
        cerr << "Usage: " << argv[0] << " <datafile> " << endl;
    else
    {
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
        }
    }
    return 0;

}