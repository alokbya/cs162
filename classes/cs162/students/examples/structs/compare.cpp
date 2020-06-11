#include <iostream>

using namespace std;

struct date
{
    int day;
    int month;
    int year;
};


void printDate(date d)
{
    cout << d.day << endl;
    cout << d.month << endl;
    cout << d.year << endl;
}

bool equal(date d1,date d2)
{
    bool ret = false;
    if ((d1.day == d2.day) &&
	(d1.month == d2.month) &&
	(d1.year == d2.year))
    {
	ret = true;
    }

    return ret;
}

int main()
{

    date d1;

    d1.day = 12;
    d1.month = 4;
    d1.year = 2020;

    date d2;
    d2 = d1;

    printDate(d1);
    printDate(d2);

    if (equal(d1,d2))
    {
	cout << "Equal" << endl;
    }
    else
    {
	cout << "Not Equal" << endl;
    }

    d2.day = 13;
    cout << "after making a change" << endl;

    printDate(d1);
    printDate(d2);

    if (equal(d1,d2))
    {
	cout << "Equal" << endl;
    }
    else
    {
	cout << "Not Equal" << endl;
    }

    return (0);
}
