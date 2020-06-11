#include <iostream>

using namespace std;

int main()
{
    int *ptr;

    int size;

    cout << "Enter size: ";
    cin >> size;

    ptr = new int[size];

    for (int i=0;i<size;i++)
    {
	ptr[i] = i;
    }

    for (int i=0;i<size;i++)
    {
	cout << ptr[i] << endl;
    }

    delete [] ptr;

    return 0;
}
