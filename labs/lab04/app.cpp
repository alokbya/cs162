#include <iostream>
#include "student.h"
using namespace std;

int main()
{
	Student s1("G10", 3.9);
	Student s2("G20", 3.5);

	s1.print();
	s2.print();

	//write code to test Student::isLessThanByID
	cout << "Student 1's ID is less than Student 2's ID: " << s1.isLessThanByID(s2) << endl;
	cout << "Student 2's ID is less than Student 1's ID: " << s2.isLessThanByID(s1) << endl;

	//write code to test Student::qualifyForHonor
	cout << "Student 1 qualifies for honors: " << s1.qualifyForHonor(3.7) << endl;
	cout << "Student 2 qualifies for honors: " << s2.qualifyForHonor(3.7) << endl;

	return 0;
}
