#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    // Feel free to edit any of the code in this file.

    node* newHead;
    duplicate(head,newHead);

    cout << "Here is the duplicate:" << endl;
    display(newHead);

    removeTwo(newHead);
    cout << "Here is the duplicate with 2s removed:" << endl;
    display(newHead);

    display(head);
    destroy(head);    
    destroy(newHead);
    return 0;
}
