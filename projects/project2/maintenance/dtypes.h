#ifndef DTYPES_H
#define DTYPES_H

#include "sizes.h"

struct day {
	int day;
	char taskname[MAX_STR];
	int duration;
	char who[MAX_STR];	
	int fileIndex;
};

struct ErrorList {
	char errors[MAX_ERRS][MAX_STR];
	int errorCounter;
};

void ReadCalendar(day assignments[], int calEntries);
void FillCalendar(char line[], day assignments[], int calIndex);
void GetDelimiters(int delIndeces[], char line[], char delimiter=';'); // Get the array filled with delimiter indeces 
void GetWho(char line[], int delIndeces[], char who[]);
void GetTaskname(char line[], int delIndeces[], char task[]);
void ReadDataIntoCalendar(char* datafile, day assignments[], int& totalAssignments); 
void ReadQuantityErrors(ErrorList quantityErrors);
void ReadDuplicateErrors(ErrorList duplicateErrors);
void FindQuantityErrors(int totalAssignments, char* datafile, ErrorList& quantityErrors, day assignments[]);
void FindDuplicateErrors(int totalAssignments, char* datafile, ErrorList& duplicateErrors, day assignments[]);
int Getday(char line[], int delIndeces[]);
int GetDuration(char line[], int delIndeces[]);

int RemoveDuplicates(int dup[], int uni[], int dsize);

#endif
