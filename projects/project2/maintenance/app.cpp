/*
Sources: https://stackoverflow.com/questions/16772842/what-is-the-difference-between-cout-cerr-clog-of-iostream-header-in-c-when
		http://www.cplusplus.com/reference/iostream/cerr/
		http://www.cplusplus.com/articles/DEN36Up4/
*/

#include <iostream>
#include <cstring>
#include "dtypes.h"

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
	//day calendar[CAL_DAYS];
	day assignments[100];

	//int totalCalSize = 0;
	int totalAssignments = 0;

	//ErrorList overlapErrors;
	ErrorList duplicateErrors;
	ErrorList quantityErrors;
	
	//int duplicateLineIndeces[MAX_STR] = {0};
	//int quantityLineIndeces[MAX_STR] = {0};

	// Main part of the program
	ReadDataIntoCalendar(datafile, assignments, totalAssignments);
	FindQuantityErrors(totalAssignments, datafile, quantityErrors, assignments);
	FindDuplicateErrors(totalAssignments, datafile, duplicateErrors, assignments);
	//ReadQuantityErrors(quantityErrors);
	ReadDuplicateErrors(duplicateErrors);

	
	return 0;
}

