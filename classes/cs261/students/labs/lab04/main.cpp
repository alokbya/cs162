#include "clist.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * copy = NULL;
    build(head);
    display(head);

    // Feel free to edit any of the code in this file.

    addHead(head,42);
    cout << "After adding 42 to the head." << endl;
    display(head);

    cout << "My version of the display function." << endl;
    myDisplay(head);

    display(head); //resulting list after your function call!
    destroy(head);
    
    return 0;
}
