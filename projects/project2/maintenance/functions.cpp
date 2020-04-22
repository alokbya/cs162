#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "functions.h"
#include <string>

using namespace std;


// FUNCTION DEFINITIONS

// void FindOverlapErrors(day calendar[][3], )

void ReadCalendar(task calendar[][3])
{	
	for (int day = 0; day < CAL_DAYS; day++)
	{
		cout << "Day" << setw(3) << day << ":" << endl;
		for (int task = 0; task < 3; task++)
		{
			if (calendar[day][task].day != -1)
			{
				cout << "  ";
				cout << calendar[day][task].who << " is doing \"";
				cout << calendar[day][task].taskname << "\" for ";
				cout << calendar[day][task].duration << " days";
				cout << endl;
			}
		}
	}
}

void ReadCalTest(day cal[])
{
	for (int i = 0; i < CAL_DAYS; i++)
	{
		cout << "Day" << setw(3) << i << ":" << endl;
		for (int j = 0; j < 3; j++)
		{
			if (cal[i].duration[j] != -1)		// if not empty
			{
				cout << "  ";
				cout << cal[i].who[j] << " is doing \"";
				cout << cal[i].taskname[j] << "\" for ";
				cout << cal[i].duration[j] << " days";
				cout << endl;
			}
		}	
	}
}

void FillCalTest(day cal[], task assignments[], int size)
{
	day cleanDay;
	cleanDay.day = -1;
	cleanDay.duration[0] = -1;
	cleanDay.duration[1] = -1;
	cleanDay.duration[2] = -1;
	// clean out the calendar
	for (int i = 0; i < CAL_DAYS; i++)
	{
		cal[i] = cleanDay;
	}

	// fill calendar with assignments
	for (int i = 0; i < CAL_DAYS; i++)
	{
		int taskCounter = 0;
		cal[i].day = i; 
		for (int j = 0; j <= size; j++)
		{
			if (assignments[j].day == i && taskCounter < 3)
			{
				strcpy(cal[i].taskname[taskCounter], assignments[j].taskname);
				cal[i].duration[taskCounter] = assignments[j].duration;
				strcpy(cal[i].who[taskCounter], assignments[j].who);
				cal[i].fileIndex[taskCounter] = assignments[j].fileIndex;
				strcpy(cal[i].line[taskCounter], assignments[j].line);

				taskCounter++;
			}
		}
	}
}

void FillCalendar(task calendar[][3], task assignments[], int size) 
{
	task shell;
	shell.day = -1;
	for (int i = 0; i < CAL_DAYS; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			calendar[i][j] = shell;
		}
	}
	for (int eachDay = 0; eachDay < CAL_DAYS; eachDay++)  
	{
		int taskNumber = 0;
		for (int eachTask = 0; eachTask <= size; eachTask++)
		{
			if(assignments[eachTask].day == eachDay && taskNumber < 3)
			{
				calendar[eachDay][taskNumber] = assignments[eachTask];
				taskNumber++;
			}
		}
	}
}

void ReadDuplicateErrors(ErrorList duplicateErrors) {
	cout << endl << "Errors due to duplicate assignments:" << endl;
	for(int i = 0; i < duplicateErrors.errorCounter; i++) {
		cout << "  " << duplicateErrors.errors[i] << endl;
	}
}


void FindDuplicateErrors(int totalAssignments, char* datafile, ErrorList& duplicateErrors, task assignments[])
{
    int duplicates[150];
    int dcounter = 0;
    for (int element = 0; element < MAX_STR; element++)
        duplicates[element] = -1;
   
   // iterate through each day of the month
    for (int d = 0; d < CAL_DAYS; d++) 
    {
        task dailywork[MAX_STR];
        int workcounter = 0;
        for (int assignment = 0; assignment < totalAssignments; assignment++)
        {
            if (assignments[assignment].day == d)
            {   // if the assignment is for the same day, add it into the daily work array
                dailywork[workcounter] = assignments[assignment];
                workcounter++;
            }            
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
							strcpy(duplicateErrors.errors[duplicateErrors.errorCounter], dailywork[i].line);
							duplicateErrors.errorCounter++;
							dcounter++;
						}
                    }   
                }
            }
		}
    }
}

void ReadQuantityErrors(ErrorList quantityErrors) {
	cout << endl << "Errors due to too many jobs on the same day:" << endl;
	for(int i = 0; i < quantityErrors.errorCounter; i++) {
		cout << "  " << quantityErrors.errors[i] << endl;
	}
}

void FindQuantityErrors(int totalAssignments, char* datafile, ErrorList& quantityErrors, task assignments[]){
// NEED TO ADD A WAY TO TRACK LINE INDEX OF EACH LINE THAT IS 
// NOT ALLOWED, SO AS TO NOT FILL THE CALENDAR WITH THAT LINE
	// to remove it from being seen
	int duplicates = 0;
	for (int i = 0; i < CAL_DAYS; i++){
		duplicates = 0;
		for (int j = 0; j < totalAssignments; j++) {
			if (assignments[j].day == i) {
				duplicates++;
				if (duplicates > 3) {
					strcpy(quantityErrors.errors[quantityErrors.errorCounter], assignments[j].line);
					quantityErrors.errorCounter++;
				}
			}
		}
	}
}


void ReadDataIntoAssignments(char* datafile, task assignments[], int& totalAssignments) {
	// File objects
	ifstream inputFile;
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
				FillAssignments(line, assignments, calIndex);
				totalAssignments = calIndex;
				calIndex++;
			}
		}
		inputFile.close();
		// ReadAssignments(assignments, calIndex);
	}
}


void FillAssignments(char line[], task assignments[], int calIndex) {
	// Create character arrays, initialize all indeces to \0
	char assign[MAX_STR] = {'\0'};
	char who[MAX_STR] = {'\0'};
	
	// Array to hold the indeces each delimiter	
	int delIndeces[5] = {0};
	GetDelimiters(delIndeces, line);

	GetWho(line, delIndeces, who);
	GetTaskname(line, delIndeces, assign);

	// New struct to be used in calendar array for a given day
	task assignment;
	assignment.day = Getday(line, delIndeces);			// Convert char num to int
	strcpy(assignment.taskname, assign);	
	assignment.duration = GetDuration(line, delIndeces);	// Convert char num to int
	strcpy(assignment.who, who);
	assignment.fileIndex = calIndex;
	strcpy(assignment.line, line);
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


void ReadAssignments(task calendar[], int calEntries) {
	for (int i = 0; i < calEntries; i++){
		cout << "### Entry " << i << " ###" << endl;
		cout << "\tday: " << calendar[i].day << endl;
		cout << "\tTask: " << calendar[i].taskname << endl;
		cout << "\tDuration: " << calendar[i].duration << endl;
		cout << "\tWho: " << calendar[i].who << endl;
		cout << "\tIndex: " << calendar[i].fileIndex << endl;
		cout << "\tLine: " << calendar[i].line << endl;
	}
}