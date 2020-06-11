#include "arr.h"
using namespace std;

int main()
{
    node * head[SIZE] = {0,0,0,0,0};
    build(head);
    display(head);

    // Feel free to edit any of the code in this file.

    int sum = sum(head);
    cout << "The sum of all the values is " << sum << endl;;

    removeTwo(head);

    cout << "After removing all of the twos the data is: " << endl;
    display(head);

    destroy(head);
    return 0;
}
