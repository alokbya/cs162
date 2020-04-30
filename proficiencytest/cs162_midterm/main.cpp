#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
    int list[CAP];
    int size = 10;
    build(list, size);
    display(list, size);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int sum = sumOfArray(list,size);
    cout << "The sum is: " << sum << endl;

    int target = list[0];
    int removed = remove(list,size,target);
    cout << "Number of removed elements: " << removed << endl;

    display(list, size);
    
    return 0;
}
