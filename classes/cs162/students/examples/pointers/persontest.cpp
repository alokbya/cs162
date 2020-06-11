#include <iostream>
#include "person.h"

using namespace std;

void printStuff(const char* msg,person p)
{
    cout << msg;
    p.print();
}

int main()
{
    person p1("bob",2000);
    printStuff("First person is ",p1);

    person p2("joe",2001);
    printStuff("Second person is ",p2);

    p2 = p1;
    p1.print();
    p2.print();

    return 0;
}
