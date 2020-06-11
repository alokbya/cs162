#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char* text = "bob";

    char* s1 = new char[strlen(text)+1];
    strcpy(s1,text);

    char* s2;

    s2 = s1;

    cout << "S1: " << s1 << endl;
    cout << "S2: " << s2 << endl;
    
    delete [] s1;

    cout << "S2: " << s2 << endl;

    delete [] s2;

    return 0;
}
