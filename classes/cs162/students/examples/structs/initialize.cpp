#include <iostream>

using namespace std;

struct date {
    int day;
    int month;
    int year;
};
	
int main(int argc,char** argv)
{

    date d1;
    date d2 = {1,2,3};
    cout << "Hello" << endl;

    cout << "D1: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
    cout << "D2: " << d2.day << "/" << d2.month << "/" << d2.year << endl;

    return 1;
}
