#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "syslog.h"

using namespace std;

#define RDBUFSIZE 100

int main(int argc,char* argv[])
{
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <access log file> <systems file> <num staff>" << endl;
        return(0);
    }

    const char* logfile = argv[1];
    const char* sysfile = argv[2];
    const int numWho = atoi(argv[3]);
    
    // Read the list of systems and create an array of syslog objects
    ifstream sysin(sysfile);
    int numSystems;
    sysin >> numSystems;                                        // number of systems in file (first line)
    sysin.get();
    syslog** allLogs = new syslog*[numSystems];                 // all logs is a double pointer w/ numSystems rows 
    for (int i=0;i<numSystems;i++)
    {
        char sys[RDBUFSIZE];
        sysin.getline(sys,RDBUFSIZE);
        allLogs[i] = new syslog(sys,numWho);
    }
    sysin.close();
    cout << "got systems" << endl;
    // Read the access list and add to the system log
    ifstream in(logfile);
    int numEntries;
    in >> numEntries;
    in.get();
    for (int i=0;i<numEntries;i++)
    {
        char sys[RDBUFSIZE];
        char who[RDBUFSIZE];

        in.getline(sys,RDBUFSIZE,',');
        in.get(); // eat the extra space
        in.getline(who,RDBUFSIZE);

        // Loop over all of the system logs and call "addEntry()" on each
        // one. The syslob object will check to see if it matches the given
        // system and will only add the entry if it matches the system.
        for (int j=0;j<numSystems;j++)
        {
            allLogs[j]->addEntry(sys,who);
        }
    }
    in.close();

    cout << "finished reading employees" << endl;
    // Print out the report for each system log.
    for (int j=0;j<numSystems;j++)
    {
	    allLogs[j]->printAll();
    }

    // Clean up memory to avoid memory leaks
    for (int j=0;j<numSystems;j++)
    {
	    delete allLogs[j];
    }
        delete [] allLogs;

    return 0;
}
