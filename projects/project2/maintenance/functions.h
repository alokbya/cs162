#ifndef DTYPES_H
#define DTYPES_H

#define MAX_STR 100
#define CAL_DAYS 30
#define MAX_ERRS 50

struct task {
	int day;
	char taskname[MAX_STR];
	int duration;
	char who[MAX_STR];
	int fileIndex;
	char line[MAX_STR];
};

struct day {
	int day;
	char taskname[3][MAX_STR];
	int duration[3];
	char who[3][MAX_STR];
	int fileIndex[3];
	char line[3][MAX_STR];
};

struct ErrorList {
	char errors[MAX_ERRS][MAX_STR];
	int errorCounter;
};

void ReadAssignments(task assignments[], int calEntries);
void FillAssignments(char line[], task assignments[], int calIndex);
void GetDelimiters(int delIndeces[], char line[], char delimiter=';'); // Get the array filled with delimiter indeces 
void GetWho(char line[], int delIndeces[], char who[]);
void GetTaskname(char line[], int delIndeces[], char task[]);
void ReadDataIntoAssignments(char* datafile, task assignments[], int& totalAssignments); 
void ReadQuantityErrors(ErrorList quantityErrors);
void ReadDuplicateErrors(ErrorList duplicateErrors);
void FindQuantityErrors(ErrorList& quantityErrors, task assignments[], int size);
void FindDuplicateErrors(int totalAssignments, char* datafile, ErrorList& duplicateErrors, task assignments[]);
int Getday(char line[], int delIndeces[]);
int GetDuration(char line[], int delIndeces[]);
void FillCalendar(task calendar[][3], task assignments[], int size);
void ReadCalendar(task calendar[][3]);
void FillCal(day cal[], task assignments[], int size);
void ReadCal(day cal[]);

void FindDups(day cal[], ErrorList& duplicateErrors);


#endif
