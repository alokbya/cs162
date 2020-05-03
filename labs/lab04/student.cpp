#include <cstring>
#include <cmath>
#include "student.h"

//implement the required 3 functions here

void Student::print() const
{
	cout << id << '\t' << gpa << endl;
}

Student::Student(const char initId[], double initGpa)
{
	strcpy(id, initId);
	gpa = initGpa;
}

bool Student::isLessThanByID(const Student& aStudent) const
{
	return getStudentIDValue() < aStudent.getStudentIDValue();
}

bool Student::qualifyForHonor(double minGpa) const
{
	return gpa >= minGpa;
}

int Student::getStudentIDValue() const
{	
	int val = 0;
	for (int i = 0; i < strlen(id); i++)
		val += static_cast<int>(id[i]);
	return val;
}