#include <iostream>

using namespace std;

int main()
{
    const int SIZE=5;
    int arr[SIZE];

    for (int i=0;i<SIZE;i++)
    {
	cout << "Enter a value: " ;
	cin >> arr[i];
    }

    int target;
    cout << "Enter the value to search for: ";
    cin >> target;

    int found = -1;
    for (int i=0;i<SIZE;i++)
    {
	if (arr[i] == target)
	{
	    found = i;
	}
    }

    if (found >= 0)
    {
	cout << "Found the target at location " << found << endl;
    }
    else
    {
	cout << "Not found" << endl;
    }


    return 0;
}
