#include <iostream>

using namespace std;

int main()
{
    int x = 5;
    int *ptr;

    cout << "X is: " << x << endl;

    ptr = &x;
    cout << "X (via ptr) is: " << (*ptr) << endl;

    (*ptr) = 7;
    cout << "X is: " << x << endl;
    cout << "X (via ptr) is: " << (*ptr) << endl;

    x = 11;
    cout << "X is: " << x << endl;
    cout << "X (via ptr) is: " << (*ptr) << endl;

    return 0;
}
