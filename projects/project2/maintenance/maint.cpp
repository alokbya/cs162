/*
Sources: https://stackoverflow.com/questions/16772842/what-is-the-difference-between-cout-cerr-clog-of-iostream-header-in-c-when
		http://www.cplusplus.com/reference/iostream/cerr/
		http://www.cplusplus.com/articles/DEN36Up4/
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "dtypes.h"
#include <string>

using namespace std;

// Function Prototypes
//void ReadCalendar(Day assignments[], int calEntries);
void FillCalendar(char line[], Day assignments[], int calIndex);
void GetDelimiters(int delIndeces[], char line[], char delimiter=';'); // Get the array filled with delimiter indeces 
void GetWho(char line[], int delIndeces[], char who[]);
void GetTaskname(char line[], int delIndeces[], char task[]);
void ReadDataIntoCalendar(char* datafile, Day assignments[], int &totalAssignments); 
void ReadQuantityErrors(ErrorList quantityErrors);
void ReadDuplicateErrors(ErrorList duplicateErrors);

void FindQuantityErrors(int totalAssignments, char* datafile, ErrorList &quantityErrors, Day assignments[]);

void FindDuplicateErrors(int totalAssignments, char* datafile, ErrorList &duplicateErrors, Day assignments[]);
int GetDay(char line[], int delIndeces[]);
int GetDuration(char line[], int delIndeces[]);


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
	//Day calendar[CAL_DAYS];
	Day assignments[100];

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

// FUNCTION DEFINITIONS

void ReadDuplicateErrors(ErrorList duplicateErrors) {
	cout << "### DUPLICATE ERRORS ###" << endl;
	for(int i = 0; i < duplicateErrors.errorCounter; i++) {
		cout << duplicateErrors.errors[i] << endl;
	}
}
void FindDuplicateErrors(int totalAssignments, char* datafile, ErrorList &duplicateErrors, Day assignments[]) {
	// Use strcmp(char i[], char j[]) to compare strings <cstring> 
	//Iterate through each day of the month
	//
	int dupcounter = 0;
	int dupindeces[MAX_STR] = {0};
	for (int i = 0; i < CAL_DAYS; i++) {

		Day daystasks[MAX_STR];
		int daytaskCounter = 0;
		for (int j = 0; j <= totalAssignments; j++) {
			// Fill the daystasks array with Day objs that are on the same day
			if (i == assignments[j].day) {
				daystasks[j] = assignments[j];
				daytaskCounter++;
				//cout << assignments.day << " | " << assignments[j].taskname << " | " << assignments[j].duration << " | " << assignments[j].who << " | " << assignments[j].fileIndex << endl;
			}
		} 
		for (int e = 0; e < daytaskCounter; e++){
			cout << daystasks[e].taskname << endl;
		}
		// Iterate through each daystasks and compare name and task
		// if the same name or same task, write down index of each assignment
		// into dubplicateLineIndeces array
		for (int k = 0; k < daytaskCounter; k++) {
			for (int m = 0; m < daytaskCounter; m++) {
				if (k != m) {
					// check if day: k and day: m have the same name or task
					// if so, send both indeces to duplicateLineIndeces array
					if (strcmp(daystasks[k].who, daystasks[m].who) == 0 || strcmp(daystasks[k].taskname, daystasks[m].taskname) == 0) {
						if (daystasks[k].who[0] != '\0' && daystasks[k].taskname[0] != '\0') {
							//cout << "Name-m: " << daystasks[m].who << " Name-k: " << daystasks[k].who << endl;
							//cout << "Task-m: " << daystasks[m].taskname << " Task-k: " << daystasks[k].taskname << endl;
							//dupindeces[dupcounter] = daystasks[m].fileIndex;
							//cout << "INDEX: " << daystasks[m].fileIndex << endl;
							//dupcounter++;
							//cout << "DUPCOUNTER: " << dupcounter << endl;
						}
					}
				}
			}
		}
		cout << "now end of day" << endl;
	}


	
	cout << "DUPLICATES: " << dupcounter << endl;
	// remove duplicates in dupindeces array
	bool exists = false;
	int unicount = 0;
	int unidups[dupcounter] = {-1};		// unique duplicates
	for (int a = 0; a < dupcounter; a++) {
		for (int b = 0; b < dupcounter; b++) {
			if (dupindeces[a] == unidups[b]) {
				exists = true;
			}
		}
		if (!exists) {
			unidups[unicount] = dupindeces[a];
			unicount++;
		}
	}
	
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
		int dindex = 0;
		while(inputFile.peek() != EOF) {
			inputFile.getline(line, MAX_STR);							// read in line from file
			if(line[0] != '#' && line[0] != '\0') {						// If line starts with '\0' or '\#', skip
				for (int n=0; n < unicount; n++) {
					if (calIndex == unidups[n]) {
						cout << line << endl;
						strcpy(duplicateErrors.errors[dindex], line);
						duplicateErrors.errorCounter++;
					}
				}
				calIndex++;
			}
		}
		inputFile.close();
	}

}


void ReadQuantityErrors(ErrorList quantityErrors) {
	cout << "### QUANTITY ERRORS ###" << endl;
	for(int i = 0; i < quantityErrors.errorCounter; i++) {
		cout << quantityErrors.errors[i] << endl;
	}
}


void FindQuantityErrors(int totalAssignments, char* datafile, ErrorList &quantityErrors, Day assignments[]){
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


void ReadDataIntoCalendar(char* datafile, Day assignments[], int &totalAssignments) {
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


void FillCalendar(char line[], Day assignments[], int calIndex) {
	// Create character arrays, initialize all indeces to \0
	char task[MAX_STR] = {'\0'};
	char who[MAX_STR] = {'\0'};
	
	// Array to hold the indeces each delimiter	
	int delIndeces[5] = {0};
	GetDelimiters(delIndeces, line);

	GetWho(line, delIndeces, who);
	GetTaskname(line, delIndeces, task);

	// New struct to be used in calendar array for a given day
	Day assignment;
	assignment.day = GetDay(line, delIndeces);			// Convert char num to int
	strcpy(assignment.taskname, task);	
	assignment.duration = GetDuration(line, delIndeces);	// Convert char num to int
	strcpy(assignment.who, who);
	assignment.fileIndex = calIndex;
	assignments[calIndex] = assignment;

}


int GetDay(char line[], int delIndeces[]) {
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


void ReadCalendar(Day calendar[], int calEntries) {
	for (int i = 0; i < calEntries; i++){
		cout << "### Entry " << i << " ###" << endl;
		cout << "\tDay: " << calendar[i].day << endl;
		cout << "\tTask: " << calendar[i].taskname << endl;
		cout << "\tDuration: " << calendar[i].duration << endl;
		cout << "\tWho: " << calendar[i].who << endl;
		cout << "\tIndex: " << calendar[i].fileIndex << endl;
	}
}
