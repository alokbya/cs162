#include <iostream>

using namespace std;

int main()
{
    int *ptr;

    ptr = new int;
    (*ptr) = 5;
    cout << "Ptr: " << *ptr << endl;

    int *p2;
    p2 = new int;
    (*p2) = 5;
    cout << "P2: " << *p2 << endl;

    if (ptr == p2)
    {
	cout << "Equal" << endl;
    }
    else
    {
	cout << "Not equal" << endl;
    }

    if (*ptr == *p2)
    {
	cout << "Equal" << endl;
    }
    else
    {
	cout << "Not equal" << endl;
    }


    delete ptr;
    delete p2;

    return 0;
}
