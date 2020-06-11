#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    // Feel free to edit any of the code in this file.

    node* newroot;
    duplicate(root,newroot);
    cout << "Here is the copy." << endl;
    display(newroot);

    cout << "Removing 100 from the tree" <<endl;
    remove(newroot,100);
    cout << "After removing 100" << endl;
    display(newroot);

    display(root);
    destroy(root);
    destroy(newroot);
    return 0;
}
