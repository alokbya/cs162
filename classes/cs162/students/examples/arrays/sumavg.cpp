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

    int sum = 0;
    for (int i=0;i<SIZE;i++)
    {
	sum = sum + arr[i];
    }

    int avg = sum/SIZE;
    
    cout << "Sum: " << sum << endl;
    cout << "Avg: " << avg << endl;

    return 0;
}
