//put your implementation of LinkedList class here
#include "list.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}   
LinkedList::~LinkedList()
{
    // Node *current;
    // current = head;
    // while (current != nullptr)
    // {
    //     current = current->next;
    //     delete current->prev;
    // }
    // delete head;
    // delete tail;
}
bool LinkedList::addAtBeginning(int val)
{
    cout << "adding " << val << endl;
    Node *newNode;                      // declare new node pointer
    newNode = new Node;                 // allocate memory for new node
    if(head == nullptr)                 // if the list has 0 nodes 
    {
        newNode->data = val;            // assign newNode->data = val
        newNode->prev = nullptr;        //  
        newNode->next = nullptr;
        
        head = newNode;
        tail = newNode;
        cout << "tail is " << tail->data << endl;
    }
    else                                // if the list has > 0 nodes
    {
        newNode->data = val;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = nullptr;
        head = newNode;
        cout << "tail is " << tail->data << endl;
    }
    
    // printForward();

}
bool LinkedList::remove(int val)
{
    // iterate through the list until last node (nullptr)
}
void LinkedList::printForward() const
{
    Node *current;
    current = new Node;
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void LinkedList::printBackward() const
{
    Node *current;
    current = new Node ;
    current = tail;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;

}
