#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "functions.h"
#include <string>

using namespace std;


// FUNCTION DEFINITIONS

// void FindOverlapErrors(day calendar[][3], )

void ReadCal(day cal[])
{
	for (int i = 1; i <= CAL_DAYS; i++)
	{
		cout << "Day" << setw(3) << i << ":" << endl;
		for (int j = 0; j < 3; j++)
		{
			if (cal[i].duration[j] != -1 && (cal[i].who[j][0] >=65 && cal[i].who[j][0] <= 90))		// if not empty
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

void FillCal(day cal[], task assignments[], int size)
{
	day cleanDay;
	
	cleanDay.day = -1;
	cleanDay.duration[0] = -1;
	cleanDay.duration[1] = -1;
	cleanDay.duration[2] = -1;

	for (int i = 0; i < CAL_DAYS; i++)					// changing this to <= causes problems
	{
		cal[i] = cleanDay;
	}

	// fill calendar with assignments
	for (int i = 0; i <= CAL_DAYS; i++)					// inlcuding CAL_DAYS (<= instead of <) is adds item to day 30, but is most correct so far
	{
		int taskCounter = 0;
		cal[i].day = i; 
		for (int j = 0; j <= size; j++)	// make sure to include the last item in the list (<=)
		{
			if ((assignments[j].day == i) && (taskCounter < 3))
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

void ReadOverlapErrors(ErrorList overLapErrors) 
{
	cout << endl << "Errors due to overlaps:" << endl;
	for(int i = 0; i < overLapErrors.errorCounter; i++) 
	{
		if (static_cast<int>(overLapErrors.errors[i][0]) > 0){
			cout << "  " << overLapErrors.errors[i] << endl;
		}
			
	}
}


void FindOverlapErrors(day cal[], ErrorList& overLapErrors)
{
	for (int day = 0; day <= CAL_DAYS; day++)
	{
		for (int task = 0; task < 3; task++)
		{
			for (int duration = day; duration <= cal[day+duration].duration[task]; duration++)//cal[day+duration].duration[task]; duration++)
			{
				if (duration <= CAL_DAYS)
				{
					if(strcmp(cal[day].who[task], cal[duration].who[task]) == 0)				// if there is overlap
					{
						strcpy(overLapErrors.errors[overLapErrors.errorCounter], cal[duration].line[task]);
						overLapErrors.errorCounter++;
					}
					else if(strcmp(cal[day].taskname[task], cal[duration].taskname[task]) == 0)
					{
						strcpy(overLapErrors.errors[overLapErrors.errorCounter], cal[duration].line[task]);
						overLapErrors.errorCounter++;
					}
				}
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


void FindDuplicateErrors(day cal[], ErrorList& duplicateErrors)
{
	for (int i = CAL_DAYS; i >= 0 ; i--)		// to get that reverse order list...
	{
		for (int j = 0; j < 2; j++)
		{
			if ((strcmp(cal[i].taskname[j], cal[i].taskname[j+1]) == 0) && cal[i].duration[j] != -1)
			{
				strcpy(duplicateErrors.errors[duplicateErrors.errorCounter], cal[i].line[j]);
				duplicateErrors.errorCounter++;
			}
			else if ((strcmp(cal[i].who[j], cal[i].who[j+1]) == 0) && cal[i].duration[j] != -1)
			{
				strcpy(duplicateErrors.errors[duplicateErrors.errorCounter], cal[i].line[j]);
				duplicateErrors.errorCounter++;
			}
		}
	}	
}


void ReadQuantityErrors(ErrorList quantityErrors) {
	cout << "Errors due to too many jobs on the same day:" << endl;
	for(int i = 0; i < quantityErrors.errorCounter; i++) {
		cout << "  " << quantityErrors.errors[i] << endl;
	}
}


void FindQuantityErrors(ErrorList& quantityErrors, task assignments[], int size)
{
	quantityErrors.errorCounter = 0;
	int qerrs[CAL_DAYS][3];
	for (int i = 0; i <= CAL_DAYS; i++)
	{
		for (int j = 0; j < 3; j++)
			qerrs[i][j] = -1;
	}
	
	for (int assignment = 0; assignment < size; assignment++)
	{
		if (qerrs[assignments[assignment].day][0] == -1)
			qerrs[assignments[assignment].day][0] = 1;
		else if (qerrs[assignments[assignment].day][1] == -1)
			qerrs[assignments[assignment].day][1] = 1;
		else if (qerrs[assignments[assignment].day][2] == -1)
			qerrs[assignments[assignment].day][2] = 1;
		else{
			strcpy(quantityErrors.errors[quantityErrors.errorCounter], assignments[assignment].line);
			quantityErrors.errorCounter++;
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
