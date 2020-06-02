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
                    Message * m = new Message(id, name);
                    ll.add(m);
                    // ll.print();
                    delete [] name;            // need to delete name
                    delete m;                  // need to delete message
                    
                // processCommand(ll, item);
                }
                else if (item[0] == 'L')
                {
                    ll.print();
                }
                else if (item[0] == 'D')
                {
                    int val = getDelData(item);
                    ll.remove(val);
                }
                
            }
        
        


        //  OG CODE BELOW
        // readData(argv[1]);
        // MessageList mList;
        // ifstream input;
        // input.open(argv[1]);
        // if(!input.is_open())
        // {
        //     cerr << "Cannot open file at specified path " << argv[1] << endl;
        //     cerr << "Exiting program " << endl;
        //     exit(0);
        // }
        // else
        // {
        //     cout << "reading data " << endl << endl;
        //     char item[BUFF];
        //     char cmd[BUFF];
        //     char name[BUFF];
        //     int id = 0;
        //     while(input.peek() != EOF)
        //     {
        //         input >> item;
        //         if (item[0] == 'R')
        //         {
        //             strcpy(cmd, item);
        //             input >> id;
        //             input.getline(name, BUFF);
        //             cout << name << endl;
                
        //             Message m = Message(id, name);
        //             mList.addNewMessage(m);
        //             mList.listAllMessages();
        //         }


                
        //         // input.getline(line, BUFF);
        //         // if(line[0] == 'R')
        //         // {   int id = -1;
        //         //     char *name = parseReceivedData(line, id);
        //         //     cout << name << " " << id << endl;
        //         //     cout << line << endl;
        //         //     Message m = Message(id, name);
        //         //     mList.addNewMessage(m);
        //         //     // mList.listAllMessages();
        //         //     delete [] name;                    // need to delete name
        //         // }
        //         // else if(line[0] == 'L')
        //         // {
        //         //     // cout << "List" << endl;
        //         //     // get list data
        //         //         // recipeint name
        //         //     // read recipients messages
        //         //         // listMessages(recipientsName)
        //         // }
        //         // else if(line[0] == 'D')
        //         // {
        //         //     // cout << "Delete" << endl;
        //         //     // get line data
        //         //         // id
        //         //     // deleteMessage(id);
        //         // }
        //         // else if(line[0] == 'A')
        //         // {
        //         //     // listAllMessages()
        //         // }
        //         // else 
        //         // {
        //         //     cout << "Error, could not determine command " << endl;
        //         // }
        //         // // processCommand(mList, line);
        //     }
        // }
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
