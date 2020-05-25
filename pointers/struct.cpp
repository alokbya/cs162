#include <iostream>

using namespace std;

typedef struct {
    char name[25];
    double gpa;
    int sID;
    char grade;
} student_t;

int main()
{
    student_t s1;
    student_t *p1;

    s1.gpa = 3.9;

    cout << "GPA: " << s1.gpa << endl;

    p1 = &s1;
    cout << "GPA (via p1): " << (*p1).gpa << endl;
    cout << "GPA (via p1): " << p1->gpa << endl;

    p1->gpa = 3.95;
    cout << "GPA: " << s1.gpa << endl;
    cout << "GPA (via p1): " << p1->gpa << endl;

    student_t *p2;
    p2 = nullptr;
    if ( p2 != nullptr)
    {
	cout << "GPA (via p2): " << p2->gpa << endl;
    }

    return 0;
}
