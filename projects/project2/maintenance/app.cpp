/*
Sources: https://stackoverflow.com/questions/16772842/what-is-the-difference-between-cout-cerr-clog-of-iostream-header-in-c-when
		http://www.cplusplus.com/reference/iostream/cerr/
		http://www.cplusplus.com/articles/DEN36Up4/
*/

#include <iostream>
#include <cstring>
#include "functions.h"

using namespace std;

// Function Prototypes

// MAIN
int main(int argc, char* argv[])
{
	// Check the number of parameters
	if (argc != 2)
	{
		cerr << "Usage: " << argv[0] << " <datafile>" << endl;	// using cerr for convention's sake
		return 0;												// should this return somehting != 0
	}
	
	char* datafile = argv[1];									// This is the filename containing the tasklist
	// Define and initialize variables
	// task calendar[CAL_DAYS][3];
	task assignments[100];
	day cal[CAL_DAYS];

	//int totalCalSize = 0;
	int totalAssignments = 0;

	//ErrorList overlapErrors;
	ErrorList duplicateErrors;
	ErrorList quantityErrors;

	duplicateErrors.errorCounter = 0;
	
	//int duplicateLineIndeces[MAX_STR] = {0};
	//int quantityLineIndeces[MAX_STR] = {0};

	// Main part of the program
	ReadDataIntoAssignments(datafile, assignments, totalAssignments);
	FillCal(cal, assignments, totalAssignments);
	
	FindQuantityErrors(quantityErrors, assignments, totalAssignments);
	FindDuplicateErrors(cal, duplicateErrors);

	ReadCal(cal);
	ReadQuantityErrors(quantityErrors);
	ReadDuplicateErrors(duplicateErrors);

	// FillCalTest(day cal[], task assignments[], int size);
	return 0;
}

