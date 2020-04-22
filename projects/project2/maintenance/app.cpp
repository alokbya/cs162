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
	ErrorList overlapErrors;
	duplicateErrors.errorCounter = 0;
	
	//int duplicateLineIndeces[MAX_STR] = {0};
	//int quantityLineIndeces[MAX_STR] = {0};

	// Main part of the program
	ReadDataIntoAssignments(datafile, assignments, totalAssignments);
	FillCal(cal, assignments, totalAssignments);
	
	FindQuantityErrors(quantityErrors, assignments, totalAssignments);
	
	FindOverlapErrors(cal, overlapErrors);
	FindDuplicateErrors(cal, duplicateErrors);
	// for (int i = 0; i < CAL_DAYS; i++)
	// {

	// }
	
	// for (int i = 0; i <= CAL_DAYS; i++)
	// {
	// 	cout << "###############" << endl;
	// 	cout << i << endl;
	// 	cout << cal[i].who[0] << endl;
	// 	cout << cal[i].who[1] << endl;
	// 	cout << cal[i].who[2] << endl;
	// 	cout << cal[i].taskname[0] << endl;
	// 	cout << cal[i].taskname[1] << endl;
	// 	cout << cal[i].taskname[2] << endl;
	// 	cout << cal[i].duration[0] << endl;
	// 	cout << cal[i].duration[1] << endl;
	// 	cout << cal[i].duration[2] << endl;
	// }
	ReadCal(cal);
	cout << "==============================" << endl;
	ReadQuantityErrors(quantityErrors);
	ReadOverlapErrors(overlapErrors);
	ReadDuplicateErrors(duplicateErrors);


	// for (int i = 0; i <= totalAssignments; i++) {
	// 	cout << assignments[i].fileIndex << ": ";
	// 	cout << assignments[i].who << endl;
		
	// }
	// FillCalTest(day cal[], task assignments[], int size);
	return 0;
}

