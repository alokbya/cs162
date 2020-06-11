#include <iostream>

using namespace std;

int* getNewInt()
{
    int* ptr = new int;
    return ptr;
}

void print(const char* msg,const int x,const int y)
{
    cout << msg << " ";
    cout << "X is " << x << " Y is " << y << endl;
}

void swap1(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;

    print("Inside swap1",a,b);
}

void swap2(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;

    print("Inside swap2",a,b);
}

void swap3(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

    print("Inside swap3",*a,*b);
}

int main()
{
    int x = 5;
    int y = 7;
    
    print("Before swap",x,y);
    swap1(x,y);
    print("After swap1",x,y);

    swap2(x,y);
    print("After swap2",x,y);

    swap3(&x,&y);
    print("After swap3",x,y);

    int* s = getNewInt();
    *s = 11;
    cout << "S is " << *s << endl;


    return 0;
}
