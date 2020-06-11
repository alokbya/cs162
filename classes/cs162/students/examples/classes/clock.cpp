#include <iostream>
#include <iomanip>
#include "clock.h"

using namespace std;

clockType::clockType()
{
    cout << "in constructor" <<endl;
    setTime(1,1,1);
}

clockType::clockType(int h,int m,int s)
{
    setTime(h,m,s);
}

clockType::~clockType()
{}

void clockType::setTime(int h,int m,int s)
{
    if (h > 0)
	hr = h;
    if (m > 0)
	min = m;
    if (s > 0)
	sec = s;
}

void clockType::getTime(int& h,int& m,int& s)
{
    h = hr;
    m = min;
    s = sec;
}

void clockType::printTime() const
{
    cout << setfill('0') << setw(2) << hr << ":" << setw(2) << min << ":" << setw(2) << sec << endl;
}


