#include <iostream>

using namespace std;

int main()
{
    const int SIZE=3;
    int arr[SIZE]; // valid 0, 1, 2

    for (int i=0;i<SIZE;i++)
    {
	arr[i] = 0;
    }

    for (int i=0;i<SIZE;i++)
    {
	cout << "Item " << i+1 << ": " << arr[i] << endl;
    }

    return 0;
}
