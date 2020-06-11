#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    int count = countEven(head);
    cout << "The count of even nodes is: " << count << endl;

    int removed = removeEven(head);
    cout << "Number of removed nodes: " << removed << endl;

    display(head);
    destroy(head);
    
    return 0;
}
