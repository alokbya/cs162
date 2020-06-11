#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    // Feel free to edit any of the code in this file.

    node * newhead;
    duplicate(head,newHead);
    display(newHead);

    removeTwo(newHead);
    display(newHead);

    display(head);
    destroy(head);
    destroy(newHead);
    
    return 0;
}
