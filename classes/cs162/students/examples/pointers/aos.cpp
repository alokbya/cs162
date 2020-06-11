#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char **aos;
    
    int size = 3;

    aos = new char*[size];

    const char* zero = "zero";
    const char* one = "one";
    const char* two = "two";

    aos[0] = new char[strlen(zero)+1];
    strcpy(aos[0],zero);

    aos[1] = new char[strlen(one)+1];
    strcpy(aos[1],one);

    aos[2] = new char[strlen(two)+1];
    strcpy(aos[2],two);

    for (int i=0;i<size;i++)
    {
	cout << aos[i] << endl;
    }

    for (int i=0;i<size;i++)
    {
	delete [] aos[i];
    }

    delete [] aos;

    return 0;
}
