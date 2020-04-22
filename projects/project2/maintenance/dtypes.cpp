#include <iostream>
#include <fstream>
#include <cstring>
#include "dtypes.h"
#include <string>

using namespace std;


// FUNCTION DEFINITIONS

void ReadDuplicateErrors(ErrorList duplicateErrors) {
	cout << "### DUPLICATE ERRORS ###" << endl;
	for(int i = 0; i < duplicateErrors.errorCounter; i++) {
		cout << duplicateErrors.errors[i] << endl;
	}
}
void FindDuplicateErrors(int totalAssignments, char* datafile, ErrorList& duplicateErrors, day assignments[])
{
    int duplicates[150];
    int dcounter = 0;
    for (int element = 0; element < MAX_STR; element++)
        duplicates[element] = -1;
   
   // iterate through each day of the month
    for (int d = 0; d < CAL_DAYS; d++) 
    {
        day dailywork[MAX_STR];
        int workcounter = 0;
        for (int assignment = 0; assignment < totalAssignments; assignment++)
        {
            if (assignments[assignment].day == d)
            {   // if the assignment is for the same day, add it into the daily work array
                dailywork[workcounter] = assignments[assignment];
                workcounter++;
            }

#pragma region  "comments"
            // for (int i = 0; i < workcounter; i++)
            // {
            //     cout << "day: " << dailywork[workcounter].day << endl;
            //     cout << "task: " << dailywork[workcounter].taskname << endl;
            //     cout << "duration: " << dailywork[workcounter].duration << endl;
            //     cout << "who: " << dailywork[workcounter].who << endl;
            //     cout << dailywork[workcounter].fileIndex << endl;
            // }

            // Iterate through daily tasks array, for each day, and see if there are any repeated tasks, or any
            // instances where the same person is scheduled twice in the same day

			#pragma endregion
            
			for (int i = 0; i < workcounter; i++)
            {
                for (int j = 0; j < workcounter; j++)
                {   // check if the name or task are the same for a given day
                    if ((strcmp(dailywork[i].taskname, dailywork[j].taskname) == 0 || strcmp(dailywork[i].who, dailywork[j].who) == 0) && (dailywork[i].fileIndex != dailywork[j].fileIndex))
                    {
						bool exists = false;
						for (int k = 0; k < dcounter; k++)
						{
							if (dailywork[i].fileIndex == duplicates[k])
								exists = true;
						}
						if (!exists)
						{
							duplicates[dcounter] = dailywork[i].fileIndex;
							dcounter++;
						}
                    }   
                }
            }
		}
    }
	// add the duplicate assignment lines into the duplicateErrors list 
	// now, fill the duplicate errors arry with the error lines
	ifstream inputFile;
	char line[MAX_STR] = {'\0'};
	inputFile.open(datafile);
	if(!inputFile.is_open()) {
		cerr << "Cannot open file at specified path " << datafile << endl;
		cerr << "Exiting program." << endl;
		exit(0);
	}
	else {
		int calIndex = 0;
		while(inputFile.peek() != EOF) {
			inputFile.getline(line, MAX_STR);							// read in line from file
			if(line[0] != '#' && line[0] != '\0') {						// If line starts with '\0' or '\#', skip
				for (int i=0; i < dcounter; i++) {
					if (duplicates[i] == calIndex) {
						strcpy(duplicateErrors.errors[duplicateErrors.errorCounter], line);
						duplicateErrors.errorCounter++;
					}
				}
				calIndex++;
			}
		}
		inputFile.close();
	}
}

/*
    returns new array size
*/
#pragma region "remove duplicates function that is no longer needed"
// int RemoveDuplicates(int dup[], int uni[], int dsize)
// {
// 	bool exists = false;
// 	int uniIndex = 0;
	
// 	// check if any value in uni[] is equal to the element in question
// 	// of dup[].
// 	for (int i = 0; i < dsize; i++)
// 	{
// 		for (int j = 0; j < dsize; j++)
// 		{
// 			// if dup contains the same value, 
// 			if (dup[i] == uni[j])
// 			{
// 				exists = true;
// 			}
// 		}

// 		// If the first index of the duplicates array does not exist anywhere in unique array
// 		// add the dup value to the unique array at the next available spot.
// 		if (!exists)
// 		{
// 			uni[uniIndex] = dup[i];
// 			uniIndex++;
// 		}
// 		else {
// 			exists = false;
// 		}
		
// 	}

// 	// cout << "DAYYYYYYYYYYY" << endl;
// 	// for (int i = 0; i < dsize; i++)
// 	// {
// 	// 	cout << dup[i] << endl;
// 	// }
// 	return uniIndex;

// }
#pragma endregion


void ReadQuantityErrors(ErrorList quantityErrors) {
	cout << "### QUANTITY ERRORS ###" << endl;
	for(int i = 0; i < quantityErrors.errorCounter; i++) {
		cout << quantityErrors.errors[i] << endl;
	}
}


