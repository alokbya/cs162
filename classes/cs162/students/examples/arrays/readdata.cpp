#include <iostream>

using namespace std;

int main()
{
    const int SIZE=3;
    int arr[SIZE];
    for (int i=0;i<SIZE;i++)
    {
	cout << "Enter a value: " ;
	cin >> arr[i];
    }

    return 0;
}
