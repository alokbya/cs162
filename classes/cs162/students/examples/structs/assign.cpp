#include <iostream>

using namespace std;

struct date
{
    int day;
    int month;
    int year;
};


int main()
{

    date d1;

    d1.day = 12;
    d1.month = 4;
    d1.year = 2020;

    cout << d1.day << endl;
    cout << d1.month << endl;
    cout << d1.year << endl;

    date d2;
    d2 = d1;

    cout << d2.day << endl;
    cout << d2.month << endl;
    cout << d2.year << endl;

    d2.day = 13;

    cout << "after making a change" << endl;

    cout << d1.day << endl;
    cout << d1.month << endl;
    cout << d1.year << endl;

    cout << d2.day << endl;
    cout << d2.month << endl;
    cout << d2.year << endl;

    return (0);
}