void FindQuantityErrors(int totalAssignments, char* datafile, ErrorList& quantityErrors, day assignments[]){
// NEED TO ADD A WAY TO TRACK LINE INDEX OF EACH LINE THAT IS 
// NOT ALLOWED, SO AS TO NOT FILL THE CALENDAR WITH THAT LINE
	// to remove it from being seen
	int duplicates = 0;
	int extrasIndex[MAX_STR] = {0};
	int extrasCounter = 0;
	for (int i = 0; i < CAL_DAYS; i++){
		duplicates = 0;
		for (int j = 0; j < totalAssignments; j++) {
			if (assignments[j].day == i) {
				duplicates++;
				if (duplicates > 3) {
					extrasIndex[extrasCounter] = assignments[j].fileIndex;
					extrasCounter++;
				}
			}
		}
	}
	// now, fill the duplicate errors arry with the error lines
	ifstream inputFile;
	char line[MAX_STR] = {'\0'};
	inputFile.open(datafile);
	if(!inputFile.is_open()) {
		cerr << "Cannot open file at specified path " << datafile << endl;
		cerr << "Exiting program." << endl;
		exit(0);
	}
	else {
		int calIndex = 0;
		while(inputFile.peek() != EOF) {
			inputFile.getline(line, MAX_STR);							// read in line from file
			if(line[0] != '#' && line[0] != '\0') {						// If line starts with '\0' or '\#', skip
				for (int i=0; i < extrasCounter; i++) {
					if (extrasIndex[i] == calIndex) {
						strcpy(quantityErrors.errors[quantityErrors.errorCounter], line);
						quantityErrors.errorCounter++;
					}
				}
				calIndex++;
			}
		}
		inputFile.close();
	}
}


void ReadDataIntoCalendar(char* datafile, day assignments[], int& totalAssignments) {
	// File objects
	ifstream inputFile;
	// Line to read in from file
	//char line[MAX_STR] = {'\0'};
	// open file
	inputFile.open(datafile);
	if(!inputFile.is_open()) {
		cerr << "Cannot open file at specified path " << datafile << endl;
		cerr << "Exiting program." << endl;
		exit(0);
	}
	else {
		int calIndex = 0;
		while(inputFile.peek() != EOF) {
			char line[MAX_STR] = {'\0'};
			inputFile.getline(line, MAX_STR);							// read in line from file
			if(line[0] != '#' && line[0] != '\0') {						// If line starts with '\0' or '\#', skip
				FillCalendar(line, assignments, calIndex);
				totalAssignments = calIndex;
				calIndex++;
			}
		}
		inputFile.close();
//		ReadCalendar(assignments, calIndex);
	}
}


void FillCalendar(char line[], day assignments[], int calIndex) {
	// Create character arrays, initialize all indeces to \0
	char task[MAX_STR] = {'\0'};
	char who[MAX_STR] = {'\0'};
	
	// Array to hold the indeces each delimiter	
	int delIndeces[5] = {0};
	GetDelimiters(delIndeces, line);

	GetWho(line, delIndeces, who);
	GetTaskname(line, delIndeces, task);

	// New struct to be used in calendar array for a given day
	day assignment;
	assignment.day = Getday(line, delIndeces);			// Convert char num to int
	strcpy(assignment.taskname, task);	
	assignment.duration = GetDuration(line, delIndeces);	// Convert char num to int
	strcpy(assignment.who, who);
	assignment.fileIndex = calIndex;
	assignments[calIndex] = assignment;

}


int Getday(char line[], int delIndeces[]) {
	// First piece of data <day>
	char cday[MAX_STR] = {'\0'};
	for (int i = 0; i < delIndeces[0]; i++) 
		cday[i] = line[i];
	return atoi(cday);
}


void GetTaskname(char line[], int delIndeces[], char task[]) {
	// Second piece of data <task>
	int taskIndex = 0;
	for (int i = delIndeces[0] + 1; i < delIndeces[1]; i++) {
		task[taskIndex] = line[i];
		taskIndex++;
	}
}


int GetDuration(char line[], int delIndeces[]) {
	// Third piece of data <duration>
	char cduration[MAX_STR] = {'\0'};
	int durationIndex = 0;
	for (int i = delIndeces[1] + 1; i < delIndeces[2]; i++) {
		cduration[durationIndex] = line[i];
		durationIndex++;
	}	
	return atoi(cduration);
}


void GetWho(char line[], int delIndeces[], char who[]) {
	// Fourth & final piece of data <who>
	int lineIndex = delIndeces[2] + 1;
	int whoIndex = 0;
	char indexChar = '!';
	while (indexChar != '\0') {
		indexChar = line[lineIndex];
		who[whoIndex] = indexChar;
		whoIndex++;
		lineIndex++;
	}
}
// Return an array of index positions for each delimiter

void GetDelimiters(int delIndeces[], char line[], char delimiter) {  
	char currentChar = '!';		
	int index = 0;					
	int delsFound = 0;
	while (currentChar != '\0') {
		currentChar = line[index];	
		if (currentChar == delimiter) {
			delIndeces[delsFound] = index;
			delsFound++;
		}
		index++;
	}
}


void ReadCalendar(day calendar[], int calEntries) {
	for (int i = 0; i < calEntries; i++){
		cout << "### Entry " << i << " ###" << endl;
		cout << "\tday: " << calendar[i].day << endl;
		cout << "\tTask: " << calendar[i].taskname << endl;
		cout << "\tDuration: " << calendar[i].duration << endl;
		cout << "\tWho: " << calendar[i].who << endl;
		cout << "\tIndex: " << calendar[i].fileIndex << endl;
	}
}
